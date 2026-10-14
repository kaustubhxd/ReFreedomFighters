#include "ff.h"

// 0x54ba10: 2 insns, 7 bytes, returns byte at [ecx + 0xa273]
u8 THISCALL fn_54ba10(void *this_ptr) {
  return *(u8 *)((u8 *)this_ptr + 0xa273);
}
PCREG(54ba10, fn_54ba10);

// 0x59ad30: 2 insns, 11 bytes, adds offset and tail-jumps to 0x4cd0e0
void THISCALL fn_59ad30(void *this_ptr) {
  typedef void (THISCALL *fn_type)(void *);
  ((fn_type)(void *)0x4cd0e0)((u8 *)this_ptr + 0x1218c);
}
PCREG(59ad30, fn_59ad30);

// 0x59b3b0: 2 insns, 7 bytes, returns lea eax, [ecx + 0x121b0]
void* THISCALL fn_59b3b0(void *this_ptr) {
  return (u8 *)this_ptr + 0x121b0;
}
PCREG(59b3b0, fn_59b3b0);

// 0x5ab4b0: 2 insns, 7 bytes, stores vtable 0x6b01dc and returns
void THISCALL fn_5ab4b0(void *this_ptr) {
  *(u32 *)this_ptr = 0x6b01dc;
}
PCREG(5ab4b0, fn_5ab4b0);
