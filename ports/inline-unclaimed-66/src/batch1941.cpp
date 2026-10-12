// batch1941.cpp - unclaimed-66 batch 42 (gap band, GUESS name). THISCALL(this), ret 0.
//   Calls 0x517540 (ECX = this, no arguments; a recording GUESS stub in the spec). If [this+0x165c] is nonzero, stores the result of
//   vtable +0x328 of this (args: [this+0x165c], this, 0x506d7647) at [this+0x1658].
#include "ff.h"

extern "C" void THISCALL ext_517540(u8 *self);  // another area's function (hooked by address in the spec)

// 0x51f5d0, GUESS FUN_0051f5d0 (batch 42).
static void THISCALL gapFn51f5d0(u8 *self) {
  ext_517540(self);
  u32 c = *(u32 *)(self + 0x165c);
  if (c) *(u32 *)(self + 0x1658) = vcall<u32>(self, 0x328, c, (u32)self, (u32)0x506d7647);
}
PCREG(51f5d0, gapFn51f5d0);
