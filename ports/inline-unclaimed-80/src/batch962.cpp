#include "ff.h"
// batch962.cpp - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x451340 (high). Thiscall (self in ecx), one stack argument o, ret 4, returns al.
// If 0x45f960(self, o) is false, return 0. Otherwise: o.vt[0x3c](self+0x94); r1 = g.vt[0x4c](self+0x98) with g = [[0x70039c]+0x9b];
// o.vt[0x3c](r1); r2 = g.vt[0x4c](self+0xc8); o.vt[0x3c](r2); o.vt[0x3c](self+0x88); o.vt[0x3c](self+0xa8);
// o.vt[0x10](self+0x8c, 2 * [self+0x88]); return 1. Every call is callee-cleaned (nothing popped after them in the exe).
// 0x45f960 is claimed elsewhere; the spec hooks it by address with a recording stub that returns a per-case bool.

extern "C" u8 THISCALL ext_45f960(u8 *self, u32 a1);

typedef u32(THISCALL *tc1)(u8 *, u32);
typedef u32(THISCALL *tc2)(u8 *, u32, u32);

static u8 THISCALL zg451340(u8 *self, u32 a1) {
  u8 *o = (u8 *)a1;
  if (!ext_45f960(self, a1)) return 0;
  ((tc1)(*(u32 *)(*(u32 *)o + 0x3c)))(o, *(u32 *)(self + 0x94));
  u32 vt = *(u32 *)o;
  u8 *go = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 r1 = ((tc1)(*(u32 *)(*(u32 *)go + 0x4c)))(go, *(u32 *)(self + 0x98));
  ((tc1)(*(u32 *)(vt + 0x3c)))(o, r1);
  go = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 r2 = ((tc1)(*(u32 *)(*(u32 *)go + 0x4c)))(go, *(u32 *)(self + 0xc8));
  ((tc1)(*(u32 *)(vt + 0x3c)))(o, r2);
  ((tc1)(*(u32 *)(*(u32 *)o + 0x3c)))(o, *(u32 *)(self + 0x88));
  ((tc1)(*(u32 *)(*(u32 *)o + 0x3c)))(o, *(u32 *)(self + 0xa8));
  u32 t = *(u32 *)(self + 0x88) * 2;
  ((tc2)(*(u32 *)(*(u32 *)o + 0x10)))(o, *(u32 *)(self + 0x8c), t);
  return 1;
}
PCREG(451340, zg451340);
