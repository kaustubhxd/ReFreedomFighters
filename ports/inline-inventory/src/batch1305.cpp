// batch1305.cpp - inventory thread (inline-inventory, 2026-10-11): profile save, inventory bridge give/set,
// default loadout, info-list lookups, ZFFItemBomb data/save, CInventoryBinding, the weapon wheel.
#include "ff.h"

extern "C" u32 THISCALL ext_5b1440(u8 *self, u8 *name);              // CSaveMissions::ZoneCompleted(const char*) const
extern "C" u32 THISCALL ext_5ad2b0(u8 *self, u8 *start);             // CPlayerStats::SetStartPoint(char*)
extern "C" u32 THISCALL ext_5c2c80(u8 *self);                        // (profile +0x92 reset, unnamed)
extern "C" u32 THISCALL ext_5b1150(u8 *self, u32 name, u32 v);       // CSaveMissions::AddResentMission
extern "C" u32 THISCALL ext_5ae710(u8 *self, u32 b);                 // CPlayerProfile::SaveRaw(bool)
extern "C" u32 THISCALL ext_5af130(u8 *list, u32 type);              // ZFFInventoryInfoList::GetInventoryInfo(EFFItemType)
extern "C" u32 THISCALL ext_5af300(u8 *self, u32 item);              // ZFFInventoryBridge::GetAmmo(ZItem*)
extern "C" u32 THISCALL ext_5af1d0(u8 *self, u32 type);              // ZFFInventoryCount::GetNoOfItem
extern "C" u32 THISCALL ext_5af2a0(u8 *self, u32 type, u32 n);       // ZFFInventoryCount::SetNoOfItem
extern "C" u32 THISCALL ext_4e5e60(void *rd);                        // DBREAD::operator unsigned int()
extern "C" void ext_4690b0(void *p, u32 size);                       // empty placement delete
extern "C" u32 THISCALL ext_4f9680(u32 self, u32 set);               // ZGui_Sound::PlaySound(ESoundSet_Gui)
extern "C" u32 THISCALL ext_5ab1e0(u8 *self, u32 show);              // ZOnScreenDisplay::WheelInventoryShow(bool)
extern "C" u32 THISCALL ext_5ab2a0(u8 *self, u32 text);              // ZOnScreenDisplay::WheelMessage(char*)
extern "C" u32 THISCALL ext_5e9b70(u8 *self);                        // ZGameOSD::WheelInventoryGetItem()

static inline u8 *refTable() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
static inline void logMsg2(u32 file, u32 line, u32 msg) {
  u8 *p = vcall<u8 *>(G(u8 *, 0x700390), 0x20, file, line);
  (*(void (**)(u8 *, u32))(*(u8 **)p + 0x2c))(p, msg);
}

// ---------------------------------------------------------------- CPlayerProfile
// 0x5ae680 CPlayerProfile::Save() (high): if the current zone (profile name at +0) is completed, the next start point
// is "C0xR" with x = chapter digit (+2) + 1 and the +0x92 block is reset; else the start point is the current zone.
// Unless the zone is a rebel base ('R' at +3), "FirstTimeInZone" is cleared (AddResentMission(name, 0)). SaveRaw(0).
static void THISCALL profSave(u8 *self) {
  if ((u8)ext_5b1440(self + 0x4b8, self)) {
    u8 buf[5];
    *(u32 *)buf = G(u32, 0x6b09f0);
    buf[4] = G(u8, 0x6b09f4);
    buf[2] = self[2] + 1;
    ext_5ad2b0(self + 0x35a, buf);
    ext_5c2c80(self + 0x92);
  } else {
    ext_5ad2b0(self + 0x35a, self);
  }
  if (self[3] != 0x52) ext_5b1150(self + 0x4b8, 0x6b08c0, 0);
  ext_5ae710(self, 0);
}
PCREG(5ae680, profSave);

// 0x5b04e0 CPlayerInventory::GiveDefaultAdditional(ZFFInventoryCount) (high): copies the counts of item types 13,
// 12, 14, 16, 15 (table at 0x6a7420 + 15, 0) from the by-value count into the inventory's count (+0x18) when non-zero.
struct Count5 { u32 c[5]; };
static void THISCALL pinvGiveDefault(u8 *self, Count5 cnt) {
  u32 types[6] = {0xd, 0xc, 0xe, 0x10, 0xf, 0};
  for (u32 i = 0; types[i]; i++) {
    u32 t = types[i];
    if (ext_5af1d0((u8 *)&cnt, t)) ext_5af2a0(self + 0x18, t, ext_5af1d0((u8 *)&cnt, t));
  }
}
PCREG(5b04e0, pinvGiveDefault);

// ---------------------------------------------------------------- ZFFInventoryInfoList
// 0x5aeff0 GetFFItemType(ZItem*) (medium): item template (slot 0x2e8) -> type (+0x10) of its record, else 0.
static u32 THISCALL infoGetFFItemType(u8 *self, u8 *item) {
  if (!item) return 0;
  u32 t = vcall<u32>(item, 0x2e8);
  u32 n = *(u32 *)self;
  u32 **e = (u32 **)(self + 4);
  for (u32 i = 0; i < n; i++)
    if (*e[i] == t) {
      u8 *r = (u8 *)e[i];
      return r ? *(u32 *)(r + 0x10) : 0;
    }
  return 0;
}
PCREG(5aeff0, infoGetFFItemType);

// 0x5af170 GetNext(ZFFInventoryInfo*) (medium): the record after `info`; 0 after the last; the first record when
// `info` is 0 or not in the list; 0 for an empty list.
static u32 THISCALL infoGetNext(u8 *self, u32 info) {
  u32 n = *(u32 *)self;
  if (!n) return 0;
  u32 *e = (u32 *)(self + 4);
  if (info) {
    for (u32 i = 0; i < n; i++)
      if (e[i] == info) return i < n - 1 ? e[i + 1] : 0;
  }
  return e[0];
}
PCREG(5af170, infoGetNext);

// ---------------------------------------------------------------- ZFFInventoryBridge
// 0x5af3a0 GetNoOfGrenade(EFFItemType) (map): the type's template -> the hero inventory's (+8) item of that template
// (slot 0x98(template, 0), an id) -> its count via GetAmmo. Warns (InventoryBridge.cpp:0x20) when not set up.
static u32 THISCALL bridgeGetNoOfGrenade(u8 *self, u32 type) {
  if (!*(u32 *)self || !*(u32 *)(self + 4) || !*(u32 *)(self + 8)) {
    logMsg2(0x6b0f44, 0x20, 0x6b0fd0);
    return 0;
  }
  u32 *r = (u32 *)ext_5af130(*(u8 **)(self + 4), type);
  if (!r || !*r) return 0;
  u32 id = vcall<u32>(*(u8 **)(self + 8), 0x98, *r, 0u);
  u32 o = vcall<u32>(refTable(), 0x58, id);
  if (!o) return 0;
  return ext_5af300(self, o);
}
PCREG(5af3a0, bridgeGetNoOfGrenade);

// 0x5af8f0 GiveNoOfItem(EFFItemType, unsigned int n) (map): creates n items of the type's template (template slot
// 0x2c4(world group, 'MEIT')) and gives each to the hero (item slot 0x2f0(hero id, 0, 1), then 0x2d0(1, 0)).
static void THISCALL bridgeGiveNoOfItem(u8 *self, u32 type, u32 n) {
  u8 **info = (u8 **)ext_5af130(*(u8 **)(self + 4), type);
  if (!info || !*info) return;
  for (; n; n--) {
    u8 *it = vcall<u8 *>(*info, 0x2c4, *(u32 *)(refTable() + 0xadc), 0x4954454du);
    if (it) {
      u8 *vt = *(u8 **)it;
      u32 id = vcall<u32>(refTable(), 0x4c, *(u32 *)self);
      (*(u32(THISCALL **)(u8 *, u32, u32, u32))(vt + 0x2f0))(it, id, 0, 1);
      vcall<u32>(it, 0x2d0, 1u, 0u);
    }
  }
}
PCREG(5af8f0, bridgeGiveNoOfItem);

// 0x5afb40 SetAmmo(ZItem*, int, bool) (map): with the hero's ammo item for this weapon (hero slot 0x55c): absolute
// (flag) sets it to n (slot 0x324, no null check), else to n minus the rounds in the weapon (slot 0x35c). Without an
// ammo item the weapon itself gets n (slot 0x360).
static void THISCALL bridgeSetAmmo(u8 *self, u8 *item, u32 n, u32 abs) {
  u8 *am = vcall<u8 *>(*(u8 **)self, 0x55c, item);
  if ((u8)abs) {
    vcall<u32>(am, 0x324, n);
    return;
  }
  u8 *ivt = *(u8 **)item;
  if (am) {
    u8 *avt = *(u8 **)am;
    u32 r = (*(u32(THISCALL **)(u8 *))(ivt + 0x35c))(item);
    (*(u32(THISCALL **)(u8 *, u32))(avt + 0x324))(am, n - r);
    return;
  }
  (*(u32(THISCALL **)(u8 *, u32))(ivt + 0x360))(item, n);
}
PCREG(5afb40, bridgeSetAmmo);

// ---------------------------------------------------------------- ZFFItemBomb (C4)
// 0x5d4250 ZFFItemBomb::CopyEventDataBlock(DBREAD&) (map): three uints: a (target -> +0x6b), b (owner -> +0x63),
// +0x67 raw; ids resolved through the ref table; armed flag +0x5a = 1, timer +0x5b = 0.
static void THISCALL bombCopyEvent(u8 *self, u8 *rd) {
  *(u32 *)(self + 0x63) = 0;
  *(u32 *)(self + 0x6b) = 0;
  u32 a = ext_4e5e60(rd);
  u32 b = ext_4e5e60(rd);
  *(u32 *)(self + 0x67) = ext_4e5e60(rd);
  if (b) *(u32 *)(self + 0x63) = vcall<u32>(refTable(), 0x58, b);
  if (a) *(u32 *)(self + 0x6b) = vcall<u32>(refTable(), 0x58, a);
  self[0x5a] = 1;
  *(u32 *)(self + 0x5b) = 0;
}
PCREG(5d4250, bombCopyEvent);

// 0x5d4840 ZFFItemBomb::Save(ZSaveGame*) (map): +0x48 (slot 0x64), +0x56 (0x3c), byte +0x5a (0x60), float +0x5b
// (0x4c), +0x63, +0x6b (0x64), then the message id of "rFF_C4_BombDmgList" (0x3c). Clears flag 0x40 of +4.
static u8 THISCALL bombSave(u8 *self, u8 *g) {
  *(u32 *)(self + 4) &= ~0x40u;
  vcall<u32>(g, 0x64, *(u32 *)(self + 0x48));
  vcall<u32>(g, 0x3c, *(u32 *)(self + 0x56));
  vcall<u32>(g, 0x60, (u32)self[0x5a]);
  vcall<u32>(g, 0x4c, *(u32 *)(self + 0x5b));
  vcall<u32>(g, 0x64, *(u32 *)(self + 0x63));
  vcall<u32>(g, 0x64, *(u32 *)(self + 0x6b));
  u8 *m = vcall<u8 *>(refTable(), 0x138);
  u32 id = 0;
  vcall<u32>(m, 0x88, 0x6b52ccu, &id);
  vcall<u32>(g, 0x3c, id);
  return 1;
}
PCREG(5d4840, bombSave);

// ---------------------------------------------------------------- CInventoryBinding
// 0x5d4920 (map: CInventoryBinding::~CInventoryBinding, low; ICF with ZShakeCamera): ZEventBase destructor, size 0x65.
static u8 *THISCALL bindingDtor(u8 *self, u32 flags) {
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  vcall<u32>(refTable(), 0x34, self);
  if (flags & 1) {
    if (!(flags & 4)) {
      typedef void (*hook_t)();
      hook_t h = G(hook_t, 0x7003b0);
      if (!h) __builtin_debugtrap();
      h();
      return self;
    }
    ext_4690b0(self, 0x65);
  }
  return self;
}
PCREG(5d4920, bindingDtor);

// 0x5d4a70 CInventoryBinding::ReadInput(DBREAD&) (map): five uints a..e: +0x4c = +0x50 = a, +0x48 = object of id b,
// +0x58 = c, +0x61 = d, +0x54 = e.
static void THISCALL bindingReadInput(u8 *self, u8 *rd) {
  u32 a = ext_4e5e60(rd);
  u32 b = ext_4e5e60(rd);
  u32 c = ext_4e5e60(rd);
  u32 d = ext_4e5e60(rd);
  u32 e = ext_4e5e60(rd);
  *(u32 *)(self + 0x58) = c;
  u32 o = vcall<u32>(refTable(), 0x58, b);
  *(u32 *)(self + 0x54) = e;
  *(u32 *)(self + 0x48) = o;
  *(u32 *)(self + 0x61) = d;
  *(u32 *)(self + 0x4c) = a;
  *(u32 *)(self + 0x50) = a;
}
PCREG(5d4a70, bindingReadInput);

// ---------------------------------------------------------------- weapon wheel
// 0x5e9ce0 ZGameOSD::WheelInventoryShow(bool) (map): own slot 0x90 first. Open: GUI sound 2 if it was closed, show,
// clear the message. Close (only if open): hide; the highlighted item (WheelInventoryGetItem) is equipped by the
// hero (+0x1d0b slots 0x3dc then 0x4dc(item, 1)) with GUI sound 1; nothing highlighted plays sound 3.
static u32 THISCALL gameOsdWheelShow(u8 *self, u32 show) {
  if (!*(u32 *)(self + 0x1d0f)) return 0;
  vcall<u32>(self, 0x90);
  if ((u8)show) {
    if (!(*(u8 **)(self + 0x1d0f))[0x3c6]) ext_4f9680(0x700e24, 2);
    ext_5ab1e0(*(u8 **)(self + 0x1d0f), show);
    return ext_5ab2a0(*(u8 **)(self + 0x1d0f), 0x677b5a);
  }
  u8 *w = *(u8 **)(self + 0x1d0f);
  if (!w[0x3c6]) return (u32)w;
  ext_5ab1e0(w, 0);
  u32 it = ext_5e9b70(self);
  if (!it) return ext_4f9680(0x700e24, 3);
  ext_4f9680(0x700e24, 1);
  vcall<u32>(*(u8 **)(self + 0x1d0b), 0x3dc);
  vcall<u32>(*(u8 **)(self + 0x1d0b), 0x4dc, it, 1u);
  return ext_5ab2a0(*(u8 **)(self + 0x1d0f), 0x677b5a);
}
PCREG(5e9ce0, gameOsdWheelShow);
