// batch7979.cpp - residue 6 batch 79: two constant getters (GUESS names, the ABI is not visible in the body).
#include "ff.h"

// 0x63dae0 (GUESS FUN_0063dae0): returns 8.
static u32 THISCALL guess63dae0(u8 *self) {
  (void)self;
  return 8u;
}
PCREG(63dae0, guess63dae0);

// 0x63ec60 (GUESS FUN_0063ec60): returns 0x1fe.
static u32 THISCALL guess63ec60(u8 *self) {
  (void)self;
  return 0x1feu;
}
PCREG(63ec60, guess63ec60);
