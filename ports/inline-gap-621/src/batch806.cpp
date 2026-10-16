// batch806.cpp - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

extern "C" u32 __attribute__((cdecl)) ext_634d40(u32 g, u32 k, u32 a, u32 b, u32 c, u32 d);   // original, cdecl six words (GUESS)

// 0x633665, cdecl(a, b, c, d) returns the callee's eax. The callee receives the cookie global 0x6f5630 and the constant
// 0x633654 first, then the four words in order.
static u32 __attribute__((cdecl)) wrapCookie_633665(u32 a, u32 b, u32 c, u32 d) {
  return ext_634d40(0x6f5630u, 0x633654u, a, b, c, d);
}
PCREG(633665, wrapCookie_633665);
