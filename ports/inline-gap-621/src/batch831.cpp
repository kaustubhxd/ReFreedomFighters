// batch831.cpp - gap band small functions (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

// 0x634861: cdecl() - returns ([0x6f5670] == 0)
static u32 __attribute__((cdecl)) isZero_634861() { return G(u32, 0x6f5670) == 0; }
PCREG(634861, isZero_634861);

// 0x63ce20: thiscall() ret 0 - walks the +8 links starting at this[8]; counts nodes until the walk returns to the
// first node or hits null (count is a byte; 0 when this[8] is null)
static u32 THISCALL ringCount_63ce20(u8 *self) {
  u8 *first = *(u8 **)(self + 8);
  u8 *p = first;
  u8 n = 0;
  if (p) {
    do {
      p = *(u8 **)(p + 8);
      n++;
    } while (p != first && p);
  }
  return n;
}
PCREG(63ce20, ringCount_63ce20);
