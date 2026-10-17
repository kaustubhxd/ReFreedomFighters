// batch1310.cpp - inventory thread (inline-inventory, 2026-10-11): ZFFInventorySelector::Init2 (0x568350).
// Object layout used here (from this function): +0x90 hero (ZFFHERO*, from message "HitmanGround"), +0x94 the
// profile holder (its byte +0x4a is the chapter digit; the profile is at +0x57 of it, CPlayerInventory at profile
// +0xe18, the rebel-base weapon unlock object at profile +0xe44), +0x180 info list 1 (ammo of the weapons held), +0x1d4
// info list 2 (the selection pool), +0x228 extra weapons list, +0x3ee..+0x42a eight (value, type) stash slots and
// +0x326 twelve-byte per-weapon records.
#include "ff.h"

struct Count5 { u32 c[5]; };
extern "C" u32 THISCALL ext_5aee60(u8 *list, u32 id);               // ZFFInventoryInfoList::AddList(unsigned int)
extern "C" u32 THISCALL ext_5b04a0(u8 *inv, u32 *type, u32 *n);     // CPlayerInventory::GetLargeItem
extern "C" u32 THISCALL ext_5b04c0(u8 *inv, u32 *type, u32 *n);     // CPlayerInventory::GetSmallItem
extern "C" u32 THISCALL ext_5adda0(u8 *profile);                    // CPlayerProfile::FirstTimeInZone()
extern "C" u32 THISCALL ext_5aef80(u8 *list, u32 type);             // ZFFInventoryInfoList::GetAmmo
extern "C" u32 THISCALL ext_5b07d0(u8 *inv, u32 type, u32 n);       // CPlayerInventory::SetLargeItem
extern "C" u32 THISCALL ext_5b07f0(u8 *inv, u32 type, u32 n);       // CPlayerInventory::SetSmallItem
extern "C" u32 THISCALL ext_567930(u8 *self, u8 *extra);            // ZFFInventorySelector::AddAdditionalWeapons
extern "C" u32 THISCALL ext_5af230(u8 *rebel, u32 type);            // ZFFAddedWeaponsToRebelBase::ItemAvailible
extern "C" u32 THISCALL ext_5aefc0(u8 *rebel, u32 type);            // ZFFAddedWeaponsToRebelBase::GetAmmoForItem
extern "C" u8 *THISCALL ext_5af130(u8 *list, u32 type);             // ZFFInventoryInfoList::GetInventoryInfo
extern "C" u32 THISCALL ext_5aedf0(u8 *list, u8 *info);             // list add-unique (info pointer)
extern "C" u32 THISCALL ext_5afc10(u8 *ctrl);                       // ZFFInventoryController::ZFFInventoryController
extern "C" u32 THISCALL ext_5afce0(u8 *ctrl, Count5 *out);          // ZFFInventoryController::GetMaxInventory
extern "C" u32 THISCALL ext_5af2a0(Count5 *cnt, u32 type, u32 n);   // ZFFInventoryCount::SetNoOfItem
extern "C" u32 THISCALL ext_5b04e0(u8 *inv, u32 a, u32 b, u32 c, u32 d, u32 e);  // GiveDefaultAdditional (by value)
extern "C" u32 THISCALL ext_5af260(u8 *list, u8 *info);             // ZFFInventoryInfoList::RemoveInventoryInfo
extern "C" u32 THISCALL ext_5aef10(u8 *rebel);                      // (rebel unlock reset, unnamed)
extern "C" u32 THISCALL ext_4cc1d0(u8 *list);                       // (list count, unnamed)
extern "C" u8 *THISCALL ext_5af0d0(u8 *list, u32 index);            // ZFFInventoryInfoList::(index) record
extern "C" u32 THISCALL ext_5aee20(u8 *rebel, u32 type, u32 n);     // (rebel stash add, unnamed)
extern "C" u32 THISCALL ext_569260(u8 *self);                       // ZFFInventorySelector::UpdateWeaponStash

static inline u8 *refTable() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// The weapon list (static at 0x6a7400: 3,5,6,7,8,11,4,10); the first entry 3 is handled before the loop index.
static const u32 WEAPONS[8] = {3, 5, 6, 7, 8, 11, 4, 10};
// The counted items (static at 0x6a7420: 13,12,14,16) and 15, in the order the loop visits them.
static const u32 COUNTED[5] = {13, 12, 14, 16, 15};

static void THISCALL selectorInit2(u8 *self) {
  u8 *sys = G(u8 *, 0x70039c);
  u32 id = 0;
  // hero: message "HitmanGround" (0x681320) -> object
  vcall<u32>(vcall<u8 *>(refTable(), 0x138), 0x88, 0x681320u, &id);
  *(u32 *)(self + 0x90) = vcall<u32>(refTable(), 0x58, id);

  // item lists: "ZListInventoryBinding" (0x6a7374) -> info list 1; "rZListAvailibleItems" (0x6a738c) -> list 2
  id = 0;
  vcall<u32>(vcall<u8 *>(refTable(), 0x138), 0x88, 0x6a7374u, &id);
  ext_5aee60(self + 0x180, id);
  id = 0;
  vcall<u32>(vcall<u8 *>(refTable(), 0x138), 0x88, 0x6a738cu, &id);
  ext_5aee60(self + 0x1d4, id);
  (void)sys;

  u8 *prof = *(u8 **)(self + 0x94) + 0x57;     // A in the asm
  u8 *inv = prof + 0xe18;
  u8 *rebel = prof + 0xe44;
  u8 *list1 = self + 0x180;
  u8 *list2 = self + 0x1d4;

  // what the profile holds in the large and small slots
  u32 lt, st, cnt;
  ext_5b04a0(inv, &lt, &cnt);
  ext_5b04c0(inv, &st, &cnt);
  u32 first = (u32)(ext_5adda0(prof) & 0xff);

  // chapter switch on the profile holder byte +0x4a ('2'..'8'), jump table 0x5688d8
  u8 *holder = *(u8 **)(self + 0x94);
  if (holder) {
    s32 idx = (s8)holder[0x4a] - 0x32;
    if ((u32)idx <= 6) {
      auto setLarge = [&](u32 t, u32 n) { ext_5b07d0(inv, t, n); };
      auto setSmall = [&](u32 t, u32 n) { ext_5b07f0(inv, t, n); };
      auto ammo = [&](u32 t) { return ext_5aef80(list1, t); };
      switch (idx) {
        case 0:  // '2'
          if (st == 0) setSmall(4, ammo(3));
          break;
        case 1:  // '3' and '7'
        case 5:
          if (lt == 0) setLarge(5, ammo(5));
          if (st == 0) setSmall(3, ammo(3));
          break;
        case 2:  // '4'
          if (lt == 0) setLarge(6, ammo(6));
          if (st == 0) setSmall(3, ammo(3));
          break;
        case 3:  // '5'
          if (first) {
            setLarge(8, ammo(8));
            setSmall(3, ammo(3));
          } else {
            if (lt == 0) setLarge(8, ammo(8));
            if (st == 0) setSmall(3, ammo(3));
          }
          break;
        case 4:  // '6': nothing
          break;
        case 6:  // '8'
          if (lt == 0) setLarge(7, ammo(7));
          if (st == 0) setSmall(3, ammo(3));
          break;
      }
    }
  }

  ext_567930(self, self + 0x228);

  // rebel-base weapons: each available weapon gets its ammo and joins list 2 (once)
  for (u32 k = 0; k < 8; k++) {
    u32 t = WEAPONS[k];
    if (!ext_5af230(rebel, t)) continue;
    u32 ammoNow = ext_5aefc0(rebel, t);
    if (ext_5af130(list2, t)) continue;
    if (ext_5af130(list2, t)) continue;
    u8 *info = ext_5af130(list1, t);
    if (!info) continue;
    *(u32 *)(info + 4) = ammoNow;
    info[0x14] = 1;
    ext_5aedf0(list2, info);
  }

  // controller maxima, then the counted items that are not in list 2 get zero
  u8 ctrl[0x78];
  ext_5afc10(ctrl);
  Count5 maxc;
  ext_5afce0(ctrl, &maxc);
  for (u32 k = 0; k < 5; k++) {
    u32 t = COUNTED[k];
    if (!ext_5af130(list2, t)) ext_5af2a0(&maxc, t, 0);
  }
  ext_5b04e0(inv, maxc.c[0], maxc.c[1], maxc.c[2], maxc.c[3], maxc.c[4]);

  // the profile's large and small slots: their info record gets its ammo added and is taken out of list 2
  ext_5b04a0(inv, &lt, &cnt);
  u32 st2 = 0, cnt2s = 0;
  ext_5b04c0(inv, &st2, &cnt2s);
  u32 typ[2] = {lt, st2};
  u32 cn[2] = {cnt, cnt2s};
  for (int k = 0; k < 2; k++) {
    u8 *info = ext_5af130(list2, typ[k]);
    if (!info || !info[0x14]) continue;
    u8 *obj = *(u8 **)info;
    *(u32 *)(info + 4) += cn[k];
    u32 v = vcall<u32>(obj, 0x354);
    if (*(u32 *)(info + 4) > v + *(u32 *)(info + 0xc)) {
      *(u32 *)(info + 4) = vcall<u32>(obj, 0x354) + *(u32 *)(info + 0xc);
    }
    if (k == 0) ext_5b07d0(inv, typ[0], *(u32 *)(info + 4));
    else ext_5b07f0(inv, typ[1], *(u32 *)(info + 4));
    ext_5af260(list2, info);
  }

  ext_5aef10(rebel);
  u32 n = ext_4cc1d0(list2);
  if (n) {
    for (u32 i = 0; i < n; i++) {
      u8 *info = ext_5af0d0(list2, i);
      if (info[0x14]) ext_5aee20(rebel, *(u32 *)(info + 0x10), *(u32 *)(info + 4));
    }
  }

  vcall<u32>(self, 0x64, 0x10u);

  // stash: for each held weapon, the eight (value, type) slots that show it take its record value
  for (u32 k = 0; k < 8; k++) {
    u32 t = WEAPONS[k];
    u8 *info = ext_5af130(list2, t);
    if (!info || info[0x14]) continue;
    for (u32 s = 0; s < 8; s++) {
      u32 base = 0x3ee + 8 * s;
      if (*(u32 *)(self + base + 4) == t) *(u32 *)(self + base) = *(u32 *)(self + 0x326 + 12 * t);
    }
  }
  ext_569260(self);
}
PCREG(568350, selectorInit2);
