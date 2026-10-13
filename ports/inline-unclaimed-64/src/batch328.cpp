// batch328.cpp - decomp area 64 (docs/20-unclaimed-64.md), slice floor(addr/16) mod 20 == 3.
#include "ff.h"

// Exe table lookup 0x5003d0 (thiscall, one stack word = index, ret 4). See batch326.cpp.
extern "C" u32 THISCALL ext_5003d0(u8 *table, u32 index);

// Exe search 0x59e610 (thiscall, ecx = obj, one stack word x, ret 4). It counts self[+0x7ce] down, and stops at the
// first entry at +0x7c2 + 16*idx whose dword is not below x (signed). On the no-loop path it returns with eax as it
// was on entry, so the caller must set eax (here: the entry pointer) before the call. Called through an inline-asm
// wrapper for that reason.
static inline u32 search59e610(u32 eaxIn, u8 *obj, u32 x) {
    u32 out;
    u32 fn = 0x59e610u;
    __asm__ volatile(
        "pushl %[x]\n\t"
        "calll *%%edx\n\t"
        : "=a"(out), "+c"(obj), "+d"(fn)
        : "a"(eaxIn), [x] "rm"(x)
        : "memory", "cc");
    return out;
}

// 0x5589b0: thiscall (ecx = self, one stack pointer p, ret 4). T = p[+4]; entry = lookup(T, 0);
// obj = self[+0x1c]; return 0x59e610(obj, *entry) with eax = entry. GUESS: a search over an object's table keyed by an
// entry value.
static u32 THISCALL searchEntry_5589b0(u8 *self, u8 *p) {
    u8 *T = *(u8 **)(p + 0x4);
    u32 entry = ext_5003d0(T, 0u);
    u8 *obj = *(u8 **)(self + 0x1c);
    return search59e610(entry, obj, *(u32 *)entry);
}
PCREG(5589b0, searchEntry_5589b0);
