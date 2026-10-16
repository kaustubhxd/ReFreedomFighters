// batch779.cpp - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

// 0x62d690, cdecl(st, code) returns int. State handler: codes 24, 35, 36, 37 count down [st+4] and switch the vtable to
// 0x62cf90 when it reaches zero; codes 21 and 38 switch the vtable to 0x62d5c0; code 15 returns 0.
static int __attribute__((cdecl)) stateStep_62d690(u8 *st, u32 code) {
  u32 k = code - 0xfu;
  if (k == 0) return 0;
  if (k == 6) {                       // code 21
    *(u32 *)st = 0x62d5c0u;
    return 0x2c;
  }
  if (k == 9 || k == 20 || k == 21 || k == 22) {   // codes 24, 35, 36, 37: countdown
    int ret = 0;
    if (k == 9) ret = 0x28;
    if (k == 20) ret = 0x2a;
    if (k == 21) ret = 0x29;
    if (k == 22) ret = 0x2b;
    *(u32 *)(st + 4) -= 1u;
    if (*(u32 *)(st + 4) == 0) *(u32 *)st = 0x62cf90u;
    return ret;
  }
  if (k == 23) {                      // code 38
    *(u32 *)st = 0x62d5c0u;
    return 0x2d;
  }
  // default path
  if (*(u32 *)(st + 0xc) == 0 && code == 0x1cu) return 0x34;
  *(u32 *)st = 0x51f230u;
  return -1;
}
PCREG(62d690, stateStep_62d690);
