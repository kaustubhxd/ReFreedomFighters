#include "ff.h"

// 0x64fc20: 9 insns, thiscall(param) ret 4: copy two dwords from self fields to param
void THISCALL fn_64fc20(u8 *self, u32 *param) {
  param[0] = *(u32 *)(self + 0x60);
  param[1] = *(u32 *)(self + 0x64);
}
PCREG(64fc20, fn_64fc20);

// 0x533500: 11 insns, thiscall(param) ret 4: check field, return 0 or indexed dword
u32 THISCALL fn_533500(u8 *self, u32 param) {
  if (*(u32 *)(self + 0x546e) == 0) {
    return 0;
  }
  return *(u32 *)(self + param*4 + 0x5462);
}
PCREG(533500, fn_533500);

extern "C" {
  void __attribute__((stdcall)) ext_5138f0(u32);
}

// 0x514480: 10 insns, thiscall(param) ret 4: compare param with self field, tail jump if different
void THISCALL fn_514480(u8 *self, u32 param) {
  if (param == *(u32 *)self) {
    return;
  }
  ext_5138f0(param);
}
PCREG(514480, fn_514480);
