// batch1520.cpp - recruits thread, batch 1520: BasicShape::GetSplinePos (the spline position of a follow shape).
#include "ff.h"

// ParametricCurve::GetSplinePos(float out[2]&, float t) const, thiscall, ret 8 (exe code; the port is batch21 of
// inline-batch45, verified there).
extern "C" void THISCALL ext_4604f0(u8 *curve, float *out, float t);

// 0x460aa0 BasicShape::GetSplinePos(float out[3]&, float t), thiscall, ret 8.
// The shape has n = +0x10 segments and a record array at +0xc, 56 bytes per segment (the curve reads its first 13
// floats, see ParametricCurve::GetSplinePos). x = n * t (single precision); segment = int(x),
// clamped to n - 1 when it is >= n; the local parameter is x - segment (x is not clamped here, as in the original).
static void THISCALL basicShapeGetSplinePos(u8 *self, float *out, float t) {
  s32 n = *(s32 *)(self + 0x10);
  float x = (float)n * t;
  s32 seg = _mm_cvttss_si32(_mm_set_ss(x));
  if (seg >= n)
    seg = n - 1;
  float local = x - (float)seg;
  u8 *rec = *(u8 **)(self + 0xc) + 56 * (u32)seg;
  ext_4604f0(rec, out, local);
}
PCREG(460aa0, basicShapeGetSplinePos);

// ---------------------------------------------------------------- batch 1521 (same file, shape field reader)
// 0x4c79f0 (GUESS: BasicShape::ReadFields(DBREAD&)), thiscall, ret 4, returns AL = 1. Reads the shape fields from the
// stream in this order: u32 -> +0x54; float -> +0x48; float -> +0x50; u32 != 0 -> +0x58 (byte); u32 != 0 -> +0x59
// (byte); u32 -> +0x5e; u32 -> +0x62. The same stream order as ZFollowShape::Init.
extern "C" u32 THISCALL ext_4e5e60(void *db);
extern "C" float THISCALL ext_4e5e80(void *db);

static u8 THISCALL basicShapeReadFields(u8 *self, void *db) {
  *(u32 *)(self + 0x54) = ext_4e5e60(db);
  *(float *)(self + 0x48) = ext_4e5e80(db);
  *(float *)(self + 0x50) = ext_4e5e80(db);
  *(u8 *)(self + 0x58) = ext_4e5e60(db) != 0;
  *(u8 *)(self + 0x59) = ext_4e5e60(db) != 0;
  *(u32 *)(self + 0x5e) = ext_4e5e60(db);
  *(u32 *)(self + 0x62) = ext_4e5e60(db);
  return 1;
}
PCREG(4c79f0, basicShapeReadFields);
