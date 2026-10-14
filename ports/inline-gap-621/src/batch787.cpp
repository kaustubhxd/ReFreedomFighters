// batch787.cpp - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

// The object's callback at [obj+0x1c] is caller-cleaned (cdecl, four words: obj, p1, p2, string).
typedef int(__attribute__((cdecl)) *MatchFn3)(u8 *, u32, u32, u32);

static int defaultStep_787(u8 *st, u32 code) {
  if (*(u32 *)(st + 0xc) == 0 && code == 0x1cu) return 0x34;
  *(u32 *)st = 0x51f230u;
  return -1;
}

// 0x62d990, cdecl(st, code, p1, p2, obj) returns int.
static int __attribute__((cdecl)) matchStep_62d990(u8 *st, u32 code, u32 p1, u32 p2, u8 *obj) {
  if (code == 0xfu) return 0;
  if (code == 0x11u) {
    *(u32 *)st = (*(u32 *)(st + 0xc) != 0) ? 0x62dc60u : 0x62dbb0u;
    return 0xd;
  }
  if (code == 0x12u) {
    MatchFn3 f = (MatchFn3)(*(u32 *)(obj + 0x1c));
    if (f(obj, p1, p2, 0x6c01c4u) != 0) {
      *(u32 *)st = 0x62da10u;
      return 0;
    }
  }
  return defaultStep_787(st, code);
}
PCREG(62d990, matchStep_62d990);

// 0x62da60, cdecl(st, code, p1, p2, obj) returns int.
static int __attribute__((cdecl)) matchStep_62da60(u8 *st, u32 code, u32 p1, u32 p2, u8 *obj) {
  if (code == 0xfu) return 0;
  if (code == 0x12u) {
    MatchFn3 f = (MatchFn3)(*(u32 *)(obj + 0x1c));
    if (f(obj, p1, p2, 0x6c0208u) != 0) {
      *(u32 *)st = 0x62db60u;
      return 0;
    }
    if (f(obj, p1, p2, 0x6c01f4u) != 0) {
      *(u32 *)st = 0x62db10u;
      return 0;
    }
  }
  if (code == 0x1bu) {
    *(u32 *)st = 0x62cf90u;
    return 10;
  }
  return defaultStep_787(st, code);
}
PCREG(62da60, matchStep_62da60);
