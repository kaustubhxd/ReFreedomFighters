// batch758.cpp - gap band batch 758 (docs/20-gap-band-401000.md): 0x410db0, cdecl, (p, b), void. A bit-position update.
#include "ff.h"
typedef int i32;

static void __attribute__((cdecl)) fn410db0(u32 *p, u32 b) {
  const i32 t = (i32)(b + p[1]);
  p[1] = (u32)t & 7;
  const i32 edx7 = t < 0 ? 7 : 0;
  const i32 q = (t + edx7) >> 3;
  p[3] = (u32)((i32)p[3] + q);
  p[0] = (u32)((i32)p[0] + q);
}

PCREG(410db0, fn410db0);
