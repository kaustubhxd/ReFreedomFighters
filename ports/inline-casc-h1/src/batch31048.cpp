#include "ff.h"

// 0x537e70: 13 insns, thiscall(param) ret 4: check param, conditional byte write
u8 THISCALL fn_537e70(u8 *self, u32 param) {
  if (param >= 4) {
    return 0;
  }
  self[param * 0xd + 0x15] = 0;
  return 1;
}
PCREG(537e70, fn_537e70);

// 0x5eec40: 13 insns, thiscall: initialize fields with vtable and zeros, return this
u8 *THISCALL fn_5eec40(u8 *self) {
  *(u32 *)self = 0x6b8190;
  *(u32 *)(self + 4) = 0;
  *(u32 *)(self + 8) = 0;
  *(u32 *)(self + 0xc) = 0;
  self[0x10] = 0;
  return self;
}
PCREG(5eec40, fn_5eec40);

// 0x4c62c0: 15 insns, thiscall(param1, param2) ret 4: check word field and conditionally copy value
u32 THISCALL fn_4c62c0(u8 *self, u16 param1, u32 *param2) {
  u16 field = *(u16 *)(self + 0x48);
  if (field == 0 || param1 != field || param2 == 0) {
    return 0;
  }
  *param2 = *(u32 *)(self + 0x4a);
  return 0;
}
PCREG(4c62c0, fn_4c62c0);
