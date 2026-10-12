// batch6860.cpp - area 73 batch 68 (gap band, GUESS name): FUN_4f9dc0.
#include "ff.h"

// 0x4f9dc0 (GUESS FUN_4f9dc0): plain ret. When this+0x70 is not 0x20: the dword at this+0x6c gets bit 2 set, vtable slot +0x2ec(0x20)
// is called on this, and r = vtable slot +0x2c4() on this; a non-null r gets vtable slot +0x2f4(this, 1).
static void THISCALL guess4f9dc0(u8 *self) {
  if (*(u32 *)(self + 0x70) == 0x20)
    return;
  *(u32 *)(self + 0x6c) |= 2;
  vcall<void>(self, 0x2ec, 0x20u);
  u8 *r = (u8 *)vcall<u32>(self, 0x2c4);
  if (!r)
    return;
  vcall<void>(r, 0x2f4, (u32)self, 1u);
}
PCREG(4f9dc0, guess4f9dc0);
