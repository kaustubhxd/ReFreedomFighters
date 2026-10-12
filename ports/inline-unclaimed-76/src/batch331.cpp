// batch331.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): 0x61cb70 (cdecl, one argument, plain ret; GUESS).
// v = [A+0x1f4]; addr = [A+0x1ec] + 20*v; buf = [A+0xc](addr) (cdecl, one argument). If buf != 0: pCur = buf + 20*v; pBase = buf + 0x14;
// 0x61cbe0(A, 0, buf, &pBase, &pCur) (exe emitter, cdecl, five arguments); return buf. Else return 0.
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_61cbe0(u32 self, u32 idx, u32 out, u32 pBase, u32 pCur);

static u32 __attribute__((cdecl)) build_61cb70(u32 A) {
    u32 v = *(u32 *)(A + 0x1f4u);
    u32 addr = *(u32 *)(A + 0x1ecu) + 20u * v;
    u32 buf = ((u32(__attribute__((cdecl)) *)(u32))(*(u32 *)(A + 0xcu)))(addr);
    if (buf != 0u) {
        u32 pCur = buf + 20u * v;
        u32 pBase = buf + 0x14u;
        ext_61cbe0(A, 0u, buf, (u32)&pBase, (u32)&pCur);
    }
    return buf;
}
PCREG(61cb70, build_61cb70);
