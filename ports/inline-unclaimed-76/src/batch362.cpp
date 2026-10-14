// batch362.cpp - area 76 (docs/20-unclaimed-76.md, label D): 0x55c8b0 (thiscall, one stack argument, ret 4; returns the callee's eax;
// GUESS). Same shape as 0x55c7a0 with the slot 0x6a0. elem = 0x5003d0([a+4], 0); w = word [elem]; tail: [this+0x1c].vtbl[0x6a0](holder, w).
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 index);

static u32 THISCALL f55c8b0(u8 *selfp, u32 a) {
    u32 self = (u32)selfp;
    u32 elem = ext_5003d0((u8 *)*(u32 *)(a + 4u), 0u);
    u32 w = (u32)*(u16 *)elem;
    u32 holder = *(u32 *)(self + 0x1cu);
    u32 vt = *(u32 *)holder;
    return ((u32(THISCALL *)(u32, u32))(*(u32 *)(vt + 0x6a0u)))(holder, w);
}
PCREG(55c8b0, f55c8b0);
