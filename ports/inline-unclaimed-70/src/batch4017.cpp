// batch4017.cpp - area 70 (slice 4 leaf), batch 4017: 0x45fdd0, a tail-jump thunk into 0x4dd8f0 (name GUESS).
#include "ff.h"

extern "C" u32 THISCALL ext_4dd8f0(void *self, u32 a);   // exe: wrapper, ECX = this, one stack argument, ret 4; calls 0x4419f0

// 0x45fdd0 (name GUESS): thiscall (ECX = this), one stack argument a, ret 4 (the caller's argument stays on the stack and
// is popped by the callee at the jump). Tail-jumps to 0x4dd8f0 with ECX = [this+8] and a as its one stack argument.
static u32 THISCALL thunk45fdd0(u8 *self, u32 a) {
  return ext_4dd8f0(*(void **)(self + 8), a);
}
PCREG(45fdd0, thunk45fdd0);
