// batch33026.cpp - h3 batch 33026: call and return wrappers
#include "ff.h"

extern "C" void THISCALL ext_466220(u8 *self);
extern "C" void THISCALL ext_573db0(u8 *self);

// 0x465650, thiscall: call 0x466220(this), return this
static u8 *THISCALL fn465650(u8 *self) {
  ext_466220(self);
  return self;
}
PCREG(465650, fn465650);

// 0x576320, thiscall: call 0x573db0(this), tail-jump to next
static void THISCALL fn576320(u8 *self) {
  ext_573db0(self);
}
PCREG(576320, fn576320);
