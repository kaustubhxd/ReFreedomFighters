#include "ff.h"

// 0x6549e0: forward two values to the current enabled engine item.
static void THISCALL fn6549e0(u8 *self, u32 a, u32 b) {
  if (self[0x80]) return;
  u8 *eng = G(u8 *, 0x70039c);
  u8 *item = vcall<u8 *>(eng, 0x1b0);
  if (!item) return;
  if (!(u8)vcall<u32>(item, 0xc)) return;
  vcall<void>(item, 0x18, a, b);
}

PCREG(6549e0, fn6549e0);
