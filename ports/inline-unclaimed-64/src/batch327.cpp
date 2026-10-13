// batch327.cpp - decomp area 64 (docs/20-unclaimed-64.md), slice floor(addr/16) mod 20 == 3.
#include "ff.h"

// Exe table lookup 0x5003d0 (thiscall, one stack word = index, ret 4). See batch326.cpp.
extern "C" u32 THISCALL ext_5003d0(u8 *table, u32 index);

// Exe helper 0x5002f0 (ecx = entry pointer, one stack word, ret 4). Its result is returned by 0x55f670 as eax.
// Runs as original code.
extern "C" u32 THISCALL ext_5002f0(u8 *entry, u32 value);

// 0x55f670: thiscall (ecx = self, one stack pointer p, ret 4). T = self[+0x18][+0x54]; entry = lookup(p[+8], 0);
// return 0x5002f0(entry, T[+4]). Returns the value 0x5002f0 leaves in eax. GUESS: a lookup then a store of a
// per-object value into the looked-up entry.
static u32 THISCALL storeLookup_55f670(u8 *self, u8 *p) {
    u8 *obj = *(u8 **)(self + 0x18);
    u8 *T = *(u8 **)(obj + 0x54);
    u8 *table = *(u8 **)(p + 0x8);
    u32 entry = ext_5003d0(table, 0u);
    return ext_5002f0((u8 *)entry, *(u32 *)(T + 0x4));
}
PCREG(55f670, storeLookup_55f670);
