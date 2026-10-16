// batch789.cpp - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

typedef int(__attribute__((cdecl)) *MatchFn4)(u8 *, u32, u32, u32);

static int defaultStep_789(u8 *st, u32 code) {
  if (*(u32 *)(st + 0xc) == 0 && code == 0x1cu) return 0x34;
  *(u32 *)st = 0x51f230u;
  return -1;
}

// 0x62d030, cdecl(st, code, p1, p2, obj) returns int.
static int __attribute__((cdecl)) stateMatch_62d030(u8 *st, u32 code, u32 p1, u32 p2, u8 *obj) {
  if (code == 0xfu) return 0;
  if (code == 0x11u) {
    *(u32 *)st = 0x62e120u;
    return 7;
  }
  if (code == 0x12u) {
    MatchFn4 f = (MatchFn4)(*(u32 *)(obj + 0x1c));
    if (f(obj, p1, p2, 0x6c0208u) != 0) {
      *(u32 *)st = 0x62d160u;
      return 0;
    }
    if (f(obj, p1, p2, 0x6c01f4u) != 0) {
      *(u32 *)st = 0x62d110u;
      return 0;
    }
  }
  if (code == 0x19u) {
    *(u32 *)st = 0x62dc60u;
    return 6;
  }
  return defaultStep_789(st, code);
}
PCREG(62d030, stateMatch_62d030);
