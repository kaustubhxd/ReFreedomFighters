// batch4027.cpp - area 70 (slice 4/5), batch 4027: 0x595510 (name GUESS). Returns when the float at [this+0x813] equals 0.0
// (ordered compare; NaN takes the body). Otherwise zeroes that float and calls slot 0x4b4 of this (thiscall, four stack
// dwords (0, 0, 0, 0): the 16-byte struct {0, 0, 0, 0xffffffff} is copied to the stack and its last dword is the fifth dword, which the callee does not read).
#include "ff.h"

// 0x595510 (name GUESS): thiscall, no arguments, plain ret.
static void THISCALL clearAndNotify595510(u8 *self) {
  float x = *(float *)(self + 0x813);
  if (x == 0.0f) return;
  *(float *)(self + 0x813) = 0.0f;
  vcall<void>(self, 0x4b4, 0u, 0u, 0u, 0u);
}
PCREG(595510, clearAndNotify595510);
