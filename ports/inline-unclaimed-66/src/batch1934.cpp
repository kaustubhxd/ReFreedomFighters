// batch1934.cpp - unclaimed-66 batch 34 (gap band, GUESS names). Thiscall(X), ret 4. p = 0x5003d0(ECX = [X+4], arg 0) (another area's
// helper, hooked in the spec); then a vtable call on a sub-object with the dword at p as its argument: +0x68c of [this+0x18], or
// +0x394 of [this+0x20] (the callee pops it).
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(void *holder, u32 index);

// 0x5072c0, GUESS FUN_005072c0.
static void THISCALL gapFnN(u8 *self, u8 *x) {
  u8 *p = ext_5003d0(*(u8 **)(x + 4), 0);
  u8 *sub = *(u8 **)(self + 0x18);
  vcall<void>(sub, 0x68c, *(u32 *)p);
}
PCREG(5072c0, gapFnN);

// 0x51fd40, GUESS FUN_0051fd40.
static void THISCALL gapFnO(u8 *self, u8 *x) {
  u8 *p = ext_5003d0(*(u8 **)(x + 4), 0);
  u8 *sub = *(u8 **)(self + 0x20);
  vcall<void>(sub, 0x394, *(u32 *)p);
}
PCREG(51fd40, gapFnO);
