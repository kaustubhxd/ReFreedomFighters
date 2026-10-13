// batch332.cpp - decomp area 64 (docs/20-unclaimed-64.md), slice floor(addr/16) mod 20 == 3.
#include "ff.h"

// Exe table lookup 0x5003d0 (thiscall, one stack word = index, ret 4). See batch326.cpp.
extern "C" u32 THISCALL ext_5003d0(u8 *table, u32 index);

// Exe method 0x514410: thiscall (ecx = child, stack a (u32), stack f (float), ret 8). It calls the sub-object at
// child[+0x5c] and returns with eax as left by that call, so the caller sets eax (here: the index-0 entry pointer)
// before the call, through an inline-asm wrapper. The float travels as its bit pattern.
static inline u32 call514410(u8 *child, u32 eaxIn, u32 a, u32 fbits) {
    u32 fn = 0x514410u;
    u32 eaxv = eaxIn;
    __asm__ volatile(
        "pushl %[f]\n\t"
        "pushl %[a]\n\t"
        "calll *%%edx\n\t"
        : "+a"(eaxv), "+c"(child), "+d"(fn)
        : [a] "r"(a), [f] "r"(fbits)
        : "memory", "cc");
    return eaxv;
}

// 0x519cb0: thiscall (ecx = self, one stack pointer p, ret 4). T = p[+4]; e1 = lookup(T, 1); e0 = lookup(T, 0);
// call 0x514410 on self[+0x14] with (*e0 as u32, *e1 as float). Returns the eax that call leaves.
// GUESS: a child method fed one integer and one float taken from table entries.
static u32 THISCALL childCall_519cb0(u8 *self, u8 *p) {
    u8 *T = *(u8 **)(p + 0x4);
    u32 e1 = ext_5003d0(T, 1u);
    u32 e0 = ext_5003d0(T, 0u);
    u32 fbits = *(u32 *)e1;
    u8 *child = *(u8 **)(self + 0x14);
    return call514410(child, e0, *(u32 *)e0, fbits);
}
PCREG(519cb0, childCall_519cb0);
