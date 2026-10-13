#include "ff.h"
// batch979.cpp - unclaimed-80 residue-19 (docs/20-unclaimed-80.md), batch 57: 0x64fc70 (thiscall, no arguments, returns an int in eax).
// n = self.vt[0xd8]() (int). f = (float)n. g = self.vt[0xf4]() (float in st0). res = f / g (fdivr); eax = cvttss2si(res) (0x80000000 when out of range or NaN).

typedef u32(THISCALL *tc0)(u8 *);
typedef float(THISCALL *tcf)(u8 *);

static u32 THISCALL zg64fc70(u8 *self) {
  u32 n = ((tc0)(*(u32 *)(*(u32 *)self + 0xd8)))(self);
  float f = (float)(s32)n;
  float g = ((tcf)(*(u32 *)(*(u32 *)self + 0xf4)))(self);
  float res = f / g;
  if (!(res > -2147483648.0f && res < 2147483648.0f)) return 0x80000000u;
  return (u32)(s32)res;
}
PCREG(64fc70, zg64fc70);
