// batch1928.cpp - unclaimed-66 batch 28 (gap band, GUESS names). Thiscall with one stack argument X, ret 4.
// Original: r = vtable +0x37c (or +0x378 for the second) of [this+0x1c], no argument; p = 0x5003d0(ECX = the pointer stored at X+8, argument 0) (the other
// area's helper: bound to the original code, and HOOKED by address in the spec); then 0x5002f0(ECX = p, argument r) (also the other
// area's helper, HOOKED in the spec).
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(void *holder, u32 index);
extern "C" void THISCALL ext_5002f0(void *p, u32 r);

// 0x51b180, GUESS FUN_0051b180.
static void THISCALL gapFnA(u8 *self, u8 *x) {
  u8 *sub = *(u8 **)(self + 0x1c);
  u32 r = vcall<u32>(sub, 0x37c);
  u8 *p = ext_5003d0(*(u8 **)(x + 8), 0);
  ext_5002f0(p, r);
}
PCREG(51b180, gapFnA);

// 0x51b240, GUESS FUN_0051b240: the same with vtable +0x378.
static void THISCALL gapFnB(u8 *self, u8 *x) {
  u8 *sub = *(u8 **)(self + 0x1c);
  u32 r = vcall<u32>(sub, 0x378);
  u8 *p = ext_5003d0(*(u8 **)(x + 8), 0);
  ext_5002f0(p, r);
}
PCREG(51b240, gapFnB);
