// batch305.cpp - unclaimed-03 batch 5 (docs/20-unclaimed-03.md): one unnamed function at 0x46ba60 (no GC name; the
// name is left as a GUESS, 'unnamed'). Body from the PC bytes. It calls 0x46b800 (original code, not lifted here).
#include "ff.h"

// 0x46b800, the callee of 0x46ba60 (thiscall, two stack arguments, original code). Bound by build.sh to its PC address.
extern "C" void THISCALL ext_46b800(u8 *self, u32 a1, u32 a2);

// 0x46ba60, unnamed (GUESS): compares the low word of a1 with the word at this+0x92. If equal, calls vtable slot +0x324
// with one argument a2 (thiscall). Then tail-calls 0x46b800 with this, a1, a2 (the PC pushes a2, then a1, and calls).
// Callee pops 8.
static void THISCALL unnamed46ba60(u8 *self, u32 a1, u32 a2) {
  if ((u16)a1 == *(u16 *)(self + 0x92)) {
    typedef void(THISCALL * slot_fn)(u8 *, u32);
    slot_fn f = *(slot_fn *)(*(u32 *)self + 0x324);
    f(self, a2);
  }
  ext_46b800(self, a1, a2);
}
PCREG(46ba60, unnamed46ba60);
