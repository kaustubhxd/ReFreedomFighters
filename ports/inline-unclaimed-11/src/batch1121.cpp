// batch1121.cpp - unclaimed-11 batch 22 (gap band): 0x5aeda0 only. 0x5aef10 (zeroing) is area 70's and area 62's, not counted here.
#include "ff.h"

// 0x5aeda0, GUESS: zeroes the sixteen dwords at this+0x00..0x3c (the PC calls 0x5aef10 for this), then returns this.
static u8 *THISCALL guessZeroAndReturn(u8 *self) {
  for (int i = 0; i < 16; ++i) *(u32 *)(self + 4 * i) = 0;
  return self;
}
PCREG(5aeda0, guessZeroAndReturn);
