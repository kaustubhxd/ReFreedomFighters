// batch1105.cpp - collision thread, batch 1105: ZCollisionBox::CalcStripsBoundInfo (0x4e8ed0).
#include "ff.h"

extern "C" void THISCALL ext_4e3340(const u8 *node, float *out);                   // ZOctree::GetOrigin
extern "C" void FASTCALL ext_4de7a0(float *m);                                     // mreset
extern "C" void THISCALL ext_4db5a0(const u8 *geom, float *m);                     // ZBaseGeom::GetRootMat (batch 1100)
extern "C" void FASTCALL ext_4de440(float *dst, const float *a, const float *b);   // mmmul
extern "C" void FASTCALL ext_4e2c60(const float *m, float *v);                     // TransformBox (half extents)
extern "C" void THISCALL ext_4db670(const u8 *geom, float *p);                     // ZBaseGeom::GetRootPoint (batch 1100)
extern "C" void FASTCALL ext_43e960(float *v, const float *a);                     // v -= a (x87)
extern "C" void FASTCALL ext_441a60(float *v, const float *m);                     // vmtmul (batch 1100)

typedef void *(THISCALL *vcallLog)(void *self, const char *file, u32 line);
typedef void (*cdeclFmt)(void *self, const char *fmt, u32 v);

// 0x4e8ed0 ZCollisionBox::CalcStripsBoundInfo(), thiscall, plain ret. Builds the per-strip bounding boxes that
// FetchPushList culls with. The box array goes right after the strips (16-byte aligned) at this+0x14; when the
// room left in the block (this+0x10 bytes from this+0xc) holds fewer boxes than strips, it logs through the error
// object [0x700390] (slot 0x20 with file 0x697650 line 0xac, then slot 0x2c of the result, cdecl, with format
// 0x6976c8 and this+0x10) and fills only the boxes that fit.
// Each strip header holds the owning geom at +0x10 and a pointer at +0x14 to its quantised local box (six u16 at
// +4: min xyz, max xyz, biased by 0x8000). The box is decoded with the octree node of the geom's room (node =
// (word at [geom+0x6c] + [[[0x70039c]+0x1aa3]+0x20] + 0x28, low bit cleared) + [[[0x70039c]+0x9b]+0xaec]; origin at
// node+4, 1/units at node+0x10), its centre is taken to world space (GetRootPoint), then into the box's own space
// (minus this+0x3c, times the transpose of this+0x18); its half extents go through TransformBox with
// (this+0x18) * rootmat(geom). The matrices and node are recomputed only when the geom changes.
static void THISCALL calcStripsBoundInfo(u8 *self) {
  u8 *strips = *(u8 **)(self + 0xc);
  if (!strips)
    return;
  u32 ns = *(u32 *)(self + 8);
  u32 nv = 0;
  u8 *s = strips;
  for (u32 k = ns; k; k--) {
    u32 n = *(u32 *)s;
    nv += n;
    s += (n * 3 + 6) * 4;
  }
  u8 *boxes = strips + (((nv + ns * 2) * 12 + 0xf) & 0xfffffff0u);
  *(u8 **)(self + 0x14) = boxes;
  s32 room = (s32)(strips - boxes + *(u32 *)(self + 0x10)) / 24;
  u32 count = ns;
  if ((u32)room < ns) {
    count = (u32)room;
    void *eh = G(void *, 0x700390);
    void *o = ((vcallLog)(*(void ***)eh)[0x20 / 4])(eh, (const char *)0x697650u, 0xacu);
    ((cdeclFmt)(*(void ***)o)[0x2c / 4])(o, (const char *)0x6976c8u, *(u32 *)(self + 0x10));
  }
  u8 *sys = G(u8 *, 0x70039c);
  float O[3] = {0.0f, 0.0f, 0.0f};
  float units = 1.0f;
  float *box = *(float **)(self + 0x14);
  u8 *strip = *(u8 **)(self + 0xc);
  u32 off = *(u32 *)(*(u8 **)(sys + 0x1aa3) + 0x20);
  u8 *octBase = *(u8 **)(*(u8 **)(sys + 0x9b) + 0xaec);
  float R[9];
  u8 *prev = 0;
  for (; count; count--) {
    u8 *geom = *(u8 **)(strip + 0x10);
    const u8 *q = *(u8 *const *)(strip + 0x14);
    if (geom != prev) {
      prev = geom;
      u8 *node = (u8 *)((*(u32 *)(*(u8 **)(geom + 0x6c) + off + 0x28) & 0xfffffffeu) + (u32)octBase);
      units = *(float *)(node + 0x10);
      ext_4e3340(node, O);
      float M[9];
      ext_4de7a0(M);
      ext_4db5a0(geom, M);
      ext_4de440(R, (const float *)(self + 0x18), M);
    }
    float inv = 1.0f / units;
    const u16 *w = (const u16 *)(q + 4);
    float lx = ((float)((s32)w[0] - 0x8000) * inv) + O[0];
    float ly = ((float)((s32)w[1] - 0x8000) * inv) + O[1];
    float lz = ((float)((s32)w[2] - 0x8000) * inv) + O[2];
    float hx = ((float)((s32)w[3] - 0x8000) * inv) + O[0];
    float hy = ((float)((s32)w[4] - 0x8000) * inv) + O[1];
    float hz = ((float)((s32)w[5] - 0x8000) * inv) + O[2];
    float C[3], H[3];
    C[0] = (hx + lx) * 0.5f;
    C[1] = (hy + ly) * 0.5f;
    C[2] = (hz + lz) * 0.5f;
    H[0] = C[0] - lx;
    H[1] = C[1] - ly;
    H[2] = C[2] - lz;
    ext_4e2c60(R, H);
    ext_4db670(geom, C);
    ext_43e960(C, (const float *)(self + 0x3c));
    ext_441a60(C, (const float *)(self + 0x18));
    float c0 = C[0], c1 = C[1], c2 = C[2], h0 = H[0], h1 = H[1], h2 = H[2];
    box[0] = c0 - h0;
    box[1] = c1 - h1;
    box[2] = c2 - h2;
    box[3] = h0 + c0;
    box[4] = h1 + c1;
    box[5] = h2 + c2;
    box += 6;
    strip += (*(u32 *)strip + 2) * 12;
  }
}
PCREG(4e8ed0, calcStripsBoundInfo);
