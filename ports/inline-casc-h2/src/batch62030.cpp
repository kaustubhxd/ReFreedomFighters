#include "ff.h"

extern "C" void THISCALL ext_43ea20(u8 *self);
extern "C" void ext_45c510(u32 self);
extern "C" void ext_4690b0(u32 self, u32 code);

static u8 *THISCALL fn4f59a0(u8 *self, u32 flags) {
  *(u32 *)self = 0x69a370;
  ext_43ea20(self);
  if (flags & 1) {
    if (flags & 4) ext_4690b0((u32)self, 0xa0);
    else ext_45c510((u32)self);
  }
  return self;
}

PCREG(4f59a0, fn4f59a0);
