// batch283.cpp - unclaimed area 76 (docs/20-unclaimed-76.md), slice 15 logger-using function.
#include "ff.h"

typedef u32 (__attribute__((thiscall)) *Slot2_4d2d30)(u8 *, u32, u32);
typedef void (__attribute__((cdecl)) *Log3_4d2d30)(u8 *, u32, u32);

// Exe helper 0x634d22 (cdecl, three arguments: source, destination, size). Runs as original code.
extern "C" void ext_634d22(u32 src, u8 *dst, u32 size);

// 0x4d2d30(this, a, b) (ret 8): r = this.vtbl[0xb0](a, 0). If r is null return it. Else, unless (r+4)->+0x10 has bit 3,
// call the logger (engine logger at 0x700390): logger.vtbl[0x24](logger, fmt 0x696394, a) as a cdecl call. Then
// ext_634d22(b, [r] + 0xc + r, [r+8]) copy. Returns [r+8] read after the copy. GUESS.
static u32 THISCALL copyRec_4d2d30(u8 *self, u32 a, u32 b) {
    u32 r = ((Slot2_4d2d30)(*(void ***)self)[0xb0 / 4])(self, a, 0u);
    if (r == 0u) return r;
    u8 *obj = *(u8 **)(r + 4);
    if ((*(u8 *)((u8 *)obj + 0x10) & 8u) == 0u) {
        u8 *lg = G(u8 *, 0x700390);
        ((Log3_4d2d30)(*(void ***)lg)[0x24 / 4])(lg, 0x696394u, a);
    }
    u32 base = *(u32 *)r;
    u32 size = *(u32 *)(r + 8);
    ext_634d22(b, (u8 *)(base + 0xcu + r), size);
    return *(u32 *)(r + 8);
}
PCREG(4d2d30, copyRec_4d2d30);
