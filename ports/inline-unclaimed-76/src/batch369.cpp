// batch369.cpp - area 76 (docs/20-unclaimed-76.md, lower half of my D claims): 0x477580 (thiscall, one stack argument flags, ret 4,
// returns this; GUESS). Frees: [this+0xc] by 0x41e2c0 (cdecl free, hooked in the fixture); [this+0x10] and [this+0x14] by 0x634273(ptr, 4)
// (cdecl free wrapper, exe code); if (flags & 1): 0x634273(this, 0x18). Returns this.
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_41e2c0(u32 p);
extern "C" void __attribute__((cdecl)) ext_634273(u32 p, u32 size);

static u8 *THISCALL f477580(u8 *selfp, u32 flags) {
    u32 self = (u32)selfp;
    u32 p = *(u32 *)(self + 0xcu);
    if (p != 0u) ext_41e2c0(p);
    p = *(u32 *)(self + 0x10u);
    if (p != 0u) ext_634273(p, 4u);
    p = *(u32 *)(self + 0x14u);
    if (p != 0u) ext_634273(p, 4u);
    if ((flags & 1u) != 0u) ext_634273(self, 0x18u);
    return selfp;
}
PCREG(477580, f477580);
