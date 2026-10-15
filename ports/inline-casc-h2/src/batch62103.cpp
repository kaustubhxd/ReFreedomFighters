#include "ff.h"
extern "C" void THISCALL ext_5fd170(u8 *state);
static void THISCALL fn5f2720(u8 *self) {
  u8 *state = (u8 *)*(u32 *)(self + 0xc);
  if (--*(u32 *)(state + 0x9c) == 0) ext_5fd170(state + 4);
  u8 *table = (u8 *)*(u32 *)(*(u32 *)0x70039c + 0x9b);
  if (*(u8 *)(table + 0xbc4) == 0) {
    u8 *a = (u8 *)*(u32 *)(state + 0xa0);
    if (a) vcall<void>(a, 0x18);
    u8 *b = (u8 *)*(u32 *)(state + 0xa4);
    if (b) vcall<void>(b, 0x18);
  }
  u32 id = vcall<u32>(table, 0x114, 0x694c6c, 0, 0x6b8738, 0x1b8);
  G(u16, 0x7143b0) = (u16)id;
}
PCREG(5f2720, fn5f2720);
