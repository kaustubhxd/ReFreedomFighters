#include "ff.h"

extern "C" void THISCALL ext_563110(u8 *self, u32 a, u32 b);
extern "C" void THISCALL ext_56fe40(u8 *self);
extern "C" void THISCALL ext_56fb10(u8 *self);

static u8 THISCALL fn56fab0(u8 *self, u32 a, u32 b) {
  ext_563110(self, a, b);
  if ((u8)b) vcall<void>(*(u8 **)(self + 0x44), 0xbc, 0u);
  *(u16 *)(self + 0x196) = 1;
  vcall<void>(*(u8 **)(self + 0x5ce), 0x284, (u32)(self + 0x1c9));
  ext_56fe40(self);
  ext_56fb10(self);
  return 0;
}

PCREG(56fab0, fn56fab0);
