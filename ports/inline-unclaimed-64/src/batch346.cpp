// batch346.cpp - decomp area 64 (docs/20-unclaimed-64.md): verifies the exe table lookup 0x5003d0 (helper used by many batches).
#include "ff.h"

// Exe hook global at 0x7003b0: called on an out-of-range lookup (cdecl-style call with no words; the exe does `call eax`).
// The out-of-range paths are not exercised by the spec (inputs are kept in range); see the doc.
typedef void(__attribute__((cdecl)) * LookupHookFn)();

// 0x5003d0: thiscall (ecx = table T: T[0] = inner, T[+4] = base, T[+8] = count), one stack word = index, ret 4.
// If index >= T[+8]: out-of-range path (hook, then a second check; not exercised here).
// Else k = base + index (in inner); if k >= inner[+8]: the hook path (here: call the hook if set, then return the same entry);
// else return inner[0] + k * 8. GUESS: a bounds-checked element address into a table of 8-byte records.
static u8 *THISCALL lookup_5003d0(u8 *T, u32 index) {
    u32 count = *(u32 *)(T + 0x8);
    if (index >= count) {
        LookupHookFn h = G(LookupHookFn, 0x7003b0);
        if (!h) __builtin_trap();
        h();
    }
    u8 *inner = *(u8 **)T;
    u32 k = *(u32 *)(T + 0x4) + index;
    if (k >= *(u32 *)(inner + 0x8)) {
        LookupHookFn h = G(LookupHookFn, 0x7003b0);
        if (!h) __builtin_trap();
        h();
    }
    return *(u8 **)inner + k * 8;
}
PCREG(5003d0, lookup_5003d0);
