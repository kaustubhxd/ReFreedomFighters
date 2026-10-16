// batch777.cpp - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

// 0x62d470, cdecl(st, code) returns int. State handler in the same family as 0x62ca20 and 0x62cb80.
static int __attribute__((cdecl)) stateStep_62d470(u8 *st, u32 code) {
  u32 k = code - 0xfu;
  if (k == 0) return 0;
  if (k == 6) {                       // code 21
    *(u32 *)st = 0x62d510u;
    return 0;
  }
  if (k == 9) {                       // code 24
    *(u32 *)st = 0x62cf90u;
    return 0x28;
  }
  if (k == 21) {                      // code 36
    *(u32 *)st = 0x62cf90u;
    return 0x29;
  }
  // default path
  if (*(u32 *)(st + 0xc) == 0 && code == 0x1cu) return 0x34;
  *(u32 *)st = 0x51f230u;
  return -1;
}
PCREG(62d470, stateStep_62d470);
