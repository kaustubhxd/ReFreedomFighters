#include "ff.h"

// 0x50d810: 2 insns, 6 bytes, returns constant 0x69c77c
u32 fn_50d810() {
  return 0x69c77c;
}
PCREG(50d810, fn_50d810);

// 0x52b3e0: 2 insns, 6 bytes, returns constant 1
u32 fn_52b3e0() {
  return 1;
}
PCREG(52b3e0, fn_52b3e0);

// 0x5333e0: 2 insns, 7 bytes, returns dword at [ecx + 0x546e]
u32 THISCALL fn_5333e0(void *this_ptr) {
  return *(u32 *)((u8 *)this_ptr + 0x546e);
}
PCREG(5333e0, fn_5333e0);

// 0x534cf0: 2 insns, 11 bytes, stores vtable and tail-jumps to 0x4e66a0
void THISCALL fn_534cf0(void *this_ptr) {
  *(u32 *)this_ptr = 0x6a1a60;
  typedef void (THISCALL *fn_type)(void *);
  ((fn_type)(void *)0x4e66a0)(this_ptr);
}
PCREG(534cf0, fn_534cf0);
