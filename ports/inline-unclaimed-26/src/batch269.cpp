// batch269.cpp - unclaimed area 26 (docs/20-unclaimed-26.md), residue-05 list.
#include "ff.h"

typedef u32 (__attribute__((thiscall)) *Slot1_4afb50)(u8 *, u32);
typedef u32 (__attribute__((thiscall)) *Slot3_4afb50)(u8 *, u32, u32, u32);

// CCheckInside-style message send. 0x4afb50(this, a): o = engine+0x9b; t = o.vtbl[0x58](this+0x4c); if t is null, return.
// ebx = o.vtbl[0x4c](this+0x44). If this+0x56 is set and t.vtbl[0x1e0](0x800001a) is true, and t+0x18 is not null:
// loop with local: t2.vtbl[0x4c](&local); x = t2.vtbl[0x5c](&local); while local != 0 { p = this+0x44;
// p.vtbl[0x12c](x, a, this+0x57 ? ebx : x); x = (t+0x18).vtbl[0x5c](&local) }. Otherwise, tail: if this+0x57 is zero,
// ebx = this+0x48; this+0x44.vtbl[0x12c](this+0x4c, a, ebx), ret 4. GUESS.
static void THISCALL sendMessage_4afb50(u8 *self, u32 a) {
    u8 *o = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *t = (u8 *)((Slot1_4afb50)(*(void ***)o)[0x58 / 4])(o, *(u32 *)(self + 0x4c));
    if (t == 0) return;
    u32 ebx = ((Slot1_4afb50)(*(void ***)o)[0x4c / 4])(o, *(u32 *)(self + 0x44));
    if (*(u8 *)(self + 0x56) != 0) {
        u32 ok = ((Slot1_4afb50)(*(void ***)t)[0x1e0 / 4])(t, 0x800001au) & 0xffu;
        if (ok != 0) {
            u8 *c = *(u8 **)(t + 0x18);
            if (c == 0) return;
            u32 local = 0;
            ((Slot1_4afb50)(*(void ***)c)[0x4c / 4])(c, (u32)&local);
            u8 *c2 = *(u8 **)(t + 0x18);
            u32 x = ((Slot1_4afb50)(*(void ***)c2)[0x5c / 4])(c2, (u32)&local);
            if (local == 0) return;
            do {
                u32 val = (*(u8 *)(self + 0x57) != 0) ? ebx : x;
                u8 *p = *(u8 **)(self + 0x44);
                ((Slot3_4afb50)(*(void ***)p)[0x12c / 4])(p, x, a, val);
                u8 *c3 = *(u8 **)(t + 0x18);
                x = ((Slot1_4afb50)(*(void ***)c3)[0x5c / 4])(c3, (u32)&local);
            } while (local != 0);
            return;
        }
    }
    if (*(u8 *)(self + 0x57) == 0) ebx = *(u32 *)(self + 0x48);
    u8 *p = *(u8 **)(self + 0x44);
    ((Slot3_4afb50)(*(void ***)p)[0x12c / 4])(p, *(u32 *)(self + 0x4c), a, ebx);
}
PCREG(4afb50, sendMessage_4afb50);
