// vcall_cc.h - area 66 only (not the shared ff.h). Calls a function at [vt + off] with ECX = vt and three stack arguments that the CALLER
// removes (add esp,12), as the logger error paths in the exe do (mov ecx,[obj]; push ...; call [ecx+off]; add esp,0xc).
#pragma once
#include "ff.h"

static inline void call_cc3(u32 vt, u32 off, u32 a, u32 b, u32 c) {
  asm volatile(
      "pushl %[c]\n\t"
      "pushl %[b]\n\t"
      "pushl %[a]\n\t"
      "call *%c[off](%%ecx)\n\t"
      "addl $12, %%esp\n\t"
      :
      : "c"(vt), [a] "r"(a), [b] "r"(b), [c] "r"(c), [off] "i"(off)
      : "eax", "edx", "memory", "cc");
}

// Two stack arguments, caller-cleaned (add esp,8), ECX = vt, returns eax (the 0x2c logger call of 0x50f5b0, 0x50f610 and 0x50ff20).
static inline u32 call_cc2(u32 vt, u32 off, u32 a, u32 b) {
  u32 res;
  asm volatile(
      "pushl %[b]\n\t"
      "pushl %[a]\n\t"
      "call *%c[off](%%ecx)\n\t"
      "addl $8, %%esp\n\t"
      : "=a"(res)
      : "c"(vt), [a] "r"(a), [b] "r"(b), [off] "i"(off)
      : "edx", "memory", "cc");
  return res;
}
