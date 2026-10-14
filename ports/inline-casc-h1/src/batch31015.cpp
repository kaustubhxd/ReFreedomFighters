#include "ff.h"

// 0x53b6d0: 6 insns, 51 bytes, thiscall: store multiple fields with constants
void THISCALL fn_53b6d0(void *this_ptr) {
  *(u32 *)((u8 *)this_ptr + 0xee) = 1;
  *(u32 *)((u8 *)this_ptr + 0xf2) = 0x12345678;
  *(u32 *)((u8 *)this_ptr + 0xf6) = 3;
  *(u32 *)((u8 *)this_ptr + 0xce) = 0x12345678;
  *(u32 *)((u8 *)this_ptr + 0xc5) = 1;
}
PCREG(53b6d0, fn_53b6d0);

// 0x5eeb90: 6 insns, 13 bytes, thiscall setter: store dword param at [ecx+0x4e], ret 4
void THISCALL fn_5eeb90(void *this_ptr, u32 val) {
  *(u32 *)((u8 *)this_ptr + 0x4e) = val;
}
PCREG(5eeb90, fn_5eeb90);

// 0x5f1bc0: 6 insns, 15 bytes, thiscall: chained loads then tail-jump to 0x5fbac0
void THISCALL fn_5f1bc0(void *this_ptr) {
  void *ecx = *(void **)((u8 *)this_ptr + 0xc);
  ecx = *(void **)((u8 *)ecx + 4);
  typedef void (*fn_type)();
  ((fn_type)(void *)0x5fbac0)();
}
PCREG(5f1bc0, fn_5f1bc0);

// 0x5f2e90: 6 insns, 12 bytes, thiscall: chained loads then indirect jump through [eax+0x50]
void THISCALL fn_5f2e90(void *this_ptr) {
  void *ecx = *(void **)((u8 *)this_ptr + 0x15);
  void *eax = *(void **)ecx;
  typedef void (*fn_type)();
  ((fn_type)(*(void **)((u8 *)eax + 0x50)))();
}
PCREG(5f2e90, fn_5f2e90);
