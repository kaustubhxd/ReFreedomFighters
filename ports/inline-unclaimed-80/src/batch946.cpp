#include "ff.h"
// batch946.cpp - unclaimed-80 gap band (docs/20-unclaimed-80.md): a walk over the object at self+0x19 (0x438200, high).
// Thiscall, no stack arguments, void. If the object is null, return. Otherwise slot +0x4c(&local) (result ignored), then
// p = slot +0x5c(&local); if local == 0 return. Loop: if p != 0 and [p] == 0, write 0 at p+0x42; then p = slot +0x5c(&local) again;
// stop when local == 0. The exe's constant 0x46 in edi is only used by the cmove that never moves (p != 0 there): dead, omitted.
// Every call is callee-cleaned (the exe pops nothing after them), so each is a plain thiscall of the slot.

typedef u32(THISCALL *tc1)(u8 *, u32);

static u32 callSlot(u8 *o, u32 off, u32 arg) {
  return ((tc1)(*(u32 *)(*(u32 *)o + off)))(o, arg);
}

static void THISCALL zgroupWalkClear(u8 *self) {
  u32 local;
  u8 *obj = *(u8 **)(self + 0x19);
  if (obj == 0) return;
  callSlot(obj, 0x4c, (u32)&local);
  u8 *p = (u8 *)callSlot(*(u8 **)(self + 0x19), 0x5c, (u32)&local);
  if (local == 0) return;
  for (;;) {
    if (p != 0 && *(u32 *)p == 0) *(u32 *)(p + 0x42) = 0;
    p = (u8 *)callSlot(*(u8 **)(self + 0x19), 0x5c, (u32)&local);
    if (local == 0) break;
  }
}
PCREG(438200, zgroupWalkClear);
