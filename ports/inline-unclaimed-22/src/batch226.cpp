// batch226.cpp - unclaimed area 22 (docs/20-unclaimed-22.md), slice floor(addr/16) mod 20 == 1. One state-change function:
// a bool from 0x4fbd50 is compared with a stored byte; on a change, a vtable slot on the global's object gives an object
// whose slot 0x128 gets three words (a 16-bit field picked by the bool, a dword, and 0).
#include "ff.h"

extern "C" u32 THISCALL ext_4fbd50(u8 *self);   // original, thiscall, no stack args; returns al (the bool)

typedef u32(THISCALL *SlotU32)(u8 *, u32);
typedef void(THISCALL *SlotVoid3)(u8 *, u32, u32, u32);

// 0x4fb8d0, thiscall(): bl = (u8)ext_4fbd50(this); if bl == this[+0x48] return; o = rm[+0x9b]->vt[0x58](this[+0x55]);
// if !o return; this[+0x48] = bl; if bl: o->vt[0x128](u16 this[+0x4d], this[+0x49] dword, 0); else the same with u16 this[+0x4f].
// Name GUESS.
static void THISCALL stateSlot128_4fb8d0(u8 *self) {
  u8 bl = (u8)ext_4fbd50(self);
  if (bl == *(u8 *)(self + 0x48)) return;
  u8 *rm = *(u8 **)0x70039cu;
  u8 *obj = *(u8 **)(rm + 0x9b);
  SlotU32 fn = (SlotU32)(*(u32 *)(*(u32 *)obj + 0x58));
  u8 *o = (u8 *)fn(obj, *(u32 *)(self + 0x55));
  if (!o) return;
  *(u8 *)(self + 0x48) = bl;
  SlotVoid3 fn128 = (SlotVoid3)(*(u32 *)(*(u32 *)o + 0x128));
  if (bl) {
    u32 w = *(u16 *)(self + 0x4d);
    fn128(o, w, *(u32 *)(self + 0x49), 0u);
  } else {
    u32 w = *(u16 *)(self + 0x4f);
    fn128(o, w, *(u32 *)(self + 0x49), 0u);
  }
}
PCREG(4fb8d0, stateSlot128_4fb8d0);
