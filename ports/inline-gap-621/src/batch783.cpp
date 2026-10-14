// batch783.cpp - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

// Default path shared by the state handlers in this batch: code 0x1c with a null st+0xc returns 0x34, else the state
// becomes 0x51f230 and the result is -1.
static int defaultStep_783(u8 *st, u32 code) {
  if (*(u32 *)(st + 0xc) == 0 && code == 0x1cu) return 0x34;
  *(u32 *)st = 0x51f230u;
  return -1;
}

// 0x62cc50, cdecl(st, code) returns int.
static int __attribute__((cdecl)) stateStep_62cc50(u8 *st, u32 code) {
  if (code == 0xfu) return 0;
  if (code == 0x17u) {
    *(u32 *)st = 0x62cc90u;
    return 0;
  }
  return defaultStep_783(st, code);
}
PCREG(62cc50, stateStep_62cc50);

// 0x62cc90, cdecl(st, code) returns int.
static int __attribute__((cdecl)) stateStep_62cc90(u8 *st, u32 code) {
  if (code == 0xfu) return 0;
  if (code == 0x12u) {
    *(u32 *)st = 0x62cce0u;
    return 0x1d;
  }
  return defaultStep_783(st, code);
}
PCREG(62cc90, stateStep_62cc90);

// 0x62cc00, cdecl(st, code) returns int.
static int __attribute__((cdecl)) stateStep_62cc00(u8 *st, u32 code) {
  if (code == 0xfu) return 0;
  if (code == 0x15u) {
    *(u32 *)st = 0x62cb80u;
    return 0;
  }
  if (code == 0x18u) {
    *(u32 *)st = 0x62cd30u;
    return 0;
  }
  return defaultStep_783(st, code);
}
PCREG(62cc00, stateStep_62cc00);
