// batch1935.cpp - unclaimed-66 batch 35 (gap band, GUESS name). Thiscall(X), ret 4. p = 0x5003d0(ECX = [X+4], arg 0) (another area's
// helper, hooked in the spec); then vtable +0x658 of [this+0x18] with the float at p as its argument (the four bytes, not converted).
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(void *holder, u32 index);

// 0x5081c0, GUESS FUN_005081c0.
static void THISCALL gapFnP(u8 *self, u8 *x) {
  u8 *p = ext_5003d0(*(u8 **)(x + 4), 0);
  u8 *sub = *(u8 **)(self + 0x18);
  vcall<void>(sub, 0x658, *(u32 *)p);
}
PCREG(5081c0, gapFnP);
