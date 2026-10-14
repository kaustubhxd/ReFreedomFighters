// batch887.cpp - area 50 (residue-09 candidate table row): 0x4daed0 [30 instr, thiscall, one stack arg (a flag, ret 4), void;
// GUESS "Forward4daed0"]. With a nonzero flag: if the object at this+0x54 is null, run the engine's hook at 0x7003b0 (it must be
// installed; the exe traps otherwise), then tail-call vt+0xc8 of the object at this+0x54 with the flag set to 1. With a zero flag:
// tail-call vt+0xc8 of the object (if any) with the flag set to 0. The tail call is written as a call followed by the return
// (the callee pops its own argument; the port's ret 4 pops the caller's).
#include "ff.h"

#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

// 0x4daed0 (name GUESS).
static void THISCALL Forward4daed0(u8 *self, u32 flag) {
  if (flag & 0xffu) {
    if (FP(self, 0x54) == 0) {
      typedef void(THISCALL * hook_t)(void *);  // the exe calls it with ECX = this and no arguments
      hook_t hook = (hook_t)G(u32, 0x7003b0);
      if (!hook) return;                       // the exe traps here (int3); the spec always installs the hook
      hook(self);
    }
    u8 *c = (u8 *)FP(self, 0x54);
    vcall<void>(c, 0xc8, 1u);
  } else {
    u8 *c = (u8 *)FP(self, 0x54);
    if (c) vcall<void>(c, 0xc8, 0u);
  }
}
PCREG(4daed0, Forward4daed0);
