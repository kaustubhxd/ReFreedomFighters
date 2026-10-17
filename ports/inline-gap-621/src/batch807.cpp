// batch807.cpp - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

extern "C" u32 __attribute__((cdecl)) ext_634cb5(void);   // original status probe (GUESS), hooked in the spec

// 0x633e8f, cdecl(flag) returns int. When the probe returns nonzero and the flag byte is zero, exchanges the word at
// 0x725494 with zero (xchg) and returns the old value; otherwise returns the probe's value.
static u32 __attribute__((cdecl)) releaseIfProbe_633e8f(u8 flag) {
  u32 r = ext_634cb5();
  if (r != 0 && flag == 0) {
    u32 old = *(volatile u32 *)0x725494u;
    *(volatile u32 *)0x725494u = 0;
    return old;
  }
  return r;
}
PCREG(633e8f, releaseIfProbe_633e8f);
