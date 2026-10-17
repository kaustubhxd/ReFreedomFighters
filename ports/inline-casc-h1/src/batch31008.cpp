#include "ff.h"

// 0x64c750: 2 insns, 6 bytes, returns constant 0x7f
u32 fn_64c750() {
  return 0x7f;
}
PCREG(64c750, fn_64c750);

// 0x64fb70: 2 insns, 7 bytes, returns dword at [ecx + 0x8c]
u32 THISCALL fn_64fb70(void *this_ptr) {
  return *(u32 *)((u8 *)this_ptr + 0x8c);
}
PCREG(64fb70, fn_64fb70);

// 0x429b00: 3 insns, 7 bytes, stores 0 at [ecx+0x75], returns 1
u8 THISCALL fn_429b00(void *this_ptr) {
  *(u8 *)((u8 *)this_ptr + 0x75) = 0;
  return 1;
}
PCREG(429b00, fn_429b00);

// 0x46f500: 3 insns, 11 bytes, compare >= 5, return bool
u8 THISCALL fn_46f500(void *this_ptr) {
  return *(u32 *)((u8 *)this_ptr + 0x8c) >= 5 ? 1 : 0;
}
PCREG(46f500, fn_46f500);
