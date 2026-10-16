// batch367.cpp - area 76 (docs/20-unclaimed-76.md, label D): 0x55b260 (thiscall, one stack argument a, ret 4; GUESS).
// elem = 0x5003d0([a+4], 0); holder = [this+0x1c]; 0x5a20d0(holder; [elem], 0) (thiscall, two words, ret 8; hooked in the fixture);
// 0x5a0da0(holder) (thiscall, no arguments; hooked in the fixture).
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 index);
extern "C" void THISCALL ext_5a20d0(u8 *self, u32 value, u32 zero);
extern "C" void THISCALL ext_5a0da0(u8 *self);

static void THISCALL f55b260(u8 *selfp, u32 a) {
    u32 self = (u32)selfp;
    u32 elem = ext_5003d0((u8 *)*(u32 *)(a + 4u), 0u);
    u32 holder = *(u32 *)(self + 0x1cu);
    ext_5a20d0((u8 *)holder, *(u32 *)elem, 0u);
    ext_5a0da0((u8 *)holder);
}
PCREG(55b260, f55b260);
