// batch323.cpp - decomp area 64 (docs/20-unclaimed-64.md), slice floor(addr/16) mod 20 == 3.
#include "ff.h"

// Exe helper 0x43ec00: thiscall, six stack words (ret 0x18), returns eax. Runs as original code.
extern "C" u32 THISCALL ext_43ec00(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);

// Virtual call on the child: slot 0x58, thiscall with two stack words (the callee pops 8). Returns eax.
typedef u32(__attribute__((thiscall)) * Slot58Fn)(u8 *, u32, u32);

// 0x43ebb0: thiscall (ecx = self, seven stack words a1..a7, ret 0x1c).
// child = sys[+0x1a9f] (sys = global at 0x70039c). If child is null, return 0. Otherwise r = child->vtbl[0x58](child, a3, a4).
// If r is 0 return 0; otherwise return 0x43ec00(self, a1, a2, r, a5, a6, a7) (exe). GUESS: a forwarder that resolves a
// child by a call, then passes the arguments on with the result substituted for a3.
static u32 THISCALL forward_43ebb0(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u8 *sys = G(u8 *, 0x70039c);
    u8 *child = *(u8 **)(sys + 0x1a9f);
    if (!child) return 0;
    void **vt = *(void ***)child;
    u32 r = ((Slot58Fn)vt[0x58 / 4])(child, a3, a4);
    if (r == 0) return 0;
    return ext_43ec00(self, a1, a2, r, a5, a6, a7);
}
PCREG(43ebb0, forward_43ebb0);
