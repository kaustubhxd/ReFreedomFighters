#include "ff.h"

static u32 THISCALL fn48d060(u8 *self) {
  vcall<u32>(self, 0x124);
  vcall<u32>(self, 0xe8);
  u32 optional = G(u32, 0x7003a4);
  if (optional) vcall<u32>((void *)optional, 0x18);
  u32 result = vcall<u32>(self, 0x19c);
  u32 engine = G(u32, 0x70039c);
  u32 object = G(u32, engine + 0x1aa3);
  if (object) result = vcall<u32>((void *)object, 0x18);
  engine = G(u32, 0x70039c);
  object = G(u32, engine + 0x1a9f);
  if (object) return vcall<u32>((void *)object, 0x18);
  return result;
}

PCREG(48d060, fn48d060);
