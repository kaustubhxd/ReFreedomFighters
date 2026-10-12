// batch1936.cpp - unclaimed-66 batch 36 (gap band, GUESS names). Thiscall(X), ret 4. b = (*0x5003d0(ECX = [X+4], 0) != 0) (another area's
// helper, hooked in the spec). Then a tail jump in the PC code: vtable slot of a sub-object with b as the argument; the callee's EAX is
// the result, and its ret pops the argument slot. The port calls it and returns its EAX; the stack effect is the same.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(void *holder, u32 index);

static u32 boolFromHolder(u8 *x) {
  u8 *p = ext_5003d0(*(u8 **)(x + 4), 0);
  return (*(u32 *)p != 0) ? 1u : 0u;
}

// 0x5083a0, GUESS FUN_005083a0: sub = [this+0x18]; tail jump vtable +0x61c with b.
static u32 THISCALL gapFnQ(u8 *self, u8 *x) {
  u32 b = boolFromHolder(x);
  u8 *sub = *(u8 **)(self + 0x18);
  return vcall<u32>(sub, 0x61c, b);
}
PCREG(5083a0, gapFnQ);

// 0x519730, GUESS FUN_00519730: sub = [this+0x14]; tail jump vtable +0xbc with b.
static u32 THISCALL gapFnR(u8 *self, u8 *x) {
  u32 b = boolFromHolder(x);
  u8 *sub = *(u8 **)(self + 0x14);
  return vcall<u32>(sub, 0xbc, b);
}
PCREG(519730, gapFnR);

// 0x51b0b0, GUESS FUN_0051b0b0: sub = [this+0x1c]; tail jump vtable +0x36c with b.
static u32 THISCALL gapFnS(u8 *self, u8 *x) {
  u32 b = boolFromHolder(x);
  u8 *sub = *(u8 **)(self + 0x1c);
  return vcall<u32>(sub, 0x36c, b);
}
PCREG(51b0b0, gapFnS);
