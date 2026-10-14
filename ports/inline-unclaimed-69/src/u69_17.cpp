// u69_17.cpp - area 69, group 17 (unclaimed-69 thread).
#include "ff.h"

// 0x5b7bd0, thiscall, no args (ret), no callees. Zeroes self[0] and self[4], sets self+8 to 0x40000000, zeroes self+0x24 and the byte at self+0x28, returns self.
static u8 *THISCALL initFields5b7bd0(u8 *self) {
  *(u32 *)self = 0;
  *(u32 *)(self + 4) = 0;
  *(u32 *)(self + 8) = 0x40000000;
  *(u32 *)(self + 0x24) = 0;
  self[0x28] = 0;
  return self;
}
PCREG(5b7bd0, initFields5b7bd0);
