// batch321.cpp - decomp area 64 (docs/20-unclaimed-64.md), slice floor(addr/16) mod 20 == 3.
#include "ff.h"

// Virtual call on self: slot 0xb0, thiscall with two stack words (first x, then 0); the callee pops 8. Returns eax.
typedef u32(__attribute__((thiscall)) * Slot_b0_Fn)(u8 *, u32, u32);

// 0x4d2ef0: thiscall (ecx = self, stack words x and an unused word, ret 8).
// r = self->vtbl[0xb0](self, x, 0). If r == 0, returns 0. Otherwise returns (*(u32 *)r) + 0xc + r: the first word of r
// (its vtable pointer) plus 12 plus r. GUESS: a lookup through a slot whose result is an object, then a pointer offset.
static u32 THISCALL lookup_4d2ef0(u8 *self, u32 x, u32) {
    void **vt = *(void ***)self;
    u32 r = ((Slot_b0_Fn)vt[0xb0 / 4])(self, x, 0u);
    if (r == 0) return 0;
    return *(u32 *)r + 0xc + r;
}
PCREG(4d2ef0, lookup_4d2ef0);
