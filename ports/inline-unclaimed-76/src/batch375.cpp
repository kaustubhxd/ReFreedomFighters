// batch375.cpp - area 76, residue 18 (out/functions.jsonl): 0x660f60 (thiscall, no arguments, plain ret; GUESS).
// If [0x70039c].0x9c7 != 0 and .0x9c3 != 0 (NaN counts as nonzero) and byte [this+0x20] == 0 and obj = [this+0x18] != 0:
//   obj.vtbl[0x4c](&local); p = obj.vtbl[0x64](&local); while p != 0: { p+0x30 = 0; p+0x34 = 0; then 98 dwords copied forward from
//   p+0x30 to p+0x38 (rep movsd: overlapping, so the block becomes zero); p = obj.vtbl[0x64](&local) }.
#include "ff.h"

static void THISCALL f660f60(u8 *selfp) {
    u32 self = (u32)selfp;
    u32 E = G(u32, 0x70039cu);
    if (*(float *)(E + 0x9c7u) == 0.0f) return;
    if (*(float *)(E + 0x9c3u) == 0.0f) return;
    if (*(u8 *)(self + 0x20u) != 0u) return;
    u32 obj = *(u32 *)(self + 0x18u);
    if (obj == 0u) return;
    u32 local;                       // [ebp-0xc]: uninitialized in the exe as well
    ((u32(THISCALL *)(u32, u32))(*(u32 *)(*(u32 *)obj + 0x4cu)))(obj, (u32)&local);
    u32 p = ((u32(THISCALL *)(u32, u32))(*(u32 *)(*(u32 *)obj + 0x64u)))(obj, (u32)&local);
    while (p != 0u) {
        volatile u32 *src = (volatile u32 *)(p + 0x30u);     // volatile: keep the overlapping forward copy sequential
        src[0] = 0u;
        src[1] = 0u;
        for (u32 i = 0u; i < 0x62u; i++) src[2 + i] = src[i];   // rep movsd, forward, overlapping
        obj = *(u32 *)(self + 0x18u);
        p = ((u32(THISCALL *)(u32, u32))(*(u32 *)(*(u32 *)obj + 0x64u)))(obj, (u32)&local);
    }
}
PCREG(660f60, f660f60);
