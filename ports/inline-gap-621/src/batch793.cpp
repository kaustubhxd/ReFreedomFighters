// batch793.cpp - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

typedef int(__attribute__((cdecl)) *MatchFn7)(u8 *, u32, u32, u32);

static int defaultStep_793(u8 *st, u32 code) {
  if (*(u32 *)(st + 0xc) == 0 && code == 0x1cu) return 0x34;
  *(u32 *)st = 0x51f230u;
  return -1;
}

// 0x62d360, cdecl(st, code, p1, p2, obj) returns int.
static int __attribute__((cdecl)) stateMatch_62d360(u8 *st, u32 code, u32 p1, u32 p2, u8 *obj) {
  if (code == 0xfu) return 0;
  if (code == 0x12u || code == 0x29u) {
    *(u32 *)st = 0x62d690u;
    return 0x2e;
  }
  if (code == 0x14u) {
    MatchFn7 f = (MatchFn7)(*(u32 *)(obj + 0x1c));
    if (f(obj, p1 + *(u32 *)(obj + 0x44), p2, 0x6c01ecu) != 0) {
      *(u32 *)st = 0x62d470u;
      return 0x26;
    }
  }
  if (code == 0x17u) {
    *(u32 *)st = 0x62d5c0u;
    *(u32 *)(st + 4) = 2u;
    return 0x27;
  }
  if (code == 0x1eu) {
    *(u32 *)st = 0x62d690u;
    return 0x30;
  }
  if (code == 0x1fu) {
    *(u32 *)st = 0x62d690u;
    return 0x2f;
  }
  if (code == 0x20u) {
    *(u32 *)st = 0x62d690u;
    return 0x31;
  }
  return defaultStep_793(st, code);
}
PCREG(62d360, stateMatch_62d360);
