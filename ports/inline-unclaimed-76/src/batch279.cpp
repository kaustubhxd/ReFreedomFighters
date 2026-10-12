// batch279.cpp - unclaimed area 76 (docs/20-unclaimed-76.md), slice 15 leaves from the full list.
#include "ff.h"

typedef u32 (__attribute__((thiscall)) *Slot0_79)(u8 *);
typedef u32 (__attribute__((thiscall)) *Slot1_79)(u8 *, u32);
typedef u32 (__attribute__((thiscall)) *Slot2_79)(u8 *, u32, u32);

// 0x4ce5f0: null this returns 0. Else vtbl[0x4c](&local); x = vtbl[0x64](&local); if x is zero return 0. Loop: if n is
// zero, return x; n--; x = vtbl[0x64](&local); if x is zero return 0, else loop. ret 4. GUESS: a counted walk that
// returns the last non-zero step.
static u32 THISCALL walkCount_4ce5f0(u8 *self, u32 n) {
    if (self == 0) return 0u;
    u32 local = 0u;
    ((Slot1_79)(*(void ***)self)[0x4c / 4])(self, (u32)&local);
    u32 x = ((Slot1_79)(*(void ***)self)[0x64 / 4])(self, (u32)&local);
    if (x == 0u) return 0u;
    for (;;) {
        if (n == 0u) return x;
        n--;
        x = ((Slot1_79)(*(void ***)self)[0x64 / 4])(self, (u32)&local);
        if (x == 0u) return 0u;
    }
}
PCREG(4ce5f0, walkCount_4ce5f0);

// 0x5ef330: two stack arguments (a, b; ret 8). If this+0xa0 is zero, returns. Else obj(+0xa9).vtbl[4](a, b),
// obj(+0xa1).vtbl[4](a, b), obj(+0xa5).vtbl[4](a, b); if this+0xb5 is set and obj(+0xb1) is not null:
// obj(+0xb1).vtbl[8]() and then obj(+0xb1).vtbl[4](a, b). GUESS.
static void THISCALL pairCalls_5ef330(u8 *self, u32 a, u32 b) {
    if (*(u8 *)(self + 0xa0) == 0) return;
    u8 *o1 = *(u8 **)(self + 0xa9);
    ((Slot2_79)(*(void ***)o1)[4 / 4])(o1, a, b);
    u8 *o2 = *(u8 **)(self + 0xa1);
    ((Slot2_79)(*(void ***)o2)[4 / 4])(o2, a, b);
    u8 *o3 = *(u8 **)(self + 0xa5);
    ((Slot2_79)(*(void ***)o3)[4 / 4])(o3, a, b);
    if (*(u8 *)(self + 0xb5) == 0) return;
    u8 *o4 = *(u8 **)(self + 0xb1);
    if (o4 == 0) return;
    ((Slot0_79)(*(void ***)o4)[8 / 4])(o4);
    u8 *o5 = *(u8 **)(self + 0xb1);
    ((Slot2_79)(*(void ***)o5)[4 / 4])(o5, a, b);
}
PCREG(5ef330, pairCalls_5ef330);
