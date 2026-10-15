#include "ff.h"
extern "C" void THISCALL ext_513190(void *self);
static void THISCALL fn520d90(u8 *self) {
  ext_513190(self);
  G(u32, self + 0x26f6) = 0;
  G(u32, self + 0x26ee) = 0;
  G(u32, self + 0x26f2) = 0;
  u8 *sys = (u8 *)g_pSysInterface;
  u8 *resource = (u8 *)G(u32, sys + 0x1a9f);
  if (resource) {
    u32 id = G(u32, self + 0x12f);
    G(u32, self + 0x26f6) = vcall<u32>(resource, 0x60, id, 0x6a05e0u);
    G(u32, self + 0x26ee) = vcall<u32>(resource, 0x60, id, 0x6a05f4u);
    G(u32, self + 0x26f2) = vcall<u32>(resource, 0x60, id, 0x6a0604u);
  }
  G(u32, self + 0x26fe) = 0;
  G(u32, self + 0x26fa) = 0;
}
PCREG(520d90, fn520d90);
