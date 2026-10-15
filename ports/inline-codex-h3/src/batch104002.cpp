#include "ff.h"
static float THISCALL select_and_advance_resource(u8* self, u32* out, u32, u32, u32, u32) {
  u8* entity = G(u8*, self + 4);
  *out = 0;
  u32 flags = G(u32, entity + 0x417);
  if (flags & 0x800) {
    u8* got = (u8*)vcall<u32>(self + 0xf5, 0x14, G(float, self + 0xc));
    if (got) *out = G(u32, got);
  } else if (!vcall<u8>(entity, 0x534) && (flags & 0x400)) {
    u8* got = (u8*)vcall<u32>(self + 0x10d, 0x14, G(float, self + 0xc));
    if (got) *out = G(u32, got);
  } else {
    u8* got = (u8*)vcall<u32>(self + 0xdd, 0x14, G(float, self + 0xc));
    if (got) *out = G(u32, got);
  }
  float next = vcall<float>(self + 0xdd, 0xc, G(float, self + 0xc));
  G(float, self + 0xc) = next;
  vcall<void>(self + 0xdd, 4);
  return G(float, self + 0xc);
}
PCREG(488900, select_and_advance_resource);
