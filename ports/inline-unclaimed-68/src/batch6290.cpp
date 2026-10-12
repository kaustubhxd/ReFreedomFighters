// batch6290.cpp - unclaimed-68 batch 28 (claim 28, gap band). Name from the GC name map (medium).
#include "ff.h"

// 0x4bc310, ZSoundVolumetricSource::Init() (medium): thiscall, void. s = this+0x44; a = s+0x18; this+0xa8 = a+8; then (s+0x18)+0x84 = 0.
static void THISCALL volumetricSourceInit(u8 *self) {
  u8 *s = *(u8 **)(self + 0x44);
  u8 *a = *(u8 **)(s + 0x18);
  *(u32 *)(self + 0xa8) = *(u32 *)(a + 8);
  u8 *b = *(u8 **)(s + 0x18);
  *(u32 *)(b + 0x84) = 0;
}
PCREG(4bc310, volumetricSourceInit);
