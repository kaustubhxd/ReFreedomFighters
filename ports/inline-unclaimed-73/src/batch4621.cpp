// batch4621.cpp - area 73 batch 21 (gap band, GUESS names): FUN_4f3240, FUN_4fa370, FUN_4fa2f0.
#include "ff.h"

// 0x4f3240 (GUESS FUN_4f3240): ret 0xc (three arguments). Packs them as ((a1 << 8 | a2) << 8) | a3 and calls slot +0x33c(packed).
static void THISCALL guess4f3240(u8 *self, u32 a1, u32 a2, u32 a3) {
  u32 packed = ((a1 << 8) | a2) << 8;
  packed |= a3;
  vcall<void>(self, 0x33c, packed);
}
PCREG(4f3240, guess4f3240);

// 0x4fa370 (GUESS FUN_4fa370): ret 4, returns a bool. When the argument is 0x104: slot +0x308 on this, and true; otherwise false.
static bool THISCALL guess4fa370(u8 *self, u32 a) {
  if (a == 0x104u) {
    vcall<void>(self, 0x308);
    return true;
  }
  return false;
}
PCREG(4fa370, guess4fa370);

// 0x4fa2f0 (GUESS FUN_4fa2f0): ret 4, one argument not used. When [this+0x70] != 0x20: slot +0x314 on this, then slot +0x2ec(8).
static void THISCALL guess4fa2f0(u8 *self, u32 unused) {
  (void)unused;
  if (*(u32 *)(self + 0x70) != 0x20u) {
    vcall<void>(self, 0x314);
    vcall<void>(self, 0x2ec, 8u);
  }
}
PCREG(4fa2f0, guess4fa2f0);
