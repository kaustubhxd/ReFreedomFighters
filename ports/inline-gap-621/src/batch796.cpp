// batch796.cpp - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

extern "C" u32 __attribute__((cdecl)) ext_628c80(u32 g, u32 a, u32 flag, u32 b, u32 c, u32 d);   // original, cdecl six words

// 0x628e70, cdecl(a, b, c, d): the flag word is 1. Returns the callee's eax.
static u32 __attribute__((cdecl)) wrapFlag1_628e70(u32 a, u32 b, u32 c, u32 d) {
  return ext_628c80(0x6f4424u, a, 1u, b, c, d);
}
PCREG(628e70, wrapFlag1_628e70);

// 0x628eb0, cdecl(a, b, c, d): the flag word is 0. Returns the callee's eax.
static u32 __attribute__((cdecl)) wrapFlag0_628eb0(u32 a, u32 b, u32 c, u32 d) {
  return ext_628c80(0x6f4424u, a, 0u, b, c, d);
}
PCREG(628eb0, wrapFlag0_628eb0);
