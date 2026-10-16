#include "ff.h"

static u32 THISCALL fn638610(u8 *self) {
  u32 length = 0x1d;
  u8 *s = (u8 *)G(u32, self + 0x18);
  if (s) {
    while (s[length - 0x1d]) ++length;
  }
  u32 i = 0;
  u32 count = vcall<u32>(self, 0x34);
  while (i < count) {
    u8 *item = (u8 *)vcall<u32>(self, 0x38, i);
    length += G(u32, item) + 4;
    ++i;
    count = vcall<u32>(self, 0x34);
  }
  return length;
}
PCREG(638610, fn638610);
