#include "ff.h"

// 0x4d5570: 2 insns, 7 bytes, stores vtable 0x6967bc and returns
void THISCALL fn_4d5570(void *this_ptr) {
  *(u32 *)this_ptr = 0x6967bc;
}
PCREG(4d5570, fn_4d5570);

// 0x4f3c30: 2 insns, 11 bytes, stores vtable and tail-jumps to 0x43ea20
void THISCALL fn_4f3c30(void *this_ptr) {
  *(u32 *)this_ptr = 0x69909c;
  typedef void (THISCALL *fn_type)(void *);
  ((fn_type)(void *)0x43ea20)(this_ptr);
}
PCREG(4f3c30, fn_4f3c30);

// 0x4f5990: 2 insns, 11 bytes, stores vtable and tail-jumps to 0x43ea20
void THISCALL fn_4f5990(void *this_ptr) {
  *(u32 *)this_ptr = 0x69a370;
  typedef void (THISCALL *fn_type)(void *);
  ((fn_type)(void *)0x43ea20)(this_ptr);
}
PCREG(4f5990, fn_4f5990);

// 0x4f9f40: 2 insns, 7 bytes, returns dword at [ecx + 0x8f]
u32 THISCALL fn_4f9f40(void *this_ptr) {
  return *(u32 *)((u8 *)this_ptr + 0x8f);
}
PCREG(4f9f40, fn_4f9f40);
