#include "ff.h"

// 0x420060: 2 insns, 5 bytes
void STDCALL fn_420060(u32 arg1) {
  // xor eax, eax; ret 4
}
PCREG(420060, fn_420060);

// 0x44ca70: 2 insns, 11 bytes, tail jump to 0x43de70
void THISCALL fn_44ca70(void *this_ptr) {
  *(u32 *)this_ptr = 0x6801a4;
  ((void (THISCALL *)(void *))(void *)0x43de70)(this_ptr);
}
PCREG(44ca70, fn_44ca70);

// 0x466470: 2 insns, 11 bytes, clears bit 0x200000 at offset 0x136
void THISCALL fn_466470(void *this_ptr) {
  *(u32 *)((u8 *)this_ptr + 0x136) &= 0xfffdffff;
}
PCREG(466470, fn_466470);

// 0x46eaa0: 2 insns, 4 bytes, returns dword at offset 0x78
u32 THISCALL fn_46eaa0(void *this_ptr) {
  return *(u32 *)((u8 *)this_ptr + 0x78);
}
PCREG(46eaa0, fn_46eaa0);
