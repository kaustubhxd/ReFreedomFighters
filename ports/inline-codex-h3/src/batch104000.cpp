#include "ff.h"
static u8 THISCALL serialize_effect_fields(u8* s, u8* out) {
  G(u32, s + 4) &= ~0x40u;
  vcall<u32>(out, 0x64, G(u32, s + 0x48));
  vcall<u32>(out, 0x3c, G(u32, s + 0x56));
  vcall<u32>(out, 0x60, (u32)G(u8, s + 0x5a));
  vcall<u32>(out, 0x4c, G(float, s + 0x5b));
  vcall<u32>(out, 0x64, G(u32, s + 0x63));
  vcall<u32>(out, 0x64, G(u32, s + 0x6b));
  u8* table = G(u8*, (u8*)g_pSysInterface + 0x9b);
  u8* sys = vcall<u8*>(table, 0x138);
  u32 result = 0;
  vcall<u32>(sys, 0x88, 0x6b52cc, &result);
  vcall<u32>(out, 0x3c, result);
  return 1;
}
PCREG(5d4840, serialize_effect_fields);
