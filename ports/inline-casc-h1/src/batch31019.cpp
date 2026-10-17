#include "ff.h"

// 0x4eb060: 8 insns, 19 bytes, thiscall setter with 2 params, ret 8
void THISCALL fn_4eb060(void *this_ptr, u32 val1, u32 val2) {
  *(u32 *)((u8 *)this_ptr + 0xc) = val1;
  *(u32 *)((u8 *)this_ptr + 0x10) = val2;
}
PCREG(4eb060, fn_4eb060);

// 0x5398d0: 8 insns, 23 bytes, thiscall: complex lea with param, store
void THISCALL fn_5398d0(void *this_ptr, u32 val, u32 idx) {
  *(u32 *)((u8 *)this_ptr + val * 9 + 0x515e) = idx;
}
PCREG(5398d0, fn_5398d0);

// 0x5c7ed0: 8 insns, 44 bytes, thiscall: multi-field store with constants
void THISCALL fn_5c7ed0(void *this_ptr) {
  *(u32 *)((u8 *)this_ptr + 0) = 0x6b48f0;
  *(u32 *)((u8 *)this_ptr + 4) = 0;
  *(u32 *)((u8 *)this_ptr + 9) = 0;
  *(u32 *)((u8 *)this_ptr + 0x29) = 0;
  *(u32 *)((u8 *)this_ptr + 0x2d) = 0;
  *(u32 *)((u8 *)this_ptr + 0x31) = 0;
}
PCREG(5c7ed0, fn_5c7ed0);

// 0x638c90: 8 insns, 19 bytes, thiscall: lea chain for array indexing, ret 4
u32 THISCALL fn_638c90(void *this_ptr, u32 idx) {
  u32 edx = idx + idx * 4;
  void *eax = *(void **)((u8 *)this_ptr + 0x14);
  return (u32)((u8 *)eax + edx * 4);
}
PCREG(638c90, fn_638c90);
