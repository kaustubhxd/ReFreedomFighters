#include "ff.h"
// batch954.cpp - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x44f540 and 0x4351a0.
// 0x44f540 (thiscall, no arguments): push 1; call 0x450980; ret. The callee takes one stack argument and cleans it (no pop here), with
// ecx unchanged from entry. Called through the exe's own 0x450980 (ext_450980, run for real in both runs).
// 0x4351a0 (thiscall, one stack argument, ret 4): inner = [self+8]; if inner == 0 return; else tail-jump to [[inner]+0x90] (jmp), so the
// target gets ecx = inner and the same stack argument, and it cleans that argument. Modelled as a call with the same argument; the
// port's own ret 4 pops it, which matches because the target is callee-cleaned. The null path leaves EAX as it came in (ret=None in spec).

extern "C" u32 THISCALL ext_450980(u8 *self, u32 a1);

typedef u32(THISCALL *tc1)(u8 *, u32);

static void THISCALL zg44f540(u8 *self) {
  ext_450980(self, 1);
}
PCREG(44f540, zg44f540);

static u32 THISCALL zg4351a0(u8 *self, u32 a1) {
  u8 *inner = *(u8 **)(self + 8);
  if (inner == 0) return 0;
  return ((tc1)(*(u32 *)(*(u32 *)inner + 0x90)))(inner, a1);
}
PCREG(4351a0, zg4351a0);
