// batch350.cpp - decomp area 64 (docs/20-unclaimed-64.md): verifies the exe helper 0x5002f0.
#include "ff.h"

// 0x5002f0: thiscall (ecx = self, one stack word v, ret 4). If the tag byte self[+4] is not 0 or 1, first log through the
// logger at 0x700390: L = G3->vtbl[0x20](G3, 0x69c8e0, 0x104) (thiscall, two words), then L->vtbl[0x2c](L, 0x69c6b0, 0x69c938)
// (cdecl, three words; the caller pops), then call the hook at 0x7003b0 (cdecl, no words; if the hook is null the exe traps).
// Then (every path): self[+0] = v; self[+4] = 1; return self. GUESS: a set-value-and-tag helper with a debug log on a bad tag.
typedef u32(__attribute__((thiscall)) * LoggerGetFn)(u8 *, u32, u32);
typedef void(__attribute__((cdecl)) * LoggerWriteFn)(u32, u32, u32);
typedef void(__attribute__((cdecl)) * HookFn)();

static u8 *THISCALL setValue_5002f0(u8 *self, u32 v) {
    u8 tag = *(u8 *)(self + 0x4);
    if (tag != 0 && tag != 1) {
        u8 *G3 = G(u8 *, 0x700390);
        void **vg = *(void ***)G3;
        u32 L = ((LoggerGetFn)vg[0x20 / 4])(G3, 0x69c8e0u, 0x104u);
        void **vl = *(void ***)L;
        ((LoggerWriteFn)vl[0x2c / 4])(L, 0x69c6b0u, 0x69c938u);
        HookFn h = G(HookFn, 0x7003b0);
        if (!h) __builtin_trap();
        h();
    }
    *(u32 *)self = v;
    *(u8 *)(self + 0x4) = 1;
    return self;
}
PCREG(5002f0, setValue_5002f0);
