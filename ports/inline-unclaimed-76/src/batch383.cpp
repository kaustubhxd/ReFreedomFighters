// batch383.cpp - area 76, residue 17 (out/functions.jsonl): two more cdecl list moves, same shape as batch381 (GUESS).
//   0x671990: pair (0x6e7128, 0x6e712c).   0x671ad0: pair (0x6e7080, 0x6e7084).
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

static void __attribute__((cdecl)) f671990(void) { move_pair(0x6e7128u, 0x6e712cu); }
PCREG(671990, f671990);
static void __attribute__((cdecl)) f671ad0(void) { move_pair(0x6e7080u, 0x6e7084u); }
PCREG(671ad0, f671ad0);
