// batch1515.cpp - recruits thread, batch 1515: ZFollowGeom (the follow point of a level object): Init, Save, FrameUpdate.
// Load is left for later (it reads through a null object in the original, see docs/20-recruits.md).
#include "ff.h"

static inline void *objTable() { return *(void **)(G(u8 *, 0x70039c) + 0x9b); }

extern "C" u32 THISCALL ext_4e5e60(void *db);                              // DBREAD::operator unsigned int()
extern "C" void THISCALL ext_4daf90(void *geom, float *cen);               // ZBaseGeom::GetCen
extern "C" void FASTCALL ext_43e920(float *dst, const float *a, const float *b);  // dst = a - b
extern "C" void FASTCALL ext_4de040(float *m, const float *dir, const float *up); // createmat

// Follow geom: +0x44 the owner (a geom whose slots 0x84 = position and 0x7c = set matrix/offset), +0x48 the target
// object id, +0x4c..+0x54 the offset vector (from the target's geom +8: +0x24..+0x2c, read at Init).

// 0x4c58b0 ZFollowGeom::Init(ZGEOM*, DBREAD&), thiscall, ret 8. Target id from the file; the offset is copied from
// the target's geom (the three dwords at +0x24 of the object at [owner+8]).
static void THISCALL followGeomInit(u8 *self, void *geom, void *db) {
  (void)geom;
  *(u32 *)(self + 0x48) = ext_4e5e60(db);
  u8 *g = *(u8 **)(*(u8 **)(self + 0x44) + 8);
  *(u32 *)(self + 0x4c) = *(u32 *)(g + 0x24);
  *(u32 *)(self + 0x50) = *(u32 *)(g + 0x28);
  *(u32 *)(self + 0x54) = *(u32 *)(g + 0x2c);
}
PCREG(4c58b0, followGeomInit);

// 0x4c59d0 ZFollowGeom::Save(ZSaveGame*), thiscall, ret 4, AL = 1. Clears flag 0x40 and writes the offset via the
// saver's slot 0x68.
static u8 THISCALL followGeomSave(u8 *self, void *sg) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  vcall<void>(sg, 0x68, self + 0x4c);
  return 1;
}
PCREG(4c59d0, followGeomSave);

// 0x4c58e0 ZFollowGeom::FrameUpdate(), thiscall, plain ret. With the target object (id +0x48) present: its geom
// centre (GetCen) is taken, then the target's own position (slot 0x84) overwrites that buffer; the owner's position
// (slot 0x84) goes to a scratch vector that is not used; dir = target position - follow offset (+0x4c);
// the owner's matrix is set (slot 0x7c) from createmat(dir, up = 0).
static void THISCALL followGeomFrameUpdate(u8 *self) {
  u8 *t = vcall<u8 *>(objTable(), 0x58, *(u32 *)(self + 0x48));
  if (!t)
    return;
  float cen[3] = {0, 0, 0};
  ext_4daf90(*(void **)(t + 8), cen);
  vcall<void>(t, 0x84, cen);
  float scratch[3] = {0, 0, 0};
  vcall<void>(*(void **)(self + 0x44), 0x84, scratch);
  // One 12-float frame: the matrix is frame[0..11] and the direction is frame + 9 (the original's direction buffer is
  // the matrix's last three floats, ebp-0x28 inside the matrix at ebp-0x4c). createmat reads it while it writes.
  float frame[12] = {0};
  float *dir = frame + 9;
  ext_43e920(dir, cen, (float *)(self + 0x4c));
  ext_4de040(frame, dir, 0);
  typedef void(THISCALL * fSetMat)(void *self, const float *mat, const float *dir);
  u8 *owner = *(u8 **)(self + 0x44);
  ((fSetMat)(*(void ***)owner)[0x7c / 4])(owner, frame, dir);
}
PCREG(4c58e0, followGeomFrameUpdate);
