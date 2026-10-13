// batch733.cpp - soldier AI, batch 733 (2026-10-12): ZFFActor::ClassInit2() (0x59e350) [medium]. The base class init (vtable
// slot 0x110 with (0x10, 0), then ZActor::ClassInit2 0x477de0) runs first. Then the object's slot 0x678 gives an id, the db
// slot 0x58 maps it to a geom, and the geom's slot 0x100 with the string "CheckVisible" gives the id stored at +0x8ee. The
// object's slot 0x6f4 (1, 1) and slot 0x6cc follow, and the function ends with a tail call to ZFFActor::InitSounds (0x5a04f0).
#include "ff.h"

extern "C" void THISCALL ext_477de0(void *self);   // ZActor::ClassInit2
extern "C" void THISCALL ext_5a04f0(void *self);   // ZFFActor::InitSounds

// 0x59e350 ZFFActor::ClassInit2() [medium].
static void THISCALL actor_ClassInit2(u8 *self) {
  vcall<void>(self, 0x110, 0x10u, 0u);
  ext_477de0(self);

  void *db = *(void **)((u8 *)*(void **)0x70039c + 0x9b);
  u32 id0 = vcall<u32>(self, 0x678);
  void *geom = vcall<void *>(db, 0x58, id0);
  u32 id1 = vcall<u32>(geom, 0x100, (const char *)0x690428);   // "CheckVisible"
  *(u32 *)(self + 0x8ee) = id1;

  vcall<void>(self, 0x6f4, 1u, 1u);
  vcall<void>(self, 0x6cc);
  ext_5a04f0(self);
}
PCREG(59e350, actor_ClassInit2);
