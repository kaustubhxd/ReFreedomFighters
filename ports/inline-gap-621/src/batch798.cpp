// batch798.cpp - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

// 0x63dbc0, thiscall(a) ret 4, returns an entry pointer or 0 (GUESS name). Searches the pointer array at this+0xf0
// (count at this+0xec) for the first entry whose field at +0x10029 equals a; a == 0 matches the first entry.
static u8 *THISCALL findEntry_63dbc0(u8 *self, u32 a) {
  u32 n = *(u32 *)(self + 0xec);
  if (n == 0) return 0;
  for (u32 i = 0; i < n; i++) {
    u8 *e = *(u8 **)(self + 0xf0 + 4u * i);
    if (a == 0u || a == *(u32 *)(e + 0x10029)) return e;
  }
  return 0;
}
PCREG(63dbc0, findEntry_63dbc0);
