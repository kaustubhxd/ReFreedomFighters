#include "ff.h"

// 0x589fd0: 13 insns, thiscall(param) ret 4: conditional return or calculate offset
u32 THISCALL fn_589fd0(u8 *self, s32 param) {
  if (param == -1) return 0;
  return param * 0xf4 + 0xd91 + (u32)self;
}
PCREG(589fd0, fn_589fd0);

// 0x5eec40: 13 insns, thiscall: initialize object fields
u8 THISCALL *fn_5eec40(u8 *self) {
  *(u32 *)self = 0x6b8190;
  *(u32 *)(self + 4) = 0;
  *(u32 *)(self + 8) = 0;
  *(u32 *)(self + 0xc) = 0;
  self[0x10] = 0;
  return self;
}
PCREG(5eec40, fn_5eec40);
