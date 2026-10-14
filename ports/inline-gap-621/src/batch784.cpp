// batch784.cpp - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

// Shared default path: code 0x1c with a null st+0xc returns 0x34; otherwise the state becomes 0x51f230 and the result is -1.
static int defaultStep_784(u8 *st, u32 code) {
  if (*(u32 *)(st + 0xc) == 0 && code == 0x1cu) return 0x34;
  *(u32 *)st = 0x51f230u;
  return -1;
}

// 0x62cce0, cdecl(st, code) returns int.
static int __attribute__((cdecl)) stateStep_62cce0(u8 *st, u32 code) {
  if (code == 0xfu) return 0;
  if (code == 0x15u) {
    *(u32 *)st = 0x62cc90u;
    return 0;
  }
  if (code == 0x18u) {
    *(u32 *)st = 0x62cd30u;
    return 0;
  }
  return defaultStep_784(st, code);
}
PCREG(62cce0, stateStep_62cce0);

// 0x62d510, cdecl(st, code) returns int. Codes 18 and 41 share a case.
static int __attribute__((cdecl)) stateStep_62d510(u8 *st, u32 code) {
  if (code == 0xfu) return 0;
  if (code == 0x12u || code == 0x29u) {
    *(u32 *)st = 0x62d560u;
    return 0x2e;
  }
  return defaultStep_784(st, code);
}
PCREG(62d510, stateStep_62d510);
