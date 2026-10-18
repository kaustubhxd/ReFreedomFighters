// batch209.cpp - ladder class housekeeping (inline-ladder thread, 2026-10-11): ZFFHeroMovementGuide constructor,
// scalar deleting destructor, GetAnims, Load and Save. Base-class calls go to the original code (hooked in the specs).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" void *THISCALL ext_5e0e10(void *self, void *hero, u32 flags);   // ZFFHeroMovementBaseMove::ZFFHeroMovementBaseMove
extern "C" void THISCALL ext_480fd0(void *member);                         // ZMovementBaseMove::~ZMovementBaseMove (low)
extern "C" void THISCALL ext_4878d0(void *self);                           // base destructor body (no GC name)
extern "C" void ext_634273(void *p, u32 size);                             // __builtin_delete (sized), cdecl
extern "C" void THISCALL ext_488bc0(void *self);                           // ZMovementBaseMove::GetAnims
extern "C" u32 THISCALL ext_489350(void *self, void *lg);                  // ZMovementBase::Load
extern "C" u32 THISCALL ext_489d00(void *self, void *sg);                  // ZMovementBase::Save

// 0x5e1040 ZFFHeroMovementGuide::ZFFHeroMovementGuide(ZFFHERO *hero, unsigned flags) [GC 800921e0, medium], thiscall,
// ret 8, returns this. Base constructor, then vtable 0x6b79d0, stamp +0x5dd = 0, phase +0x5e1 = -1.0, list +0x54c = 0,
// byte +0x578 = 0, ladder +0x550 = 0. The object is 0x5fd bytes (the size the destructor frees).
static void *THISCALL guideCtor(u8 *self, void *hero, u32 flags) {
  ext_5e0e10(self, hero, flags);
  U32(self, 0) = 0x6b79d0;
  U32(self, 0x5dd) = 0;
  U32(self, 0x5e1) = 0xbf800000;
  U32(self, 0x54c) = 0;
  self[0x578] = 0;
  U32(self, 0x550) = 0;
  return self;
}
PCREG(5e1040, guideCtor);

// 0x5e1450 ZFFHeroMovementGuide scalar deleting destructor [GC 8009223c ~ZFFHeroMovementGuide, medium; vtable slot 1],
// thiscall, one stack arg (flags), ret 4, returns this. Resets the vtable, destroys the four ZMovementBaseMove-like
// members at +0x523, +0x4ab, +0x3eb, +0x3d3 (reverse declaration order), runs the base destructor 0x4878d0, and frees
// 0x5fd bytes when bit 0 of flags is set.
static void *THISCALL guideDtor(u8 *self, u32 flags) {
  U32(self, 0) = 0x6b79d0;
  ext_480fd0(self + 0x523);
  ext_480fd0(self + 0x4ab);
  ext_480fd0(self + 0x3eb);
  ext_480fd0(self + 0x3d3);
  ext_4878d0(self);
  if (flags & 1)
    ext_634273(self, 0x5fd);
  return self;
}
PCREG(5e1450, guideDtor);

// 0x5e4600 ZFFHeroMovementGuide::GetAnims() [GC 8009230c, medium; vtable slot 8], thiscall, no args. Base GetAnims,
// then +0x5e5 = own slot 0x58("Climb_Ladder") (the string at 0x68d410: find the animation), then slot 0x54(&+0x5e5).
static void THISCALL guideGetAnims(u8 *self) {
  ext_488bc0(self);
  U32(self, 0x5e5) = vcall<u32>(self, 0x58, (const char *)0x68d410);
  vcall<void>(self, 0x54, self + 0x5e5);
}
PCREG(5e4600, guideGetAnims);

// 0x5e5bc0 ZFFHeroMovementGuide::Load(ZLoadGame *lg) [GC 80092378, medium; vtable slot 14], thiscall, ret 4, AL = 1.
// Base Load; then the saved ladder-list handle is read with lg's slot 0x40 and turned back into the object with the
// engine's geom table ([engine+0x9b] slot 0x58), stored at +0x54c.
static bool THISCALL guideLoad(u8 *self, void *lg) {
  ext_489350(self, lg);
  u32 h;
  vcall<void>(lg, 0x40, &h);
  U32(self, 0x54c) = vcall<u32>((void *)U32(G(u32, 0x70039c), 0x9b), 0x58, h);
  return true;
}
PCREG(5e5bc0, guideLoad);

// 0x5e7150 ZFFHeroMovementGuide::Save(ZSaveGame *sg) [GC 800923b8, medium; vtable slot 13], thiscall, ret 4, AL = 1.
// Base Save, then sg's slot 0x64(+0x54c) writes the ladder list.
static bool THISCALL guideSave(u8 *self, void *sg) {
  ext_489d00(self, sg);
  vcall<void>(sg, 0x64, U32(self, 0x54c));
  return true;
}
PCREG(5e7150, guideSave);
