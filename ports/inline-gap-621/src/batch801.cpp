// batch801.cpp - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

// Case index per class (class - 5, 0..24) and the advance for each case (0 -> 2, 1 -> 3, 2 -> 4, 3 -> 1); case 4 stops.
static const u8 kCase801[25] = {0, 1, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 4, 3};
static const u32 kAdv801[4] = {2, 3, 4, 1};

// 0x6228e0, cdecl(st, p) returns the number of bytes consumed from p.
static u32 __attribute__((cdecl)) span_6228e0(const u8 *st, const u8 *p) {
  const u8 *tab = st + 0x4c;
  const u8 *p0 = p;
  u32 c = (u32)tab[*p] - 5u;
  while (c <= 0x18u) {
    u8 k = kCase801[c];
    if (k == 4) break;
    p += kAdv801[k];
    c = (u32)tab[*p] - 5u;
  }
  return (u32)(p - p0);
}
PCREG(6228e0, span_6228e0);
