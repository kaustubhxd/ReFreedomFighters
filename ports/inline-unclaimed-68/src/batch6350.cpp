// batch6350.cpp - unclaimed-68 batches 34 and 35 (claims 34 and 35, gap band). Names from the GC name map (medium).
#include "ff.h"

typedef void(THISCALL *VSlot1)(u8 *self, u32 a);
typedef void(THISCALL *VSlot2)(u8 *self, u32 a, u32 b);

// 0x4bc060, ZSoundRandomVolume::ActivateFrameUpdate(bool) (medium): thiscall, ret 4. True: slot +0x64 with 0x10 (the original tail-jumps).
// False: slot +0x68 with (0x10, 0).
static void THISCALL randomVolumeActivateFrameUpdate(u8 *self, u32 flag) {
  u8 *vt = *(u8 **)self;
  if ((u8)flag) {
    ((VSlot1)*(u32 *)(vt + 0x64))(self, 0x10);
  } else {
    ((VSlot2)*(u32 *)(vt + 0x68))(self, 0x10, 0);
  }
}
PCREG(4bc060, randomVolumeActivateFrameUpdate);

// 0x4be6a0, ZSoundSpline::ActivateFrameUpdate(bool) (medium): thiscall, ret 4. True: the dword at +0xd2 is cleared, then slot +0x64 with 0x10.
// False: slot +0x68 with (0x10, 0).
static void THISCALL splineActivateFrameUpdate(u8 *self, u32 flag) {
  u8 *vt = *(u8 **)self;
  if ((u8)flag) {
    *(u32 *)(self + 0xd2) = 0;
    ((VSlot1)*(u32 *)(vt + 0x64))(self, 0x10);
  } else {
    ((VSlot2)*(u32 *)(vt + 0x68))(self, 0x10, 0);
  }
}
PCREG(4be6a0, splineActivateFrameUpdate);
