// batch6370.cpp - unclaimed-68 batches 38 and 39 (claims 38 and 39, gap band). Names from the GC name map (medium).
#include "ff.h"

typedef void(THISCALL *VSlot0)(u8 *self);
typedef void(THISCALL *VSlot1)(u8 *self, u32 a);

// 0x4bf0f0, ZSoundExtend::Command(unsigned short, void*) (medium): thiscall, ret 8. If the command word equals the word at this+0x81, slot
// +0x88 is called with no argument. Returns 0.
static u32 THISCALL soundExtendCommand(u8 *self, u32 cmd, u32 arg) {
  (void)arg;
  if ((u16)cmd == *(u16 *)(self + 0x81)) ((VSlot0)*(u32 *)(*(u8 **)self + 0x88))(self);
  return 0;
}
PCREG(4bf0f0, soundExtendCommand);

// 0x4bf0d0, ZSoundAnimation::Command(unsigned short, void*) (medium): thiscall, ret 8. If the command word equals the word at this+0x48, the
// second argument is stored at this+0x4a and slot +0x64 is called with 0x10. Returns 0.
static u32 THISCALL soundAnimationCommand(u8 *self, u32 cmd, u32 arg) {
  if ((u16)cmd == *(u16 *)(self + 0x48)) {
    *(u32 *)(self + 0x4a) = arg;
    ((VSlot1)*(u32 *)(*(u8 **)self + 0x64))(self, 0x10);
  }
  return 0;
}
PCREG(4bf0d0, soundAnimationCommand);
