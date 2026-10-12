// batch1023.cpp - unclaimed-07 batch 23 (slice 6, small leaf): ZSoundVolumetricSource::ActivateVolume(bool) (high, 0x4bcc20).
#include "ff.h"

// 0x4bcc20, ZSoundVolumetricSource::ActivateVolume(bool) (high), thiscall, ret 4: stores the low byte of the argument at
// this+0xd0.
static void THISCALL soundVolumeActivate(u8 *self, u32 flag) {
  self[0xd0] = (u8)flag;
}
PCREG(4bcc20, soundVolumeActivate);
