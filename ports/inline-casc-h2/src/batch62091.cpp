#include "ff.h"
static void THISCALL fn4e7480(u8 *self, u8 *object) {
  vcall<void>(object, 0x6c, (u32)self);
  vcall<void>(object, 0x50, (u32)(self + 0xc));
  vcall<void>(object, 0x6c, (u32)(self + 0x10));
  vcall<void>(object, 0x6c, (u32)(self + 0x1c));
  vcall<void>(object, 0x50, (u32)(self + 0x28));
}
PCREG(4e7480, fn4e7480);
