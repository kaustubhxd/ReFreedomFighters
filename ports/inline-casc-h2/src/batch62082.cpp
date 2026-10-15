#include "ff.h"
extern "C" void THISCALL ext_43e0f0(void *self);
static u32 THISCALL fn45b970(u8 *self) {
  u8 *sys = (u8 *)g_pSysInterface;
  u8 *collection = *(u8 **)(sys + 0x9b);
  u32 item = vcall<u32>(collection, 0x138);
  u32 value = vcall<u32>(collection, 0x4c, (u32)self, 4u);
  vcall<void>((void *)item, 0x60, 0x684cd4u, value);
  vcall<void>(self, 0x110, 0x10u, 0u);
  ext_43e0f0(self);
  return vcall<u32>(self, 0x214);
}
PCREG(45b970, fn45b970);
