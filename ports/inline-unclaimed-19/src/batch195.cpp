// batch195.cpp - unclaimed area 19 (docs/20-unclaimed-19.md), slice floor(addr/16) mod 20 == 18.
#include "ff.h"

// Exe helper 0x5003d0 (table lookup, thiscall, one stack argument, ret 4). Runs as original code.
extern "C" u32 THISCALL ext_5003d0(u8 *table, u32 index);

typedef u32 (__attribute__((thiscall)) *Slot2d0Fn_519760)(u8 *, float);

// 0x519760: T = [arg+4]; p = ext_5003d0(T, 0) (the lookup returns a pointer to a float); child = [this+0x14];
// return child->vtbl[0x2d0](child, *p) (push ecx, then movss into that slot, so one float argument; ret 4).
// GUESS: a float forward from a table entry to a child.
static u32 THISCALL floatForward_519760(u8 *self, u32 arg) {
    u8 *table = *(u8 **)(arg + 4);
    float v = *(float *)ext_5003d0(table, 0u);
    u8 *child = *(u8 **)(self + 0x14);
    void **vt = *(void ***)child;
    return ((Slot2d0Fn_519760)vt[0x2d0 / 4])(child, v);
}
PCREG(519760, floatForward_519760);
