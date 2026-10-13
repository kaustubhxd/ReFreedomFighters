// batch9801.cpp - residue 6 batch 98: FUN_004cdca0
#include "ff.h"

// 0x4cdca0 (GUESS FUN_004cdca0): thiscall, no arguments, ret void.
// If [this+0x1c] is non-zero, calls vcall [ecx][0] with argument 1,
// then stores 0 at [this+0x1c].
static void THISCALL guess4cdca0(void *self) {
  void *obj_ptr = (void *)(*(u32 *)((u8 *)self + 0x1c));

  if (obj_ptr) {
    u32 **vt = (u32 **)obj_ptr;
    u32 fn_ptr = vt[0][0];

    // Call vcall with inline asm - simple version
    asm volatile(
      "push $1\n\t"
      "mov %[obj], %%ecx\n\t"
      "call *%[fn]\n\t"
      :
      : [obj] "r" (obj_ptr), [fn] "r" (fn_ptr)
      : "eax", "ecx"
    );

    *(u32 *)((u8 *)self + 0x1c) = 0;
  }
}
PCREG(4cdca0, guess4cdca0);
