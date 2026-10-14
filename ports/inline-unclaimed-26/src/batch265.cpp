// batch265.cpp - unclaimed area 26 (docs/20-unclaimed-26.md), slice floor(addr/16) mod 20 == 5.
// Also residue-05 list (core-todo/residue-05.txt).
#include "ff.h"

typedef u32 (__attribute__((thiscall)) *Slot1_5be690)(u8 *, u32);
typedef u32 (__attribute__((thiscall)) *Slot0_5be690)(u8 *);

// 0x5be690: finds key in a table of 5-byte entries at this+0x718 (count at this+0x910) and returns its index. If absent:
// when count < cap (dword at this+0x992), appends the key (count++), sets the flag byte to 0xff, bumps the dword at
// this+0x91e and returns the old count; when count >= cap, sets the flag byte, calls engine->vtbl[0x58](key)->vtbl[0x20]()
// ->vtbl[0x28]() and returns the count. GUESS: an id table with a capacity check.
static u32 THISCALL findOrAdd_5be690(u8 *self, u32 key) {
    s32 n = *(s32 *)(self + 0x910);
    for (s32 k = 0; k < n; k++) {
        if (*(u32 *)(self + 0x718 + 5 * k) == key) return (u32)k;
    }
    u8 *edx = self + (u32)n * 4u;
    if (n >= *(s32 *)(self + 0x992)) {
        *(u8 *)(edx + (u32)n + 0x71c) = 0xffu;
        u8 *eng = G(u8 *, 0x70039c);
        u8 *o = *(u8 **)(eng + 0x9b);
        u8 *c = (u8 *)((Slot1_5be690)(*(void ***)o)[0x58 / 4])(o, key);
        u8 *r = (u8 *)((Slot0_5be690)(*(void ***)c)[0x20 / 4])(c);
        ((Slot0_5be690)(*(void ***)r)[0x28 / 4])(r);
        return (u32)n;
    }
    *(s32 *)(self + 0x910) = n + 1;
    *(u32 *)(edx + (u32)n + 0x718) = key;
    *(u8 *)(edx + (u32)n + 0x71c) = 0xffu;
    *(u32 *)(self + 0x91e) += 1u;
    return (u32)n;
}
PCREG(5be690, findOrAdd_5be690);
