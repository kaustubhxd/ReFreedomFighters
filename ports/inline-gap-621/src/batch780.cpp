// batch780.cpp - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

// Matcher callback: the object's vt[0x1c] is caller-cleaned (cdecl, four words: obj, p1, p2, string).
typedef int(__attribute__((cdecl)) *MatchFn)(u8 *, u32, u32, u32);

// 0x62cac0, cdecl(st, code, p1, p2, obj) returns int. Code 18 tests eight table strings (0x6f4458[0..7]) and then the
// fixed string 0x6c01e0 through obj->vt[0x1c]; code 23 moves the state to 0x62cb80; everything else is the default path.
static int __attribute__((cdecl)) matchStep_62cac0(u8 *st, u32 code, u32 p1, u32 p2, u8 *obj) {
  if (code == 0xfu) return 0;
  if (code == 0x17u) {                // code 23
    *(u32 *)st = 0x62cb80u;
    return 0;
  }
  if (code == 0x12u) {                // code 18
    MatchFn f = (MatchFn)(*(u32 *)(obj + 0x1c));   // a function pointer stored in the object, not a vtable slot
    for (u32 i = 0; i < 8; i++) {
      u32 s = *(u32 *)(0x6f4458u + i * 4);
      if (f(obj, p1, p2, s) != 0) {
        *(u32 *)st = 0x62cd30u;
        return (int)(i + 0x14);
      }
    }
    if (f(obj, p1, p2, 0x6c01e0u) != 0) {
      *(u32 *)st = 0x62cc50u;
      return 0;
    }
  }
  // default path
  if (*(u32 *)(st + 0xc) == 0 && code == 0x1cu) return 0x34;
  *(u32 *)st = 0x51f230u;
  return -1;
}
PCREG(62cac0, matchStep_62cac0);
