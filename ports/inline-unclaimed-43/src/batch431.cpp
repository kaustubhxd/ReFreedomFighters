// batch431.cpp - residue 2 row 0x4f9d60 (stdcall, one stack argument a, ret 4; returns bool).
// Call 0x4f9c90 (GUESS, hooked by address, thiscall with ECX = this, no args).
// Call 0x4e12e0 (GUESS, hooked) with (1, address of [ebp+8]=a, a).
// Call 0x4e11e0 (GUESS, hooked) with (1, address [this+0xab], a).
// Call 0x4e12e0 (GUESS, hooked) with (1, address [this+0x9b], a).
// Call 0x4e1b30 (GUESS, hooked) with ECX = a, no args.
// Compare a with 0, set [this+0x8f] = (a == 0).
#include "ff.h"

extern "C" void THISCALL ext_4f9c90(void *self);          // exe callee by address (hooked in the spec)
extern "C" void ext_4e12e0(u32 v1, u32 a, u32 v3);        // exe callee (hooked)
extern "C" void ext_4e11e0(u32 v1, u32 a, u32 v3);        // exe callee (hooked)
extern "C" void THISCALL ext_4e1b30(void *self);          // exe callee (hooked)

static u32 STDCALL multiCallSequence(u8 *self, u32 a) {
  ext_4f9c90(self);
  ext_4e12e0(1, (u32)&a, a);
  ext_4e11e0(1, (u32)(self + 0xab), a);
  ext_4e12e0(1, (u32)(self + 0x9b), a);
  ext_4e1b30((void *)(unsigned long)a);
  u32 result = (a == 0) ? 1 : 0;
  *(u32 *)((u8 *)self + 0x8f) = result;
  return result;
}
PCREG(4f9d60, multiCallSequence);
