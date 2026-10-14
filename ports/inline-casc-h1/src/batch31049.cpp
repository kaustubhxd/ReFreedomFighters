#include "ff.h"

// 0x5df720: 15 insns, thiscall(param1, param2, param3): copy three parameters to self fields, init vtable
u8 *THISCALL fn_5df720(u8 *self, u32 param1, u32 param2, u32 param3) {
  *(u32 *)(self + 4) = param1;
  *(u32 *)(self + 8) = param2;
  *(u32 *)(self + 0xc) = param3;
  *(u32 *)self = 0x6b7360;
  return self;
}
PCREG(5df720, fn_5df720);
