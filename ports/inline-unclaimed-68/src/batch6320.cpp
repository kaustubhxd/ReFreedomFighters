// batch6320.cpp - unclaimed-68 batch 31 (claim 31, gap band). Name from the GC name map (medium).
#include "ff.h"

// 0x4bbe10, ZSoundRandomVolume::Init() (medium): thiscall, void.
static void THISCALL randomVolumeInit(u8 *self) {
  u8 *blk = *(u8 **)(*(u8 **)(self + 0x44) + 0x18);
  *(u32 *)(self + 0x48) = 0;
  *(u32 *)(self + 0x4c) = *(u32 *)(blk + 0x84);
  *(u32 *)(self + 0x79) = *(u32 *)(self + 0x50);
  *(u32 *)(self + 0x64) = 1;
  *(u32 *)(self + 0x68) = 0;
  *(u32 *)(self + 0x70) = 0xbf800000u;
  *(u32 *)(self + 0x74) = 0;
  self[0x78] = 1;
}
PCREG(4bbe10, randomVolumeInit);
