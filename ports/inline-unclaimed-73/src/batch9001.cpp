// batch9001.cpp - residue 6 batch 90: FUN_0053a9e0.
#include "ff.h"

// 0x53a9e0 (GUESS FUN_0053a9e0): thiscall, no arguments, no return value.
// Dereferences this, calls virtual method at +4 on the dereferenced value,
// then conditionally copies data based on comparison with global at 0x70039c.
static void THISCALL guess53a9e0(void *self) {
  // Get object from *this
  void **obj_ptr = (void **)self;
  void *obj = obj_ptr[0];

  // Get vtable from obj and call offset 4
  u32 **vt = (u32 **)obj;
  u32 fn_ptr = vt[0][4 / 4];

  // Use inline assembly to preserve ECX across the thiscall
  // The original pushes 0 as an argument before calling
  u32 result;
  asm volatile(
    "push $0\n\t"
    "mov %[obj], %%ecx\n\t"
    "call *%[fn]\n\t"
    : "=a" (result)
    : [obj] "r" (obj), [fn] "r" (fn_ptr)
    : "ecx"
  );

  // Get global and do address arithmetic
  u32 *global = *(u32 **)0x70039c;
  u32 *global_at_40 = (u32 *)((u8 *)global + 0x40);
  u32 *edx = (u32 *)((u8 *)result - 4 + 0x20);

  // Conditional copy
  if (edx != global_at_40) {
    u32 *copy_src = (u32 *)((u8 *)global_at_40);
    *edx = *copy_src;
  }
}
PCREG(53a9e0, guess53a9e0);
