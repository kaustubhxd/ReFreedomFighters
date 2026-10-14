#include "ff.h"

// 0x45e900: 10 insns, thiscall(byte_param) ret 4: conditional bit set/clear
void THISCALL fn_45e900(u8 *self, u8 param) {
  if (param != 0) {
    *(u32 *)(self + 0x14) |= 0x10;
  } else {
    *(u32 *)(self + 0x14) &= 0xffffffef;
  }
}
PCREG(45e900, fn_45e900);

// 0x524660: 10 insns, thiscall: initialize structure fields
void THISCALL fn_524660(u8 *self) {
  *(u32 *)self = 0;
  *(u32 *)(self + 4) = 0;
  *(u32 *)(self + 8) = 0;
  *(u32 *)(self + 0xc) = 0x46c35000;
  *(u32 *)(self + 0x10) = 0x44fa0000;
  *(u32 *)(self + 0x14) = 0x42a00000;
  *(u32 *)(self + 0x18) = 0;
  *(u32 *)(self + 0x1c) = 0;
}
PCREG(524660, fn_524660);

// 0x533bc0: 10 insns, thiscall(dword_param) ret 4: null check, return if zero
u32 THISCALL fn_533bc0(u8 *self, u32 param) {
  if (param == 0) {
    return 0;
  }
  return param;
}
PCREG(533bc0, fn_533bc0);
