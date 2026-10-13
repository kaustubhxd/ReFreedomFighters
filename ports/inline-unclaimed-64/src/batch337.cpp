// batch337.cpp - decomp area 64 (docs/20-unclaimed-64.md), slice floor(addr/16) mod 20 == 3.
#include "ff.h"

// Exe table lookup 0x5003d0 (thiscall, one stack word = index, ret 4). See batch326.cpp.
extern "C" u32 THISCALL ext_5003d0(u8 *table, u32 index);

// Exe helper 0x5002f0 (ecx = entry, one stack word, ret 4). Stubbed on both sides in the spec (see batch327.cpp).
extern "C" u32 THISCALL ext_5002f0(u8 *entry, u32 value);

// Virtual call on the object: slot 0x6dc, thiscall with one stack word (the callee pops 4). Returns eax.
typedef u32(__attribute__((thiscall)) * Slot6dcFn)(u8 *, u32);

// 0x55acb0: thiscall (ecx = self, one stack pointer p, ret 4). obj = self[+0x1c]; r = obj->vtbl[0x6dc](obj, 0);
// entry = lookup(p[+8], 0); return 0x5002f0(entry, r). Returns the eax that helper leaves. GUESS: a query on an object
// whose answer is stored into a table entry.
static u32 THISCALL storeQuery_55acb0(u8 *self, u8 *p) {
    u8 *obj = *(u8 **)(self + 0x1c);
    void **vt = *(void ***)obj;
    u32 r = ((Slot6dcFn)vt[0x6dc / 4])(obj, 0u);
    u8 *T = *(u8 **)(p + 0x8);
    u32 entry = ext_5003d0(T, 0u);
    return ext_5002f0((u8 *)entry, r);
}
PCREG(55acb0, storeQuery_55acb0);
