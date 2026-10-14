// u69_70.cpp - area 69, group 70 (slice 8). A constructor with field stores. No callees.
#include "ff.h"

// 0x499880, thiscall two stack args (ret 8), returns this. Sets the vtable 0x68e9cc, zeroes +4, +8, +0xc, sets +0x14 and +0x18 to -1, +0x1c = arg1, +0x20 = arg2.
static u8 *THISCALL ctor68e9cc499880(u8 *self, u32 a1, u32 a2) {
  *(u32 *)self = 0x68e9cc;
  *(u32 *)(self + 4) = 0;
  *(u32 *)(self + 8) = 0;
  *(u32 *)(self + 0xc) = 0;
  *(u32 *)(self + 0x14) = 0xffffffffu;
  *(u32 *)(self + 0x18) = 0xffffffffu;
  *(u32 *)(self + 0x1c) = a1;
  *(u32 *)(self + 0x20) = a2;
  return self;
}
PCREG(499880, ctor68e9cc499880);
