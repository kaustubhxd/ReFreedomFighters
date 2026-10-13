// batch9401.cpp - residue 6 batch 94: FUN_0054bba0
#include "ff.h"

// 0x54bba0 (GUESS FUN_0054bba0): thiscall, no arguments, returns pointer.
// Returns address of [this+0x2c].
static void* THISCALL guess54bba0(void *self) {
  return (void *)((u8 *)self + 0x2c);
}
PCREG(54bba0, guess54bba0);
