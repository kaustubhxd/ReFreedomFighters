// batch776.cpp - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

// 0x62cb80, cdecl(st, code) returns int. A state handler: sets the vtable word at [st] and returns a status code.
// Codes 18, 19 and 41 share one case; code 15 returns 0; every other code (and unsigned-wrapped values) takes the default path.
static int __attribute__((cdecl)) stateStep_62cb80(u8 *st, u32 code) {
  u32 k = code - 0xfu;
  if (k == 0) return 0;
  if (k == 3 || k == 4 || k == 0x1a) {   // codes 18, 19, 41
    *(u32 *)st = 0x62cc00u;
    return 0x1c;
  }
  // default path
  if (*(u32 *)(st + 0xc) == 0 && code == 0x1cu) return 0x34;
  *(u32 *)st = 0x51f230u;
  return -1;
}
PCREG(62cb80, stateStep_62cb80);
