#include "ff.h"

// 0x61c5c0: 9 insns, 20 bytes, thiscall: 2-param setter at 0x34, 0x38
void THISCALL fn_61c5c0(void *this_ptr, u32 val1, u32 val2) {
  *(u32 *)((u8 *)this_ptr + 0x34) = val1;
  *(u32 *)((u8 *)this_ptr + 0x38) = val2;
}
PCREG(61c5c0, fn_61c5c0);

// 0x45e900: 10 insns, 25 bytes, thiscall: test param, conditional OR flag at 0x14
void THISCALL fn_45e900(void *this_ptr, u8 param) {
  if (param != 0) {
    *(u32 *)((u8 *)this_ptr + 0x14) = *(u32 *)((u8 *)this_ptr + 0x14) | 0x10;
  }
}
PCREG(45e900, fn_45e900);

// 0x524660: 10 insns, 58 bytes, thiscall: zero-fill multiple fields + const
void THISCALL fn_524660(void *this_ptr) {
  *(u32 *)((u8 *)this_ptr + 0) = 0;
  *(u32 *)((u8 *)this_ptr + 4) = 0;
  *(u32 *)((u8 *)this_ptr + 8) = 0;
  *(u32 *)((u8 *)this_ptr + 0x18) = 0;
  *(u32 *)((u8 *)this_ptr + 0x1c) = 0;
  *(u32 *)((u8 *)this_ptr + 0xc) = 0x46c35000;
}
PCREG(524660, fn_524660);

// 0x59a8d0: 10 insns, 26 bytes, thiscall: load field, test, conditional indirect jump
void THISCALL fn_59a8d0(void *this_ptr) {
  void *ecx = *(void **)((u8 *)this_ptr + 0x1d0f);
  if (ecx != 0) {
    void *eax = *(void **)ecx;
    typedef void (*fn_type)();
    ((fn_type)(*(void **)((u8 *)eax + 0)))();
  }
}
PCREG(59a8d0, fn_59a8d0);
