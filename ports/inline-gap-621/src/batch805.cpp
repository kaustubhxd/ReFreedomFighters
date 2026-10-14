// batch805.cpp - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

// Case-folding compare of two zero-terminated strings: lowercase letters fold to uppercase. Returns 1 when equal.
static u8 fold805(u8 c) {
  if ((u8)(c - 0x61u) <= 0x19u) c = (u8)(c - 0x20u);
  return c;
}

// 0x62c5b0, cdecl(s1, s2) returns 0 or 1.
static u32 __attribute__((cdecl)) ieqZ_62c5b0(const u8 *s1, const u8 *s2) {
  for (u32 i = 0;; i++) {
    u8 a = fold805(s1[i]);
    u8 b = fold805(s2[i]);
    if (a != b) return 0;
    if (a == 0) return 1;
  }
}
PCREG(62c5b0, ieqZ_62c5b0);
