// batch1306.cpp - inventory thread (inline-inventory, 2026-10-11): ZFFInventoryController::RoomFor(type),
// ZItemState Command/Init/EnableCamera, ZItemTemplate state lookups, ZItemTemplateContainer::CopyData,
// ZFFInventoryInfoList::AddList, the put/pickup action callbacks, ZFFItemBomb::Init, Item_If DestroyItem,
// CInventory::Load2.
#include "ff.h"

extern "C" u32 THISCALL ext_5af5b0(u8 *bridge, u32 *type, u32 *n, u32 large);  // ZFFInventoryBridge::GetWeapon
extern "C" u32 THISCALL ext_5af350(u8 *bridge, u32 type);            // ZFFInventoryBridge::GetNoOf(EFFItemType)
extern "C" u32 THISCALL ext_5af1d0(u8 *self, u32 type);              // ZFFInventoryCount::GetNoOfItem
extern "C" u32 FASTCALL ext_4cc850(u32 a, u32 b);                    // striwcmp(const char*, const char*)
extern "C" u32 THISCALL ext_41e680(u8 *self);                        // ConvPtr(void*)
extern "C" u32 THISCALL ext_43f8c0(u8 *self, u8 *src);               // ZGROUP::CopyData(const ZGEOM*)
struct V4 { u32 a, b, c, d; };
extern "C" u32 THISCALL ext_467410(u8 *self, u32 obj, u32 t, V4 v);  // (hand attach list update)
extern "C" void FASTCALL ext_4de7a0(float *m);                       // mreset(float*)
extern "C" u32 THISCALL ext_4dc630(u8 *geom, u32 a, u32 b);          // ZBaseGeom::SetControl
extern "C" u32 THISCALL ext_4dbe30(u8 *geom, u32 b);                 // ZBaseGeom::MakeDynamic(bool)
extern "C" u32 THISCALL ext_4dc440(u8 *geom, u32 b);                 // ZBaseGeom::SetAutoRoomAssign(bool)
extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 i);                 // opaque call parameter i
extern "C" u32 THISCALL ext_5002f0(u8 *self, u32 v);                 // set opaque value

static inline u8 *refTable() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
static inline u8 isA(u8 *g, u32 type) { return (u8)vcall<u32>(g, 0x1e0, type); }
static inline u32 nameOr(u32 nm) { return nm ? nm : 0x67c8e8; }   // "<NONAME>"
static inline u8 *logger(u32 file, u32 line) { return vcall<u8 *>(G(u8 *, 0x700390), 0x20, file, line); }
static inline void logPrint2(u8 *p, u32 msg) { (*(void (**)(u8 *, u32))(*(u8 **)p + 0x2c))(p, msg); }
static inline void logPrint3(u8 *p, u32 msg, u32 a) { (*(void (**)(u8 *, u32, u32))(*(u8 **)p + 0x2c))(p, msg, a); }
typedef int (*stricmp_t)(u32, u32);
#define crt_stricmp (*(stricmp_t *)0x676414)   // IAT: api-ms-win-crt-string _stricmp

// ---------------------------------------------------------------- ZFFInventoryController
// 0x5afe20 RoomFor(EFFItemType) (map): pistols (3 Magnum, 4 Beretta) need the small slot free, long guns (5-8, 10,
// 11) the large slot (GetWeapon(&type, &n, large) leaves type 0 when empty); counted items (12-16) return the free
// count (limit - carried, or 0); 0..2, 9 and unknown types (> 16) always fit (1).
static u32 THISCALL ctlRoomForType(u8 *self, u32 type) {
  if (type > 0x10) return 1;
  static const u8 idx[17] = {0, 0, 0, 1, 1, 2, 2, 2, 2, 0, 2, 2, 3, 3, 3, 3, 3};
  switch (idx[type]) {
    case 1:
    case 2: {
      u32 n = (u32)self;  // the exe reuses the pushed ECX slot; GetWeapon writes it
      ext_5af5b0(self + 0x18, &type, &n, idx[type] == 2);
      return type == 0;
    }
    case 3: {
      u32 have = ext_5af350(self + 0x18, type);
      if (have < ext_5af1d0(self, type)) return ext_5af1d0(self, type) - have;
      return 0;
    }
    default:
      return 1;
  }
}
PCREG(5afe20, ctlRoomForType);

// ---------------------------------------------------------------- ZItemState
// 0x4684c0 ZItemState::Command(unsigned short, void*) (map): message +0x4a (MSG_ITEMSETSTATE): own slot 0x84 with the
// owner's (+0x44 slot 0x20(data)) result. Message +0x4c (MSG_ITEMGETANIMNAME): "rItem" from the CCom (slot 0x88,
// into the argument slot), own slot 0x88(data), then the item gets slot 0x310(this, t) where
// t = (game time sys+0x40 - (int)(+0x57 * -1024)) / 1024. Returns 0.
static u32 THISCALL itemStateCommand(u8 *self, u32 cmd, u8 *data) {
  u16 c = (u16)cmd;
  if (c == *(u16 *)(self + 0x4a)) {
    u8 *vt = *(u8 **)self;
    u32 x = vcall<u32>(*(u8 **)(self + 0x44), 0x20, data);
    (*(u32(THISCALL **)(u8 *, u32))(vt + 0x84))(self, x);
    return 0;
  }
  if (c == *(u16 *)(self + 0x4c)) {
    u32 slot = cmd;
    vcall<u32>(data, 0x88, 0x688a30u, &slot);
    u8 *it = vcall<u8 *>(refTable(), 0x58, slot);
    vcall<u32>(self, 0x88, data);
    s32 t = (s32)(*(float *)(self + 0x57) * -1024.0f);
    s32 now = *(s32 *)(G(u8 *, 0x70039c) + 0x40);
    float v = (float)(now - t) * 0.0009765625f;
    vcall<u32>(it, 0x310, self, v);
  }
  return 0;
}
PCREG(4684c0, itemStateCommand);

// 0x468320 ZItemState::Init() (map): the owner (+0x44) must be INACTIVE (class info bit 0x400) and its parent (slot
// 0x20) a ZItemTemplate; then the state registers with the template (slot 0x2dc(owner, +0x4e)). Otherwise a warning
// (zitem.cpp:0xf7d "...is in ZROOT" / :0xf85 "...does not have a valid parent") and own slot 0x58 (tail).
static u32 THISCALL itemStateInit(u8 *self) {
  u8 *own = *(u8 **)(self + 0x44);
  u32 line, msg;
  if (*(u32 *)(*(u8 **)(own + 8) + 0x3c) & 0x400) {
    if (isA(vcall<u8 *>(own, 0x20), 0x1007d3)) {
      u8 *t = vcall<u8 *>(*(u8 **)(self + 0x44), 0x20);
      return vcall<u32>(t, 0x2dc, *(u32 *)(self + 0x44), *(u32 *)(self + 0x4e));
    }
    line = 0xf85;
    msg = 0x688f08;
  } else {
    line = 0xf7d;
    msg = 0x688ec0;
  }
  u8 *p = logger(0x6887c4, line);
  logPrint3(p, msg, nameOr(*(u32 *)(*(u8 **)(self + 0x44) + 4)));
  return vcall<u32>(self, 0x58);
}
PCREG(468320, itemStateInit);

// 0x468a30 ZItemState::EnableCamera(ZCAMERA*) (map): cameras named "*Overlay" are skipped. With an active camera list
// ("rActiveCameraList" message id via ref slot 0x138 -> 0x88) the camera is added to it (message "Camera_Add",
// zitem.cpp:0x1009, slot 0x128(msg, ConvPtr(cam), 0)); otherwise the system camera manager (sys+0x190f slot 0xac)
// gets (cam, 100000.0).
static void THISCALL itemStateEnableCamera(u8 *self, u8 *cam) {
  if (!ext_4cc850(nameOr(*(u32 *)(cam + 4)), 0x688f74)) return;
  u8 *m = vcall<u8 *>(refTable(), 0x138);
  u32 id = 0;
  vcall<u32>(m, 0x88, 0x688f80u, &id);
  u8 *sys = G(u8 *, 0x70039c);
  if (!id) {
    vcall<u32>(*(u8 **)(sys + 0x190f), 0xac, cam, 100000.0f);
    return;
  }
  u8 *lst = vcall<u8 *>(*(u8 **)(sys + 0x9b), 0x58, id);
  u16 msg = (u16)vcall<u32>(refTable(), 0x114, 0x688f94u, 0u, 0x6887c4u, 0x1009u);
  u8 *vt = *(u8 **)lst;
  u32 p = ext_41e680(cam);
  (*(u32(THISCALL **)(u8 *, u32, u32, u32))(vt + 0x128))(lst, msg, p, 0);
}
PCREG(468a30, itemStateEnableCamera);

// ---------------------------------------------------------------- ZItemTemplate state list (+0x70)
// The state list is a REFTAB of {ITEMSTATE state, u32 geom id} entries: slot 0x4c = begin(cursor), 0x64 = next
// entry pointer (0 at the end), 0x44 = remove current.
// 0x46b760 CheckStateExists(ITEMSTATE, const char*) (map): an entry with that state (and, with a name, whose geom has
// that name, _stricmp).
static u8 THISCALL templCheckState(u8 *self, u32 state, u32 name) {
  if (!*(u32 *)(self + 0x70)) return 0;
  u32 it[3];
  vcall<u32>(*(u8 **)(self + 0x70), 0x4c, it);
  for (u32 *e = vcall<u32 *>(*(u8 **)(self + 0x70), 0x64, it); e; e = vcall<u32 *>(*(u8 **)(self + 0x70), 0x64, it)) {
    if (e[0] != state) continue;
    if (!name) return 1;
    u8 *g = vcall<u8 *>(refTable(), 0x58, e[1]);
    if (!g) continue;
    if (!crt_stricmp(name, nameOr(*(u32 *)(g + 4)))) return 1;
  }
  return 0;
}
PCREG(46b760, templCheckState);

// 0x46d810 FindStateGeoms(REFTAB*, ITEMSTATE, const char*) (map): adds (slot 4) the geom ids of matching entries;
// entries whose geom no longer exists are removed.
static void THISCALL templFindStateGeoms(u8 *self, u8 *out, u32 state, u32 name) {
  if (!*(u32 *)(self + 0x70)) return;
  u32 it[3];
  vcall<u32>(*(u8 **)(self + 0x70), 0x4c, it);
  for (u32 *e = vcall<u32 *>(*(u8 **)(self + 0x70), 0x64, it); e; e = vcall<u32 *>(*(u8 **)(self + 0x70), 0x64, it)) {
    if (state != e[0]) continue;
    u8 *g = vcall<u8 *>(refTable(), 0x58, e[1]);
    if (!g) {
      vcall<u32>(*(u8 **)(self + 0x70), 0x44, it);
      continue;
    }
    if (name && ext_4cc850(nameOr(*(u32 *)(g + 4)), name)) continue;
    vcall<u32>(out, 4, e[1]);
  }
}
PCREG(46d810, templFindStateGeoms);

// 0x46d760 FindMainState(REFTAB*) (map): adds the geom ids whose "ItemState*" child (slot 0x100) says IsMain
// (slot 0x90); stale entries are removed.
static void THISCALL templFindMainState(u8 *self, u8 *out) {
  if (!*(u32 *)(self + 0x70)) return;
  u32 it[3];
  vcall<u32>(*(u8 **)(self + 0x70), 0x4c, it);
  for (u32 *e = vcall<u32 *>(*(u8 **)(self + 0x70), 0x64, it); e; e = vcall<u32 *>(*(u8 **)(self + 0x70), 0x64, it)) {
    u8 *g = vcall<u8 *>(refTable(), 0x58, e[1]);
    if (!g) {
      vcall<u32>(*(u8 **)(self + 0x70), 0x44, it);
      continue;
    }
    u8 *st = vcall<u8 *>(g, 0x100, 0x688854u);
    if (st && (u8)vcall<u32>(st, 0x90)) vcall<u32>(out, 4, e[1]);
  }
}
PCREG(46d760, templFindMainState);

// 0x46cb70 ZItemTemplateContainer::CopyData(const ZGEOM*) (map): template part (as ZItemTemplate::CopyData), then
// from another container template (0x1007d9) every allowed id of its list +0x7c is added (slot 4) to ours.
static void THISCALL templContCopyData(u8 *self, u8 *src) {
  ext_43f8c0(self, src);
  if (isA(src, 0x1007d3)) {
    *(u32 *)(self + 0x5c) = *(u32 *)(src + 0x5c);
    *(u32 *)(self + 0x60) = *(u32 *)(src + 0x60);
    *(u32 *)(self + 0x64) = *(u32 *)(src + 0x64);
    *(u32 *)(self + 0x68) = *(u32 *)(src + 0x68);
    *(u32 *)(self + 0x6c) = *(u32 *)(src + 0x6c);
    *(u32 *)(self + 0x78) = *(u32 *)(src + 0x78);
  }
  if (!isA(src, 0x1007d9) || !*(u32 *)(src + 0x7c)) return;
  u32 it[3];
  vcall<u32>(*(u8 **)(src + 0x7c), 0x4c, it);
  u32 x = vcall<u32>(*(u8 **)(src + 0x7c), 0x5c, it);
  while (it[0]) {
    vcall<u32>(*(u8 **)(self + 0x7c), 4, x);
    x = vcall<u32>(*(u8 **)(src + 0x7c), 0x5c, it);
  }
}
PCREG(46cb70, templContCopyData);

// ---------------------------------------------------------------- ZFFInventoryInfoList
// 0x5aee60 AddList(unsigned int) (map): for each child (+0x18 list: count slot 0x14, i-th id slot 0x30) of the group,
// its "InventoryBinding" child (slot 0x100) contributes its record (binding + 0x48) to the list, unique, max 20.
static void THISCALL infoAddList(u8 *self, u32 id) {
  u8 *g = vcall<u8 *>(refTable(), 0x58, id);
  s32 n = vcall<s32>(*(u8 **)(g + 0x18), 0x14);
  for (s32 i = 0; i < n; i++) {
    u8 *vt = *(u8 **)refTable();
    u32 x = vcall<u32>(*(u8 **)(g + 0x18), 0x30, (u32)i);
    u8 *o = (*(u8 *(THISCALL **)(u8 *, u32))(vt + 0x58))(refTable(), x);
    u8 *b = vcall<u8 *>(o, 0x100, 0x6b0f30u);
    if (!b) continue;
    u32 rec = (u32)(b + 0x48);
    u32 cnt = *(u32 *)self;
    if (cnt >= 0x14) continue;
    u32 *e = (u32 *)(self + 4);
    u32 k = 0;
    for (; k < cnt; k++)
      if (e[k] == rec) break;
    if (k < cnt) continue;
    e[cnt] = rec;
    ++*(u32 *)self;
  }
}
PCREG(5aee60, infoAddList);

// ---------------------------------------------------------------- actions
// 0x4861f0 ZActionPutItem::CallBack() (map): the hand item (+0xc slot 0x10) is put down: hand list update, hand
// slot 8(actor, 0), item slot 0x2d0(1, 0). No item: warning "ZActionPutItem::Callback pItem=0"
// (zlnkwhandsactions.cpp:0xb3, printer slot 0x30). Returns false.
static u32 THISCALL putCallBack(u8 *self) {
  u8 *it = vcall<u8 *>(*(u8 **)(self + 0xc), 0x10);
  vcall<u32>(refTable(), 0x4c, it);
  if (!it) {
    u8 *p = logger(0x68cdc4, 0xb3);
    u32 r = (*(u32 (**)(u8 *, u32))(*(u8 **)p + 0x30))(p, 0x68cdf8);
    return r & ~0xffu;
  }
  V4 v = {0, 0, 0, 0xffffffffu};
  ext_467410(*(u8 **)(self + 0xc) + 4, *(u32 *)(self + 8), 0, v);
  vcall<u32>(*(u8 **)(self + 0xc), 8, *(u32 *)(self + 8), 0u);
  u32 r = vcall<u32>(it, 0x2d0, 1u, 0u);
  return r & ~0xffu;
}
PCREG(4861f0, putCallBack);

// 0x4860b0 ZActionPickupItem::CallBack() (map): the item (+8) loses its rigid body ("QRigidBody", slot 0x144); hand
// list update with t = 0.3. A container-like item (IsA 0x1007d8) is opened (slot 0x2d0(1, 0)) and given to the actor
// (slot 0x2f0(actor id, 0, 1)); anything else goes into the hand (+0x10 slot 8(actor, item id)). Returns false.
static u32 THISCALL pickupCallBack(u8 *self) {
  vcall<u32>(*(u8 **)(self + 8), 0x144, 0x68ce24u);
  V4 v = {0, 0, 0, 0xffffffffu};
  ext_467410(*(u8 **)(self + 0x10) + 4, *(u32 *)(self + 0xc), 0x3e99999a, v);
  u32 r;
  if (isA(*(u8 **)(self + 8), 0x1007d8)) {
    vcall<u32>(*(u8 **)(self + 8), 0x2d0, 1u, 0u);
    u8 *vt = **(u8 ***)(self + 8);
    u32 id = vcall<u32>(refTable(), 0x4c, *(u32 *)(self + 0xc));
    r = (*(u32(THISCALL **)(u8 *, u32, u32, u32))(vt + 0x2f0))(*(u8 **)(self + 8), id, 0, 1);
  } else {
    u32 id = vcall<u32>(refTable(), 0x4c, *(u32 *)(self + 8));
    r = vcall<u32>(*(u8 **)(self + 0x10), 8, *(u32 *)(self + 0xc), id);
  }
  return r & ~0xffu;
}
PCREG(4860b0, pickupCallBack);

// ---------------------------------------------------------------- ZFFItemBomb
// 0x5d4660 ZFFItemBomb::Init() (map): with a target (+0x6b), spawns the bomb geom +0x48 from it (slot 0x1bc(world,
// identity matrix, zero pos, 0, 0, 0, 0)), control 0x2008000, init (0x2c), hidden (0xbc(0)), dynamic, auto room,
// colour 0xff0000 (0x234), 100.0 (0x23c) and 500.0 (0x240).
static void THISCALL bombInit(u8 *self) {
  if (!*(u32 *)(self + 0x6b)) return;
  float pos[3] = {0, 0, 0};
  float m[9];
  ext_4de7a0(m);
  u8 *g = vcall<u8 *>(*(u8 **)(self + 0x6b), 0x1bc, *(u32 *)(refTable() + 0xadc), m, pos, 0u, 0u, 0u, 0u);
  *(u8 **)(self + 0x48) = g;
  ext_4dc630(*(u8 **)(g + 8), 0x2008000, 0);
  vcall<u32>(*(u8 **)(self + 0x48), 0x2c);
  vcall<u32>(*(u8 **)(self + 0x48), 0xbc, 0u);
  ext_4dbe30(*(u8 **)(*(u8 **)(self + 0x48) + 8), 1);
  ext_4dc440(*(u8 **)(*(u8 **)(self + 0x48) + 8), 1);
  vcall<u32>(*(u8 **)(self + 0x48), 0x234, 0xff0000u);
  vcall<u32>(*(u8 **)(self + 0x48), 0x23c, 100.0f);
  vcall<u32>(*(u8 **)(self + 0x48), 0x240, 500.0f);
}
PCREG(5d4660, bombInit);

// ---------------------------------------------------------------- Item_If
// 0x50bf60 ZScriptItemInterface_t::DestroyItem(params) (map): result 0; the item (parameter 0) must exist
// ("Unable to locate item", item_if.cpp:0x107) and be a ZItem (":0x10d Object %s is not an item"); it is destroyed
// (slot 0x210(1)) and the result set to 1.
static void THISCALL scriptDestroyItem(u8 *, u8 *params) {
  ext_5002f0((u8 *)ext_5003d0(*(u8 **)(params + 8), 0), 0);
  u32 *p0 = (u32 *)ext_5003d0(*(u8 **)(params + 4), 0);
  u8 *o = vcall<u8 *>(refTable(), 0x58, *p0);
  if (!o) {
    logPrint2(logger(0x69d420, 0x107), 0x69d5dc);
    return;
  }
  if (!isA(o, 0x1007d1)) {
    u8 *p = logger(0x69d420, 0x10d);
    logPrint3(p, 0x69d5fc, *(u32 *)(o + 4));
    return;
  }
  vcall<u32>(o, 0x210, 1u);
  ext_5002f0((u8 *)ext_5003d0(*(u8 **)(params + 8), 0), 1);
}
PCREG(50bf60, scriptDestroyItem);

// ---------------------------------------------------------------- CInventory
// 0x4acd10 CInventory::Load2() (map): walks the owner's (+0x44 -> +0x10 -> +8) child list; each child event (event
// manager 0x70038c slot 0xcc) named "Action" (slot 0x14, striwcmp) whose key (+0x106) is in the REFTAB +0x11a
// (slot 0x28) is added to the action REFTAB +0x1c6 (slot 4, ConvPtr).
static void THISCALL inventoryLoad2(u8 *self) {
  u8 *l = *(u8 **)(*(u8 **)(*(u8 **)(self + 0x44) + 0x10) + 8);
  if (!l) return;
  u32 it[4];
  vcall<u32>(l, 0x4c, it);
  u32 x = vcall<u32>(*(u8 **)(*(u8 **)(*(u8 **)(self + 0x44) + 0x10) + 8), 0x5c, it);
  while (it[0]) {
    u8 *o = vcall<u8 *>(G(u8 *, 0x70038c), 0xcc, x);
    if (vcall<u32>(o, 0x14) && !ext_4cc850(vcall<u32>(o, 0x14), 0x67a110) &&
        vcall<u32>(self + 0x11a, 0x28, *(u32 *)(o + 0x106))) {
      u8 *vt = *(u8 **)(self + 0x1c6);
      u32 p = ext_41e680(o);
      (*(u32(THISCALL **)(u8 *, u32))(vt + 4))(self + 0x1c6, p);
    }
    x = vcall<u32>(*(u8 **)(*(u8 **)(*(u8 **)(self + 0x44) + 0x10) + 8), 0x5c, it);
  }
}
PCREG(4acd10, inventoryLoad2);
