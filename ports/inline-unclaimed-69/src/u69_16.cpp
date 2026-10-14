// u69_16.cpp - area 69, group 16 (unclaimed-69 thread).
#include "ff.h"

// 0x54cb50, thiscall, no args (ret), no callees. Sets the vtable at self to 0x6a3de4, zeroes self+4 and self+0xc, returns self.
static u8 *THISCALL initVt6a3de4(u8 *self) {
  *(u32 *)(self + 4) = 0;
  *(u32 *)self = 0x6a3de4;
  *(u32 *)(self + 0xc) = 0;
  return self;
}
PCREG(54cb50, initVt6a3de4);
