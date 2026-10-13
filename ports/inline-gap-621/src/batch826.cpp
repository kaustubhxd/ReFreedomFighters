// batch826.cpp - gap band getter functions (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

// 0x6387c0: thiscall() ret 4 - read [this+0x24]
static u32 THISCALL getter_0x24_6387c0(u8 *self) {
  return *(u32 *)(self + 0x24);
}
PCREG(6387c0, getter_0x24_6387c0);

// 0x638c80: thiscall() ret 4 - read [this+0x29]
static u32 THISCALL getter_0x29_638c80(u8 *self) {
  return *(u32 *)(self + 0x29);
}
PCREG(638c80, getter_0x29_638c80);

// 0x638cb0: thiscall() ret 4 - read [this+0x18]
static u32 THISCALL getter_0x18_638cb0(u8 *self) {
  return *(u32 *)(self + 0x18);
}
PCREG(638cb0, getter_0x18_638cb0);
