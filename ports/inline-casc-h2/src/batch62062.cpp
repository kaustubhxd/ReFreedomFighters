#include "ff.h"

static u8 *FASTCALL fn511c20(u8 *self, u32 *items) {
  vcall<void>(self, 0x3c, items[0]);
  for (u32 i = 0; i < items[0]; ++i) vcall<void>(self, 0x64, items[i + 1]);
  return self;
}

PCREG(511c20, fn511c20);
