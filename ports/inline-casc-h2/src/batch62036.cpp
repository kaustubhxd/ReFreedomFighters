#include "ff.h"

extern "C" u8 *ext_41e290(u32 size);

static void THISCALL fn492820(u8 *self) {
  u32 count = *(u32 *)(self + 0xaf8);
  if (!count) {
    count = vcall<u32>(self, 0x218);
    *(u32 *)(self + 0xaf8) = count;
    if (!count || count == 0xffffffffu) {
      *(u32 *)(self + 0xaf8) = 0;
      return;
    }
  }
  if (*(u32 *)(self + 0xafc)) return;
  u8 *buffer = ext_41e290(count);
  *(u32 *)(self + 0xafc) = (u32)buffer;
  vcall<void>(self, 0x21c, (u32)buffer, count);
}

PCREG(492820, fn492820);
