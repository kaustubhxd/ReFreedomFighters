// batch965.cpp - area 56 band, claim A29 (0x526ef0): a constructor with no calls.
#include "ff.h"

// A29 0x526ef0: sets the vtable and fields, returns this.
static u8 *THISCALL ctor526ef0(u8 *self) {
  *(u32 *)self = 0x6a09ec;
  *(u8 *)(self + 0x18) = 0;
  *(u32 *)(self + 0x14) = 0x3f800000u;
  *(u32 *)(self + 0x10) = 0;
  *(u32 *)(self + 0xc) = 0;
  *(u32 *)(self + 0x19) = 2;
  return self;
}
PCREG(526ef0, ctor526ef0);
