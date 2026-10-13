// batch708.cpp - soldier AI, batch 708 (2026-10-11): ZFFActor::ClassCommand, the soldier's engine-message dispatcher.
// Message ids are registered in ZFFActor::ZFFActor (0x59d580) into u16 globals:
//   0x7142d0 "WeaponFired", 0x7142d4 "DamageInfo", 0x7142d8 "ProjectileHit", 0x7142dc "SE_ProjectileHit",
//   0x7142e0 "HitObject", 0x7142e4 "ObjectVisible", 0x7142e8 "ObjectNotVisible".
#include "ff.h"

extern "C" u32 THISCALL ext_477950(void *, u32, void *);     // ZActor::ClassCommand
extern "C" void THISCALL ext_5ab0d0(void *, u32);            // unnamed (called on the hero's +0x852 -> +0x1d0f object)
extern "C" void THISCALL ext_589980(void *, void *);         // ZFFGameData::SSquad::AddTarget
extern "C" void THISCALL ext_5a0e60(void *, void *, void *); // ZTargetManager::ObjectVisible
extern "C" void THISCALL ext_5a0e10(void *, void *, void *); // ZTargetManager::ObjectNotVisible

static inline void *geom_of(u32 ref) {
  void *db = *(void **)(*(u8 **)0x70039c + 0x9b);
  return vcall<void *>(db, 0x58, ref);
}

// 0x59e080 ZFFActor::ClassCommand(unsigned short, void*) [high]. Returns 0.
//  WeaponFired: slot 0x4d4; if +0x92e (the hero, inferred) is set and my team index is 0, 0x5ab0d0(1) on the hero's
//    +0x852 -> +0x1d0f object; counts down byte +0x79e and sets +0x79f when it reaches 0; then the ZActor handler.
//  DamageInfo: slot 0x6c0(data), then the ZActor handler. ProjectileHit: slot 0x6c4(data) only.
//  HitObject: +0x907 = data+0x44 (what was hit); +0x90b counts consecutive hits on something other than slot 0x4c4's
//    answer (reset to 0 otherwise); +0x8fb..+0x903 = data+0x28..+0x30 (hit position).
//  Message +0x128 while +0x90f is set: reads "lAnimId" from the data block (slot 0x88); +0x90f is cleared when it is not
//    greater than that id; then the ZActor handler.
//  ObjectVisible: the squad (+0x921) gets AddTarget(team record) when the object is a 0x200006-derived geom with a team;
//    then the target manager (+0x92a) filters it (0x5a0e60). Without a target manager: the ZActor handler.
//  ObjectNotVisible: target manager 0x5a0e10, else the ZActor handler. Anything else: the ZActor handler.
static u32 THISCALL ffactor_ClassCommand(u8 *self, u32 id, u8 *data) {
  u16 m = (u16)id;
  if (m == G(u16, 0x7142d0)) {
    vcall<void>(self, 0x4d4);
    u8 *h = *(u8 **)(self + 0x92e);
    if (h && *(u32 *)(*(u8 **)(self + 0x54) + 4) == 0)
      ext_5ab0d0(*(void **)(*(u8 **)(h + 0x852) + 0x1d0f), 1);
    if (--*(u8 *)(self + 0x79e) == 0)
      *(u8 *)(self + 0x79f) = 1;
  } else if (m == G(u16, 0x7142d4)) {
    vcall<void>(self, 0x6c0, data);
    ext_477950(self, id, data);
    return 0;
  } else if (m == G(u16, 0x7142d8)) {
    vcall<void>(self, 0x6c4, data);
    return 0;
  } else if (m == G(u16, 0x7142e0)) {
    u32 hit = *(u32 *)(data + 0x44);
    *(u32 *)(self + 0x907) = hit;
    if (hit != 0 && vcall<u32>(self, 0x4c4) != *(u32 *)(self + 0x907))
      ++*(u32 *)(self + 0x90b);
    else
      *(u32 *)(self + 0x90b) = 0;
    *(u32 *)(self + 0x8fb) = *(u32 *)(data + 0x28);
    *(u32 *)(self + 0x8ff) = *(u32 *)(data + 0x2c);
    *(u32 *)(self + 0x903) = *(u32 *)(data + 0x30);
    return 0;
  } else if (*(s32 *)(self + 0x90f) != 0 && m == *(u16 *)(self + 0x128)) {
    s32 anim;
    vcall<void>(data, 0x88, (const char *)0x6ae82c, &anim);   // "lAnimId"
    if (!(*(s32 *)(self + 0x90f) > anim)) {
      *(s32 *)(self + 0x90f) = 0;
      ext_477950(self, id, data);
      return 0;
    }
  } else if (m == G(u16, 0x7142e4)) {
    if (*(void **)(self + 0x921)) {
      u8 *g = (u8 *)geom_of((u32)data);
      if (vcall<bool>(g, 0x1e0, 0x200006) && *(void **)(g + 0x54))
        ext_589980(*(void **)(self + 0x921), *(void **)(g + 0x54));
    }
    if (*(void **)(self + 0x92a)) {
      ext_5a0e60(*(void **)(self + 0x92a), self, geom_of((u32)data));
      return 0;
    }
  } else if (m == G(u16, 0x7142e8)) {
    if (*(void **)(self + 0x92a)) {
      ext_5a0e10(*(void **)(self + 0x92a), self, geom_of((u32)data));
      return 0;
    }
  }
  ext_477950(self, id, data);
  return 0;
}
PCREG(59e080, ffactor_ClassCommand);
