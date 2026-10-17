#include "ff.h"

// 0x45fa00: 17 insns, thiscall(param) ret 4: conditional bit operations on field
void THISCALL fn_45fa00(u8 *self, u8 param) {
  u32 field = *(u32 *)(self + 0x14);
  if (param == 0) {
    if ((field & 8) == 0) {
      return;
    }
    *(u32 *)(self + 0x14) = field & 0xfffffff7;
  } else {
    if ((field & 8) != 0) {
      return;
    }
    *(u32 *)(self + 0x14) = field | 9;
  }
}
PCREG(45fa00, fn_45fa00);
