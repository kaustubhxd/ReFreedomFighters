// batch303.cpp - unclaimed area 76 (docs/20-unclaimed-76.md), residue 15: 0x45dcb0 (a wrapper, ret 0x10).
#include "ff.h"

// Exe helper 0x4daaf0 (thiscall, five stack arguments, ret 0x14). Runs as original code.
extern "C" u32 THISCALL ext_4daaf0(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 one);

// 0x45dcb0(this, a, b, c, d) (ret 0x10): ext_4daaf0([this+8], a, b, c, d, 1) and returns its eax. GUESS.
static u32 THISCALL wrap_45dcb0(u8 *self, u32 a, u32 b, u32 c, u32 d) {
    u8 *obj = *(u8 **)(self + 8);
    return ext_4daaf0(obj, a, b, c, d, 1u);
}
PCREG(45dcb0, wrap_45dcb0);
