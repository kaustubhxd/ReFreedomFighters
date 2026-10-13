// batch336.cpp - decomp area 64 (docs/20-unclaimed-64.md), slice floor(addr/16) mod 20 == 3.
#include "ff.h"

// Exe table lookup 0x5003d0 (thiscall, one stack word = index, ret 4). See batch326.cpp.
extern "C" u32 THISCALL ext_5003d0(u8 *table, u32 index);

// Virtual call on the child: slot 0x5d8, thiscall with two stack words (the callee pops 8). Returns eax.
typedef u32(__attribute__((thiscall)) * Slot5d8Fn)(u8 *, u32, u32);

// 0x55c970: thiscall (ecx = self, one stack pointer p, ret 4). T = p[+4]; a = *lookup(T, 0);
// flag = (*lookup(T, 1) != 0); return self[+0x1c]->vtbl[0x5d8](child, a, flag). The exe's last call leaves eax as the
// callee returns it, so the port returns the callee's eax. GUESS: a child method given a table value and a flag.
static u32 THISCALL childFlag_55c970(u8 *self, u8 *p) {
    u8 *T = *(u8 **)(p + 0x4);
    u32 e0 = ext_5003d0(T, 0u);
    u32 a = *(u32 *)e0;
    u32 e1 = ext_5003d0(T, 1u);
    u32 flag = *(u32 *)e1 != 0 ? 1u : 0u;
    u8 *child = *(u8 **)(self + 0x1c);
    void **vt = *(void ***)child;
    return ((Slot5d8Fn)vt[0x5d8 / 4])(child, a, flag);
}
PCREG(55c970, childFlag_55c970);
