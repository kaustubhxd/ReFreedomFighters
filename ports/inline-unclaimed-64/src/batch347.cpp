// batch347.cpp - decomp area 64 (docs/20-unclaimed-64.md): verifies the exe predicate 0x4da3a0.
#include "ff.h"

// 0x4da3a0: thiscall (ecx = obj), no stack words, returns al. a = obj[+0x54]; if a is null, 0. b = a[+0x10]; if b is null,
// 0. If b[+8] == 0, 0. Else 1. GUESS: a has-target predicate on a chain of two sub-records.
static u8 THISCALL hasTarget_4da3a0(u8 *obj) {
    u8 *a = *(u8 **)(obj + 0x54);
    if (!a) return 0;
    u8 *b = *(u8 **)(a + 0x10);
    if (!b) return 0;
    if (*(u32 *)(b + 0x8) == 0) return 0;
    return 1;
}
PCREG(4da3a0, hasTarget_4da3a0);
