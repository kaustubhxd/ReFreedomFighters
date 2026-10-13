// batch384.cpp - 0x41e180 (gap band). thiscall (this = ECX), no arguments, returns this (eax).
// Constructor: stores vtable 0x67716c at +0, zeroes the fields, sets word +0x4d = 1 and byte +0x30 = 1.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

static u8 *THISCALL initDefaults(u8 *self) {
  U32(self, 0x00) = 0x67716c;
  U32(self, 0x49) = 0;
  // movups of 16 zero bytes at +0x35 (dwords +0x35..+0x44)
  for (u32 i = 0x35; i < 0x45; i++) self[i] = 0;
  U32(self, 0x18) = 0;
  U32(self, 0x1c) = 0;
  U32(self, 0x45) = 0;
  U32(self, 0x14) = 0;
  *(u16 *)(self + 0x4d) = 1;
  U32(self, 0x20) = 0;
  U32(self, 0x28) = 0;
  U32(self, 0x04) = 0;
  U32(self, 0x08) = 0;
  U32(self, 0x0c) = 0;
  U32(self, 0x10) = 0;
  self[0x30] = 1;
  U32(self, 0x2c) = 0;
  return self;
}
PCREG(41e180, initDefaults);
