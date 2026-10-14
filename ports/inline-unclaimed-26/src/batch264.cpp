// batch264.cpp - unclaimed area 26 (docs/20-unclaimed-26.md), slice floor(addr/16) mod 20 == 5.
#include "ff.h"

typedef u32 (__attribute__((thiscall)) *Slot0_4a1190)(u8 *);
typedef u32 (__attribute__((thiscall)) *Slot2_4a1190)(u8 *, u32, u32);
typedef u32 (__attribute__((thiscall)) *Slot4_4a1190)(u8 *, u32, u32, u32, u32);

// 0x4a1190: o = engine+0x9b; c = o.vtbl[0x138](o); v = o.vtbl[0x4c]([this+0x44], 4); c.vtbl[0x60](c, v) with the
// argument 0x68f75c first; this+0x8b0 = low word of o.vtbl[0x114](o, 0x68f774, 0, 0x68f6b4, 0x220);
// this+0x8b2 = low word of o.vtbl[0x114](o, 0x68f788, 0, 0x68f6b4, 0x221); then nine dwords are cleared. GUESS.
static void THISCALL setup_4a1190(u8 *self) {
    u8 *o = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *c = (u8 *)((Slot0_4a1190)(*(void ***)o)[0x138 / 4])(o);
    u32 v = ((Slot2_4a1190)(*(void ***)o)[0x4c / 4])(o, *(u32 *)(self + 0x44), 4u);
    ((Slot2_4a1190)(*(void ***)c)[0x60 / 4])(c, 0x68f75cu, v);
    *(u16 *)(self + 0x8b0) = (u16)((Slot4_4a1190)(*(void ***)o)[0x114 / 4])(o, 0x68f774u, 0u, 0x68f6b4u, 0x220u);
    *(u16 *)(self + 0x8b2) = (u16)((Slot4_4a1190)(*(void ***)o)[0x114 / 4])(o, 0x68f788u, 0u, 0x68f6b4u, 0x221u);
    *(u32 *)(self + 0x5c) = 0;
    *(u32 *)(self + 0x4c) = 0;
    *(u32 *)(self + 0x60) = 0;
    *(u32 *)(self + 0x50) = 0;
    *(u32 *)(self + 0x64) = 0;
    *(u32 *)(self + 0x54) = 0;
    *(u32 *)(self + 0x68) = 0;
    *(u32 *)(self + 0x58) = 0;
    *(u32 *)(self + 0x48) = 0;
}
PCREG(4a1190, setup_4a1190);
