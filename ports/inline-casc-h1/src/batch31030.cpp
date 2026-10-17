#include "ff.h"

// 0x4619c0: 9 insns, thiscall(param) ret 4: indexed byte read with bit extraction
u8 THISCALL fn_4619c0(u8 *self, u32 param) {
  u32 idx = param + param*2;  // param*3
  u8 *table = *(u8 **)(self + 0x1c);
  return *(u8 *)(table + idx*8 + 4) & 1;
}
PCREG(4619c0, fn_4619c0);

// 0x54e1c0: 11 insns, thiscall: no-frame conditional logic
u8 THISCALL fn_54e1c0(u8 *self) {
  if (*(u32 *)(self + 0x5b) != 0 && self[0x57] == 0) {
    return 0;
  }
  if (self[0x1d] != 0) {
    self[0x1d] = 0;
    return 1;
  }
  return 0;
}
PCREG(54e1c0, fn_54e1c0);

// 0x5af0d0: 11 insns, thiscall(param) ret 4: bounds check with indexed read
u32 THISCALL fn_5af0d0(u8 *self, u32 param) {
  u32 limit = *(u32 *)self;
  if (param >= limit) return 0;
  return *(u32 *)(self + param*4 + 4);
}
PCREG(5af0d0, fn_5af0d0);

// 0x4cf1c0: 13 insns, thiscall(ptr_param) ret 4: conditional copy with pointer check
void THISCALL fn_4cf1c0(u8 *self, u32 *param) {
  param[2] = 0xffffffff;
  param[0] = *(u32 *)(self + 8);
  u8 *ptr = *(u8 **)(self + 8);
  if (ptr != 0) {
    param[1] = *(u32 *)(ptr + 8);
  }
}
PCREG(4cf1c0, fn_4cf1c0);

// 0x52b370: 13 insns, thiscall(param) ret 4: null check with calculated offset
u32 THISCALL fn_52b370(u8 *self, u32 param) {
  if (param == 0) return 0;
  u32 base = *(u32 *)(self + 0x7d);
  return base + param*8 - 8;
}
PCREG(52b370, fn_52b370);
