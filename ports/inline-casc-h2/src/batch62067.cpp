#include "ff.h"

extern "C" void THISCALL ext_43ef30(u8 *self, u32 arg1, u32 arg2, u32 arg3);

static void THISCALL fn444260(u8 *self, u32 arg1, u32 arg2, u32 arg3) {
  ext_43ef30(self, arg1, arg2, arg3);
  u32 p = G(u32, (u8 *)arg1 + 0x54);
  if (!p) return;
  u32 nested = G(u32, (u8 *)p + 0xc);
  if (G(u32, (u8 *)nested + 0x23) != 0x200015) return;
  u8 *table = (u8 *)G(u32, G(u32, 0x70039c) + 0x9b);
  u32 result = vcall<u32>(table, 0x50, arg1);
  vcall<void>(self, 0x360, result);
}

PCREG(444260, fn444260);
