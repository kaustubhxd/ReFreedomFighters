// batch732.cpp - soldier AI, batch 732 (2026-10-12): squad membership and recruit mode on ZFFActor.
//   RemoveFromSquad() (0x5a2860): if the actor has a squad (+0x921), SSquad::RemoveMember(squad, actor), then +0x921 = 0 and
//   +0x925 = -1.
//   AddToSquad(SSquad*) (0x59dce0): if SSquad::AddMember(squad, actor) returns true, +0x921 = squad.
//   SetRecruitMode(mode, bool, ZFFHERO* hero, float t) (0x5a2e20): sets +0x77f = mode; when the flag is set, a non-null hero
//   replaces +0x92e. Unless the hero is absent and the mode's class is not 2 (table 0x6adebc, stride 8), every actor in the
//   global list (gl+0x40c, count gl+0x408) is checked: a non-null actor passes when the class is 2, or when it is not the
//   hero and the class is not 0, and either the hero and the actor share the +0x54 class id or the class is not 1. A passing
//   actor gets its marker removed (mode 0) or added with type 0x6adeb8[mode] and time t, on its +0x852 object.
#include "ff.h"

extern "C" void THISCALL ext_58a360(void *squad, void *member);                       // SSquad::RemoveMember
extern "C" u8 THISCALL ext_5898c0(void *squad, void *member);                         // SSquad::AddMember (al)
extern "C" void THISCALL ext_598e10(void *mcl, void *self, u32 type, float t);        // AddActorActionMarker
extern "C" void THISCALL ext_59a850(void *mcl, void *self);                           // RemoveActorActionMarker

// 0x5a2860 ZFFActor::RemoveFromSquad() [medium].
static void THISCALL actor_RemoveFromSquad(u8 *self) {
  void *squad = *(void **)(self + 0x921);
  if (squad) {
    ext_58a360(squad, self);
    *(u32 *)(self + 0x921) = 0;
    *(u32 *)(self + 0x925) = 0xffffffffu;
  }
}
PCREG(5a2860, actor_RemoveFromSquad);

// 0x59dce0 ZFFActor::AddToSquad(ZFFGameData::SSquad*) [medium].
static void THISCALL actor_AddToSquad(u8 *self, void *squad) {
  if (ext_5898c0(squad, self))
    *(void **)(self + 0x921) = squad;
}
PCREG(59dce0, actor_AddToSquad);

// 0x5a2e20 ZFFActor::SetRecruitMode(EActorMode mode, bool flag, ZFFHERO* hero, float t) [high].
static void THISCALL actor_SetRecruitMode(u8 *self, u32 mode, u32 flag, void *hero, float t) {
  *(u32 *)(self + 0x77f) = mode;
  if (!(u8)flag)
    return;
  if (hero)
    *(void **)(self + 0x92e) = hero;
  u32 m = *(u32 *)(0x6adebc + mode * 8);
  if (*(void **)(self + 0x92e) == 0 && m != 2)
    return;

  u8 *gl = *(u8 **)0x7003b8;
  u32 **iter = (u32 **)(gl + 0x40c);
  u32 **end = iter + *(u32 *)(gl + 0x408);
  for (; iter != end; iter++) {
    u8 *actor = (u8 *)*iter;
    if (!actor)
      continue;
    void *heroNow = *(void **)(self + 0x92e);
    bool match;
    if (m == 2) {
      match = true;
    } else if (heroNow != (void *)actor && m == 0) {
      match = false;
    } else {
      u32 hc = *(u32 *)((u8 *)*(void **)((u8 *)heroNow + 0x54) + 4);
      u32 ac = *(u32 *)((u8 *)*(void **)(actor + 0x54) + 4);
      match = (hc == ac) || (m != 1);
    }
    if (!match)
      continue;
    void *mcl = *(void **)(actor + 0x852);
    if (mode == 0)
      ext_59a850(mcl, self);
    else
      ext_598e10(mcl, self, *(u32 *)(0x6adeb8 + mode * 8), t);
  }
}
PCREG(5a2e20, actor_SetRecruitMode);
