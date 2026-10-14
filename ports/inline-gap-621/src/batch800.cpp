// batch800.cpp - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

// 0x622aa0, cdecl(st, p) returns a pointer. Skips bytes whose class (st[0x4c + byte]) is 9, 10 or 21.
static u8 *__attribute__((cdecl)) skipClass_622aa0(const u8 *st, const u8 *p) {
  const u8 *tab = st + 0x4c;
  for (;;) {
    u8 c = tab[*p];
    if (c < 9) return (u8 *)p;
    if (c <= 10) {
      p++;
      continue;
    }
    if (c != 21) return (u8 *)p;
    p++;
  }
}
PCREG(622aa0, skipClass_622aa0);
