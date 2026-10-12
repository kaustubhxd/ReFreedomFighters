// batch2446.cpp - decomp area 24, batch 2446 (gap band).
#include "ff.h"

extern "C" void THISCALL ext_43de70(void *self);  // tail target of 0x452f80, plain ret

// 0x452f80 (GUESS owner), thiscall, plain ret. Vtable 0x681b24; the child at +0x52 (when set) gets slot 0 with 1; then the
// tail jump to 0x43de70 on this.
static void THISCALL vtableSetAndTail(u8 *self) {
  *(u32 *)self = 0x681b24u;
  u8 *child = *(u8 **)(self + 0x52);
  if (child)
    vcall<void>(child, 0, 1u);
  ext_43de70(self);
}
PCREG(452f80, vtableSetAndTail);

// 0x45c4f0 (GUESS, unnamed), cdecl, plain ret: the child at ([sys+0x9b]+8) gets slot 0x10 with (first, second).
static void cdeclForwardSlot10(u32 a, u32 b) {
  u8 *sys = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(sys + 0x9b);
  void *child = *(void **)(tab + 8);
  vcall<void>(child, 0x10, a, b);
}
PCREG(45c4f0, cdeclForwardSlot10);
