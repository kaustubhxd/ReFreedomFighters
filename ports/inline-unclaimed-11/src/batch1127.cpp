// batch1127.cpp - unclaimed-11 batch 28 (gap band): 0x5ab190, GUESS (eighteen stack args, ret 0x48).
#include "ff.h"

static void THISCALL guessCopyEighteen(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8,
                                       u32 a9, u32 a10, u32 a11, u32 a12, u32 a13, u32 a14, u32 a15, u32 a16, u32 a17,
                                       u32 a18) {
  u32 b0[4] = {a1, a2, a3, a4};
  u32 b1[4] = {a5, a6, a7, a8};
  u32 b2[4] = {a9, a10, a11, a12};
  u32 b3[4] = {a13, a14, a15, a16};
  __builtin_memcpy(self + 0x37d, b0, 16);
  __builtin_memcpy(self + 0x38d, b1, 16);
  __builtin_memcpy(self + 0x39d, b2, 16);
  __builtin_memcpy(self + 0x3ad, b3, 16);
  *(u32 *)(self + 0x3bd) = a17;
  self[0x3c1] = (u8)a18;
}
PCREG(5ab190, guessCopyEighteen);
