#include "ff.h"
// batch2723.cpp - unclaimed-27 batch 23 (gap band; docs/20-unclaimed-27.md). Name unknown (GUESS).
// 0x59a8f0 and 0x59a2d0 are original code (bound by build.sh): thiscall, no arguments, plain ret.
extern "C" void THISCALL ext_59a8f0(u8 *self);
extern "C" void THISCALL ext_59a2d0(u8 *self);

// 0x59a280 (GUESS): thiscall, no arguments, void. Stores 1.0f at this+0x1d17, zeros at +0x1d0b, +0x1d07, +0x1d03 and +0x58,
// calls 0x59a8f0(this) and 0x59a2d0(this), then clears the byte at this+0xe1.
static void THISCALL funcInitAndRun(u8 *self) {
  *(u32 *)(self + 0x1d17) = 0x3f800000u;
  *(u32 *)(self + 0x1d0b) = 0;
  *(u32 *)(self + 0x1d07) = 0;
  *(u32 *)(self + 0x1d03) = 0;
  *(u32 *)(self + 0x58) = 0;
  ext_59a8f0(self);
  ext_59a2d0(self);
  self[0xe1] = 0;
}
PCREG(59a280, funcInitAndRun);
