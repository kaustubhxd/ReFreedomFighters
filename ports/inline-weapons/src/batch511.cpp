// batch511.cpp - weapons thread, batch 511: putting items into the hands (ZLNKWHANDS ForceR/LHandItem and helpers).
// Hand slot objects: right +0x34f (its IK target ZTARGET at +0x353), left +0x2e7 (IK target +0x2eb).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vU0)(void *self);
typedef u32(THISCALL *vUU)(void *self, u32 a);
typedef u32(THISCALL *vUUU)(void *self, u32 a, u32 b);
typedef u32(THISCALL *vUUUU)(void *self, u32 a, u32 b, u32 c);
struct PMF { u32 fn, adj, vb, vi; };
extern "C" void THISCALL ext_467410(void *target, u32 owner, float time, PMF cb);   // ZTARGET remove with callback
static const PMF kNone = {0, 0, 0, 0xffffffffu};
static inline u32 handleOf(u32 o) {
  u8 *rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  return ((vUU)VT(rm, 0x4c))(rm, o);
}

static void THISCALL attachRHandItem(u8 *self, u32 h) { u8 *hd = self + 0x34f; ((vUUU)VT(hd, 8))(hd, (u32)self, h); }
PCREG(472420, attachRHandItem);
static void THISCALL attachLHandItem(u8 *self, u32 h) { u8 *hd = self + 0x2e7; ((vUUU)VT(hd, 8))(hd, (u32)self, h); }
PCREG(472400, attachLHandItem);
static void THISCALL slipLHandItem(u8 *self) { u8 *hd = self + 0x2e7; ((vUU)VT(hd, 0xc))(hd, (u32)self); }
PCREG(475aa0, slipLHandItem);
static void THISCALL slipRHandItem(u8 *self) { u8 *hd = self + 0x34f; ((vUU)VT(hd, 0xc))(hd, (u32)self); }
PCREG(475ac0, slipRHandItem);
// 0x474700 LetItemFall(item): tail call to own slot 0x4f4 (drop).
static void THISCALL letItemFall(u8 *self, u32 item) { ((vUU)VT(self, 0x4f4))(self, item); }
PCREG(474700, letItemFall);
// 0x473b20 EmptyHands(): slots 0x548 and 0x54c with (0, 0) (left and right hand put-away; guess from the bodies below).
static void THISCALL emptyHands(u8 *self) {
  ((vUUU)VT(self, 0x548))(self, 0, 0);
  ((vUUU)VT(self, 0x54c))(self, 0, 0);
}
PCREG(473b20, emptyHands);
// 0x473960 / 0x473910 DestroyR/LHandItem(): take the item out of the hand (slot 0x54c / 0x548 with (0, 1)), item
// state 0, item slot 0x2f0(0, 0, 1) and slot 0x210(1) (guess: detach and destroy).
static inline void destroyHand(u8 *self, u32 getSlot, u32 putSlot) {
  u8 *it = (u8 *)((vU0)VT(self, getSlot))(self);
  ((vUUU)VT(self, putSlot))(self, 0, 1);
  ((vUUU)VT(it, 0x2d0))(it, 0, 0);
  ((vUUUU)VT(it, 0x2f0))(it, 0, 0, 1);
  ((vUU)VT(it, 0x210))(it, 1);
}
static void THISCALL destroyRHandItem(u8 *self) { destroyHand(self, 0x504, 0x54c); }
PCREG(473960, destroyRHandItem);
static void THISCALL destroyLHandItem(u8 *self) { destroyHand(self, 0x500, 0x548); }
PCREG(473910, destroyLHandItem);

// 0x473cd0 ForceRHandItem(item, force): nothing when the item is already in the right hand. Unless forced, an
// occupied hand (GetRHandItemType, slot 0x510, non-zero) is only emptied: type 1 puts the item away (state 1, IK
// target released, detached), other types drop it (LetItemFall, slot 0x46c); the new item is not taken this call.
// Forced or empty: attach the new item (AttachRHandItem slot 0x520 with its handle, or 0) and set it to state 0.
static void THISCALL forceRHandItem(u8 *self, u8 *item, u8 force) {
  u32 ty = ((vU0)VT(self, 0x510))(self);
  u8 *hd = self + 0x34f;
  if ((u8 *)((vU0)VT(hd, 0x10))(hd) == item)
    return;
  if (!force && ty) {
    if (ty == 1) {
      u8 *cur = (u8 *)((vU0)VT(hd, 0x10))(hd);
      if (!cur)
        return;
      ((vUUU)VT(cur, 0x2d0))(cur, 1, 0);
      ext_467410(self + 0x353, (u32)self, 0.0f, kNone);
      ((vUUU)VT(hd, 8))(hd, (u32)self, 0);
    } else {
      u8 *cur = (u8 *)((vU0)VT(hd, 0x10))(hd);
      if (!cur)
        return;
      ext_467410(self + 0x353, (u32)self, 0.0f, kNone);
      ((vUU)VT(self, 0x46c))(self, (u32)cur);
    }
    return;
  }
  if (!item) {
    ((vUU)VT(self, 0x520))(self, 0);
    return;
  }
  ((vUU)VT(self, 0x520))(self, handleOf((u32)item));
  ((vUUU)VT(item, 0x2d0))(item, 0, 0);
}
PCREG(473cd0, forceRHandItem);

// 0x473b70 ForceLHandItem(item, force): the same for the left hand (type slot 0x514, attach slot 0x524) without the
// "already held" test. Note the exe's type-1 branch works on the RIGHT hand (+0x34f, IK target +0x353), unlike the
// drop branch (left hand +0x2e7, +0x2eb); kept as is.
static void THISCALL forceLHandItem(u8 *self, u8 *item, u8 force) {
  u32 ty = ((vU0)VT(self, 0x514))(self);
  if (!force && ty) {
    if (ty == 1) {
      u8 *hd = self + 0x34f;
      u8 *cur = (u8 *)((vU0)VT(hd, 0x10))(hd);
      if (!cur)
        return;
      ((vUUU)VT(cur, 0x2d0))(cur, 1, 0);
      ext_467410(self + 0x353, (u32)self, 0.0f, kNone);
      hd = self + 0x34f;
      ((vUUU)VT(hd, 8))(hd, (u32)self, 0);
    } else {
      u8 *hd = self + 0x2e7;
      u8 *cur = (u8 *)((vU0)VT(hd, 0x10))(hd);
      if (!cur)
        return;
      ext_467410(self + 0x2eb, (u32)self, 0.0f, kNone);
      ((vUU)VT(self, 0x46c))(self, (u32)cur);
    }
    return;
  }
  if (!item) {
    ((vUU)VT(self, 0x524))(self, 0);
    return;
  }
  ((vUU)VT(self, 0x524))(self, handleOf((u32)item));
  ((vUUU)VT(item, 0x2d0))(item, 0, 0);
}
PCREG(473b70, forceLHandItem);
