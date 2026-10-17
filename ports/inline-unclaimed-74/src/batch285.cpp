// batch285.cpp - unclaimed area 74 (docs/20-unclaimed-74.md), slice 13 leaves from the full list.
#include "ff.h"

// Exe helper 0x59dae0 (thiscall, five stack arguments, ret 0x14). Runs as original code; its residue is not 13.
extern "C" void THISCALL ext_59dae0(u8 *self, u32 a, u32 b, u32 c, u32 one, u32 d);

// 0x4682d0: stores the stack argument at this+0x1d6 (ret 4). GUESS: a dword field setter.
static void THISCALL setField1d6_4682d0(u8 *self, u32 v) {
    *(u32 *)(self + 0x1d6) = v;
}
PCREG(4682d0, setField1d6_4682d0);

// 0x5eeb90: stores the stack argument at this+0x4e (ret 4). GUESS: a dword field setter.
static void THISCALL setField4e_5eeb90(u8 *self, u32 v) {
    *(u32 *)(self + 0x4e) = v;
}
PCREG(5eeb90, setField4e_5eeb90);

// 0x5af0d0: idx = the stack argument; if idx < [this] (unsigned), returns [this + 4 + 4*idx]; else 0 (ret 4). GUESS: an
// indexed dword table read with a bound.
static u32 THISCALL tableAt_5af0d0(u8 *self, u32 idx) {
    if (idx < *(u32 *)self) return *(u32 *)(self + 4 + 4 * idx);
    return 0u;
}
PCREG(5af0d0, tableAt_5af0d0);

// 0x59db50(this, a, b, c, d) (ret 0x10). If [this+0x7ce] is zero, or the dword at this + 0x7c2 + 16*n (n = [this+0x7ce])
// is below a, calls ext_59dae0(this, a, b, c, 1, d) and returns 1. Otherwise returns 0. GUESS.
static u32 THISCALL gateCall_59db50(u8 *self, u32 a, u32 b, u32 c, u32 d) {
    u32 n = *(u32 *)(self + 0x7ce);
    if (n == 0u || *(u32 *)(self + 0x7c2 + 16 * n) < a) {
        ext_59dae0(self, a, b, c, 1u, d);
        return 1u;
    }
    return 0u;
}
PCREG(59db50, gateCall_59db50);
