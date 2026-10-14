// batch270.cpp - unclaimed area 26 (docs/20-unclaimed-26.md), residue-05 list.
#include "ff.h"

typedef void (__attribute__((thiscall)) *Slot2_4b89d0)(u8 *, u32, u32);

// Exe helper 0x4b8ab0 (thiscall, one stack argument, ret 4): a list pass over this+0x4c. Runs as original code.
extern "C" u32 THISCALL ext_4b8ab0(u8 *self, u32 zero);

// 0x4b89d0: s = (this+0x54 + this+0x50) * G(0x678620) truncated to int. If engine+0x40 < s (signed), return. Else
// ext_4b8ab0(this, 0) and this.vtbl[0x68](this, 0x10, 0). No stack args, plain ret. GUESS.
static void THISCALL tick_4b89d0(u8 *self) {
    float s = (*(float *)(self + 0x54) + *(float *)(self + 0x50)) * G(float, 0x678620);
    s32 limit = (s32)s;
    u8 *eng = G(u8 *, 0x70039c);
    if ((s32)G(u32, eng + 0x40) < limit) return;
    ext_4b8ab0(self, 0u);
    ((Slot2_4b89d0)(*(void ***)self)[0x68 / 4])(self, 0x10u, 0u);
}
PCREG(4b89d0, tick_4b89d0);
