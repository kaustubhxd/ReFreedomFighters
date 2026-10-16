// batch6503.cpp - unclaimed-65: batch 3 (docs/20-unclaimed-65.md, claim 3). Thiscall, one stack argument, ret 4. The name is a
// GUESS (FUN_6463e0): it has no GC map entry; the label is only a label.
#include "ff.h"

// 0x63ea50 (thiscall, no arguments; original code here)
extern "C" u32 THISCALL ext_63ea50(u8 *self);

typedef u32(THISCALL *Slot1Fn)(u8 *self, u32 a);

static u32 vcall1(u8 *obj, u32 slot, u32 arg) {
  return ((Slot1Fn)(*(const u32 *)(*(const u32 *)obj + slot)))(obj, arg);
}

// 0x6463e0 (GUESS): X = the object at [0x70039c]+0x190f; Y = X's slot +0x20 with the dword at arg+8. When 0x63ea50 on Y returns
// nonzero, that result is returned. Otherwise the call tail-jumps to slot +0xbc of the object at [R+0x18], where R =
// [0x70039c]+0x1aa3, with the dword at [arg+8]+0x6c as the one argument.
static u32 THISCALL unknown6463e0(u8 *self, u8 *arg) {
  (void)self;
  u8 *rm = G(u8 *, 0x70039c);
  u8 *x = *(u8 **)(rm + 0x190f);
  u8 *y = (u8 *)vcall1(x, 0x20, *(const u32 *)(arg + 8));
  const u32 r = ext_63ea50(y);
  if (r) return r;
  u8 *holder = *(u8 **)(G(u8 *, 0x70039c) + 0x1aa3);
  u8 *obj = *(u8 **)(holder + 0x18);
  const u32 tail = *(const u32 *)(*(const u32 *)(arg + 8) + 0x6c);
  return ((Slot1Fn)(*(const u32 *)(*(const u32 *)obj + 0xbc)))(obj, tail);
}
PCREG(6463e0, unknown6463e0);
