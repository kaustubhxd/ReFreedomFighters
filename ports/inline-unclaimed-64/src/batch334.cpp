// batch334.cpp - decomp area 64 (docs/20-unclaimed-64.md), slice floor(addr/16) mod 20 == 3.
#include "ff.h"

// Virtual calls on the child C (slot 8: four stack words, returns eax) and on self (slot 0x28c: three stack words).
// Thiscall: the callee pops the words.
typedef u32(__attribute__((thiscall)) * Slot8Fn)(u8 *, u32, u32, u32, u32);
typedef void(__attribute__((thiscall)) * Slot28cFn)(u8 *, u32, u32, u32);

// 0x43fab0: thiscall (ecx = self, four stack words a, b, c, d; ret 0x10).
// C = sys[+0x9b][+8] (sys = global at 0x70039c). r = C->vtbl[8](C, a, b, 0, 0). If r == 0 return 0.
// Otherwise self->vtbl[0x28c](self, r, c, d); return *(u32 *)(r + 0x54). GUESS: a request to a child, and a result
// read back from the returned record.
static u32 THISCALL requestRecord_43fab0(u8 *self, u32 a, u32 b, u32 c, u32 d) {
    u8 *sys = G(u8 *, 0x70039c);
    u8 *ch = *(u8 **)(sys + 0x9b);
    u8 *C = *(u8 **)(ch + 0x8);
    void **vc = *(void ***)C;
    u32 r = ((Slot8Fn)vc[0x8 / 4])(C, a, b, 0u, 0u);
    if (r == 0) return 0;
    void **vs = *(void ***)self;
    ((Slot28cFn)vs[0x28c / 4])(self, r, c, d);
    return *(u32 *)(r + 0x54);
}
PCREG(43fab0, requestRecord_43fab0);
