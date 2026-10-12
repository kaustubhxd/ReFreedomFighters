// batch276.cpp - unclaimed area 76 (docs/20-unclaimed-76.md), slice 15 (small leaves from the full function list).
#include "ff.h"

typedef u32 (__attribute__((thiscall)) *Slot3_4442b0)(u8 *, u32, u32, u32);

// 0x483eb0: writes 1.0f to the three dwords at the pointer argument (ret 4). GUESS: sets a unit vector.
static void THISCALL unitVec_483eb0(u8 *, u32 p) {
    *(float *)(p + 0) = 1.0f;
    *(float *)(p + 4) = 1.0f;
    *(float *)(p + 8) = 1.0f;
}
PCREG(483eb0, unitVec_483eb0);

// 0x4cf130: pointer argument p gets this+4 at p+0, 0 at p+4 and 1 at p+8 (ret 4). GUESS: a record init.
static void THISCALL initRec_4cf130(u8 *self, u32 p) {
    *(u32 *)(p + 4) = 0u;
    *(u32 *)(p + 8) = 1u;
    *(u32 *)(p + 0) = *(u32 *)(self + 4);
}
PCREG(4cf130, initRec_4cf130);

// 0x4e7d70: stores v at this, unless this is the stack slot of the argument itself (ret 4). GUESS.
static void THISCALL storeUnlessSelf_4e7d70(u8 *self, u32 v) {
    if ((u32)self != (u32)&v) *(u32 *)self = v;
}
PCREG(4e7d70, storeUnlessSelf_4e7d70);

// 0x5a7530: this+0x354 = (byte at 0x7142f8 != 0) ? 0 : v (ret 4). GUESS: a flag-gated setter.
static void THISCALL gatedSet_5a7530(u8 *self, u32 v) {
    *(u32 *)(self + 0x354) = (G(u8, 0x7142f8) != 0) ? 0u : v;
}
PCREG(5a7530, gatedSet_5a7530);

// 0x4442b0: returns this.vtbl[0x28c](*(a+8), b, c) with three stack arguments (ret 0xc). GUESS: a forward with a field of a.
static u32 THISCALL forward3_4442b0(u8 *self, u32 a, u32 b, u32 c) {
    void **vt = *(void ***)self;
    return ((Slot3_4442b0)vt[0x28c / 4])(self, *(u32 *)(((u8 *)a) + 8), b, c);
}
PCREG(4442b0, forward3_4442b0);
