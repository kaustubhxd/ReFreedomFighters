// batch67552.cpp - cascade s6 batch 67552: 0x62cd30.
#include "ff.h"

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))
typedef u32 (__cdecl *match67552_t)(u8 *, u32, u32, u32);

// 0x62cd30, cdecl(ctx, code, off, n, obj) returns eax: token classifier of a text parser state machine (ctx[0] receives the next state function). Code 0xf: 0. Code 0x14 tries the compare
// callback obj[0x1c](obj, obj[0x44] + off, n, string) with three keyword strings in turn (0x6c01b4: state 0x62ca20 / result 0x1f; 0x6c01fc: 0x62ca20 / 0x20; 0x6c0190: state 0x62ce20 / 0) and falls
// through to the default when none matches; code 0x1b: state 0x62ca20, result 0x21. Default: code 0x1c with ctx[0xc] == 0 returns 0x34, anything else sets state 0x51f230 and returns -1.
static u32 __attribute__((cdecl)) fn62cd30(u8 *ctx, u32 code, u32 off, u32 n, u8 *obj) {
  if (code == 0xf) return 0;
  if (code == 0x14) {
    match67552_t cb = *(match67552_t *)(obj + 0x1c);
    if (cb(obj, D32(obj, 0x44) + off, n, 0x6c01b4u)) {
      D32(ctx, 0) = 0x62ca20u;
      return 0x1f;
    }
    if (cb(obj, D32(obj, 0x44) + off, n, 0x6c01fcu)) {
      D32(ctx, 0) = 0x62ca20u;
      return 0x20;
    }
    if (cb(obj, D32(obj, 0x44) + off, n, 0x6c0190u)) {
      D32(ctx, 0) = 0x62ce20u;
      return 0;
    }
  } else if (code == 0x1b) {
    D32(ctx, 0) = 0x62ca20u;
    return 0x21;
  }
  if (D32(ctx, 0xc) == 0 && code == 0x1c) return 0x34;
  D32(ctx, 0) = 0x51f230u;
  return 0xffffffffu;
}
PCREG(62cd30, fn62cd30);
