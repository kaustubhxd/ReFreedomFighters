// batch1125.cpp - unclaimed-11 batch 26 (gap band): two GUESS functions.
#include "ff.h"

extern "C" void THISCALL ext_469870(void *self);

// 0x5bf4a0, GUESS: base constructor (exe, via ext), then flag |= 0x20 at +4, dword 0 at +0x44, vtable 0x6b36bc. Returns this.
static u8 *THISCALL guessCtor5bf4a0(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6b36bc;
  return self;
}
PCREG(5bf4a0, guessCtor5bf4a0);

// 0x5a40b0, GUESS: copies the dwords at arg+0x113, +0x117 and +0x11f to this at the same offsets.
static void THISCALL guessCopyThree(u8 *self, const u8 *src) {
  *(u32 *)(self + 0x113) = *(const u32 *)(src + 0x113);
  *(u32 *)(self + 0x117) = *(const u32 *)(src + 0x117);
  *(u32 *)(self + 0x11f) = *(const u32 *)(src + 0x11f);
}
PCREG(5a40b0, guessCopyThree);
