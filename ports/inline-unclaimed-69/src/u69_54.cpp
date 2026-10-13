// u69_54.cpp - area 69, group 54 (slice 8). A constructor with field stores. No callees.
#include "ff.h"

// 0x41e180, thiscall no args (ret), returns this. Sets the vtable 0x67716c and zeroes the fields the original writes; the byte at +0x30 is 1 and the word at +0x4d is 1.
static u8 *THISCALL ctor67716c41e180(u8 *self) {
  *(u32 *)self = 0x67716c;
  *(u32 *)(self + 4) = 0;
  *(u32 *)(self + 8) = 0;
  *(u32 *)(self + 0xc) = 0;
  *(u32 *)(self + 0x10) = 0;
  *(u32 *)(self + 0x14) = 0;
  *(u32 *)(self + 0x18) = 0;
  *(u32 *)(self + 0x1c) = 0;
  *(u32 *)(self + 0x20) = 0;
  *(u32 *)(self + 0x28) = 0;
  *(u32 *)(self + 0x2c) = 0;
  self[0x30] = 1;
  *(u32 *)(self + 0x35) = 0;
  *(u32 *)(self + 0x39) = 0;
  *(u32 *)(self + 0x3d) = 0;
  *(u32 *)(self + 0x41) = 0;
  *(u32 *)(self + 0x45) = 0;
  *(u32 *)(self + 0x49) = 0;
  *(u16 *)(self + 0x4d) = 1;
  return self;
}
PCREG(41e180, ctor67716c41e180);
