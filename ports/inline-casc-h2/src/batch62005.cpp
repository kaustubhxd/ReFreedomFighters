#include "ff.h"

// 0x4a0d00, thiscall() plain ret: lazily asks the owner at +0x44 to populate
// this+0x102; if the out field stays null, points it at the embedded record.
static void THISCALL fn4a0d00(u8 *self) {
  u8 **out = (u8 **)(self + 0x102);
  if (*out) return;
  u8 *owner = *(u8 **)(self + 0x44);
  vcall<void>(owner, 0x128, (u32)G(u16, 0x7002ac), out, owner);
  if (!*out) {
    self[0x5e] = 1;
    *out = self + 0x7e;
  }
}

PCREG(4a0d00, fn4a0d00);
