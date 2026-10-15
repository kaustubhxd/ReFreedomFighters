#include "ff.h"

static void THISCALL fn4c3880(u8 *self) {
  u32 engine = G(u32, 0x70039c);
  if (!(u8)vcall<u32>((void *)engine, 0xe8, 0x20u)) return;
  u8 *table = (u8 *)G(u32, engine + 0x9b);
  u32 id = (u16)vcall<u32>((void *)table, 0x114, 0x682e18u, 0u, 0x69404cu, 0x188u);
  u8 *child = (u8 *)G(u32, self + 0x44);
  vcall<u32>((void *)child, 0x128, id, 0u, 0u);
}

PCREG(4c3880, fn4c3880);
