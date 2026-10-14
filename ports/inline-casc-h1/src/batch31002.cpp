#include "ff.h"

// 0x46e720: 2 insns, 6 bytes, returns constant 0x686504
u32 fn_46e720() {
  return 0x686504;
}
PCREG(46e720, fn_46e720);

// 0x46ee00: 2 insns, 7 bytes, returns dword at [ecx+0x80]
u32 THISCALL fn_46ee00(void *this_ptr) {
  return *(u32 *)((u8 *)this_ptr + 0x80);
}
PCREG(46ee00, fn_46ee00);

// 0x46efa0: 2 insns, 7 bytes, returns dword at [ecx+0xd5]
u32 THISCALL fn_46efa0(void *this_ptr) {
  return *(u32 *)((u8 *)this_ptr + 0xd5);
}
PCREG(46efa0, fn_46efa0);

// 0x46efe0: 2 insns, 7 bytes, returns byte at [ecx+0xc6]
u8 THISCALL fn_46efe0(void *this_ptr) {
  return *(u8 *)((u8 *)this_ptr + 0xc6);
}
PCREG(46efe0, fn_46efe0);
