// batch2906.cpp - unclaimed-29: batch 6 (docs/20-unclaimed-29.md, claim 6, slice 8). Thiscall, one stack argument (the
// OpaqueCallParameters_t reference); the callee pops it. The final call goes through the global function pointer at 0x7003b0.
#include "ff.h"

typedef u32(THISCALL *Slot0Fn)(u8 *self);
typedef u32(THISCALL *Slot2Fn)(u8 *self, u32 a, u32 b);
typedef u32(*PlainFn)(void);

// 0x506e80, ZActorIf::GetInitialRefPos(OpaqueCallParameters_t&) (high). X = global 0x700390's slot +0x20 with (0x69cff0, 0x290);
// Y = this+0x18's slot +0x20 (no args); then X's slot +0x2c with (X, 0x69d188, def) where def = Y+4 when nonzero, else 0x67c8e8,
// and the call's this is Y+4; then the function pointer at 0x7003b0 is called with no arguments and its result is returned.
// X's slot +0x2c: this in ecx, three stack arguments, and the CALLER removes them (add esp, 0xc follows the call in the
// original). Plain C cannot express that convention, so the call is made with inline asm.
static void callSlot2c(u8 *x, u8 *ecxThis, u32 a, u32 b, u32 c) {
  const u32 vtbl = *(const u32 *)x;
  const u32 fn = *(const u32 *)(vtbl + 0x2c);
  asm volatile(
      "pushl %[c]\n\t"
      "pushl %[b]\n\t"
      "pushl %[a]\n\t"
      "call *%[fn]\n\t"
      "addl $12, %%esp\n\t"
      :
      : "c"(ecxThis), [fn] "r"(fn), [a] "r"(a), [b] "r"(b), [c] "r"(c)
      : "eax", "edx", "memory", "cc");
}

static u32 THISCALL actorIfGetInitialRefPos(u8 *self, u8 *params) {
  (void)params;
  u8 *g = G(u8 *, 0x700390);
  u8 *x = (u8 *)((Slot2Fn)(*(const u32 *)(*(const u32 *)g + 0x20)))(g, 0x69cff0, 0x290);
  u8 *member = *(u8 **)(self + 0x18);
  u8 *y = (u8 *)((Slot0Fn)(*(const u32 *)(*(const u32 *)member + 0x20)))(member);
  u32 def = 0x67c8e8;
  const u32 yfield = *(const u32 *)(y + 4);
  if (yfield) def = yfield;
  callSlot2c(x, (u8 *)(u32)yfield, (u32)x, 0x69d188, def);
  PlainFn fn = (PlainFn)G(u32, 0x7003b0);
  return fn();
}
PCREG(506e80, actorIfGetInitialRefPos);
