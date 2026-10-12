// batch2425.cpp - decomp area 24, batch 2425: CGeomSound::FrameUpdate() (0x4a35b0), thiscall, plain ret.
// A slot at +0x54 (signed) that is non-negative and at most (engine time >> 10) is set to -1. The time is the dword at
// +0x40 of the engine object at 0x70039c (arithmetic shift).
#include "ff.h"

// 0x4a35b0
static void THISCALL geomSoundFrameUpdate(u8 *self) {
  s32 slot = *(s32 *)(self + 0x54);
  if (slot < 0)
    return;
  u8 *sys = G(u8 *, 0x70039c);
  s32 limit = (*(s32 *)(sys + 0x40)) >> 10;
  if (slot <= limit)
    *(s32 *)(self + 0x54) = -1;
}
PCREG(4a35b0, geomSoundFrameUpdate);
