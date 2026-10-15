// batch9001.cpp - wire-ai thread (2026-10-13): ZFastBoxColi1::AddFace, the face record the ragdoll's contact code reads
// (ConstrainedParticleSystem::CheckCollision3 0x543a90, CollideLineBetweenParticles3 0x5440b0, the capsule test 0x544330).
#include "ff.h"

extern "C" void FASTCALL ext_53d160(float *out, const float *e, const float *s1, const float *s2);   // unit normal of (s1-e)x(s2-e), (0,1,0) when degenerate
extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);   // d = a - b
extern "C" void FASTCALL ext_4de420(float *dst, const float *src);               // mcpy (9 floats)
extern "C" void FASTCALL ext_446ee0(float *d, const float *a, const float *b);   // vcross d = a x b
extern "C" void FASTCALL ext_43e8e0(float *d, const float *a, const float *b);   // d = a + b
extern "C" float THISCALL ext_44c840(float *v);                                  // vnorm in place (length in st0, dropped)
extern "C" void THISCALL ext_4e0d00(float *v, float s);                          // vscalar in place

// 0x6354a0 ZFastBoxColi1::AddFace(ZBaseGeom* geom, const float* a, const float* b, const float* c) (GameCube reference, name low), thiscall,
// ret 0x10. Builds a 0x7c-byte face record on the stack and appends it to the face list at this+0x14 (slot 4(0) returns the new
// element + 4; the record is copied to that address - 4):
//  +0 ref of the geom (geom database slot 0x50), +4 N = unit normal of (b - a) x (c - a) (0x53d160), +0x10..+0x30 the 3x3 inverse
//  of the edge basis [e1 = b - a, e2 = c - a, N] by cofactors over the determinant, +0x34 a, +0x40 b, +0x4c c, +0x58 the negated
//  unit sum of the two edge normals, +0x64 unit(N x (b - a)), +0x70 unit((c - a) x N).
//  Skipped: byte +0x59 set and dot(+0x5a, N) >= 0 (faces turned along +0x5a); geom flag 0x400000 at +0x3c with byte [+0x54]+0x5b
//  clear; |det| < 1e-6 (strictly inside (-1e-6, 1e-6)); with byte +0x6e set, an edge normal (squared length <= 1e-9) or the sum
//  degenerate. With +0x6e clear the edge part is skipped and +0x40..+0x7b are copied from uninitialised stack (as the exe).
static void THISCALL addFace(u8 *self, u8 *geom, const float *a, const float *b, const float *c) {
  u32 R[0x1f];
  float *Rf = (float *)R;
  float N[3];
  ext_53d160(N, a, b, c);
  if (self[0x59]) {
    float d = *(float *)(self + 0x5e) * N[1] + *(float *)(self + 0x5a) * N[0];
    d = d + *(float *)(self + 0x62) * N[2];
    if (d >= 0.0f) return;
  }
  if (*(u32 *)(geom + 0x3c) & 0x400000) {
    if (*(*(u8 **)(geom + 0x54) + 0x5b) == 0) return;
  }
  void *db = *(void **)(*(u8 **)0x70039c + 0x9b);
  u32 ref = vcall<u32>(db, 0x50, geom);
  float e1[3], e2[3];
  ext_43e920(e1, b, a);
  ext_43e920(e2, c, a);
  const float x1 = e1[0], y1 = e1[1], z1 = e1[2], x2 = e2[0], y2 = e2[1], z2 = e2[2], nx = N[0], ny = N[1], nz = N[2];
  const float yx = y2 * x1, zy = z2 * y1, xz = x2 * z1, yz = y2 * z1, xy = x2 * y1, zx = z2 * x1;
  float det = yx * nz + zy * nx;
  det = det + xz * ny;
  det = det - yz * nx;
  det = det - xy * nz;
  det = det - zx * ny;
  if (det > bitsf(0xb58637bdu) && bitsf(0x358637bdu) > det) return;   // 0x6972c8 -1e-6, 0x681370 1e-6
  const float inv = 1.0f / det;
  float m[9];
  m[0] = (y2 * nz - z2 * ny) * inv;
  m[1] = (z1 * ny - y1 * nz) * inv;
  m[2] = (zy - yz) * inv;
  m[3] = (z2 * nx - x2 * nz) * inv;
  m[4] = (x1 * nz - z1 * nx) * inv;
  m[5] = (xz - zx) * inv;
  m[6] = (x2 * ny - y2 * nx) * inv;
  m[7] = (y1 * nx - x1 * ny) * inv;
  m[8] = (yx - xy) * inv;
  R[0] = ref;
  u8 ok = 1;
  ext_4de420(Rf + 4, m);
  Rf[1] = N[0]; Rf[2] = N[1]; Rf[3] = N[2];
  Rf[0xd] = a[0]; Rf[0xe] = a[1]; Rf[0xf] = a[2];
  if (self[0x6e]) {
    Rf[0x10] = b[0]; Rf[0x11] = b[1]; Rf[0x12] = b[2];
    Rf[0x13] = c[0]; Rf[0x14] = c[1]; Rf[0x15] = c[2];
    float d1[3], d2[3];
    ext_43e920(d1, b, a);
    ext_43e920(d2, c, a);
    float *S = Rf + 0x16, *Pb = Rf + 0x19, *Pc = Rf + 0x1c;
    ext_446ee0(Pb, N, d1);
    ext_446ee0(Pc, d2, N);
    ext_43e8e0(S, Pb, Pc);
    float l = Pb[0] * Pb[0] + Pb[1] * Pb[1];
    l = l + Pb[2] * Pb[2];
    if (l > bitsf(0x3089705fu)) ext_44c840(Pb); else ok = 0;   // 0x6970c0 1e-9
    l = Pc[0] * Pc[0] + Pc[1] * Pc[1];
    l = l + Pc[2] * Pc[2];
    if (l > bitsf(0x3089705fu)) ext_44c840(Pc); else ok = 0;
    ext_4e0d00(S, -1.0f);
    l = S[0] * S[0] + S[1] * S[1];
    l = l + S[2] * S[2];
    if (!(l > bitsf(0x3089705fu))) return;
    ext_44c840(S);
    if (!ok) return;
  }
  u8 *p = vcall<u8 *>(*(void **)(self + 0x14), 4, 0);
  u32 *dst = (u32 *)(p - 4);
  for (int i = 0; i < 0x1f; i++) dst[i] = R[i];
}
PCREG(6354a0, addFace);
