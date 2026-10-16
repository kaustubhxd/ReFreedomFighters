// batch775.cpp - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

// 0x62ca20, cdecl(st, code) returns int. A state handler: sets the vtable word at [st] and returns a status code.
// Codes 17, 18 and 41 have their own cases; every other code takes the default path (unsigned range check below).
static int __attribute__((cdecl)) stateStep_62ca20(u8 *st, u32 code) {
  u32 k = code - 0xfu;
  if (k == 0) return 0;
  if (k == 2) {                 // code 17
    *(u32 *)st = (*(u32 *)(st + 0xc) != 0) ? 0x62dc60u : 0x62dbb0u;
    return 0;
  }
  if (k == 3) {                 // code 18
    *(u32 *)st = 0x62cac0u;
    return 0x13;
  }
  if (k == 0x1a + 0) {          // code 41 (k == 26)
    *(u32 *)st = 0x62cac0u;
    return 0x13;
  }
  // default path (codes 16, 19..40 and anything outside 15..41)
  if (*(u32 *)(st + 0xc) == 0 && code == 0x1cu) return 0x34;
  *(u32 *)st = 0x51f230u;
  return -1;
}
PCREG(62ca20, stateStep_62ca20);
