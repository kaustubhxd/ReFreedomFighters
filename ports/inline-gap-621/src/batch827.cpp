// batch827.cpp - gap band getter/setter functions (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

// 0x638cc0: thiscall() ret 4 - read [this+0x2d]
static u32 THISCALL getter_0x2d_638cc0(u8 *self) {
  return *(u32 *)(self + 0x2d);
}
PCREG(638cc0, getter_0x2d_638cc0);

// 0x638cd0: thiscall() ret 4 - read [this+0x32]
static u32 THISCALL getter_0x32_638cd0(u8 *self) {
  return *(u32 *)(self + 0x32);
}
PCREG(638cd0, getter_0x32_638cd0);

// 0x638ce0: thiscall() ret 4 - read [this+0x20]
static u32 THISCALL getter_0x20_638ce0(u8 *self) {
  return *(u32 *)(self + 0x20);
}
PCREG(638ce0, getter_0x20_638ce0);

// 0x635330: thiscall() ret 0 - OR [this+4] with 1
static void THISCALL or_one_635330(u8 *self) {
  *(u32 *)(self + 4) |= 1;
}
PCREG(635330, or_one_635330);
