#include "ff.h"

extern "C" void THISCALL ext_480fd0(u8 *embedded);
extern "C" void THISCALL ext_4878d0(u8 *self);
extern "C" void ext_634273(u32 self, u32 tag);

// 0x5e1450: initialize the object and its embedded members, then optionally
// issue the tagged cleanup callback.
static u8 *THISCALL fn5e1450(u8 *self, u32 flags) {
  *(u32 *)self = 0x6b79d0;
  ext_480fd0(self + 0x523);
  ext_480fd0(self + 0x4ab);
  ext_480fd0(self + 0x3eb);
  ext_480fd0(self + 0x3d3);
  ext_4878d0(self);
  if (flags & 1) ext_634273((u32)self, 0x5fd);
  return self;
}

PCREG(5e1450, fn5e1450);
