#include "ff.h"
extern "C" u8 THISCALL ext_466dc0(u8 *self, u8 *arg);
static u8 THISCALL fn468220(u8 *self, u8 *arg) {
  if (!ext_466dc0(self, arg)) return 0;
  vcall<void>(arg, 0x18, (u32)(self + 0x1d2), 4);
  vcall<void>(arg, 0x40, (u32)(self + 0x1d6));
  vcall<void>(arg, 0x50, (u32)(self + 0x1da));
  return 1;
}
PCREG(468220, fn468220);
