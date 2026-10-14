// batch8819.cpp - hit-reaction thread, batch 8819: ConstrainedParticleSystem::FindFaces (the ragdoll's box query that fills the face
// list CheckCollision3 / CollideLineBetweenParticles3 walk) and its small vector helpers vmin / vmax / ZBaseGeom::GetSize.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])

extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);          // PSVECSubtract d = a - b
extern "C" void FASTCALL ext_43e8e0(float *d, const float *a, const float *b);          // d = a + b
extern "C" void THISCALL ext_4e0d00(float *v, float s);                                 // vscalar in place
extern "C" void FASTCALL ext_4e0900(float *d, const float *s);                          // vmin (this batch)
extern "C" void FASTCALL ext_4e08d0(float *d, const float *s);                          // vmax (this batch)
extern "C" void THISCALL ext_4de7a0(float *m);                                          // mreset (strict, inline-batch45)
extern "C" void *ext_41e290(u32 n);                                              // __builtin_new
extern "C" void *THISCALL ext_6353d0(void *self, u32 a, float r, u32 b, u32 c);         // ZFastBoxColi1::ZFastBoxColi1 (GUESS hook, not verified)
extern "C" void THISCALL ext_635eb0(void *self, const float *cen, const float *m, const float *half, u32 fresh);   // ZFastBoxColi1::SetBox (GUESS hook)
extern "C" void THISCALL ext_4daf90(void *g, float *out);                               // ZBaseGeom::GetCen (strict, inline-collision)
extern "C" void THISCALL ext_4db670(void *g, float *v);                                 // ZBaseGeom::GetRootPoint (strict, inline-collision)
extern "C" void THISCALL ext_4db7c0(void *g, float *out);                               // ZBaseGeom::GetSize (this batch)

typedef void (THISCALL *vIter)(void *self, void *cookie);
typedef u32 (THISCALL *vNextId)(void *self, void *cookie);
typedef void *(THISCALL *vGeom)(void *self, u32 id);

// 0x4e0900 vmin(float* d, const float* s), fastcall: per axis d = s when d > s (comiss d, s; jbe keeps d, so NaN keeps d).
static void FASTCALL vmin3(float *d, const float *s) {
  for (int i = 0; i < 3; i++) {
    float v = s[i];
    if (d[i] > v) d[i] = v;
  }
}
PCREG(4e0900, vmin3);

// 0x4e08d0 vmax(float* d, const float* s), fastcall: per axis d = s when s > d.
static void FASTCALL vmax3(float *d, const float *s) {
  for (int i = 0; i < 3; i++) {
    float v = s[i];
    if (v > d[i]) d[i] = v;
  }
}
PCREG(4e08d0, vmax3);

// 0x4db7c0 ZBaseGeom::GetSize(float* out) const, thiscall, ret 4: out = the half size at +0x40.
static void THISCALL getSize(u8 *g, u32 *out) {
  out[0] = *(u32 *)(g + 0x40);
  out[1] = *(u32 *)(g + 0x44);
  out[2] = *(u32 *)(g + 0x48);
}
PCREG(4db7c0, getSize);

// 0x545950 ConstrainedParticleSystem::FindFaces() (), thiscall, no arguments.
//  Box lo / hi over every particle's position (+0xc) and last position (+0), from lo = 1e7 / hi = -1e7; grown by 15 [0x680a80];
//  centre c = (lo + hi) * 0.5, half h = (hi - lo) * 0.5, orientation the identity (mreset).
//  The box query [this+0x5d]: none yet -> new(0x93) and ZFastBoxColi1(obj, [render manager +0xadc], 10.0, 0x20, 0) (a failed new
//  leaves 0), +0x6e = 1, +0x6f = 1, then SetBox(c, m, h, 1); otherwise SetBox(c, m, h, 0).
//  Then the geom list [this+0xa] (none -> done): +0xe = 0, +9 = old +8, +8 = 0; slot 0x4c(cookie) starts, slot 0x5c(cookie) gives the
//  next id while cookie[0] != 0. Each geom (render manager slot 0x54(id)): centre GetCen then GetRootPoint (to world), size GetSize;
//  the first whose box [c - s, c + s] overlaps lo..hi on all three axes sets +0xe = 1 and ends the walk.
static void THISCALL findFaces(u8 *self) {
  float lo[3], hi[3];
  lo[0] = lo[1] = lo[2] = G(float, 0x6a13bc);
  hi[0] = hi[1] = hi[2] = G(float, 0x6a3164);
  u8 *p = *(u8 **)(self + 0xf);
  for (s32 i = 0; i < *(s32 *)(self + 0x28); i++, p += 0x34) {
    ext_4e0900(lo, (float *)(p + 0xc));
    ext_4e08d0(hi, (float *)(p + 0xc));
    ext_4e0900(lo, (float *)p);
    ext_4e08d0(hi, (float *)p);
  }
  float g = G(float, 0x680a80);
  lo[0] = lo[0] - g; lo[1] = lo[1] - g; lo[2] = lo[2] - g;
  hi[0] = hi[0] + g; hi[1] = hi[1] + g; hi[2] = hi[2] + g;
  float c[3], h[3], m[9];
  ext_43e8e0(c, lo, hi);
  ext_4e0d00(c, 0.5f);
  ext_43e920(h, hi, lo);
  ext_4e0d00(h, 0.5f);
  u32 fresh;
  if (!*(void **)(self + 0x5d)) {
    ext_4de7a0(m);
    void *o = ext_41e290(0x93);
    u8 *bx = 0;
    if (o) {
      u8 *rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
      bx = (u8 *)ext_6353d0(o, *(u32 *)(rm + 0xadc), 10.0f, 0x20, 0);
    }
    *(u8 **)(self + 0x5d) = bx;
    bx[0x6e] = 1;
    (*(u8 **)(self + 0x5d))[0x6f] = 1;
    fresh = 1;
  } else {
    ext_4de7a0(m);
    fresh = 0;
  }
  ext_635eb0(*(void **)(self + 0x5d), c, m, h, fresh);
  void *gl = *(void **)(self + 0xa);
  if (!gl) return;
  u32 cookie[4];
  self[0xe] = 0;
  self[9] = self[8];
  self[8] = 0;
  ((vIter)VT(gl, 0x4c))(gl, cookie);
  gl = *(void **)(self + 0xa);
  u32 id = ((vNextId)VT(gl, 0x5c))(gl, cookie);
  while (cookie[0]) {
    void *rm = *(void **)(G(u8 *, 0x70039c) + 0x9b);
    void *geom = ((vGeom)VT(rm, 0x54))(rm, id);
    float gc[3], gs[3], glo[3], ghi[3];
    ext_4daf90(geom, gc);
    ext_4db670(geom, gc);
    ext_4db7c0(geom, gs);
    ext_43e920(glo, gc, gs);
    ext_43e8e0(ghi, gc, gs);
    int ox = hi[0] >= glo[0] && ghi[0] >= lo[0];
    int oy = hi[1] >= glo[1] && ghi[1] >= lo[1];
    int oz = hi[2] >= glo[2] && ghi[2] >= lo[2];
    if (ox && oy && oz) {
      self[0xe] = 1;
      return;
    }
    gl = *(void **)(self + 0xa);
    id = ((vNextId)VT(gl, 0x5c))(gl, cookie);
  }
}
PCREG(545950, findFaces);
