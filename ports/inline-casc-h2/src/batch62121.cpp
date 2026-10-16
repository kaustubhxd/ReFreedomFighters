#include "ff.h"
static void THISCALL fn641bd0(u8 *self) {
  u8 *sys = G(u8 *, 0x70039c);
  u32 p = G(u32, self + 0x1d);
  vcall<void>(sys, 0x1a8, p);
  if (p) vcall<void>((void *)p, 0, 1u);
  G(u32, self + 0x1d) = 0;
  p = G(u32, self + 0x15);
  vcall<void>(sys, 0x1a8, p);
  if (p) vcall<void>((void *)p, 0, 1u);
  G(u32, self + 0x15) = 0;
  p = G(u32, self + 0x19);
  vcall<void>(sys, 0x1a8, p);
  if (p) vcall<void>((void *)p, 0, 1u);
  G(u32, self + 0x19) = 0;
}
PCREG(641bd0, fn641bd0);
