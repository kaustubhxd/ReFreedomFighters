// batch342.cpp - decomp area 64 (docs/20-unclaimed-64.md), slice floor(addr/16) mod 20 == 3.
#include "ff.h"

// Exe allocator 0x41e290 and free 0x41e2c0 (both cdecl; the caller pops). Both are patched to stubs in the spec, on
// both sides (the exe wrappers run through a global object and an SEH frame, which are not modelled).
extern "C" u32 __attribute__((cdecl)) ext_41e290(u32 size);
extern "C" void __attribute__((cdecl)) ext_41e2c0(u32 block);

// 0x5f4630: thiscall (ecx = self; plain ret, no stack words). With n = self[+4] and the old buffer old = self[+0]:
// size = 4 * (2n) (all ones if the product overflows); p = alloc(size); self[+0] = p; copy n dwords old -> p;
// free(old); self[+4] = 2n. GUESS: a growable array that doubles its count and copies the existing elements.
static void THISCALL growArray_5f4630(u8 *self) {
    u32 *old = *(u32 **)self;
    u32 n = *(u32 *)(self + 0x4);
    u32 newCount = n + n;
    u64 prod = (u64)newCount * 4u;
    u32 size = prod > 0xffffffffu ? 0xffffffffu : (u32)prod;
    u32 *p = (u32 *)ext_41e290(size);
    *(u32 **)self = p;
    for (u32 i = 0; i < n; i++) p[i] = old[i];
    ext_41e2c0((u32)old);
    *(u32 *)(self + 0x4) = newCount;
}
PCREG(5f4630, growArray_5f4630);
