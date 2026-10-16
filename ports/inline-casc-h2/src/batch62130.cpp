#include "ff.h"
extern "C" void THISCALL ext_515850(u8 *self);
extern "C" void THISCALL ext_5157d0(u8 *self);
extern "C" void THISCALL ext_514c70(u8 *self);
extern "C" void THISCALL ext_514cf0(u8 *self);

static void THISCALL fn515d00(u8 *self) {
  u8 *state = G(u8 *, 0x7003b8);
  if (!G(u8, self + 0x21a) || G(u32, state + 0x4b0) < 1) return;
  ext_515850(self);
  ext_5157d0(self);
  ext_514c70(self);
  for (u32 n = 0; n < 0x14; ++n) {
    u32 index = G(u32, self + 0x2a7);
    s32 count = G(s32, state + 0x4b0);
    if ((s32)index >= count) {
      G(u32, self + 0x2a7) = 0;
      index = 0;
    }
    u8 *entry = (u8 *)G(u32, state + 0x4b4 + index * 4);
    u8 *item = (u8 *)G(u32, entry + 4);
    G(u32, self + 0x2af) = (u32)item;
    vcall<void>(item, 0x630, self + 0x2b3);
    ext_514cf0(self);
    G(u32, self + 0x2a7) += 1;
  }
}
PCREG(515d00, fn515d00);
