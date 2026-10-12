// batch1943.cpp - unclaimed-66 batch 44 (gap band, GUESS name). THISCALL(this), one stack argument x (u32), ret 4.
//   0x51b5c0(ECX = this, x) (a recording GUESS stub in the spec); then r = vtable +0x38 of this (no arguments); then vtable slot 0 of x
//   with ECX = x and r as its one argument.
#include "ff.h"

extern "C" void THISCALL ext_51b5c0(u8 *self, u32 x);  // THISCALL, one argument, ret 4 (hooked in the spec)

// 0x51ff00, GUESS FUN_0051ff00 (batch 44).
static void THISCALL gapFn51ff00(u8 *self, u32 x) {
  ext_51b5c0(self, x);
  u32 r = vcall<u32>(self, 0x38);
  vcall<void>((u8 *)x, 0, r);
}
PCREG(51ff00, gapFn51ff00);
