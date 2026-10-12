#include "ff.h"
// batch1512.cpp - unclaimed-15 claim 12 (docs/20-unclaimed-15.md): ZMovementBaseMove::ZMovementBaseMove(ZPlayer*, unsigned int)
// (0x4876e0). Name from the GC name map (medium). Thiscall, two arguments, ret 8. The member constructor 0x480980 is
// stubbed in the harness (thiscall, no arguments). The exe's SEH frame (fs:[0]) is stack state and is not ported.

extern "C" void THISCALL ext_480980(u8 *self);   // member constructor, stubbed in the harness

// 0x4876e0, ZMovementBaseMove::ZMovementBaseMove(ZPlayer*, unsigned int) (medium).
static u8 *THISCALL movementBaseMoveCtor(u8 *self, u32 a1, u32 a2) {
  *(u32 *)(self + 0x10) = a2;
  self[0x1c] = 1;
  *(u32 *)(self + 0xc) = 0;
  *(u32 *)(self + 0x14) = 0;
  *(u32 *)(self + 0x18) = 0;
  *(u32 *)(self + 0x4) = a1;
  *(u32 *)(self + 0x8) = 0;
  *(u32 *)self = 0x68d018;
  *(u32 *)(self + 0x1d) = 0;
  ext_480980(self + 0x25);
  ext_480980(self + 0x3d);
  ext_480980(self + 0x55);
  *(u32 *)(self + 0x21) = 0;
  *(u32 *)(self + 0x1d) = 0;
  return self;
}
PCREG(4876e0, movementBaseMoveCtor);
