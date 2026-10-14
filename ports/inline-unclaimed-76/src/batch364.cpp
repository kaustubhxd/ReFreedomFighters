// batch364.cpp - area 76 (docs/20-unclaimed-76.md, label D): 0x5589e0 (thiscall, one stack argument a, ret 4; GUESS).
// elem = 0x5003d0([a+4], 0) (exe accessor); 0x59e650([this+0x1c], [elem]) (thiscall, one word, ret 4; exe code).
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 index);
extern "C" void THISCALL ext_59e650(u8 *self, u32 value);

static void THISCALL f5589e0(u8 *selfp, u32 a) {
    u32 self = (u32)selfp;
    u32 elem = ext_5003d0((u8 *)*(u32 *)(a + 4u), 0u);
    ext_59e650((u8 *)*(u32 *)(self + 0x1cu), *(u32 *)elem);
}
PCREG(5589e0, f5589e0);
