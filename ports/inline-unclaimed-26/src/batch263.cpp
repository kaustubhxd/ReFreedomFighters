// batch263.cpp - unclaimed area 26 (docs/20-unclaimed-26.md), slice floor(addr/16) mod 20 == 5.
#include "ff.h"

typedef u32 (__attribute__((thiscall)) *SlotF_524810)(u8 *, float);

// 0x524810: calls a.vtbl[0x4c](a, float) for the six floats at this+0, +4, ..., +0x14 (in that order), then returns true
// (ret 4). GUESS: copies a six-float block into a sink object.
static u8 THISCALL pushSix_524810(u8 *self, u32 a) {
    u8 *obj = (u8 *)a;
    void **vt = *(void ***)obj;
    for (int i = 0; i < 6; i++) {
        ((SlotF_524810)vt[0x4c / 4])(obj, *(float *)(self + 4 * i));
    }
    return 1;
}
PCREG(524810, pushSix_524810);
