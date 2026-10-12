#include "ff.h"
// batch949.cpp - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x483df0 (high), the settings-from-anim reader. Stdcall, one stack
// argument s, ret 4. Zeroes s+4, s+8, s+0xc, s+0x10, s+0x14. a = [s]; if a == 0 return. s+0xc, s+0x10, s+0x14 = a+0x70, a+0x74, a+0x78
// (dwords). len = (float) sqrt((double) (x*x + y*y + z*z)) in that order, as the double sqrt of the exe helper 0x634d7c (sqrtsd here; a direct ext_634d7c call does not link: vectorcall decoration).
// s+8 = [a+0x64] - [a+0x60] (int). s+4 = len / ((float)(int)s+8 * [0x68c748]).

// sqrtsd: the correctly rounded double sqrt that the CRT helper (0x634d7c, through the IAT) returns for this input.
static double sqrtDouble(double v) {
  double r;
  __asm__("sqrtsd %1, %0" : "=x"(r) : "x"(v));
  return r;
}

static void STDCALL zplayerSettingsFromAnim(u8 *s) {
  *(u32 *)(s + 4) = 0;
  *(u32 *)(s + 8) = 0;
  *(u32 *)(s + 0xc) = 0;
  *(u32 *)(s + 0x10) = 0;
  *(u32 *)(s + 0x14) = 0;
  u8 *a = *(u8 **)s;
  if (a == 0) return;
  *(u32 *)(s + 0xc) = *(u32 *)(a + 0x70);
  *(u32 *)(s + 0x10) = *(u32 *)(a + 0x74);
  *(u32 *)(s + 0x14) = *(u32 *)(a + 0x78);
  float x = *(float *)(s + 0xc);
  float y = *(float *)(s + 0x10);
  float z = *(float *)(s + 0x14);
  float sq = x * x;
  sq = sq + y * y;
  sq = sq + z * z;
  float len = (float)sqrtDouble((double)sq);
  *(u32 *)(s + 8) = *(u32 *)(a + 0x64) - *(u32 *)(a + 0x60);
  float k = (float)(s32)*(u32 *)(s + 8) * G(float, 0x68c748);
  *(float *)(s + 4) = len / k;
}
PCREG(483df0, zplayerSettingsFromAnim);
