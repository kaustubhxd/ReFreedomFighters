// batch1303.cpp - inventory thread (inline-inventory, 2026-10-11): the FF inventory model (ZFFInventoryCount,
// ZFFInventoryInfoList, ZFFInventoryBridge, ZFFInventoryController, ZFFAddedWeaponsToRebelBase), the HUD inventory
// text, profile helpers, ZFFItemBomb::Init2, ZFFActionDropC4::Execute and CFFTools_if::GetHeroItem.
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 i);                 // opaque call parameter i (pointer to value)
extern "C" u32 THISCALL ext_5002f0(u8 *self, u32 v);                 // set opaque return value
extern "C" u32 THISCALL ext_591e50(u8 *hero, u32 type);              // ZFFHERO::GetItem(EFFItemType)
extern "C" u32 THISCALL ext_5ae450(u8 *prof, u8 *buf);               // CPlayerProfile::LoadProfileFromBuffer(char*)
extern "C" u32 THISCALL ext_5ae900(u8 *prof, u8 *buf);               // (profile header read, unnamed)
extern "C" u32 THISCALL ext_5abcd0(u8 *self);                        // CMessageBasics::IsVisible()
extern "C" u32 THISCALL ext_5acac0(u8 *self, u32 b);                 // (OSD inventory panel show)
extern "C" u32 THISCALL ext_5ac940(u8 *self, u8 *text);              // CMessageBasics::SetText(const char*)
extern "C" u32 THISCALL ext_5edb00(u8 *self, u32 h);                 // CSpriteBorder2D::SetHeight(unsigned int)
extern "C" u32 THISCALL ext_5b0b70(u8 *self, u32 name);              // CSaveMissions::GetLevelVar(const char*)
extern "C" u32 THISCALL ext_5aeff0(u8 *list, u32 item);              // ZFFInventoryInfoList::GetFFItemType(ZItem*)
extern "C" u32 THISCALL ext_5af1d0(u8 *self, u32 type);              // ZFFInventoryCount::GetNoOfItem(EFFItemType)
extern "C" u32 THISCALL ext_5af2a0(u8 *self, u32 type, u32 n);       // ZFFInventoryCount::SetNoOfItem
extern "C" u32 THISCALL ext_5af130(u8 *list, u32 type);              // ZFFInventoryInfoList::GetInventoryInfo(EFFItemType)
extern "C" u32 THISCALL ext_5aedb0(u8 *self);                        // ZFFInventoryCount::ZFFInventoryCount()
extern "C" u32 THISCALL ext_65e090(u8 *self);                        // ZFFInventoryBridge::ZFFInventoryBridge()
extern "C" u32 THISCALL ext_5afe20(u8 *self, u32 type);              // ZFFInventoryController::RoomFor(EFFItemType)
extern "C" u32 THISCALL ext_5a9e20(u8 *osd, u32 name);               // ZOnScreenDisplay::InventoryAdd(const char*)
extern "C" u32 THISCALL ext_5aa060(u8 *osd, u32 text);               // ZOnScreenDisplay::InventoryText(char*)
extern "C" u32 THISCALL ext_5b0010(u8 *self, u8 *item);              // ZGameOSD::InventoryOutputWeaponInfo(ZItem*)
extern "C" u32 THISCALL ext_589c20(u8 *self, u32 c);                 // ZFFGameData::GetGameOSD(char)
extern "C" u32 THISCALL ext_4614d0(u8 *anim, float t, u32 cb, u32 data);  // ZBoneAnim::AddCallBack

static inline u8 *refTable() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// Debug log: ZSysInterface-like logger at 0x700390, slot 0x20(file, line) returns a printer whose slot 0x2c is a
// cdecl printf (printer, fmt, ...).
static inline void logMsg2(u32 file, u32 line, u32 msg) {
  u8 *p = vcall<u8 *>(G(u8 *, 0x700390), 0x20, file, line);
  (*(void (**)(u8 *, u32))(*(u8 **)p + 0x2c))(p, msg);
}

// ---------------------------------------------------------------- ZFFInventoryCount (20 bytes)
// Layout from GetNoOfItem/SetNoOfItem (high): +0 = item type 14, +4 = type 16, +8 = type 13, +0xc = type 12,
// +0x10 = type 15 stored as a bool. Other types: 0 / ignored.
// 0x5af1d0 ZFFInventoryCount::GetNoOfItem(EFFItemType)
static u32 THISCALL countGet(u8 *self, u32 type) {
  u32 *c = (u32 *)self;
  switch (type - 0xc) {
    case 0: return c[3];
    case 1: return c[2];
    case 2: return c[0];
    case 3: return c[4] != 0;
    case 4: return c[1];
    default: return 0;
  }
}
PCREG(5af1d0, countGet);

// 0x5af2a0 ZFFInventoryCount::SetNoOfItem(EFFItemType, unsigned int)
static void THISCALL countSet(u8 *self, u32 type, u32 n) {
  u32 *c = (u32 *)self;
  switch (type - 0xc) {
    case 0: c[3] = n; break;
    case 1: c[2] = n; break;
    case 2: c[0] = n; break;
    case 3: c[4] = n != 0; break;
    case 4: c[1] = n; break;
    default: break;
  }
}
PCREG(5af2a0, countSet);

// ---------------------------------------------------------------- ZFFInventoryInfoList: u32 count, then pointers
// to ZFFInventoryInfo records (+0 template, +4 ammo, +0xc max ammo, +0x10 item type).
// 0x5af0f0 GetInventoryInfo(ZItemTemplate*) (high): the record whose template matches, else 0.
static u32 THISCALL infoGetByTemplate(u8 *self, u32 t) {
  u32 n = *(u32 *)self;
  u32 **e = (u32 **)(self + 4);
  for (u32 i = 0; i < n; i++)
    if (*e[i] == t) return (u32)e[i];
  return 0;
}
PCREG(5af0f0, infoGetByTemplate);

// 0x5aef80 GetAmmo(EFFItemType) (medium): ammo (+4) of the first record of that type, else 0.
static u32 THISCALL infoGetAmmo(u8 *self, u32 type) {
  u32 n = *(u32 *)self;
  u8 **e = (u8 **)(self + 4);
  for (u32 i = 0; i < n; i++)
    if (*(u32 *)(e[i] + 0x10) == type) {
      u8 *r = e[i];
      return r ? *(u32 *)(r + 4) : 0;
    }
  return 0;
}
PCREG(5aef80, infoGetAmmo);

// 0x5af260 RemoveInventoryInfo(ZFFInventoryInfo*) (high): unordered remove (last entry moves into the hole).
static void THISCALL infoRemove(u8 *self, u32 info) {
  if (!info) return;
  u32 n = *(u32 *)self;
  u32 *e = (u32 *)(self + 4);
  for (u32 i = 0; i < n; i++)
    if (e[i] == info) {
      *(u32 *)self = n - 1;
      e[i] = e[n - 1];
      return;
    }
}
PCREG(5af260, infoRemove);

// 0x5aedf0 (map: ZFFInventorySelector::AddAdditionalWeaponToList, but `ret 4` = one argument, so that name is an
// ICF/map mismatch): add a type to a list of at most 20 (count at +0, types at +4) if not already present.
static void THISCALL typeListAddUnique(u8 *self, u32 type) {
  u32 n = *(u32 *)self;
  if (n >= 0x14) return;
  u32 *e = (u32 *)(self + 4);
  for (u32 i = 0; i < n; i++)
    if (e[i] == type) return;
  e[n] = type;
  ++*(u32 *)self;
}
PCREG(5aedf0, typeListAddUnique);

// ---------------------------------------------------------------- ZFFAddedWeaponsToRebelBase
// 0x5af040 GetIndex(EFFItemType) (high): weapon types 3..11 to slots 0..7 (type 9 has none -> 8).
static u32 THISCALL rebelGetIndex(u8 *, u32 type) {
  switch (type - 3) {
    case 0: return 0;
    case 1: return 6;
    case 2: return 1;
    case 3: return 2;
    case 4: return 3;
    case 5: return 4;
    case 7: return 7;
    case 8: return 5;
    default: return 8;
  }
}
PCREG(5af040, rebelGetIndex);

// ---------------------------------------------------------------- ZFFInventoryBridge (+0 hero, +4 info list, +8 ...)
// 0x5af300 GetAmmo(ZItem*) (map): rounds in the weapon (item slot 0x35c) plus, if the hero has a matching ammo item
// (hero slot 0x55c(item)), that item's count (slot 0x320).
static u32 THISCALL bridgeGetAmmo(u8 *self, u8 *item) {
  u32 a = vcall<u32>(item, 0x35c);
  u8 *am = vcall<u8 *>(*(u8 **)self, 0x55c, item);
  if (am) return vcall<u32>(am, 0x320) + a;
  return a;
}
PCREG(5af300, bridgeGetAmmo);

// 0x5afbb0 SetData(ZFFHERO*, ZFFInventoryInfoList*) (map): store both; +8 = hero slot 0x464 (its inventory);
// warns ("InventoryBridge.cpp" line 0x18) if any is missing.
static void THISCALL bridgeSetData(u8 *self, u8 *hero, u32 list) {
  *(u8 **)self = hero;
  *(u32 *)(self + 4) = list;
  if (hero) *(u32 *)(self + 8) = vcall<u32>(hero, 0x464);
  if (!*(u32 *)self || !*(u32 *)(self + 4) || !*(u32 *)(self + 8)) logMsg2(0x6b0f44, 0x18, 0x6b0f80);
}
PCREG(5afbb0, bridgeSetData);

// ---------------------------------------------------------------- ZFFInventoryController
// +0 ZFFInventoryCount (maximum carried), +0x14 info list, +0x18 ZFFInventoryBridge.
// 0x5afc10 ZFFInventoryController() (high): maximums type 13 = 10, type 12 = 10, type 14 = 4, type 16 = 8,
// type 15 = 1 (bool).
static u8 *THISCALL ctlCtor(u8 *self) {
  ext_5aedb0(self);
  ext_65e090(self + 0x18);
  ext_5af2a0(self, 0xd, 0xa);
  ext_5af2a0(self, 0xc, 0xa);
  ext_5af2a0(self, 0xe, 4);
  ext_5af2a0(self, 0x10, 8);
  ext_5af2a0(self, 0xf, 1);
  *(u32 *)(self + 0x14) = 0;
  return self;
}
PCREG(5afc10, ctlCtor);

// 0x5afc70 GetMaxAmmo(ZItem*) (map): weapon types 3..8, 10, 11 use the info record's max ammo (+0xc); counted items
// 12..14 and 16 use the maximum count; 9, 15 and others have none.
static u32 THISCALL ctlGetMaxAmmo(u8 *self, u32 item) {
  u32 type = ext_5aeff0(*(u8 **)(self + 0x14), item);
  switch (type - 3) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 7: case 8:
      return *(u32 *)(ext_5af130(*(u8 **)(self + 0x14), type) + 0xc);
    case 9: case 10: case 11: case 13:
      return ext_5af1d0(self, type);
    default:
      return 0;
  }
}
PCREG(5afc70, ctlGetMaxAmmo);

// 0x5afdd0 RoomFor(ZItem*) (map): needs the info list (error "InventoryController.cpp" line 0x74 otherwise) and an
// item; forwards to RoomFor(EFFItemType).
static u32 THISCALL ctlRoomFor(u8 *self, u32 item) {
  if (!*(u32 *)(self + 0x14)) {
    logMsg2(0x6b10bc, 0x74, 0x6b10f8);
    return 0;
  }
  if (!item) return 0;
  return ext_5afe20(self, ext_5aeff0(*(u8 **)(self + 0x14), item));
}
PCREG(5afdd0, ctlRoomFor);

// ---------------------------------------------------------------- HUD
// 0x5aa060 ZOnScreenDisplay::InventoryText(char*) (map): empty text hides the panel (+0x640) if visible; otherwise
// shows it with the text. With the border sprite (+0x658) the border is resized: 0x20 when hidden, 0x2c with text.
static void THISCALL osdInventoryText(u8 *self, u8 *text) {
  u32 h;
  if (!*text) {
    if (!(u8)ext_5abcd0(*(u8 **)(self + 0x640))) return;
    ext_5acac0(*(u8 **)(self + 0x640), 0);
    if (!self[0x658]) return;
    h = 0x20;
  } else {
    ext_5acac0(*(u8 **)(self + 0x640), 1);
    ext_5ac940(*(u8 **)(self + 0x640), text);
    if (!self[0x658]) return;
    h = 0x2c;
  }
  ext_5edb00(*(u8 **)(self + 0x470), h);
  vcall<u32>(*(u8 **)(self + 0x470), 8);
}
PCREG(5aa060, osdInventoryText);

// 0x5ab130 ZOnScreenDisplay::WheelInventoryCommand(cmd) (low): while the wheel is shown and the command differs from
// the selection +0x3c2: command 8 (none) starts the 0.2 s close timer +0x3d0 if it is exactly 0; any other command
// selects that slot and resets the timer.
static void THISCALL osdWheelCommand(u8 *self, u32 cmd) {
  if (!self[0x3c6]) return;
  if (*(u32 *)(self + 0x3c2) == cmd) return;
  if (cmd == 8) {
    if (*(float *)(self + 0x3d0) == 0.0f) *(u32 *)(self + 0x3d0) = 0x3e4ccccd;
    return;
  }
  *(u32 *)(self + 0x3d0) = 0;
  *(u32 *)(self + 0x3c2) = cmd;
}
PCREG(5ab130, osdWheelCommand);

// 0x5b0220 ZGameOSD::InventoryShow() (map): the hero's (+0x1d0b) current item (slot 0x504): none -> InventoryAdd(0)
// and empty text; else the item template's (slot 0x2e8) name (or "<NONAME>") and the weapon info line.
static void THISCALL gameOsdInventoryShow(u8 *self) {
  u8 *it = vcall<u8 *>(*(u8 **)(self + 0x1d0b), 0x504);
  if (!it) {
    ext_5a9e20(*(u8 **)(self + 0x1d0f), 0);
    u8 *osd = *(u8 **)(self + 0x1d0f);
    if (osd) ext_5aa060(osd, 0x677b5a);
    return;
  }
  u8 *t = vcall<u8 *>(it, 0x2e8);
  u32 nm = *(u32 *)(t + 4);
  ext_5a9e20(*(u8 **)(self + 0x1d0f), nm ? nm : 0x67c8e8);
  ext_5b0010(self, it);
}
PCREG(5b0220, gameOsdInventoryShow);

// ---------------------------------------------------------------- profile
// 0x56b930 (map: CPlayerProfile::SetFileName, low; the body is a save-device method): load profile slot `idx` into
// `prof` from the device buffers (+0x2100 + idx*0x400, header +idx*0x80) and copy the slot's dword (+0x2000 + idx*4)
// to prof+0x86.
static void THISCALL saveDevLoadProfile(u8 *self, u8 *prof, u32 idx) {
  ext_5ae450(prof, self + (idx << 10) + 0x2100);
  ext_5ae900(prof, self + (idx << 7));
  *(u32 *)(prof + 0x86) = *(u32 *)(self + idx * 4 + 0x2000);
}
PCREG(56b930, saveDevLoadProfile);

// 0x5addc0 CPlayerProfile::GetAddCharactersId(sCharactersToAdd&) (medium): in chapter '2' the characters recruited in
// C02B / C02A ("C02B_Flag" -> id 1 in slot 0, "C02A_Flag" -> id 2 in slot 1) join; four slots zeroed first.
static void THISCALL profAddCharacters(u8 *self, u32 *out) {
  out[0] = 0; out[1] = 0; out[2] = 0; out[3] = 0;
  if (self[2] != 0x32) return;
  if (ext_5b0b70(self + 0x4b8, 0x6b045c)) out[0] = 1;
  if (ext_5b0b70(self + 0x4b8, 0x6b03f8)) out[1] = 2;
}
PCREG(5addc0, profAddCharacters);

// ---------------------------------------------------------------- script / bomb / C4
// 0x553dd0 CFFTools_if::GetHeroItem(OpaqueCallParameters_t&) (map): hero (ZFFGameData+0x2c3d) GetItem(type from
// parameter 0), returned as a reference id in parameter 1. The ref-table vtable is read before GetItem.
static u32 THISCALL toolsGetHeroItem(u8 *, u8 *params) {
  u32 *p0 = (u32 *)ext_5003d0(*(u8 **)(params + 4), 0);
  u8 *hero = *(u8 **)(G(u8 *, 0x7003b8) + 0x2c3d);
  u8 *vt = *(u8 **)refTable();
  u32 item = ext_591e50(hero, *p0);
  u32 id = (*(u32(THISCALL **)(u8 *, u32))(vt + 0x4c))(refTable(), item);
  u8 *out = (u8 *)ext_5003d0(*(u8 **)(params + 8), 0);
  return ext_5002f0(out, id);
}
PCREG(553dd0, toolsGetHeroItem);

// 0x5d4610 ZFFItemBomb::Init2() (map): registers for message "ObjectItemNotify" (sys+0x9b slot 0x138 -> slot 0x88,
// id out-param stored at +0x56) and caches player 0's OSD at +0x5f.
static void THISCALL bombInit2(u8 *self) {
  u8 *m = vcall<u8 *>(refTable(), 0x138);
  u32 id = 0;
  vcall<u32>(m, 0x88, 0x6b2cd8u, &id);
  *(u32 *)(self + 0x56) = id;
  *(u32 *)(self + 0x5f) = ext_589c20(G(u8 *, 0x7003b8), 0);
}
PCREG(5d4610, bombInit2);

// 0x5e0200 ZFFActionDropC4::Execute() (map): like ZActionDropItem::Execute without the no-item branch; the callback
// fires at t = 0.016.
static u32 THISCALL dropC4Execute(u8 *self) {
  vcall<u32>(*(u8 **)(self + 0xc), 0x10);
  u8 *anim = vcall<u8 *>(*(u8 **)(self + 8), 0x228, *(u32 *)(self + 0x10), 1u, 0u, 0x41200000u, 0x3f800000u);
  u32 r = ext_4614d0(anim, bitsf(0x3c83126f), 0x465710, 0);
  return (r & ~0xffu) | 1;
}
PCREG(5e0200, dropC4Execute);
