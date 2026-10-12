// batch311.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): three compare-and-copy functions (thiscall, ret 4).
// Compares the 16 dwords at this+OFF with the source (the argument, or the exe's default block at 0x6efc90 when it is null). On the
// first mismatch, copies the 64 bytes of the source over this+OFF and returns the result of the stdcall slot 0x94 of the object at
// this+0x1377, called with (object, MODE, this+OFF). If all 16 dwords match, returns the last dword (this+OFF+0x3c). GUESS.
#include "ff.h"

typedef u32 (__attribute__((stdcall)) *Slot94_311)(u8 *, u32, u32);

static u32 compareCopy_311(u8 *self, u32 a, u32 off, u32 mode) {
    u8 *src = a != 0u ? (u8 *)a : (u8 *)0x6efc90u;
    u8 *dst = self + off;
    for (u32 i = 0; i < 16u; i++) {
        if (*(u32 *)(dst + 4u * i) != *(u32 *)(src + 4u * i)) {
            for (u32 j = 0; j < 16u; j++) *(u32 *)(dst + 4u * j) = *(u32 *)(src + 4u * j);
            u8 *obj = *(u8 **)(self + 0x1377);
            return ((Slot94_311)(*(void ***)obj)[0x94 / 4])(obj, mode, (u32)dst);
        }
    }
    return *(u32 *)(dst + 0x3c);
}

// 0x6107e0 (dst at this+0x142a, mode 3).
static u32 THISCALL cc_6107e0(u8 *self, u32 a) { return compareCopy_311(self, a, 0x142au, 3u); }
PCREG(6107e0, cc_6107e0);

// 0x610e20 (dst at this+0x146a, mode 2).
static u32 THISCALL cc_610e20(u8 *self, u32 a) { return compareCopy_311(self, a, 0x146au, 2u); }
PCREG(610e20, cc_610e20);

// 0x610f20 (dst at this+0x14aa, mode 0x100).
static u32 THISCALL cc_610f20(u8 *self, u32 a) { return compareCopy_311(self, a, 0x14aau, 0x100u); }
PCREG(610f20, cc_610f20);
