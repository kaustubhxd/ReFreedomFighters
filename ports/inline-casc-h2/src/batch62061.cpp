#include "ff.h"

static void THISCALL fn4f42a0(u8 *self, u8 *target) {
  vcall<void>(target, 0x3c, G(u32, self + 0x2e));
  vcall<void>(target, 0x3c, G(u32, self + 0x32));
  vcall<void>(target, 0x24, G(u32, self + 0x2a));
  vcall<void>(target, 0x24, G(u32, self + 0x36));
  vcall<void>(target, 0x24, G(u32, self + 0x3a));
}

PCREG(4f42a0, fn4f42a0);
