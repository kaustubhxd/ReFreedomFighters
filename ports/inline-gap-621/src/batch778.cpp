// batch778.cpp - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

// 0x62d5c0, cdecl(st, code) returns int. State handler: codes 18 and 41 and codes 30, 31, 32 set the vtable [st] to
// 0x62d690; code 23 increments the counter at [st+4]. Other codes take the default path.
static int __attribute__((cdecl)) stateStep_62d5c0(u8 *st, u32 code) {
  u32 k = code - 0xfu;
  if (k == 0) return 0;
  if (k == 3 || k == 0x1a) {          // codes 18, 41
    *(u32 *)st = 0x62d690u;
    return 0x2e;
  }
  if (k == 8) {                       // code 23
    *(u32 *)(st + 4) += 1u;
    return 0x27;
  }
  if (k == 15) {                      // code 30
    *(u32 *)st = 0x62d690u;
    return 0x30;
  }
  if (k == 16) {                      // code 31
    *(u32 *)st = 0x62d690u;
    return 0x2f;
  }
  if (k == 17) {                      // code 32
    *(u32 *)st = 0x62d690u;
    return 0x31;
  }
  // default path
  if (*(u32 *)(st + 0xc) == 0 && code == 0x1cu) return 0x34;
  *(u32 *)st = 0x51f230u;
  return -1;
}
PCREG(62d5c0, stateStep_62d5c0);
