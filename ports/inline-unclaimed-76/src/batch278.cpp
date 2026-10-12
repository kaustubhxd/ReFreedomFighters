// batch278.cpp - unclaimed area 76 (docs/20-unclaimed-76.md), slice 15 small leaves from the full list.
#include "ff.h"

typedef u32 (__attribute__((thiscall)) *Slot2_45fab0)(u8 *, u32, u32);
typedef u32 (__attribute__((thiscall)) *Slot4_45fab0)(u8 *, u32, u32, u32, u32);

// 0x45fab0: three stack arguments (a, b, c; ret 0xc). a.vtbl[0x168](b, c) (c is pushed before the call, so two arguments); then a.vtbl[0x124](a, 0x20, c, (u16)b, this).
// GUESS: a two-step call on a child with the word of b.
static void THISCALL twoStep_45fab0(u8 *self, u32 a, u32 b, u32 c) {
    u8 *A = (u8 *)a;
    ((Slot2_45fab0)(*(void ***)A)[0x168 / 4])(A, b, c);
    ((Slot4_45fab0)(*(void ***)A)[0x124 / 4])(A, 0x20u, c, (u32)(u16)b, (u32)self);
}
PCREG(45fab0, twoStep_45fab0);
