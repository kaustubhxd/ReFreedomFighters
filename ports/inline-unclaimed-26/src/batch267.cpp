// batch267.cpp - unclaimed area 26 (docs/20-unclaimed-26.md), residue-05 list.
#include "ff.h"

// Exe find-or-add 0x5be690 (batch 265's function, run as original code; thiscall, one argument).
extern "C" u32 THISCALL ext_5be690(u8 *self, u32 key);

// 0x5be190: if the word arg equals the word at this+0x914: idx = ext_5be690(this, key); flag = byte at this+5*idx+0x71c.
// If flag == 0xff, return 0. Else byte [this+0x3a*(s8)flag+0x54] is decremented; if byte [this+0x3a*(s8)flag+0x85] is
// zero: set flag to 0xff, bump the dword at +0x91e. Otherwise store idx at this+[+0x92a]+0x92e and bump [+0x92a].
// If the word equals the word at this+0x918: store key at this+0x48. Always returns 0 (ret 8). GUESS.
static u32 THISCALL flagRecord_5be190(u8 *self, u32 w, u32 key) {
    u16 word = (u16)w;
    if (word == *(u16 *)(self + 0x914)) {
        u32 idx = ext_5be690(self, key);
        u8 flag = *(u8 *)(self + idx * 5u + 0x71c);
        if (flag == 0xffu) return 0u;
        s32 base = (s32)(s8)flag * 0x3a;
        *(u8 *)(self + (u32)base + 0x54) -= 1u;
        if (*(u8 *)(self + (u32)base + 0x85) == 0u) {
            *(u8 *)(self + idx * 5u + 0x71c) = 0xffu;
            *(u32 *)(self + 0x91e) += 1u;
        } else {
            u32 n = *(u32 *)(self + 0x92a);
            *(u8 *)(self + n + 0x92e) = (u8)idx;
            *(u32 *)(self + 0x92a) = n + 1u;
        }
        return 0u;
    }
    if (word == *(u16 *)(self + 0x918)) {
        *(u32 *)(self + 0x48) = key;
    }
    return 0u;
}
PCREG(5be190, flagRecord_5be190);
