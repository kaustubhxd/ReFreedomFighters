// batch333.cpp - decomp area 64 (docs/20-unclaimed-64.md), slice floor(addr/16) mod 20 == 3.
#include "ff.h"

// Exe table lookup 0x5003d0 (thiscall, one stack word = index, ret 4). See batch326.cpp.
extern "C" u32 THISCALL ext_5003d0(u8 *table, u32 index);

// 0x55bcf0: thiscall (ecx = self, unused; one stack pointer p, ret 4).
// e0 = lookup(T, 0), e1 = lookup(T, 1) with T = p[+4]; v1 = *e1; the flags word is sub[+0x423], where
// sub = global[0x7003b8][+0x2c15]. If *e0 != 0, set bit (v1 mod 32) of the flags word; else clear it. The bit ops are
// the register forms of bts and btr, which take the bit offset mod 32. GUESS: a per-object bit set by a table entry.
static void THISCALL setFlagBit_55bcf0(u8 *self, u8 *p) {
    (void)self;
    u8 *T = *(u8 **)(p + 0x4);
    u32 e0 = ext_5003d0(T, 0u);
    u32 flagOn = *(u32 *)e0;
    u32 e1 = ext_5003d0(T, 1u);
    u32 v1 = *(u32 *)e1;
    u8 *g = G(u8 *, 0x7003b8);
    u8 *sub = *(u8 **)(g + 0x2c15);
    u32 *flags = (u32 *)(sub + 0x423);
    u32 bit = 1u << (v1 & 31u);
    if (flagOn != 0) {
        *flags = *flags | bit;
    } else {
        *flags = *flags & ~bit;
    }
}
PCREG(55bcf0, setFlagBit_55bcf0);
