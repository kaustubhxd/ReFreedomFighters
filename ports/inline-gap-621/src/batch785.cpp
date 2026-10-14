// batch785.cpp - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

// Shared default path: code 0x1c with a null st+0xc returns 0x34; otherwise the state becomes 0x51f230 and the result is -1.
static int defaultStep_785(u8 *st, u32 code) {
  if (*(u32 *)(st + 0xc) == 0 && code == 0x1cu) return 0x34;
  *(u32 *)st = 0x51f230u;
  return -1;
}

// 0x62d560, cdecl(st, code) returns int.
static int __attribute__((cdecl)) stateStep_62d560(u8 *st, u32 code) {
  if (code == 0xfu) return 0;
  if (code == 0x15u) {
    *(u32 *)st = 0x62d510u;
    return 0;
  }
  if (code == 0x24u) {
    *(u32 *)st = 0x62cf90u;
    return 0x29;
  }
  return defaultStep_785(st, code);
}
PCREG(62d560, stateStep_62d560);
