// batch351.cpp - decomp area 64 (docs/20-unclaimed-64.md): verifies the exe string compare 0x59be70.
#include "ff.h"

// Exe helper 0x5b1000: thiscall (ecx = obj+0x50f), one stack word (the string pointer), ret 4; returns eax. Stubbed on both
// sides in the spec (it reads the object's fields and faults on random ones).
extern "C" u32 THISCALL ext_5b1000(u8 *obj, u32 str);

// Compare two NUL-terminated strings the way the exe does: two bytes at a time, stopping at the first mismatch or at a NUL.
// Returns true when they are equal.
static bool eqAt(const u8 *a, const u8 *b) {
    for (;;) {
        u8 x = a[0];
        if (x != b[0]) return false;
        if (x == 0) return true;
        u8 y = a[1];
        if (y != b[1]) return false;
        a += 2;
        b += 2;
        if (y == 0) return true;
    }
}

// 0x59be70: thiscall (ecx = obj, no stack words). s = obj+0x48. If s equals the string at 0x6a7808, return 0. Else if s
// equals the string at 0x6adcc8, return 1. Else return ext 0x5b1000(obj+0x50f, s). GUESS: a two-constant string classifier
// with a fallback to a sub-object.
static u32 THISCALL classify_59be70(u8 *obj) {
    u8 *s = obj + 0x48;
    if (eqAt(s, (const u8 *)0x6a7808)) return 0;
    if (eqAt(s, (const u8 *)0x6adcc8)) return 1;
    return ext_5b1000(obj + 0x50f, (u32)s);
}
PCREG(59be70, classify_59be70);
