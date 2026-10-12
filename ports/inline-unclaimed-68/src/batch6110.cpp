// batch6110.cpp - unclaimed-68 batch 12 (claim 11). Name: GUESS FUN_516730.
#include "ff.h"

// 0x4690b0 is a bare `ret` in the exe (no-op; see docs/20-unclaimed-68.md). Called as a thiscall with no arguments.
extern "C" void THISCALL ext_4690b0(u8 *self);
// 0x524930: thiscall with one float argument, ret 4 (original code).
extern "C" void THISCALL ext_524930(u8 *self, float f);

// 0x516730 (GUESS): this+0x11, +0x15, +0x19, +0x1d get four constants (bit patterns); ext_4690b0 on +0x41 and +0x55 (no-ops);
// then ext_524930 on this+0x21 with the argument. Thiscall, one stack argument, ret 4.
static void THISCALL guessFun516730(u8 *self, float f) {
  *(u32 *)(self + 0x11) = 0xc4bb8000u;
  *(u32 *)(self + 0x15) = 0x41f00000u;
  *(u32 *)(self + 0x19) = 0x43020000u;
  *(u32 *)(self + 0x1d) = 0x42700000u;
  ext_4690b0(self + 0x41);
  ext_4690b0(self + 0x55);
  ext_524930(self + 0x21, f);
}
PCREG(516730, guessFun516730);
