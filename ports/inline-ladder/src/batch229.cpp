// batch229.cpp - ZIKLNKOBJ constructor and ClassInit (inline-ladder thread, 2026-10-11).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define U16(p, off) (*(u16 *)((u8 *)(p) + (off)))
#define F32(p, off) (*(float *)((u8 *)(p) + (off)))

extern "C" void *THISCALL ext_460e40(void *self, u32 ci, u32 name, u32 parent);   // ZLNKOBJ::ZLNKOBJ
extern "C" void THISCALL ext_466220(void *target);                                // ZTARGET::Clear
extern "C" void THISCALL ext_4dc630(void *geom, u32 set, u32 clear);              // ZBaseGeom::SetControl
extern "C" void THISCALL ext_461d60(void *self);                                  // ZLNKOBJ::ClassInit

static inline void *db229() { return (void *)U32(G(u32, 0x70039c), 0x9b); }
static const char *const kFileIk = (const char *)0x685ee0;   // "..\..\code\engine\geomsextend\ziklnkobj.cpp"

// 0x4654b0 ZIKLNKOBJ::ZIKLNKOBJ(ZGEOMCLASSINFO*, const char*, ZBaseGeom*) [GameCube reference, high], ret 0xc, returns this.
// Base ZLNKOBJ, vtable 0x685ac4, ZTARGET::Clear on +0x16d, then defaults (eye height +0x1ca = 160.0, IK flags 0,
// ragdoll-off byte +0x13a = 1) and the message ids ObjectVisibleAdd (+0x161), ObjectVisibleRemove (+0x163) and
// CutSequence_End (+0x167) (database slot 0x114, lines 0x115..0x117). The SEH frame is constructor cleanup only.
static void *THISCALL ikCtor(u8 *self, u32 ci, u32 name, u32 parent) {
  ext_460e40(self, ci, name, parent);
  U32(self, 0) = 0x685ac4;
  ext_466220(self + 0x16d);
  self[0x158] = 0;
  U32(self, 0x1ca) = 0x43200000;
  U32(self, 0x136) = 0;
  U16(self, 0x161) = (u16)vcall<u32>(db229(), 0x114, (const char *)0x685f0c, 0u, kFileIk, 0x115u);
  U16(self, 0x163) = (u16)vcall<u32>(db229(), 0x114, (const char *)0x685f20, 0u, kFileIk, 0x116u);
  U16(self, 0x167) = (u16)vcall<u32>(db229(), 0x114, (const char *)0x685f34, 0u, kFileIk, 0x117u);
  U32(self, 0x169) = 0;
  U32(self, 0x147) = 0;
  U32(self, 0x14b) = 0;
  U32(self, 0x14f) = 0;
  U32(self, 0x153) = 0;
  self[0x157] = 0;
  U16(self, 0x144) = 0;
  U32(self, 0x15d) = 0;
  U32(self, 0x13b) = 0;
  U32(self, 0x13f) = 0;
  self[0x13a] = 1;
  U32(self, 0x1c2) = 0;
  U32(self, 0x1be) = 0;
  U32(self, 0x1ba) = 0;
  U32(self, 0x1c6) = 0;
  self[0x146] = 0;
  return self;
}
PCREG(4654b0, ikCtor);

// 0x466040 ZIKLNKOBJ::ClassInit() [GameCube reference, high]:
// 1. SetControl(g, 0, 0x2001d) on each geom of the chain from own slot 0x20's +8 (next: slot 0x20 object slot 0x50).
// 2. ZLNKOBJ::ClassInit.
// 3. With a sound manager ([engine+0x1a9f]): +0x147 and +0x14b = its slot 0x5c("default"), +0x14f = slot 0x5c("shoe")
//    (footstep sound sets).
// 4. Find "TrackLinkObjects" or create it as a ZLIST with notify ranges (RangeNotify -1, SelectNotify -1,
//    ActorCollision 9999, CheckVisible -1, ActionController -1; list slot 0x10c), list slot 0x154, SetControl(list+8,
//    0x800000, 0), list slot 0x124(1, 0, 0, 0). Store it in [0x7003b8]+0x4ac and add this (list slot 0x218).
// 5. Own slot 0x358; own slot 0x398(own slot 0x3a0(&box)) (vtable read once); eye height +0x1ca = box[1] + 40.0;
//    byte +0x143 = 2; own slot 0x3d4.
static void THISCALL ikClassInit(u8 *self) {
  u32 cur = U32(vcall<u8 *>(self, 0x20), 8);
  while (cur) {
    ext_4dc630((void *)cur, 0, 0x2001d);
    void *o = vcall<void *>(self, 0x20);
    vcall<void>(o, 0x50, &cur);
  }
  ext_461d60(self);
  if (U32(G(u32, 0x70039c), 0x1a9f)) {
    U32(self, 0x147) = vcall<u32>((void *)U32(G(u32, 0x70039c), 0x1a9f), 0x5c, (const char *)0x685ffc);
    U32(self, 0x14f) = vcall<u32>((void *)U32(G(u32, 0x70039c), 0x1a9f), 0x5c, (const char *)0x686004);
    U32(self, 0x14b) = U32(self, 0x147);
  }
  u8 *list = vcall<u8 *>((void *)U32(db229(), 0xadc), 0x25c, (const char *)0x685f44, 0u);
  if (!list) {
    list = vcall<u8 *>((void *)U32(db229(), 0xadc), 0x294, (const char *)0x685f44, (const char *)0x67f610, (void *)0, 1u);
    vcall<void>(list, 0x10c, (const char *)0x68600c, 0xffffffffu);
    vcall<void>(list, 0x10c, (const char *)0x686020, 0xffffffffu);
    vcall<void>(list, 0x10c, (const char *)0x686034, 0x270fu);
    vcall<void>(list, 0x10c, (const char *)0x68604c, 0xffffffffu);
    vcall<void>(list, 0x10c, (const char *)0x686060, 0xffffffffu);
    vcall<void>(list, 0x154);
    ext_4dc630((void *)U32(list, 8), 0x800000, 0);
    vcall<void>(list, 0x124, 1u, 0u, 0u, 0u);
  }
  U32(G(u32, 0x7003b8), 0x4ac) = (u32)list;
  vcall<void>(list, 0x218, self);
  vcall<void>(self, 0x358);
  u8 *vt = *(u8 **)self;
  float box[3];
  typedef u32(THISCALL * fa)(void *, float *);
  typedef void(THISCALL * fb)(void *, u32);
  u32 r = (*(fa *)(vt + 0x3a0))(self, box);
  (*(fb *)(vt + 0x398))(self, r);
  float eye = box[1] + 40.0f;
  self[0x143] = 2;
  F32(self, 0x1ca) = eye;
  vcall<void>(self, 0x3d4);
}
PCREG(466040, ikClassInit);
