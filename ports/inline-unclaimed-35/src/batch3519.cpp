#include "ff.h"
// batch3519.cpp - area 35 claim 19 (docs/20-unclaimed-35.md): two tail-jump thunks in slice 14 (GUESS names).
// Stubbed in the harness: 0x445330 (thiscall, no args) by address; the vtable slot +0x208 target (thiscall, no args, logged).

typedef u32(THISCALL *Slot0)(u8 *self);

extern "C" void THISCALL ext_445330(u8 *self);

// 0x5b21a0, GUESS thunk (thiscall): sets the vtable 0x6b1650 at this, then tail-jumps to 0x445330 with the same this.
static void THISCALL guessDtorThunk(u8 *self) {
  *(u32 *)self = 0x6b1650;
  ext_445330(self);
}
PCREG(5b21a0, guessDtorThunk);

// 0x535560, GUESS thunk (thiscall): tail-jumps through vtable slot +0x208 of this, with this as its only argument.
// PARTIAL: the slot target's arity is not resolvable statically; this assumes no stack arguments.
static u32 THISCALL guessSlot208Thunk(u8 *self) {
  return ((Slot0)*(u32 *)(*(u32 *)self + 0x208))(self);
}
PCREG(535560, guessSlot208Thunk);
