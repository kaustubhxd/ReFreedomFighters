// batch328.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): two small members (GUESS).
// 0x605380 (thiscall, one argument, ret 4, returns bool in al): begin = [this+0xc]; end = begin + strlen(begin); 0x5f2d60 (exe, thiscall
//   with ECX = arg, two stack words end, begin; the callee pops) is called; returns 1.
// 0x6132f0 (thiscall, two arguments a, b, ret 8): t = a*16 + (a < 0x800 ? 1 : 0xffff7801) + a; ptr = this + 4*t; if ptr == 0 or
//   [ptr+0x3c] == 0 return ptr; obj = [ptr+0x3c]; idx = [obj + 4*b + 4]; return this + 4*(17*idx + 1).
#include "ff.h"

extern "C" void THISCALL ext_5f2d60(u32 self, u32 begin, u32 end);

static u8 THISCALL checkName_605380(u8 *self, u32 arg) {
    u32 begin = *(u32 *)(self + 0xcu);
    u32 p = begin;
    while (*(u8 *)p != 0u) p++;
    u32 end = begin + (p - begin);   // the byte loop ends after the NUL; end = begin + strlen(begin)
    ext_5f2d60(arg, begin, end);
    return 1u;
}
PCREG(605380, checkName_605380);

static u32 THISCALL slotIndex_6132f0(u8 *self, u32 a, u32 b) {
    u32 t = a * 16u;
    if (a < 0x800u) t = t + 1u;
    else t = t + 0xffff7801u;
    t = t + a;
    u32 ptr = (u32)self + 4u * t;
    if (ptr == 0u) return ptr;
    u32 obj = *(u32 *)(ptr + 0x3cu);
    if (obj == 0u) return ptr;
    u32 idx = *(u32 *)(obj + 4u * b + 4u);
    return (u32)self + 4u * (idx + 1u + idx * 16u);
}
PCREG(6132f0, slotIndex_6132f0);
