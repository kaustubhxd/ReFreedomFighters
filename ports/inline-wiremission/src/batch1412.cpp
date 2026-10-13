// batch1412.cpp - missions thread, batch 1412: ZFFCareTaker_C01A (the first level's director) small members.
//
// ZFFCareTaker_C01A fields used here: +0x04 flags, +0x58 hero (ZFFHERO, "HitmanGround"), +0x5c dword (saved with
// ZSaveGame slot 0x44), +0x60/+0x61 bytes, +0xb4 a copy of the engine timer [sys+0x40], +0xb8 byte, +0xb9 time
// (timer + 0x1400 at Init2), +0xbe float[3] hero position at Init2.
#include "missions.h"

extern "C" void THISCALL ext_6352f0(u8 *ev, u32 *db);   // ZEventBase::GetInput(DBREAD&)
extern "C" void THISCALL ext_5ba590(u8 *ct, u32 *db);   // ZFFCareTaker_C01A::ReadInput(DBREAD&)

static inline u8 *sysi() { return G(u8 *, 0x70039c); }
static inline u8 *mgr() { return *(u8 **)(sysi() + 0x9b); }
static inline void copyTimer(u8 *ct) {   // operator= with a self-assignment check
  if (ct + 0xb4 != sysi() + 0x40)
    *(u32 *)(ct + 0xb4) = *(u32 *)(sysi() + 0x40);
}

// 0x5ba2e0 ZFFCareTaker_C01A::Init(): reads the event data block (GetInput) and parses it (ReadInput).
static void THISCALL c01aInit(u8 *ct) {
  u32 db = 0;
  ext_6352f0(ct, &db);
  ext_5ba590(ct, &db);
}
PCREG(5ba2e0, c01aInit);

// 0x5ba220 ZFFCareTaker_C01A::Init2(): finds the hero ("HitmanGround") into +0x58 and sets its byte +0x9f4,
// copies the timer to +0xb4, schedules +0xb9 = timer + 0x1400, clears +0xb8, and stores the hero's position
// (hero slot 0x84) at +0xbe.
static void THISCALL c01aInit2(u8 *ct) {
  u8 *reg = vcall<u8 *>(mgr(), 0x138);
  u32 h = 0;
  vcall<u32, const char *, u32 *>(reg, 0x88, (const char *)0x681320, &h);
  u8 *hero = vcall<u8 *, u32>(mgr(), 0x58, h);
  *(u8 **)(ct + 0x58) = hero;
  hero[0x9f4] = 1;
  copyTimer(ct);
  *(u32 *)(ct + 0xb9) = *(u32 *)(sysi() + 0x40) + 0x1400;
  ct[0xb8] = 0;
  float *p = (float *)(ct + 0xbe);
  ((u32 *)p)[0] = 0;
  ((u32 *)p)[1] = 0;
  ((u32 *)p)[2] = 0;
  vcall<void, float *>(*(u8 **)(ct + 0x58), 0x84, p);
}
PCREG(5ba220, c01aInit2);

// 0x5ba790 ZFFCareTaker_C01A::Save(ZSaveGame*): +0x5c (slot 0x44), +0x60, +0x61 (bools), the hero reference,
// +0xb8 (bool), +0xb9 (slot 0x54, by value). Returns true.
static u8 THISCALL c01aSave(u8 *ct, u8 *sg) {
  *(u32 *)(ct + 4) &= ~0x40u;
  vcall<void, u32>(sg, 0x44, *(u32 *)(ct + 0x5c));
  vcall<void, u32>(sg, 0x60, (u32)ct[0x60]);
  vcall<void, u32>(sg, 0x60, (u32)ct[0x61]);
  vcall<void, u32>(sg, 0x64, *(u32 *)(ct + 0x58));
  vcall<void, u32>(sg, 0x60, (u32)ct[0xb8]);
  vcall<void, u32>(sg, 0x54, *(u32 *)(ct + 0xb9));
  return 1;
}
PCREG(5ba790, c01aSave);

// 0x5ba4e0 ZFFCareTaker_C01A::Load(ZLoadGame*): re-reads the event data, then the mirror of Save (the hero through
// the manager's slot 0x58), and re-copies the timer. Returns true.
static u8 THISCALL c01aLoad(u8 *ct, u8 *lg) {
  u32 db = 0;
  *(u32 *)(ct + 4) &= ~0x40u;
  ext_6352f0(ct, &db);
  ext_5ba590(ct, &db);
  vcall<void, u8 *>(lg, 0x48, ct + 0x5c);
  vcall<void, u8 *>(lg, 0x68, ct + 0x60);
  vcall<void, u8 *>(lg, 0x68, ct + 0x61);
  u32 ref = (u32)lg;   // the original reads into its argument slot
  vcall<void, u32 *>(lg, 0x40, &ref);
  *(u32 *)(ct + 0x58) = vcall<u32, u32>(mgr(), 0x58, ref);
  vcall<void, u8 *>(lg, 0x68, ct + 0xb8);
  vcall<void, u8 *>(lg, 0x58, ct + 0xb9);
  copyTimer(ct);
  return 1;
}
PCREG(5ba4e0, c01aLoad);

extern "C" float THISCALL ext_58b9c0(u8 *hero, float delta, u32 a, u32 b);   // ZFFHERO::AdjustHitPoints, x87 return
extern "C" void THISCALL ext_596940(u8 *osd, u32 kind, float *pos, u32 flag, s32 n);   // ZGameOSD::CharismaAddExperience
#define CARETAKER_C01A_CPP 0x6b290cu

// 0x5b9d50 ZFFCareTaker_C01A::Command(unsigned short msg, void *data). Message ids are cached in the object:
//  +0x72 CompletedAct (data = act index): logs "Completed tutorial Act %i" with the index, then for act number
//    (index + 1) 5 takes 20 hit points from a hero at full health (the first-aid lesson), 8 clears the hero's byte
//    +0x9f5, 9 sets it and gives charisma experience 7 at the +0x4c actor's position (50 units up). The next act
//    (act number, 6 becomes 7: act 7 is skipped) is sent as message +0x74 to the objects at +0x50 and +0x4c, and
//    stored at +0x5c.
//  +0x7c: once (+0x63), message +0x7a with 0 to +0xb0, and the hero loses 40% of its hit points.
//  +0x7e: sets +0x62.
// Returns 0.
static u32 THISCALL c01aCommand(u8 *ct, u32 msg, u32 data) {
  u16 m = (u16)msg;
  if (m == *(u16 *)(ct + 0x72)) {
    LOGF(CARETAKER_C01A_CPP, 0xb8, (const char *)0x6b2978, data);
    u32 act = data + 1;
    if (act == 5) {
      u8 *hero = *(u8 **)(ct + 0x58);
      if (comiss_ge(*(float *)(hero + 0x7ff), *(float *)(hero + 0x7fb)))
        ext_58b9c0(hero, -20.0f, 0, 0);
    } else if (act == 8) {
      (*(u8 **)(ct + 0x58))[0x9f5] = 0;
    } else if (act == 9) {
      (*(u8 **)(ct + 0x58))[0x9f5] = 1;
      float mat[9], pos[3];
      u8 *actor = *(u8 **)(ct + 0x4c);
      void **vt = *(void ***)actor;
      u32 r = ((u32(THISCALL *)(u8 *, float *, float *))vt[0x3a0 / 4])(actor, mat, pos);
      ((void(THISCALL *)(u8 *, u32))vt[0x390 / 4])(*(u8 **)(ct + 0x4c), r);
      u8 *g = vcall<u8 *>(*(u8 **)(ct + 0x4c), 0x20);
      vcall<void, float *>(g, 0x84, pos);
      pos[1] = pos[1] + 50.0f;
      ext_596940(*(u8 **)(*(u8 **)(ct + 0x58) + 0x852), 7, pos, 1, -1);
    }
    u32 next = act == 6 ? 7 : act;
    vcall<void, u32, u32, u32>(*(u8 **)(ct + 0x44), 0x130, *(u32 *)(ct + 0x50), (u32) * (u16 *)(ct + 0x74), next);
    vcall<void, u32, u32, u32>(*(u8 **)(ct + 0x44), 0x130, *(u32 *)(ct + 0x4c), (u32) * (u16 *)(ct + 0x74), next);
    *(u32 *)(ct + 0x5c) = next;
    return 0;
  }
  if (m == *(u16 *)(ct + 0x7c)) {
    if (!ct[0x63]) {
      vcall<void, u32, u32, u32>(*(u8 **)(ct + 0x44), 0x130, *(u32 *)(ct + 0xb0), (u32) * (u16 *)(ct + 0x7a), 0);
      u8 *hero = *(u8 **)(ct + 0x58);
      ct[0x63] = 1;
      ext_58b9c0(hero, *(float *)(hero + 0x7ff) * -0.4f, 0, 0);
    }
    return 0;
  }
  if (m == *(u16 *)(ct + 0x7e))
    ct[0x62] = 1;
  return 0;
}
PCREG(5b9d50, c01aCommand);

extern "C" u32 THISCALL ext_4e5e60(u32 *db);         // DBREAD::operator unsigned int() (Get32, Next)
extern "C" void THISCALL ext_5d1440(u8 *cam);        // ZCamHelper::ResetFocus()
extern "C" void THISCALL ext_5b9c00(u8 *ct, u32 actor, u8 *geom);   // ZFFCareTaker_C01A::BeamActor (debug log + move)

// 0x5ba590 ZFFCareTaker_C01A::ReadInput(DBREAD&): 16 scene-object handles from the event data, each resolved through
// the manager's slot 0x58: +0x50 (Jones), +0x4c (Bagzton), +0x54, the 11 act start groups +0x84..+0xac, +0x6e, +0xb0.
extern "C" void THISCALL m_5ba590(u8 *ct, u32 *db) {
  static const u16 offs[17] = {0x50, 0x4c, 0x54, 0x84, 0x88, 0x8c, 0x90, 0x94, 0x98,
                               0x9c, 0xa0, 0xa4, 0xa8, 0xac, 0x6e, 0xb0, 0};
  for (int i = 0; i < 16; i++) {
    u32 h = ext_4e5e60(db);
    *(u32 *)(ct + offs[i]) = vcall<u32, u32>(mgr(), 0x58, h);
  }
}
PCREG(5ba590, m_5ba590);

// 0x5ba310 ZFFCareTaker_C01A::JumpToAct(int act) (debug act skip): the act's start group (+0x84 + 4*act) gives
// HeroStartPos (the hero is teleported there, camera helper "ZCamHelper" created on demand and refocused),
// JonesStartPos and BagztonStartPos (those actors are beamed there). Act 5 takes 20 hit points from a hero at full
// health, acts 8 and 9 clear the hero's +0x9f5, act 10 sets it; then the act is sent like Command does.
static void THISCALL c01aJumpToAct(u8 *ct, s32 act) {
  u32 groups[11];
  for (int i = 0; i < 11; i++) groups[i] = *(u32 *)(ct + 0x84 + 4 * i);
  u8 *grp = (u8 *)groups[act];
  if (!grp)
    return;
  u8 *start = vcall<u8 *, const char *, u32>(grp, 0x25c, (const char *)0x6b29c8, 0);   // HeroStartPos
  if (start) {
    float mat[9], pos[3];
    vcall<void, float *, float *>(start, 0x80, mat, pos);
    u8 *hero = *(u8 **)(ct + 0x58);
    if (!*(u32 *)(hero + 0x85a))
      *(u32 *)(hero + 0x85a) = vcall<u32, const char *>(hero, 0x100, (const char *)0x6a6e88);   // ZCamHelper
    ext_5d1440(*(u8 **)(hero + 0x85a));
    vcall<void, float *, float *>(*(u8 **)(ct + 0x58), 0x370, mat, pos);
  }
  u8 *j = vcall<u8 *, const char *, u32>(grp, 0x25c, (const char *)0x6b29d8, 0);   // JonesStartPos
  if (j)
    ext_5b9c00(ct, *(u32 *)(ct + 0x50), j);
  u8 *b = vcall<u8 *, const char *, u32>(grp, 0x25c, (const char *)0x6b29e8, 0);   // BagztonStartPos
  if (b)
    ext_5b9c00(ct, *(u32 *)(ct + 0x4c), b);
  if (act == 5) {
    u8 *hero = *(u8 **)(ct + 0x58);
    if (comiss_ge(*(float *)(hero + 0x7ff), *(float *)(hero + 0x7fb)))
      ext_58b9c0(hero, -20.0f, 0, 0);
  } else if (act == 9 || act == 8) {
    (*(u8 **)(ct + 0x58))[0x9f5] = 0;
  } else if (act == 10) {
    (*(u8 **)(ct + 0x58))[0x9f5] = 1;
  }
  vcall<void, u32, u32, u32>(*(u8 **)(ct + 0x44), 0x130, *(u32 *)(ct + 0x50), (u32) * (u16 *)(ct + 0x74), (u32)act);
  vcall<void, u32, u32, u32>(*(u8 **)(ct + 0x44), 0x130, *(u32 *)(ct + 0x4c), (u32) * (u16 *)(ct + 0x74), (u32)act);
  *(s32 *)(ct + 0x5c) = act;
}
PCREG(5ba310, c01aJumpToAct);
