// batch346.cpp - 0x405090 (gap band). cdecl, one argument v; returns the number of loop iterations of
// { while v != 0: count++, v >>= 1 }, i.e. the bit length of v (0 for v == 0).
#include "ff.h"

static u32 bitLength(u32 v) {
  u32 count = 0;
  while (v != 0) {
    count++;
    v >>= 1;
  }
  return count;
}
PCREG(405090, bitLength);
