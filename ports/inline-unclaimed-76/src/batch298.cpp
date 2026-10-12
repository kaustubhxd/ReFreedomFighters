// batch298.cpp - unclaimed area 76 (docs/20-unclaimed-76.md), residue 15: two scalar-deleting destructors with an SEH frame.
// SEH frame not reproduced: the exe's fs:[0] frame setup and its unwinding are not modelled; the logic below is the same.
#include "ff.h"

typedef u32 (__attribute__((thiscall)) *Slot1_498)(u8 *, u32);
typedef void (__attribute__((cdecl)) *Cb0_498)(void);

// Exe helper 0x4690b0 (cdecl, two arguments: object, size). GUESS call-recording stub in the spec.
extern "C" void ext_4690b0(u32 self, u32 size);

// Shared body. Sets this+0x44 = 0, this+0x30 = 0 and the vtable 0x686874; calls engine-object vtbl[0x34](this); then, if
// flags bit 0 is set: flags bit 2 gives ext_4690b0(this, size) (size 0xd5 or 0xa64); otherwise the global callback at
// 0x7003b0 is called when set. Returns this. GUESS.
static u8 *dtorBody_498(u8 *self, u32 flags, u32 size_if_bit2) {
    *(u32 *)(self + 0x44) = 0u;
    *(u32 *)(self + 0x30) = 0u;
    *(u32 *)self = 0x686874u;
    u8 *eng9b = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    ((Slot1_498)(*(void ***)eng9b)[0x34 / 4])(eng9b, (u32)self);
    if ((flags & 1u) == 0u) return self;
    if (flags & 4u) {
        ext_4690b0((u32)self, size_if_bit2);
        return self;
    }
    Cb0_498 cb = G(Cb0_498, 0x7003b0);
    if (cb != 0) cb();   // the exe asserts (int3) when this is null; that path is not ported
    return self;
}

// 0x4a50b0(this, flags) (ret 4): size 0xd5 for the bit-2 branch.
static u32 THISCALL dtor_4a50b0(u8 *self, u32 flags) {
    return (u32)dtorBody_498(self, flags, 0xd5u);
}
PCREG(4a50b0, dtor_4a50b0);

// 0x5816f0(this, flags) (ret 4): size 0xa64 for the bit-2 branch.
static u32 THISCALL dtor_5816f0(u8 *self, u32 flags) {
    return (u32)dtorBody_498(self, flags, 0xa64u);
}
PCREG(5816f0, dtor_5816f0);
