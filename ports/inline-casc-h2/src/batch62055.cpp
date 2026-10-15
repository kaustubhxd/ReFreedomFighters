#include "ff.h"

extern "C" void THISCALL ext_5aedb0(u8 *self);
extern "C" void THISCALL ext_65e090(u8 *self);
extern "C" void THISCALL ext_5af2a0(u8 *self, u32 key, u32 value);

static u32 THISCALL fn5afc10(u8 *self) {
  ext_5aedb0(self);
  ext_65e090(self + 0x18);
  ext_5af2a0(self, 0x0d, 0x0a);
  ext_5af2a0(self, 0x0c, 0x0a);
  ext_5af2a0(self, 0x0e, 4);
  ext_5af2a0(self, 0x10, 8);
  ext_5af2a0(self, 0x0f, 1);
  G(u32, self + 0x14) = 0;
  return (u32)self;
}

PCREG(5afc10, fn5afc10);
