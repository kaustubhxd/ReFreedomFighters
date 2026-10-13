// batch9901.cpp - residue 6 batch 99: FUN_004f4760
#include "ff.h"

// 0x4f4760 (GUESS FUN_004f4760): thiscall, one argument a, ret 4.
// Stores a at [this+0xb0]. If [this+0xac] is zero, calls vcall at [this][0x294].
static void THISCALL guess4f4760(void *self, u32 a) {
  *(u32 *)((u8 *)self + 0xb0) = a;

  if (*(u32 *)((u8 *)self + 0xac)) {
    u32 **vt = (u32 **)self;
    u32 fn_ptr = vt[0][0x294 / 4];

    asm volatile(
      "mov %[self], %%ecx\n\t"
      "call *%[fn]\n\t"
      :
      : [self] "r" (self), [fn] "r" (fn_ptr)
      : "eax", "ecx"
    );
  }
}
PCREG(4f4760, guess4f4760);
