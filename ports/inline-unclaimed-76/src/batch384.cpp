// batch384.cpp - area 76, residue 17 (out/functions.jsonl): two more cdecl list moves, same shape as batch381 (GUESS).
//   0x671c10: pair (0x6e7320, 0x6e7324).   0x671d50: pair (0x6e75c8, 0x6e75cc).
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

static void __attribute__((cdecl)) f671c10(void) { move_pair(0x6e7320u, 0x6e7324u); }
PCREG(671c10, f671c10);
static void __attribute__((cdecl)) f671d50(void) { move_pair(0x6e75c8u, 0x6e75ccu); }
PCREG(671d50, f671d50);
