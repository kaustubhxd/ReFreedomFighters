// batch253.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch253"): the inventory bridge
// call that gives the hero ammo (pickups, rebel base racks). Names from the GameCube name map; behaviour from the PC bytes.
#include "ff.h"

// 0x5af130 ZFFInventoryInfoList::GetInventoryInfo(EFFItemType k) ret 4: like 0x5af0f0, but matches the record's kind (+0x10).
static u8 *THISCALL getInventoryInfoByType_5af130(u32 *self, u32 k) {
  u32 n = self[0];
  for (u32 i = 0; i < n; i++)
    if (*(u32 *)(self[1 + i] + 0x10) == k) return (u8 *)self[1 + i];
  return 0;
}
PCREG(5af130, getInventoryInfoByType_5af130);

// 0x5afb40 ZFFInventoryBridge::SetAmmo(ZItem *gun, int n, bool spareOnly) ret 0xc. x = owner->vt[0x55c](gun) (spare-ammo
// item). spareOnly: x->vt[0x324](n) (the exe does not test x). Else with x: x->vt[0x324](n - gun->vt[0x35c]()) (the
// rounds already in the gun are not added to the spare count); without x: gun->vt[0x360](n).
static void THISCALL setAmmo_5afb40(u8 **self, u8 *gun, u32 n, u8 spareOnly) {
  u8 *x = (u8 *)vcall<u32>(self[0], 0x55c, (u32)gun);
  if (spareOnly) {
    vcall<void>(x, 0x324, n);
    return;
  }
  if (x) {
    u8 *xv = *(u8 **)x;   // the exe reads x's vtable before calling the gun
    u32 in = vcall<u32>(gun, 0x35c);
    (*(void(THISCALL **)(u8 *, u32))(xv + 0x324))(x, n - in);
  } else {
    vcall<void>(gun, 0x360, n);
  }
}
PCREG(5afb40, setAmmo_5afb40);

// 0x5af7c0 ZFFInventoryBridge::GiveAmmo(EFFItemType k, unsigned n, bool spareOnly) ret 0xc. Finds the info record of kind
// k (needs a nonzero first word), asks +8's vt[0x98](record[0], 0) for the item handle, and continues only while the
// engine db (vt[0x58]) knows it and the geom is a ZItemWeapon (geom->vt[0x1e0](db->vt[0x154]("ZItemWeapon", 0)[+0x23])).
// When the owner has no spare-ammo item for the gun (owner->vt[0x55c] is 0), it creates one: gun->vt[0x328]() is the ammo
// template, template->vt[0x2c4](owner->vt[0x20]('ITEM' 0x4954454d)) the new item, item->vt[0x2f0](db->vt[0x4c](owner), 0, 1)
// and item->vt[0x2d0](1, 0) (the exe pushes the 0, 1 words before the db call; vt[0x2f0] takes three words, ret 0xc).
// Then SetAmmo(gun, n, spareOnly).
static void THISCALL giveAmmo_5af7c0(u8 **self, u32 k, u32 n, u8 spareOnly) {
  u8 *info = getInventoryInfoByType_5af130((u32 *)self[1], k);
  if (!info || !*(u32 *)info) return;
  u32 h = vcall<u32>(self[2], 0x98, *(u32 *)info, 0u);
#define DB (*(u8 **)(*(u8 **)0x70039cu + 0x9b))
  if (!vcall<u32>(DB, 0x58, h)) return;
  u8 *g = (u8 *)vcall<u32>(DB, 0x58, h);
  u8 *ci = (u8 *)vcall<u32>(DB, 0x154, 0x6867bcu, 0u);
  if (!(u8)vcall<u32>(g, 0x1e0, *(u32 *)(ci + 0x23))) return;
  u8 *gun = (u8 *)vcall<u32>(DB, 0x58, h);
  if (!gun) return;
  if (!vcall<u32>(self[0], 0x55c, (u32)gun)) {
    u8 *tm = (u8 *)vcall<u32>(gun, 0x328);
    u8 *tv = *(u8 **)tm;   // read before the owner call, as the exe does
    u32 tag = vcall<u32>(self[0], 0x20, 0x4954454du);
    u8 *it = (u8 *)(*(u32(THISCALL **)(u8 *, u32))(tv + 0x2c4))(tm, tag);
    u8 *iv = *(u8 **)it;
    u32 oh = vcall<u32>(DB, 0x4c, (u32)self[0]);
    (*(void(THISCALL **)(u8 *, u32, u32, u32))(iv + 0x2f0))(it, oh, 0u, 1u);
    vcall<void>(it, 0x2d0, 1u, 0u);
  }
#undef DB
  setAmmo_5afb40(self, gun, n, spareOnly);
}
PCREG(5af7c0, giveAmmo_5af7c0);
