// batch309.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): 0x616fa0, a packed-byte copy (stdcall, ret 0xc).
#include "ff.h"

// 0x616fa0(dst, src, n) (ret 0xc): for i in 0..n-1: dst[i] = (dword at src + 0x18 + 0x24*i) >> 1, masked to 0x7f7f7f7f. Returns n
// (eax counts the copies). GUESS: halves packed colour or byte lanes out of a record array.
static u32 STDCALL packHalf_616fa0(u32 dst, u32 src, u32 n) {
    u32 i = 0;
    while (i < n) {
        u32 v = *(u32 *)(src + 0x18u + 0x24u * i);
        *(u32 *)(dst + 4u * i) = (v >> 1) & 0x7f7f7f7fu;
        i++;
    }
    return i;
}
PCREG(616fa0, packHalf_616fa0);
