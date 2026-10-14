// batch1506.cpp - recruits thread, batch 1506: ZGameOSD::CommandRecruit, the order to one recruit.
#include "ff.h"

static inline void *objTable() { return *(void **)(G(u8 *, 0x70039c) + 0x9b); }
typedef float(THISCALL *vcallRandF)(void *self, const char *file, u32 line);

extern "C" u32 THISCALL ext_59ffc0(u8 *actor);                                   // actor mode (+0x77f)
extern "C" u8 THISCALL ext_5cfa00(u8 *cam, float *pos);                          // ZCamHelper::GetRecruitPosPrecisionAim
extern "C" void THISCALL ext_5cf3e0(u8 *cam, float *normal);                     // ZCamHelper: aim surface normal
extern "C" void THISCALL ext_5cfae0(u8 *cam, float *pos);                        // ZCamHelper::GetRecruitScoutPos
extern "C" u8 *THISCALL ext_4e1b60(void *coli);                                  // COLI::COLI
extern "C" void THISCALL ext_45bfd0(void *coli, float *normal);                  // COLI hit triangle normal
extern "C" void THISCALL ext_5a2e20(u8 *actor, u32 mode, u32 show, u8 *hero, float time);  // SetRecruitMode
extern "C" void THISCALL ext_5b7ce0(u8 *o, float p0, float p1, float p2, float n0, float n1, float n2);
extern "C" void THISCALL ext_5b7d30(u8 *o);
extern "C" void THISCALL ext_5a1ac0(u8 *actor, u32 snd, u32 v, u32 b);         // ZFFActor::PlaySound_Command

// Event block sent to the recruit with the order (slot 0x128): defend/stay, scout, form.
struct OrderPosEvent {
  u32 all;          // the "all" flag of the order (byte, zero-extended)
  u32 heroId;
  float pos[3];     // target position
  float normal[3];  // ground normal there (0, 1, 0 unless a surface was hit); not set for form
};
// Attack: {all, heroId, target (camera helper +0xd11)}.
struct OrderAttackEvent {
  u32 all, heroId, target;
};

// Ground the position: ray from pos straight down 500 units through the level collision (table +0xadc, slot 0x2e0
// (coli, 0, 0x20, -1, 1, 0)); on a hit the position becomes the hit point (+0x28), the normal the hit triangle's
// normal, transformed by the hit object (id +0x44, its slot 0x88).
static void groundPosition(float *pos, float *normal) {
  u8 c[0x90];
  ext_4e1b60(c);
  float *cf = (float *)c;
  cf[0] = pos[0];
  cf[1] = pos[1];
  cf[2] = pos[2];
  ((u32 *)c)[3] = 0;
  ((u32 *)c)[4] = 0xc3fa0000u;   // -500.0
  ((u32 *)c)[5] = 0;
  void *coll = *(void **)((u8 *)objTable() + 0xadc);
  if (!vcall<u8>(coll, 0x2e0, (void *)c, 0u, 0x20u, 0xffffffffu, 1u, 0u))
    return;
  pos[0] = *(float *)(c + 0x28);
  pos[1] = *(float *)(c + 0x2c);
  pos[2] = *(float *)(c + 0x30);
  ext_45bfd0(c, normal);
  void *o = vcall<void *>(objTable(), 0x58, *(u32 *)(c + 0x44));
  vcall<void>(o, 0x88, normal);
}

// 0x597050 ZGameOSD::CommandRecruit(RECRUIT_COMMAND cmd, unsigned id, bool all), thiscall, ret 0xc.
// The recruit's candidate entry (table +0x1da2..+0x1da6, first dword = id, +4 actor; missing -> null, which faults
// as in the original) gets a time stamp (+0x18 = [sys+0x40] / 1024); wounded actors (mode 5) are skipped.
//   cmd 0 defend/stay: target = the camera's precision-aim point (when aiming, camera helper +0xb45) or the hero's
//     position grounded by a ray; actor mode 1; sound 0x22 or 0x23 at random (engine random > 0.5 gives 0x22).
//   cmd 3 scout: target = precision-aim point or the camera's scout point, grounded; mode 2; sound 0x25.
//   cmd 4 attack: event {all, hero id, camera target +0xd11}; mode 2; sound 0x21.
//   cmd 5 form: event with a zero position; mode 3 (following); sound 0x24.
//   other: the event id and data pointer are whatever the original had in its frame (see the note at the end).
// For defend/scout the target is also stored in the entry's order object (+0xc defend, +0x14 scout) unless the
// order is not aimed and the system's "order markers" float [sys+0x9c7] is 0.0, and the entry is added to the
// active list +0x5c (slot 0x2c find, slot 4 add) if missing. Every order then sends the event (slot 0x128) with the
// event id from +0x1d31 (aimed defend), +0x1d33 (defend), +0x1d35 (scout), +0x1d37 (attack), +0x1d39 (form).
static void THISCALL commandRecruit(u8 *self, u32 cmd, u32 id, u32 all) {
  u8 *e = 0;
  for (u8 **p = *(u8 ***)(self + 0x1da2); p != *(u8 ***)(self + 0x1da6); ++p)
    if (**(u32 **)p == id) {
      e = *p;
      break;
    }
  asm("" : "+r"(e));
  u8 *actor = *(u8 **)(e + 4);
  if (ext_59ffc0(actor) == 5)
    return;
  *(float *)(e + 0x18) = (float)*(s32 *)(G(u8 *, 0x70039c) + 0x40) * 0.0009765625f;
  u8 *hero = *(u8 **)(self + 0x1d0b);
  u8 *cam = *(u8 **)(self + 0x1d03);
  OrderPosEvent ev;
  OrderAttackEvent at;
  void *data;
  u32 evid;
  u32 snd = 0;
  u32 slotOff = 0;   // 0xc defend, 0x14 scout: the entry's order object
  switch (cmd) {
    case 0: {
      ev.normal[0] = 0;
      data = &ev;
      ev.all = (u8)all;
      ev.normal[1] = 1.0f;
      ev.normal[2] = 0;
      ev.heroId = vcall<u32>(objTable(), 0x4c, hero);
      if (cam[0xb45]) {
        evid = *(u16 *)(self + 0x1d31);
        if (!ext_5cfa00(*(u8 **)(self + 0x1d03), ev.pos))
          return;
        ext_5cf3e0(*(u8 **)(self + 0x1d03), ev.normal);
      } else {
        evid = *(u16 *)(self + 0x1d33);
        ev.pos[2] = 0;
        ev.pos[1] = 0;
        ev.pos[0] = 0;
        vcall<void>(*(u8 **)(self + 0x1d0b), 0x84, ev.pos);
        groundPosition(ev.pos, ev.normal);
      }
      u8 *sys = G(u8 *, 0x70039c);
      float r = ((vcallRandF)(*(void ***)sys)[0x1c0 / 4])(sys, (const char *)0x6ad250, 0x22e);
      snd = (r > 0.5f) ? 0x22 : 0x23;
      ext_5a2e20(actor, 1, 1, *(u8 **)(self + 0x1d0b), 5.0f);
      slotOff = 0xc;
      break;
    }
    case 3: {
      ev.normal[0] = 0;
      data = &ev;
      evid = *(u16 *)(self + 0x1d35);
      ev.all = (u8)all;
      ev.normal[1] = 1.0f;
      ev.normal[2] = 0;
      ev.heroId = vcall<u32>(objTable(), 0x4c, hero);
      if (cam[0xb45]) {
        if (!ext_5cfa00(*(u8 **)(self + 0x1d03), ev.pos))
          return;
        ext_5cf3e0(*(u8 **)(self + 0x1d03), ev.normal);
      } else {
        ext_5cfae0(cam, ev.pos);
        groundPosition(ev.pos, ev.normal);
      }
      snd = 0x25;
      ext_5a2e20(actor, 2, 1, *(u8 **)(self + 0x1d0b), 5.0f);
      slotOff = 0x14;
      break;
    }
    case 4:
      evid = *(u16 *)(self + 0x1d37);
      at.all = (u8)all;
      at.heroId = vcall<u32>(objTable(), 0x4c, hero);
      snd = 0x21;
      at.target = *(u32 *)(*(u8 **)(self + 0x1d03) + 0xd11);
      ext_5a2e20(actor, 2, 1, *(u8 **)(self + 0x1d0b), 5.0f);
      data = &at;
      break;
    case 5:
      evid = *(u16 *)(self + 0x1d39);
      ev.all = (u8)all;
      ev.pos[2] = 0;
      ev.pos[1] = 0;
      ev.pos[0] = 0;
      ev.heroId = vcall<u32>(objTable(), 0x4c, hero);
      snd = 0x24;
      ext_5a2e20(actor, 3, 1, *(u8 **)(self + 0x1d0b), 5.0f);
      data = &ev;   // normal[] not set (stack contents in the original)
      break;
    default:
      // Not reachable from the game's order handlers. The original sends an uninitialised frame slot as the event
      // id and a null data pointer; the port uses 0xcccccccc, the checker's stack fill.
      evid = 0xccccccccu;
      data = 0;
      break;
  }
  if (slotOff) {
    if ((*(u8 **)(self + 0x1d03))[0xb45] != 0 || *(float *)(G(u8 *, 0x70039c) + 0x9c7) != 0.0f) {
      ext_5b7ce0(*(u8 **)(e + slotOff), ev.pos[0], ev.pos[1], ev.pos[2], ev.normal[0], ev.normal[1], ev.normal[2]);
      ext_5b7d30(*(u8 **)(e + slotOff));
    }
    if (!vcall<u32>(*(void **)(self + 0x5c), 0x2c, e))
      vcall<void>(*(void **)(self + 0x5c), 4, e);
  }
  vcall<void>(actor, 0x128, evid, data, 0u);
  if (snd)
    ext_5a1ac0(actor, snd, *(u32 *)(self + 0xdd), 0);
}
PCREG(597050, commandRecruit);
