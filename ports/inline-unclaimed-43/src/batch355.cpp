// batch355.cpp - 0x408f90 (gap band). cdecl, one argument v; returns the number of set bits of v (the loop adds the low bit of v
// and shifts v right until it is zero).
#include "ff.h"

static u32 popcountByShift(u32 v) {
  u32 count = 0;
  while (v != 0) {
    count += v & 1u;
    v >>= 1;
  }
  return count;
}
PCREG(408f90, popcountByShift);
