// batch1108.cpp - collision thread, batch 1108: ZBaseGeom world-to-local helpers and small leaves of the
// ZCollisionBase line casts.
#include "ff.h"

extern "C" void FASTCALL ext_43e960(float *v, const float *a);   // v -= a (x87)
extern "C" void FASTCALL ext_441a60(float *v, const float *m);   // vmtmul (batch 1100)

static inline u8 *geomParent(const u8 *g) { return *(u8 *const *)(g + 0x50); }

// 0x4db1f0 ZBaseGeom::GetLocalPoint(float *p) const, thiscall, ret 4. World point to this geom's frame. The root
// geom (no parent at +0x50) is the world frame and changes nothing; otherwise the parent's GetLocalPoint runs
// first, then p = (p - pos(+0x24)) * transpose(mat).
static void THISCALL GetLocalPoint(const u8 *self, float *p) {
  if (!geomParent(self))
    return;
  GetLocalPoint(geomParent(self), p);
  ext_43e960(p, (const float *)(self + 0x24));
  ext_441a60(p, (const float *)self);
}
PCREG(4db1f0, GetLocalPoint);

// 0x4db270 ZBaseGeom::GetLocalVect(float *v) const, thiscall, ret 4. The same for a direction (no translation).
static void THISCALL GetLocalVect(const u8 *self, float *v) {
  if (!geomParent(self))
    return;
  GetLocalVect(geomParent(self), v);
  ext_441a60(v, (const float *)self);
}
PCREG(4db270, GetLocalVect);

extern "C" void THISCALL ext_4db1f0(const u8 *self, float *p);
extern "C" void THISCALL ext_4db270(const u8 *self, float *v);

// 0x4db220 ZBaseGeom::GetLocalPointVect(float *p, float *v) const, thiscall, ret 8: both of the above, with the
// parent pointer re-read for the second half.
static void THISCALL GetLocalPointVect(const u8 *self, float *p, float *v) {
  if (geomParent(self)) {
    ext_4db1f0(geomParent(self), p);
    ext_43e960(p, (const float *)(self + 0x24));
    ext_441a60(p, (const float *)self);
  }
  if (geomParent(self)) {
    ext_4db270(geomParent(self), v);
    ext_441a60(v, (const float *)self);
  }
}
PCREG(4db220, GetLocalPointVect);

// 0x4daf80 ZBaseGeom::GetBoundTreeType() [low], thiscall: slot 0x38 of the object at +0x54 (tail call), or 0.
static u32 THISCALL GetBoundTreeType(u8 *self) {
  u8 *o = *(u8 **)(self + 0x54);
  if (!o)
    return 0;
  return vcall<u32>(o, 0x38);
}
PCREG(4daf80, GetBoundTreeType);

// 0x4e3170 (unnamed; a one-word copy constructor), thiscall, ret 4: this[0] = src[0], returns this.
static u32 *THISCALL copyWord(u32 *self, const u32 *src) {
  *self = *src;
  return self;
}
PCREG(4e3170, copyWord);

// 0x4e3180 SRecurseInfoCompiled::SRecurseInfoCompiled() [high], thiscall: +0 = 1.0f, returns this.
static float *THISCALL SRecurseInfoCompiledCtor(float *self) {
  *(u32 *)self = 0x3f800000;
  return self;
}
PCREG(4e3180, SRecurseInfoCompiledCtor);
