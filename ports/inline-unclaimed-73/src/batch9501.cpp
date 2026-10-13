// batch9501.cpp - residue 6 batch 95: FUN_005acfe0
#include "ff.h"

// 0x5acfe0 (GUESS FUN_005acfe0): thiscall, no arguments, returns pointer.
// Returns address of [this+8].
static void* THISCALL guess5acfe0(void *self) {
  return (void *)((u8 *)self + 8);
}
PCREG(5acfe0, guess5acfe0);
