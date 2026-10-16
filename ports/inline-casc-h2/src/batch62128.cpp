#include "ff.h"
extern "C" u32 STDCALL ext_43ed60(u32 a, u32 b, u32 c, u32 d, u32 e);

static u32 STDCALL fn43ea70(u32 a, u32 b, u32 c, u32 d, u32 e) {
  u8 *sys = G(u8 *, 0x70039c);
  u8 *table = (u8 *)G(u32, sys + 0x9b);
  u32 current = G(u32, table + 0x14);
  u8 *resource = (u8 *)vcall<u32>(table, 0x58, current);
  if (!resource) {
    u8 *manager = (u8 *)G(u32, table + 0xadc);
    resource = (u8 *)vcall<u32>(manager, 0x294, 0x67c7fcu, 0x67cd24u, 1u, 1u);
    u32 replacement = vcall<u32>(table, 0x4c, resource);
    G(u32, table + 0x14) = replacement;
  }
  return ext_43ed60(a, b, c, d, e);
}
PCREG(43ea70, fn43ea70);
