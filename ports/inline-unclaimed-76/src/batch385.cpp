// batch385.cpp - area 76, residue 17 (out/functions.jsonl): cdecl list move, same shape as batch381 (GUESS).
//   0x671e90: pair (0x6e771c, 0x6e7720).
#include "ff.h"

static void move_pair(u32 ga, u32 gb) {
    u32 a = *(u32 *)ga;
    u32 b = *(u32 *)gb;
    if (a != 0u) {
        *(u32 *)(a + 0x14u) = b;
        b = *(u32 *)gb;
        a = *(u32 *)ga;
    } else {
        *(u32 *)0x7003bcu = b;
    }
    if (b != 0u) {
        *(u32 *)(b + 0x10u) = a;
    } else {
        *(u32 *)0x7003c0u = a;
    }
    *(u32 *)ga = 0u;
    *(u32 *)gb = 0u;
}

static void __attribute__((cdecl)) f671e90(void) { move_pair(0x6e771cu, 0x6e7720u); }
PCREG(671e90, f671e90);
