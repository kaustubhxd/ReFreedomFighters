// batch786.cpp - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

// Shared default path: code 0x1c with a null st+0xc returns 0x34; otherwise the state becomes 0x51f230 and the result is -1.
static int defaultStep_786(u8 *st, u32 code) {
  if (*(u32 *)(st + 0xc) == 0 && code == 0x1cu) return 0x34;
  *(u32 *)st = 0x51f230u;
  return -1;
}

// 0x62d7f0, cdecl(st, code) returns int.
static int __attribute__((cdecl)) stateStep_62d7f0(u8 *st, u32 code) {
  if (code == 0xfu) return 0;
  if (code == 0x12u) {
    *(u32 *)st = 0x62da60u;
    return 9;
  }
  return defaultStep_786(st, code);
}
PCREG(62d7f0, stateStep_62d7f0);

// 0x62d8f0, cdecl(st, code) returns int.
static int __attribute__((cdecl)) stateStep_62d8f0(u8 *st, u32 code) {
  if (code == 0xfu) return 0;
  if (code == 0x1bu) {
    *(u32 *)st = 0x62d940u;
    return 0xc;
  }
  return defaultStep_786(st, code);
}
PCREG(62d8f0, stateStep_62d8f0);

// 0x62d940, cdecl(st, code) returns int.
static int __attribute__((cdecl)) stateStep_62d940(u8 *st, u32 code) {
  if (code == 0xfu) return 0;
  if (code == 0x1bu) {
    *(u32 *)st = 0x62d990u;
    return 0xb;
  }
  return defaultStep_786(st, code);
}
PCREG(62d940, stateStep_62d940);

// 0x62da10, cdecl(st, code) returns int.
static int __attribute__((cdecl)) stateStep_62da10(u8 *st, u32 code) {
  if (code == 0xfu) return 0;
  if (code == 0x12u) {
    *(u32 *)st = 0x62cf90u;
    return 0xe;
  }
  return defaultStep_786(st, code);
}
PCREG(62da10, stateStep_62da10);
