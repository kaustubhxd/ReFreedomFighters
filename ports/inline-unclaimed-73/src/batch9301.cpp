// batch9301.cpp - residue 6 batch 93: FUN_004f0020
#include "ff.h"

// 0x4f0020 (GUESS FUN_004f0020): thiscall, no arguments, returns byte in AL.
// Loads byte from [this+0x20] and returns it.
static u8 THISCALL guess4f0020(void *self) {
  return *(u8 *)((u8 *)self + 0x20);
}
PCREG(4f0020, guess4f0020);
