// batch338.cpp - decomp area 64 (docs/20-unclaimed-64.md), slice floor(addr/16) mod 20 == 3.
#include "ff.h"

// Exe helpers, run as original code. 0x5af2a0: thiscall (ecx = this+0x18), two stack words (index k, then 0).
// 0x5aef10: thiscall (ecx = this+0x2c), no stack words; the exe reaches it by a tail jump.
extern "C" u32 THISCALL ext_5af2a0(u8 *self, u32 k, u32 zero);
extern "C" u32 THISCALL ext_5aef10(u8 *self);

// 0x5b02f0: thiscall (ecx = self, no stack words, plain ret). Calls 0x5af2a0(self+0x18, k, 0) for k = 0xd, 0xc, 0xe,
// 0x10, 0xf in that order; zeroes self[+8], [+0xc], [+0x10], [+0x14]; then tail-jumps to 0x5aef10 with ecx = self+0x2c.
// The port calls that helper and returns its eax. GUESS: a table initialiser for five slots, then a sub-init.
static u32 THISCALL initSlots_5b02f0(u8 *self) {
    ext_5af2a0(self + 0x18, 0xdu, 0u);
    ext_5af2a0(self + 0x18, 0xcu, 0u);
    ext_5af2a0(self + 0x18, 0xeu, 0u);
    ext_5af2a0(self + 0x18, 0x10u, 0u);
    ext_5af2a0(self + 0x18, 0xfu, 0u);
    *(u32 *)(self + 0x8) = 0;
    *(u32 *)(self + 0xc) = 0;
    *(u32 *)(self + 0x10) = 0;
    *(u32 *)(self + 0x14) = 0;
    return ext_5aef10(self + 0x2c);
}
PCREG(5b02f0, initSlots_5b02f0);
