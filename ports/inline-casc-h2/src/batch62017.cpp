#include "ff.h"

static void THISCALL fn437ad0(u8 *self, u32 *items, u32 value) {
  for (u32 i = 0; i < 4; ++i) {
    u32 item = items[i];
    if (item == 0xffffffffu) break;
    vcall<void>(self, 4, item, value);
  }
}

PCREG(437ad0, fn437ad0);
