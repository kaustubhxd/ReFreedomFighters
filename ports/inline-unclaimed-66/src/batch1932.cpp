// batch1932.cpp - unclaimed-66 batch 32 (gap band, GUESS names). Thiscall(X), ret 4. b = (*0x5003d0(ECX = [X+4], arg 0) != 0);
// then a byte b stored into the sub-object at [this+0x18]: at +0x157 (0x5063a0) or +0x704 (0x508530). 0x5003d0 is another area's helper
// (hooked in the spec).
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(void *holder, u32 index);

static u8 boolFromHolder(u8 *x) {
  u8 *p = ext_5003d0(*(u8 **)(x + 4), 0);
  return (*(u32 *)p != 0) ? 1 : 0;
}

// 0x5063a0, GUESS FUN_005063a0.
static void THISCALL gapFnK(u8 *self, u8 *x) {
  u8 b = boolFromHolder(x);
  u8 *sub = *(u8 **)(self + 0x18);
  sub[0x157] = b;
}
PCREG(5063a0, gapFnK);

// 0x508530, GUESS FUN_00508530.
static void THISCALL gapFnL(u8 *self, u8 *x) {
  u8 b = boolFromHolder(x);
  u8 *sub = *(u8 **)(self + 0x18);
  sub[0x704] = b;
}
PCREG(508530, gapFnL);
