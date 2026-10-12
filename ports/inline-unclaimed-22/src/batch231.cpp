// batch231.cpp - unclaimed area 22 (docs/20-unclaimed-22.md), residue 01. 0x46f510: calls 0x45f3a0 (thiscall, no stack
// arguments), then tail-jumps to 0x46f240 with ecx = this; the callee's eax is returned. Name GUESS.
#include "ff.h"

extern "C" void THISCALL ext_45f3a0(u8 *self);     // original, thiscall, no stack arguments
extern "C" u32 THISCALL ext_46f240(u8 *self);      // original, thiscall, no stack arguments (tail target)

// 0x46f510, thiscall(): push esi; esi = this; call 0x45f3a0 (this); ecx = esi; jmp 0x46f240.
static u32 THISCALL callThenTail_46f510(u8 *self) {
  ext_45f3a0(self);
  return ext_46f240(self);
}
PCREG(46f510, callThenTail_46f510);
