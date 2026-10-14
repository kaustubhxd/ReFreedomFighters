// batch289.cpp - unclaimed area 74 (docs/20-unclaimed-74.md), slice 13 logger-using leaf.
#include "ff.h"

typedef u32 (__attribute__((thiscall)) *Slot2_4d2e50)(u8 *, u32, u32);
typedef void (__attribute__((cdecl)) *Log3_4d2e50)(u8 *, u32, u32);

// Exe copy helper 0x634d22 (cdecl: source, destination, size). Runs as original code; the spec stubs its memcpy import.
extern "C" void ext_634d22(const u8 *src, u8 *dst, u32 size);

// 0x4d2e50(this, a, bp) (ret 8). local = byte at bp. r = this.vtbl[0xb0](a, 0). If r is non-null: unless (r+4)->+0x10 has bit 0,
// the logger (0x700390).vtbl[0x24](logger, 0x696394, a) (cdecl); size = [r+8]; ext_634d22(&local, [r] + 0xc + r, size).
// Then the byte at bp = (local != 0). Returns size (0 when r is null). GUESS.
static u32 THISCALL copyFlag_4d2e50(u8 *self, u32 a, u32 bp) {
    u32 local = (u32)*(u8 *)bp;
    u32 size = 0u;
    u32 r = ((Slot2_4d2e50)(*(void ***)self)[0xb0 / 4])(self, a, 0u);
    if (r != 0u) {
        u8 *obj = *(u8 **)(r + 4);
        if ((*(u8 *)(obj + 0x10) & 1u) == 0u) {
            u8 *lg = G(u8 *, 0x700390);
            ((Log3_4d2e50)(*(void ***)lg)[0x24 / 4])(lg, 0x696394u, a);
        }
        size = *(u32 *)(r + 8);
        ext_634d22((const u8 *)&local, (u8 *)(*(u32 *)r + 0xcu + r), size);
    }
    *(u8 *)bp = (local != 0u) ? 1 : 0;
    return size;
}
PCREG(4d2e50, copyFlag_4d2e50);
