// batch297.cpp - unclaimed area 76 (docs/20-unclaimed-76.md), residue 15: 0x4e6dc0 (ret 8; thiscall with two arguments).
#include "ff.h"

typedef void (__attribute__((thiscall)) *SlotU_4e6dc0)(u8 *, u8 *);

// Exe helpers, stubbed in the spec with GUESS call-recording hooks: 0x45e420 (thiscall, one argument, returns an object or null),
// 0x48db70 (thiscall, no arguments, returns a count), 0x41e290 (cdecl, one argument: allocation).
extern "C" u8 *THISCALL ext_45e420(u8 *self, u32 y);
extern "C" u32 THISCALL ext_48db70(u8 *self);
extern "C" u8 *ext_41e290(u32 size);

// 0x4e6dc0(this, x, y) (ret 8). o = ext_45e420(x, y) with ecx = x; if o is null return. cnt = ext_48db70(o). e = [o+8] when the
// top two bits of [o+4] are 01, 10 or 11 (the 0xc0000000 test), else 8. If (y - 0x100001) is at most 1 (unsigned): rec = a
// new 0x1c block; rec = {8, y, o+e, o+e+8, ..., cnt-1 times 8 added to o+e at +0xc, rec+0x14 = o+e+8, rec+0x10 = o+e}, then
// (this+0xc)->vtbl[4](rec). GUESS.
static void THISCALL pushRec_4e6dc0(u8 *self, u32 x, u32 y) {
    u8 *o = ext_45e420((u8 *)x, y);
    if (o == 0) return;
    u32 cnt = ext_48db70(o);
    u32 top = *(u32 *)(o + 4) & 0xc0000000u;
    u32 e = (top == 0x40000000u || top == 0x80000000u || top == 0xc0000000u) ? *(u32 *)(o + 8) : 8u;
    u32 base = e + (u32)o;
    if ((y - 0x100001u) > 1u) return;
    u8 *rec = ext_41e290(0x1cu);
    u32 k = (cnt - 1u) * 8u;
    *(u32 *)(rec + 0) = 8u;
    *(u32 *)(rec + 4) = y;
    *(u32 *)(rec + 8) = base;
    *(u32 *)(rec + 0x10) = base;
    *(u32 *)(rec + 0x14) = base + 8u;
    *(u32 *)(rec + 0xc) = k + base;
    u8 *emb = self + 0xc;
    ((SlotU_4e6dc0)(*(void ***)emb)[4 / 4])(emb, rec);
}
PCREG(4e6dc0, pushRec_4e6dc0);
