#include "ff.h"
extern "C" u32 THISCALL ext_534100(u8 *self, u32 index);

static void THISCALL fn5348e0(u8 *self, u8 *object, u32 index) {
  u32 value = ext_534100(self, index);
  vcall<void>(object, 0x44, value);
  if (index == 0 || index == 0x80000000u) return;
  u8 *node = self + (index + 1u) * 8u;
  if (!node) return;
  for (;;) {
    vcall<void>(object, 0x3c, G(u32, node));
    u32 next = G(u32, node + 4);
    if (next == 0 || next == 0x80000000u) return;
    node = self + 8u + next * 8u;
    if (!node) return;
  }
}
PCREG(5348e0, fn5348e0);
