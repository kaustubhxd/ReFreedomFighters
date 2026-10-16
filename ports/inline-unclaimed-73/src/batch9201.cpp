// batch9201.cpp - residue 6 batch 92: FUN_004cef60
#include "ff.h"

extern "C" void THISCALL ext_4cee80(void *self, u32 a);

// 0x4cef60 (GUESS FUN_004cef60): thiscall, one argument a, ret 4.
// Calls vcall at [this][0x78], compares result with [this+0x28],
// stores 0 at [this+0x28] if they match, then calls ext_4cee80 with arg and this.
static void THISCALL guess4cef60(void *self, u32 a) {
  u32 **vt = (u32 **)self;
  u32 fn_ptr = vt[0][0x78 / 4];

  // Call vcall at [this][0x78] with inline asm to preserve ECX
  u32 vcall_result;
  asm volatile(
    "mov %[self], %%ecx\n\t"
    "call *%[fn]\n\t"
    : "=a" (vcall_result)
    : [self] "r" (self), [fn] "r" (fn_ptr)
    : "ecx"
  );

  // Compare result with [this+0x28]
  // If equal, store 0 at [this+0x28]
  u32 stored_val = *(u32 *)((u8 *)self + 0x28);
  if (stored_val == vcall_result) {
    *(u32 *)((u8 *)self + 0x28) = 0;
  }

  // Call ext_4cee80 with arg and this
  ext_4cee80(self, a);
}
PCREG(4cef60, guess4cef60);
