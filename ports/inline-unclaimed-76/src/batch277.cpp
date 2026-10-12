// batch277.cpp - unclaimed area 76 (docs/20-unclaimed-76.md), slice 15 small leaves from the full list.
#include "ff.h"

typedef u32 (__attribute__((thiscall)) *Slot0_4dc970)(u8 *);

// 0x5edb70: five stack arguments (a, b, c, d used; the fifth at [ebp+0x18] is never read; ret 0x14). Unless this+0xe7/+0xeb/+0xef equal a/b/c and this+0xf3 equals d,
// clears this+0xd7 and this+0xdb, stores a, b, c, d at +0xe7, +0xeb, +0xef, +0xf3 and sets the byte at +0xa6 to 1. GUESS.
static void THISCALL setKey_5edb70(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 unusedFifth) {
    if (*(u32 *)(self + 0xe7) == a && *(u32 *)(self + 0xeb) == b && *(u32 *)(self + 0xef) == c) {
        if (*(u32 *)(self + 0xf3) == d) return;
    }
    *(u32 *)(self + 0xd7) = 0u;
    *(u32 *)(self + 0xdb) = 0u;
    *(u32 *)(self + 0xe7) = a;
    *(u32 *)(self + 0xeb) = b;
    *(u32 *)(self + 0xef) = c;
    *(u32 *)(self + 0xf3) = d;
    *(u8 *)(self + 0xa6) = 1;
}
PCREG(5edb70, setKey_5edb70);

// 0x4dc970: if a is zero, stores 0 as a word at this+0x5c. Else x = (engine+0x9b)->[+8]->vtbl[0x4c](); k = a - x; stores
// a word at this+0x5c: the signed division of k by 7 (magic 0x92492493, sar 6, plus one, as the exe computes it). GUESS.
static void THISCALL divSeven_4dc970(u8 *self, u32 a) {
    if (a == 0u) {
        *(u16 *)(self + 0x5c) = 0;
        return;
    }
    u8 *o = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *child = *(u8 **)(o + 8);
    u32 x = ((Slot0_4dc970)(*(void ***)child)[0x4c / 4])(child);
    s32 k = (s32)(a - x);
    long long p = (long long)(s32)0x92492493u * (long long)k;
    s32 hi = (s32)(p >> 32);
    hi += k;
    hi >>= 6;
    s32 r = hi + (s32)((u32)hi >> 31) + 1;
    *(u16 *)(self + 0x5c) = (u16)r;
}
PCREG(4dc970, divSeven_4dc970);
