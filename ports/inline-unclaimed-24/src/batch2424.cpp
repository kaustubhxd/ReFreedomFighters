// batch2424.cpp - decomp area 24, batch 2424: three small leaves.
#include "ff.h"

// 0x4dffb0 v2scalar(float*, float), thiscall, ret 4: the first two floats are multiplied by the argument.
static void THISCALL v2scalar(float *self, float s) {
  self[0] = self[0] * s;
  self[1] = self[1] * s;
}
PCREG(4dffb0, v2scalar);

// 0x4cc4b0 (unnamed), fastcall, plain ret. Compares the two bytes after folding 'A'..'Z' to lower case.
static u8 FASTCALL foldedByteEqual(u32 a, u32 b) {
  u8 x = (u8)a;
  u8 y = (u8)b;
  if ((u8)(x - 0x41) <= 0x19)
    x = (u8)(x + 0x20);
  if ((u8)(y - 0x41) <= 0x19)
    y = (u8)(y + 0x20);
  return x == y;
}
PCREG(4cc4b0, foldedByteEqual);

// 0x4bcd30 ZSoundVolumetricSource::Load(ZLoadGame*), thiscall, ret 4, AL = 1.
static u8 THISCALL volumetricSourceLoad(u8 *self, void *ld) {
  (void)ld;
  u8 *o2 = *(u8 **)(self + 0x44);
  *(u32 *)(self + 4) &= 0xffffffbfu;
  u8 *o3 = *(u8 **)(o2 + 0x18);
  *(u32 *)(self + 0xa8) = *(u32 *)(o3 + 8);
  u8 *o4 = *(u8 **)(o2 + 0x18);
  *(u32 *)(o4 + 0x84) = 0;
  return 1;
}
PCREG(4bcd30, volumetricSourceLoad);
