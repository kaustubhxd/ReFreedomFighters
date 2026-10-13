// batch331.cpp - decomp area 64 (docs/20-unclaimed-64.md), slice floor(addr/16) mod 20 == 3.
#include "ff.h"

// Exe table lookup 0x5003d0 (thiscall, one stack word = index, ret 4). See batch326.cpp.
extern "C" u32 THISCALL ext_5003d0(u8 *table, u32 index);

// Virtual call on the child: slot 0x2e0, thiscall with two stack words (the callee pops 8).
typedef u32(__attribute__((thiscall)) * Slot2WordFn)(u8 *, u32, u32);

// 0x519b70: thiscall (ecx = self, one stack pointer p, ret 4). T = p[+4]; e1 = lookup(T, 1); e0 = lookup(T, 0);
// r = self[+0x14]->vtbl[0x2e0](child, *e0, *e1). Returns r. GUESS: a child method fed the first two entries of a table.
static u32 THISCALL twoEntries_519b70(u8 *self, u8 *p) {
    u8 *T = *(u8 **)(p + 0x4);
    u32 e1 = ext_5003d0(T, 1u);
    u32 e0 = ext_5003d0(T, 0u);
    u8 *child = *(u8 **)(self + 0x14);
    void **vt = *(void ***)child;
    return ((Slot2WordFn)vt[0x2e0 / 4])(child, *(u32 *)e0, *(u32 *)e1);
}
PCREG(519b70, twoEntries_519b70);
