// batch9101.cpp - residue 6 batch 91: FUN_005228e0
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(void *self, u32 a1, u32 a2);
extern "C" void THISCALL ext_5002f0(void *self);

// 0x5228e0 (GUESS FUN_005228e0): thiscall, one argument a, ret 4.
// Loads ecx from [this+0x1c], calls vcall at [ecx][0x398],
// then calls 0x5003d0(arg, 0) and 0x5002f0(eax).
static void THISCALL guess5228e0(void *self, u32 a) {
  void *obj = *(void **)((u8 *)self + 0x1c);

  // Call vcall at [obj][0x398] with inline asm to preserve ECX
  u32 **vt = (u32 **)obj;
  u32 fn_ptr = vt[0][0x398 / 4];

  u32 vcall_result;
  asm volatile(
    "mov %[obj], %%ecx\n\t"
    "call *%[fn]\n\t"
    : "=a" (vcall_result)
    : [obj] "r" (obj), [fn] "r" (fn_ptr)
    : "ecx"
  );

  // Call 0x5003d0([a+8], 0, vcall_result)
  void *this_for_5003d0 = (void *)(*(u32 *)((u8 *)a + 8));
  u32 second_result = ext_5003d0(this_for_5003d0, 0, vcall_result);

  // Call 0x5002f0 with ecx=result from 0x5003d0
  ext_5002f0((void *)second_result);
}
PCREG(5228e0, guess5228e0);
