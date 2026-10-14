// batch795.cpp - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

extern "C" u32 __attribute__((cdecl)) ext_626b00(u32 a, u32 b, u32 c, u32 d);   // original, cdecl four words

// 0x626d70, cdecl(a, b, c, d). Calls 0x626b00 with the same four words; when it returns a pointer, marks byte +0x86 as 0x17.
static void __attribute__((cdecl)) markResult_626d70(u32 a, u32 b, u32 c, u32 d) {
  u8 *r = (u8 *)ext_626b00(a, b, c, d);
  if (r) r[0x86] = 0x17;
}
PCREG(626d70, markResult_626d70);
