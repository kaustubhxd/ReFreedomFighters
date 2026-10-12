// batch274.cpp - unclaimed area 76 (docs/20-unclaimed-76.md), residue-15 list.
#include "ff.h"

typedef void (__attribute__((thiscall)) *Slot1_5bd970)(u8 *, u32);
typedef void (__attribute__((thiscall)) *Slot2_5bd970)(u8 *, u32, u32);

// 0x5bd970 (CCheckInsideByType::Load): ld = the stack argument, the loader object. Clears bit 6 of this+4, then calls
// ld.vtbl[0x48](this+0x6c), ld.vtbl[0x48](this+0x70), ld.vtbl[0x18](this+0x48, 0x24), ld.vtbl[0x44](this+0x75),
// ld.vtbl[0x44](this+0x77), ld.vtbl[0x40](this+0x79), ld.vtbl[0x68](this+0x74). Returns true. ret 4.
static u8 THISCALL load_5bd970(u8 *self, u32 ld) {
    u8 *l = (u8 *)ld;
    *(u32 *)(self + 4) &= 0xffffffbfu;
    ((Slot1_5bd970)(*(void ***)l)[0x48 / 4])(l, (u32)(self + 0x6c));
    ((Slot1_5bd970)(*(void ***)l)[0x48 / 4])(l, (u32)(self + 0x70));
    ((Slot2_5bd970)(*(void ***)l)[0x18 / 4])(l, (u32)(self + 0x48), 0x24u);
    ((Slot1_5bd970)(*(void ***)l)[0x44 / 4])(l, (u32)(self + 0x75));
    ((Slot1_5bd970)(*(void ***)l)[0x44 / 4])(l, (u32)(self + 0x77));
    ((Slot1_5bd970)(*(void ***)l)[0x40 / 4])(l, (u32)(self + 0x79));
    ((Slot1_5bd970)(*(void ***)l)[0x68 / 4])(l, (u32)(self + 0x74));
    return 1;
}
PCREG(5bd970, load_5bd970);
