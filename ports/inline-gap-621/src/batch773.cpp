// batch773.cpp - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

// 0x6344f2, cdecl(a) returns a value. c = [0x6f5630] (the stack-cookie global). The original rotates a right by
// (32 - (c & 31)) (the x86 count is masked to 5 bits, so a count of 0 means no rotation) and XORs the result with c.
static u32 __attribute__((cdecl)) rotCookie_6344f2(u32 a) {
  u32 c = *(u32 *)0x6f5630u;
  u32 n = (32u - (c & 31u)) & 31u;
  u32 r = n == 0 ? a : ((a >> n) | (a << (32u - n)));
  return r ^ c;
}
PCREG(6344f2, rotCookie_6344f2);
