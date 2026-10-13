// batch1979.cpp - slice-5 batch 112 (GUESS name): 0x500190
// THISCALL(this, arg), ret 4: calls vtable slot 0x2c of arg with array size,
// then iterates through array at [this..[this+4]), calling 0x5f95a0(element, arg) for each.
#include "ff.h"

extern "C" void THISCALL ext_5f95a0(u8 *element, void *arg);  // visitor thiscall

// 0x500190, GUESS FUN_00500190 (batch 112).
static void THISCALL gapFn500190(u8 *self, void *arg) {
  // Get array bounds
  u8 **begin = (u8 **)self;
  u8 **end = (u8 **)(self + 4);

  // Calculate size in elements
  u32 size = (*end - *begin) / 4;

  // Call vtable slot 0x2c of arg with size
  vcall<void>((u8 *)arg, 0x2c, size);

  // Iterate through array
  for (u32 i = 0; i < size; i++) {
    u8 *element = *((u8 **)(((u8 *)*begin) + i * 4));
    ext_5f95a0(element, arg);
  }
}
PCREG(500190, gapFn500190);
