// batch286.cpp - unclaimed area 74 (docs/20-unclaimed-74.md), slice 13 leaf from the full list.
#include "ff.h"

// 0x545d10(this, a, b, c, d) (ret 0x10): p = [this+0xf] + 0x34*a. Copies the three dwords at p+0xc into b, the three dwords
// at p+0x24 into c, and the dword at p+0x30 into d. GUESS: an indexed record read into three out-parameters.
static void THISCALL readRec_545d10(u8 *self, u32 a, u32 b, u32 c, u32 d) {
    u32 base = *(u32 *)(self + 0xf);
    u8 *p = (u8 *)(base + 0x34u * a);
    *(u32 *)(b + 0) = *(u32 *)(p + 0xc);
    *(u32 *)(b + 4) = *(u32 *)(p + 0x10);
    *(u32 *)(b + 8) = *(u32 *)(p + 0x14);
    *(u32 *)(c + 0) = *(u32 *)(p + 0x24);
    *(u32 *)(c + 4) = *(u32 *)(p + 0x28);
    *(u32 *)(c + 8) = *(u32 *)(p + 0x2c);
    *(u32 *)(d) = *(u32 *)(p + 0x30);
}
PCREG(545d10, readRec_545d10);
