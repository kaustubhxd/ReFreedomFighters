// batch275.cpp - unclaimed area 76 (docs/20-unclaimed-76.md), residue-15 list.
#include "ff.h"

typedef u32 (__attribute__((thiscall)) *Slot0_46c170)(u8 *);
typedef u32 (__attribute__((thiscall)) *Slot1_46c170)(u8 *, u32);
typedef u32 (__attribute__((thiscall)) *Slot7_46c170)(u8 *, u32, u32, u32, u32, u32, u32, u32);

// 0x46c170: if count (this+0x9c) is non-zero: for i in 0..count-1: c = this.vtbl[0x334](this); stop if c is null;
// r = c.vtbl[0x1bc](dword o+0xadc, 0, 0, 0, 0, 0, 1) (seven arguments) with o = engine+0x9b; out[i] (this+0x98 array) = o.vtbl[0x4c](r).
// Plain ret. GUESS: fills a table of handles from a factory.
static void THISCALL fillHandles_46c170(u8 *self) {
    if (*(u32 *)(self + 0x9c) == 0u) return;
    u32 i = 0;
    do {
        u8 *c = (u8 *)((Slot0_46c170)(*(void ***)self)[0x334 / 4])(self);
        if (c == 0) break;
        u8 *o = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
        u32 adc = *(u32 *)(o + 0xadc);
        u32 r = ((Slot7_46c170)(*(void ***)c)[0x1bc / 4])(c, adc, 0u, 0u, 0u, 0u, 0u, 1u);
        u8 *o2 = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
        u32 v = ((Slot1_46c170)(*(void ***)o2)[0x4c / 4])(o2, r);
        *(u32 *)(*(u8 **)(self + 0x98) + 4 * i) = v;
        i++;
    } while (i < *(u32 *)(self + 0x9c));
}
PCREG(46c170, fillHandles_46c170);
