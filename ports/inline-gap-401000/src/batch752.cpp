// batch752.cpp - gap band batch 752 (docs/20-gap-band-401000.md): 0x40ce80, cdecl, one argument (and the second stack argument).
#include "ff.h"

extern "C" u32 __attribute__((cdecl)) ext_40ceb0(u32 n, u32 b, u32 base, u32 end, u32 c);   // five arguments (caller cleans)

// eax on the way out: the count n (when n == 1 the exe returns straight away), else the result of 0x40ceb0
static u32 __attribute__((cdecl)) fn40ce80(u32 a, u32 b) {
  const u32 n = G(u32, a);
  if (n == 1) return n;
  const u32 base = G(u32, a + 4);
  const u32 c = G(u32, a + 8);
  return ext_40ceb0(n, b, base, base + 4 * n, c);
}

PCREG(40ce80, fn40ce80);
