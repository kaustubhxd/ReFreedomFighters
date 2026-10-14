// batch791.cpp - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

static int defaultStep_791(u8 *st, u32 code) {
  if (*(u32 *)(st + 0xc) == 0 && code == 0x1cu) return 0x34;
  *(u32 *)st = 0x51f230u;
  return -1;
}

// 0x62de90, cdecl(st, code) returns int.
static int __attribute__((cdecl)) stateStep_62de90(u8 *st, u32 code) {
  if (code == 0xfu) return 0;
  if (code == 0x1bu) {
    *(u32 *)st = 0x62df30u;
    return 0x12;
  }
  return defaultStep_791(st, code);
}
PCREG(62de90, stateStep_62de90);
