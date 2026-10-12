// batch345.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): two members (GUESS).
// 0x606ea0 (stdcall, two arguments pp (a pointer to a char pointer) and m, ret 8): s = [pp]; h = 0; for each byte c != 0 (signed):
//   h = h*5 + (c in 'A'..'Z' ? 0x20 : 0) + (signed) c; returns h % m (unsigned).
// 0x6204a0 (cdecl, one argument p, plain ret): if [p+4] == 0: [p+4] = [p]; else reverse the list at [p] into the list at [p+4] (each
//   node's first dword is the link). Then [p] = [p+0x10] = [p+0xc] = [p+8] = 0.
#include "ff.h"

static u32 STDCALL hash_606ea0(u32 pp, u32 m) {
    const s8 *s = (const s8 *)*(u32 *)pp;
    u32 h = 0u;
    for (; *s != 0; s++) {
        s8 c = *s;
        if (c >= 0x41 && c <= 0x5a) h = h * 5u + 0x20u + (u32)(s32)c;
        else h = h * 5u + (u32)(s32)c;
    }
    return h % m;
}
PCREG(606ea0, hash_606ea0);

static void __attribute__((cdecl)) reverse_6204a0(u32 p) {
    if (*(u32 *)(p + 4u) == 0u) {
        *(u32 *)(p + 4u) = *(u32 *)p;
    } else {
        u32 esi = *(u32 *)p;
        while (esi != 0u) {
            u32 edx = *(u32 *)esi;
            *(u32 *)esi = *(u32 *)(p + 4u);
            *(u32 *)(p + 4u) = esi;
            esi = edx;
        }
    }
    *(u32 *)p = 0u;
    *(u32 *)(p + 0x10u) = 0u;
    *(u32 *)(p + 0xcu) = 0u;
    *(u32 *)(p + 8u) = 0u;
}
PCREG(6204a0, reverse_6204a0);
