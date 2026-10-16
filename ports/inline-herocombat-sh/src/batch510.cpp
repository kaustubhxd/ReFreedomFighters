// batch510.cpp - weapons thread, batch 510: weapon switching actions (get item into a hand, put it away, swap the
// two hands) and ZLNKWHANDS::AddAction. Source file: ..\..\code\engine\geomsextend\zlnkwhandsactions.cpp.
// Action objects (ZLnkAction subclasses, PC layout): ZActionGetItem +8 item, +0xc owner (ZIKLNKOBJ), +0x10 hand,
// +0x14 / +0x18 anim (one-hand / two-hand: the second when the item template IsDerivedFrom(0x1007d4));
// ZActionPutItem +8 owner, +0xc hand, +0x10 / +0x14 anim; ZActionSwapItems +8 owner, +0xc / +0x10 the two hands,
// +0x14 anim. A hand object: slot 0x8 = attach(owner, item handle), slot 0x10 = item, +4 = its IK target (ZTARGET).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vU0)(void *self);
typedef u32(THISCALL *vUU)(void *self, u32 a);
typedef u32(THISCALL *vUUU)(void *self, u32 a, u32 b);
typedef u8(THISCALL *vB0)(void *self);
typedef u8(THISCALL *vBU)(void *self, u32 a);
typedef u32(THISCALL *vSeg)(void *self, u32 anim, u32 one, float a, float b, float speed);
typedef long double(THISCALL *vRand)(void *self, const char *file, u32 line);
typedef void *(THISCALL *vLogLine)(void *self, const char *file, u32 line);
typedef void (*logPrintf)(void *self, const char *fmt, ...);
struct PMF { u32 fn, adj, vb, vi; };

extern "C" void THISCALL ext_467410(void *target, u32 owner, float time, PMF cb);   // ZTARGET remove with callback
extern "C" void THISCALL ext_461570(void *bone, float t, u32 cb, u32 z);           // ZBoneAnim::AddCallBackAlways
extern "C" void THISCALL ext_4614d0(void *bone, float t, u32 cb, u32 z);           // ZBoneAnim::AddCallBack
extern "C" void THISCALL ext_4870b0(void *action, u32 item);                        // action SetItem (+8)

static const char *const kFile = (const char *)0x68cdc4;   // "..\..\code\engine\geomsextend\zlnkwhandsactions.cpp"
static const u32 kAnimDone = 0x465710;                      // the bone-anim callback (member function pointer code)
static inline u8 *rmgr() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
static inline u32 handleOf(u32 o) { u8 *rm = rmgr(); return ((vUU)VT(rm, 0x4c))(rm, o); }
static const PMF kNone = {0, 0, 0, 0xffffffffu};

// 0x4870b0: action +8 = item (the action's item; no GC name).
static void THISCALL actionSetItem(u8 *a, u32 item) { *(u32 *)(a + 8) = item; }
PCREG(4870b0, actionSetItem);

// 0x486020 ZActionGetItem::CallBack(): the item goes into the hand: drop the hand's IK target, attach the item
// (hand slot 0x8), then item state 2 and 0 (SetState slot 0x2d0). Returns 0.
static u8 THISCALL getItemCallBack(u8 *a) {
  u32 h = handleOf(*(u32 *)(a + 8));
  u8 *hand = *(u8 **)(a + 0x10);
  ext_467410(hand + 4, *(u32 *)(a + 0xc), 0.0f, kNone);
  hand = *(u8 **)(a + 0x10);
  ((vUUU)VT(hand, 8))(hand, *(u32 *)(a + 0xc), h);
  u8 *it = *(u8 **)(a + 8);
  ((vUUU)VT(it, 0x2d0))(it, 2, 0);
  it = *(u8 **)(a + 8);
  ((vUUU)VT(it, 0x2d0))(it, 0, 0);
  return 0;
}
PCREG(486020, getItemCallBack);

// 0x4864e0 ZActionGetItem::Execute(): play the draw animation segment at a random speed 0.8..1.2 (random from
// [0x70039c] slot 0x1c0, line 0x4c) and call back at 5.0; no animation: own slot 0xc (end the action).
static u8 THISCALL getItemExecute(u8 *a) {
  u8 *it = *(u8 **)(a + 8);
  u8 *t = (u8 *)((vU0)VT(it, 0x2e8))(it);
  u32 anim = ((vBU)VT(t, 0x1e0))(t, 0x1007d4) ? *(u32 *)(a + 0x18) : *(u32 *)(a + 0x14);
  if (!anim)
    return ((vB0)VT(a, 0xc))(a);
  u8 *s = G(u8 *, 0x70039c);
  float speed = (float)(((vRand)VT(s, 0x1c0))(s, kFile, 0x4c) * 0.4f + 0.8f);
  u8 *o = *(u8 **)(a + 0xc);
  u32 bone = ((vSeg)VT(o, 0x228))(o, anim, 1, 0.0f, -1.0f, speed);
  ext_461570((void *)bone, 5.0f, kAnimDone, 0);
  return 1;
}
PCREG(4864e0, getItemExecute);

// 0x4861f0 ZActionPutItem::CallBack(): the hand's item is detached (hand slot 0x8 with handle 0) and set to state 1;
// no item: "WARNING: ZActionPutItem::Callback pItem=0" (line 0xb3). Returns 0.
static u8 THISCALL putItemCallBack(u8 *a) {
  u8 *hand = *(u8 **)(a + 0xc);
  u8 *it = (u8 *)((vU0)VT(hand, 0x10))(hand);
  handleOf((u32)it);
  if (!it) {
    u8 *l = G(u8 *, 0x700390);
    void *st = ((vLogLine)VT(l, 0x20))(l, kFile, 0xb3);
    ((logPrintf)VT(st, 0x30))(st, (const char *)0x68cdf8);
    return 0;
  }
  ext_467410(*(u8 **)(a + 0xc) + 4, *(u32 *)(a + 8), 0.0f, kNone);
  hand = *(u8 **)(a + 0xc);
  ((vUUU)VT(hand, 8))(hand, *(u32 *)(a + 8), 0);
  ((vUUU)VT(it, 0x2d0))(it, 1, 0);
  return 0;
}
PCREG(4861f0, putItemCallBack);

// 0x486890 ZActionPutItem::Execute(): play the holster animation (ActivateAnim, slot 0x230) with a call back at 12.5.
static u8 THISCALL putItemExecute(u8 *a) {
  u8 *hand = *(u8 **)(a + 0xc);
  u8 *it = (u8 *)((vU0)VT(hand, 0x10))(hand);
  u8 *t = (u8 *)((vU0)VT(it, 0x2e8))(it);
  u32 anim = ((vBU)VT(t, 0x1e0))(t, 0x1007d4) ? *(u32 *)(a + 0x14) : *(u32 *)(a + 0x10);
  if (!anim)
    return ((vB0)VT(a, 0xc))(a);
  u8 *o = *(u8 **)(a + 8);
  u32 bone = ((vUUU)VT(o, 0x230))(o, anim, 1);
  ext_461570((void *)bone, 12.5f, kAnimDone, 0);
  return 1;
}
PCREG(486890, putItemExecute);

// 0x4862b0 ZActionSwapItems::CallBack(): both hands drop their IK targets and items, then each takes the other's.
static u8 THISCALL swapItemsCallBack(u8 *a) {
  ext_467410(*(u8 **)(a + 0xc) + 4, *(u32 *)(a + 8), 0.0f, kNone);
  ext_467410(*(u8 **)(a + 0x10) + 4, *(u32 *)(a + 8), 0.0f, kNone);
  u8 *hA = *(u8 **)(a + 0xc);
  u32 itA = ((vU0)VT(hA, 0x10))(hA);
  hA = *(u8 **)(a + 0xc);
  ((vUUU)VT(hA, 8))(hA, *(u32 *)(a + 8), 0);
  u8 *hB = *(u8 **)(a + 0x10);
  u32 itB = ((vU0)VT(hB, 0x10))(hB);
  hB = *(u8 **)(a + 0x10);
  ((vUUU)VT(hB, 8))(hB, *(u32 *)(a + 8), 0);
  if (itA) {
    u32 h = handleOf(itA);
    hB = *(u8 **)(a + 0x10);
    ((vUUU)VT(hB, 8))(hB, *(u32 *)(a + 8), h);
  }
  if (itB) {
    u32 h = handleOf(itB);
    hA = *(u8 **)(a + 0xc);
    ((vUUU)VT(hA, 8))(hA, *(u32 *)(a + 8), h);
  }
  return 0;
}
PCREG(4862b0, swapItemsCallBack);

// 0x4869a0 ZActionSwapItems::Execute(): the swap animation with a (non-"always") call back at 12.5.
static u8 THISCALL swapItemsExecute(u8 *a) {
  u32 anim = *(u32 *)(a + 0x14);
  if (!anim)
    return ((vB0)VT(a, 0xc))(a);
  u8 *o = *(u8 **)(a + 8);
  u32 bone = ((vUUU)VT(o, 0x230))(o, anim, 1);
  ext_4614d0((void *)bone, 12.5f, kAnimDone, 0);
  return 1;
}
PCREG(4869a0, swapItemsExecute);

// 0x471ff0 ZLNKWHANDS::AddAction(id, handle): create action `id` (own slot 0x3ec CreateLnkAction) and run it (slot
// 0x3d8). Ids 1-4, 7 and 8 also get the resolved object as the action's item; 5, 6 and 9-15 do not. Other ids hit
// the assert hook [0x7003b0] (int3 without one) and then RunLnkAction is called with the raw handle.
static void THISCALL addAction(u8 *self, u32 id, u32 handle) {
  u8 *rm = rmgr();
  u32 obj = ((vUU)VT(rm, 0x58))(rm, handle);
  if (id - 1 > 14) {
    typedef void (*hookFn)();
    hookFn hook = G(hookFn, 0x7003b0);
    if (hook)
      hook();
    else
      __builtin_debugtrap();
    ((vUU)VT(self, 0x3d8))(self, handle);
    return;
  }
  u32 act = ((vUU)VT(self, 0x3ec))(self, id);
  switch (id) {
  case 1: case 2: case 3: case 4: case 7: case 8:
    ext_4870b0((void *)act, obj);
    break;
  default:
    break;
  }
  ((vUU)VT(self, 0x3d8))(self, act);
}
PCREG(471ff0, addAction);
