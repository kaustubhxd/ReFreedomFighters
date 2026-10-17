#include "ff.h"

// 0x54db80: 7 insns, thiscall: check field value, return conditional increment
u32 THISCALL fn_54db80(u8 *self) {
  u32 val = *(u32 *)(self + 0x40ad);
  if (val == 1) return 0;
  return val + 1;
}
PCREG(54db80, fn_54db80);

// 0x5c7ed0: 8 insns, thiscall: initialize multiple fields and return this
u8 THISCALL *fn_5c7ed0(u8 *self) {
  *(u32 *)self = 0x6b48f0;
  *(u32 *)(self + 4) = 0;
  *(u32 *)(self + 9) = 0;
  *(u32 *)(self + 0x29) = 0;
  *(u32 *)(self + 0x2d) = 0;
  *(u32 *)(self + 0x31) = 0;
  return self;
}
PCREG(5c7ed0, fn_5c7ed0);

// 0x5af0d0: 11 insns, thiscall(index_param) ret 4: bounds-checked indexed read
u32 THISCALL fn_5af0d0(u8 *self, u32 index) {
  u32 limit = *(u32 *)self;
  if (index >= limit) return 0;
  return *(u32 *)(self + index*4 + 4);
}
PCREG(5af0d0, fn_5af0d0);
