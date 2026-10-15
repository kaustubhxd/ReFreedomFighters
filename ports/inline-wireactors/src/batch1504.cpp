// batch1504.cpp - recruits thread, batch 1504: squad records (ctor, copy, targets, automatic squads) and the recruit
// list (IsRecruited, AddRecruit, PurgeOneWoundedIfFull).
#include "ff.h"

static inline void *objTable() { return *(void **)(G(u8 *, 0x70039c) + 0x9b); }
typedef void(__attribute__((cdecl)) * logPrintf)(void *log, const char *fmt, ...);
static inline void *logAt(const char *file, u32 line) { return vcall<void *>(G(void *, 0x700390), 0x20, file, line); }
typedef void *(__attribute__((cdecl)) * memmoveFn)(void *, const void *, u32);
#define CRT_MEMMOVE (*(memmoveFn *)0x676278)

// ZFFGameData::SSquad (0xf4 bytes): +0 member count, +4 members[12], +0x34 group (the geom whose children form the
// squad), +0x38 target count, +0x3c targets[16], +0x7c count + 0x80 array (12 dwords), +0xb0 count + 0xb4 array.

// 0x5889c0 (unnamed; SSquad constructor from a group), thiscall, ret 4, returns this.
static u32 *THISCALL squadCtor(u32 *self, u32 group) {
  self[0] = 0;
  self[0x34 / 4] = group;
  self[0x38 / 4] = 0;
  self[0x7c / 4] = 0;
  self[0xb0 / 4] = 0;
  self[0x7c / 4] = 0;
  self[0xb0 / 4] = 0;
  return self;
}
PCREG(5889c0, squadCtor);

// 0x589710 (unnamed; SSquad copy assignment), thiscall, ret 4, returns this. Copies only the used parts of each array
// (the two last arrays with CRT memmove).
static u8 *THISCALL squadAssign(u8 *self, const u8 *o) {
  *(u32 *)self = *(const u32 *)o;
  for (s32 n = *(const s32 *)o, i = 0; n > 0; --n, ++i)
    ((u32 *)(self + 4))[i] = ((const u32 *)(o + 4))[i];
  *(u32 *)(self + 0x34) = *(const u32 *)(o + 0x34);
  *(u32 *)(self + 0x38) = *(const u32 *)(o + 0x38);
  for (s32 n = *(const s32 *)(o + 0x38), i = 0; n > 0; --n, ++i)
    ((u32 *)(self + 0x3c))[i] = ((const u32 *)(o + 0x3c))[i];
  memmoveFn mm = CRT_MEMMOVE;
  *(u32 *)(self + 0x7c) = *(const u32 *)(o + 0x7c);
  mm(self + 0x80, o + 0x80, *(const u32 *)(o + 0x7c) << 2);
  *(u32 *)(self + 0xb0) = *(const u32 *)(o + 0xb0);
  mm(self + 0xb4, o + 0xb4, *(const u32 *)(o + 0xb0) << 2);
  return self;
}
PCREG(589710, squadAssign);

// 0x59d370 (unnamed; "target is gone"), thiscall, plain ret, AL. The target entity's geom (+0) answers IsKindOf
// (slot 0x1e0) for class 0x200074, and then its slot 0x438 decides (tail call); other geoms give 0.
static u8 THISCALL targetGone(void **self) {
  void *g = self[0];
  if (!vcall<u8>(g, 0x1e0, 0x200074u))
    return 0;
  return vcall<u8>(self[0], 0x438);
}
PCREG(59d370, targetGone);

extern "C" u8 THISCALL ext_59d370(void *target);

// 0x58a320 (unnamed; SSquad purge of gone targets), thiscall, plain ret. Every target that is gone is replaced by
// the last one (which is then checked in its place).
static void THISCALL squadPurgeTargets(u8 *self) {
  u32 *p = (u32 *)(self + 0x3c);
  while (p != (u32 *)(self + (*(u32 *)(self + 0x38) + 0xf) * 4)) {
    if (ext_59d370((void *)*p)) {
      *p = *(u32 *)(self + *(u32 *)(self + 0x38) * 4 + 0x38);
      --*(u32 *)(self + 0x38);
    } else {
      ++p;
    }
  }
}
PCREG(58a320, squadPurgeTargets);

extern "C" void THISCALL ext_58a320(u8 *sq);

// 0x589980 ZFFGameData::SSquad::AddTarget(GameEntity*), thiscall, ret 4. Adds a target once; with 16 targets the
// gone ones are purged first, and if it is still full the squad logs "too many targets" and drops it.
static void THISCALL squadAddTarget(u8 *self, u32 t) {
  u32 *p = (u32 *)(self + 0x3c);
  u32 *end = (u32 *)(self + (*(u32 *)(self + 0x38) + 0xf) * 4);
  for (; p != end; ++p)
    if (*p == t)
      break;
  if (p != (u32 *)(self + (*(u32 *)(self + 0x38) + 0xf) * 4))
    return;
  if (*(u32 *)(self + 0x38) == 0x10) {
    ext_58a320(self);
    if (*(u32 *)(self + 0x38) == 0x10) {
      void *lo = logAt((const char *)0x6abf90, 0x14d);
      ((logPrintf)(*(void ***)lo)[0x2c / 4])(lo, (const char *)0x6abfec);
      return;
    }
  }
  *(u32 *)(self + 0x3c + *(u32 *)(self + 0x38) * 4) = t;
  ++*(u32 *)(self + 0x38);
}
PCREG(589980, squadAddTarget);

extern "C" u8 THISCALL ext_4db9a0(void *geom, u32 cls);   // ZBaseGeom::IsDerivedFrom (batch 7)
extern "C" u8 *THISCALL ext_5889c0(void *sq, u32 group);
extern "C" u8 *THISCALL ext_589710(void *dst, const void *src);
extern "C" u8 THISCALL ext_5898c0(u8 *sq, u8 *actor);     // SSquad::AddMember

// 0x59db90 ZFFActor::AddToSquad(), thiscall, plain ret. Only for team 1 actors ([+0x54]+4 == 1). The squad is the
// one whose group (+0x34) is the actor's group (slot 0x20 twice: actor -> geom -> parent group). Without one, a new
// squad is made for the group when the group has at least two recruitable children (class 0x2007f9; children from
// [group+8], next by group slot 0x50), up to 32 squads ("too many squads" is logged at 32). Then AddMember; on
// success the actor remembers the squad (+0x921).
static void THISCALL actorAddToSquadAuto(u8 *self) {
  if (*(u32 *)(*(u8 **)(self + 0x54) + 4) != 1)
    return;
  void *a = vcall<void *>(self, 0x20);
  u8 *grp = vcall<u8 *>(a, 0x20);
  u8 *game = G(u8 *, 0x7003b8);
  s32 *nsq = (s32 *)(game + 0xd8d);
  u8 *sq = (u8 *)nsq + 4;
  u8 *end = (u8 *)nsq + 4 + (u32)(*nsq * 0xf4);
  for (; sq != end; sq += 0xf4)
    if (*(u8 **)(sq + 0x34) == grp)
      break;
  if (sq == end) {
    u32 ch = *(u32 *)(grp + 8);
    s32 n = 0;
    if (!ch)
      return;
    do {
      if (ext_4db9a0((void *)ch, 0x2007f9))
        ++n;
      vcall<void>(grp, 0x50, &ch);
    } while (ch);
    if (n <= 1)
      return;
    if (*nsq == 0x20) {
      void *lo = logAt((const char *)0x6ae6a0, 0x1b2);
      ((logPrintf)(*(void ***)lo)[0x30 / 4])(lo, (const char *)0x6ae7d0, 0x20u);
      return;
    }
    u8 tmp[0xf4];
    ext_5889c0(tmp, (u32)grp);
    ext_589710((u8 *)nsq + 4 + (u32)(*nsq * 0xf4), tmp);
    ++*nsq;
    sq = (u8 *)nsq + (u32)(*nsq * 0xf4) - 0xf0;
  }
  if (ext_5898c0(sq, self))
    *(u8 **)(self + 0x921) = sq;
}
PCREG(59db90, actorAddToSquadAuto);

// ---------------------------------------------------------------- recruit list
extern "C" u8 *THISCALL ext_589c20(u8 *game, u32 player);
extern "C" void THISCALL ext_5a2e20(u8 *actor, u32 mode, u32 show, u8 *hero, float time);
extern "C" void THISCALL ext_5a1ac0(u8 *actor, u32 snd, u32 v, u32 b);
extern "C" u32 THISCALL ext_59ffc0(u8 *actor);
extern "C" void THISCALL ext_597e00(u8 *osd, u32 id);
extern "C" void THISCALL ext_594460(u8 *hero, u8 *actor);

// 0x597a70 ZGameOSD::IsRecruited(unsigned id), thiscall, ret 4, AL. True when the id is in the recruit list of any
// of the 4 players' OSDs whose player is active (bit 10 of [[entry+8]+0x3c] clear; entries at game +0x2c3d) and on
// the same team as this OSD's hero.
static u8 THISCALL osdIsRecruited(u8 *self, u32 id) {
  for (u32 s = 0; s < 4; ++s) {
    u8 *osd = ext_589c20(G(u8 *, 0x7003b8), s);
    u8 *game = G(u8 *, 0x7003b8);
    if (!osd)
      continue;
    u8 *e = *(u8 **)(game + 0x2c3d + 4 * s);
    if ((*(u32 *)(*(u8 **)(e + 8) + 0x3c) >> 10) & 1)
      continue;
    if (*(u32 *)(*(u8 **)(*(u8 **)(self + 0x1d0b) + 0x54) + 4) != *(u32 *)(*(u8 **)(e + 0x54) + 4))
      continue;
    s32 n = *(s32 *)(osd + 0x1fae);
    for (s32 i = 0; i < n; ++i)
      if (((u32 *)(osd + 0x1dae))[i] == id)
        return 1;
  }
  return 0;
}
PCREG(597a70, osdIsRecruited);

// 0x5967b0 ZGameOSD::AddRecruit(unsigned id), thiscall, ret 4.
// When there is room (+0x1fae < +0x1fba, signed) and the object is a recruitable actor (class 0x2007f9): stamps the
// actor's entry in the candidate table (+0x1da2..+0x1da6, pointers to records whose first dword is the id; +0x18 =
// engine time [sys+0x40] / 1024; a missing entry writes through null as the original does), puts the id first in
// the recruit list (list shifted up one, selection reset to 0), sets the actor to mode 3 (following) with this
// OSD's hero and a 5 s marker, and has it play the "joined" sound 0x20. Full squad: logs and does nothing.
static void THISCALL osdAddRecruit(u8 *self, u32 id) {
  if (!(*(s32 *)(self + 0x1fae) < *(s32 *)(self + 0x1fba))) {
    void *lo = logAt((const char *)0x6ad250, 0x1ba);
    ((logPrintf)(*(void ***)lo)[0x2c / 4])(lo, (const char *)0x6ad2d8);
    return;
  }
  u8 *a = vcall<u8 *>(objTable(), 0x58, id);
  if (!vcall<u8>(a, 0x1e0, 0x2007f9u))
    return;
  u8 *e = 0;
  for (u32 **p = *(u32 ***)(self + 0x1da2); p != *(u32 ***)(self + 0x1da6); ++p) {
    if (**p == id) {
      e = (u8 *)*p;
      break;
    }
  }
  float t = (float)*(s32 *)(G(u8 *, 0x70039c) + 0x40) * 0.0009765625f;   // 0x6785e4
  asm("" : "+r"(e));   // keep the store through a null entry (the compiler would treat it as unreachable)
  *(float *)(e + 0x18) = t;
  u32 n = *(u32 *)(self + 0x1fae);
  *(u32 *)(self + 0x1fb2) = 0;
  CRT_MEMMOVE(self + 0x1db2, self + 0x1dae, n << 2);
  *(u32 *)(self + 0x1dae) = id;
  ++*(u32 *)(self + 0x1fae);
  ext_5a2e20(a, 3, 1, *(u8 **)(self + 0x1d0b), 5.0f);
  ext_5a1ac0(a, 0x20, *(u32 *)(self + 0xdd), 0);
}
PCREG(5967b0, osdAddRecruit);

// 0x597b50 ZGameOSD::PurgeOneWoundedIfFull(), thiscall, plain ret. When the squad is full, the first recruit in mode
// 5 (wounded) is dismissed: removed from the list, sent the "dismissed" event (id from the table's slot 0x114 for
// the name at 0x6a5354; data {hero id, multiplayer flag [sys+0x1b5d] == 1}), and removed from the hero's followers.
#pragma pack(push, 1)
struct DismissEvent {
  u32 heroId;
  u8 mp;
};
#pragma pack(pop)
static void THISCALL osdPurgeOneWounded(u8 *self) {
  if (*(s32 *)(self + 0x1fae) < *(s32 *)(self + 0x1fba))
    return;
  s32 i = 0;
  if (*(s32 *)(self + 0x1fae) <= 0)
    return;
  u8 *a;
  for (;;) {
    a = vcall<u8 *>(objTable(), 0x58, ((u32 *)(self + 0x1dae))[i]);
    if (ext_59ffc0(a) == 5)
      break;
    ++i;
    if (!(i < *(s32 *)(self + 0x1fae)))
      return;
  }
  DismissEvent ev;
  ev.heroId = vcall<u32>(objTable(), 0x4c, *(u8 **)(self + 0x1d0b));
  u8 *sys = G(u8 *, 0x70039c);
  ev.mp = *(u32 *)(sys + 0x1b5d) == 1;
  u16 evid = vcall<u16>(*(void **)(sys + 0x9b), 0x114, (const char *)0x6a5354, 0u, (const char *)0x6ad250, 0x413u);
  ext_597e00(self, ((u32 *)(self + 0x1dae))[i]);
  vcall<void>(a, 0x128, (u32)evid, &ev, 0u);
  ext_594460(*(u8 **)(self + 0x1d0b), a);
}
PCREG(597b50, osdPurgeOneWounded);
