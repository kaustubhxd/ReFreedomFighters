// batch281.cpp - unclaimed area 76 (docs/20-unclaimed-76.md), slice 15 leaves from the full list.
#include "ff.h"

typedef void (__attribute__((thiscall)) *Slot2_59d3f0)(u8 *, u32, u32);
typedef void (__attribute__((thiscall)) *Slot1_59d3f0)(u8 *, u32);

// 0x5eebb0: stores the stack argument at this+0x6f (ret 4). GUESS: a dword field setter.
static void THISCALL setField6f_5eebb0(u8 *self, u32 v) {
    *(u32 *)(self + 0x6f) = v;
}
PCREG(5eebb0, setField6f_5eebb0);

// 0x59d3f0: A = the stack argument. A.vtbl[0x10](this+4, 4); A.vtbl[0x10](this+8, 4); A.vtbl[0x3c](this+0xc);
// A.vtbl[0x3c](this+0x10); returns true (ret 4). GUESS: sends a small record to an object.
static u8 THISCALL sendRec_59d3f0(u8 *self, u32 a) {
    u8 *A = (u8 *)a;
    ((Slot2_59d3f0)(*(void ***)A)[0x10 / 4])(A, (u32)(self + 4), 4u);
    ((Slot2_59d3f0)(*(void ***)A)[0x10 / 4])(A, (u32)(self + 8), 4u);
    ((Slot1_59d3f0)(*(void ***)A)[0x3c / 4])(A, *(u32 *)(self + 0xc));
    ((Slot1_59d3f0)(*(void ***)A)[0x3c / 4])(A, *(u32 *)(self + 0x10));
    return 1;
}
PCREG(59d3f0, sendRec_59d3f0);
