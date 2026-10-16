// batch248.cpp - ZFFHERO::GetAttachedGeomMatPos (inline-ladder thread, 2026-10-11).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" bool THISCALL ext_462d10(void *self, const void *geom, float *mat, float *pos);   // ZLNKOBJ::GetAttachedGeomMatPos

// 0x591980 ZFFHERO::GetAttachedGeomMatPos(const ZBaseGeom *g, float *mat, float *pos) const [GameCube reference, high], thiscall,
// ret 0xc, returns AL. If byte +0x67f is zero: the base ZLNKOBJ version (same arguments, tail). Otherwise:
// obj = db slot 0x58(member(eng+0x190f) slot 0xb4(0)); obj slot 0x80(mat, pos); the hero's own slot 0x94(mat, pos); returns true.
static bool THISCALL heroGetAttachedGeomMatPos(u8 *self, const void *g, float *mat, float *pos) {
  if (*(u8 *)(self + 0x67f) == 0)
    return ext_462d10(self, g, mat, pos);
  u8 *eng = (u8 *)G(u32, 0x70039c);
  void *member = (void *)U32(eng, 0x190f);
  u32 x = vcall<u32>(member, 0xb4, 0u);
  u8 *db = (u8 *)U32(eng, 0x9b);
  void *obj = vcall<void *>(db, 0x58, x);
  vcall<void>(obj, 0x80, mat, pos);
  vcall<void>(self, 0x94, mat, pos);
  return true;
}
PCREG(591980, heroGetAttachedGeomMatPos);
