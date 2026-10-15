#include "ff.h"
static u32 THISCALL fn4f4020(u8 *self, u8 *desc) {
  u32 selector = *(u32 *)(desc + 4);
  if (selector == 0x100 || selector == 0x200) {
    u32 enabled = *(u32 *)(desc + 0xc) != 0;
    u32 value = *(u32 *)(desc + 8);
    return selector == 0x100
      ? vcall<u32>(self, 0x2d8, value, enabled)
      : vcall<u32>(self, 0x2dc, value, enabled);
  }
  return selector & 0xffffff00;
}
PCREG(4f4020, fn4f4020);
