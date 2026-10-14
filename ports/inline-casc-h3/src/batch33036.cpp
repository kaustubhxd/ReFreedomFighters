// batch33036.cpp - h3 cascade batch 33036: single tier B multi-field init
#include "ff.h"

extern "C" void THISCALL ext_5aedb0(u8 *self);  // thiscall, ret 0
extern "C" void THISCALL ext_5aeda0(u8 *self);  // thiscall, ret 0

// 0x5b02b0: thiscall (no args), initializes multiple fields and calls two functions, returns this
static u8 *THISCALL fn5b02b0(u8 *self) {
  *(u32 *)(self + 0x4) = 0;
  *(u32 *)self = 0x6b1148;
  ext_5aedb0(self + 0x18);
  ext_5aeda0(self + 0x2c);
  *(u32 *)(self + 0x8) = 0;
  *(u32 *)(self + 0xc) = 0;
  *(u32 *)(self + 0x10) = 0;
  *(u32 *)(self + 0x14) = 0;
  return self;
}
PCREG(5b02b0, fn5b02b0);
