#include "ff.h"

extern "C" u32 THISCALL ext_4db520(u8 *item);
static void THISCALL fn4faa00(u8 *self, u32 value) {
  if (*(u32 *)(self + 0x6c) == 0) return;
  u8 *item = (u8 *)*(u32 *)(self + 0x54);
  while (item) {
    u32 flags;
    u32 nested = *(u32 *)(item + 0x54);
    if (nested) flags = *(u32 *)(*(u32 *)(nested + 0xc) + 0x23);
    else flags = 0x200002;
    if (flags & 0x100000) return;
    vcall<void>(self, 0x2f0, value, item);
    item = (u8 *)ext_4db520(item);
  }
}
PCREG(4faa00, fn4faa00);
