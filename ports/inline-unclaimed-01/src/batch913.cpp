#include "ff.h"
// batch913.cpp - unclaimed-01 claim 12 (docs/20-unclaimed-01.md). ZInputActions::CheckActionAnalog(unsigned int, void*)
// (0x438000, high). Returns a float in st0 (as the i386 ABI does for a float return).

// Calls vtable slot +0x2c (two arguments) and returns 0.0 when the result byte is zero. Otherwise calls vtable slot +0xa0
// with the first argument, takes that result byte as a signed value, converts it to float and divides by the constant at
// 0x67af20 (read from the exe image, not guessed).
static float THISCALL inputActionsCheckActionAnalog(u8 *self, u32 a1, u32 a2) {
  typedef u8(THISCALL * slot2c_fn)(u8 *, u32, u32);
  slot2c_fn f2c = *(slot2c_fn *)(*(u32 *)self + 0x2c);
  if (f2c(self, a1, a2) == 0)
    return 0.0f;
  typedef u8(THISCALL * slot_a0_fn)(u8 *, u32);
  slot_a0_fn fa0 = *(slot_a0_fn *)(*(u32 *)self + 0xa0);
  s32 v = (s32)(s8)fa0(self, a1);
  return (float)v / G(float, 0x67af20);
}
PCREG(438000, inputActionsCheckActionAnalog);
