// batch825.cpp - gap band function (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

// 0x63480d: cdecl() ret 0 - returns 1 (always)
static u8 __attribute__((cdecl)) return_one_63480d() {
  return 1;
}
PCREG(63480d, return_one_63480d);
