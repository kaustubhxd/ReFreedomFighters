// batch517.cpp - weapons thread, batch 517: the hero's weapon switch (ZFFHERO::ControlUseOneAlone) and its helpers
// (item on the back, drop into the recycle list, current item type, restore after a temporary item).
// ZFFHERO fields: +0x83a handle of the previous right-hand item, +0x842 handle of the item on the back,
// +0x832 / +0x836 bit 0x20 item to restore after a temporary one, +0x654 / +0x658 / +0x65c cached item type,
// item and "forced type" flag, +0x95b inventory info list, +0x9e7 uses the weapon recycle list.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vU0)(void *self);
typedef u32(THISCALL *vUU)(void *self, u32 a);
typedef u32(THISCALL *vUUU)(void *self, u32 a, u32 b);
typedef u8(THISCALL *vB0)(void *self);
extern "C" void THISCALL ext_5e9300(void *list, u32 item);        // ZWeaponRecycleList::AddWeapon
extern "C" void THISCALL ext_4748b0(u8 *self, u32 item);          // ZLNKWHANDS::PerformDrop
extern "C" void THISCALL ext_4dcbb0(void *geom, u8 on);           // ZBaseGeom::SetOwnerDraw
extern "C" u32 THISCALL ext_5aeff0(void *list, u32 item);         // ZFFInventoryInfoList::GetFFItemType

static inline u8 *rmgr() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
static inline u32 resolve(u32 h) { u8 *rm = rmgr(); return ((vUU)VT(rm, 0x58))(rm, h); }
static inline void runAction(u8 *self, u32 id) {
  u32 a = ((vUU)VT(self, 0x3ec))(self, id);
  ((vUU)VT(self, 0x3d8))(self, a);
}

// 0x590140 ControlUseOneAlone(handle) (hero slot 0x480): switch the right hand to the item `handle`. Nothing if it is
// already held. The held item goes to idle and is put away: action 0x17 (onto the back) when its template's
// GetItemSize (slot 0x308) is 1, else hand action 6 (put away). Its handle is kept at +0x83a. The new item comes
// from the back with action 0x18 when it is the back item, else with hand action 8 (get item).
static void THISCALL controlUseOneAlone(u8 *self, u32 handle) {
  u8 *nw = (u8 *)resolve(handle);
  u8 *cur = (u8 *)((vU0)VT(self, 0x504))(self);
  u32 back = resolve(*(u32 *)(self + 0x842));
  if (nw == cur)
    return;
  if (cur) {
    ((vUUU)VT(cur, 0x2d0))(cur, 0, 0);
    u8 *t = (u8 *)((vU0)VT(cur, 0x2e8))(cur);
    if (((vU0)VT(t, 0x308))(t) == 1)
      runAction(self, 0x17);
    else
      ((vUUU)VT(self, 0x45c))(self, 6, 0);
  }
  u8 *rm = rmgr();
  *(u32 *)(self + 0x83a) = ((vUU)VT(rm, 0x4c))(rm, (u32)cur);
  if (!nw)
    return;
  if ((u32)nw == back)
    runAction(self, 0x18);
  else
    ((vUUU)VT(self, 0x45c))(self, 8, handle);
}
PCREG(590140, controlUseOneAlone);

// 0x593ee0 ZFFHERO::PerformDrop(item): a dropped weapon also goes on the recycle list (when used), then the hand drop.
static void THISCALL heroPerformDrop(u8 *self, u32 item) {
  if (self[0x9e7]) {
    u8 *x = (u8 *)((vU0)VT(rmgr(), 0x138))(rmgr());
    u32 list = 0;
    ((vUUU)VT(x, 0x88))(x, 0x6acf30, (u32)&list);   // "rWeaponRecycleList"
    ext_5e9300((void *)list, item);
  }
  ext_4748b0(self, item);
}
PCREG(593ee0, heroPerformDrop);

// 0x591f00 GetItemBack() / 0x591080 DetachItemBack(): the item on the back; detaching stops its owner-draw, detaches
// its geom from bone slot 0xc (own slot 0x294) and clears the handle. Returns the item.
static u32 THISCALL getItemBack(u8 *self) { return resolve(*(u32 *)(self + 0x842)); }
PCREG(591f00, getItemBack);
static u32 THISCALL detachItemBack(u8 *self) {
  u8 *it = (u8 *)resolve(*(u32 *)(self + 0x842));
  ext_4dcbb0(*(void **)(it + 8), 0);
  ((vUUU)VT(self, 0x294))(self, *(u32 *)(it + 8), 0xc);
  *(u32 *)(self + 0x842) = 0;
  return (u32)it;
}
PCREG(591080, detachItemBack);

// 0x591b20 GetFFItemType(): type 9 while flag 0x2000000 of +0x417 is set; otherwise the inventory type of the held
// item, cached against the item (+0x658) and recomputed when it changes or the forced type just ended; 0 when dead.
static u32 THISCALL getFFItemType(u8 *self) {
  u8 forced = 0;
  if (*(u32 *)(self + 0x417) & 0x2000000) {
    forced = 1;
    *(u32 *)(self + 0x654) = 9;
  }
  u8 was = self[0x65c];
  self[0x65c] = forced;
  if (forced)
    return *(u32 *)(self + 0x654);
  u32 cur = ((vU0)VT(self, 0x504))(self);
  if (cur != *(u32 *)(self + 0x658) || was) {
    *(u32 *)(self + 0x658) = cur;
    *(u32 *)(self + 0x654) = 0;
    if (cur)
      *(u32 *)(self + 0x654) = ext_5aeff0(self + 0x95b, cur);
  }
  if (((vB0)VT(self, 0x438))(self))
    *(u32 *)(self + 0x654) = 0;
  return *(u32 *)(self + 0x654);
}
PCREG(591b20, getFFItemType);

// 0x594590 RestoreItem(): after a temporary item (bit 0x20 of +0x836), end the current action and switch back to
// the saved item (+0x832, through ControlUseOneAlone, slot 0x480); with no saved item this only happens when something
// is held (switching to "nothing").
static void THISCALL restoreItem(u8 *self) {
  if (!(self[0x836] & 0x20))
    return;
  if (*(u32 *)(self + 0x832)) {
    ((vU0)VT(self, 0x3dc))(self);
    ((vUU)VT(self, 0x480))(self, *(u32 *)(self + 0x832));
    *(u32 *)(self + 0x836) &= 0xffffffdfu;
    *(u32 *)(self + 0x832) = 0;
    return;
  }
  if (((vU0)VT(self, 0x504))(self)) {
    ((vU0)VT(self, 0x3dc))(self);
    ((vUU)VT(self, 0x480))(self, *(u32 *)(self + 0x832));
  }
  *(u32 *)(self + 0x836) &= 0xffffffdfu;
}
PCREG(594590, restoreItem);
