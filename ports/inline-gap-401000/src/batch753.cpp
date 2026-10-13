// batch753.cpp - gap band batch 753 (docs/20-gap-band-401000.md): 0x40e240, cdecl, the template of 0x40ce80 with callee 0x40e270.
#include "ff.h"

extern "C" u32 __attribute__((cdecl)) ext_40e270(u32 n, u32 b, u32 base, u32 end, u32 c);   // five arguments (caller cleans)

static u32 __attribute__((cdecl)) fn40e240(u32 a, u32 b) {
  const u32 n = G(u32, a);
  if (n == 1) return n;
  const u32 base = G(u32, a + 4);
  const u32 c = G(u32, a + 8);
  return ext_40e270(n, b, base, base + 4 * n, c);
}

PCREG(40e240, fn40e240);
