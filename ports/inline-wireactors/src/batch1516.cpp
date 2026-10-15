// batch1516.cpp - recruits thread, batch 1516: ZFollowShape Init and Save (the follow shape of a level object).
// FrameUpdate (0x4c5df0) and Load (0x4c5c50, which calls 0x4c79f0) are not ported in this batch.
#include "ff.h"

static inline void *objTable() { return *(void **)(G(u8 *, 0x70039c) + 0x9b); }

extern "C" u32 THISCALL ext_4e5e60(void *db);   // DBREAD::operator unsigned int()
extern "C" float THISCALL ext_4e5e80(void *db); // DBREAD::operator float (ST0)

// Shape record: +0x44 owner geom (slots 0x80 / 0x7c set position and matrix), +0x48 radius (float), +0x4c offset
// dword, +0x50 height (float), +0x54 object id, +0x58 / +0x59 flags (the file's non-zero tests), +0x5a value (the
// file's dword), +0x5e value (tested against 1), +0x62 value, +0x66 / +0x67 flags.

// 0x4c5d00 ZFollowShape::Init(ZGEOM*, DBREAD&), thiscall, ret 8. Reads the object id, the two floats, two flags
// (non-zero test) and three dwords from the file, then copies the level's value at [0x70039c]+0x40 into +0x4c when
// it differs from the stored value (asserting nothing else). The owner's geom is then sent its position and matrix
// (slots 0x80 and 0x7c) and the physics object (table +0xadc, slot 0x28c) gets (owner +8, 0, 1). Finally +0x5a
// is compared with 1 to set the shape flag (+0x66) and +0x67 = 1. The SEH frame is not ported.
static void THISCALL followShapeInit(u8 *self, void *geom, void *db) {
  (void)geom;
  *(u32 *)(self + 0x54) = ext_4e5e60(db);
  *(float *)(self + 0x48) = ext_4e5e80(db);
  *(float *)(self + 0x50) = ext_4e5e80(db);
  *(u8 *)(self + 0x58) = ext_4e5e60(db) != 0;
  *(u8 *)(self + 0x59) = ext_4e5e60(db) != 0;
  *(u32 *)(self + 0x5e) = ext_4e5e60(db);
  *(u32 *)(self + 0x62) = ext_4e5e60(db);
  u32 *lvl = (u32 *)(G(u8 *, 0x70039c) + 0x40);
  if ((u32 *)(self + 0x4c) != lvl)
    *(u32 *)(self + 0x4c) = *lvl;
  u8 *owner = *(u8 **)(self + 0x44);
  // one 12-float frame: the position is the frame's last 3 floats, starting at float 9 (the original's two stack
  // buffers overlap by 9 floats: ebp-0x34 for the matrix and ebp-0x10 for the position)
  float frame[12] = {0};
  float *mat = frame;
  float *pos = frame + 9;
  vcall<void>(owner, 0x80, mat, pos);
  void *phys = *(void **)((u8 *)objTable() + 0xadc);
  // the owner's geom pointer (owner +8) is the first argument; the call pushes 0 and 1 after it
  vcall<void>(phys, 0x28c, *(void **)(owner + 8), 0u, 1u);
  vcall<void>(owner, 0x7c, mat, pos);   // (the overlap is the original's)
  *(u32 *)(self + 0x5a) = *(u32 *)(self + 0x5e);
  *(u8 *)(self + 0x66) = *(u32 *)(self + 0x5e) != 1;
  *(u32 *)(self + 0x67) = 1;
}
PCREG(4c5d00, followShapeInit);

// 0x4c5cb0 ZFollowShape::Save(ZSaveGame*), thiscall, ret 4, AL = 1. Clears flag 0x40 at +4 and writes: the dword at
// +0x5a (slot 0x44), the shape flag (slot 0x60, byte at +0x66), the dword at +0x67 (slot 0x44), then the offset at
// +0x4c through the saver's slot 0x54 (value argument).
static u8 THISCALL followShapeSave(u8 *self, void *sg) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  vcall<void>(sg, 0x44, *(u32 *)(self + 0x5a));
  vcall<void>(sg, 0x60, (u32)self[0x66]);
  vcall<void>(sg, 0x44, *(u32 *)(self + 0x67));
  vcall<void>(sg, 0x54, *(u32 *)(self + 0x4c));   // by value: the original stores the value in the pushed slot
  return 1;
}
PCREG(4c5cb0, followShapeSave);
