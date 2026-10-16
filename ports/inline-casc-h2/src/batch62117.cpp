#include "ff.h"
extern "C" void THISCALL ext_562d90(u8 *self, u32 value);
static u8 THISCALL fn56a840(u8 *self, u32 value) {
  u8 *sys = G(u8 *, 0x70039c);
  u8 *table = G(u8 *, sys + 0x9b);
  u8 *descriptor = (u8 *)vcall<u32>(table, 0x138);
  u32 id = 0;
  vcall<void>(descriptor, 0x88, 0x681320u, &id);
  u32 handle = vcall<u32>(table, 0x58, id);
  if (!handle || !vcall<u8>((void *)handle, 0x438))
    ext_562d90(self, value);
  return 0;
}
PCREG(56a840, fn56a840);
