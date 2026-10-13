#include "ff.h"
// batch2704.cpp - unclaimed-27 claim 4 (docs/20-unclaimed-27.md). Name from the GC name map (medium, GUESS).

// 0x4876e0, the base constructor (original code, bound as ext_4876e0): thiscall, two stack arguments, ret 8.
extern "C" u8 *THISCALL ext_4876e0(u8 *self, u32 a1, u32 a2);

// 0x4877a0, ZMovementGuide::ZMovementGuide(ZPlayer*, unsigned int) (medium, GUESS name). Thiscall, ret 8, returns this.
// Calls the base constructor with both arguments, then sets the vtable to 0x68d080 and clears the fields: the float
// at +0x3a9 to -1.0, dwords at +0x375, +0x371, +0x36d, +0x385, +0x389, +0x38d to 0, the byte at +0x3ad, and the word at +0x3bd.
static u8 *THISCALL zMovementGuideCtor(u8 *self, u32 a1, u32 a2) {
  ext_4876e0(self, a1, a2);
  *(u32 *)self = 0x68d080u;
  *(u32 *)(self + 0x3a9) = 0xbf800000u;
  *(u32 *)(self + 0x375) = 0;
  *(u8 *)(self + 0x3ad) = 0;
  *(u16 *)(self + 0x3bd) = 0;
  *(u32 *)(self + 0x371) = 0;
  *(u32 *)(self + 0x36d) = 0;
  *(u32 *)(self + 0x385) = 0;
  *(u32 *)(self + 0x389) = 0;
  *(u32 *)(self + 0x38d) = 0;
  return self;
}
PCREG(4877a0, zMovementGuideCtor);
