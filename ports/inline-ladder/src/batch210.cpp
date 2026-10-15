// batch210.cpp - the ladder object's controller (inline-ladder thread, 2026-10-11): ZT1GuideController.
// The ladder in the level data is the GMS spline object Tower_T1Guide_* (class 0x4000022, docs/25); this controller
// registers it in the engine list "T1GuideList" (the list ZFFHeroMovementGuide walks in WantControl, +0x54c) and answers
// MSG_GETCAMERAPLANE with a geom reference (+0x4a) read from the event data. All names here are GC names.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define U16(p, off) (*(u16 *)((u8 *)(p) + (off)))

extern "C" long double THISCALL ext_4e5e80(void *db);   // DBREAD::operator float (ST0)
extern "C" u32 THISCALL ext_4e5e60(void *db);           // DBREAD::operator unsigned int
extern "C" void THISCALL ext_4db500(void *geom, float *out);   // ZBaseGeom::GetPos (batch 29)

static const char *const kMsg = (const char *)0x694cec;    // "MSG_GETCAMERAPLANE"
static const char *const kFile = (const char *)0x694ad8;   // "..\..\code\engine\eventsbase\eventsbase.cpp"
static const char *const kList = (const char *)0x68d404;   // "T1GuideList"
static const char *const kZList = (const char *)0x67f610;  // "ZLIST"

static inline void *db() { return (void *)U32(G(u32, 0x70039c), 0x9b); }   // ZEngineDataBase

// 0x4c61a0 ZT1GuideController::CopyEventDataBlock(DBREAD &d) [high; vtable slot 1], thiscall, ret 4.
// Reads one float (discarded) and one unsigned (the camera-plane geom reference) into +0x4a.
static void THISCALL t1CopyEventDataBlock(u8 *self, void *d) {
  (void)ext_4e5e80(d);
  U32(self, 0x4a) = ext_4e5e60(d);
}
PCREG(4c61a0, t1CopyEventDataBlock);

// 0x4c61c0 ZT1GuideController::Init() [low (string match; GC body has the same strings and calls)],
// thiscall, no args. +0x48 = RegisterZMsg("MSG_GETCAMERAPLANE", 0, file, 0x3a0) (database slot 0x114). The list
// "T1GuideList" is looked up in the database's +0xadc object (slot 0x25c) and created as a "ZLIST" (slot 0x294) when
// missing. The controller's geom (+0x44) gets the position of its own +8 geom (ZBaseGeom::GetPos, then slot 0x70), is
// added to the list (slot 0x218), and both the camera-plane geom (GeomRefToPtr = database slot 0x58 of +0x4a, when it
// exists) and the controller's geom get slot 0xbc(1).
static void THISCALL t1Init(u8 *self) {
  U16(self, 0x48) = (u16)vcall<u32>(db(), 0x114, kMsg, 0u, kFile, 0x3a0u);
  void *list = vcall<void *>((void *)U32(db(), 0xadc), 0x25c, kList, 0u);
  if (!list)
    list = vcall<void *>((void *)U32(db(), 0xadc), 0x294, kList, kZList, (void *)0, 1u);
  float pos[3];
  ext_4db500((void *)U32(U32(self, 0x44), 8), pos);
  vcall<void>((void *)U32(self, 0x44), 0x70, pos);
  vcall<void>(list, 0x218, U32(self, 0x44));
  void *cam = vcall<void *>(db(), 0x58, U32(self, 0x4a));
  if (cam)
    vcall<void>(cam, 0xbc, 1u);
  vcall<void>((void *)U32(self, 0x44), 0xbc, 1u);
}
PCREG(4c61c0, t1Init);

// 0x4c62c0 ZT1GuideController::Command(unsigned short msg, void *data) [high; vtable slot 17], thiscall,
// ret 8, returns 0. For MSG_GETCAMERAPLANE (the registered id at +0x48, when non-zero) with a data pointer, writes the
// camera-plane geom reference +0x4a to it.
static u32 THISCALL t1Command(u8 *self, u32 msg, u32 *data) {
  u16 id = U16(self, 0x48);
  if (id != 0 && (u16)msg == id && data)
    *data = U32(self, 0x4a);
  return 0;
}
PCREG(4c62c0, t1Command);

// 0x4c62f0 ZT1GuideController::Save(ZSaveGame *s) [high; vtable slot 7], thiscall, ret 4, AL = 1.
// Clears flag bit 0x40 of +4, writes +0x4a (stream slot 0x3c).
static bool THISCALL t1Save(u8 *self, void *s) {
  U32(self, 4) &= ~0x40u;
  vcall<void>(s, 0x3c, U32(self, 0x4a));
  return true;
}
PCREG(4c62f0, t1Save);

// 0x4c6310 ZT1GuideController::Load(ZLoadGame *l) [low], thiscall, ret 4, AL = 1. Clears bit 0x40 of +4,
// reads +0x4a (stream slot 0x40), registers MSG_GETCAMERAPLANE again (line 0x396) into +0x48.
static bool THISCALL t1Load(u8 *self, void *l) {
  U32(self, 4) &= ~0x40u;
  vcall<void>(l, 0x40, self + 0x4a);
  U16(self, 0x48) = (u16)vcall<u32>(db(), 0x114, kMsg, 0u, kFile, 0x396u);
  return true;
}
PCREG(4c6310, t1Load);
