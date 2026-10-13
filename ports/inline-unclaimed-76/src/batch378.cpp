// batch378.cpp - area 76, residue 17 (out/functions.jsonl). Three vtable chains (thiscall; GUESS).
// 0x650b50 (thiscall, one stack argument unused, ret 4): this.vtbl[0x90](); this.vtbl[0x9c]([this+0x3c] + 1).
// 0x64f9d0 (thiscall, no arguments, plain ret; returns the last call's eax): r = [0x70038c].vtbl[0x98](); this.vtbl[0x74](r, 0x2000).
// 0x657450 (thiscall, one stack argument, ret 4; returns eax): r = this.vtbl[0xc](a); return this.vtbl[0xc]([r + 0x80]).
#include "ff.h"

static u32 vt0(u32 obj, u32 off) {
    return ((u32(THISCALL *)(u32))(*(u32 *)(*(u32 *)obj + off)))(obj);
}
static u32 vt1(u32 obj, u32 off, u32 a) {
    return ((u32(THISCALL *)(u32, u32))(*(u32 *)(*(u32 *)obj + off)))(obj, a);
}
static u32 vt2(u32 obj, u32 off, u32 a, u32 b) {
    return ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(*(u32 *)obj + off)))(obj, a, b);
}

static void THISCALL f650b50(u8 *selfp, u32 unused) {
    u32 self = (u32)selfp;
    (void)unused;
    vt0(self, 0x90u);
    u32 w = *(u32 *)(self + 0x3cu) + 1u;
    vt1(self, 0x9cu, w);
}
PCREG(650b50, f650b50);

static u32 THISCALL f64f9d0(u8 *selfp) {
    u32 self = (u32)selfp;
    u32 r = vt0(G(u32, 0x70038cu), 0x98u);
    return vt2(self, 0x74u, r, 0x2000u);
}
PCREG(64f9d0, f64f9d0);

static u32 THISCALL f657450(u8 *selfp, u32 a) {
    u32 self = (u32)selfp;
    u32 r = vt1(self, 0xcu, a);
    return vt1(self, 0xcu, *(u32 *)(r + 0x80u));
}
PCREG(657450, f657450);
