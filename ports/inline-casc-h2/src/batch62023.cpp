#include "ff.h"

static u8 THISCALL fn537e00(u8 *self, u32 value) {
  u8 *first = vcall<u8 *>(self, 0x40, value);
  if (!first) return 0;
  u8 *result = vcall<u8 *>(self, 0x1dc, first);
  return result ? (*(u8 *)(result + 8) & 1) : 0;
}

PCREG(537e00, fn537e00);
