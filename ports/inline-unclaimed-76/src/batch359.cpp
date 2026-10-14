// batch359.cpp - area 76 (docs/20-unclaimed-76.md, label D): 0x55c770 (thiscall, one stack argument a, ret 4; GUESS).
// elem = 0x5003d0([a+4], index 0) (exe accessor, thiscall with one argument); [[this+0x1c] + 0x945] = [elem].
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 index);

static void THISCALL f55c770(u8 *selfp, u32 a) {
    u32 self = (u32)selfp;
    u32 elem = ext_5003d0((u8 *)*(u32 *)(a + 4u), 0u);
    *(u32 *)(*(u32 *)(self + 0x1cu) + 0x945u) = *(u32 *)elem;
}
PCREG(55c770, f55c770);
