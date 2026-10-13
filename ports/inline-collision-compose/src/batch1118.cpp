// batch1118.cpp - collision thread, batch 1118: ZCollisionBase::GetGeomsInBoxLocal (0x4ed0e0).
#include "ff.h"

extern "C" void FASTCALL ext_4de420(float *dst, const float *src);   // mcpy (3 floats)

// 0x4ed0e0 ZCollisionBase::GetGeomsInBoxLocal(ZBaseGeom **a, ZBaseGeom **b, ZTreeGroup *tree, eGlobalTreeType type,
// const float *mat, const float *vec, int start, bool f24, bool first, bool second, bool f30) const [medium],
// thiscall, ret 0x2c, returns the total count.
// 1. first: n = tree's slot 0x344 (a, b, type, mat, vec, start, f24, f30); a count, starting at 0.
// 2. second: a local copy of vec at [esp-0x10] and a local matrix copy of mat; the tree's slot 0x98 (matrix, vec) runs
//    on the local pair, then this's slot 0x7c (a + n, b, type, matrix, vec, start, f24, f30) adds its count.
static u32 THISCALL getGeomsInBoxLocal(u8 *self, u8 **a, u8 **b, u8 *tree, u32 type, const float *mat, const float *vec,
                                       u32 start, u8 f24, u8 first, u8 second, u8 f30) {
  u32 n = 0;
  if (first)
    n = vcall<u32>(tree, 0x344, a, b, type, mat, vec, start, f24, f30);
  if (!second)
    return n;
  float v[3], m[9];
  v[0] = vec[0];
  v[1] = vec[1];
  v[2] = vec[2];
  ext_4de420(m, mat);
  vcall<void>(tree, 0x98, m, v);
  return vcall<u32>(self, 0x7c, a + n, b, type, m, v, start, f24, f30) + n;
}
PCREG(4ed0e0, getGeomsInBoxLocal);
