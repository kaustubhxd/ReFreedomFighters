#include "ff.h"

extern "C" void THISCALL ext_5f04a0(u8 *self);
extern "C" void THISCALL ext_5f0540(u8 *self);

static void THISCALL fn5f05e0(u8 *self) {
  u32 sys = G(u32, 0x70039c);
  u8 *table = (u8 *)G(u32, sys + 0x1907);
  u32 first = vcall<u32>(table, 0x2c, *(u32 *)(self + 0x0c), 0);
  if (first & 0xff) ext_5f04a0(self);

  sys = G(u32, 0x70039c);
  table = (u8 *)G(u32, sys + 0x1907);
  u32 second = vcall<u32>(table, 0x2c, *(u32 *)(self + 0x10), 0);
  if (second & 0xff) ext_5f0540(self);
}

PCREG(5f05e0, fn5f05e0);
