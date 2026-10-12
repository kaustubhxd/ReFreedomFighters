// batch196.cpp - unclaimed area 19 (docs/20-unclaimed-19.md), slice floor(addr/16) mod 20 == 18.
#include "ff.h"

// Exe helper 0x5003d0 (table lookup, thiscall, one stack argument, ret 4). Runs as original code.
extern "C" u32 THISCALL ext_5003d0(u8 *table, u32 index);

typedef u32 (__attribute__((thiscall)) *Slot390Fn_51b060)(u8 *, float, u32);

// 0x51b060: T = [arg+4]; p1 = ext_5003d0(T, 1); p0 = ext_5003d0(T, 0) (the table is reread for the second call).
// Then child = [this+0x1c] and child->vtbl[0x390](child, *p0 as float, (*p1 != 0) as u32), ret 4. GUESS: a
// two-entry table read that forwards to a child.
static u32 THISCALL pairForward_51b060(u8 *self, u32 arg) {
    u8 *table = *(u8 **)(arg + 4);
    u32 *p1 = (u32 *)ext_5003d0(table, 1u);
    table = *(u8 **)(arg + 4);
    float p0 = *(float *)ext_5003d0(table, 0u);
    u32 nz = *p1 != 0u ? 1u : 0u;
    u8 *child = *(u8 **)(self + 0x1c);
    void **vt = *(void ***)child;
    return ((Slot390Fn_51b060)vt[0x390 / 4])(child, p0, nz);
}
PCREG(51b060, pairForward_51b060);
