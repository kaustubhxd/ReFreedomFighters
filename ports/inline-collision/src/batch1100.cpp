// batch1100.cpp - collision thread, batch 1100: matrix helpers and ZBaseGeom root transforms used by
// ZCollisionBox::CalcStripsBoundInfo (0x4e8ed0), below ZMovementBase::CheckMovingSphereCollision (0x4883d0).
// Matrices are 3x3 floats stored row by row; the exe's row-vector products walk the rows from the last one
// (lane j of v*m is (v0*m[6+j] + v1*m[3+j]) + v2*m[j]), which is the GameCube layout carried over.
// x87 code runs at 53-bit precision (FPCW 0x27f), so the sums are written in double.
#include "ff.h"

// 0x441970 vmmul(float *out, const float *v, const float *m), fastcall (out ECX, v EDX, m on the stack), ret 4.
// All of v is read before out is written, so out may alias v.
static void FASTCALL vmmul3(float *out, const float *v, const float *m) {
  double v0 = v[0], v1 = v[1], v2 = v[2];
  double r0 = ((v0 * m[6]) + (v1 * m[3])) + (v2 * m[0]);
  double r1 = ((v0 * m[7]) + (v1 * m[4])) + (v2 * m[1]);
  double r2 = ((v0 * m[8]) + (v1 * m[5])) + (v2 * m[2]);
  out[0] = (float)r0;
  out[1] = (float)r1;
  out[2] = (float)r2;
}
PCREG(441970, vmmul3);

// 0x441a60 vmtmul(float *v, const float *m), fastcall, plain ret. v = v times the transpose of m, in place:
// lane 0 = (v0*m[6] + v1*m[7]) + v2*m[8], lane 1 the same with m[3..5], lane 2 with m[0..2].
static void FASTCALL vmtmul(float *v, const float *m) {
  double v0 = v[0], v1 = v[1], v2 = v[2];
  double r0 = ((v0 * m[6]) + (v1 * m[7])) + (v2 * m[8]);
  double r1 = ((v0 * m[3]) + (v1 * m[4])) + (v2 * m[5]);
  double r2 = ((v0 * m[0]) + (v1 * m[1])) + (v2 * m[2]);
  v[0] = (float)r0;
  v[1] = (float)r1;
  v[2] = (float)r2;
}
PCREG(441a60, vmtmul);

extern "C" void FASTCALL ext_4419f0(float *v, const float *m);          // vmmul in place (batch 48)
extern "C" void FASTCALL ext_441940(float *v, const float *a);          // PSVECAdd: v += a

// ZBaseGeom: the local matrix is at +0, the local position at +0x24, the parent geom at +0x50.
static inline u8 *geomParent(const u8 *g) { return *(u8 *const *)(g + 0x50); }

// 0x4db780 ZBaseGeom::GetRootVect(float *v) const, thiscall, ret 4. Rotates v by this geom's matrix and then
// by every parent's, up to the root (no translation).
static void THISCALL GetRootVect(const u8 *self, float *v) {
  ext_4419f0(v, (const float *)self);
  for (const u8 *g = geomParent(self); g; g = geomParent(g))
    ext_4419f0(v, (const float *)g);
}
PCREG(4db780, GetRootVect);

// 0x4db670 ZBaseGeom::GetRootPoint(float *p) const, thiscall, ret 4. p = p * mat + pos for this geom and each
// parent in turn: local point to world point.
static void THISCALL GetRootPoint(const u8 *self, float *p) {
  const u8 *g = self;
  do {
    ext_4419f0(p, (const float *)g);
    ext_441940(p, (const float *)(g + 0x24));
    g = geomParent(g);
  } while (g);
}
PCREG(4db670, GetRootPoint);

// 0x4db5a0 ZBaseGeom::GetRootMat(float *m) const, thiscall, ret 4. Each row of m (row 2, row 1, row 0) is
// rotated by this geom's matrix, then by the parent chain through GetRootVect on the parent.
static void THISCALL GetRootMat(const u8 *self, float *m) {
  for (int row = 2; row >= 0; row--) {
    float *r = m + 3 * row;
    ext_4419f0(r, (const float *)self);
    if (geomParent(self))
      GetRootVect(geomParent(self), r);
  }
}
PCREG(4db5a0, GetRootMat);
