// batch1312.cpp - inventory thread (inline-inventory, 2026-10-11): ZFFInventorySelector::SwapWeapons (0x568dc0).
// Object: +0x90 hero, +0x180 info list 1 (held), +0x1d4 info list 2 (selection), +0x27c bridge, +0x288 / +0x28c
// UI helpers, +0x291 the selected weapon type, +0x94 profile holder (rebel unlock object at holder +0xe9b).
// Message ids: 0x688968 "MSG_REMOVEITEMFROMINVENTORY" (file 0x6a73cc, line 0x218), 0x688984 "MSG_ADDITEMTOINVENTORY"
// (line 0x23f). Text formatter: ref table slot 0xae4 object, vtable slot 0 (format 0x68899c "Items/ShortNames").
#include "ff.h"

extern "C" u8 *THISCALL ext_5af130(u8 *list, u32 type);               // ZFFInventoryInfoList::GetInventoryInfo
extern "C" u32 THISCALL ext_5af5b0(u8 *bridge, u32 *type, u32 *n, u32 large);  // ZFFInventoryBridge::GetWeapon
extern "C" u32 THISCALL ext_5aedf0(u8 *list, u8 *info);               // list add-unique (info pointer)
extern "C" u32 THISCALL ext_5af260(u8 *list, u8 *info);               // ZFFInventoryInfoList::RemoveInventoryInfo
extern "C" u32 THISCALL ext_5aef10(u8 *rebel);                        // (rebel unlock reset)
extern "C" u32 THISCALL ext_4cc1d0(u8 *list);                         // (list count)
extern "C" u8 *THISCALL ext_5af0d0(u8 *list, u32 index);              // (list record by index)
extern "C" u32 THISCALL ext_5aee20(u8 *rebel, u32 type, u32 n);       // (rebel stash add)
extern "C" u8 *THISCALL ext_591f00(u8 *hero);                         // ZFFHERO::GetItemBack() const
extern "C" u8 *THISCALL ext_591080(u8 *hero);                         // ZFFHERO::DetachItemBack()
extern "C" u32 THISCALL ext_59a580(u8 *osd, u32 text, u32 unsignedv, u32 sound);  // ZGameOSD::MessageAdd
extern "C" u32 THISCALL ext_5b0290(u8 *osd);                          // ZGameOSD::InventoryUpdate()
extern "C" u32 THISCALL ext_569260(u8 *self);                         // ZFFInventorySelector::UpdateWeaponStash

static inline u8 *refTable() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
static inline u8 isA(u8 *g, u32 type) { return (u8)vcall<u32>(g, 0x1e0, type); }
static inline u32 msgId(u32 name, u32 line) {   // ref table slot 0x114(name, 0, file, line), low word
  return (u16)vcall<u32>(refTable(), 0x114, name, 0u, 0x6a73ccu, line);
}

static void THISCALL selectorSwapWeapons(u8 *self) {
  if (!*(u32 *)(self + 0x291)) return;
  u8 *hero = *(u8 **)(self + 0x90);
  u8 *lst1 = self + 0x180;
  u8 *lst2 = self + 0x1d4;
  vcall<u32>(hero, 0x3dc);
  vcall<u32>(hero, 0x4dc, 0u, 1u);

  u32 typ = *(u32 *)(self + 0x291);
  u8 *info = ext_5af130(lst1, typ);
  u32 flag = (*(u32 *)(info + 0x19) == 1) ? 1 : 0;
  u32 wt = 0, wn = 0;                                   // [ebp-4] type, [ebp-0xc] count
  ext_5af5b0(self + 0x27c, &wt, &wn, flag);

  if (wt) {
    u8 *g = ext_5af130(lst2, wt);
    if (g) {
      if (g[0x14]) *(u32 *)(g + 4) += wn;
    } else {
      u32 w8 = wn;                                      // [ebp-8]
      if (!ext_5af130(lst2, wt)) {
        u8 *i1 = ext_5af130(lst1, wt);
        if (i1) {
          *(u32 *)(i1 + 4) = w8;
          i1[0x14] = 1;
          ext_5aedf0(lst2, i1);
        }
      }
    }

    // the selection's record in list 2: its value, the ammo of the hero's item, and the HUD messages
    u8 *i2 = ext_5af130(lst2, wt);
    u32 mid1 = msgId(0x688968u, 0x218u);                // MSG_REMOVEITEMFROMINVENTORY
    if (i2 && *(u32 *)i2) {
      u8 *obj = *(u8 **)i2;
      u32 v = vcall<u32>(*(u8 **)(self + 0x288), 0x98, obj, 0u);
      *(u32 *)(i2 + 0x15) = v;
      u8 *o = vcall<u8 *>(refTable(), 0x58, v);
      if (o) {
        u32 r = vcall<u32>(hero, 0x55c, o);
        if (r) vcall<u32>((u8 *)r, 0x324, 0u);
      }
      vcall<u32>(*(u8 **)(self + 0x288), 0x44, mid1, *(u32 *)(i2 + 0x15));
      u8 *back = ext_591f00(hero);
      if (back && vcall<u32>(back, 0x2e8) == *(u32 *)i2) {
        u8 *d = ext_591080(hero);
        if (isA(d, 0x1007d2)) {
          vcall<u32>(d, 0x320);
          *(u32 *)(i2 + 0x15) = 0;
        }
      }
    }
  }

  // the hero's back item goes; then the selected record of list 1 is shown and set up
  {
    u8 *hh = *(u8 **)(self + 0x90);
    vcall<u32>(hh, 0x3f4, *(u32 *)(hh + 0xf12));
  }
  u8 *i3 = ext_5af130(lst1, typ);
  u32 mid2 = msgId(0x688984u, 0x23fu);                  // MSG_ADDITEMTOINVENTORY
  if (i3 && *(u32 *)i3) {
    u8 *obj3 = *(u8 **)i3;
    u32 vid = *(u32 *)(i3 + 0x15);
    if (vid) {
      vcall<u32>(*(u8 **)(self + 0x288), 0x44, mid2, vid);
    } else {
      u32 id = vcall<u32>(refTable(), 0x4c, obj3);
      vcall<u32>(*(u8 **)(self + 0x288), 0x44, mid2, id);
      u32 v3 = vcall<u32>(*(u8 **)(self + 0x288), 0x98, obj3, 0u);
      *(u32 *)(i3 + 0x15) = v3;
    }
    u8 *o2 = vcall<u8 *>(refTable(), 0x58, *(u32 *)(i3 + 0x15));
    if (o2 && isA(o2, 0x1007d2)) {
      vcall<u32>(hero, 0x4dc, o2, 1u);
      u8 *t2 = vcall<u8 *>(o2, 0x2e8);
      u32 nm = t2 ? *(u32 *)(t2 + 4) : 0;
      u32 name = nm ? nm : 0x67c8e8;                    // "<NONAME>"
      u8 *fmtobj = *(u8 **)(refTable() + 0xae4);
      u32 txt = vcall<u32>(fmtobj, 0, 0x68899cu, name);
      ext_59a580(*(u8 **)(self + 0x28c), txt, 0xffffffffu, 0);
      if (*(u32 *)(i3 + 0x10) == 0xb) {
        vcall<u32>(o2, 0x360, *(u32 *)(i3 + 4));
      } else {
        u8 *o3 = vcall<u8 *>(refTable(), 0x58, *(u32 *)(i3 + 0x15));
        if (o3 && isA(o3, 0x1007d2) && vcall<u32>(o3, 0x328)) {
          u32 e = vcall<u32>(o3, 0x364);
          u32 eq = e;                                   // [ebp-0x10]
          if (e > *(u32 *)(i3 + 4)) {
            vcall<u32>(o3, 0x360, *(u32 *)(i3 + 4));
          } else {
            vcall<u32>(o3, 0x360, e);
            u32 left = *(u32 *)(i3 + 4) - eq;           // [ebp-8] -= [ebp-0x10]
            if (left) {
              u32 w = vcall<u32>(hero, 0x55c, o3);
              u8 *target;
              if (w) {
                target = (u8 *)w;
              } else {
                u8 *r1 = vcall<u8 *>(o3, 0x328);
                u32 nw = vcall<u32>(hero, 0x20, 0x4954454du);
                u8 *ni = (u8 *)vcall<u32>(r1, 0x2c4, nw);
                u32 id = vcall<u32>(refTable(), 0x4c, hero);
                vcall<u32>(ni, 0x2f0, id, 0u, 1u);
                target = ni;
              }
              vcall<u32>(target, 0x324, left);
            }
          }
        }
      }
    }
    // 5691d5: the record leaves list 2 and its stored amount is cleared
    if (i3[0x14]) {
      ext_5af260(lst2, i3);
      *(u32 *)(i3 + 4) = 0;
    }
  }

  // the profile's rebel-base stash is rebuilt from list 2
  u8 *rebel = *(u8 **)(self + 0x94) + 0xe9b;
  ext_5aef10(rebel);
  u32 n = ext_4cc1d0(lst2);
  if ((s32)n > 0) {
    for (u32 i = 0; i < n; i++) {
      u8 *info2 = ext_5af0d0(lst2, i);
      if (info2[0x14]) ext_5aee20(rebel, *(u32 *)(info2 + 0x10), *(u32 *)(info2 + 4));
    }
  }
  ext_5b0290(*(u8 **)(self + 0x28c));
  ext_569260(self);
}
PCREG(568dc0, selectorSwapWeapons);
