#include "ff.h"

// 0x5aedb0: 7 insns, 37 bytes, thiscall: zero-fill multiple fields, return self
void THISCALL fn_5aedb0(void *this_ptr) {
  *(u32 *)((u8 *)this_ptr + 0) = 0;
  *(u32 *)((u8 *)this_ptr + 4) = 0;
  *(u32 *)((u8 *)this_ptr + 8) = 0;
  *(u32 *)((u8 *)this_ptr + 0xc) = 0;
  *(u32 *)((u8 *)this_ptr + 0x10) = 0;
}
PCREG(5aedb0, fn_5aedb0);

// 0x4646f0: 8 insns, 19 bytes, thiscall setter with 2 params, ret 8
void THISCALL fn_4646f0(void *this_ptr, u32 val2, u32 val1) {
  *(u32 *)((u8 *)this_ptr + 0x68) = val1;
  *(u32 *)((u8 *)this_ptr + 0x60) = val2;
}
PCREG(4646f0, fn_4646f0);

// 0x467cd0: 8 insns, 18 bytes, thiscall: test byte, conditional tail-jump
void THISCALL fn_467cd0(void *this_ptr) {
  u8 val = *(u8 *)this_ptr;
  if (val != 0) {
    typedef void (*fn_type)();
    ((fn_type)(void *)0x465930)();
  }
}
PCREG(467cd0, fn_467cd0);

// 0x4c3280: 8 insns, 19 bytes, thiscall setter with 2 params, ret 8
void THISCALL fn_4c3280(void *this_ptr, u32 val1, u32 val2) {
  *(u32 *)((u8 *)this_ptr + 0x48) = val1;
  *(u32 *)((u8 *)this_ptr + 0x4c) = val2;
}
PCREG(4c3280, fn_4c3280);
