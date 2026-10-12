// batch192.cpp - unclaimed area 19 (docs/20-unclaimed-19.md), slice floor(addr/16) mod 20 == 18.
// Needs a vtable stub: a forwarder that calls slot 0x220 of the child object with one stack argument of 0.
#include "ff.h"

// 0x5059e0: child = [this+0x14]; returns child->vtbl[0x220](child, 0) (push 0, call [eax+0x220], ret 4).
// The one stack argument is popped and not used. GUESS: a forwarder to a child's method.
typedef u32 (__attribute__((thiscall)) *ChildFn_5059e0)(u8 *, u32);
static u32 THISCALL forward_5059e0(u8 *self, u32) {
    u8 *child = *(u8 **)(self + 0x14);
    void **vt = *(void ***)child;
    return ((ChildFn_5059e0)vt[0x220 / 4])(child, 0u);
}
PCREG(5059e0, forward_5059e0);
