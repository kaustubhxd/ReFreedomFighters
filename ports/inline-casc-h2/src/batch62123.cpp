#include "ff.h"
extern "C" void THISCALL ext_45d3a0(u8 *self);
static void THISCALL fn465fd0(u8 *self) {
  ext_45d3a0(self);
  u8 *sys = G(u8 *, 0x70039c);
  u8 *table = (u8 *)G(u32, sys + 0x9b);
  u8 *manager = (u8 *)G(u32, table + 0xadc);
  u8 *object = (u8 *)vcall<u32>(manager, 0x25c, 0x685f44u, 0u);
  if (!object) {
    u32 assertion = G(u32, 0x7003b0);
    if (assertion) ((void (FASTCALL *)(void))assertion)();
    else __asm__ volatile("int3");
  }
  u32 a = G(u16, self + 0x161);
  u32 b = G(u16, self + 0x163);
  u32 result = vcall<u32>(table, 0x4c, self, a, b);
  vcall<void>(object, 0x228, result);
}
PCREG(465fd0, fn465fd0);
