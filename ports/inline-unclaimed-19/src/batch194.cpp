// batch194.cpp - unclaimed area 19 (docs/20-unclaimed-19.md), slice floor(addr/16) mod 20 == 18.
#include "ff.h"

typedef u32 (__attribute__((thiscall)) *Slot0Fn_5a76a0)(u8 *);

// 0x5a76a0: child = [this+0x644]; child->vtbl[8](child) (call, no args); then child = [this+0x644] again and
// tail-jumps to child->vtbl[4] with ECX = child (jmp, no stack args). The port ends with a call + return, so the
// slot's eax comes back the same way. The slot 4 entry takes no stack arguments in this spec only: the exe's
// tail jump passes the caller's own stack, and the port does not model that. GUESS: a double forward to a child.
static u32 THISCALL forward_5a76a0(u8 *self) {
    u8 *child = *(u8 **)(self + 0x644);
    void **vt = *(void ***)child;
    ((Slot0Fn_5a76a0)vt[8 / 4])(child);
    child = *(u8 **)(self + 0x644);
    vt = *(void ***)child;
    return ((Slot0Fn_5a76a0)vt[4 / 4])(child);
}
PCREG(5a76a0, forward_5a76a0);
