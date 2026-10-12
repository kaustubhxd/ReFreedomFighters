#include "ff.h"
// batch963.cpp - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x4450b0 (high). Thiscall (self in ecx), one stack argument o (ret 4), returns al.
// If 0x441790(self, o) is false, return 0. Otherwise o.vt[0x3c](self+0x94); o.vt[0x3c](self+0x98); o.vt[0x3c](self+0xc0);
// g = [self+0xa4]: if g != 0: x = g.vt[0x14](); o.vt[0x3c](x); o.vt[0x20]([self+0xa4]); else o.vt[0x3c](0);
// finally o.vt[0x3c]([self+0xac]); return 1. Every call is callee-cleaned. 0x441790 is claimed elsewhere (hooked by address in the spec).

extern "C" u8 THISCALL ext_441790(u8 *self, u32 a1);

typedef u32(THISCALL *tc1)(u8 *, u32);
typedef u32(THISCALL *tc0)(u8 *);

static u8 THISCALL zg4450b0(u8 *self, u32 a1) {
  u8 *o = (u8 *)a1;
  if (!ext_441790(self, a1)) return 0;
  ((tc1)(*(u32 *)(*(u32 *)o + 0x3c)))(o, *(u32 *)(self + 0x94));
  ((tc1)(*(u32 *)(*(u32 *)o + 0x3c)))(o, *(u32 *)(self + 0x98));
  ((tc1)(*(u32 *)(*(u32 *)o + 0x3c)))(o, *(u32 *)(self + 0xc0));
  u8 *g = *(u8 **)(self + 0xa4);
  if (g != 0) {
    u32 x = ((tc0)(*(u32 *)(*(u32 *)g + 0x14)))(g);
    ((tc1)(*(u32 *)(*(u32 *)o + 0x3c)))(o, x);
    ((tc1)(*(u32 *)(*(u32 *)o + 0x20)))(o, *(u32 *)(self + 0xa4));
  } else {
    ((tc1)(*(u32 *)(*(u32 *)o + 0x3c)))(o, 0);
  }
  ((tc1)(*(u32 *)(*(u32 *)o + 0x3c)))(o, *(u32 *)(self + 0xac));
  return 1;
}
PCREG(4450b0, zg4450b0);
