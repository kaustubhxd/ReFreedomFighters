#include "ff.h"

static u32 THISCALL fn539850(u8 *self, u32 value) {
  if (!G(u8, self + 0x50ba)) return 0;
  while (!((u8)vcall<u32>(self, 0x19c))) {}
  u8 *cursor = (u8 *)G(u32, self + 0x51a5);
  G(u32, self + 0x51a9) = (u32)cursor;
  G(u32, cursor) = value;
  G(u32, cursor + 4) = 8;
  cursor += 8;
  G(u32, self + 0x51a9) = (u32)cursor;
  G(u32, cursor + 4) = 8;
  G(u32, cursor) = 0x10000;
  return vcall<u32>(self, 0x164);
}

PCREG(539850, fn539850);
