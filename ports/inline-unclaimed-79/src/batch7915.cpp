#include "ff.h"
// batch7915.cpp - unclaimed-79 batch 15 (docs/20-unclaimed-79.md, gap band). Name from the GC name map (high).
// The base copy 0x462000 and the helper 0x4dc630 run as original code (stubbed by the harness).

extern "C" void THISCALL ext_462000(u8 *self, u8 *geom);
extern "C" void THISCALL ext_4dc630(u8 *self, u32 a, u32 b);

// 0x4827c0, ZPlayer::CopyData(const ZGEOM*) (high). Thiscall, one stack argument (ret 4).
static void THISCALL playerCopyData(u8 *self, u8 *geom) {
  ext_462000(self, geom);
  ext_4dc630(*(u8 **)(self + 8), 0u, 1u);
  u8 *r = vcall<u8 *>(self, 0x20);
  ext_4dc630(*(u8 **)(r + 8), 0u, 1u);
}
PCREG(4827c0, playerCopyData);
