// batch5126.cpp - area 73 batch 51 (gap band, GUESS name): FUN_4f4d60, with a tail call (jmp 0x560360).
#include "ff.h"

// 0x560360 is outside the decompiled set. The original tail-jumps to it with the stack argument still in place, so the
// port calls it as a thiscall with the same argument and returns its result (the rule for tail jumps: arity is the
// function's own ret imm16 / 4, the thunk's stack args pass straight through, the target is hooked by address).
extern "C" u8 THISCALL ext_560360(u8 *self, u32 a);

// 0x4f4d60 (GUESS FUN_4f4d60): ret 4, returns a bool. this+0x70 == 0x20 gives 1; otherwise the tail call result.
static u8 THISCALL guess4f4d60(u8 *self, u32 a1) {
  if (*(u32 *)(self + 0x70) == 0x20)
    return 1;
  return ext_560360(self, a1);
}
PCREG(4f4d60, guess4f4d60);
