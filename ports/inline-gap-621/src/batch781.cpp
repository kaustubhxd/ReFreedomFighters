// batch781.cpp - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

// The object's callback at [obj+0x1c] is caller-cleaned (cdecl, four words: obj, a, p2, string).
typedef int(__attribute__((cdecl)) *MatchFn2)(u8 *, u32, u32, u32);

// 0x62cd30, cdecl(st, code, p1, p2, obj) returns int. Code 20 tries three strings through the callback, each time with
// a = p1 + [obj+0x44]; code 27 moves the state to 0x62ca20; everything else is the default path.
static int __attribute__((cdecl)) matchStep_62cd30(u8 *st, u32 code, u32 p1, u32 p2, u8 *obj) {
  if (code == 0xfu) return 0;
  if (code == 0x1bu) {                    // code 27
    *(u32 *)st = 0x62ca20u;
    return 0x21;
  }
  if (code == 0x14u) {                    // code 20
    MatchFn2 f = (MatchFn2)(*(u32 *)(obj + 0x1c));
    if (f(obj, p1 + *(u32 *)(obj + 0x44), p2, 0x6c01b4u) != 0) {
      *(u32 *)st = 0x62ca20u;
      return 0x1f;
    }
    if (f(obj, p1 + *(u32 *)(obj + 0x44), p2, 0x6c01fcu) != 0) {
      *(u32 *)st = 0x62ca20u;
      return 0x20;
    }
    if (f(obj, p1 + *(u32 *)(obj + 0x44), p2, 0x6c0190u) != 0) {
      *(u32 *)st = 0x62ce20u;
      return 0;
    }
  }
  // default path
  if (*(u32 *)(st + 0xc) == 0 && code == 0x1cu) return 0x34;
  *(u32 *)st = 0x51f230u;
  return -1;
}
PCREG(62cd30, matchStep_62cd30);
