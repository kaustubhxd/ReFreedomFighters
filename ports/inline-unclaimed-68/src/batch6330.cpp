// batch6330.cpp - unclaimed-68 batch 32 (claim 32, gap band). Name from the GC name map (medium).
#include "ff.h"

// 0x4bcbe0, ZSoundVolumetricSource::SetSourceVolume(float, float) (medium): thiscall, ret 8. When the byte at this+0xd0 is set: the first
// argument goes to the block's +0x84 (block = this+0x44 -> +0x18), and the second argument, truncated to an int, to the block's +0x68.
static void THISCALL volumetricSetSourceVolume(u8 *self, float a, float b) {
  if (self[0xd0]) {
    u8 *blk = *(u8 **)(*(u8 **)(self + 0x44) + 0x18);
    *(float *)(blk + 0x84) = a;
    *(s32 *)(blk + 0x68) = (s32)b;
  }
}
PCREG(4bcbe0, volumetricSetSourceVolume);
