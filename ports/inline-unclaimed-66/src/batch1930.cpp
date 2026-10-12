// batch1930.cpp - unclaimed-66 batch 30 (gap band, GUESS name). Thiscall with one stack argument X, ret 4. r = vtable +0x684 of
// [this+0x18] (no argument); p = 0x5003d0(ECX = [X+8], arg 0) and 0x5002f0(ECX = p, arg r) (other areas' helpers, hooked in the spec).
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(void *holder, u32 index);
extern "C" void THISCALL ext_5002f0(void *p, u32 r);

// 0x506bb0, GUESS FUN_00506bb0.
static void THISCALL gapFnF(u8 *self, u8 *x) {
  u8 *sub = *(u8 **)(self + 0x18);
  u32 r = vcall<u32>(sub, 0x684);
  u8 *p = ext_5003d0(*(u8 **)(x + 8), 0);
  ext_5002f0(p, r);
}
PCREG(506bb0, gapFnF);
