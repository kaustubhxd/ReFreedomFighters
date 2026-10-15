#include "ff.h"

extern "C" void THISCALL ext_563a50(u8 *self);

static void THISCALL fn56a030(u8 *self) {
  u32 mode = *(u32 *)(self + 0x1c5);
  if (mode == 2) {
    u8 *target = *(u8 **)(self + 0x94);
    if (target) {
      u8 *eng = G(u8 *, 0x70039c);
      u8 *table = *(u8 **)(eng + 0x9b);
      u32 value = vcall<u32>(table, 0x4c, *(u32 *)(self + 0x44));
      *(u32 *)(target + 0x1329f) = value;
    }
  }
  if (mode == 5) {
    vcall<void>(self, 0x64, 0x10u);
    ext_563a50(self);
  }
}

PCREG(56a030, fn56a030);
