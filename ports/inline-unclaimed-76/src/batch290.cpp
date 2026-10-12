// batch290.cpp - unclaimed area 76 (docs/20-unclaimed-76.md), residue-15 leaf 0x464e70 (two stack arguments, ret 8).
#include "ff.h"

typedef u32 (__attribute__((thiscall)) *Slot1_464e70)(u8 *, u32);

// Release one pending handle: obj = engine+0x9b ->vtbl[0x58](key); if null return; obj->vtbl[0x210](1); clear the field.
static void release_464e70(u8 *self, u32 field_off, u32 key) {
    u8 *eng9b = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *obj = (u8 *)((Slot1_464e70)(*(void ***)eng9b)[0x58 / 4])(eng9b, key);
    if (obj == 0) return;
    ((Slot1_464e70)(*(void ***)obj)[0x210 / 4])(obj, 1u);
    *(u32 *)(self + field_off) = 0u;
}

// 0x464e70(this, unused, flags) (ret 8). X = [this+0x12a], Y = [this+0x12e], Z = [this+0x132]. If all three are zero, return.
// Else, by the flag byte: bit 0x20 releases X when set (return if X is zero); otherwise bit 0x10 releases Y; otherwise Z is
// released (return if zero). A release fetches obj = engine vtbl[0x58](key), calls obj.vtbl[0x210](1) and clears the field.
// GUESS: a three-slot handle release.
static void THISCALL releaseSlots_464e70(u8 *self, u32 unused, u32 flags) {
    (void)unused;
    u32 x = *(u32 *)(self + 0x12a);
    u32 y = *(u32 *)(self + 0x12e);
    u32 z = *(u32 *)(self + 0x132);
    if (x == 0u && y == 0u && z == 0u) return;
    u8 f = (u8)flags;
    if (f & 0x20) {
        if (x == 0u) return;
        release_464e70(self, 0x12a, x);
        return;
    }
    if (f & 0x10) {
        if (y == 0u) return;
        release_464e70(self, 0x12e, y);
        return;
    }
    if (z == 0u) return;
    release_464e70(self, 0x132, z);
}
PCREG(464e70, releaseSlots_464e70);
