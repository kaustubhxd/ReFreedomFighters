// batch204.cpp - unclaimed area 20 (docs/20-unclaimed-20.md), slice floor(addr/16) mod 20 == 19. Thin wrappers around one
// vtable call each (the callee is looked up in the object's vtable at a fixed slot).
#include "ff.h"

extern "C" void THISCALL ext_4f21f0(u8 *self);   // original code, thiscall, no stack args (called on a returned object)

typedef u32(THISCALL *SlotU32)(u8 *, u32);
typedef void(THISCALL *SlotFloat)(u8 *, float);

// 0x4cf3f0, thiscall(a): r = [this]->slot 0x70(this, a); return r ? *(u32 *)r : 0. Name GUESS.
static u32 THISCALL vtSlot70Deref_4cf3f0(u8 *self, u32 a) {
  SlotU32 fn = (SlotU32)(*(u32 *)(*(u32 *)self + 0x70));
  u32 r = fn(self, a);
  return r ? *(u32 *)r : 0;
}
PCREG(4cf3f0, vtSlot70Deref_4cf3f0);

// 0x5139b0, thiscall(v float): obj = [this+0x5c]; obj->slot 4 (obj, v). Name GUESS.
static void THISCALL vtSlot4Float_5139b0(u8 *self, float v) {
  u8 *obj = *(u8 **)(self + 0x5c);
  SlotFloat fn = (SlotFloat)(*(u32 *)(*(u32 *)obj + 4));
  fn(obj, v);
}
PCREG(5139b0, vtSlot4Float_5139b0);

// 0x5eb770, thiscall(a): rm = [0x70039c]; obj = [rm+0x9b]; [this+0xc] = obj->slot 0x58(obj, a). Name GUESS.
static void THISCALL storeVtSlot58_5eb770(u8 *self, u32 a) {
  u8 *rm = *(u8 **)0x70039cu;
  u8 *obj = *(u8 **)(rm + 0x9b);
  SlotU32 fn = (SlotU32)(*(u32 *)(*(u32 *)obj + 0x58));
  *(u32 *)(self + 0xc) = fn(obj, a);
}
PCREG(5eb770, storeVtSlot58_5eb770);

// 0x5630f0, thiscall(): r = this->slot 0x84(this, 1); call original 0x4f21f0 with ecx = r; [this+0x85] = 0. Name GUESS.
static void THISCALL callSlot84Reset_5630f0(u8 *self) {
  SlotU32 fn = (SlotU32)(*(u32 *)(*(u32 *)self + 0x84));
  u32 r = fn(self, 1);
  ext_4f21f0((u8 *)r);
  self[0x85] = 0;
}
PCREG(5630f0, callSlot84Reset_5630f0);
