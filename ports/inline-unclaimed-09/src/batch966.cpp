// batch966.cpp - area 56 band, claim A30 (0x5273b0): a constructor that calls 0x526ef0 (A29, original exe code).
#include "ff.h"

extern "C" u8 *THISCALL ext_526ef0(u8 *self);  // original exe constructor (not hooked)

// A30 0x5273b0: sets the vtable, calls the 0x526ef0 constructor on this+0x28, sets three fields, returns this.
static u8 *THISCALL ctor5273b0(u8 *self) {
  *(u32 *)self = 0x6a0ae8;
  ext_526ef0(self + 0x28);
  *(u32 *)(self + 0x1c) = 0x39000000u;
  *(u32 *)(self + 0x20) = 0;
  *(u32 *)(self + 0x24) = 0x39000000u;
  return self;
}
PCREG(5273b0, ctor5273b0);
