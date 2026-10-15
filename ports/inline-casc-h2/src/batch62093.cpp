#include "ff.h"
extern "C" void THISCALL ext_572240(u8 *self, u32 index, u32 value);
static u32 THISCALL fn571c40(u8 *self) {
  ext_572240(self, 0, *(u32 *)(self + 0x18c));
  ext_572240(self, 1, *(u32 *)(self + 0x190));
  ext_572240(self, 2, *(u32 *)(self + 0x194));
  for (u32 i = 0; i < 3; ++i) {
    u8 *target = (u8 *)*(u32 *)(self + 0x180 + i * 4);
    vcall<void>(target, 0x36c, *(u32 *)(self + 0x18c + i * 4), 1);
  }
  return vcall<u32>(self, 0xd0, 0);
}
PCREG(571c40, fn571c40);
