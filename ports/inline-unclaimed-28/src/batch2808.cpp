#include "ff.h"
// batch2808.cpp - unclaimed-28 batch 8 (docs/20-unclaimed-28.md). Name from the GC name map (naming only).
// The helper at 0x4e5e60 (called with a null this, returns a dword) and the no-argument function pointer at 0x7003b0 run as
// original code / harness stubs here.

extern "C" u32 THISCALL ext_4e5e60(u8 *self);

// 0x4c5990, ZFollowGeom::Load(ZLoadGame*) (high). Clears bit 0x40 at this+4. Calls the no-argument function pointer at
// 0x7003b0 (the exe stops with int3 when it is null; the harness only runs non-null). Then stores the helper's return
// (called with a null this) at this+0x48, and calls the load game's slot +0x6c with this+0x4c. Returns true (al = 1).
static u8 THISCALL followGeomLoad(u8 *self, u8 *ld) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  ((void (*)())G(u32, 0x7003b0))();
  *(u32 *)(self + 0x48) = ext_4e5e60(0);
  vcall<void, u8 *>(ld, 0x6c, self + 0x4c);
  return 1;
}
PCREG(4c5990, followGeomLoad);
