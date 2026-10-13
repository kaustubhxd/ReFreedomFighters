// batch354.cpp - decomp area 64 residue-18 pass: 0x4d93e0 (init and link of a record). Helpers 0x634d10 (cdecl, three words),
// 0x4de7a0 (thiscall, ecx = self, no words) and the global child's slot 0x34 (thiscall, one word) are stubbed on both sides (GUESS).
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_634d10(u8 *self, u32 zero, u32 size);
extern "C" void THISCALL ext_4de7a0(u8 *self);
typedef u32(__attribute__((thiscall)) * Slot1Fn)(u8 *, u32);

// 0x4d93e0: thiscall (ecx = self, no stack words, plain ret), returns self. Calls 0x634d10(self, 0, 0x70); the child's
// (sys[+0x9b][+8]) slot 0x34 with self; 0x4de7a0(self); then self[+0x3c] |= 0x1000000, clears the word at +0x5a, the byte at +0x58,
// the dword at +0x54, and sets self[+0x68] = 0.
static u8 *THISCALL initLink_4d93e0(u8 *self) {
    ext_634d10(self, 0u, 0x70u);
    u8 *sys = G(u8 *, 0x70039c);
    u8 *obj = *(u8 **)(*(u8 **)(sys + 0x9b) + 0x8);
    void **vt = *(void ***)obj;
    ((Slot1Fn)vt[0x34 / 4])(obj, (u32)self);
    ext_4de7a0(self);
    *(u32 *)(self + 0x3c) |= 0x1000000u;
    *(u16 *)(self + 0x5a) = 0;
    *(u8 *)(self + 0x58) = 0;
    *(u32 *)(self + 0x54) = 0;
    *(u32 *)(self + 0x68) = 0;
    return self;
}
PCREG(4d93e0, initLink_4d93e0);
