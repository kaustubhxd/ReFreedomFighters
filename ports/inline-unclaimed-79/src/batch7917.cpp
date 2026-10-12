#include "ff.h"
// batch7917.cpp - unclaimed-79 batch 17 (docs/20-unclaimed-79.md, gap band). Name from the GC name map (high).
// Helpers 0x4dafb0 and 0x4db6c0 run as original code (stubbed by the harness).

extern "C" u8 *THISCALL ext_4dafb0(u8 *self);
extern "C" void THISCALL ext_4db6c0(u8 *self, u8 *a, u8 *b);

// 0x484f30, ZPlayer::SetContactGeom(unsigned int) (high). Thiscall, one stack argument (ret 4). Looks up the geometry for the id
// through the system interface's +0x9b object (slot +0x58). Without one, stores 0 at this+0x1d6. With one: when the helper
// 0x4dafb0 of its +8 gives a record, calls 0x4db6c0 on it with (this+0x4f5, this+0x519). Then, when slot +0x428 of this differs
// from the id, stores the id at this+0x1d6.
static void THISCALL playerSetContactGeom(u8 *self, u32 id) {
  u8 *t = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *geom = vcall<u8 *, u32>(t, 0x58, id);
  if (geom == 0) {
    *(u32 *)(self + 0x1d6) = 0;
    return;
  }
  u8 *r = ext_4dafb0(*(u8 **)(geom + 8));
  if (r != 0)
    ext_4db6c0(r, self + 0x4f5, self + 0x519);
  u32 cur = vcall<u32>(self, 0x428);
  if (cur != id)
    *(u32 *)(self + 0x1d6) = id;
}
PCREG(484f30, playerSetContactGeom);
