// batch1301.cpp - inventory thread (inline-inventory, 2026-10-11): CInventory, CInventoryBinding, CPlayerProfile,
// CPlayerInventory, ZFFInventory*, ZFFItemBomb, ZScriptItemInterface_t and the inventory HUD (OSD) small functions.
#include "ff.h"

extern "C" u32 THISCALL ext_4e6330(u8 *rd, u8 *reftab);              // DBREAD::GetRefTab(REFTAB*)
extern "C" u32 THISCALL ext_4ad3a0(u8 *self, u8 *reftab);            // CInventory::AddListToInventory(REFTAB*)
extern "C" u32 THISCALL ext_6352f0(u8 *self, void *rd);              // ZEventBase::GetInput(DBREAD&)
extern "C" void ext_634d10(void *d, int v, u32 n);                   // memset (cdecl)
extern "C" u32 THISCALL ext_5acac0(u8 *self, u32 b);                 // (OSD inventory panel show, unnamed)
extern "C" u32 THISCALL ext_5edb00(u8 *self, u32 h);                 // CSpriteBorder2D::SetHeight(unsigned int)
extern "C" u32 THISCALL ext_5b0b70(u8 *self, u32 name);              // CSaveMissions::GetLevelVar(const char*)
extern "C" u32 THISCALL ext_5b0f20(u8 *self, u32 st, u32 name);      // CSaveMissions::GetSubZoneMissionInfo
extern "C" u32 THISCALL ext_5b0360(u8 *self);                        // CPlayerInventory::GetFFInventory()
extern "C" u32 THISCALL ext_5af040(u8 *self, u32 type);              // ZFFAddedWeaponsToRebelBase::GetIndex
extern "C" u32 THISCALL ext_5af3a0(u8 *self, u32 type);              // ZFFInventoryBridge::GetNoOfGrenade
extern "C" u32 THISCALL ext_5af430(u8 *self, u32 type);              // ZFFInventoryBridge::GetNoOfItem
extern "C" u32 THISCALL ext_5afbb0(u8 *self, u32 hero, u32 list);    // ZFFInventoryBridge::SetData
extern "C" u32 THISCALL ext_5b0220(u8 *self);                        // ZGameOSD::InventoryShow()
extern "C" u32 THISCALL ext_5aedb0(u8 *self);                        // ZFFInventoryCount::ZFFInventoryCount()
extern "C" u32 THISCALL ext_5aeda0(u8 *self);                        // (unnamed ctor of the +0x2c member)
extern "C" u32 THISCALL ext_589c20(u8 *self, u32 c);                 // ZFFGameData::GetGameOSD(char)
extern "C" u32 THISCALL ext_5ab130(u8 *self, u32 cmd);               // ZOnScreenDisplay::WheelInventoryCommand
extern "C" u32 THISCALL ext_5e9b70(u8 *self);                        // ZGameOSD::WheelInventoryGetItem()
extern "C" void ext_634273(void *p, u32 size);                       // operator delete(void*, size_t)

// ---------------------------------------------------------------- CInventory (event object holding a REFTAB at +0x6e)
// 0x4ab9b0 CInventory::CopyEventDataBlock(DBREAD&) (name from map): clears the REFTAB (slot 0xc), then reads it from
// the data block unless flag 2 of +4 is set.
static u32 THISCALL invCopyEvent(u8 *self, u8 *rd) {
  u8 *rt = self + 0x6e;
  u32 r = vcall<u32>(rt, 0xc);
  if (!(self[4] & 2)) r = ext_4e6330(rd, rt);
  return r;
}
PCREG(4ab9b0, invCopyEvent);

// 0x4abc00 CInventory::Init2(): if the REFTAB has entries (slot 0x14), add them to the inventory and clear it.
static u32 THISCALL invInit2(u8 *self) {
  u8 *rt = self + 0x6e;
  u32 n = vcall<u32>(rt, 0x14);
  if (!n) return 0;
  ext_4ad3a0(self, rt);
  return vcall<u32>(rt, 0xc);
}
PCREG(4abc00, invInit2);

// 0x4afd90 CInventoryBinding::Load(ZLoadGame*) (map): as ZItemState::Load but the second read is its own slot 0x84.
static u8 THISCALL bindingLoad(u8 *self, u8 *) {
  u32 rd = 0;
  *(u32 *)(self + 4) &= ~0x40u;
  ext_6352f0(self, &rd);
  vcall<u32>(self, 0x84, &rd);
  return 1;
}
PCREG(4afd90, bindingLoad);

// 0x4c5610 CInventoryBinding::CopyEventDataBlock(DBREAD&): tail call own slot 0x84 (ReadInput).
static u32 THISCALL bindingCopyEvent(u8 *self, u8 *rd) { return vcall<u32>(self, 0x84, rd); }
PCREG(4c5610, bindingCopyEvent);

// 0x4f9f30 ZItemTemplate::GetPointerPicture() const (low, ICF): +0x68.
static u32 THISCALL templGetPointerPicture(u8 *self) { return *(u32 *)(self + 0x68); }
PCREG(4f9f30, templGetPointerPicture);

// ---------------------------------------------------------------- ZScriptItemInterface_t (script binding "Item_If")
// Statics: 0x7012cc = current opaque object, 0x7012c8 = count, 0x7012d0 = 0xc8-byte buffer.
// 0x50d750 clean(): destroy (slot 4, arg 0) and forget the current object.
static void THISCALL scriptItemClean(u8 *) {
  u8 *o = G(u8 *, 0x7012cc);
  if (o) vcall<u32>(o, 4, 0u);
  G(u32, 0x7012cc) = 0;
}
PCREG(50d750, scriptItemClean);

// 0x50d770 consume(OpaqueType_t*): wipe the buffer, zero the count, delete (slot 0, flag 1) the current object.
static void THISCALL scriptItemConsume(u8 *, u32) {
  ext_634d10((void *)0x7012d0, 0, 0xc8);
  G(u32, 0x7012c8) = 0;
  u8 *o = G(u8 *, 0x7012cc);
  if (o) vcall<u32>(o, 0, 1u);
  G(u32, 0x7012cc) = 0;
}
PCREG(50d770, scriptItemConsume);

// 0x50d810 getTypeName(): "Item_If".
static u32 THISCALL scriptItemTypeName(u8 *) { return 0x69c77c; }
PCREG(50d810, scriptItemTypeName);

// ---------------------------------------------------------------- save device / profile
// 0x59b330 / 0x59b340 ZFFSaveDeviceInterface::GetNoOfProfiles / GetNoOfProfilesRef (medium): count at +0x121a8.
static u32 THISCALL saveDevNoOfProfiles(u8 *self) { return *(u32 *)(self + 0x121a8); }
PCREG(59b330, saveDevNoOfProfiles);
static u8 *THISCALL saveDevNoOfProfilesRef(u8 *self) { return self + 0x121a8; }
PCREG(59b340, saveDevNoOfProfilesRef);

// 0x5adda0 CPlayerProfile::FirstTimeInZone() (high): level variable "FirstTimeInZone" of the mission save (+0x4b8)
// is non-zero. setne only writes AL; the rest of EAX is the variable's value.
static u32 THISCALL profFirstTimeInZone(u8 *self) {
  u32 r = ext_5b0b70(self + 0x4b8, 0x6b08c0);
  return (r & ~0xffu) | (r != 0);
}
PCREG(5adda0, profFirstTimeInZone);

// 0x5ade30 CPlayerProfile::GetDeBriefingLocalizetPath() (map): byte +2 is the chapter digit ('2'..'8');
// "C0xRB/DeBriefing" for '3'..'8', C02RB for anything else.
static u32 THISCALL profDebriefPath(u8 *self) {
  switch ((s32)(s8)self[2] - 0x32) {
    case 1: return 0x6b0eb8;
    case 2: return 0x6b0ecc;
    case 3: return 0x6b0ee0;
    case 4: return 0x6b0ef4;
    case 5: return 0x6b0f08;
    case 6: return 0x6b0f1c;
    default: return 0x6b0ea4;
  }
}
PCREG(5ade30, profDebriefPath);

// 0x5ade90 CPlayerProfile::GetFFInventoryFromHero() (medium): the player inventory is embedded at +0xe18.
static u32 THISCALL profGetFFInventory(u8 *self) { return ext_5b0360(self + 0xe18); }
PCREG(5ade90, profGetFFInventory);

// 0x5adeb0 GetLevelVar / 0x5adee0 GetSubZoneMissionInfo (high): forward to the CSaveMissions at +0x4b8.
static u32 THISCALL profGetLevelVar(u8 *self, u32 name) { return ext_5b0b70(self + 0x4b8, name); }
PCREG(5adeb0, profGetLevelVar);
static u32 THISCALL profGetSubZone(u8 *self, u32 st, u32 name) { return ext_5b0f20(self + 0x4b8, st, name); }
PCREG(5adee0, profGetSubZone);

// 0x5ae240 CPlayerProfile::InitSaveDeviceSerialNumberAfterLoad() (map): asks sys+0x9b slot 0x134 for the save
// device, then its slot 0x6c(profile +0x8a, "SaveDeviceSerialNumber", 0x16).
static u32 THISCALL profInitSerial(u8 *self) {
  u8 *dev = vcall<u8 *>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x134);
  return vcall<u32>(dev, 0x6c, self + 0x8a, 0x6b09d8u, 0x16u);
}
PCREG(5ae240, profInitSerial);

// ---------------------------------------------------------------- ZFFInventory* value types
// 0x5aedb0 ZFFInventoryCount::ZFFInventoryCount() (high): five zero dwords (20-byte record).
static u8 *THISCALL invCountCtor(u8 *self) {
  u32 *p = (u32 *)self;
  p[0] = 0; p[1] = 0; p[2] = 0; p[3] = 0; p[4] = 0;
  return self;
}
PCREG(5aedb0, invCountCtor);

// 0x5aede0 ZFFInventoryInfoList::ZFFInventoryInfoList() (high): head pointer = 0.
static u8 *THISCALL infoListCtor(u8 *self) {
  *(u32 *)self = 0;
  return self;
}
PCREG(5aede0, infoListCtor);

// 0x65e090 ZFFInventoryBridge::ZFFInventoryBridge() (high): three zero dwords (hero, info list, ...).
static u8 *THISCALL bridgeCtor(u8 *self) {
  u32 *p = (u32 *)self;
  p[0] = 0; p[1] = 0; p[2] = 0;
  return self;
}
PCREG(65e090, bridgeCtor);

// 0x5aefc0 ZFFAddedWeaponsToRebelBase::GetAmmoForItem / 0x5af230 ItemAvailible (high): 8 slots; GetIndex returns 8
// for unknown types. Availability flags at +0, ammo counts at +0x20.
static u32 THISCALL rebelGetAmmo(u8 *self, u32 type) {
  u32 i = ext_5af040(self, type);
  if (i == 8) return 0;
  return *(u32 *)(self + i * 4 + 0x20);
}
PCREG(5aefc0, rebelGetAmmo);
static u32 THISCALL rebelAvailable(u8 *self, u32 type) {
  u32 i = ext_5af040(self, type);
  if (i == 8) return 0;
  return *(u32 *)(self + i * 4);
}
PCREG(5af230, rebelAvailable);

// 0x5af350 ZFFInventoryBridge::GetNoOf(EFFItemType) (map): types 12-13 are grenades (GetNoOfGrenade), 14-16 other
// counted items (GetNoOfItem); anything else 0.
static u32 THISCALL bridgeGetNoOf(u8 *self, u32 type) {
  switch (type - 0xc) {
    case 0: case 1: return ext_5af3a0(self, type);
    case 2: case 3: case 4: return ext_5af430(self, type);
    default: return 0;
  }
}
PCREG(5af350, bridgeGetNoOf);

// 0x5afce0 ZFFInventoryController::GetMaxInventory() (medium): returns the 20-byte ZFFInventoryCount at +0 by value
// (hidden result pointer).
static u8 *THISCALL ctlGetMaxInventory(u8 *self, u8 *out) {
  u32 *d = (u32 *)out, *s = (u32 *)self;
  u32 a = s[0], b = s[1], c = s[2], e = s[3], f = s[4];
  d[0] = a; d[1] = b; d[2] = c; d[3] = e; d[4] = f;
  return out;
}
PCREG(5afce0, ctlGetMaxInventory);

// 0x5afed0 ZFFInventoryController::SetData(ZFFHERO*, ZFFInventoryInfoList*) (medium): bridge at +0x18, list at +0x14.
static void THISCALL ctlSetData(u8 *self, u32 hero, u32 list) {
  ext_5afbb0(self + 0x18, hero, list);
  *(u32 *)(self + 0x14) = list;
}
PCREG(5afed0, ctlSetData);

// ---------------------------------------------------------------- CPlayerInventory (the loadout kept in the profile)
// 0x5b02b0 CPlayerInventory::CPlayerInventory() (medium): vtable 0x6b1148; ZFFInventoryCount at +0x18, a second
// member at +0x2c; large item type/count at +8/+0x10, small item type/count at +0xc/+0x14 all zero.
static u8 *THISCALL playerInvCtor(u8 *self) {
  *(u32 *)(self + 4) = 0;
  *(u32 *)self = 0x6b1148;
  ext_5aedb0(self + 0x18);
  ext_5aeda0(self + 0x2c);
  *(u32 *)(self + 8) = 0;
  *(u32 *)(self + 0xc) = 0;
  *(u32 *)(self + 0x10) = 0;
  *(u32 *)(self + 0x14) = 0;
  return self;
}
PCREG(5b02b0, playerInvCtor);

// 0x5b04a0 GetLargeItem / 0x5b04c0 GetSmallItem (low) / 0x5b07d0 SetLargeItem / 0x5b07f0 SetSmallItem (medium).
static void THISCALL playerInvGetLarge(u8 *self, u32 *type, u32 *n) {
  *type = *(u32 *)(self + 8);
  *n = *(u32 *)(self + 0x10);
}
PCREG(5b04a0, playerInvGetLarge);
static void THISCALL playerInvGetSmall(u8 *self, u32 *type, u32 *n) {
  *type = *(u32 *)(self + 0xc);
  *n = *(u32 *)(self + 0x14);
}
PCREG(5b04c0, playerInvGetSmall);
static void THISCALL playerInvSetLarge(u8 *self, u32 type, u32 n) {
  *(u32 *)(self + 8) = type;
  *(u32 *)(self + 0x10) = n;
}
PCREG(5b07d0, playerInvSetLarge);
static void THISCALL playerInvSetSmall(u8 *self, u32 type, u32 n) {
  *(u32 *)(self + 0xc) = type;
  *(u32 *)(self + 0x14) = n;
}
PCREG(5b07f0, playerInvSetSmall);

// ---------------------------------------------------------------- ZFFItemBomb (C4 / time bomb)
// 0x5d4210 ZFFItemBomb::CopyData(ZEventBase*) (high): copies +0x56 (dword), +0x5a (byte), +0x5b..+0x6e (5 dwords).
static void THISCALL bombCopyData(u8 *self, u8 *src) {
  *(u32 *)(self + 0x56) = *(u32 *)(src + 0x56);
  self[0x5a] = src[0x5a];
  *(u32 *)(self + 0x5b) = *(u32 *)(src + 0x5b);
  *(u32 *)(self + 0x5f) = *(u32 *)(src + 0x5f);
  *(u32 *)(self + 0x63) = *(u32 *)(src + 0x63);
  *(u32 *)(self + 0x67) = *(u32 *)(src + 0x67);
  *(u32 *)(self + 0x6b) = *(u32 *)(src + 0x6b);
}
PCREG(5d4210, bombCopyData);

// 0x5d4750 ZFFItemBomb::Load2() (high): caches the OSD of player 0 (ZFFGameData at 0x7003b8) at +0x5f.
static void THISCALL bombLoad2(u8 *self) { *(u32 *)(self + 0x5f) = ext_589c20(G(u8 *, 0x7003b8), 0); }
PCREG(5d4750, bombLoad2);

// 0x5df850 ZFFActionPickupItem::~ZFFActionPickupItem() (deleting dtor; ICF-shared with ZActionDropItem and
// ZFFActionDropC4): ZAction base vtable, 0x14 bytes.
static u8 *THISCALL ffPickupDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x685294;
  if (flags & 1) ext_634273(self, 0x14);
  return self;
}
PCREG(5df850, ffPickupDtor);

// ---------------------------------------------------------------- inventory HUD
// 0x5aa020 ZOnScreenDisplay::InventoryShow(bool) (map): forwards to the panel at +0x640; when hiding with byte
// +0x658 set, the border sprite (+0x470) is set to height 0x20 and refreshed (slot 8).
static void THISCALL osdInventoryShow(u8 *self, u32 show) {
  ext_5acac0(*(u8 **)(self + 0x640), show);
  if (self[0x658] && !(u8)show) {
    ext_5edb00(*(u8 **)(self + 0x470), 0x20);
    vcall<u32>(*(u8 **)(self + 0x470), 8);
  }
}
PCREG(5aa020, osdInventoryShow);

// 0x5ab1e0 ZOnScreenDisplay::WheelInventoryShow(bool) (low): on a change to hidden, if the wheel selection +0x3c2 is
// not 8 (none), remembers it: +0x3c7 = byte +0x37c, +0x3c8 = 0, +0x3cc = selection. Then stores the flag at +0x3c6.
static void THISCALL osdWheelShow(u8 *self, u32 show) {
  u8 s = (u8)show;
  if (self[0x3c6] == s) return;
  if (!s) {
    u32 sel = *(u32 *)(self + 0x3c2);
    if (sel != 8) {
      self[0x3c7] = self[0x37c];
      *(u32 *)(self + 0x3c8) = 0;
      *(u32 *)(self + 0x3cc) = sel;
    }
  }
  self[0x3c6] = s;
}
PCREG(5ab1e0, osdWheelShow);

// 0x5b0290 ZGameOSD::InventoryUpdate() (medium): show timer +0x1d91 = 2.0 s, flag +0x1d8c = 1, then InventoryShow.
static u32 THISCALL gameOsdInventoryUpdate(u8 *self) {
  *(u32 *)(self + 0x1d91) = 0x40000000;
  self[0x1d8c] = 1;
  return ext_5b0220(self);
}
PCREG(5b0290, gameOsdInventoryUpdate);

// 0x5e9b40 ZGameOSD::WheelInventoryCommand(cmd) (high): only while the weapon wheel (+0x1d0f) is shown (+0x3c6):
// pass the command on, then pick the highlighted item.
static void THISCALL gameOsdWheelCommand(u8 *self, u32 cmd) {
  u8 *w = *(u8 **)(self + 0x1d0f);
  if (w && w[0x3c6]) {
    ext_5ab130(w, cmd);
    ext_5e9b70(self);
  }
}
PCREG(5e9b40, gameOsdWheelCommand);
