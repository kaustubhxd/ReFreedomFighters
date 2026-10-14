// batch5820.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 120: 0x5dbc20 (ZFireDamageBox::Load(ZLoadGame*), vtable thunk), thiscall, one stack argument
// (ret 4), returns al = 1. Original: this+4 &= ~0x40; call 0x5dbc30 (thiscall, no arguments; area 63's batch 6356, hooked in the spec); al = 1; ret 4.
#include "ff.h"

extern "C" void THISCALL ext_5dbc30(u8 *self);  // area 63's batch 6356 function, original code (hooked in the spec)

// 0x5dbc20, thiscall, one stack argument (the load object, unused) (GUESS name)
static u8 THISCALL unnamed5dbc20(u8 *self, u32 load) {
  (void)load;
  *(u32 *)(self + 4) &= 0xffffffbfu;
  ext_5dbc30(self);
  return 1;
}
PCREG(5dbc20, unnamed5dbc20);
