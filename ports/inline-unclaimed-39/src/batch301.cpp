// batch301.cpp - decomp area 39 (docs/20-unclaimed-39.md), slice floor(addr/16) mod 20 == 18.
#include "ff.h"

// Exe helpers, run as original code (not ported here). 0x5166e0: thiscall, one float stack argument, ret 4.
// 0x52a1a0: thiscall, no arguments, plain ret (stores three constants at +0x29, +0x2d, +0x31).
extern "C" void THISCALL ext_5166e0(u8 *self, float t);
extern "C" void THISCALL ext_52a1a0(u8 *self);

// 0x5266e0: thiscall with one float stack argument t, ret 4. Writes the constants 400.0, 1.0476 and 0.002 (as bit
// patterns) at +0x94, +0x98, +0x9c. Then, for i in [0, s32[+0x8c]): 0x5166e0(this+0xbd+i*0xde, t) and
// 0x52a1a0(this+0x7dd+i*0x163). Then, for i in [0, s32[+0x90]): 0x5166e0(this+0x435+i*0xde, t) and
// 0x52a1a0(this+0xd39+i*0x133). Loops use signed counts (jle skips a non-positive count). GUESS: a two-list
// update of child records from one time value.
static void THISCALL trackUpdate_5266e0(u8 *self, float t) {
    *(u32 *)(self + 0x94) = 0x43c80000u;
    *(u32 *)(self + 0x98) = 0x3f860a92u;
    *(u32 *)(self + 0x9c) = 0x3b03126fu;

    s32 n1 = *(s32 *)(self + 0x8c);
    for (s32 i = 0; i < n1; i++) {
        ext_5166e0(self + 0xbd + (u32)i * 0xde, t);
        ext_52a1a0(self + 0x7dd + (u32)i * 0x163);
    }

    s32 n2 = *(s32 *)(self + 0x90);
    for (s32 i = 0; i < n2; i++) {
        ext_5166e0(self + 0x435 + (u32)i * 0xde, t);
        ext_52a1a0(self + 0xd39 + (u32)i * 0x133);
    }
}
PCREG(5266e0, trackUpdate_5266e0);
