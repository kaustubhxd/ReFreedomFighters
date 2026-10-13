// batch335.cpp - decomp area 64 (docs/20-unclaimed-64.md), slice floor(addr/16) mod 20 == 3.
#include "ff.h"

// Exe compare 0x59be70 (thiscall, ecx = object, no stack words). Compares the string at object[+0x48] with the
// constant at 0x6a7808 and returns al = 0 when they are equal. Runs as original code.
extern "C" u32 THISCALL ext_59be70(u8 *obj);

// 0x561330: thiscall (ecx = self, one stack pointer buf, ret 4). A = self[+0x94].
// Return if A[+0x103c] != 0 or self[+0x87] == 0. Else take = A[+0x103e] != 0, or (al = ext 0x59be70(A), al == 0, or
// (A[+0x103f] != 0 and A[+0x1043] != 0)). If take: ec = the zero terminator of buf; write the dword at 0x67aef4 and the
// word at 0x67aef8 at ec (a six-byte suffix). GUESS: an append of a fixed tag to a string, gated by object flags.
static void THISCALL appendTag_561330(u8 *self, u8 *buf) {
    u8 *A = *(u8 **)(self + 0x94);
    if (*(u8 *)(A + 0x103c) != 0 || *(u8 *)(self + 0x87) == 0) return;
    bool take;
    if (*(u8 *)(A + 0x103e) != 0) {
        take = true;
    } else {
        u32 al = ext_59be70(A) & 0xffu;
        if (al == 0) {
            take = true;
        } else {
            take = *(u8 *)(A + 0x103f) != 0 && *(u8 *)(A + 0x1043) != 0;
        }
    }
    if (!take) return;
    u8 *ec = buf;
    while (*ec != 0) ec++;
    *(u32 *)ec = G(u32, 0x67aef4);
    *(u16 *)(ec + 4) = G(u16, 0x67aef8);
}
PCREG(561330, appendTag_561330);
