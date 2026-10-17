// batch240003.cpp - Sonnet-w4a: MSVC 64-bit signed division helpers.
#include "ff.h"

// shift-subtract unsigned 64-bit division (no libcalls in the freestanding build)
static inline void w4a_udivmod(u64 n, u64 d, u64 *q, u64 *r) {
  u64 qq = 0, rr = 0;
  for (int i = 63; i >= 0; i--) {
    rr = (rr << 1) | ((n >> i) & 1);
    if (rr >= d) {
      rr -= d;
      qq |= (u64)1 << i;
    }
  }
  *q = qq;
  *r = rr;
}

// 0x634290 (_alldiv): stdcall(s64 a, s64 b) ret 0x10: a / b truncated toward zero; b == 0 faults in the exe (not exercised)
static u64 STDCALL fn_634290(u32 alo, u32 ahi, u32 blo, u32 bhi) {
  u64 a = ((u64)ahi << 32) | alo, b = ((u64)bhi << 32) | blo;
  bool neg = false;
  if ((s32)ahi < 0) { a = 0 - a; neg = !neg; }
  if ((s32)bhi < 0) { b = 0 - b; neg = !neg; }
  u64 q, r;
  w4a_udivmod(a, b, &q, &r);
  return neg ? 0 - q : q;
}
PCREG(634290, fn_634290);

// 0x634380 (_allrem): stdcall(s64 a, s64 b) ret 0x10: remainder with the sign of a
static u64 STDCALL fn_634380(u32 alo, u32 ahi, u32 blo, u32 bhi) {
  u64 a = ((u64)ahi << 32) | alo, b = ((u64)bhi << 32) | blo;
  bool neg = false;
  if ((s32)ahi < 0) { a = 0 - a; neg = true; }
  if ((s32)bhi < 0) b = 0 - b;
  u64 q, r;
  w4a_udivmod(a, b, &q, &r);
  return neg ? 0 - r : r;
}
PCREG(634380, fn_634380);
