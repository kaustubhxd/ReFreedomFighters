// batch1931.cpp - unclaimed-66 batch 31 (gap band, GUESS names). The helpers 0x5003d0 and 0x5002f0 are other areas' (hooked in the spec).
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(void *holder, u32 index);
extern "C" void THISCALL ext_5002f0(void *p, u32 r);

// 0x508260, GUESS FUN_00508260: thiscall(X) (ret 4). b = (the value at 0x5003d0(ECX = [X+4], 0)) != 0; then vtable +0x608 of [this+0x18]
// with b (a tail jump in the PC code: the callee pops b, and this function's ret 4 pops X).
static void THISCALL gapFnI(u8 *self, u8 *x) {
  u8 *p = ext_5003d0(*(u8 **)(x + 4), 0);
  u32 b = (*(u32 *)p != 0) ? 1u : 0u;
  u8 *sub = *(u8 **)(self + 0x18);
  vcall<void>(sub, 0x608, b);
}
PCREG(508260, gapFnI);

// 0x50b510, GUESS FUN_0050b510: stdcall(X) (ret 4). V = *0x5003d0(ECX = [X+4], 0); p = 0x5003d0(ECX = [X+8], 0); 0x5002f0(ECX = p, V).
static void STDCALL gapFnJ(u8 *x) {
  u8 *p1 = ext_5003d0(*(u8 **)(x + 4), 0);
  u32 v = *(u32 *)p1;
  u8 *p2 = ext_5003d0(*(u8 **)(x + 8), 0);
  ext_5002f0(p2, v);
}
PCREG(50b510, gapFnJ);
