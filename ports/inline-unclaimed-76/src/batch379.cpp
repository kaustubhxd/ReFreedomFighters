// batch379.cpp - area 76, residue 17 (out/functions.jsonl). Three thiscall functions (GUESS).
// 0x57aa50 (thiscall, two stack arguments a, b, ret 8, returns bool in al): 0x562e90(a, b) (stdcall-like call, hooked); this.vtbl[0x64](0x10);
//   al = 0.
// 0x661310 (thiscall, one stack argument, ret 4, returns this): 0x4eb350(a) (thiscall with ECX = this, hooked); [this] = 0x6c4a00; return this.
// 0x650dd0 (thiscall, one stack argument, ret 4, no return value): old = [this+0x8c]; if old: old.vtbl[0](old, 1); [this+0x8c] = a.
#include "ff.h"

extern "C" void __attribute__((stdcall)) ext_562e90(u32 a, u32 b);
extern "C" void THISCALL ext_4eb350(u8 *self, u32 a);

static u8 THISCALL f57aa50(u8 *selfp, u32 a, u32 b) {
    u32 self = (u32)selfp;
    ext_562e90(a, b);
    ((u32(THISCALL *)(u32, u32))(*(u32 *)(*(u32 *)self + 0x64u)))(self, 0x10u);
    return 0u;
}
PCREG(57aa50, f57aa50);

static u8 *THISCALL f661310(u8 *selfp, u32 a) {
    u32 self = (u32)selfp;
    ext_4eb350(selfp, a);
    *(u32 *)self = 0x6c4a00u;
    return selfp;
}
PCREG(661310, f661310);

static void THISCALL f650dd0(u8 *selfp, u32 a) {
    u32 self = (u32)selfp;
    u32 old = *(u32 *)(self + 0x8cu);
    if (old != 0u) ((void(THISCALL *)(u32, u32))(*(u32 *)(*(u32 *)old)))(old, 1u);
    *(u32 *)(self + 0x8cu) = a;
}
PCREG(650dd0, f650dd0);
