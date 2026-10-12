// batch6340.cpp - unclaimed-68 batch 33 (claim 33, gap band). Name from the GC name map (medium).
#include "ff.h"

typedef void(THISCALL *VSlot1)(u8 *self, u32 a);
typedef void(THISCALL *VSlot2)(u8 *self, u32 a, u32 b);

// 0x4bcc30, ZSoundVolumetricSource::ActivateFrameUpdate(bool) (medium): thiscall, ret 4. A true flag calls slot +0x64 with 0x10 and clears
// the dword at +0xd5; a false flag calls slot +0x68 with (0x10, 0).
static void THISCALL volumetricActivateFrameUpdate(u8 *self, u32 flag) {
  u8 *vt = *(u8 **)self;
  if ((u8)flag) {
    ((VSlot1)*(u32 *)(vt + 0x64))(self, 0x10);
    *(u32 *)(self + 0xd5) = 0;
  } else {
    ((VSlot2)*(u32 *)(vt + 0x68))(self, 0x10, 0);
  }
}
PCREG(4bcc30, volumetricActivateFrameUpdate);
