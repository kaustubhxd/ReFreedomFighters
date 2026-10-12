#include "ff.h"
// batch8012.cpp - unclaimed-79 gap-band group (docs/20-unclaimed-79.md). Names GUESS (no GC name).

// 0x49b360 (GUESS): thiscall, stores its two stack arguments at this+0x128 and this+0x12c (ret 8).
static void THISCALL f_49b360(u8 *self, u32 a, u32 b) { *(u32 *)(self + 0x128) = a; *(u32 *)(self + 0x12c) = b; }
PCREG(49b360, f_49b360);

// 0x497700 (GUESS): thiscall, 0 for a zero argument, else ((arg - field at this+0x51) >> 5) + 1 (signed, ret 4).
static u32 THISCALL f_497700(u8 *self, u32 a) {
  if (a == 0) return 0;
  return (u32)((s32)(a - *(u32 *)(self + 0x51)) >> 5) + 1;
}
PCREG(497700, f_497700);

// 0x49a4f0 (GUESS): thiscall, stores (sub-object+0xc + sub-object+4) to its first argument, then adds the second argument
// to sub-object+0xc (ret 8).
static void THISCALL f_49a4f0(u8 *self, u32 p, u32 v) {
  u8 *c = *(u8 **)(self + 0xc);
  *(u32 *)(unsigned long)p = *(u32 *)(c + 0xc) + *(u32 *)(c + 0x4);
  u8 *d = *(u8 **)(self + 0xc);
  *(u32 *)(d + 0xc) += v;
}
PCREG(49a4f0, f_49a4f0);

// 0x48d0c0 (GUESS): cdecl, 0 if the dwords at (arg1+4) and (arg2+4) are equal, else 1 or -1 by unsigned order.
static s32 f_48d0c0(u32 a, u32 b) {
  u32 x = *(u32 *)(unsigned long)(a + 0x4);
  u32 y = *(u32 *)(unsigned long)(b + 0x4);
  if (y == x) return 0;
  return y < x ? 1 : -1;
}
PCREG(48d0c0, f_48d0c0);

// 0x491a60 (GUESS): thiscall, word argument: 0 for a zero index, else the dword at this+0xc4d+4*index (ret 4).
static u32 THISCALL f_491a60(u8 *self, u32 a) {
  u16 i = (u16)a;
  if (i == 0) return 0;
  return *(u32 *)(self + 0xc4d + (u32)i * 4);
}
PCREG(491a60, f_491a60);
