// batch6120.cpp - unclaimed-68 batch 13 (claim 12). Name from the GC name map (see docs/20-unclaimed-68.md for the confidence).
#include "ff.h"

// The hook pointer at 0x7003b0 is an exe function pointer, called with ecx = this and no arguments.
typedef void(THISCALL *HookFn)(u8 *self);

// 0x4cee30, ZOffsetAlloc::Reset(unsigned int, unsigned int): thiscall, ret 8. The count at this+8 is reset; when the second
// argument b is not above the first, a (the first argument) the hook at 0x7003b0 is called; then the entry (a, b - a) is
// appended at this+4 + count*8 and the count goes up. (A null hook pointer is an int3 trap in the original; not modelled.)
static void THISCALL zOffsetAllocReset(u8 *self, u32 a, u32 b) {
  *(u32 *)(self + 8) = 0;
  if (!(b > a)) {
    HookFn hook = G(HookFn, 0x7003b0);
    if (hook) hook(self);
  }
  u32 n = *(u32 *)(self + 8);
  u32 diff = b - a;
  u8 *entry = *(u8 **)(self + 4) + n * 8;
  *(u32 *)(entry + 4) = diff;
  *(u32 *)entry = a;
  *(u32 *)(self + 8) = n + 1;
}
PCREG(4cee30, zOffsetAllocReset);
