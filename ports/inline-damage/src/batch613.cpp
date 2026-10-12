// batch613.cpp - damage thread, batch 613: ZKillBox::Kill (instant-death volumes).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
#define ENGINE G(u8 *, 0x70039c)

extern "C" void THISCALL ext_4daf90(void *baseGeom, float *out);  // ZBaseGeom::GetCen
extern "C" void THISCALL ext_5d0ba0(void *cam, u32 amount);       // ZCamHelper::MoveBackward

typedef u8 *(THISCALL *vPU)(void *self, u32 a);
typedef void (THISCALL *vVec)(void *self, float *v);
typedef u8 (THISCALL *vInside)(void *self, float *p, float margin);
typedef u16 (THISCALL *vMsgId)(void *self, const char *name, u32 a, const char *file, u32 line);
typedef void (THISCALL *vPost)(void *self, u32 msg, void *data, u32 z);
typedef u8 *(THISCALL *vFind)(void *self, const char *cls);
typedef u32 (THISCALL *vIter)(void *self, u32 *cookie);
typedef void (THISCALL *v0)(void *self);
typedef u8 (THISCALL *vB0)(void *self);

static inline u8 *rm() { return *(u8 **)(ENGINE + 0x9b); }

// Is `obj`'s centre inside the box geom (handle at +0x4e), with a margin of -10?
static int inside(u8 *box, u8 *obj) {
  float c[3];
  ext_4daf90(*(u8 **)(obj + 8), c);
  ((vVec)VT(obj, 0x84))(obj, c);
  ((vVec)VT(box, 0x8c))(box, c);
  return ((vInside)VT(box, 0x180))(box, c, -10.0f);
}

static inline u16 damageMsg(u32 line) {
  return ((vMsgId)VT(rm(), 0x114))(rm(), (const char *)0x69eaac, 0, (const char *)0x6b15fc, line);  // "DamageInfo"
}

// 0x5b1ce0 ZKillBox::Kill() (GC 800dd0e8). The kill box keeps an SDamageInfo at +0x52, set up by the ctor as type 4
// (explosion) with damage 1,000,000 (+0x7a). Hero mode (+0x87): when the Hero (+0x83) centre is inside the box,
// the Hero gets DamageInfo and its camera helper (+0x85a, found by name "ZCamHelper" on first use) MoveBackward(1000).
// Otherwise every object in the box's list (+0x4a -> +0x18 iterator, slots 0x4c / 0x5c) with a team (+0x54) whose
// centre is inside: a ZFFActor (class 0x2007f9) first gets slot 0x6e0 when +0x8c is set, and slot 0x28 when its slot
// 0x438 says so; then DamageInfo for all of them.
static void THISCALL killBoxKill(u8 *self) {
  u8 *box = ((vPU)VT(rm(), 0x58))(rm(), *(u32 *)(self + 0x4e));
  if (self[0x87]) {
    u8 *hero = *(u8 **)(self + 0x83);
    if (!inside(box, hero)) return;
    u16 id = damageMsg(0x8a);
    hero = *(u8 **)(self + 0x83);
    ((vPost)VT(hero, 0x128))(hero, id, self + 0x52, 0);
    u8 *h = *(u8 **)(self + 0x83);
    if (!*(u32 *)(h + 0x85a)) *(u8 **)(h + 0x85a) = ((vFind)VT(h, 0x100))(h, (const char *)0x6a6e88);
    ext_5d0ba0(*(u8 **)(h + 0x85a), 1000);
    return;
  }
  u8 *list = *(u8 **)(*(u8 **)(self + 0x4a) + 0x18);
  if (!list) return;
  u32 cookie;
  ((vIter)VT(list, 0x4c))(list, &cookie);
  u32 handle = ((vIter)VT(*(u8 **)(*(u8 **)(self + 0x4a) + 0x18), 0x5c))(*(u8 **)(*(u8 **)(self + 0x4a) + 0x18), &cookie);
  while (cookie) {
    u8 *o = ((vPU)VT(rm(), 0x58))(rm(), handle);
    if (*(u32 *)(o + 0x54) && inside(box, o)) {
      if ((u8)(u32)((vPU)VT(o, 0x1e0))(o, 0x2007f9)) {
        if (self[0x8c]) ((v0)VT(o, 0x6e0))(o);
        if (((vB0)VT(o, 0x438))(o)) ((v0)VT(o, 0x28))(o);
      }
      u16 id = damageMsg(0xba);
      ((vPost)VT(o, 0x128))(o, id, self + 0x52, 0);
    }
    u8 *l = *(u8 **)(*(u8 **)(self + 0x4a) + 0x18);
    handle = ((vIter)VT(l, 0x5c))(l, &cookie);
  }
}
PCREG(5b1ce0, killBoxKill);
