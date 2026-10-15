// batch309.cpp - mounted gun tree, batch 309: the hero's machine-gun movement mode (ZFFHeroMovementMachinegun, vtable
// 0x6b7820, 26 slots; GotControl/TerminateControl/WantControl/Move were lifted by the Decompilation thread, batches
// 56-62): its constructor, deleting destructor, GetAnims, and the shared movement-base destructor body 0x4878d0.
#include "ff.h"

extern "C" void THISCALL ext_5e0e10(void *self, u32 a, u32 b);   // ZFFHeroMovementBaseMove::ZFFHeroMovementBaseMove
extern "C" void THISCALL ext_480fd0(void *sub);                  // ZMovementBaseMove::~ZMovementBaseMove (sub-object)
extern "C" void THISCALL ext_4878d0(void *self);                 // movement base destructor body (this batch)
extern "C" void ext_634273(void *p, u32 size);                   // sized operator delete (cdecl)
extern "C" void THISCALL ext_5e3e90(void *self);                 // ZFFHeroMovementBaseMove::GetAnims

// 0x5e1110 ZFFHeroMovementMachinegun::ZFFHeroMovementMachinegun(ZFFHERO *hero, unsigned int id) (no PC map
// entry; only caller ZFFHERO::CreateMovements). thiscall, ret 8, returns this. Base constructor, vtable 0x6b7820, and
// clears the mode's own fields: byte +0x54c, dwords +0x54d, +0x551, +0x58d (object size 0x591, from the delete below).
static u8 *THISCALL ctor(u8 *self, u32 hero, u32 id) {
  ext_5e0e10(self, hero, id);
  *(u32 *)self = 0x6b7820u;
  self[0x54c] = 0;
  *(u32 *)(self + 0x54d) = 0;
  *(u32 *)(self + 0x551) = 0;
  *(u32 *)(self + 0x58d) = 0;
  return self;
}
PCREG(5e1110, ctor);

// 0x4878d0 (no map name; the ZMovementBase destructor body shared by ten hero movement modes): vtable 0x68d018, destroy
// the three ZMovementBaseMove sub-objects at +0x55, +0x3d, +0x25 (in that order), then vtable 0x68cf50. thiscall.
static void THISCALL movementBaseDtor(u8 *self) {
  *(u32 *)self = 0x68d018u;
  ext_480fd0(self + 0x55);
  ext_480fd0(self + 0x3d);
  ext_480fd0(self + 0x25);
  *(u32 *)self = 0x68cf50u;
}
PCREG(4878d0, movementBaseDtor);

// 0x5e1510 ZFFHeroMovementMachinegun scalar deleting destructor (GC ~ZFFHeroMovementMachinegun [medium]); thiscall,
// ret 4, returns this. vtable 0x6b7820, the four sub-objects at +0x523, +0x4ab, +0x3eb, +0x3d3, the base body, and
// with flag bit 0 the sized delete (0x591 bytes).
static u8 *THISCALL dtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x6b7820u;
  ext_480fd0(self + 0x523);
  ext_480fd0(self + 0x4ab);
  ext_480fd0(self + 0x3eb);
  ext_480fd0(self + 0x3d3);
  ext_4878d0(self);
  if (flags & 1)
    ext_634273(self, 0x591);
  return self;
}
PCREG(5e1510, dtor);

// 0x5e4680 ZFFHeroMovementMachinegun::GetAnims() (GC map [medium]); thiscall: the base GetAnims, then the word at
// +0x371 = 0x0101 (two flags set; inferred: upper and lower body animations both owned by this mode).
static void THISCALL getAnims(u8 *self) {
  ext_5e3e90(self);
  *(u16 *)(self + 0x371) = 0x101;
}
PCREG(5e4680, getAnims);
