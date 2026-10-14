#include "ff.h"

// 0x473fb0: 2 insns, 11 bytes, modifies ecx and tail-jumps to 0x4666d0
u32 THISCALL fn_473fb0(void *this_ptr) {
  typedef u32 (THISCALL *fn_type)(void *);
  return ((fn_type)(void *)0x4666d0)((u8 *)this_ptr + 0x26a);
}
PCREG(473fb0, fn_473fb0);

// 0x474440: 2 insns, 7 bytes, returns lea eax, [ecx + 0x2e7]
void* THISCALL fn_474440(void *this_ptr) {
  return (u8 *)this_ptr + 0x2e7;
}
PCREG(474440, fn_474440);

// 0x478e90: 2 insns, 7 bytes, returns dword at [ecx + 0x5b2]
u32 THISCALL fn_478e90(void *this_ptr) {
  return *(u32 *)((u8 *)this_ptr + 0x5b2);
}
PCREG(478e90, fn_478e90);

// 0x490d10: 2 insns, 11 bytes, modifies ecx and tail-jumps to 0x4cc1d0
void THISCALL fn_490d10(void *this_ptr) {
  typedef void (THISCALL *fn_type)(void *);
  ((fn_type)(void *)0x4cc1d0)((u8 *)this_ptr + 0xbcd);
}
PCREG(490d10, fn_490d10);
