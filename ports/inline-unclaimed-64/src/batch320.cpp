// batch320.cpp - decomp area 64 (docs/20-unclaimed-64.md), slice floor(addr/16) mod 20 == 3.
#include "ff.h"

// Virtual call on a child: slot 0xf8, thiscall with two stack words (the callee pops 8).
typedef u8(__attribute__((thiscall)) * Slot_f8_Fn)(u8 *, u32, u32);

// 0x5738f0: thiscall (ecx = self, stack word unused, stack word a, ret 8), returns true (al = 1).
// For each of the four child pointers at self[+0x18..+0x24] that is non-null:
// child->vtbl[0xf8](child, a, self[+0x28]). GUESS: a broadcast of one value to four child objects.
static u8 THISCALL broadcast_5738f0(u8 *self, u32, u32 a) {
    for (u32 i = 0; i < 4; i++) {
        u8 *child = *(u8 **)(self + 0x18 + 4 * i);
        if (child) {
            void **vt = *(void ***)child;
            ((Slot_f8_Fn)vt[0xf8 / 4])(child, a, *(u32 *)(self + 0x28));
        }
    }
    return 1;
}
PCREG(5738f0, broadcast_5738f0);
