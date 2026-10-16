// batch271.cpp - unclaimed area 26 (docs/20-unclaimed-26.md), slice 5 (not on the residue-05 list; claimed here).
#include "ff.h"

typedef void (__attribute__((thiscall)) *Slot1_5ac5d0)(u8 *, u32);

// 0x5ac5d0: for i in 0..count-1 (count = dword at this+0x7f, read each pass, unsigned): obj = [this+0x1a+4*i];
// obj.vtbl[0x248](obj, arg). Skips the loop when count is zero. ret 4. GUESS: forwards a call to an array of children.
static void THISCALL forwardAll_5ac5d0(u8 *self, u32 arg) {
    if (*(u32 *)(self + 0x7f) == 0u) return;
    u32 i = 0;
    do {
        u8 *obj = *(u8 **)(self + 0x1a + 4 * i);
        void **vt = *(void ***)obj;
        ((Slot1_5ac5d0)vt[0x248 / 4])(obj, arg);
        i++;
    } while (i < *(u32 *)(self + 0x7f));
}
PCREG(5ac5d0, forwardAll_5ac5d0);
