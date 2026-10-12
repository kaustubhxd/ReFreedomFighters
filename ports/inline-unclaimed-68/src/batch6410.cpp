// batch6410.cpp - unclaimed-68 batch 41 (claim 41, gap band). Name from the GC name map (medium).
#include "ff.h"

// 0x4a3640, CGeomSound::OnSetDelay(void*) (medium): thiscall, ret 4, returns 0. The argument is used as an integer: when it is nonzero,
// this+0x54 gets ((arg << 10) + the engine's dword at +0x40) >> 10 (arithmetic shift).
static u32 THISCALL geomSoundOnSetDelay(u8 *self, u32 arg) {
  if (arg != 0) {
    u8 *eng = G(u8 *, 0x70039c);
    s32 v = (s32)((arg << 10) + *(u32 *)(eng + 0x40));
    *(s32 *)(self + 0x54) = v >> 10;
  }
  return 0;
}
PCREG(4a3640, geomSoundOnSetDelay);
