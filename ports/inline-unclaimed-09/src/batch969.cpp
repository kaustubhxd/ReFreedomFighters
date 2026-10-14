// batch969.cpp - area 56 band, claim A34 (0x524660): a constructor with no calls.
#include "ff.h"

// A34 0x524660: zero and float-constant fields; returns this.
static u8 *THISCALL ctor524660(u8 *self) {
  *(u32 *)self = 0;
  *(u32 *)(self + 4) = 0;
  *(u32 *)(self + 8) = 0;
  *(u32 *)(self + 0x18) = 0;
  *(u32 *)(self + 0x1c) = 0;
  *(u32 *)(self + 0xc) = 0x46c35000u;
  *(u32 *)(self + 0x10) = 0x44fa0000u;
  *(u32 *)(self + 0x14) = 0x42a00000u;
  return self;
}
PCREG(524660, ctor524660);
