#include "ff.h"

extern "C" u32 THISCALL ext_4e5e60(u8 *parser);

static u32 THISCALL fn548ef0(u8 *self, u8 *parser) {
  G(u32, self + 0x4c) = ext_4e5e60(parser);
  G(u32, self + 0x50) = ext_4e5e60(parser);
  G(u32, self + 0x54) = ext_4e5e60(parser);
  G(u32, self + 0x58) = 0;
  u32 ptr = G(u32, parser);
  u8 code = G(u8, ptr);
  if (code != 0xff && (code & 0x3f) == 0xb) {
    u32 result = ext_4e5e60(parser);
    G(u32, self + 0x58) = result;
    return result;
  }
  return (ptr & 0xffffff00u) | code;
}

PCREG(548ef0, fn548ef0);
