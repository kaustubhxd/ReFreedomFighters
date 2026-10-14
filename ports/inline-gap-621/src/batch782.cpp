// batch782.cpp - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

// 0x62ce20, cdecl(st, code) returns int. Code 15 returns 0; code 27 moves the state to 0x62ca20.
static int __attribute__((cdecl)) stateStep_62ce20(u8 *st, u32 code) {
  if (code == 0xfu) return 0;
  if (code == 0x1bu) {
    *(u32 *)st = 0x62ca20u;
    return 0x22;
  }
  if (*(u32 *)(st + 0xc) == 0 && code == 0x1cu) return 0x34;
  *(u32 *)st = 0x51f230u;
  return -1;
}
PCREG(62ce20, stateStep_62ce20);

// 0x62cf90, cdecl(st, code) returns int. Code 15 returns 0; code 17 picks the vtable by st+0xc and returns 0.
static int __attribute__((cdecl)) stateStep_62cf90(u8 *st, u32 code) {
  if (code == 0xfu) return 0;
  if (code == 0x11u) {
    *(u32 *)st = (*(u32 *)(st + 0xc) != 0) ? 0x62dc60u : 0x62dbb0u;
    return 0;
  }
  if (*(u32 *)(st + 0xc) == 0 && code == 0x1cu) return 0x34;
  *(u32 *)st = 0x51f230u;
  return -1;
}
PCREG(62cf90, stateStep_62cf90);
