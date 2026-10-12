// batch302.cpp - decomp area 39 (docs/20-unclaimed-39.md), slice floor(addr/16) mod 20 == 18.
#include "ff.h"

// Exe helper 0x5270f0 (thiscall, ecx = block at +0x28, one stack argument = obj, ret 4). Runs as original code.
// It makes its own virtual calls on obj (slots 0x50, 0x68, 0x18, 0x6c), so the harness stubs obj's vtable.
extern "C" void THISCALL ext_5270f0(u8 *self, u8 *obj);

// Virtual call through obj's vtable at byte offset 0x6c: thiscall with one stack argument (callee pops it).
typedef void(__attribute__((thiscall)) * Slot6cFn)(u8 *, u8 *);
static void callSlot6c(u8 *obj, u8 *arg) {
    void **vt = *(void ***)obj;
    ((Slot6cFn)vt[0x6c / 4])(obj, arg);
}

// 0x5274a0: thiscall (ecx = self block, one stack argument = obj, ret 4), returns true (al = 1).
// Calls obj->vtbl[0x6c](obj, self+4), (obj, self+0x10), (obj, self+0x1c) in order, re-reading the vtable each time,
// then runs the exe helper 0x5270f0(self+0x28, obj). GUESS: a three-field read from an object, then a sub-block load.
static u8 THISCALL readBlock_5274a0(u8 *self, u8 *obj) {
    callSlot6c(obj, self + 0x4);
    callSlot6c(obj, self + 0x10);
    callSlot6c(obj, self + 0x1c);
    ext_5270f0(self + 0x28, obj);
    return 1;
}
PCREG(5274a0, readBlock_5274a0);
