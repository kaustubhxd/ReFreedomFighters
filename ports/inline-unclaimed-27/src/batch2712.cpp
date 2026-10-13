#include "ff.h"
// batch2712.cpp - unclaimed-27 batch 12 (docs/20-unclaimed-27.md). Names from the GC name map (high).

// 0x4831c0, ZPlayer::DisplayCollisionsBounds(bool) (high). Thiscall, ret 4: stores the low byte of the argument at this+0x601.
static void THISCALL zPlayerDisplayCollisionsBounds(u8 *self, u32 a1) {
  self[0x601] = (u8)a1;
}
PCREG(4831c0, zPlayerDisplayCollisionsBounds);

// 0x45f7c0, ZGEOM::RecurGetNext(const ZBaseGeom**) const (high). Thiscall, ret 4: writes 0 to the dword the argument points to.
static void THISCALL zGeomRecurGetNext(u8 *self, u32 *out) {
  (void)self;
  *out = 0;
}
PCREG(45f7c0, zGeomRecurGetNext);
