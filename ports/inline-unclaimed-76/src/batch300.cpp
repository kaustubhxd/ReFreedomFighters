// batch300.cpp - unclaimed area 76 (docs/20-unclaimed-76.md), residue 15: 0x4ce9b0 (plain ret; ECX = this).
#include "ff.h"

typedef u32 (__attribute__((thiscall)) *Slot2_4ce9b0)(u8 *, u32, u32);
typedef u32 (__attribute__((thiscall)) *Slot0_4ce9b0)(u8 *);
typedef void (__attribute__((thiscall)) *SlotOut_4ce9b0)(u8 *, u32 *);
typedef u32 (__attribute__((thiscall)) *SlotGet_4ce9b0)(u8 *, u32 *);
typedef void (__attribute__((cdecl)) *Log4_4ce9b0)(u8 *, u32, u32, u32);
typedef void (__attribute__((cdecl)) *Log3_4ce9b0)(u8 *, u32, u32);

// 0x4ce9b0(this) (plain ret). lg = [0x700390]: obj = lg.vtbl[0x20](0x695b7c, 0x4c0); r = this.vtbl[0x14](); obj.vtbl[0x2c]
// (cdecl): (obj, 0x695c8c, [this+0x14], r). Then local = 0; this.vtbl[0x4c](&local); e = this.vtbl[0x5c](&local); while local
// is non-zero: obj2 = lg.vtbl[0x20](0x695b7c, 0x4c4); obj2.vtbl[0x2c] (cdecl): (obj2, 0x695ca4, e); e = this.vtbl[0x5c](&local).
// GUESS: a logged walk over this's list.
static void THISCALL logWalk_4ce9b0(u8 *self) {
    u8 *lg = G(u8 *, 0x700390);
    u8 *obj = (u8 *)((Slot2_4ce9b0)(*(void ***)lg)[0x20 / 4])(lg, 0x695b7cu, 0x4c0u);
    u32 r = ((Slot0_4ce9b0)(*(void ***)self)[0x14 / 4])(self);
    ((Log4_4ce9b0)(*(void ***)obj)[0x2c / 4])(obj, 0x695c8cu, *(u32 *)(self + 0x14), r);
    u32 local = 0u;
    ((SlotOut_4ce9b0)(*(void ***)self)[0x4c / 4])(self, &local);
    u32 e = ((SlotGet_4ce9b0)(*(void ***)self)[0x5c / 4])(self, &local);
    while (local != 0u) {
        u8 *lg2 = G(u8 *, 0x700390);
        u8 *obj2 = (u8 *)((Slot2_4ce9b0)(*(void ***)lg2)[0x20 / 4])(lg2, 0x695b7cu, 0x4c4u);
        ((Log3_4ce9b0)(*(void ***)obj2)[0x2c / 4])(obj2, 0x695ca4u, e);
        e = ((SlotGet_4ce9b0)(*(void ***)self)[0x5c / 4])(self, &local);
    }
}
PCREG(4ce9b0, logWalk_4ce9b0);
