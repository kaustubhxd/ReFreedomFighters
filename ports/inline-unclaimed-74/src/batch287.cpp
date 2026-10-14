// batch287.cpp - unclaimed area 74 (docs/20-unclaimed-74.md), slice 13 leaves from the full list.
#include "ff.h"

// 0x4cc690(this): s = *this (a NUL-terminated string). Every byte from 'A' to 'Z' (c - 0x41 <= 0x19 as a byte) becomes c + 0x20.
// Plain ret. GUESS: lower-case a string in place.
static void THISCALL lowerInPlace_4cc690(u8 *self) {
    char *s = *(char **)self;
    u32 n = 0;
    while (s[n] != 0) n++;
    for (u32 i = 0; i < n; i++) {
        u8 c = (u8)s[i];
        if ((u8)(c - 0x41) <= 0x19) s[i] = (char)(c + 0x20);
    }
}
PCREG(4cc690, lowerInPlace_4cc690);

// 0x5ed3d0(this, a, b, c) (ret 0xc). c != -1: el = arr[c] (c is an index). If el's dword +8 is not a, or its sign-extended
// word +0xe is not b, set [this+0xa6] = 1. Then el.dword+8 = a, el.word+0xe = low word of b. c == -1: the same check and
// store on every slot pointer in [this+0xcb]..[this+0xcf]. GUESS.
static void THISCALL setTagged_5ed3d0(u8 *self, u32 a, u32 b, u32 c) {
    if (c != 0xffffffffu) {
        u8 *el = *(u8 **)(*(u32 *)(self + 0xcb) + 4 * c);
        if (*(u32 *)(el + 8) != a || (s32)(s16)*(u16 *)(el + 0xe) != (s32)b) *(u8 *)(self + 0xa6) = 1;
        *(u32 *)(el + 8) = a;
        *(u16 *)(el + 0xe) = (u16)b;
        return;
    }
    u32 it = *(u32 *)(self + 0xcb);
    if (it == *(u32 *)(self + 0xcf)) return;
    do {
        u8 *el = *(u8 **)it;
        if (*(u32 *)(el + 8) != a || (s32)(s16)*(u16 *)(el + 0xe) != (s32)b) *(u8 *)(self + 0xa6) = 1;
        *(u32 *)(el + 8) = a;
        *(u16 *)(el + 0xe) = (u16)b;
        it += 4;
    } while (it != *(u32 *)(self + 0xcf));
}
PCREG(5ed3d0, setTagged_5ed3d0);
