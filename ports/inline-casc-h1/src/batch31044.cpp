#include "ff.h"

// 0x471a70: 13 insns, stdcall(param) ret 4: null check dereference and compare field with constant
u8 STDCALL fn_471a70(u32 param) {
  if (param == 0) {
    return 0;
  }
  u32 ptr = *(u32 *)(param + 0xc);
  return (*(u32 *)(ptr + 0x23) == 0x1007d9) ? 1 : 0;
}
PCREG(471a70, fn_471a70);

// 0x4e54a0: 13 insns, thiscall(param) ret 4: check field sign, return 0 or dereference and add
u32 THISCALL fn_4e54a0(u8 *self, s32 param) {
  s32 field = *(s32 *)(param + 0x48);
  if (field < 0) {
    return 0;
  }
  return *(u32 *)(self + 0xc) + field;
}
PCREG(4e54a0, fn_4e54a0);
