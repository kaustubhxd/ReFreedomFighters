// batch322.cpp - decomp area 64 (docs/20-unclaimed-64.md), slice floor(addr/16) mod 20 == 3.
#include "ff.h"

// 0x514670: thiscall with no stack arguments (plain ret). x = self[+0x1c9] (float). If !(x > 0): return.
// Otherwise x' = x - sys[+0x48] (sys = global at 0x70039c), stored to self[+0x1c9]. If !(0 > x') return.
// Otherwise self[+0x1c9] = -1.0f and, if child = self[+0x134] is non-null, the exe tail-jumps to child->vtbl[0x28].
// The port calls that slot and returns; this is equal only because the callee takes no stack arguments (see the spec).
// GUESS: a countdown that clamps at -1 and then notifies a child.
static void THISCALL countdown_514670(u8 *self) {
    float x = *(float *)(self + 0x1c9);
    if (!(x > 0.0f)) return;
    u8 *sys = G(u8 *, 0x70039c);
    float nx = x - *(float *)(sys + 0x48);
    *(float *)(self + 0x1c9) = nx;
    if (!(0.0f > nx)) return;
    *(float *)(self + 0x1c9) = -1.0f;
    u8 *child = *(u8 **)(self + 0x134);
    if (child) {
        void **vt = *(void ***)child;
        ((void(__attribute__((thiscall)) *)(u8 *))vt[0x28 / 4])(child);
    }
}
PCREG(514670, countdown_514670);
