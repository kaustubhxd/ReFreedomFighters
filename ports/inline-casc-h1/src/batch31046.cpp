#include "ff.h"

// 0x4eb060: 8 insns, thiscall(param1, param2) ret 8: copy two parameters to self at offsets 0xc and 0x10
void THISCALL fn_4eb060(u8 *self, u32 param1, u32 param2) {
  *(u32 *)(self + 0xc) = param1;
  *(u32 *)(self + 0x10) = param2;
}
PCREG(4eb060, fn_4eb060);

// 0x5c7ed0: 8 insns, thiscall: initialize fields and return this
u8 *THISCALL fn_5c7ed0(u8 *self) {
  *(u32 *)self = 0x6b48f0;
  *(u32 *)(self + 4) = 0;
  *(u32 *)(self + 9) = 0;
  *(u32 *)(self + 0x29) = 0;
  *(u32 *)(self + 0x2d) = 0;
  *(u32 *)(self + 0x31) = 0;
  return self;
}
PCREG(5c7ed0, fn_5c7ed0);

// 0x62c9b0: 8 insns, cdecl(param): initialize param fields with vtable and constants
void fn_62c9b0(u8 *param) {
  *(u32 *)param = 0x62dfa0;
  *(u32 *)(param + 0xc) = 1;
  *(u32 *)(param + 8) = 0;
}
PCREG(62c9b0, fn_62c9b0);
