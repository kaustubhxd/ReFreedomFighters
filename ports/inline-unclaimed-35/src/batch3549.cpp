#include "ff.h"
// batch3549.cpp - slice 14, batch 49: 0x62cfe0 and 0x4cca60 (two 0-call leaves).
// No external calls; pure leaf functions.

u32 gap62cfe0(u8 *arg0, u32 arg1) {
  if (arg1 == 0xf)
    return 0;
  if (arg1 == 0x12 || arg1 == 0x29) {
    *(u32 *)arg0 = 0x62d030;
    return 3;
  }
  if (*(u32 *)(arg0 + 0xc) != 0) {
    *(u32 *)arg0 = 0x51f230;
    return 0xffffffffu;  // -1
  }
  if (arg1 == 0x1c)
    return 0x34;
  // else: fall through to shared code
  *(u32 *)arg0 = 0x51f230;
  return 0xffffffffu;  // -1
}
PCREG(62cfe0, gap62cfe0);

u8 *THISCALL gap4cca60(u8 *self, u32 arg0, u32 arg1) {
  // cmovge edx, [ebp+8] with preceding cmp [ebp+8], 1: signed comparison
  u32 max_val = (((s32)arg0 >= 1) ? arg0 : 1);
  *(u32 *)(self + 0xc) = max_val;
  *(u32 *)(self + 0x18) = arg1 + 3;
  *(u32 *)(self + 0x10) = max_val * (arg1 + 3);
  *(u32 *)(self + 4) = 0;
  *(u32 *)(self + 8) = 0;
  *(u32 *)(self + 0x14) = 0;
  *(u32 *)(self + 0x1c) = 0;
  *(u32 *)(self + 0x20) = 0;
  *(u32 *)(self + 0x24) = 0;
  *(u32 *)self = 0x69595c;
  return self;
}
PCREG(4cca60, gap4cca60);
