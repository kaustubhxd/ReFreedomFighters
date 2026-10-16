#include "ff.h"
extern "C" void __attribute__((cdecl)) ext_634273(u32 ptr, u32 mode);
extern "C" void THISCALL ext_4d8450(u8 *self);

static void THISCALL fn4d3f80(u8 *self) {
  G(u32, self) = 0x696580u;
  for (u32 i = 0; i < 1000; ++i) {
    u32 ptr = G(u32, self + 0x0f + 4 * i);
    if (ptr) ext_634273(ptr, 1);
  }
  for (u32 i = 0; i < 20; ++i) {
    u32 ptr = G(u32, self + 0xfb7 + 4 * i);
    if (ptr) ext_634273(ptr, 1);
  }
  u8 *object = (u8 *)G(u32, self + 0x10f0);
  if (object) vcall<void>(object, 0, 1u);
  ext_4d8450(self + 0x10db);
}
PCREG(4d3f80, fn4d3f80);
