// batch378.cpp - 0x40b6a0 (gap band). cdecl(a0, a1, a2, a3, a4), 32-bit integers. diff = (a3 & 0x7fff) - (a2 & 0x7fff);
// q = (|diff| * (a4 - a0)) / (a1 - a0) (signed, truncating: idiv); return diff >= 0 ? q + (a2 & 0x7fff) : (a2 & 0x7fff) - q.
// The exe faults on a zero divisor (and on INT_MIN / -1); the spec keeps the divisor nonzero and not -1.
#include "ff.h"

static s32 maskedBlend(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
  s32 x2 = (s32)((u32)a2 & 0x7fffu);
  s32 x3 = (s32)((u32)a3 & 0x7fffu);
  s32 diff = (s32)((u32)x3 - (u32)x2);
  s32 sgn = diff >> 31;
  s32 absd = (s32)(((u32)diff ^ (u32)sgn) - (u32)sgn);
  s32 prod = (s32)((u32)absd * ((u32)a4 - (u32)a0));
  s32 den = (s32)((u32)a1 - (u32)a0);
  s32 q = prod / den;
  if (diff >= 0)
    return (s32)((u32)q + (u32)x2);
  return (s32)((u32)x2 - (u32)q);
}
PCREG(40b6a0, maskedBlend);
