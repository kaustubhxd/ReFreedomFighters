// batch2489.cpp - decomp area 24, batch 2489.
#include "ff.h"

extern "C" void THISCALL ext_51aa60(void *self);   // ZTankIf base destructor step (thiscall, no argument)
extern "C" void THISCALL ext_519430(void *self);   // ZHeliIf base destructor step (thiscall, no argument)
extern "C" void ext_634273(void *p, u32 size);     // __builtin_delete (cdecl)

// 0x4b8a10 ZRelayMessageList::Load(ZLoadGame*), thiscall, ret 4, AL = 1. Clears bit 0x40 of +4 and loads the list at +0x54.
static u8 THISCALL relayMessageListLoad(u8 *self, void *ld) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  vcall<void>(ld, 0x50, self + 0x54);
  return 1;
}
PCREG(4b8a10, relayMessageListLoad);

// 0x522740 ZTankIf::~ZTankIf(flags), thiscall, ret 4. Vtable 0x6a06f4, base step, delete (this, 0x20) when bit 0 is set; returns this.
static u8 *THISCALL tankIfDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x6a06f4u;
  ext_51aa60(self);
  if (flags & 1)
    ext_634273(self, 0x20);
  return self;
}
PCREG(522740, tankIfDtor);

// 0x51e810 ZHeliIf::~ZHeliIf(flags), thiscall, ret 4. Vtable 0x69fa64, base step, delete (this, 0x1c) when bit 0 is set; returns this.
static u8 *THISCALL heliIfDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x69fa64u;
  ext_519430(self);
  if (flags & 1)
    ext_634273(self, 0x1c);
  return self;
}
PCREG(51e810, heliIfDtor);

// 0x488b60 ZMovementBaseMove::GetActiveWalkDefsList(), thiscall, plain ret. Offset +0x25; slot 0x534 of the owner at +4 returning
// false with flag 0x400 selects +0x3d; flag 0x800 selects +0x55 instead.
static u8 *THISCALL movementGetActiveWalkDefsList(u8 *self) {
  u8 *owner = *(u8 **)(self + 4);
  u8 *p = self + 0x25;
  if (!vcall<u8>(owner, 0x534) && (*(u32 *)(owner + 0x417) & 0x400))
    p = self + 0x3d;
  return (*(u32 *)(owner + 0x417) & 0x800) ? self + 0x55 : p;
}
PCREG(488b60, movementGetActiveWalkDefsList);
