// batch382.cpp - area 76, residue 17 (out/functions.jsonl): three more cdecl list moves, same shape as batch381 (GUESS).
//   0x6715d0: pair (0x6e6f30, 0x6e6f34).   0x671710: pair (0x6e7010, 0x6e7014).   0x671850: pair (0x6e7208, 0x6e720c).
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

static void __attribute__((cdecl)) f6715d0(void) { move_pair(0x6e6f30u, 0x6e6f34u); }
PCREG(6715d0, f6715d0);
static void __attribute__((cdecl)) f671710(void) { move_pair(0x6e7010u, 0x6e7014u); }
PCREG(671710, f671710);
static void __attribute__((cdecl)) f671850(void) { move_pair(0x6e7208u, 0x6e720cu); }
PCREG(671850, f671850);
