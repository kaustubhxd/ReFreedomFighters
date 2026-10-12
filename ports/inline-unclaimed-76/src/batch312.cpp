// batch312.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): 0x61cbe0, a recursive cdecl emitter (plain ret, GUESS).
// emit(this, idx, out, pBase, pCur): record idx is 7 dwords at [this+0x1e8] (T[7*idx]). out[0] = T[7i], out[1] = T[7i+1].
// kind 4: out[2] = *pCur, copy the NUL-terminated string at T[7i+2] to *pCur (NUL included, *pCur advances), out[3] = out[4] = 0.
// otherwise: out[3] = count T[7i+5], out[4] = *pBase, *pBase += 20*count; for k < count: emit(this, child, out[4] + 0x14*k, pBase, pCur),
// child starts at T[7i+3] and then follows T[7*child+6] (sibling). out[2] = 0 in both the count-zero and the normal case.
#include "ff.h"

static void __attribute__((cdecl)) emit_61cbe0(u32 self, u32 idx, u32 out, u32 pBase, u32 pCur) {
    u32 tab = *(u32 *)(self + 0x1e8u);
    u32 r = tab + 28u * idx;
    *(u32 *)(out + 0u) = *(u32 *)(r + 0u);
    *(u32 *)(out + 4u) = *(u32 *)(r + 4u);
    if (*(u32 *)(out + 0u) == 4u) {
        *(u32 *)(out + 8u) = *(u32 *)pCur;
        u32 dst = *(u32 *)pCur;
        u32 s = *(u32 *)(r + 8u);
        u8 c;
        do {
            c = *(u8 *)s;
            *(u8 *)dst = c;
            s++;
            dst++;
            *(u32 *)pCur += 1u;
        } while (c != 0u);
        *(u32 *)(out + 0xcu) = 0u;
        *(u32 *)(out + 0x10u) = 0u;
        return;
    }
    u32 count = *(u32 *)(r + 0x14u);
    *(u32 *)(out + 0xcu) = count;
    *(u32 *)(out + 0x10u) = *(u32 *)pBase;
    *(u32 *)pBase += 20u * count;
    u32 child = *(u32 *)(r + 0xcu);
    for (u32 k = 0; k < count; k++) {
        emit_61cbe0(self, child, *(u32 *)(out + 0x10u) + 0x14u * k, pBase, pCur);
        child = *(u32 *)(tab + 28u * child + 0x18u);
    }
    *(u32 *)(out + 8u) = 0u;
}
PCREG(61cbe0, emit_61cbe0);
