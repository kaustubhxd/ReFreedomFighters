// batch8942.cpp - residue 6 batch 89: FUN_00451ce0, FUN_006038e0, FUN_004ea260.
#include "ff.h"

// 0x451ce0 (GUESS FUN_00451ce0): thiscall, one argument a. Calls thunk 0x45d5b0 (which tail-jumps to vtable[0x48]).
// Then calls vtable[0xb4](1) on this. Ret 4.
static void THISCALL guess451ce0(void *self, u32 a) {
  u32 **vt = (u32 **)self;
  u32 fn48_ptr = vt[0][0x48 / 4];
  u32 fnb4_ptr = vt[0][0xb4 / 4];

  // Call through vtable[0x48] with inline asm to preserve ECX
  asm volatile(
    "push %[arg]\n\t"
    "mov %[self], %%ecx\n\t"
    "call *%[fn]\n\t"
    :
    : [self] "r" (self), [arg] "r" (a), [fn] "r" (fn48_ptr)
    : "eax", "ecx"
  );

  // Call vtable[0xb4](1) with inline asm to preserve ECX
  // Need to reload self into a local temp to ensure ECX is set correctly
  void *self_copy = self;
  asm volatile(
    "push $1\n\t"
    "mov %[self], %%ecx\n\t"
    "call *%[fn]\n\t"
    :
    : [self] "r" (self_copy), [fn] "r" (fnb4_ptr)
    : "eax", "ecx"
  );
}
PCREG(451ce0, guess451ce0);

// 0x6038e0 (GUESS FUN_006038e0): cdecl, no arguments. Calls 0x634d10(0x7246a0, 0, 0xc8).
// Stores 0 at global 0x724698. Plain ret (0 arguments).
static void guess6038e0() {
  typedef void (*cdecl_fn)(u32, u32, u32);
  cdecl_fn fn = (cdecl_fn)0x634d10;
  fn(0x7246a0, 0, 0xc8);
  *(u32 *)0x724698 = 0;
}
PCREG(6038e0, guess6038e0);

// 0x4ea260 (GUESS FUN_004ea260): thiscall, one argument a, ret 4.
// Gets object at global[0x70039c]+0x9b, calls vtable[0x54] on that object with [this+4] on stack.
// Returns result if non-zero, otherwise returns a.
static u32 THISCALL guess4ea260(void *self, u32 a) {
  u8 **global_ptr = (u8 **)0x70039c;
  u8 *global = *global_ptr;
  u8 *obj = *(u8 **)(global + 0x9b);  // Dereference to get the actual object pointer

  u32 **vt = (u32 **)obj;
  u32 fn_ptr = vt[0][0x54 / 4];

  u32 arg = *(u32 *)((u8 *)self + 4);

  // Use inline assembly to preserve ECX across the thiscall vcall
  u32 r;
  asm volatile(
    "push %[arg]\n\t"
    "mov %[obj], %%ecx\n\t"
    "call *%[fn]\n\t"
    : "=a" (r)
    : [obj] "r" (obj), [arg] "r" (arg), [fn] "r" (fn_ptr)
    : "ecx"
  );

  return r ? r : a;
}
PCREG(4ea260, guess4ea260);
