#include "ff.h"

// 0x4666d0: 2 insns, 4 bytes, returns dword at [ecx+0x39]
u32 THISCALL fn_4666d0(void *this_ptr) {
  return *(u32 *)((u8 *)this_ptr + 0x39);
}
PCREG(4666d0, fn_4666d0);

// 0x468a20: 2 insns, 4 bytes, returns byte at [ecx+0x52]
u8 THISCALL fn_468a20(void *this_ptr) {
  return *(u8 *)((u8 *)this_ptr + 0x52);
}
PCREG(468a20, fn_468a20);

// 0x46e680: 2 insns, 7 bytes, returns dword at [ecx+0x94]
u32 THISCALL fn_46e680(void *this_ptr) {
  return *(u32 *)((u8 *)this_ptr + 0x94);
}
PCREG(46e680, fn_46e680);

// 0x46e6f0: 2 insns, 4 bytes, returns dword at [ecx+0x64]
u32 THISCALL fn_46e6f0(void *this_ptr) {
  return *(u32 *)((u8 *)this_ptr + 0x64);
}
PCREG(46e6f0, fn_46e6f0);
