// batch1957.cpp - unclaimed-66 batch 67 (gap band, GUESS name). THISCALL(this), no arguments, plain ret; returns this in eax.
//   Clears the fields: [this] = 0, [+4] = 0, [+8] = 0, [+0x30] = 0x41000000 (8.0f), [+0x34] = 0x41000000, [+0x14..+0x2c] = 0 (seven dwords).
#include "ff.h"

// 0x511c60, GUESS FUN_00511c60 (batch 67).
static u8 *THISCALL gapInit511c60(u8 *self) {
  *(u32 *)self = 0;
  *(u32 *)(self + 4) = 0;
  *(u32 *)(self + 8) = 0;
  *(u32 *)(self + 0x30) = 0x41000000;
  *(u32 *)(self + 0x34) = 0x41000000;
  *(u32 *)(self + 0x14) = 0;
  *(u32 *)(self + 0x18) = 0;
  *(u32 *)(self + 0x1c) = 0;
  *(u32 *)(self + 0x20) = 0;
  *(u32 *)(self + 0x24) = 0;
  *(u32 *)(self + 0x28) = 0;
  *(u32 *)(self + 0x2c) = 0;
  return self;
}
PCREG(511c60, gapInit511c60);
