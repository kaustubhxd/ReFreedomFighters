#include "ff.h"
static void THISCALL fn4f4d80(u8 *self, u32 ignored) {
  if (G(u32, self + 0x70) == 0x20) return;
  if (G(u32, self + 0x8f) != 1) vcall<void>(self, 0x2ec, 2u);
  u32 a = vcall<u32>(self, 0x2c4);
  vcall<void>((void *)a, 0x2ec, (u32)self);
  u32 b = vcall<u32>(self, 0x2c4);
  vcall<void>((void *)b, 0x34c, 0x10u, 1u, (u32)self, 0x41200000u, 1u);
}
PCREG(4f4d80, fn4f4d80);
