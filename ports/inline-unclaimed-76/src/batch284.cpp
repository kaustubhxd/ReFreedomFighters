// batch284.cpp - unclaimed area 76 (docs/20-unclaimed-76.md), slice 15: 0x5ed2b0, both branches read in full.
#include "ff.h"

// 0x5ed2b0(this, a, b, c) (ret 0xc).
// c != -1: el = [[this+0xcb] + 4*c] (c is an index). If the sign-extended words el[0], el[1] are not a, b, set
// [this+0xa6] = 1. Then el[0] = low word of a, el[1] = low word of b. Return.
// c == -1: it = [this+0xcb]; return if it == [this+0xcf]. Else for each slot pointer it (until it == [this+0xcf]): the same
// check and stores on el = *it, then it += 4. GUESS: sets a (key, value) pair in one or every entry of a table.
static void THISCALL setPairs_5ed2b0(u8 *self, u32 a, u32 b, u32 c) {
    if (c != 0xffffffffu) {
        u8 *el = *(u8 **)(*(u32 *)(self + 0xcb) + 4 * c);
        if ((s32)(s16)*(u16 *)(el + 0) != (s32)a || (s32)(s16)*(u16 *)(el + 2) != (s32)b) {
            *(u8 *)(self + 0xa6) = 1;
        }
        *(u16 *)(el + 0) = (u16)a;
        *(u16 *)(el + 2) = (u16)b;
        return;
    }
    u32 it = *(u32 *)(self + 0xcb);
    if (it == *(u32 *)(self + 0xcf)) return;
    do {
        u8 *el = *(u8 **)it;
        if ((s32)(s16)*(u16 *)(el + 0) != (s32)a || (s32)(s16)*(u16 *)(el + 2) != (s32)b) {
            *(u8 *)(self + 0xa6) = 1;
        }
        *(u16 *)(el + 0) = (u16)a;
        *(u16 *)(el + 2) = (u16)b;
        it += 4;
    } while (it != *(u32 *)(self + 0xcf));
}
PCREG(5ed2b0, setPairs_5ed2b0);
