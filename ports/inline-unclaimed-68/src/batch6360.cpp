// batch6360.cpp - unclaimed-68 batches 36 and 37 (claims 36 and 37, gap band). Names from the GC name map (medium).
#include "ff.h"

// A stream slot taking one argument (thiscall; callee cleans its argument).
typedef void(THISCALL *VStream1)(u8 *self, u32 a);

// 0x4bd000, ZSoundVolume2D::Load(ZLoadGame*) (medium): thiscall, ret 4, returns true in AL.
static u8 THISCALL volume2DLoad(u8 *self, u8 *ld) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  ((VStream1)*(u32 *)(*(u8 **)ld + 0x6c))(ld, (u32)(self + 0x48));
  return 1;
}
PCREG(4bd000, volume2DLoad);

// 0x4bd020, ZSoundVolume2D::Save(ZSaveGame*) (medium): thiscall, ret 4, returns true in AL.
static u8 THISCALL volume2DSave(u8 *self, u8 *sv) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  ((VStream1)*(u32 *)(*(u8 **)sv + 0x68))(sv, (u32)(self + 0x48));
  return 1;
}
PCREG(4bd020, volume2DSave);
