// batch193.cpp - unclaimed area 19 (docs/20-unclaimed-19.md), slice floor(addr/16) mod 20 == 18.
// 0x45d1a0 only. 0x51be20 is held out (see the spec note).
#include "ff.h"

typedef void (__attribute__((thiscall)) *Slot0Fn_45d1a0)(u8 *);

// 0x45d1a0: flag (stack byte, ret 4). If flag != 0: when this+0x10 is null, calls this->vtbl[0x40](this) first;
// then sets bit 0 of the dword at ([this+0x10]+0x18). Else: clears bit 0 at the same place when this+0x10 is non-null.
// GUESS: a flag set and clear on a child record.
static void THISCALL setFlag_45d1a0(u8 *self, u32 flag) {
    if ((u8)flag != 0) {
        if (*(u32 *)(self + 0x10) == 0u) {
            void **vt = *(void ***)self;
            ((Slot0Fn_45d1a0)vt[0x40 / 4])(self);
        }
        u8 *o = *(u8 **)(self + 0x10);
        *(u32 *)(o + 0x18) |= 1u;
    } else {
        u8 *o = *(u8 **)(self + 0x10);
        if (o) *(u32 *)(o + 0x18) &= ~1u;
    }
}
PCREG(45d1a0, setFlag_45d1a0);
