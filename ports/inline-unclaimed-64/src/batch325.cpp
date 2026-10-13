// batch325.cpp - decomp area 64 (docs/20-unclaimed-64.md), slice floor(addr/16) mod 20 == 3.
#include "ff.h"

// Exe switch 0x59d450 (thiscall, no stack words, plain ret): mode = self[+4]; bounded jump table for modes 0..7 (any
// larger mode takes the default path). Writes self[+0xc] and self[+0x10] from the mode, and sets self[+0xc] = 0 when
// self[+8] == 3. Runs as original code.
extern "C" void THISCALL ext_59d450(u8 *self);

// 0x59d330: thiscall (ecx = self, stack words a and b, ret 8). Writes self[+0] = a, self[+4] = b, self[+0xc] = 0,
// self[+0x10] = 0; calls ext 0x59d450(self); self[+0x14] = the global list head at 0x7142cc; the global becomes self;
// self[+8] = 0. Returns self. GUESS: a constructor that links the object into a global list.
static u32 THISCALL ctor_59d330(u8 *self, u32 a, u32 b) {
    *(u32 *)(self + 0x0) = a;
    *(u32 *)(self + 0x4) = b;
    *(u32 *)(self + 0xc) = 0;
    *(u32 *)(self + 0x10) = 0;
    ext_59d450(self);
    *(u32 *)(self + 0x14) = G(u32, 0x7142cc);
    G(u32, 0x7142cc) = (u32)self;
    *(u32 *)(self + 0x8) = 0;
    return (u32)self;
}
PCREG(59d330, ctor_59d330);
