#include "ff.h"

// 0x606db0: 2 insns, 4 bytes, returns dword at [ecx + 0x2f]
u32 THISCALL fn_606db0(void *this_ptr) {
  return *(u32 *)((u8 *)this_ptr + 0x2f);
}
PCREG(606db0, fn_606db0);

// 0x615ed0: 2 insns, 6 bytes, returns constant 0x55
u32 fn_615ed0() {
  return 0x55;
}
PCREG(615ed0, fn_615ed0);

// 0x63dac0: 2 insns, 6 bytes, returns constant 0x1000
u32 fn_63dac0() {
  return 0x1000;
}
PCREG(63dac0, fn_63dac0);

// 0x63ec50: 2 insns, 6 bytes, returns constant 0xff
u32 fn_63ec50() {
  return 0xff;
}
PCREG(63ec50, fn_63ec50);
