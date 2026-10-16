// batch386.cpp - area 76, residue 17 (out/functions.jsonl).
// 0x663610 (thiscall, one stack argument, ret 4, returns bool; GUESS): sub = this+0x1218c; sub.vtbl[0xc]() (thiscall, no words);
//   g = [0x700394]; q = [[[0x70039c]+0x9b]+0xae4]; v = q.vtbl[0]() (thiscall, no words);
//   g.vtbl[0x134](sub, v, 0x6a67e8, 0x6c4aa8) (thiscall, four words); if sub.vtbl[0x14]() == 0: [arg] = 0xf, return false; else true.
#include "ff.h"

static u8 THISCALL f663610(u8 *selfp, u32 arg) {
    u32 sub = (u32)selfp + 0x1218cu;
    ((void(THISCALL *)(u32))(*(u32 *)(*(u32 *)sub + 0xcu)))(sub);
    u32 gvt = *(u32 *)(*(u32 *)0x700394u);
    u32 p = *(u32 *)(*(u32 *)0x70039cu + 0x9bu);
    u32 q = *(u32 *)(p + 0xae4u);
    u32 v = ((u32(THISCALL *)(u32))(*(u32 *)(*(u32 *)q)))(q);
    ((void(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(gvt + 0x134u)))(*(u32 *)0x700394u, sub, v, 0x6a67e8u, 0x6c4aa8u);
    if (((u32(THISCALL *)(u32))(*(u32 *)(*(u32 *)sub + 0x14u)))(sub) == 0u) {
        *(u32 *)arg = 0xfu;
        return 0u;
    }
    return 1u;
}
PCREG(663610, f663610);
