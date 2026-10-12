// batch327.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): 0x6079d0 (stdcall, two arguments, ret 8; GUESS).
// 0x64fec0(a, b) (exe, stdcall, two arguments); then r = [[0x70039c] + 0x190f].vtbl[0x290]() (thiscall, no arguments);
// return r.vtbl[8](a) (thiscall, one argument; the callee pops it and its result is returned).
#include "ff.h"

extern "C" void STDCALL ext_64fec0(u32 a, u32 b);
typedef u32(THISCALL * slot290_t)(u32);
typedef u32(THISCALL * slot8_t)(u32, u32);

static u32 STDCALL run_6079d0(u32 a, u32 b) {
    ext_64fec0(a, b);
    u32 obj = *(u32 *)(G(u32, 0x70039cu) + 0x190fu);
    u32 r = ((slot290_t)*(u32 *)(*(u32 *)obj + 0x290u))(obj);
    return ((slot8_t)*(u32 *)(*(u32 *)r + 8u))(r, a);
}
PCREG(6079d0, run_6079d0);
