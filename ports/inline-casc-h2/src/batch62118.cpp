#include "ff.h"
extern "C" u32 THISCALL ext_462d10(u8 *self, u32 a, u32 b, u32 c);
static u8 THISCALL fn591980(u8 *self, u32 a, u32 b, u32 c) {
  if (!G(u8, self + 0x67f)) return (u8)ext_462d10(self, a, b, c);
  u8 *sys = G(u8 *, 0x70039c);
  u8 *service = G(u8 *, sys + 0x190f);
  u32 id = vcall<u32>(service, 0xb4, 0u);
  u8 *table = G(u8 *, sys + 0x9b);
  u8 *resource = (u8 *)vcall<u32>(table, 0x58, id);
  vcall<void>(resource, 0x80, b, c);
  vcall<void>(self, 0x94, b, c);
  return 1;
}
PCREG(591980, fn591980);
