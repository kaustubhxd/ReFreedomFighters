// batch104.cpp - climb down: small members of the hero's jump and fall movements (climb thread, batch 104).
// Class names of the vtables written here come from the exe's RTTI (pc.vtables()): 0x68b604 ZAnimDefsList,
// 0x68cf50 ZMovementBase, 0x68d018 ZMovementBaseMove, 0x6b760c ZFFHeroMovementJump, 0x6b76dc ZFFHeroMovementFall.
#include "ff.h"

extern "C" void THISCALL ext_480fd0(void *self);   // ZAnimDefsList::~ZAnimDefsList body, original code
extern "C" void THISCALL ext_4878d0(void *self);   // ZMovementBaseMove::~ZMovementBaseMove body, original code
extern "C" void THISCALL ext_5e3e90(void *self);   // ZFFHeroMovementBaseMove::GetAnims, original code
extern "C" void ext_634273(void *p, u32 size);     // operator delete(p, size), CRT

// 0x591f20, ZFFHERO::GetJump() const (GC map medium). thiscall, returns bit 19 of the flag word at +0x417 in AL.
// (Upper EAX bits are whatever the shift left; the contract is the bool in AL.)
static bool THISCALL getJump(u8 *self) { return (*(u32 *)(self + 0x417) >> 19) & 1; }
PCREG(591f20, getJump);

// 0x480fd0, ZAnimDefsList::~ZAnimDefsList body (vtable from RTTI). thiscall: vtable = 0x68b604; the owned object at +0x14,
// if any, gets its slot 0 called with 1 (scalar deleting destructor).
static void THISCALL animDefsListDtor(u8 *self) {
  *(u32 *)self = 0x68b604u;
  void *p = *(void **)(self + 0x14);
  if (p)
    vcall<void>(p, 0, 1u);
}
PCREG(480fd0, animDefsListDtor);

// 0x4878d0, ZMovementBaseMove::~ZMovementBaseMove body. thiscall: vtable = 0x68d018, destroys the three ZAnimDefsList
// members at +0x55, +0x3d, +0x25 (last declared first), then vtable = 0x68cf50 (ZMovementBase).
static void THISCALL movementBaseMoveDtor(u8 *self) {
  *(u32 *)self = 0x68d018u;
  ext_480fd0(self + 0x55);
  ext_480fd0(self + 0x3d);
  ext_480fd0(self + 0x25);
  *(u32 *)self = 0x68cf50u;
}
PCREG(4878d0, movementBaseMoveDtor);

// Shared body of the two hero movement scalar deleting destructors below (four more ZAnimDefsList members).
static u8 *heroMoveDtor(u8 *self, u32 flags, u32 vtable, u32 size) {
  *(u32 *)self = vtable;
  ext_480fd0(self + 0x523);
  ext_480fd0(self + 0x4ab);
  ext_480fd0(self + 0x3eb);
  ext_480fd0(self + 0x3d3);
  ext_4878d0(self);
  if (flags & 1)
    ext_634273(self, size);
  return self;
}

// 0x5e13f0, ZFFHeroMovementFall scalar deleting destructor: vtable 0x6b76dc, object size 0x578.
static u8 *THISCALL fallDtor(u8 *self, u32 flags) { return heroMoveDtor(self, flags, 0x6b76dcu, 0x578); }
PCREG(5e13f0, fallDtor);

// 0x5e14b0, ZFFHeroMovementJump scalar deleting destructor: vtable 0x6b760c, object size 0x5af.
static u8 *THISCALL jumpDtor(u8 *self, u32 flags) { return heroMoveDtor(self, flags, 0x6b760cu, 0x5af); }
PCREG(5e14b0, jumpDtor);

// 0x5e71f0, ZFFHeroMovementFall::TerminateControl(bool force) (GC map high). thiscall, ret 4, AL.
// force clears the "falling" byte +0x554; returns whether it is clear (the movement may end).
static bool THISCALL fallTerminate(u8 *self, bool force) {
  if (force)
    self[0x554] = 0;
  return self[0x554] == 0;
}
PCREG(5e71f0, fallTerminate);

// 0x5e7230, ZFFHeroMovementJump::TerminateControl(bool force) (GC map high). thiscall, ret 4, AL.
// force clears the "jumping" byte +0x550. The current time is stored at +0x54c either way: the engine's tick counter
// [g_pSysInterface + 0x40] as a float times 1/1024 (0x6785e4). When the byte is clear, the hero's (+0x36d) flag word +0x417
// loses bit 29 and the byte is read again for the result.
static bool THISCALL jumpTerminate(u8 *self, bool force) {
  if (force)
    self[0x550] = 0;
  bool clear = self[0x550] == 0;
  *(float *)(self + 0x54c) = (float)*(s32 *)(G(u8 *, 0x70039c) + 0x40) * 0.0009765625f;
  if (!clear)
    return false;
  u8 *hero = *(u8 **)(self + 0x36d);
  *(u32 *)(hero + 0x417) &= 0xdfffffffu;
  return self[0x550] == 0;
}
PCREG(5e7230, jumpTerminate);

// 0x5e45d0, ZFFHeroMovementFall::GetAnims() (GC map high). thiscall. Base GetAnims, then +0x563 = slot 0x58("Fall") and
// +0x567 = slot 0x58("Land_Soft") (slot 0x58 looks an animation up by name).
static void THISCALL fallGetAnims(u8 *self) {
  ext_5e3e90(self);
  *(void **)(self + 0x563) = vcall<void *>(self, 0x58, (const char *)0x6b7cac);
  *(void **)(self + 0x567) = vcall<void *>(self, 0x58, (const char *)0x6b7cb4);
}
PCREG(5e45d0, fallGetAnims);

// 0x5e4630, ZFFHeroMovementJump::GetAnims() (GC map high). thiscall. Base GetAnims, then +0x577 = slot 0x58("Jump") and
// slot 0x54(&+0x577), then +0x55f = slot 0x58("Leap_Forward") and slot 0x54(&+0x55f) (slot 0x54 takes the address of an
// animation field; guess: registers it so it is kept loaded).
static void THISCALL jumpGetAnims(u8 *self) {
  ext_5e3e90(self);
  void **a = (void **)(self + 0x577);
  *a = vcall<void *>(self, 0x58, (const char *)0x6aaa08);
  vcall<void>(self, 0x54, a);
  void **b = (void **)(self + 0x55f);
  *b = vcall<void *>(self, 0x58, (const char *)0x6b7be4);
  vcall<void>(self, 0x54, b);
}
PCREG(5e4630, jumpGetAnims);
