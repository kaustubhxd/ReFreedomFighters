// batch329.cpp - decomp area 64 (docs/20-unclaimed-64.md), slice floor(addr/16) mod 20 == 3.
#include "ff.h"

// Exe table lookup 0x5003d0 (thiscall, one stack word = index, ret 4). See batch326.cpp.
extern "C" u32 THISCALL ext_5003d0(u8 *table, u32 index);

// Virtual call on obj: slot 0x36c, thiscall with one stack word (the callee pops it, as the exe's tail jump requires).
typedef u32(__attribute__((thiscall)) * Slot36cFn)(u8 *, u32);

// 0x51b0b0: thiscall (ecx = self, one stack pointer p, ret 4). T = p[+4]; entry = lookup(T, 0); flag = (*entry != 0);
// obj = self[+0x1c]. The exe then tail-jumps to obj->vtbl[0x36c] with flag in the stack slot of p, so the callee's
// ret pops that slot for the caller. The port calls the slot with flag and returns its eax. GUESS: a flag from a table
// entry forwarded to an object's method.
static u32 THISCALL flagForward_51b0b0(u8 *self, u8 *p) {
    u8 *T = *(u8 **)(p + 0x4);
    u32 entry = ext_5003d0(T, 0u);
    u32 flag = *(u32 *)entry != 0 ? 1u : 0u;
    u8 *obj = *(u8 **)(self + 0x1c);
    void **vt = *(void ***)obj;
    return ((Slot36cFn)vt[0x36c / 4])(obj, flag);
}
PCREG(51b0b0, flagForward_51b0b0);
