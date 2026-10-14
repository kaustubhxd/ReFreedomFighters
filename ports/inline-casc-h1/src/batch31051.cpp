#include "ff.h"

// 0x5df690: 17 insns, thiscall(param1, param2, param3, param4) ret 0x10: copy four parameters and init vtable
u8 *THISCALL fn_5df690(u8 *self, u32 param1, u32 param2, u32 param3, u32 param4) {
  *(u32 *)(self + 4) = param1;
  *(u32 *)(self + 8) = param2;
  *(u32 *)(self + 0xc) = param3;
  *(u32 *)(self + 0x10) = param4;
  *(u32 *)self = 0x6b7400;
  return self;
}
PCREG(5df690, fn_5df690);
