// batch353.cpp - 0x407ed0 (gap band). cdecl, one argument v; returns the number of right shifts needed to bring v to 1 or
// below (0 for v <= 1).
#include "ff.h"

static u32 halvingsToOne(u32 v) {
  u32 count = 0;
  while (v > 1) {
    v >>= 1;
    count++;
  }
  return count;
}
PCREG(407ed0, halvingsToOne);
