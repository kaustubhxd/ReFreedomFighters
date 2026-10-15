#include "ff.h"

extern "C" void THISCALL ext_4cbec0(u8 *member);
extern "C" void THISCALL ext_42bae0(u8 *self);
extern "C" void __attribute__((cdecl)) ext_634273(u8 *object, u32 tag);

static u32 THISCALL fn42a7b0(u8 *self, u32 flags) {
  const u32 first[] = {0x1e0b, 0x1d71, 0x1cf1, 0x1c71, 0x1bf1, 0x1b71};
  for (u32 off : first) ext_4cbec0(self + off);
  ext_42bae0(self);
  if (flags & 1) ext_634273(self, 0x1e8b);
  return (u32)self;
}

PCREG(42a7b0, fn42a7b0);
