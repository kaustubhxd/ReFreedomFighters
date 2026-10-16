// batch1307.cpp - inventory thread (inline-inventory, 2026-10-11): ZActionGetItem/PickupItem::Execute,
// ZActionSwapItems::CallBack, ZItem::GetItemTemplate/GetMarkedGeom, Item_If GetOwner/GetName,
// ZFFInventoryController::GiveAmmoBox, CInventory::AddListToInventory, ZGameOSD::WheelInventoryGetItem,
// CPlayerInventory::GetFFInventory.
#include "ff.h"

struct V4 { u32 a, b, c, d; };
extern "C" u32 THISCALL ext_467410(u8 *self, u32 obj, u32 t, V4 v);  // (hand attach list update)
extern "C" u32 THISCALL ext_461570(u8 *anim, float t, u32 cb, u32 data);  // ZBoneAnim::AddCallBackAlways
extern "C" u32 THISCALL ext_4cc1d0(u8 *s);                           // MYSTR c_str
extern "C" u32 THISCALL ext_4cbec0(u8 *s);                           // MYSTR::~MYSTR()
extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 i);                 // opaque call parameter i
extern "C" u32 THISCALL ext_5002f0(u8 *self, u32 v);                 // set opaque int value
extern "C" u32 THISCALL ext_50d7b0(u8 *self, u32 *v);                // set opaque reference value
extern "C" u32 THISCALL ext_5af5b0(u8 *bridge, u32 *type, u32 *n, u32 large);  // ZFFInventoryBridge::GetWeapon
extern "C" u32 THISCALL ext_5af130(u8 *list, u32 type);              // ZFFInventoryInfoList::GetInventoryInfo(type)
extern "C" u32 THISCALL ext_5af7c0(u8 *bridge, u32 type, u32 n, u32 b);  // ZFFInventoryBridge::GiveAmmo
extern "C" u32 THISCALL ext_4acf30(u8 *self, u32 id);                // CInventory::AddItem(unsigned int)
extern "C" u32 THISCALL ext_4dc630(u8 *geom, u32 a, u32 b);          // ZBaseGeom::SetControl
extern "C" u32 THISCALL ext_4f9680(u32 self, u32 set);               // ZGui_Sound::PlaySound
extern "C" u32 THISCALL ext_5ab230(u8 *self, u32 msg);               // ZOnScreenDisplay::WheelMessage(unsigned int)
extern "C" u32 THISCALL ext_5ab2a0(u8 *self, u32 text);              // ZOnScreenDisplay::WheelMessage(char*)
extern "C" u32 THISCALL ext_5aede0(u8 *self);                        // ZFFInventoryInfoList ctor
extern "C" u32 THISCALL ext_5aee60(u8 *self, u32 id);                // ZFFInventoryInfoList::AddList
extern "C" u32 THISCALL ext_65e090(u8 *self);                        // ZFFInventoryBridge ctor
extern "C" u32 THISCALL ext_5afbb0(u8 *self, u32 hero, u8 *list);    // ZFFInventoryBridge::SetData
extern "C" u32 THISCALL ext_5af350(u8 *bridge, u32 type);            // ZFFInventoryBridge::GetNoOf
extern "C" u32 THISCALL ext_5af2a0(u8 *self, u32 type, u32 n);       // ZFFInventoryCount::SetNoOfItem
extern "C" void FASTCALL ext_43e960(float *a, const float *b);       // vsub in place (a -= b)

static inline u8 *refTable() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
static inline u8 isA(u8 *g, u32 type) { return (u8)vcall<u32>(g, 0x1e0, type); }
static inline u32 nameOr(u32 nm) { return nm ? nm : 0x67c8e8; }
static inline u8 *logger(u32 file, u32 line) { return vcall<u8 *>(G(u8 *, 0x700390), 0x20, file, line); }
static inline void logPrint2(u8 *p, u32 msg) { (*(void (**)(u8 *, u32))(*(u8 **)p + 0x2c))(p, msg); }
static inline void logPrint3(u8 *p, u32 msg, u32 a) { (*(void (**)(u8 *, u32, u32))(*(u8 **)p + 0x2c))(p, msg, a); }
typedef int (*stricmp_t)(u32, u32);
#define crt_stricmp (*(stricmp_t *)0x676414)

// ---------------------------------------------------------------- actions
// 0x4864e0 ZActionGetItem::Execute() (map): take from a container template (0x1007d4) target +0x18, else +0x14. The
// actor (+0xc) plays slot 0x228(target, 1, 0.0, -1.0, speed) with speed = random (sys slot 0x1c0, x87) * 0.4 + 0.8,
// and the callback 0x465710 is added (always) at t=5.0. Returns true; no target: own slot 0xc.
typedef long double(THISCALL *rnd_fn)(u8 *, u32, u32);
static u32 THISCALL getExecute(u8 *self) {
  u8 *t = vcall<u8 *>(*(u8 **)(self + 8), 0x2e8);
  u32 target = isA(t, 0x1007d4) ? *(u32 *)(self + 0x18) : *(u32 *)(self + 0x14);
  if (!target) return vcall<u32>(self, 0xc);
  u8 *sys = G(u8 *, 0x70039c);
  long double r = (*(rnd_fn *)(*(u8 **)sys + 0x1c0))(sys, 0x68cdc4, 0x4c);
  float speed = (float)(r * (long double)0.4f + (long double)0.8f);
  u8 *anim = vcall<u8 *>(*(u8 **)(self + 0xc), 0x228, target, 1u, 0u, 0xbf800000u, speed);
  u32 res = ext_461570(anim, 5.0f, 0x465710, 0);
  return (res & ~0xffu) | 1;
}
PCREG(4864e0, getExecute);

// 0x4865a0 ZActionPickupItem::Execute() (map): the item's (+8) world matrix/position (slots 0x2e0, 0x98) go to the
// actor (+0xc slot 0x94); the hand (+0x10 slot 0x1c) aims at it (callback record {0x465708,0,0,0}, 0.84). The
// height of the item relative to the actor (actor slot 0x3a8 -> 0x398, minus the item position) picks the pickup
// animation frames: y > 80: 0..31, > 50: 46..76, > 20: 91..121, > -60: 136..166, else 181..228; actor slot
// 0x228(anim +0x14, 1, from, to, 1.0). Returns true.
static u32 THISCALL pickupExecute(u8 *self) {
  float m[12], pos[3], v[3];
  vcall<u32>(*(u8 **)(self + 8), 0x2e0, m, pos);
  vcall<u32>(*(u8 **)(self + 8), 0x98, m, pos);
  vcall<u32>(*(u8 **)(self + 0xc), 0x94, m, pos);
  V4 cb = {0x465708, 0, 0, 0};
  (*(u32(THISCALL **)(u8 *, u32, float *, float *, u32, V4))(*(u8 **)(*(u8 **)(self + 0x10)) + 0x1c))(
      *(u8 **)(self + 0x10), *(u32 *)(self + 0xc), m, pos, 0x3f570a3d, cb);
  u8 *avt = **(u8 ***)(self + 0xc);
  u32 p = (*(u32(THISCALL **)(u8 *, float *))(avt + 0x3a8))(*(u8 **)(self + 0xc), v);
  (*(u32(THISCALL **)(u8 *, u32))(avt + 0x398))(*(u8 **)(self + 0xc), p);
  ext_43e960(v, pos);
  float y = v[1];
  u32 a, b;
  if (y > 80.0f) { a = 0; b = 0x41f80000; }
  else if (y > 50.0f) { a = 0x42380000; b = 0x42980000; }
  else if (y > 20.0f) { a = 0x42b60000; b = 0x42f20000; }
  else if (y > -60.0f) { a = 0x43080000; b = 0x43260000; }
  else { a = 0x43350000; b = 0x43640000; }
  u32 r = vcall<u32>(*(u8 **)(self + 0xc), 0x228, *(u32 *)(self + 0x14), 1u, a, b, 0x3f800000u);
  return (r & ~0xffu) | 1;
}
PCREG(4865a0, pickupExecute);

// 0x4862b0 ZActionSwapItems::CallBack() (map): both hands (+0xc, +0x10) get the list update, release their items
// (slot 0x10, slot 8(actor, 0)), then each item goes into the other hand (slot 8(actor, item id)). Returns false.
static u32 THISCALL swapCallBack(u8 *self) {
  V4 v = {0, 0, 0, 0xffffffffu};
  ext_467410(*(u8 **)(self + 0xc) + 4, *(u32 *)(self + 8), 0, v);
  ext_467410(*(u8 **)(self + 0x10) + 4, *(u32 *)(self + 8), 0, v);
  u32 a = vcall<u32>(*(u8 **)(self + 0xc), 0x10);
  vcall<u32>(*(u8 **)(self + 0xc), 8, *(u32 *)(self + 8), 0u);
  u32 b = vcall<u32>(*(u8 **)(self + 0x10), 0x10);
  u32 r = vcall<u32>(*(u8 **)(self + 0x10), 8, *(u32 *)(self + 8), 0u);
  if (a) {
    u8 *vt = **(u8 ***)(self + 0x10);
    u32 id = vcall<u32>(refTable(), 0x4c, a);
    r = (*(u32(THISCALL **)(u8 *, u32, u32))(vt + 8))(*(u8 **)(self + 0x10), *(u32 *)(self + 8), id);
  }
  if (b) {
    u8 *vt = **(u8 ***)(self + 0xc);
    u32 id = vcall<u32>(refTable(), 0x4c, b);
    r = (*(u32(THISCALL **)(u8 *, u32, u32))(vt + 8))(*(u8 **)(self + 0xc), *(u32 *)(self + 8), id);
  }
  return r & ~0xffu;
}
PCREG(4862b0, swapCallBack);

// ---------------------------------------------------------------- ZItem
// 0x46e800 ZItem::GetItemTemplate() const (map): the template from id +0x60; missing: "ERROR: Item %s does not have a
// Item template" (zitem.cpp:0x4df) with the item's path (slot 0x1d8(&str, 1)).
static u32 THISCALL itemGetTemplate(u8 *self) {
  u32 t = vcall<u32>(refTable(), 0x58, *(u32 *)(self + 0x60));
  if (t) return t;
  u8 *p = logger(0x6887c4, 0x4df);
  u8 str[0x80];
  u8 *s = vcall<u8 *>(self, 0x1d8, str, 1u);
  logPrint3(p, 0x6889f4, ext_4cc1d0(s));
  ext_4cbec0(str);
  return 0;
}
PCREG(46e800, itemGetTemplate);

// 0x46e9e0 ZItem::GetMarkedGeom(const char*) (map): the list +0x70 holds geom ids; the first whose name matches
// (_stricmp) is unmarked: removed from +0x6c and +0x74 (slot 0x40) and from +0x70; returned. Stale ids are removed.
static u32 THISCALL itemGetMarkedGeom(u8 *self, u32 name) {
  if (!*(u32 *)(self + 0x70)) return 0;
  u32 it[3];
  vcall<u32>(*(u8 **)(self + 0x70), 0x4c, it);
  for (u32 *e = vcall<u32 *>(*(u8 **)(self + 0x70), 0x64, it); e; e = vcall<u32 *>(*(u8 **)(self + 0x70), 0x64, it)) {
    u8 *g = vcall<u8 *>(refTable(), 0x58, e[0]);
    if (!g) {
      vcall<u32>(*(u8 **)(self + 0x70), 0x44, it);
      continue;
    }
    if (crt_stricmp(nameOr(*(u32 *)(g + 4)), name)) continue;
    vcall<u32>(*(u8 **)(self + 0x6c), 0x40, e[0]);
    vcall<u32>(*(u8 **)(self + 0x74), 0x40, e[0]);
    vcall<u32>(*(u8 **)(self + 0x70), 0x44, it);
    return (u32)g;
  }
  return 0;
}
PCREG(46e9e0, itemGetMarkedGeom);

// ---------------------------------------------------------------- Item_If
// 0x50c450 GetOwner(params) (map): result 0; for a ZItem, the owner (slot 0x2f4) as a reference id result.
static void THISCALL scriptGetOwner(u8 *, u8 *params) {
  ext_5002f0((u8 *)ext_5003d0(*(u8 **)(params + 8), 0), 0);
  u32 *p0 = (u32 *)ext_5003d0(*(u8 **)(params + 4), 0);
  u8 *o = vcall<u8 *>(refTable(), 0x58, *p0);
  if (!o) {
    logPrint2(logger(0x69d420, 0x217), 0x69d754);
    return;
  }
  if (!isA(o, 0x1007d1)) {
    u8 *p = logger(0x69d420, 0x21c);
    logPrint3(p, 0x69d5fc, *(u32 *)(o + 4));
    return;
  }
  u8 *vt = *(u8 **)refTable();
  u32 own = vcall<u32>(o, 0x2f4);
  u32 id = (*(u32(THISCALL **)(u8 *, u32))(vt + 0x4c))(refTable(), own);
  ext_50d7b0((u8 *)ext_5003d0(*(u8 **)(params + 8), 0), &id);
}
PCREG(50c450, scriptGetOwner);

// 0x50c360 GetName(params) (map): a "String" value (factory = parameter block +0xc slot 0(name, 0)) gets the item
// template's name (slot 0x30); the result slot (tag byte +4: 0 empty, 4 string) takes a reference (slot 0x24) after
// releasing (slot 0x28) an old string; the temporary is released (slot 0x28). Warnings item_if.cpp:0x15b / 0x15e.
static void THISCALL scriptGetName(u8 *, u8 *params) {
  u8 *fac = *(u8 **)(params + 0xc);
  u8 *s = (*(u8 *(THISCALL **)(u8 *, u32, u32))(*(u8 **)fac))(fac, 0x67a14c, 0);
  u32 *p0 = (u32 *)ext_5003d0(*(u8 **)(params + 4), 0);
  u8 *o = vcall<u8 *>(refTable(), 0x58, *p0);
  if (o) {
    if (isA(o, 0x1007d1)) {
      u8 *t = vcall<u8 *>(o, 0x2e8);
      vcall<u32>(s, 0x30, *(u32 *)(t + 4));
    } else {
      u8 *p = logger(0x69d420, 0x15b);
      logPrint3(p, 0x69d650, *(u32 *)(o + 4));
    }
  } else {
    logPrint2(logger(0x69d420, 0x15e), 0x69d698);
  }
  u8 *v = (u8 *)ext_5003d0(*(u8 **)(params + 8), 0);
  u8 tag = v[4];
  if (tag == 0 || tag == 4) {
    if (tag == 4) vcall<u32>(*(u8 **)v, 0x28);
    *(u32 *)v = vcall<u32>(s, 0x24);
    v[4] = 4;
  }
  vcall<u32>(s, 0x28);
}
PCREG(50c360, scriptGetName);

// ---------------------------------------------------------------- ZFFInventoryController
// 0x5afd00 GiveAmmoBox(EFFItemType&, unsigned&, EFFItemType&, unsigned&) (map): an ammo box tops up the large and the
// small weapon: each gets a third of its record's +8 (box amount) added, capped at the max (+0xc), if below it
// (GiveAmmo(type, new, 0)). The count references return how much was added. Returns whether anything was given.
static u8 THISCALL ctlGiveAmmoBox(u8 *self, u32 *lt, u32 *ln, u32 *st, u32 *sn) {
  u8 *br = self + 0x18;
  u8 given = 0;
  ext_5af5b0(br, lt, ln, 1);
  ext_5af5b0(self + 0x18, st, sn, 0);
  u32 types[2] = {*lt, *st};
  u32 cnt[2] = {*ln, *sn};
  for (int k = 0; k < 2; k++) {
    u32 t = types[k];
    if (!t) continue;
    u8 *info = (u8 *)ext_5af130(*(u8 **)(self + 0x14), t);
    u32 c = cnt[k];
    u32 mx = *(u32 *)(info + 0xc);
    if (c >= mx) continue;
    u32 n = *(u32 *)(info + 8) / 3 + c;
    if (n > mx) n = mx;
    cnt[k] = n;
    ext_5af7c0(br, t, n, 0);
    given = 1;
  }
  *ln = cnt[0] - *ln;
  *sn = cnt[1] - *sn;
  return given;
}
PCREG(5afd00, ctlGiveAmmoBox);

// ---------------------------------------------------------------- CInventory
// 0x4ad3a0 CInventory::AddListToInventory(REFTAB*) (map): each listed item is added (AddItem); active items (class
// bit 0x400 clear) are deactivated (control 0x800000, slot 0x158), owned by the inventory's actor (+0x44 id, item
// slot 0x2f0(id, 0, 0)) and hidden (slot 0x2d0(1, 0)). Items whose template says 2 (slot 0x300) are also equipped
// by the actor (slot 0x548(item, 0)).
static void THISCALL invAddList(u8 *self, u8 *l) {
  if (!l || !vcall<u32>(l, 0x14)) return;
  u32 it[4];
  vcall<u32>(l, 0x4c, it);
  u32 x = vcall<u32>(l, 0x5c, it);
  while (it[0]) {
    u8 *item = (u8 *)ext_4acf30(self, x);
    if (item) {
      u8 *bg = *(u8 **)(item + 8);
      if (!(*(u32 *)(bg + 0x3c) & 0x400)) {
        ext_4dc630(bg, 0x800000, 0);
        vcall<u32>(item, 0x158);
        u8 *vt = *(u8 **)item;
        u32 id = vcall<u32>(refTable(), 0x4c, *(u32 *)(self + 0x44));
        (*(u32(THISCALL **)(u8 *, u32, u32, u32))(vt + 0x2f0))(item, id, 0, 0);
        vcall<u32>(item, 0x2d0, 1u, 0u);
      }
      u8 *t = vcall<u8 *>(item, 0x2e8);
      if (t && vcall<u32>(t, 0x300) == 2) vcall<u32>(*(u8 **)(self + 0x44), 0x548, item, 0u);
    }
    x = vcall<u32>(l, 0x5c, it);
  }
}
PCREG(4ad3a0, invAddList);

// ---------------------------------------------------------------- weapon wheel
// 0x5e9b70 ZGameOSD::WheelInventoryGetItem() (map): snapshot of the wheel's 8 pockets (+0x37d..+0x3c1); a new
// selection (+0x3c2, != last +0x1d47, != 8) plays GUI sound 0. Per pocket: the item pointer and the message id shown
// (WheelMessage(id)) or an empty message. Pocket 6 hides its message when +0x39a is 2. Selection 8 (none) shows an
// empty message and returns 0 without remembering it. Remembers the selection in +0x1d47.
static u32 THISCALL wheelGetItem(u8 *self) {
  u8 *w = *(u8 **)(self + 0x1d0f);
  u8 b[0x45];
  for (int i = 0; i < 0x45; i++) b[i] = w[0x37d + i];
#define WB(off) (*(u32 *)(b + (off) - 0x37d))
  u32 sel = *(u32 *)(w + 0x3c2);
  if (sel != *(u32 *)(self + 0x1d47) && sel != 8) ext_4f9680(0x700e24, 0);
  w = *(u8 **)(self + 0x1d0f);
  u32 item = 0, msg = 0;
  bool show = false;   // WheelMessage(id) (even for id 0) instead of the empty text
  switch (*(u32 *)(w + 0x3c2)) {
    case 0: msg = WB(0x381); if (msg) { item = WB(0x3a6); show = true; } break;
    case 1: item = WB(0x3b2); break;
    case 2: item = WB(0x3ba); if (item) { msg = WB(0x392); show = true; } break;
    case 3: item = WB(0x3a2); if (item) { msg = WB(0x37d); show = true; } break;
    case 4: msg = WB(0x389); if (msg) { item = WB(0x3ae); show = true; } break;
    case 5: item = WB(0x3be); break;
    case 6: item = WB(0x3b6); if (item && WB(0x39a) != 2) { msg = WB(0x396); show = true; } break;
    case 7: item = WB(0x3aa); if (item) { msg = WB(0x385); show = true; } break;
    case 8: ext_5ab2a0(w, 0x677b5a); return 0;
    default: break;
  }
#undef WB
  if (show) ext_5ab230(w, msg);
  else ext_5ab2a0(w, 0x677b5a);
  *(u32 *)(self + 0x1d47) = *(u32 *)(*(u8 **)(self + 0x1d0f) + 0x3c2);
  return item;
}
PCREG(5e9b70, wheelGetItem);

// ---------------------------------------------------------------- CPlayerInventory
// 0x5b0360 CPlayerInventory::GetFFInventory() (map): builds an info list from "ZListInventoryBinding" and a bridge to
// the hero ("HitmanGround"), then copies the hero's counts of Frag, Molotov, C4, FirstAid, Binoculars into +0x18
// and the large (+8 type, +0x10 count) and small (+0xc, +0x14) weapons. This is what the profile stores between
// levels.
static void THISCALL pinvGetFFInventory(u8 *self) {
  u8 list[0x54];
  ext_5aede0(list);
  u8 *m = vcall<u8 *>(refTable(), 0x138);
  u32 id = 0;
  vcall<u32>(m, 0x88, 0x6a7374u, &id);
  ext_5aee60(list, id);
  u8 br[0xc];
  ext_65e090(br);
  m = vcall<u8 *>(refTable(), 0x138);
  id = 0;
  vcall<u32>(m, 0x88, 0x681320u, &id);
  u32 hero = vcall<u32>(refTable(), 0x58, id);
  ext_5afbb0(br, hero, list);
  static const u32 types[5] = {0xd, 0xc, 0xe, 0x10, 0xf};
  for (int i = 0; i < 5; i++) ext_5af2a0(self + 0x18, types[i], ext_5af350(br, types[i]));
  ext_5af5b0(br, (u32 *)(self + 8), (u32 *)(self + 0x10), 1);
  ext_5af5b0(br, (u32 *)(self + 0xc), (u32 *)(self + 0x14), 0);
}
PCREG(5b0360, pinvGetFFInventory);
