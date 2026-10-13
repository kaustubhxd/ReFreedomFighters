#include "ff.h"
// batch2719.cpp - unclaimed-27 batch 19 (gap band; docs/20-unclaimed-27.md). Name unknown (GUESS).

// 0x5897d0 (GUESS): thiscall, no arguments, void, ret 0. Zeroes the dwords at this+0, +0x34, +0x38, +0x7c and +0xb0, then
// +0x7c and +0xb0 again.
static void THISCALL funcZeroFields(u8 *self) {
  *(u32 *)(self + 0x00) = 0;
  *(u32 *)(self + 0x34) = 0;
  *(u32 *)(self + 0x38) = 0;
  *(u32 *)(self + 0x7c) = 0;
  *(u32 *)(self + 0xb0) = 0;
  *(u32 *)(self + 0x7c) = 0;
  *(u32 *)(self + 0xb0) = 0;
}
PCREG(5897d0, funcZeroFields);
