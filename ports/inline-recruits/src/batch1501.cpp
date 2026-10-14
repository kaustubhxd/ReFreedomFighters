// batch1501.cpp - recruits thread, batch 1501: the squad order layer of ZGameOSD (recruit, follow, defend, form,
// attack, scout), from the key handlers down to CommandAllRecruits / CommandOneRecruit.
//
// RECRUIT_COMMAND values seen here: 0 = defend (hold position), 3 = scout ahead, 4 = attack target, 5 = form up
// (regroup on the hero). Hero command animations (ZFFHERO::PlayCommandAnim): 0 = point (attack/scout), 1 = defend,
// 2 = form. Command sounds (ZFFHERO::PlaySound_Command): 0x0b attack, 0x0d defend, 0x0f form, 0x11 recruit,
// 0x13/0x15 scout (picked at random, 50/50). The bool sound argument is "all" (1) versus "one" (0).
#include "ff.h"

extern "C" void THISCALL ext_593f40(u8 *hero, u32 anim);              // ZFFHERO::PlayCommandAnim
extern "C" u32 THISCALL ext_594040(u8 *hero, u32 sound, u32 all);     // ZFFHERO::PlaySound_Command
extern "C" void THISCALL ext_596d70(u8 *osd, u32 cmd, u32 b);         // ZGameOSD::CommandAllRecruits
extern "C" void THISCALL ext_596ef0(u8 *osd, u32 cmd, u32 b);         // ZGameOSD::CommandOneRecruit
extern "C" u32 THISCALL ext_59ffc0(u8 *actor);                         // ZFFActor actor mode (+0x77f), batch 48
extern "C" u32 THISCALL ext_5cda40(u8 *camhelper);                     // ZCamHelper::CommandPointerAtEnemy
extern "C" u32 THISCALL ext_597720(u8 *osd, float *dist);              // ZGameOSD::FindNextRecruit
extern "C" void THISCALL ext_5967b0(u8 *osd, u32 id);                  // ZGameOSD::AddRecruit
extern "C" void THISCALL ext_597b50(u8 *osd);                          // ZGameOSD::PurgeOneWoundedIfFull
extern "C" void THISCALL ext_5a1ac0(u8 *actor, u32 snd, u32 v, u32 b); // ZFFActor::PlaySound_Command

#define HERO(self) (*(u8 **)((self) + 0x1d0b))
#define LAST_SOUND(self) (*(u32 *)((self) + 0xdd))

// Engine object table: system object 0x70039c, +0x9b. Slot 0x58 = object from id, slot 0x4c = id of object.
static inline void *objTable() { return *(void **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x597640 (unnamed in the GC map; DefendAll by its body), thiscall, plain ret.
static void THISCALL defendAll(u8 *self) {
  ext_593f40(HERO(self), 1);
  LAST_SOUND(self) = ext_594040(HERO(self), 0xd, 1);
  ext_596d70(self, 0, 0);
}
PCREG(597640, defendAll);

// 0x597f70 (DefendOne by its body), thiscall, plain ret.
static void THISCALL defendOne(u8 *self) {
  ext_593f40(HERO(self), 1);
  LAST_SOUND(self) = ext_594040(HERO(self), 0xd, 0);
  ext_596ef0(self, 0, 0);
}
PCREG(597f70, defendOne);

// 0x597930 (FormAll by its body), thiscall, plain ret. Also sends the hero the "form" event id stored at +0x1d2f
// (vtable slot 0x128 = send event (id, data, 0)).
static void THISCALL formAll(u8 *self) {
  ext_593f40(HERO(self), 2);
  u8 *hero = HERO(self);
  LAST_SOUND(self) = ext_594040(hero, 0xf, 1);
  hero = HERO(self);
  vcall<void>(hero, 0x128, (u32) * (u16 *)(self + 0x1d2f), 0u, 0u);
  ext_596d70(self, 5, 0);
}
PCREG(597930, formAll);

// 0x597980 (FormOne by its body), thiscall, plain ret.
static void THISCALL formOne(u8 *self) {
  ext_593f40(HERO(self), 2);
  LAST_SOUND(self) = ext_594040(HERO(self), 0xf, 0);
  ext_596ef0(self, 5, 0);
}
PCREG(597980, formOne);

// 0x5968c0 ZGameOSD::AttackTargetAll(), thiscall, plain ret. Sound first, then the animation (One does the opposite).
static void THISCALL attackTargetAll(u8 *self) {
  LAST_SOUND(self) = ext_594040(HERO(self), 0xb, 1);
  ext_593f40(HERO(self), 0);
  ext_596d70(self, 4, 0);
}
PCREG(5968c0, attackTargetAll);

// 0x596900 ZGameOSD::AttackTargetOne(), thiscall, plain ret.
static void THISCALL attackTargetOne(u8 *self) {
  ext_593f40(HERO(self), 0);
  LAST_SOUND(self) = ext_594040(HERO(self), 0xb, 0);
  ext_596ef0(self, 4, 0);
}
PCREG(596900, attackTargetOne);

typedef float(THISCALL *vcallRandF)(void *self, const char *file, u32 line);
// Engine random number in [0, 1): system object slot 0x1c0 (file, line), result on the x87 stack.
static inline float sysRandom(u32 line) {
  u8 *sys = G(u8 *, 0x70039c);
  return ((vcallRandF)(*(void ***)sys)[0x1c0 / 4])(sys, (const char *)0x6ad250, line);
}

// 0x597e90 ZGameOSD::ScoutAheadAll(), thiscall, plain ret. Random pick between two scout sounds (r > 0.5 picks 0x13;
// a NaN picks 0x15). The random call is made from ZGameOSD.cpp line 0x36c.
static void THISCALL scoutAheadAll(u8 *self) {
  ext_593f40(HERO(self), 0);
  float r = sysRandom(0x36c);
  u8 *hero = HERO(self);
  LAST_SOUND(self) = ext_594040(hero, r > 0.5f ? 0x13 : 0x15, 1);
  ext_596d70(self, 3, 0);
}
PCREG(597e90, scoutAheadAll);

// 0x597f00 ZGameOSD::ScoutAheadOne(), thiscall, plain ret (line 0x380).
static void THISCALL scoutAheadOne(u8 *self) {
  ext_593f40(HERO(self), 0);
  float r = sysRandom(0x380);
  u8 *hero = HERO(self);
  LAST_SOUND(self) = ext_594040(hero, r > 0.5f ? 0x13 : 0x15, 0);
  ext_596ef0(self, 3, 0);
}
PCREG(597f00, scoutAheadOne);

extern "C" void THISCALL ext_597c40(u8 *self);
extern "C" void THISCALL ext_597d30(u8 *self);
extern "C" void THISCALL ext_597640(u8 *self);
extern "C" void THISCALL ext_597f70(u8 *self);
extern "C" void THISCALL ext_597930(u8 *self);
extern "C" void THISCALL ext_597980(u8 *self);
extern "C" void THISCALL ext_5968c0(u8 *self);
extern "C" void THISCALL ext_596900(u8 *self);
extern "C" void THISCALL ext_597e90(u8 *self);
extern "C" void THISCALL ext_597f00(u8 *self);

// 0x59a7e0 ZGameOSD::RecruitFollow(bool all), thiscall, ret 4: RecruitAll or RecruitOne (only the low byte counts).
static void THISCALL recruitFollow(u8 *self, u32 all) {
  if ((u8)all)
    ext_597c40(self);
  else
    ext_597d30(self);
}
PCREG(59a7e0, recruitFollow);

// 0x59a7a0 ZGameOSD::RecruitDefend(bool all), thiscall, ret 4: DefendAll or DefendOne. The original also tests the
// byte at +0x1d95 but both arms are the same code, so it has no effect.
static void THISCALL recruitDefend(u8 *self, u32 all) {
  if ((u8)all)
    ext_597640(self);
  else
    ext_597f70(self);
}
PCREG(59a7a0, recruitDefend);

// Hero event to the OSD's message target (+0x44, slot 0x12c = post event (target, id, 0)) after an order, when the
// hero target +0x22df is set.
static inline void postOrderEvent(u8 *self, u32 target, u32 ev) {
  vcall<void>(*(void **)(self + 0x44), 0x12c, target, ev, 0u);
}

// 0x59a800 ZGameOSD::RecruitForm(bool all), thiscall, ret 4: FormAll/FormOne, then the event id at +0x1d39.
static void THISCALL recruitForm(u8 *self, u32 all) {
  if ((u8)all)
    ext_597930(self);
  else
    ext_597980(self);
  if (*(u32 *)(self + 0x22df))
    postOrderEvent(self, *(u32 *)(self + 0x22df), *(u16 *)(self + 0x1d39));
}
PCREG(59a800, recruitForm);

// 0x59a720 ZGameOSD::RecruitAttack(bool all), thiscall, ret 4. When the camera's command pointer is on an enemy
// (ZCamHelper +0x1d03) the order is attack (event id +0x1d37), otherwise scout ahead (event id +0x1d35).
static void THISCALL recruitAttack(u8 *self, u32 all) {
  u32 ev;
  if (ext_5cda40(*(u8 **)(self + 0x1d03))) {
    if ((u8)all)
      ext_5968c0(self);
    else
      ext_596900(self);
    if (!*(u32 *)(self + 0x22df))
      return;
    ev = *(u16 *)(self + 0x1d37);
  } else {
    if ((u8)all)
      ext_597e90(self);
    else
      ext_597f00(self);
    if (!*(u32 *)(self + 0x22df))
      return;
    ev = *(u16 *)(self + 0x1d35);
  }
  postOrderEvent(self, *(u32 *)(self + 0x22df), ev);
}
PCREG(59a720, recruitAttack);

// 0x597680 ZGameOSD::FindCurrentRecruit(int start, int step), thiscall, ret 8.
// Walks the recruit list (ids +0x1dae, count +0x1fae) from `start` by `step`, wrapping below 0 to the last entry and
// at the end to 0, and returns the first index whose actor is not in mode 5 and answers no to vtable slot 0x670;
// -1 after a full lap. A negative start means the last entry; an out-of-range start means 0.
static s32 THISCALL findCurrentRecruit(u8 *self, s32 start, s32 step) {
  s32 n = *(s32 *)(self + 0x1fae);
  s32 i = start;
  if (i < 0)
    i = n - 1;
  i = (i < n) ? i : 0;
  start = i;
  do {
    void *o = vcall<void *>(objTable(), 0x58, ((u32 *)(self + 0x1dae))[i]);
    if (ext_59ffc0((u8 *)o) != 5 && !vcall<u8>(o, 0x670))
      return i;
    i = (s32)((u32)i + (u32)step);
    if (i < 0)
      i = *(s32 *)(self + 0x1fae) - 1;
    i = (i < *(s32 *)(self + 0x1fae)) ? i : 0;
  } while (i != start);
  return -1;
}
PCREG(597680, findCurrentRecruit);

struct OrderEvent {   // the event block passed to the hero's slot 0x12c: a vtable-like type tag and the hero's id
  u32 tag;
  u32 heroId;
};

// 0x597c40 ZGameOSD::RecruitAll(), thiscall, plain ret. Plays the recruit sound, then while there is room
// (+0x1fba recruitable != +0x1fae recruited) takes the next candidate from FindNextRecruit and tells the hero to
// recruit it (slot 0x12c with the event id +0x1d2d and a "join" event tagged 0x6ad2f4), then AddRecruit.
// Nothing happens when the recruit search object +0x4f7 is null. The hero position read (slot 0x84 into a zeroed
// vector) is unused. The stack-cookie epilogue is the CRT's check and not part of the port.
static void THISCALL recruitAll(u8 *self) {
  LAST_SOUND(self) = ext_594040(HERO(self), 0x11, 1);
  if (!*(u32 *)(self + 0x4f7))
    return;
  float pos[3] = {0, 0, 0};
  vcall<void>(HERO(self), 0x84, pos);
  float dist[3];
  while (*(u32 *)(self + 0x1fba) != *(u32 *)(self + 0x1fae)) {
    u32 id = ext_597720(self, dist);
    if (!id)
      return;
    OrderEvent ev;
    ev.tag = 0x6ad2f4;
    ev.heroId = vcall<u32>(objTable(), 0x4c, HERO(self));
    vcall<void>(HERO(self), 0x12c, id, (u32) * (u16 *)(self + 0x1d2d), &ev);
    ext_5967b0(self, id);
  }
}
PCREG(597c40, recruitAll);

// 0x597d30 ZGameOSD::RecruitOne(), thiscall, plain ret. Recruits the nearest candidate (FindNextRecruit(null)).
// When the squad is full (+0x1fae >= +0x1fba, signed, checked after PurgeOneWoundedIfFull) the hero still sends
// the event, tagged 0x6ad304 ("squad full"), and the candidate plays sound 0x1b (refuse) instead of joining.
static void THISCALL recruitOne(u8 *self) {
  LAST_SOUND(self) = ext_594040(HERO(self), 0x11, 0);
  u32 id = ext_597720(self, 0);
  if (!id)
    return;
  OrderEvent ev;
  ev.heroId = vcall<u32>(objTable(), 0x4c, HERO(self));
  ext_597b50(self);
  bool room = *(s32 *)(self + 0x1fae) < *(s32 *)(self + 0x1fba);
  u8 *hero = HERO(self);
  if (room) {
    ev.tag = 0x6ad2f4;
    vcall<void>(hero, 0x12c, id, (u32) * (u16 *)(self + 0x1d2d), &ev);
    ext_5967b0(self, id);
    return;
  }
  ev.tag = 0x6ad304;
  vcall<void>(hero, 0x12c, id, (u32) * (u16 *)(self + 0x1d2d), &ev);
  u8 *a = vcall<u8 *>(objTable(), 0x58, id);
  if (a)
    ext_5a1ac0(a, 0x1b, LAST_SOUND(self), 0);
}
PCREG(597d30, recruitOne);
