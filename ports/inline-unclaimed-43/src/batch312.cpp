// batch312.cpp - ZFFActor::PerformDrop(ZItem *item) (core-todo residue-02). 0x5a1a60, thiscall (this = ECX), one stack
// argument, ret 4. GameCube reference (name map, high). Body: eng = g_pSysInterface; if eng->[0x1b5d] == 1:
// obj = eng->[0x9b] slot 0x138(); obj slot 0x88("rWeaponRecycleList", &list); AddWeapon 0x5e9300(list, item) (thiscall).
// Then ZLNKWHANDS::PerformDrop 0x4748b0(this, item) (thiscall, original code; hooked in the spec).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" void THISCALL ext_5e9300(u8 *list, u32 item);     // ZWeaponRecycleList::AddWeapon (ecx list, stack item)
extern "C" void THISCALL ext_4748b0(u8 *self, u32 item);     // ZLNKWHANDS::PerformDrop (ecx self, stack item)

static void THISCALL actorPerformDrop(u8 *self, u32 item) {
  u8 *eng = (u8 *)G(u32, 0x70039c);
  if (U32(eng, 0x1b5d) == 1) {
    u8 *obj = vcall<u8 *>((void *)U32(eng, 0x9b), 0x138);
    u32 list = 0;
    vcall<void>((void *)obj, 0x88, (u32)0x6acf30u, (void *)&list);
    ext_5e9300((u8 *)(unsigned long)list, item);
  }
  ext_4748b0(self, item);
}
PCREG(5a1a60, actorPerformDrop);
