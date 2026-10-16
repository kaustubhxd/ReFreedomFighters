// batch365.cpp - area 76 (docs/20-unclaimed-76.md, label D): 0x5f0340 (thiscall, one stack argument a, ret 4, returns this; GUESS).
// [this] = 0x6b823c; [this+0xc] = a.vtbl[0x14](0x6b1e6c) (thiscall, one word); returns this.
#include "ff.h"

static u8 *THISCALL f5f0340(u8 *selfp, u32 a) {
    u32 self = (u32)selfp;
    *(u32 *)self = 0x6b823cu;
    u32 vt = *(u32 *)a;
    u32 r = ((u32(THISCALL *)(u32, u32))(*(u32 *)(vt + 0x14u)))(a, 0x6b1e6cu);
    *(u32 *)(self + 0xcu) = r;
    return selfp;
}
PCREG(5f0340, f5f0340);
