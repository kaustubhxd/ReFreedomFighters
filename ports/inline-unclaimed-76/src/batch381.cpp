// batch381.cpp - area 76, residue 17 (out/functions.jsonl): four cdecl list moves, no arguments, plain ret (GUESS). Each moves a pending
// pair (globals A, B) into the list, as 0x671fe0 does (batch373): if A != 0 { A.+0x14 = B; B = [B-global]; A = [A-global] } else
// [0x7003bc] = B; if B != 0 { B.+0x10 = A } else [0x7003c0] = A; then clear both globals.
//   0x6710d0: A = 0x6e69ec, B = 0x6e69f0.     0x671210: A = 0x6e6828, B = 0x6e682c.
//   0x671350: A = 0x6e6c90, B = 0x6e6c94.     0x671490: A = 0x6e6da8, B = 0x6e6dac.
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

static void __attribute__((cdecl)) f6710d0(void) { move_pair(0x6e69ecu, 0x6e69f0u); }
PCREG(6710d0, f6710d0);
static void __attribute__((cdecl)) f671210(void) { move_pair(0x6e6828u, 0x6e682cu); }
PCREG(671210, f671210);
static void __attribute__((cdecl)) f671350(void) { move_pair(0x6e6c90u, 0x6e6c94u); }
PCREG(671350, f671350);
static void __attribute__((cdecl)) f671490(void) { move_pair(0x6e6da8u, 0x6e6dacu); }
PCREG(671490, f671490);
