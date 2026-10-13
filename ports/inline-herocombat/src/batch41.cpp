// batch41.cpp - ladder-tree composite, inline session batch 41 (Haiku, night): 0x460af0 BasicShape::GetSplinePosVelocity.
#include "ff.h"

extern "C" void THISCALL ext_4604f0(u8 *self, float *out, float t);  // GetSplinePos, original code (batch 21 port)
extern "C" void THISCALL ext_460570(u8 *self, float *out, float t);  // GetSplineVelocity, original code (batch 40 port)

// 0x460af0, thiscall, three stack args (posOut, velOut, t), ret 0xc. Let n = [this+0x10] and prod = (float)n * t. The
// segment index is trunc(prod), clamped to n-1 when it is not below n (signed compare). frac = prod - (float)index. The
// segment record is at [this+0xc] + index*56 (7 * index, then << 3). GetSplinePos runs on that record with (posOut, frac),
// then GetSplineVelocity with (velOut, frac). The exe keeps frac in the t slot; the port passes it directly.
static void THISCALL getSplinePosVelocity(u8 *self, float *posOut, float *velOut, float t) {
  s32 n = *(s32 *)(self + 0x10);
  float prod = (float)n * t;
  s32 idx = (s32)prod;
  if (idx >= n)
    idx = n - 1;
  float frac = prod - (float)idx;
  u8 *seg = *(u8 **)(self + 0xc) + (u32)idx * 56u;
  ext_4604f0(seg, posOut, frac);
  ext_460570(seg, velOut, frac);
}
PCREG(460af0, getSplinePosVelocity);
