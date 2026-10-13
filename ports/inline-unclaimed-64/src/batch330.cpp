// batch330.cpp - decomp area 64 (docs/20-unclaimed-64.md), slice floor(addr/16) mod 20 == 3.
#include "ff.h"

// Exe table lookup 0x5003d0 (thiscall, one stack word = index, ret 4). See batch326.cpp.
extern "C" u32 THISCALL ext_5003d0(u8 *table, u32 index);

// Virtual calls, thiscall with one stack word (the callee pops it).
typedef u32(__attribute__((thiscall)) * Slot1WordFn)(u8 *, u32);

// 0x558eb0: thiscall (ecx = self, one stack pointer p, ret 4). entry = lookup(p[+4], 0);
// r = sys->child->vtbl[0x58](child, *entry); obj = self[+0x1c]; the exe tail-jumps to obj->vtbl[0x4e0](obj, r).
// The port calls that slot and returns its eax (equal because the callee pops the same stack word). GUESS: a value
// read through a table is sent to a child, and the child's result is forwarded to an object's method.
static u32 THISCALL forwardValue_558eb0(u8 *self, u8 *p) {
    u8 *T = *(u8 **)(p + 0x4);
    u32 entry = ext_5003d0(T, 0u);
    u8 *sys = G(u8 *, 0x70039c);
    u8 *child = *(u8 **)(sys + 0x9b);
    void **vt = *(void ***)child;
    u32 r = ((Slot1WordFn)vt[0x58 / 4])(child, *(u32 *)entry);
    u8 *obj = *(u8 **)(self + 0x1c);
    void **vo = *(void ***)obj;
    return ((Slot1WordFn)vo[0x4e0 / 4])(obj, r);
}
PCREG(558eb0, forwardValue_558eb0);
