// batch707.cpp - soldier AI, batch 707 (2026-10-11): how a soldier hooks into the vision system and what it does when
// something comes into view.
// Engine geom database (engine +0x9b): slot 0x4c geom->ref, 0x58 ref->geom, 0x114 RegisterZMsg(name, 0, file, line)
// -> message id. Geom slots: 0x130 SendCommand(target, id, data), 0x16c (unnamed; posts message id with data to itself,
// inferred), 0x1e0 IsDerivedFrom(class id), 0x438 (low-confidence "IsDead"), 0x5b0 GetActiveMoveSet,
// 0x670 GetKnockedOut, 0x674 GetHitpoints, 0x678 GetActorList.
// Team record at geom +0x54: +4 team index, +8 kind (4 checked below), +0xc bit mask of hostile teams (inferred).
#include "ff.h"

static inline void *db() { return *(void **)(*(u8 **)0x70039c + 0x9b); }
static inline u32 zmsg(const char *name, u32 line) {
  return vcall<u16>(db(), 0x114, name, 0, (const char *)0x6ae6a0, line);   // "..\..\freedomfighter\FFBackground\ZFFActor.cpp"
}

// 0x477940 ZActor::CheckSight() const [high]: +0x496 != 0.
static bool THISCALL actor_CheckSight(u8 *self) { return *(u32 *)(self + 0x496) != 0; }
PCREG(477940, actor_CheckSight);

// 0x47bd60 ZActor::SetCheckSight(bool) [high].
static void THISCALL actor_SetCheckSight(u8 *self, u32 b) { *(u32 *)(self + 0x496) = (u8)b; }
PCREG(47bd60, actor_SetCheckSight);

// 0x5a2570 ZFFActor::ReducedSight(unsigned int) [high]: only when the actor's flag +0x8fa is set: a ZActor target
// whose active move set is 3 or 4 (crouched/prone, inferred), or a ZPlayer target with bit 10 of +0x417.
static bool THISCALL ffactor_ReducedSight(u8 *self, u32 ref) {
  if (!*(u8 *)(self + 0x8fa))
    return false;
  u8 *g = vcall<u8 *>(db(), 0x58, ref);
  if (vcall<bool>(g, 0x1e0, 0x2007d0)) {
    if (vcall<s32>(g, 0x5b0) == 3)
      return true;
    return vcall<s32>(g, 0x5b0) == 4;
  }
  if (vcall<bool>(g, 0x1e0, 0x80200014))
    return (*(u32 *)(g + 0x417) >> 10) & 1;
  return false;
}
PCREG(5a2570, ffactor_ReducedSight);

// 0x59fed0 ZFFActor::GetNextVisible() [high]: ref of an object this soldier sees. Keeps the last answer (+0x8f6) while
// that pair is still registered (bit 15), otherwise takes the first object with both bits set; 0 if none.
static u32 THISCALL ffactor_GetNextVisible(u8 *self) {
  void *cv = *(void **)(self + 0x8ee);
  u8 *seer = vcall<u8 *>(cv, 0x88, *(u32 *)(self + 0x8f2));
  s32 cur = *(s32 *)(self + 0x8f6);
  if (cur != -1 && !(*(u16 *)(seer + 0x28 + cur * 2) >> 15 & 1))
    *(s32 *)(self + 0x8f6) = -1;
  if (*(s32 *)(self + 0x8f6) == -1) {
    for (u32 i = 0; i < 200; i++) {
      if ((*(u16 *)(seer + 0x28 + i * 2) & 0xc000) == 0xc000) {
        *(s32 *)(self + 0x8f6) = i;
        break;
      }
    }
  }
  s32 k = *(s32 *)(self + 0x8f6);
  if (k == -1)
    return 0;
  return *vcall<u32 *>(*(void **)(self + 0x8ee), 0x8c, k);
}
PCREG(59fed0, ffactor_GetNextVisible);

// 0x5a0e10 ZTargetManager::ObjectNotVisible(ZFFActor*, ZGEOM*) [medium]: posts "ObjectNotVisible" with the object's ref
// to the actor. `this` unused.
static void THISCALL tm_ObjectNotVisible(void *, u8 *actor, void *obj) {
  u32 ref = vcall<u32>(db(), 0x4c, obj);
  u32 id = zmsg((const char *)0x690650, 0xcaa);
  vcall<void>(actor, 0x16c, id, ref);
}
PCREG(5a0e10, tm_ObjectNotVisible);

// 0x5a0e60 ZTargetManager::ObjectVisible(ZFFActor*, ZGEOM*) [high]: the filter between "seen" and the soldier's script.
// A ZFFActor object is passed on as "ObjectVisible" only if its team is in the actor's hostile mask, it is not dead
// (slot 0x438), has hit points and is not knocked out. The hero (ZFFHERO) is passed on unless dead. Anything else logs
// "Ignoring object visible: '%s'".
struct MYSTR_buf { u8 b[0x80]; };
extern "C" const char *THISCALL ext_4cc1d0(void *);
extern "C" void THISCALL ext_4cbec0(void *);
static void tm_post_visible(u8 *actor, void *obj, u32 line) {
  u32 ref = vcall<u32>(db(), 0x4c, obj);
  u32 id = zmsg((const char *)0x690640, line);
  vcall<void>(actor, 0x16c, id, ref);
}
static void THISCALL tm_ObjectVisible(void *, u8 *actor, u8 *obj) {
  if (vcall<bool>(obj, 0x1e0, 0x2007f9)) {
    u32 bit = 1u << (*(u32 *)(*(u8 **)(obj + 0x54) + 4) & 31);
    if (!(*(u32 *)(*(u8 **)(actor + 0x54) + 0xc) & bit))
      return;
    if (vcall<bool>(obj, 0x438))
      return;
    if (vcall<s32>(obj, 0x674) == 0)
      return;
    if (vcall<bool>(obj, 0x670))
      return;
    tm_post_visible(actor, obj, 0xc9a);
  } else if (vcall<bool>(obj, 0x1e0, 0x2003e8)) {
    if (vcall<bool>(obj, 0x438))
      return;
    tm_post_visible(actor, obj, 0xca1);
  } else {
    void *log = vcall<void *>(*(void **)0x700390, 0x20, (const char *)0x6ae6a0, 0xca5);
    MYSTR_buf n;
    void *m = vcall<void *>(obj, 0x1d8, &n, 1);
    const char *s = ext_4cc1d0(m);
    typedef void(__attribute__((cdecl)) * printf_t)(void *, const char *, const char *);
    (*(printf_t *)(*(u8 **)log + 0x2c))(log, (const char *)0x6aef4c, s);
    ext_4cbec0(&n);
  }
}
PCREG(5a0e60, tm_ObjectVisible);

// 0x5a2600 ZFFActor::RegisterVision(bool add, bool keepOld) [high]. The actor list (geom of GetActorList(), slot
// 0x678) receives vision messages through SendCommand (slot 0x130). Unless keepOld: "Msg_SeerDel" and "Msg_ObjectDel"
// with the actor's ref. If add: for every geom in the list's container (+0x18, iterator 0x4c/0x5c) that has a team
// record: "Msg_SeerObjectAdd" {me, it} when its team is hostile to me, again {me, it} when its team kind is 4 and my
// team index is 2, and (unless keepOld) {it, me} when my team is hostile to it. Finally caches my seer index (+0x8f2)
// from the CCheckVisible (+0x8ee, slot 0x84).
static void THISCALL ffactor_RegisterVision(u8 *self, u32 add, u32 keepOld) {
  void *d = db();
  u32 lref = vcall<u32>(self, 0x678);
  u8 *list = vcall<u8 *>(db(), 0x58, lref);
  u32 me = vcall<u32>(db(), 0x4c, self);
  if (!(u8)keepOld) {
    u32 id = zmsg((const char *)0x690458, 0x691);   // "Msg_SeerDel"
    vcall<void>(self, 0x130, list, id, me);
    id = zmsg((const char *)0x690474, 0x692);       // "Msg_ObjectDel"
    vcall<void>(self, 0x130, list, id, me);
  }
  (void)d;
  if (!(u8)add)
    return;
  void *cont = *(void **)(list + 0x18);
  if (cont) {
    u32 it[6];
    vcall<void>(cont, 0x4c, it);
    u32 r = vcall<u32>(*(void **)(list + 0x18), 0x5c, it);
    while (it[0] != 0) {
      u8 *og = vcall<u8 *>(db(), 0x58, r);
      u8 *ot = *(u8 **)(og + 0x54);
      if (ot) {
        u32 pair[2];
        if (*(u32 *)(*(u8 **)(self + 0x54) + 0xc) & (1u << (*(u32 *)(ot + 4) & 31))) {
          pair[0] = me;
          pair[1] = r;
          u32 id = zmsg((const char *)0x690438, 0x6a2);
          vcall<void>(self, 0x130, list, id, pair);
        }
        if (*(u32 *)(*(u8 **)(og + 0x54) + 8) == 4 && *(u32 *)(*(u8 **)(self + 0x54) + 4) == 2) {
          pair[0] = me;
          pair[1] = r;
          u32 id = zmsg((const char *)0x690438, 0x6aa);
          vcall<void>(self, 0x130, list, id, pair);
        }
        if (!(u8)keepOld &&
            (*(u32 *)(*(u8 **)(og + 0x54) + 0xc) & (1u << (*(u32 *)(*(u8 **)(self + 0x54) + 4) & 31)))) {
          pair[1] = me;
          pair[0] = r;
          u32 id = zmsg((const char *)0x690438, 0x6b1);
          vcall<void>(self, 0x130, list, id, pair);
        }
      }
      r = vcall<u32>(*(void **)(list + 0x18), 0x5c, it);
    }
  }
  *(u32 *)(self + 0x8f2) = vcall<u32>(*(void **)(self + 0x8ee), 0x84, me);
}
PCREG(5a2600, ffactor_RegisterVision);
