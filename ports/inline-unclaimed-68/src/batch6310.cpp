// batch6310.cpp - unclaimed-68 batch 30 (claim 30, gap band). Name from the GC name map (medium).
#include "ff.h"

// Slot 0 of the object at this+0x6d (thiscall, one argument; the callee cleans it).
typedef void(THISCALL *VSlot0)(u8 *self, u32 arg);

// 0x4bf500, ZSoundSpline::End() (medium): thiscall, void. The pointer at the unaligned field this+0x6d, when not null, gets slot 0 (1);
// then the field is cleared.
static void THISCALL soundSplineEnd(u8 *self) {
  u8 *s = *(u8 **)(self + 0x6d);
  if (s) ((VSlot0)*(u32 *)(*(u8 **)s))(s, 1);
  *(u32 *)(self + 0x6d) = 0;
}
PCREG(4bf500, soundSplineEnd);
