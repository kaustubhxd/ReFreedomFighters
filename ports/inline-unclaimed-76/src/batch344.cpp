// batch344.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): 0x60f1a0 (thiscall, two arguments a, b, ret 8; GUESS).
// If byte [engine+0x63] == 0: edi = a, ebx = b; else edi = [engine+0x6f], ebx = [engine+0x73] (engine = [0x70039c]).
// If byte [this+0x33] != 0: [this+0x137b] = edi, [this+0x137f] = ebx, call this.vtbl[0x50]() (thiscall, no arguments).
// Return this.vtbl[0xe0](this, edi, ebx) (thiscall, two arguments; the callee pops them).
#include "ff.h"

typedef u32(THISCALL * slot50_t)(u32 self);
typedef u32(THISCALL * slotE0_t)(u32 self, u32 p, u32 q);

static u32 THISCALL pick_60f1a0(u8 *self, u32 a, u32 b) {
    u32 eng = G(u32, 0x70039cu);
    u32 edi, ebx;
    if (*(u8 *)(eng + 0x63u) == 0u) {
        edi = a;
        ebx = b;
    } else {
        edi = *(u32 *)(eng + 0x6fu);
        ebx = *(u32 *)(eng + 0x73u);
    }
    if (*(u8 *)(self + 0x33u) != 0u) {
        *(u32 *)(self + 0x137bu) = edi;
        *(u32 *)(self + 0x137fu) = ebx;
        u32 vt = *(u32 *)self;
        ((slot50_t)*(u32 *)(vt + 0x50u))((u32)self);
    }
    u32 vt2 = *(u32 *)self;
    return ((slotE0_t)*(u32 *)(vt2 + 0xe0u))((u32)self, edi, ebx);
}
PCREG(60f1a0, pick_60f1a0);
