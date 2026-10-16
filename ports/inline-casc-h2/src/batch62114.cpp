#include "ff.h"
static void THISCALL fn473240(u8 *self, u32 id) {
  if (vcall<u32>(self, 0x3f0)) return;
  u32 accepted = vcall<u32>(self, 0x514);
  u8 *sys = G(u8 *, 0x70039c);
  u8 *engine = G(u8 *, sys + 0x9b);
  u32 handle = vcall<u32>(engine, 0x4c);
  vcall<void>(self, 0x45c, accepted ? 2u : 1u, handle, id);
}
PCREG(473240, fn473240);
