// batch368.cpp - area 76 (docs/20-unclaimed-76.md, label D): three constructors, thiscall, two stack arguments, ret 8, return this.
// Each calls 0x5e0e10(this, a1, a2) (base constructor; hooked in the fixture) and then stores its vtable and fields:
//   0x5e11c0: [this] = 0x6b7964; byte [+0x54c] = 0; dword [+0x55c] = 0.
//   0x5e1200: [this] = 0x6b77b4; byte [+0x550] = 0; dword [+0x565] = 0.
//   0x5e10a0: [this] = 0x6b760c; dword [+0x54c] = 0; byte [+0x550] = 0; byte [+0x559] = 1; dword [+0x593], [+0x597], [+0x59b], [+0x59f] = 0.
#include "ff.h"

extern "C" void THISCALL ext_5e0e10(u8 *self, u32 a1, u32 a2);

static u8 *THISCALL f5e11c0(u8 *selfp, u32 a1, u32 a2) {
    u32 self = (u32)selfp;
    ext_5e0e10(selfp, a1, a2);
    *(u32 *)self = 0x6b7964u;
    *(u8 *)(self + 0x54cu) = 0u;
    *(u32 *)(self + 0x55cu) = 0u;
    return selfp;
}
PCREG(5e11c0, f5e11c0);

static u8 *THISCALL f5e1200(u8 *selfp, u32 a1, u32 a2) {
    u32 self = (u32)selfp;
    ext_5e0e10(selfp, a1, a2);
    *(u32 *)self = 0x6b77b4u;
    *(u8 *)(self + 0x550u) = 0u;
    *(u32 *)(self + 0x565u) = 0u;
    return selfp;
}
PCREG(5e1200, f5e1200);

static u8 *THISCALL f5e10a0(u8 *selfp, u32 a1, u32 a2) {
    u32 self = (u32)selfp;
    ext_5e0e10(selfp, a1, a2);
    *(u32 *)self = 0x6b760cu;
    *(u32 *)(self + 0x54cu) = 0u;
    *(u8 *)(self + 0x550u) = 0u;
    *(u8 *)(self + 0x559u) = 1u;
    *(u32 *)(self + 0x593u) = 0u;
    *(u32 *)(self + 0x597u) = 0u;
    *(u32 *)(self + 0x59bu) = 0u;
    *(u32 *)(self + 0x59fu) = 0u;
    return selfp;
}
PCREG(5e10a0, f5e10a0);
