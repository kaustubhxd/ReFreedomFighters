// batch228.cpp - unclaimed area 22 (docs/20-unclaimed-22.md), slice floor(addr/16) mod 20 == 1. A one-time setup of a
// field from a virtual getter and an out-parameter call, then a call on a sub-object, then an original call, then a flag
// bit set or clear at [sub-object + 0x48] by the byte at this + 0x4d. Name GUESS.
#include "ff.h"

extern "C" void THISCALL ext_4fdac0(u8 *self);   // original, thiscall, no stack args

typedef u32(THISCALL *SlotNoArg)(u8 *);
typedef void(THISCALL *SlotU32Ptr)(u8 *, u32, u32 *);
typedef void(THISCALL *SlotPtrPair)(u8 *, u32 *);

// 0x4fc690, thiscall(): if this[+0x6e] == 0: r = rm[+0x9b]->vt[0x138](); local = 0; r->vt[0x88](0x690410, &local);
// this[+0x6e] = local. Then sub = this[+0x44]; sub->vt[0x240](this + 0x4e); ext_4fdac0(this); then the bit 0x400000 in
// sub[+0x48] is set if this[+0x4d] != 0 and cleared otherwise.
static void THISCALL setupFlag_4fc690(u8 *self) {
  if (*(u32 *)(self + 0x6e) == 0) {
    u8 *rm = *(u8 **)0x70039cu;
    u8 *o = *(u8 **)(rm + 0x9b);
    SlotNoArg f138 = (SlotNoArg)(*(u32 *)(*(u32 *)o + 0x138));
    u8 *r = (u8 *)f138(o);
    u32 local = 0;
    SlotU32Ptr f88 = (SlotU32Ptr)(*(u32 *)(*(u32 *)r + 0x88));
    f88(r, 0x690410u, &local);
    *(u32 *)(self + 0x6e) = local;
  }
  u8 *sub = *(u8 **)(self + 0x44);
  SlotPtrPair f240 = (SlotPtrPair)(*(u32 *)(*(u32 *)sub + 0x240));
  f240(sub, (u32 *)(self + 0x4e));
  ext_4fdac0(self);
  sub = *(u8 **)(self + 0x44);
  if (*(u8 *)(self + 0x4d)) {
    *(u32 *)(sub + 0x48) |= 0x400000u;
  } else {
    *(u32 *)(sub + 0x48) &= 0xffbfffffu;
  }
}
PCREG(4fc690, setupFlag_4fc690);
