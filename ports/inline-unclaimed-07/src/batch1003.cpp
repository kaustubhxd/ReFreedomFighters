// batch1003.cpp - unclaimed-07 batch 3 (docs/20-unclaimed-07.md, slice 6): ZFFActor::Resurrect.
// Name from the GC name map (high). Body from the PC bytes.
#include "ff.h"

// 0x47adc0: called first with this in ECX and no arguments (original code, not lifted here).
extern "C" void THISCALL ext_47adc0(u8 *self);

// 0x5a29a0, ZFFActor::Resurrect() (high): calls 0x47adc0, then vtable slot +0x354 with (0, 0) and slot +0x694 with 1,
// and tail-jumps to vtable slot +0x6cc (no arguments). A tail jump with no arguments returns to the same caller, so the
// port calls the slot and returns.
static void THISCALL ffActorResurrect(u8 *self) {
  ext_47adc0(self);
  vcall<void>(self, 0x354, 0u, 0u);
  vcall<void>(self, 0x694, 1u);
  vcall<void>(self, 0x6cc);
}
PCREG(5a29a0, ffActorResurrect);
