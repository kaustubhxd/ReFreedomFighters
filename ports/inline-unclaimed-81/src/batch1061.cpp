// batch1061.cpp - area 81, batch 1061: 0x57fa80, data initializer
// Copies arguments from stack to object fields. Pure data movement, no calls.
#include "ff.h"

static void __attribute__((fastcall)) batch1061_init(u8 *self, u32 edx, u32 a1, u32 a2, u32 a3, u32 a4,
                                                       u32 a5, u32 a6, u32 a7, u32 a8, u32 a9, float f1, u8 b1) {
  *(u32 *)(self + 0x0) = a1;
  *(u32 *)(self + 0x4) = a2;
  *(u32 *)(self + 0x8) = a3;
  *(u32 *)(self + 0xc) = a4;
  *(u32 *)(self + 0x10) = a5;
  *(u32 *)(self + 0x14) = a6;
  *(u32 *)(self + 0x18) = a7;
  *(u32 *)(self + 0x1c) = a8;
  *(u32 *)(self + 0x20) = a9;
  *(float *)(self + 0x24) = f1;
  *(u8 *)(self + 0x28) = b1;
}

PCREG(57fa80, batch1061_init);
