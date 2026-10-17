// batch788.cpp - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

static int defaultStep_788(u8 *st, u32 code) {
  if (*(u32 *)(st + 0xc) == 0 && code == 0x1cu) return 0x34;
  *(u32 *)st = 0x51f230u;
  return -1;
}

// 0x62cf00, cdecl(st, code) returns int.
static int __attribute__((cdecl)) stateStep_62cf00(u8 *st, u32 code) {
  if (code == 0xfu) return 0;
  if (code == 0x19u) {
    *(u32 *)(st + 8) += 1u;
    *(u32 *)st = 0x62dbb0u;
    return 0;
  }
  return defaultStep_788(st, code);
}
PCREG(62cf00, stateStep_62cf00);

// 0x62cf40, cdecl(st, code) returns int.
static int __attribute__((cdecl)) stateStep_62cf40(u8 *st, u32 code) {
  if (code == 0xfu) return 0;
  if (code == 0x19u) {
    *(u32 *)st = 0x62dbb0u;
    return 0x33;
  }
  return defaultStep_788(st, code);
}
PCREG(62cf40, stateStep_62cf40);

// 0x62d110, cdecl(st, code) returns int.
static int __attribute__((cdecl)) stateStep_62d110(u8 *st, u32 code) {
  if (code == 0xfu) return 0;
  if (code == 0x1bu) {
    *(u32 *)st = 0x62d160u;
    return 5;
  }
  return defaultStep_788(st, code);
}
PCREG(62d110, stateStep_62d110);

// 0x62d160, cdecl(st, code) returns int.
static int __attribute__((cdecl)) stateStep_62d160(u8 *st, u32 code) {
  if (code == 0xfu) return 0;
  if (code == 0x1bu) {
    *(u32 *)st = 0x62d1b0u;
    return 4;
  }
  return defaultStep_788(st, code);
}
PCREG(62d160, stateStep_62d160);

// 0x62ddb0, cdecl(st, code) returns int.
static int __attribute__((cdecl)) stateStep_62ddb0(u8 *st, u32 code) {
  if (code == 0xfu) return 0;
  if (code == 0x12u) {
    *(u32 *)st = 0x62de00u;
    return 0xf;
  }
  return defaultStep_788(st, code);
}
PCREG(62ddb0, stateStep_62ddb0);

// 0x62dee0, cdecl(st, code) returns int.
static int __attribute__((cdecl)) stateStep_62dee0(u8 *st, u32 code) {
  if (code == 0xfu) return 0;
  if (code == 0x1bu) {
    *(u32 *)st = 0x62cf90u;
    return 0x10;
  }
  return defaultStep_788(st, code);
}
PCREG(62dee0, stateStep_62dee0);
