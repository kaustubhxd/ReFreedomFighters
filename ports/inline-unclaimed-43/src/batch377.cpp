// batch377.cpp - 0x403f90 (gap band). cdecl(countp, a, b, d): n = *countp; if n <= 0 return; for i in 0..n-1: x = a[i];
// if x is zero or unordered (NaN): d[i] = 0; else d[i] = x / b[i] (x87 fdiv: long double, stored as float).
// The exe addresses b and d as byte offsets from a (esi = b - a, edx = d - a).
#include "ff.h"

static void divideWhereNonzero(const s32 *countp, u8 *a, u8 *b, u8 *d) {
  s32 n = *countp;
  if (n <= 0)
    return;
  u32 offB = (u32)(unsigned long)b - (u32)(unsigned long)a;
  u32 offD = (u32)(unsigned long)d - (u32)(unsigned long)a;
  u8 *p = a;
  do {
    float x = *(float *)p;
    float y = *(float *)(p + offB);
    if (!(x < 0.0f || x > 0.0f))
      *(float *)(p + offD) = 0.0f;
    else
      *(float *)(p + offD) = (float)((long double)x / (long double)y);
    p += 4;
    n--;
  } while (n != 0);
}
PCREG(403f90, divideWhereNonzero);
