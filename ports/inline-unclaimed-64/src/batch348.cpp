// batch348.cpp - decomp area 64 (docs/20-unclaimed-64.md): verifies the exe allocator 0x41e290.
#include "ff.h"

// 0x41e290: cdecl (one stack word = size). mm = the global at 0x70038c. If mm is set: return mm->vtbl[8](mm, size) (a
// thiscall with one word; the callee pops it). Else: size &= 0x1fffffff, then tail-jump through the function pointer at
// 0x6762f0 (cdecl; the port calls it and returns its eax). GUESS: a memory-manager wrapper with a plain fallback allocator.
typedef u32(__attribute__((thiscall)) * MmAllocFn)(u8 *, u32);
typedef u32(__attribute__((cdecl)) * FallbackFn)(u32);

static u32 __attribute__((cdecl)) alloc_41e290(u32 size) {
    u8 *mm = G(u8 *, 0x70038c);
    if (mm) {
        void **vt = *(void ***)mm;
        return ((MmAllocFn)vt[0x8 / 4])(mm, size);
    }
    u32 s = size & 0x1fffffffu;
    return ((FallbackFn)G(u32, 0x6762f0))(s);
}
PCREG(41e290, alloc_41e290);
