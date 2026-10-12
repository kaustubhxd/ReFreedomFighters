// batch310.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): two record and span copies.
#include "ff.h"

// 0x616fe0(dst, src, n) (stdcall, ret 0xc). For each 0x24-byte record k < n: dst record k gets the dwords of src record k at offsets
// 0, 4, 8, ..., 0x20, except offset 0x18, which is (dword >> 1) & 0x7f7f7f7f. Returns nothing (n == 0 does nothing). GUESS.
static void STDCALL copyRecords_616fe0(u32 dst, u32 src, u32 n) {
    for (u32 k = 0; k < n; k++) {
        u8 *d = (u8 *)(dst + 0x24u * k);
        u8 *s = (u8 *)(src + 0x24u * k);
        for (u32 off = 0; off <= 0x20u; off += 4u) {
            u32 v = *(u32 *)(s + off);
            if (off == 0x18u) v = (v >> 1) & 0x7f7f7f7fu;
            *(u32 *)(d + off) = v;
        }
    }
}
PCREG(616fe0, copyRecords_616fe0);

// 0x606a30(b = ecx, e = edx, p) (fastcall, ret 4). cnt = (e - b + 3) >> 2 (unsigned; zero when b > e). For i < cnt: if p + 4i is
// not null, [p + 4i] = [b + 4i]. Returns p + 4*cnt. GUESS: a bounded dword copy into a pointer.
static u32 FASTCALL copySpan_606a30(u32 b, u32 e, u32 p) {
    u32 cnt = (e - b + 3u) >> 2;
    if (b > e) cnt = 0u;
    for (u32 i = 0; i < cnt; i++) {
        u32 pi = p + 4u * i;
        if (pi != 0u) *(u32 *)pi = *(u32 *)(b + 4u * i);
    }
    return p + 4u * cnt;
}
PCREG(606a30, copySpan_606a30);
