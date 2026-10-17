#include "ff.h"

// 0x4619c0: 9 insns, thiscall(param) ret 4: indexed byte read and bit extraction
u8 THISCALL fn_4619c0(u8 *self, u32 param) {
  u32 offset = param * 3;
  u8 *base = *(u8 **)(self + 0x1c);
  u8 byte_val = base[offset * 8 + 4];
  return byte_val & 1;
}
PCREG(4619c0, fn_4619c0);
