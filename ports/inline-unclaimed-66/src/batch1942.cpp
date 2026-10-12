// batch1942.cpp - unclaimed-66 batch 43 (gap band, GUESS name). THISCALL(this), no arguments, eax returned.
//   Calls 0x573da0 (a jmp thunk to 0x573dd0; ECX = this, no arguments; discarded), then tail-jumps to 0x576330 (ECX = this, no
//   arguments, plain ret) and returns its eax. Both callees are recording GUESS stubs hooked by address in the spec.
#include "ff.h"

extern "C" void THISCALL ext_573da0(u8 *self);       // no arguments; result unused
extern "C" u32 THISCALL ext_576330(u8 *self);        // no arguments; returns eax

// 0x576250, GUESS FUN_00576250 (batch 43).
static u32 THISCALL gapFn576250(u8 *self) {
  ext_573da0(self);
  return ext_576330(self);
}
PCREG(576250, gapFn576250);
