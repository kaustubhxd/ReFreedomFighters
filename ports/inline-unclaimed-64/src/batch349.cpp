// batch349.cpp - decomp area 64 (docs/20-unclaimed-64.md): verifies the exe free wrapper 0x41e2c0.
#include "ff.h"

// 0x41e2c0: cdecl (one stack word = pointer). mm = the global at 0x70038c. If mm is set: mm->vtbl[0x10](mm, ptr), a
// thiscall with one word (the callee pops it). Otherwise: call the function pointer at 0x6762ec with ptr (cdecl; the caller
// pops). The SEH frame in the exe has no effect on the result. Returns void. GUESS: a memory-manager wrapper that falls back to
// a plain free.
typedef void(__attribute__((thiscall)) * MmFreeFn)(u8 *, u32);
typedef void(__attribute__((cdecl)) * FallbackFreeFn)(u32);

static void __attribute__((cdecl)) free_41e2c0(u32 ptr) {
    u8 *mm = G(u8 *, 0x70038c);
    if (mm) {
        void **vt = *(void ***)mm;
        ((MmFreeFn)vt[0x10 / 4])(mm, ptr);
    } else {
        ((FallbackFreeFn)G(u32, 0x6762ec))(ptr);
    }
}
PCREG(41e2c0, free_41e2c0);
