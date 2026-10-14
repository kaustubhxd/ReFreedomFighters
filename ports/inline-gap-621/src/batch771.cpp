// batch771.cpp - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

// 0x640c90, stdcall(p) ret 4, returns bool (al). True when the word at [p+0x5a] is nonzero and [p+0x3c] has no 0x2000 bit.
static bool STDCALL flagTest_640c90(u8 *p) {
  if (*(u16 *)(p + 0x5a) == 0) return false;
  if (*(u32 *)(p + 0x3c) & 0x2000u) return false;
  return true;
}
PCREG(640c90, flagTest_640c90);

// 0x624960, cdecl(x, p), returns int. The first stack word is never read; the pointer is the second word.
// 1 when byte [p] == 0xf4 and byte [p+1] has a 0x30 bit; 0 otherwise.
static int __attribute__((cdecl)) lead_f4_624960(u32 unused, u8 *p) {
  if (p[0] != 0xf4) return 0;
  if ((p[1] & 0x30) == 0) return 0;
  return 1;
}
PCREG(624960, lead_f4_624960);
