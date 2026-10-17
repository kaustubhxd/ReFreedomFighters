#include "ff.h"

extern "C" void ext_4670b0(void);

// 0x651010: 8 insns, 25 bytes, thiscall setter with 2 params, ret 8
void THISCALL fn_651010(void *this_ptr, u32 val1, u32 val2) {
  *(u32 *)((u8 *)this_ptr + 0x84) = val1;
  *(u32 *)((u8 *)this_ptr + 0x88) = val2;
}
PCREG(651010, fn_651010);

// 0x47fb10: 9 insns, 28 bytes, thiscall: store param at 0x8, then constants
void THISCALL fn_47fb10(void *this_ptr, u32 val) {
  *(u32 *)((u8 *)this_ptr + 0x8) = val;
  *(u32 *)((u8 *)this_ptr + 0) = 0x68b164;
  *(u32 *)((u8 *)this_ptr + 4) = 0;
}
PCREG(47fb10, fn_47fb10);

// 0x516620: 9 insns, 20 bytes, thiscall: copy 2 dwords from param to self, ret 4
void THISCALL fn_516620(void *this_ptr, void *src) {
  *(u32 *)((u8 *)this_ptr + 0) = *(u32 *)src;
  *(u32 *)((u8 *)this_ptr + 8) = *(u32 *)((u8 *)src + 8);
}
PCREG(516620, fn_516620);

// 0x593fd0: 9 insns, 27 bytes, thiscall: test flag, conditional return or tail-jump
u32 THISCALL fn_593fd0(void *this_ptr) {
  if ((*(u32 *)((u8 *)this_ptr + 0x417) & 0x400) == 0) {
    ext_4670b0();
  }
  return 0;
}
PCREG(593fd0, fn_593fd0);
