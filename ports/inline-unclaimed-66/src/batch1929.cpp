// batch1929.cpp - unclaimed-66 batch 29 (gap band, GUESS names). Thiscall with one stack argument X, ret 4. The same shape as batch 28,
// with the sub-object at this+0x14: r = vtable (+0x350, +0x35c or +0x2d8) of [this+0x14]; p = 0x5003d0(ECX = [X+8], arg 0) and
// 0x5002f0(ECX = p, arg r) (other areas' helpers, hooked in the spec).
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(void *holder, u32 index);
extern "C" void THISCALL ext_5002f0(void *p, u32 r);

static void THISCALL shapeFn(u8 *self, u8 *x, u32 slot) {
  u8 *sub = *(u8 **)(self + 0x14);
  u32 r = vcall<u32>(sub, slot);
  u8 *p = ext_5003d0(*(u8 **)(x + 8), 0);
  ext_5002f0(p, r);
}

// 0x5195b0, GUESS FUN_005195b0 (slot +0x350).
static void THISCALL gapFnC(u8 *self, u8 *x) { shapeFn(self, x, 0x350); }
PCREG(5195b0, gapFnC);

// 0x5195e0, GUESS FUN_005195e0 (slot +0x35c).
static void THISCALL gapFnD(u8 *self, u8 *x) { shapeFn(self, x, 0x35c); }
PCREG(5195e0, gapFnD);

// 0x519670, GUESS FUN_00519670 (slot +0x2d8).
static void THISCALL gapFnE(u8 *self, u8 *x) { shapeFn(self, x, 0x2d8); }
PCREG(519670, gapFnE);
