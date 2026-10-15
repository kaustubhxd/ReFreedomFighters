#include "ff.h"
static u32 THISCALL fn5d8c90(u8 *dest, u8 *source) {
  vcall<void>(dest, 0x48, (u32)source);
  u32 allowed = vcall<u32>(source, 0x1e0, 0x20044cu);
  if (allowed & 0xff) {
    for (u32 off = 0x18; off <= 0x30; off += 4) G(u32, dest + off) = G(u32, source + off);
  }
  return allowed & 0xff ? G(u32, source + 0x30) : allowed;
}
PCREG(5d8c90, fn5d8c90);
