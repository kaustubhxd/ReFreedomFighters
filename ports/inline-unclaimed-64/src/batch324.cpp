// batch324.cpp - decomp area 64 (docs/20-unclaimed-64.md), slice floor(addr/16) mod 20 == 3.
#include "ff.h"

// Virtual calls, thiscall. Arity is the number of pushes at the exe call site (the callee pops them).
typedef u32(__attribute__((thiscall)) * Slot58Fn)(u8 *, u32);                          // one stack word, returns eax
typedef u32(__attribute__((thiscall)) * Slot114Fn)(u8 *, u32, u32, u32, u32, u32, u32); // six stack words, returns ax
typedef void(__attribute__((thiscall)) * Slot12cFn)(u8 *, u32);                        // one stack word

// 0x5c2630: thiscall (ecx = self, stack word a (16 bits), one unused word; ret 8). Always returns 0.
// If a == word[0x71432c]: self[+0x25b] = 1; e = sys->child->vtbl[0x58](child, self[+0x50]); if e != 0:
//   res = sys->child->vtbl[0x114](child, 0x68fee8, 0, 0x6b3cdc, 0x4f, 0x3e8, 0);
//   e->vtbl[0x12c](e, (u16)res).
// Else if a == word[0x714330]: self[+0x25a] = 1. Else if a == word[0x714334]: self[+0x25a] = 0.
// GUESS: a flag setter keyed by a 16-bit id, with a notify path for the first id.
static u32 THISCALL flagByKey_5c2630(u8 *self, u32 aw, u32) {
    u16 a = (u16)aw;
    if (a == G(u16, 0x71432c)) {
        *(u8 *)(self + 0x25b) = 1;
        u8 *sys = G(u8 *, 0x70039c);
        u8 *child = *(u8 **)(sys + 0x9b);
        void **vt = *(void ***)child;
        u32 e = ((Slot58Fn)vt[0x58 / 4])(child, *(u32 *)(self + 0x50));
        if (e) {
            u8 *ed = (u8 *)e;
            void **vte = *(void ***)ed;
            sys = G(u8 *, 0x70039c);
            child = *(u8 **)(sys + 0x9b);
            vt = *(void ***)child;
            u32 res = ((Slot114Fn)vt[0x114 / 4])(child, 0x68fee8u, 0u, 0x6b3cdcu, 0x4fu, 0x3e8u, 0u);
            ((Slot12cFn)vte[0x12c / 4])(ed, (u32)(u16)res);
        }
        return 0;
    }
    if (a == G(u16, 0x714330)) {
        *(u8 *)(self + 0x25a) = 1;
        return 0;
    }
    if (a == G(u16, 0x714334)) {
        *(u8 *)(self + 0x25a) = 0;
    }
    return 0;
}
PCREG(5c2630, flagByKey_5c2630);
