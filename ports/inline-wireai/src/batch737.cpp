// batch737.cpp - ZFFActor::CreateLnkAction(unsigned int id) (0x59f070) [medium], residue 11 slice (2026-10-12).
// id 0x11: new(0x51), then ZFFActorActionCloseCombat ctor (0x5eae20) with (0x11, this, this+0x7b2, this+0x7ae).
// id 0x12 / 0x13: new(0x21), then the action ctor 0x5eaee0 with (id, this, this+0x7b6).
// Any other id: ZLNKWHANDS::CreateLnkAction (0x4733d0) on this with id, its result returned.
// The ctors return eax, which is returned as is. A null allocation returns 0. SEH frame not ported.
#include "ff.h"

extern "C" void *__attribute__((cdecl)) ext_41e290(u32 size);                                       // operator new
extern "C" u32 THISCALL ext_5eae20(void *p, u32 id, u8 *owner, u32 a, u32 b);                       // close-combat action ctor
extern "C" u32 THISCALL ext_5eaee0(void *p, u32 id, u8 *owner, u32 a);                              // action ctor (ids 0x12, 0x13)
extern "C" u32 THISCALL ext_4733d0(void *self, u32 id);                                             // ZLNKWHANDS::CreateLnkAction

// 0x59f070 ZFFActor::CreateLnkAction(unsigned int id) [medium].
static u32 THISCALL actor_CreateLnkAction(u8 *self, u32 id) {
  if (id == 0x11) {
    void *p = ext_41e290(0x51);
    if (!p)
      return 0;
    return ext_5eae20(p, 0x11, self, *(u32 *)(self + 0x7b2), *(u32 *)(self + 0x7ae));
  }
  if (id == 0x12 || id == 0x13) {
    void *p = ext_41e290(0x21);
    if (!p)
      return 0;
    return ext_5eaee0(p, id, self, *(u32 *)(self + 0x7b6));
  }
  return ext_4733d0(self, id);
}
PCREG(59f070, actor_CreateLnkAction);
