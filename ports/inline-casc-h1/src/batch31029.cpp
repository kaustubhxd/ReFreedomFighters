#include "ff.h"

// 0x533bc0: 10 insns, thiscall(ptr_param) ret 4: null check, return 0 or [param+0x10]
u32 THISCALL fn_533bc0(u8 *self, u8 *param) {
  if (param == 0) return 0;
  return *(u32 *)(param + 0x10);
}
PCREG(533bc0, fn_533bc0);

// 0x5b04a0: 10 insns, thiscall(ptr1, ptr2) ret 8: copy [ecx+8] to [ptr1], [ecx+0x10] to [ptr2]
void THISCALL fn_5b04a0(u8 *self, u32 *ptr1, u32 *ptr2) {
  *ptr1 = *(u32 *)(self + 8);
  *ptr2 = *(u32 *)(self + 0x10);
}
PCREG(5b04a0, fn_5b04a0);

// 0x516230: 11 insns, thiscall(ptr_param) ret 4: copy three dwords [ecx+0/0x41/8] to [param+0/4/8]
void THISCALL fn_516230(u8 *self, u32 *param) {
  param[0] = *(u32 *)self;
  param[1] = *(u32 *)(self + 0x41);
  param[2] = *(u32 *)(self + 8);
}
PCREG(516230, fn_516230);

// 0x4dc600: 12 insns, thiscall(ptr_param) ret 0: copy three dwords and set flag bit
void THISCALL fn_4dc600(u8 *self, u32 *param) {
  *(u32 *)(self + 0x30) = param[0];
  *(u32 *)(self + 0x34) = param[1];
  *(u32 *)(self + 0x38) = param[2];
  *(u32 *)(self + 0x3c) |= 0x100000;
}
PCREG(4dc600, fn_4dc600);

// 0x471a10: 13 insns, thiscall(ptr_param) ret 4: null check, then compare [*[param+0xc]+0x23] with 0x1007d3
u8 THISCALL fn_471a10(u8 *self, u8 *param) {
  if (param == 0) return 0;
  u8 *ptr = *(u8 **)(param + 0xc);
  return (*(u32 *)(ptr + 0x23) == 0x1007d3) ? 1 : 0;
}
PCREG(471a10, fn_471a10);
