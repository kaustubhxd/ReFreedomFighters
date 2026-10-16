#include "ff.h"
extern "C" void ext_634273(u32 value, u32 flag);
extern "C" void THISCALL ext_43de70(u8 *self);
extern "C" void THISCALL ext_45c510(u8 *self);
extern "C" void ext_4690b0(u32 flags, u32 self);
static u8 * THISCALL fn5d57c0(u8 *self, u32 flags) {
  G(u32, self) = 0x6b5610;
  u8 *old = (u8 *)G(u32, self + 0x19);
  if (old) vcall<void>(old, 0, 1u);
  ext_634273(G(u32, self + 0x29), 1);
  ext_43de70(self);
  if (flags & 1) {
    if (!(flags & 4)) { ext_45c510(self); return self; }
    ext_4690b0((u32)self, 0x36);
  }
  return self;
}
PCREG(5d57c0, fn5d57c0);
