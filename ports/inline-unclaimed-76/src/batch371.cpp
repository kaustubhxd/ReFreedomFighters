// batch371.cpp - area 76, residue 18 (slice from out/functions.jsonl; the full PC list). Two thiscall accessors.
// 0x660ce0 (thiscall, no arguments, plain ret, returns eax; GUESS): o = [this+0x18]; if o == 0 return 0; else tail-jump to
//   o.vtbl[0x14](o) with no arguments (the port calls the slot as a thiscall with no arguments and returns its eax).
// 0x6043a0 (thiscall, no arguments, plain ret, returns eax; GUESS): x = [[0x724278] + 0x3c]; return x.vtbl[8](x, word [this+0x24]).
#include "ff.h"

static u32 THISCALL f660ce0(u8 *selfp) {
    u32 o = *(u32 *)((u32)selfp + 0x18u);
    if (o == 0u) return 0u;
    return ((u32(THISCALL *)(u32))(*(u32 *)(*(u32 *)o + 0x14u)))(o);
}
PCREG(660ce0, f660ce0);

static u32 THISCALL f6043a0(u8 *selfp) {
    u32 self = (u32)selfp;
    u32 x = *(u32 *)(G(u32, 0x724278u) + 0x3cu);
    u32 w = (u32)*(u16 *)(self + 0x24u);
    return ((u32(THISCALL *)(u32, u32))(*(u32 *)(*(u32 *)x + 8u)))(x, w);
}
PCREG(6043a0, f6043a0);
