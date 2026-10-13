// batch326.cpp - decomp area 64 (docs/20-unclaimed-64.md), slice floor(addr/16) mod 20 == 3.
#include "ff.h"

// Exe table lookup 0x5003d0: thiscall (ecx = table T, one stack word = index, ret 4). Returns a pointer to entry
// data + (base + index) * 8, where T[0] = inner, T[+4] = base, inner[0] = data, inner[+8] = size. Runs as original code.
extern "C" u32 THISCALL ext_5003d0(u8 *table, u32 index);

// Exe setter 0x59d430: thiscall (ecx = target, one stack word = mode, ret 4); stores mode and runs the switch 0x59d450.
extern "C" void THISCALL ext_59d430(u8 *target, u32 mode);

// 0x55cab0: thiscall (ecx = self, one stack word p, ret 4), returns nothing used (plain eax value dropped).
// T = p[+4]; entry = lookup(T, 0); obj = self[+0x1c]; target = obj[+0x54]; 0x59d430(target, *(u32 *)entry).
// GUESS: a setter that takes the mode for a child from a table entry at index 0.
static void THISCALL setModeFromTable_55cab0(u8 *self, u8 *p) {
    u8 *table = *(u8 **)(p + 0x4);
    u32 entry = ext_5003d0(table, 0u);
    u8 *obj = *(u8 **)(self + 0x1c);
    u8 *target = *(u8 **)(obj + 0x54);
    ext_59d430(target, *(u32 *)entry);
}
PCREG(55cab0, setModeFromTable_55cab0);
