#include "ff.h"
static u32 THISCALL fn5f40b0(u8 *self, s32 *divisor_ptr) {
  if (*(u8 *)(self + 4) == 1) {
    s32 value = *(s32 *)self;
    s32 quotient = value / *divisor_ptr;
    *(s32 *)self = quotient;
    return (u32)quotient;
  }
  u8 *global = (u8 *)*(u32 *)0x700390;
  u32 object = vcall<u32>(global, 0x20, 0x69c8e0, 0x98);
  asm volatile("movl (%0), %%edx; pushl $0x69c938; pushl $0x69c6b0; pushl %0; movl %0, %%ecx; call *0x2c(%%edx); addl $12, %%esp"
               : : "r"(object) : "eax", "ecx", "edx", "memory");
  u32 assert_fn = *(u32 *)0x7003b0;
  return ((u32 (__attribute__((cdecl)) *)(void))assert_fn)();
}
PCREG(5f40b0, fn5f40b0);
