// batch33018.cpp - h3 batch 33018: simple tail-jump thunks
#include "ff.h"

extern "C" void THISCALL ext_471540(u8 *self);
extern "C" void THISCALL ext_4c16b0(u8 *self);

// 0x471630, thiscall: standard frame, tail-jumps to 0x471540
static void THISCALL fn471630(u8 *self) {
  ext_471540(self);
}
PCREG(471630, fn471630);

// 0x4bf4e0, thiscall: standard frame, tail-jumps to 0x4c16b0
static void THISCALL fn4bf4e0(u8 *self) {
  ext_4c16b0(self);
}
PCREG(4bf4e0, fn4bf4e0);
