// batch1964.cpp - unclaimed-66 batches 81 and 82 (gap band, GUESS names). THISCALL(this), one float argument f, ret 4.
//   Stores four float constants at this+0x11, +0x15, +0x19, +0x1d; 0x4690b0(ECX = this+0x41) and 0x4690b0(ECX = this+0x55) (THISCALL,
//   no arguments); then 0x524890(ECX = this+0x21, f) (THISCALL, one float argument). 0x4690b0 and 0x524890 are GUESS stubs by address.
#include "ff.h"

extern "C" void THISCALL ext_4690b0(u8 *self);            // THISCALL, no arguments (hooked in the spec)
extern "C" void THISCALL ext_524890(u8 *self, float f);   // THISCALL, one float argument (hooked in the spec)

// 0x516640, GUESS FUN_00516640 (batch 81).
static void THISCALL gapFn516640(u8 *self, float f) {
  *(u32 *)(self + 0x11) = 0xc47a0000;
  *(u32 *)(self + 0x15) = 0x42200000;
  *(u32 *)(self + 0x19) = 0x42dc0000;
  *(u32 *)(self + 0x1d) = 0x42700000;
  ext_4690b0(self + 0x41);
  ext_4690b0(self + 0x55);
  ext_524890(self + 0x21, f);
}
PCREG(516640, gapFn516640);

// 0x516780, GUESS FUN_00516780 (batch 82).
static void THISCALL gapFn516780(u8 *self, float f) {
  *(u32 *)(self + 0x11) = 0xc4bb8000;
  *(u32 *)(self + 0x15) = 0x42700000;
  *(u32 *)(self + 0x19) = 0x42f00000;
  *(u32 *)(self + 0x1d) = 0x42be0000;
  ext_4690b0(self + 0x41);
  ext_4690b0(self + 0x55);
  ext_524890(self + 0x21, f);
}
PCREG(516780, gapFn516780);
