// batch360.cpp - area 76 (docs/20-unclaimed-76.md, label D): 0x55c8e0 (thiscall, one stack argument, ret 4; GUESS).
// elem = 0x5003d0([a+4], index 0) (exe accessor); byte [[this+0x1c] + 0x929] = ([elem] != 0).
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 index);

static void THISCALL f55c8e0(u8 *selfp, u32 a) {
    u32 self = (u32)selfp;
    u32 elem = ext_5003d0((u8 *)*(u32 *)(a + 4u), 0u);
    *(u8 *)(*(u32 *)(self + 0x1cu) + 0x929u) = (*(u32 *)elem != 0u) ? 1u : 0u;
}
PCREG(55c8e0, f55c8e0);
