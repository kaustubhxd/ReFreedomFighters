// batch316.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): 0x602ff0 (thiscall, ret 4, GUESS). SEH-tagged: the SEH frame
// (fs:[0], 0x665c86 handler) and the stack cookie (0x6f5630) are NOT reproduced; SEH frame not reproduced.
// L is a local string range: the ctor 0x42b390(L, a, &flag) (thiscall, ret 8) fills it from a; the tree search 0x5fb980(this+1, &a, &L)
// (thiscall, ret 8) may replace a; if L.begin and the size L.end - L.begin are both nonzero, 0x54f870 frees L.begin (thiscall, ret 8).
// Returns 0 when a == [this+1]; otherwise [a+0x19] (dword). Local layout: L+0 begin, L+8 end, L+0xc flag byte.
#include "ff.h"

extern "C" void THISCALL ext_42b390(u8 *self, u32 a, u32 flagPtr);
extern "C" void THISCALL ext_5fb980(u8 *self, u32 pa, u32 pb);
extern "C" void THISCALL ext_54f870(u8 *self, u32 a, u32 b);

static u32 THISCALL f602ff0_602ff0(u8 *self, u32 a) {
    u32 L[4];
    u32 aa = a;
    u8 *Lp = (u8 *)L;
    ext_42b390(Lp, aa, (u32)(Lp + 0xcu));
    ext_5fb980(self + 1u, (u32)&aa, (u32)Lp);
    u32 begin = *(u32 *)Lp;
    u32 size = *(u32 *)(Lp + 8u) - begin;
    if (begin != 0u && size != 0u) ext_54f870(Lp, begin, size);
    if (aa == *(u32 *)(self + 1u)) return 0u;
    return *(u32 *)(aa + 0x19u);
}
PCREG(602ff0, f602ff0_602ff0);
