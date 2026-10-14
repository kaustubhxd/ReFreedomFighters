#include "ff.h"

extern "C" {
  void __attribute__((thiscall)) ext_4670b0(u8 *);
}

// 0x4646f0: 8 insns, thiscall(param1, param2) ret 8: copy two parameters to fields
void THISCALL fn_4646f0(u8 *self, u32 param1, u32 param2) {
  *(u32 *)(self + 0x60) = param1;
  *(u32 *)(self + 0x68) = param2;
}
PCREG(4646f0, fn_4646f0);

// 0x646040: 8 insns, thiscall: check two fields, return bool
u8 THISCALL fn_646040(u8 *self) {
  if (*(u32 *)(self + 0x291) == 0 && self[0x295] == 0) {
    return 1;
  }
  return 0;
}
PCREG(646040, fn_646040);

// 0x593fd0: 9 insns, thiscall(ret 4): test bit flag, return 0 or tail jump
u32 THISCALL fn_593fd0(u8 *self) {
  if ((*(u32 *)(self + 0x417) & 0x400) != 0) {
    return 0;
  }
  ext_4670b0(self);
  return 0;
}
PCREG(593fd0, fn_593fd0);
