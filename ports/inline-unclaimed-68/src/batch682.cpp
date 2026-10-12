// batch682.cpp - unclaimed-68 batch 2 (claim 2). Name: GUESS FUN_5ab0b0 (owner class unknown; see docs/20-unclaimed-68.md).
#include "ff.h"

// 0x5ab0b0 (GUESS): if the word at this+0x300 is not 0x10000000, increments the dword at this+0x8af.
static void THISCALL guessFun5ab0b0(u8 *self) {
  if (*(u32 *)(self + 0x300) != 0x10000000u) *(u32 *)(self + 0x8af) += 1;
}
PCREG(5ab0b0, guessFun5ab0b0);
