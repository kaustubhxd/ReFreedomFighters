// u18_14.cpp - core-todo residue 17 (unclaimed-18 thread): ZActor::SetInitialPosDir (0x47be10). Engine slot 0x114
// (RegisterZMsg, four arguments) and slot 0x128 (three arguments on the geom classes, ret 0xc).
#include "ff.h"

static inline u8 *sys() { return G(u8 *, 0x70039c); }
static inline u8 *engineDb() { return *(u8 **)(sys() + 0x9b); }

// 0x47be10, ZActor::SetInitialPosDir(const float* pos, const float* dir) (GC name medium/low). thiscall, two stack args
// (ret 8). Stores the position at +0x628 and the direction at +0x634 (three floats each), then registers the message
// "NewInitialPosDir" (file zactor.cpp, line 0x291) and sends its id to the actor through slot 0x128.
static void THISCALL actorSetInitialPosDir(u8 *self, const u32 *pos, const u32 *dir) {
  for (int q = 0; q < 3; ++q)
    *(u32 *)(self + 0x628 + 4 * q) = pos[q];
  for (int q = 0; q < 3; ++q)
    *(u32 *)(self + 0x634 + 4 * q) = dir[q];
  u16 id = vcall<u16>(engineDb(), 0x114, (const char *)0x68a9f4, 0u, (const char *)0x68a7c4, 0x291u);
  vcall<void>(self, 0x128, (u32)id, 0u, 0u);   // the two leftover pushes of the exe reach slot 0x128 as arguments 2 and 3
}
PCREG(47be10, actorSetInitialPosDir);
