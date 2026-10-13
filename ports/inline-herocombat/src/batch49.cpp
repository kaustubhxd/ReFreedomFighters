// batch49.cpp - hero frame-update tree, inline session batch 49: ZFFHERO::StashItem and the item lookups.
#include "ff.h"

typedef u32(THISCALL *vcallU0)(void *self);
typedef u32(THISCALL *vcallU1)(void *self, u32 a);
typedef void(THISCALL *vcallV0)(void *self);
typedef void(THISCALL *vcallV1)(void *self, u32 a);
typedef void(THISCALL *vcallIt)(void *self, u32 *it);
typedef u32(THISCALL *vcallItNext)(void *self, u32 *it);

#define VT(o, off) ((*(void ***)(o))[(off) / 4])

// 0x595440 ZFFHERO::StashItem(bool stash, STASHREASON reason), thiscall, ret 8. Keeps a set of stash reasons at +0x836.
// While any reason is set, the held item (slot 0x504) is put away once: its render-manager handle (render-manager slot
// 0x4c) goes to +0x832, then slots 0x3dc and 0x480(0). When the last reason clears, slots 0x3dc and 0x480(+0x832)
// bring it back and +0x832 is cleared.
static void THISCALL stashItem(u8 *self, u32 stash, u32 reason) {
  u8 on = (u8)stash;
  if (on)
    *(u32 *)(self + 0x836) |= reason;
  else
    *(u32 *)(self + 0x836) &= ~reason;
  if (*(u32 *)(self + 0x836) != 0) {
    if (*(u32 *)(self + 0x832) != 0)
      return;
    if (((vcallU0)VT(self, 0x504))(self) == 0 || !on)
      return;
    u8 *rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    void **rvt = *(void ***)rm;
    u32 item = ((vcallU0)VT(self, 0x504))(self);
    rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    *(u32 *)(self + 0x832) = ((vcallU1)rvt[0x4c / 4])(rm, item);
    ((vcallV0)VT(self, 0x3dc))(self);
    ((vcallV1)VT(self, 0x480))(self, 0);
    return;
  }
  if (*(u32 *)(self + 0x832) == 0)
    return;
  ((vcallV0)VT(self, 0x3dc))(self);
  ((vcallV1)VT(self, 0x480))(self, *(u32 *)(self + 0x832));
  *(u32 *)(self + 0x832) = 0;
}
PCREG(595440, stashItem);

// 0x5af130 ZFFInventoryInfoList::GetInventoryInfo(EFFItemType), thiscall, ret 4. [this] = count, then count entry
// pointers; returns the first entry whose +0x10 equals type, or 0.
static u8 *THISCALL getInventoryInfo(u32 *self, u32 type) {
  u32 n = self[0];
  for (u32 i = 0; i < n; ++i)
    if (type == *(u32 *)((u8 *)self[1 + i] + 0x10))
      return (u8 *)self[1 + i];
  return 0;
}
PCREG(5af130, getInventoryInfo);

extern "C" u8 *THISCALL ext_5af130(u8 *list, u32 type);
// 0x591e50 ZFFHERO::GetItem(EFFItemType), thiscall, ret 4. Walks the inventory (slot 0x464, then its slot 0xa0 list,
// iterated by the list's slots 0x48 and 0x58; each step's value is resolved by render-manager slot 0x58) and returns the
// first item whose slot 0x2e8 equals the first dword of the type's inventory info, or 0.
static u8 *THISCALL getItem(u8 *self, u32 type) {
  u32 *info = (u32 *)ext_5af130(self + 0x95b, type);
  if (!info || info[0] == 0)
    return 0;
  u8 *inv = (u8 *)((vcallU0)VT(self, 0x464))(self);
  u8 *list = (u8 *)((vcallU0)VT(inv, 0xa0))(inv);
  if (!list)
    return 0;
  u32 it;
  ((vcallIt)VT(list, 0x48))(list, &it);
  u32 v = ((vcallItNext)VT(list, 0x58))(list, &it);
  while (it != 0) {
    u8 *rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *obj = (u8 *)((vcallU1)VT(rm, 0x58))(rm, v);
    if (((vcallU0)VT(obj, 0x2e8))(obj) == info[0])
      return obj;
    v = ((vcallItNext)VT(list, 0x58))(list, &it);
  }
  return 0;
}
PCREG(591e50, getItem);

// 0x591d80, thiscall, plain ret. Same walk as GetItem, but returns the first item whose type info (slot 0x2e8) has the
// name "FirstAid_Large" (0x6acb04; a null name reads as "<NONAME>", 0x67c8e8), or 0.
static u8 *THISCALL findFirstAidLarge(u8 *self) {
  u8 *inv = (u8 *)((vcallU0)VT(self, 0x464))(self);
  u8 *list = (u8 *)((vcallU0)VT(inv, 0xa0))(inv);
  if (!list)
    return 0;
  u32 it;
  ((vcallIt)VT(list, 0x48))(list, &it);
  u32 v = ((vcallItNext)VT(list, 0x58))(list, &it);
  while (it != 0) {
    u8 *rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *obj = (u8 *)((vcallU1)VT(rm, 0x58))(rm, v);
    u8 *ti = (u8 *)((vcallU0)VT(obj, 0x2e8))(obj);
    const u8 *a = *(const u8 **)(ti + 4);
    if (!a)
      a = (const u8 *)0x67c8e8u;
    const u8 *b = (const u8 *)0x6acb04u;
    bool same = true;
    for (;;) {
      if (a[0] != b[0]) { same = false; break; }
      if (a[0] == 0) break;
      if (a[1] != b[1]) { same = false; break; }
      if (a[1] == 0) break;
      a += 2;
      b += 2;
    }
    if (same)
      return obj;
    v = ((vcallItNext)VT(list, 0x58))(list, &it);
  }
  return 0;
}
PCREG(591d80, findFirstAidLarge);
