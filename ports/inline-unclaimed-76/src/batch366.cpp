// batch366.cpp - area 76 (docs/20-unclaimed-76.md, label D): 0x5e1160 (thiscall, two stack arguments, ret 8, returns this; GUESS).
// 0x5e0e10(this, a1, a2) (exe base constructor, thiscall, ret 8; runs as exe code); [this] = 0x6b788c; byte [this+0x54c] = 0; returns this.
#include "ff.h"

extern "C" void THISCALL ext_5e0e10(u8 *self, u32 a1, u32 a2);

static u8 *THISCALL f5e1160(u8 *selfp, u32 a1, u32 a2) {
    u32 self = (u32)selfp;
    ext_5e0e10(selfp, a1, a2);
    *(u32 *)self = 0x6b788cu;
    *(u8 *)(self + 0x54cu) = 0u;
    return selfp;
}
PCREG(5e1160, f5e1160);
