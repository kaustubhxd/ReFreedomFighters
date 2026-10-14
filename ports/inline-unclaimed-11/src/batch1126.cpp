// batch1126.cpp - unclaimed-11 batch 27 (gap band): 0x5b7b90, GUESS struct initializer (ret 8, returns this).
#include "ff.h"

static u8 *THISCALL guessStructInit(u8 *self, u32 a1, u32 a2) {
  *(u32 *)(self + 0) = a1;
  *(u32 *)(self + 8) = a2;  // the float argument, stored as its bits
  *(u32 *)(self + 4) = 0;
  *(u32 *)(self + 0x24) = 0;
  *(u32 *)(self + 0x14) = 0;
  *(u32 *)(self + 0x10) = 0;
  *(u32 *)(self + 0xc) = 0;
  self[0x28] = 0;
  return self;
}
PCREG(5b7b90, guessStructInit);
