// batch792.cpp - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

typedef int(__attribute__((cdecl)) *MatchFn6)(u8 *, u32, u32, u32);

static int defaultStep_792(u8 *st, u32 code) {
  if (*(u32 *)(st + 0xc) == 0 && code == 0x1cu) return 0x34;
  *(u32 *)st = 0x51f230u;
  return -1;
}

// 0x62e070, cdecl(st, code, p1, p2, obj) returns int.
static int __attribute__((cdecl)) stateMatch_62e070(u8 *st, u32 code, u32 p1, u32 p2, u8 *obj) {
  if (code == 0xbu || code == 0xdu || code == 0xeu || code == 0xfu) return 0;
  if (code == 0x10u) {
    MatchFn6 f = (MatchFn6)(*(u32 *)(obj + 0x1c));
    if (f(obj, p1 + 2u * *(u32 *)(obj + 0x44), p2, 0x6c0164u) != 0) {
      *(u32 *)st = 0x62cfe0u;
      return 0;
    }
  }
  if (code == 0x1du) {                // code 29
    *(u32 *)st = 0x51f230u;
    return 2;
  }
  return defaultStep_792(st, code);
}
PCREG(62e070, stateMatch_62e070);
