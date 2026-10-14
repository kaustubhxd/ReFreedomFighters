// u69_33.cpp - area 69, group 33 (slice 8). No callees.
#include "ff.h"

// 0x648280, thiscall, no args (ret). Sets the vtable 0x6c2c20 at self, then clears bit 1 of the bytes at self+0x18282, self+0x1825e, self+0x10032 and self+9.
static void THISCALL initVt6c2c20(u8 *self) {
  *(u32 *)self = 0x6c2c20;
  self[0x18282] &= 0xfd;
  self[0x1825e] &= 0xfd;
  self[0x10032] &= 0xfd;
  self[9] &= 0xfd;
}
PCREG(648280, initVt6c2c20);
