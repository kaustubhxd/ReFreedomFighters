// batch345.cpp - decomp area 64 (docs/20-unclaimed-64.md), slice floor(addr/16) mod 20 == 3.
#include "ff.h"

// Exe helper 0x4da440: thiscall (ecx = object), one stack word, ret 4. Stubbed on both sides in the spec.
extern "C" u32 THISCALL ext_4da440(u8 *obj, u32 arg);

// Virtual calls: thiscall with one or two stack words (the callee pops them).
typedef u32(__attribute__((thiscall)) * Slot2Fn)(u8 *, u32, u32);   // logger G3 slot 0x20 (returns the logger)
typedef u32(__attribute__((thiscall)) * Slot1Fn)(u8 *, u32);        // A slot 0x1cc and 0x210; logger slots
// The logger's slot 0x2c is cdecl with six words; the caller removes them (add esp, 0x18).
typedef u32(__attribute__((cdecl)) * Slot2cFn)(u32, u32, u32, u32, u32, u32);

// 0x45dd30: thiscall (ecx = self, two stack words A and B, ret 8), returns al.
// x = self[+0xc][+0x23] ^ A[+0xc][+0x23]. If (x & 0x7f000000) != 0 (the logging path): L = G3(0x685054, 0x337) (the logger at
// 0x700390, slot 0x20); the logger's slot 0x2c is called (cdecl) with (L, 0x6850a0, self[+0xc][0], str2, A[+0xc][0], str1),
// where str1 = A[+4] or 0x67c8e8 and str2 = self[+4] or 0x67c8e8; then A->vtbl[0x210](A, 1); return 1.
// Otherwise: ext 0x4da440(A[+8], self[+8]); if B != 0, A->vtbl[0x1cc](A, B); return 0. GUESS: a debug-logged check
// between two records, with a fallback notification.
static u8 THISCALL check_45dd30(u8 *self, u8 *A, u32 B) {
    u8 *P = *(u8 **)(self + 0xc);
    u8 *Q = *(u8 **)(A + 0xc);
    u32 x = *(u32 *)(P + 0x23) ^ *(u32 *)(Q + 0x23);
    if (x & 0x7f000000u) {
        u8 *G3 = G(u8 *, 0x700390);
        void **vg = *(void ***)G3;
        u32 L = ((Slot2Fn)vg[0x20 / 4])(G3, 0x685054u, 0x337u);
        u32 str1 = *(u32 *)(A + 0x4) ? *(u32 *)(A + 0x4) : 0x67c8e8u;
        u32 val = *(u32 *)Q;
        u32 str2 = *(u32 *)(self + 0x4) ? *(u32 *)(self + 0x4) : 0x67c8e8u;
        u32 p0 = *(u32 *)P;
        void **vl = *(void ***)L;
        ((Slot2cFn)vl[0x2c / 4])(L, 0x6850a0u, p0, str2, val, str1);
        void **va = *(void ***)A;
        ((Slot1Fn)va[0x210 / 4])(A, 1u);
        return 1;
    }
    ext_4da440(*(u8 **)(A + 0x8), *(u32 *)(self + 0x8));
    if (B != 0) {
        void **va = *(void ***)A;
        ((Slot1Fn)va[0x1cc / 4])(A, B);
    }
    return 0;
}
PCREG(45dd30, check_45dd30);
