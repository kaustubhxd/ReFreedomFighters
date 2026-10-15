// batch293.cpp - unclaimed area 76 (docs/20-unclaimed-76.md), residue 15: 0x5edc80 and 0x5edcb0 (a rotate of a buffer).
#include "ff.h"

// 0x5edc80: __fastcall (ECX = a, EDX = b, one stack argument; ret 4, unused). Swap the dwords at a and (b - 4) walking inward
// until the two pointers meet. GUESS: a half of an in-place rotation.
static void FASTCALL swapInward_5edc80(u32 a, u32 b, u32 unused) {
    (void)unused;
    if (a == b) return;
    b -= 4;
    if (a == b) return;
    for (;;) {
        u32 t = *(u32 *)a;
        *(u32 *)a = *(u32 *)b;
        a += 4;
        *(u32 *)b = t;
        if (a == b) return;
        b -= 4;
        if (a == b) return;
    }
}
PCREG(5edc80, swapInward_5edc80);

// 0x5edcb0: __fastcall (ECX = x, EDX = end, three stack arguments; ret 0xc). A rotate: returns s1 when x == end, returns x when
// s1 == end; otherwise, two inward swap passes (end side, then s1 side), a third pass with the x pointer, and a final call
// to 0x5edc80 (the return value is edi = s1, or x for the last path). GUESS.
static u32 FASTCALL rotate_5edcb0(u32 x, u32 end, u32 s1, u32 s2, u32 s3) {
    (void)s2;
    (void)s3;
    if (x == end) return s1;
    u32 edi = s1;
    if (edi == end) return x;
    u32 b = x;
    u32 e = end;
    for (;;) {                       // pass 1 (5edce0): b walks up from x, e walks down from end
        e -= 4;
        if (b == e) break;
        u32 t = *(u32 *)b;
        *(u32 *)b = *(u32 *)e;
        b += 4;
        *(u32 *)e = t;
        if (b == e) break;
    }
    b = end;                         // pass 2 (5edcf6): b starts at end, e walks down from s1
    e = edi;
    for (;;) {
        e -= 4;
        if (b == e) break;
        u32 t = *(u32 *)b;
        *(u32 *)b = *(u32 *)e;
        b += 4;
        *(u32 *)e = t;
        if (b == e) break;
    }
    u32 xp = x;                      // pass 3 (5edd20): xp walks up from x, edi walks down from s1
    while (end != edi) {
        u32 t = *(u32 *)xp;
        edi -= 4;
        *(u32 *)xp = *(u32 *)edi;
        xp += 4;
        *(u32 *)edi = t;
        if (xp == end) {
            swapInward_5edc80(end, edi, s1);
            return edi;
        }
    }
    if (xp == end) {                 // 5edd4f: xp == end
        swapInward_5edc80(end, edi, s1);
        return edi;
    }
    swapInward_5edc80(xp, end, s1);  // 5edd69
    return xp;
}
PCREG(5edcb0, rotate_5edcb0);
