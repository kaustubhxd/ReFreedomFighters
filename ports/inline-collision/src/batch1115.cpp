// batch1115.cpp - collision thread, batch 1115: geom frame helpers used by the ZCollisionBase box queries.
#include "ff.h"

extern "C" void FASTCALL ext_441a60(float *v, const float *m);       // vmtmul in place (batch 1100)
extern "C" void FASTCALL ext_4419f0(float *v, const float *m);       // vmmul in place (batch 48)
extern "C" void FASTCALL ext_43e960(float *v, const float *a);       // v -= a (x87)
extern "C" void THISCALL ext_4db270(const u8 *g, float *v);          // GetLocalVect (batch 1108)
extern "C" void THISCALL ext_4db1f0(const u8 *g, float *p);          // GetLocalPoint (batch 1108)
extern "C" void THISCALL ext_4db150(const u8 *g, float *m);
extern "C" void THISCALL ext_4db670(const u8 *g, float *p);          // GetRootPoint (batch 1100)
extern "C" void THISCALL ext_4db780(const u8 *g, float *v);          // GetRootVect (batch 1100)
extern "C" void THISCALL ext_4dc630(u8 *g, u32 set, u32 mask);       // SetControl (batch 1114)

static inline u8 *geomParent(const u8 *g) { return *(u8 *const *)(g + 0x50); }

// 0x459fc0 vmtmul(float *out, const float *v, const float *m) [high], fastcall (out ECX, v EDX, m stack), ret 4.
// out = v * transpose(m), with batch 1100's lane order; all of v is read before out is written.
static void FASTCALL vmtmul3(float *out, const float *v, const float *m) {
  double v0 = v[0], v1 = v[1], v2 = v[2];
  double r0 = ((v0 * m[6]) + (v1 * m[7])) + (v2 * m[8]);
  double r1 = ((v0 * m[3]) + (v1 * m[4])) + (v2 * m[5]);
  double r2 = ((v0 * m[0]) + (v1 * m[1])) + (v2 * m[2]);
  out[0] = (float)r0;
  out[1] = (float)r1;
  out[2] = (float)r2;
}
PCREG(459fc0, vmtmul3);

// 0x4daf90 ZBaseGeom::GetCen(float *out) const [high], thiscall, ret 4: out = the box centre at +0x30.
static void THISCALL getCen(const u8 *self, float *out) {
  ((u32 *)out)[0] = *(const u32 *)(self + 0x30);
  ((u32 *)out)[1] = *(const u32 *)(self + 0x34);
  ((u32 *)out)[2] = *(const u32 *)(self + 0x38);
}
PCREG(4daf90, getCen);

// 0x4db150 ZBaseGeom::GetLocalMat(float *m) const [high], thiscall, ret 4. World rotation to this geom's frame,
// row by row (2, 1, 0): when the geom has a parent, the parent's GetLocalVect, then times transpose(own matrix).
// A root geom leaves m unchanged.
static void THISCALL getLocalMat(const u8 *self, float *m) {
  for (int row = 2; row >= 0; row--) {
    if (!geomParent(self))
      continue;
    ext_4db270(geomParent(self), m + 3 * row);
    ext_441a60(m + 3 * row, (const float *)self);
  }
}
PCREG(4db150, getLocalMat);

// 0x4db1b0 ZBaseGeom::GetLocalMatPos(float *m, float *p) const [medium], thiscall, ret 8: for a geom with a parent,
// p to the local frame (parent's GetLocalPoint, minus +0x24, times transpose(mat)) and GetLocalMat(m).
static void THISCALL getLocalMatPos(const u8 *self, float *m, float *p) {
  if (!geomParent(self))
    return;
  ext_4db1f0(geomParent(self), p);
  ext_43e960(p, (const float *)(self + 0x24));
  ext_441a60(p, (const float *)self);
  ext_4db150(self, m);
}
PCREG(4db1b0, getLocalMatPos);

// 0x4db600 ZBaseGeom::GetRootMatPos(float *m, float *p) const [high], thiscall, ret 8: for a geom with a parent,
// GetRootPoint(p) and each row of m (2, 1, 0) times this matrix then up the parent chain. A root geom changes nothing.
static void THISCALL getRootMatPos(const u8 *self, float *m, float *p) {
  if (!geomParent(self))
    return;
  ext_4db670(self, p);
  for (int row = 2; row >= 0; row--) {
    ext_4419f0(m + 3 * row, (const float *)self);
    if (geomParent(self))
      ext_4db780(geomParent(self), m + 3 * row);
  }
}
PCREG(4db600, getRootMatPos);

// 0x4ec6d0 (unnamed; guessed ZCollisionBase::ClearMarkedGeoms), thiscall: clears control flag 0x10000000 on each of
// the [this+0x1074] geoms listed at this+0x74 (SetControl(0, 0x10000000)), then empties the list.
static void THISCALL clearMarked(u8 *self) {
  for (u32 i = 0; i != *(u32 *)(self + 0x1074); i++)
    ext_4dc630(((u8 **)(self + 0x74))[i], 0, 0x10000000);
  *(u32 *)(self + 0x1074) = 0;
}
PCREG(4ec6d0, clearMarked);
