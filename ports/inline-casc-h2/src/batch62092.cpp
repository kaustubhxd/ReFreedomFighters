#include "ff.h"
static u8 THISCALL fn549100(u8 *self, u8 *source) {
  u32 flags = *(u32 *)(self + 4) & ~0x40u;
  *(u32 *)(self + 4) = flags;
  if (flags & 4) {
    vcall<void>(source, 0x40, (u32)(self + 0x4c));
    vcall<void>(source, 0x40, (u32)(self + 0x50));
    vcall<void>(source, 0x40, (u32)(self + 0x54));
    vcall<void>(source, 0x40, (u32)(self + 0x58));
  }
  return 1;
}
PCREG(549100, fn549100);
