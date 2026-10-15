// batch1010.cpp - unclaimed-10, batch 6 (docs/20-unclaimed-10.md): ZFFHeroMovementBaseMove::ZFFHeroMovementBaseMove(ZFFHERO*,
// unsigned int), the hero's movement-base constructor (thiscall, two stack arguments, ret 8).
// Unverified callees run as ORIGINAL code through ext_ bindings (build.sh binds each ext_<hex> to that PC address):
//   0x4876e0  ZMovementBaseMove::ZMovementBaseMove(ZPlayer*, unsigned int) (medium) - the base constructor.
//   0x480980  member constructor, thiscall, no arguments (ret). It calls operator new (0x41e290, hooked in the spec)
//             and 0x4ccbe0, a pure constructor (ret 8) that the spec leaves as original code.
#include "ff.h"

extern "C" u8 *THISCALL ext_4876e0(u8 *self, u8 *a1, u32 a2);  // ZMovementBaseMove ctor, original code
extern "C" void THISCALL ext_480980(u8 *self);                 // member ctor, original code

// 0x5e0e10, ZFFHeroMovementBaseMove::ZFFHeroMovementBaseMove(ZFFHERO*, unsigned int) (medium, GUESS on the class name):
// base ctor with (a1, a2); vtable 0x6b75a0 at +0; a1 at +0x36d; word 0 at +0x371; four member ctors at +0x3d3, +0x3eb,
// +0x4ab, +0x523; then dword 0 at +0x53b and +0x53f, +0x543, +0x547, byte 0 at +0x54b. Returns this in eax.
static u8 *THISCALL heroMoveBaseCtor(u8 *self, u8 *a1, u32 a2) {
  ext_4876e0(self, a1, a2);
  *(u32 *)self = 0x6b75a0;
  *(u32 *)(self + 0x36d) = (u32)(unsigned long)a1;
  *(u16 *)(self + 0x371) = 0;
  ext_480980(self + 0x3d3);
  ext_480980(self + 0x3eb);
  ext_480980(self + 0x4ab);
  ext_480980(self + 0x523);
  *(u32 *)(self + 0x53b) = 0;
  self[0x54b] = 0;
  *(u32 *)(self + 0x53f) = 0;
  *(u32 *)(self + 0x543) = 0;
  *(u32 *)(self + 0x547) = 0;
  return self;
}
PCREG(5e0e10, heroMoveBaseCtor);
