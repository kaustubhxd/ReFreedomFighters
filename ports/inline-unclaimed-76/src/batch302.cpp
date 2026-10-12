// batch302.cpp - unclaimed area 76 (docs/20-unclaimed-76.md), residue 15: 0x4b91f0 (ZProjectile dtor, ret 4).
// SEH frame not reproduced (the exe's fs:[0] frame and its restore are not modelled).
#include "ff.h"

typedef u32 (__attribute__((thiscall)) *Slot1_4b91f0)(u8 *, u32);
typedef void (__attribute__((cdecl)) *Free2_4b91f0)(u32, u32);
typedef void (__attribute__((cdecl)) *Cb_4b91f0)(void);

// Exe helpers (run as original code, or stubbed in the spec): 0x634273 (cdecl: pointer, size; a free), 0x4690b0 (cdecl: object, size).
extern "C" void ext_634273(u32 ptr, u32 size);
extern "C" void ext_4690b0(u32 self, u32 size);

// 0x4b91f0(this, flags) (ret 4). Writes the vtable 0x692a30, frees [this+0x8d] (size 0x6d) and [this+0x6d] (size 0x2c), then sets
// this+0x44 = 0, this+0x30 = 0, the vtable 0x686874 and calls engine vtbl[0x34](this). If flags bit 0: bit 2 gives
// ext_4690b0(this, 0x9f); else the dispatch callback at 0x7003b0 is called (the exe asserts when it is null: not ported).
// Returns this. SEH frame not reproduced.
static u32 THISCALL dtorC_4b91f0(u8 *self, u32 flags) {
    *(u32 *)self = 0x692a30u;
    ext_634273(*(u32 *)(self + 0x8d), 0x6du);
    ext_634273(*(u32 *)(self + 0x6d), 0x2cu);
    *(u32 *)(self + 0x44) = 0u;
    *(u32 *)(self + 0x30) = 0u;
    *(u32 *)self = 0x686874u;
    u8 *eng9b = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    ((Slot1_4b91f0)(*(void ***)eng9b)[0x34 / 4])(eng9b, (u32)self);
    if ((flags & 1u) == 0u) return (u32)self;
    if (flags & 4u) {
        ext_4690b0((u32)self, 0x9fu);
        return (u32)self;
    }
    Cb_4b91f0 cb = G(Cb_4b91f0, 0x7003b0);
    cb();
    return (u32)self;
}
PCREG(4b91f0, dtorC_4b91f0);
