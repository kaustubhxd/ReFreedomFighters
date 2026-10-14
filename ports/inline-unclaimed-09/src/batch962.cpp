// batch962.cpp - area 56 band, claim A25 (0x537880).
#include "ff.h"

extern "C" void THISCALL ext_4690b0(u8 *self);  // original exe helper (hooked in the spec); ecx only, no pushed arguments

// A25 0x537880: if this->0x52fa then ext_4690b0(this->0x52fa); tail-jump through vt[0x194] with ecx = this (no arguments).
static u32 THISCALL tail537880(u8 *self) {
  u8 *fld = *(u8 **)(self + 0x52fa);
  if (fld) ext_4690b0(fld);
  u8 *vt = *(u8 **)self;
  return ((u32(THISCALL *)(u8 *))(*(u32 *)((u8 *)vt + 0x194)))(self);
}
PCREG(537880, tail537880);
