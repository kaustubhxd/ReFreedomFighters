// batch376.cpp - area 76, residue 17 (out/functions.jsonl). Three small functions.
// 0x635490 (thiscall, no arguments, plain ret; GUESS): o = [this+0x14]; if o != 0: o.vtbl[0](o, 1) (deleting destructor, thiscall, one word).
// 0x425150 (thiscall, no arguments, plain ret; GUESS): o = [this+0x28]; if o != 0: o.vtbl[0](o, 1); then 0x42ad20(this) (thiscall,
//   plain; runs as exe code: if [this+0xc] != 0 it calls its vtbl[0](obj, 1) and clears [this+0xc]).
// 0x659b10 (thiscall, one stack argument, ret 4, returns bool; GUESS): r = this.vtbl[0xe4](arg) (thiscall, one word); [arg+0x14] = r; return true.
#include "ff.h"

extern "C" void THISCALL ext_42ad20(u8 *self);

static void THISCALL f635490(u8 *selfp) {
    u32 o = *(u32 *)((u32)selfp + 0x14u);
    if (o == 0u) return;
    ((void(THISCALL *)(u32, u32))(*(u32 *)(*(u32 *)o)))(o, 1u);
}
PCREG(635490, f635490);

static void THISCALL f425150(u8 *selfp) {
    u32 self = (u32)selfp;
    u32 o = *(u32 *)(self + 0x28u);
    if (o != 0u) ((void(THISCALL *)(u32, u32))(*(u32 *)(*(u32 *)o)))(o, 1u);
    ext_42ad20(selfp);
}
PCREG(425150, f425150);

static u8 THISCALL f659b10(u8 *selfp, u32 arg) {
    u32 r = ((u32(THISCALL *)(u32, u32))(*(u32 *)(*(u32 *)selfp + 0xe4u)))((u32)selfp, arg);
    *(u32 *)(arg + 0x14u) = r;
    return 1u;
}
PCREG(659b10, f659b10);
