#include "ff.h"

extern "C" void THISCALL ext_467410(u8 *self, u32 a, float f, u32 x, u32 y, u32 z, u32 w);

static u8 THISCALL fn486020(u8 *self) {
  u8 *so = *(u8 **)0x70039c;
  u8 *table = *(u8 **)(so + 0x9b);
  u32 result = vcall<u32>(table, 0x4c, *(u32 *)(self + 8));
  u8 *state = *(u8 **)(self + 0x10);
  ext_467410(state + 4, *(u32 *)(self + 0xc), 0.0f, 0, 0, 0, 0xffffffffu);
  vcall<void>(state, 8, *(u32 *)(self + 0xc), result);
  vcall<void>(*(u8 **)(self + 8), 0x2d0, 2u, 0u);
  vcall<void>(*(u8 **)(self + 8), 0x2d0, 0u, 0u);
  return 0;
}
PCREG(486020, fn486020);
