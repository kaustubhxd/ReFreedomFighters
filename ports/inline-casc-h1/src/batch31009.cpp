#include "ff.h"

// 0x5490f0: 3 insns, 11 bytes, test bit and conditional jump
void THISCALL fn_5490f0(void *this_ptr) {
  if (*(u8 *)((u8 *)this_ptr + 4) & 4) {
    typedef void (THISCALL *fn_type)(void *);
    ((fn_type)(void *)0x5491a0)(this_ptr);
  }
}
PCREG(5490f0, fn_5490f0);

// 0x5b0290: 3 insns, 22 bytes, stores dword and byte, tail-jumps
void THISCALL fn_5b0290(void *this_ptr) {
  *(u32 *)((u8 *)this_ptr + 0x1d91) = 0x40000000;
  *(u8 *)((u8 *)this_ptr + 0x1d8c) = 1;
  typedef void (THISCALL *fn_type)(void *);
  ((fn_type)(void *)0x5b0220)(this_ptr);
}
PCREG(5b0290, fn_5b0290);

// 0x613350: 3 insns, 11 bytes, compare != 0, return bool
u8 THISCALL fn_613350(void *this_ptr) {
  return *(u32 *)((u8 *)this_ptr + 0x22030) != 0 ? 1 : 0;
}
PCREG(613350, fn_613350);

// 0x655a60: 3 insns, 11 bytes, stores vtable, returns this, stdcall
void* STDCALL fn_655a60(void *this_ptr) {
  *(u32 *)this_ptr = 0x6c3be4;
  return this_ptr;
}
PCREG(655a60, fn_655a60);
