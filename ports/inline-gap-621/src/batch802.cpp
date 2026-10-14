// batch802.cpp - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

// Three-byte bit lookup. t = tab[((b1 >> 2) & 15) + 16 * (b0 & 15)]; e = (b1 & 3) + 4t; the result is the word at
// 0x6bf720[((b2 >> 5) & 1) + 2e] AND (1 << (b2 & 31)).
static u32 bitLookup3_802(const u8 *tab, const u8 *p) {
  u32 b0 = p[0], b1 = p[1], b2 = p[2];
  u32 t = tab[((b1 >> 2) & 15u) + 16u * (b0 & 15u)];
  u32 e = (b1 & 3u) + 4u * t;
  u32 w = *(const u32 *)(0x6bf720u + 4u * (((b2 >> 5) & 1u) + 2u * e));
  return w & (1u << (b2 & 31u));
}

// 0x6244e0, cdecl(unused, p) returns int; the first stack word is not read.
static u32 __attribute__((cdecl)) bitLookup3A_6244e0(u32 unused, const u8 *p) {
  (void)unused;
  return bitLookup3_802((const u8 *)0x6bfd20u, p);
}
PCREG(6244e0, bitLookup3A_6244e0);

// 0x624650, cdecl(unused, p) returns int: as 0x6244e0 with byte table 0x6bfc20.
static u32 __attribute__((cdecl)) bitLookup3B_624650(u32 unused, const u8 *p) {
  (void)unused;
  return bitLookup3_802((const u8 *)0x6bfc20u, p);
}
PCREG(624650, bitLookup3B_624650);
