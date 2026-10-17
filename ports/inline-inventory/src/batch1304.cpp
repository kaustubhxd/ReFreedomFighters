// batch1304.cpp - inventory thread (inline-inventory, 2026-10-11): event-object ctors/dtors (ZItemState,
// ZItemSpawn, CInventory, ZFFInventorySelector), ZItemTemplateContainer, ZItem::AddActivate/Clear/Load/Save,
// ZItemTemplate::CopyDataBlock/CreateItem/SetStateGeometry, ZItemButton::ClassCommand, the get/drop/put item action
// callbacks and the Item_If validity checks.
// The SEH frames (fs:[0]) and /GS cookies of the originals are not reproduced: they have no effect unless an
// exception unwinds or the stack is smashed.
#include "ff.h"

extern "C" u32 THISCALL ext_4cbee0(u8 *dst, u8 *src);                // MYSTR::operator=(const MYSTR&)
extern "C" u32 THISCALL ext_4cbec0(u8 *s);                           // MYSTR::~MYSTR()
extern "C" u32 THISCALL ext_4cbeb0(u8 *s);                           // MYSTR::MYSTR()
extern "C" u32 THISCALL ext_469870(u8 *self);                        // ZEventBase ctor (unnamed)
extern "C" u32 THISCALL ext_4ccf60(u8 *t);                           // REFTAB32::~REFTAB32()
extern "C" u32 THISCALL ext_43ea20(u8 *self);                        // ZGROUP body dtor
extern "C" void ext_45c510(void *p);                                 // ZGEOM::operator delete(void*)
extern "C" void ext_4690b0(void *p, u32 size);                       // empty placement delete
extern "C" u32 THISCALL ext_43f900(u8 *self, u8 *blk);               // ZGROUP::CopyDataBlock(DBLK*)
extern "C" u32 THISCALL ext_4e11e0(u8 *blk, void *dst, int n);       // DBLK::Get(int*, int)
extern "C" u32 THISCALL ext_4e12e0(u8 *blk, void *dst, int n);       // DBLK::Get(unsigned int*, int)
extern "C" u32 THISCALL ext_4e1600(u8 *blk);                         // DBLK::GetType()
extern "C" u32 THISCALL ext_4e1b30(u8 *blk);                         // DBLK::NextBlock()
extern "C" u32 THISCALL ext_4dc630(u8 *geom, u32 a, u32 b);          // ZBaseGeom::SetControl(unsigned int, unsigned int)
extern "C" u32 THISCALL ext_440e10(u8 *self, u8 *g);                 // ZGROUP::Load(ZLoadGame*)
extern "C" u32 THISCALL ext_441790(u8 *self, u8 *g);                 // ZGROUP::Save(ZSaveGame*)
extern "C" u32 THISCALL ext_41e680(u8 *self);                        // ConvPtr(void*)
extern "C" u32 THISCALL ext_46b800(u8 *self, u32 cmd, void *data);   // ZItem::ClassCommand(unsigned short, void*)
extern "C" u32 THISCALL ext_4d9430(u8 *s);                           // (child item detach, unnamed)
extern "C" void ext_4d9590(u8 *s);                                   // (child item free, cdecl, unnamed)
struct V4 { u32 a, b, c, d; };
extern "C" u32 THISCALL ext_467410(u8 *self, u32 obj, u32 z, V4 v);  // (hand attach list update, unnamed)
extern "C" u32 THISCALL ext_461570(u8 *anim, float t, u32 cb, u32 data);  // ZBoneAnim::AddCallBackAlways
extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 i);                 // opaque call parameter i
extern "C" u32 THISCALL ext_561020(u8 *self);                        // CBaseWindow::CBaseWindow()
extern "C" u32 THISCALL ext_5aede0(u8 *self);                        // ZFFInventoryInfoList::ZFFInventoryInfoList()
extern "C" u32 THISCALL ext_65e090(u8 *self);                        // ZFFInventoryBridge::ZFFInventoryBridge()

static inline u8 *refTable() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
static inline u8 isA(u8 *g, u32 type) { return (u8)vcall<u32>(g, 0x1e0, type); }
static inline void logMsg2(u32 file, u32 line, u32 msg) {
  u8 *p = vcall<u8 *>(G(u8 *, 0x700390), 0x20, file, line);
  (*(void (**)(u8 *, u32))(*(u8 **)p + 0x2c))(p, msg);
}
static inline void logMsg3(u32 file, u32 line, u32 msg, u32 a) {
  u8 *p = vcall<u8 *>(G(u8 *, 0x700390), 0x20, file, line);
  (*(void (**)(u8 *, u32, u32))(*(u8 **)p + 0x2c))(p, msg, a);
}
// Message ids are registered by name through ref table slot 0x114(name, 0, file, line) (low word kept).
static inline u16 msgId(u32 name, u32 line) { return (u16)vcall<u32>(refTable(), 0x114, name, 0u, 0x6887c4u, line); }

// ---------------------------------------------------------------- ZEventBase destructor tail
// The inlined ~ZEventBase: +0x44 = +0x30 = 0, vtable 0x686874, unregister from the ref table (slot 0x34). A plain
// `delete` of an event object (flag 1 without 4) calls the exception hook at 0x7003b0 (int3 when unset): events
// are not freed with operator delete. Flag 4 (placement form) calls the empty operator delete with the size.
static inline u8 *eventBaseDtor(u8 *self, u32 flags, u32 size) {
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
    ext_4690b0(self, size);
  }
  return self;
}

// 0x468cb0 ZItemState::~ZItemState() (low; ICF with Cartridge/Projectile states): anim name MYSTR +0x61, size 0xe6.
static u8 *THISCALL itemStateDtor(u8 *self, u32 flags) {
  ext_4cbec0(self + 0x61);
  return eventBaseDtor(self, flags, 0xe6);
}
PCREG(468cb0, itemStateDtor);

// 0x46a870 ZItemSpawn::~ZItemSpawn() (map): forgets the spawned item +0x5a; size 0x5e.
static u8 *THISCALL itemSpawnDtor(u8 *self, u32 flags) {
  *(u32 *)(self + 0x5a) = 0;
  return eventBaseDtor(self, flags, 0x5e);
}
PCREG(46a870, itemSpawnDtor);

// 0x49e2e0 CInventory::~CInventory() (map): three REFTAB32 members (+0x1c6, +0x11a, +0x6e); size 0x272.
static u8 *THISCALL inventoryDtor(u8 *self, u32 flags) {
  ext_4ccf60(self + 0x1c6);
  ext_4ccf60(self + 0x11a);
  ext_4ccf60(self + 0x6e);
  return eventBaseDtor(self, flags, 0x272);
}
PCREG(49e2e0, inventoryDtor);

// 0x567820 ZFFInventorySelector::~ZFFInventorySelector() (map): size 0x42e.
static u8 *THISCALL selectorDtor(u8 *self, u32 flags) { return eventBaseDtor(self, flags, 0x42e); }
PCREG(567820, selectorDtor);

// ---------------------------------------------------------------- constructors
// 0x469c00 ZItemSpawn::ZItemSpawn() (map): event base, flag 0x20, vtable 0x6886d4; message ids
// MSG_REMOVEITEMFROMINVENTORY (+0x48, zitem.cpp:0x10ae) and Msg_ForceSpawn (+0x4a, :0x10af); state zeroed.
static u8 *THISCALL itemSpawnCtor(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6886d4;
  *(u16 *)(self + 0x48) = msgId(0x688968, 0x10ae);
  *(u16 *)(self + 0x4a) = msgId(0x689050, 0x10af);
  *(u32 *)(self + 0x52) = 0;
  *(u32 *)(self + 0x56) = 0;
  *(u32 *)(self + 0x5a) = 0;
  return self;
}
PCREG(469c00, itemSpawnCtor);

// 0x469cc0 ZItemState::ZItemState() (map): event base, flag 0x20, vtable 0x688638, MYSTR +0x61; message ids
// MSG_ITEMSETSTATE +0x4a, MSG_ITEMGETANIMNAME +0x4c, MSG_ITEMSTATECREATE +0x48 (zitem.cpp:0xf62..0xf64).
static u8 *THISCALL itemStateCtor(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x688638;
  ext_4cbeb0(self + 0x61);
  *(u16 *)(self + 0x4a) = msgId(0x6887ec, 0xf62);
  *(u16 *)(self + 0x4c) = msgId(0x688800, 0xf63);
  *(u16 *)(self + 0x48) = msgId(0x688eac, 0xf64);
  return self;
}
PCREG(469cc0, itemStateCtor);

// 0x567720 ZFFInventorySelector::ZFFInventorySelector() (high): CBaseWindow base, vtable 0x6a70dc, three info lists
// (+0x180, +0x1d4, +0x228), a bridge (+0x27c); 8 dwords +0x3ee..+0x426 (stride 8) and 17 records of 12 bytes at
// +0x322 zeroed; byte +0x321 = 0, +0x290 = 1.
static u8 *THISCALL selectorCtor(u8 *self) {
  ext_561020(self);
  *(u32 *)self = 0x6a70dc;
  ext_5aede0(self + 0x180);
  ext_5aede0(self + 0x1d4);
  ext_5aede0(self + 0x228);
  ext_65e090(self + 0x27c);
  for (u32 o = 0x3ee; o <= 0x426; o += 8) *(u32 *)(self + o) = 0;
  u8 *p = self + 0x322;
  for (int i = 0; i < 0x11; i++, p += 0xc) {
    *(u32 *)(p + 4) = 0;
    *(u32 *)p = 0;
    *(u32 *)(p + 8) = 0;
  }
  self[0x321] = 0;
  self[0x290] = 1;
  return self;
}
PCREG(567720, selectorCtor);

// 0x46aa00 ZItemTemplateContainer::~ZItemTemplateContainer() (map): vtable 0x687fe4, deletes the REFTAB +0x7c, then
// the template part (vtable 0x6868e8, states +0x70), ZGROUP body; size 0x80.
static u8 *THISCALL templContDtor(u8 *self, u32 flags) {
  u8 *a = *(u8 **)(self + 0x7c);
  *(u32 *)self = 0x687fe4;
  if (a) vcall<u32>(a, 0, 1u);
  u8 *b = *(u8 **)(self + 0x70);
  *(u32 *)self = 0x6868e8;
  if (b) vcall<u32>(b, 0, 1u);
  ext_43ea20(self);
  if (flags & 1) {
    if (!(flags & 4)) {
      ext_45c510(self);
      return self;
    }
    ext_4690b0(self, 0x80);
  }
  return self;
}
PCREG(46aa00, templContDtor);

// ---------------------------------------------------------------- ZItem
// 0x46ab30 ZItem::AddActivate(ZItemState*, float) (map): own slot 0x110(0x10, 0); the state's reference id (0 for
// none or when the event manager 0x70038c says it is not registered, slot 0x20); id comes from the manager's fast
// lookup (+8 function for states inside [+0xc, +0x10)) or the dword before the object (registered on demand,
// slot 0xac). Then controller +0x78 slot 0x98(id, delay, 0).
static void THISCALL itemAddActivate(u8 *self, u8 *st, u32 delay) {
  vcall<u32>(self, 0x110, 0x10u, 0u);
  u32 id;
  if (!st || vcall<u32>(G(u8 *, 0x70038c), 0x20, st)) {
    id = 0;
  } else {
    u8 *m = G(u8 *, 0x70038c);
    u32 fn = *(u32 *)(m + 8);
    if (fn && *(u32 *)(m + 0xc) <= (u32)st && (u32)st < *(u32 *)(m + 0x10)) {
      id = ((u32(THISCALL *)(u8 *))fn)(st);
    } else {
      if (!*(u32 *)(st - 4)) vcall<u32>(m, 0xac, st);
      id = *(u32 *)(st - 4);
    }
  }
  vcall<u32>(*(u8 **)(self + 0x78), 0x98, id, delay, 0u);
}
PCREG(46ab30, itemAddActivate);

// 0x46c8a0 ZItem::Clear(const char*) (map): frees all child items (+0x50 head, detach 0x4d9430 + free 0x4d9590);
// with a name, creates a "NewObject" child of that name (slot 0x294(..., name, 0, 1)) and returns the new head.
static u32 THISCALL itemClear(u8 *self, u32 name) {
  u8 *s = *(u8 **)(self + 0x50);
  while (s) {
    ext_4d9430(s);
    ext_4d9590(s);
    s = *(u8 **)(self + 0x50);
  }
  if (!name) return 0;
  vcall<u32>(self, 0x294, 0x688a24u, name, 0u, 1u);
  return *(u32 *)(self + 0x50);
}
PCREG(46c8a0, itemClear);

// 0x46f520 ZItem::Load(ZLoadGame*) (map): ZGROUP part; chained reads (slot 0x40 returns the stream) of +0x5c (via
// the argument slot), +0x60, +0x64, +0x68; then lists +0x6c, +0x70 (slot 0x70) and +0x78, +0x74 (slot 0x7c).
static u8 THISCALL itemLoad(u8 *self, u8 *g) {
  ext_440e10(self, g);
  u32 slot = (u32)g;
  u8 *s = vcall<u8 *>(g, 0x40, &slot);
  s = vcall<u8 *>(s, 0x40, self + 0x60);
  s = vcall<u8 *>(s, 0x40, self + 0x64);
  vcall<u32>(s, 0x40, self + 0x68);
  u32 a = *(u32 *)(self + 0x6c);
  *(u32 *)(self + 0x5c) = slot;
  s = vcall<u8 *>(g, 0x70, a);
  vcall<u32>(s, 0x70, *(u32 *)(self + 0x70));
  s = vcall<u8 *>(g, 0x7c, *(u32 *)(self + 0x78));
  vcall<u32>(s, 0x7c, *(u32 *)(self + 0x74));
  return 1;
}
PCREG(46f520, itemLoad);

// 0x4705a0 ZItem::Save(ZSaveGame*) (map): mirror of Load with slots 0x3c, 0x6c, 0x78.
static u8 THISCALL itemSave(u8 *self, u8 *g) {
  ext_441790(self, g);
  u8 *s = vcall<u8 *>(g, 0x3c, *(u32 *)(self + 0x5c));
  s = vcall<u8 *>(s, 0x3c, *(u32 *)(self + 0x60));
  s = vcall<u8 *>(s, 0x3c, *(u32 *)(self + 0x64));
  vcall<u32>(s, 0x3c, *(u32 *)(self + 0x68));
  s = vcall<u8 *>(g, 0x6c, *(u32 *)(self + 0x6c));
  vcall<u32>(s, 0x6c, *(u32 *)(self + 0x70));
  s = vcall<u8 *>(g, 0x78, *(u32 *)(self + 0x78));
  vcall<u32>(s, 0x78, *(u32 *)(self + 0x74));
  return 1;
}
PCREG(4705a0, itemSave);

// ---------------------------------------------------------------- ZItemState
// 0x468420 ZItemState::CopyData(ZEventBase*) (map): copies +0x4e..+0x60, the anim name, +0xe1 (use geom id), +0xe5;
// if the owner (+0x44 slot 0x20) is a ZItemTemplate, registers this state with it (slot 0x2dc(owner, +0x4e)),
// else own slot 0x58.
static u32 THISCALL itemStateCopyData(u8 *self, u8 *src) {
  *(u32 *)(self + 0x4e) = *(u32 *)(src + 0x4e);
  self[0x52] = src[0x52];
  *(u32 *)(self + 0x53) = *(u32 *)(src + 0x53);
  *(u32 *)(self + 0x57) = *(u32 *)(src + 0x57);
  *(u32 *)(self + 0x5b) = *(u32 *)(src + 0x5b);
  self[0x5f] = src[0x5f];
  self[0x60] = src[0x60];
  ext_4cbee0(self + 0x61, src + 0x61);
  u8 *own = *(u8 **)(self + 0x44);
  *(u32 *)(self + 0xe1) = *(u32 *)(src + 0xe1);
  self[0xe5] = src[0xe5];
  if (isA(vcall<u8 *>(own, 0x20), 0x1007d3)) {
    u8 *t = vcall<u8 *>(*(u8 **)(self + 0x44), 0x20);
    return vcall<u32>(t, 0x2dc, *(u32 *)(self + 0x44), *(u32 *)(self + 0x4e));
  }
  return vcall<u32>(self, 0x58);
}
PCREG(468420, itemStateCopyData);

// ---------------------------------------------------------------- ZItemTemplate
// 0x46cee0 ZItemTemplate::CopyDataBlock(DBLK*) (high): ZGROUP part; ints +0x5c, +0x60; uints +0x64, +0x68, +0x6c;
// the material +0x78 only if the next field's type is 0xb (newer data).
static u32 THISCALL templCopyDataBlock(u8 *self, u8 *blk) {
  ext_43f900(self, blk);
  ext_4e11e0(blk, self + 0x5c, 1);
  ext_4e11e0(blk, self + 0x60, 1);
  ext_4e12e0(blk, self + 0x64, 1);
  ext_4e12e0(blk, self + 0x68, 1);
  ext_4e12e0(blk, self + 0x6c, 1);
  if ((u8)ext_4e1600(blk) == 0xb) ext_4e12e0(blk, self + 0x78, 1);
  return ext_4e1b30(blk);
}
PCREG(46cee0, templCopyDataBlock);

// 0x46d530 ZItemTemplate::CreateItem(ZGROUP*, unsigned int) (map): the item class (slot 0x2c8) -> class info (ref
// table slot 0x154); parent slot 0x298(name or "<NONAME>", arg, class type id (+0x23), 0, 1) creates the item; it
// gets the template's reference id (slot 0x2e4), init (0x154), control flag 0x800000 set, then 0x158.
static u32 THISCALL templCreateItem(u8 *self, u8 *parent, u32 arg) {
  u32 cls = vcall<u32>(self, 0x2c8);
  u8 *info = vcall<u8 *>(refTable(), 0x154, cls, 0u);
  u32 type = *(u32 *)(info + 0x23);
  u32 nm = *(u32 *)(self + 4);
  u8 *it = vcall<u8 *>(parent, 0x298, nm ? nm : 0x67c8e8u, arg, type, 0u, 1u);
  if (!it) return 0;
  u8 *vt = *(u8 **)it;
  u32 id = vcall<u32>(refTable(), 0x4c, self);
  (*(u32(THISCALL **)(u8 *, u32))(vt + 0x2e4))(it, id);
  vcall<u32>(it, 0x154);
  ext_4dc630(*(u8 **)(it + 8), 0x800000, 0);
  vcall<u32>(it, 0x158);
  return (u32)it;
}
PCREG(46d530, templCreateItem);

// 0x4714d0 ZItemTemplate::SetStateGeometry(ZItem*, ZGEOM*) (map): temporarily sets control flag 0x800000 on the geom
// while its "ItemState*" child (slot 0x100) gets slot 0x5c(0x20, item, state message +0x74), then restores the bit.
static void THISCALL templSetStateGeometry(u8 *self, u32 item, u8 *g) {
  u8 *st = vcall<u8 *>(g, 0x100, 0x688854u);
  u8 *bg = *(u8 **)(g + 8);
  u32 saved = *(u32 *)(bg + 0x3c) & 0x800000;
  ext_4dc630(bg, 0x800000, 0);
  if (st) vcall<u32>(st, 0x5c, 0x20u, item, (u32) * (u16 *)(self + 0x74));
  ext_4dc630(*(u8 **)(g + 8), saved, 0x800000);
}
PCREG(4714d0, templSetStateGeometry);

// 0x46b650 ZItemTemplateContainer::CanContainItem(const ZItem*) const (map): an empty allow-list (+0x7c, slot 0x14)
// accepts everything; else the item's template id must be in the list (iterate: slot 0x4c begin, slot 0x5c next
// with a 12-byte cursor whose first dword is 0 at the end).
static u8 THISCALL templContCanContain(u8 *self, u8 *item) {
  if (!vcall<u32>(*(u8 **)(self + 0x7c), 0x14)) return 1;
  u32 t = vcall<u32>(item, 0x2e8);
  u32 id = vcall<u32>(refTable(), 0x4c, t);
  u8 *l = *(u8 **)(self + 0x7c);
  if (!l) return 0;
  u32 it[3];
  vcall<u32>(l, 0x4c, it);
  u32 x = vcall<u32>(*(u8 **)(self + 0x7c), 0x5c, it);
  while (it[0]) {
    if (x == id) return 1;
    x = vcall<u32>(*(u8 **)(self + 0x7c), 0x5c, it);
  }
  return 0;
}
PCREG(46b650, templContCanContain);

// ---------------------------------------------------------------- ZItemButton
// 0x46b9d0 ZItemButton::ClassCommand(unsigned short, void*) (map): with a template (+0x60): command +0x7c asks the
// CCom (slot 0x88) for "lState" into the argument slot; state 3 with a target (+0x8e) sends message +0x92 to it
// (slot 0x12c(target, msg, ConvPtr(this))). Command +0x92 presses the button (slot 0x2d0(0, 0)) and returns.
// Everything else goes to ZItem::ClassCommand. Returns 0.
static u32 THISCALL buttonClassCommand(u8 *self, u32 cmd, u8 *data) {
  if (*(u32 *)(self + 0x60)) {
    if ((u16)cmd == *(u16 *)(self + 0x7c)) {
      u32 slot = cmd;
      vcall<u32>(data, 0x88, 0x68884cu, &slot);
      if (slot == 3 && *(u32 *)(self + 0x8e)) {
        u8 *vt = *(u8 **)self;
        u32 p = ext_41e680(self);
        (*(u32(THISCALL **)(u8 *, u32, u32, u32))(vt + 0x12c))(self, *(u32 *)(self + 0x8e),
                                                                (u32) * (u16 *)(self + 0x92), p);
      }
    } else if ((u16)cmd == *(u16 *)(self + 0x92)) {
      vcall<u32>(self, 0x2d0, 0u, 0u);
      return 0;
    }
  }
  ext_46b800(self, cmd, data);
  return 0;
}
PCREG(46b9d0, buttonClassCommand);

// ---------------------------------------------------------------- item actions
// 0x485f90 ZActionDropItem::CallBack() (map): at the animation event: hand (+0xc) releases its item (slot 0x10),
// hand list update (0x467410 on hand+4 with the actor and a {0,0,0,-1} record), hand slot 8(actor, 0), item slot
// 0x2d0(0, 0) (drop to world), actor slot 0x4f4(item). Returns false (only AL defined).
static u32 THISCALL dropCallBack(u8 *self) {
  u8 *it = vcall<u8 *>(*(u8 **)(self + 0xc), 0x10);
  V4 v = {0, 0, 0, 0xffffffffu};
  ext_467410(*(u8 **)(self + 0xc) + 4, *(u32 *)(self + 8), 0, v);
  vcall<u32>(*(u8 **)(self + 0xc), 8, *(u32 *)(self + 8), 0u);
  vcall<u32>(it, 0x2d0, 0u, 0u);
  u32 r = vcall<u32>(*(u8 **)(self + 8), 0x4f4, it);
  return r & ~0xffu;
}
PCREG(485f90, dropCallBack);

// 0x486020 ZActionGetItem::CallBack() (map): the item (+8) is put into the hand (+0x10): hand list update with the
// actor (+0xc), hand slot 8(actor, item id), item slot 0x2d0(2, 0) then 0x2d0(0, 0). Returns false.
static u32 THISCALL getCallBack(u8 *self) {
  u32 id = vcall<u32>(refTable(), 0x4c, *(u32 *)(self + 8));
  V4 v = {0, 0, 0, 0xffffffffu};
  ext_467410(*(u8 **)(self + 0x10) + 4, *(u32 *)(self + 0xc), 0, v);
  vcall<u32>(*(u8 **)(self + 0x10), 8, *(u32 *)(self + 0xc), id);
  vcall<u32>(*(u8 **)(self + 8), 0x2d0, 2u, 0u);
  u32 r = vcall<u32>(*(u8 **)(self + 8), 0x2d0, 0u, 0u);
  return r & ~0xffu;
}
PCREG(486020, getCallBack);

// 0x486890 ZActionPutItem::Execute() (map): the hand item's template (slot 0x2e8) decides the target: a container
// template (IsA 0x1007d4) puts into +0x14, else +0x10. With a target the actor (+8) plays slot 0x230(target, 1) and
// the callback 0x465710 is added (always) at t=12.5; returns true. Without one: own slot 0xc.
static u32 THISCALL putExecute(u8 *self) {
  u8 *it = vcall<u8 *>(*(u8 **)(self + 0xc), 0x10);
  u8 *t = vcall<u8 *>(it, 0x2e8);
  u32 target = isA(t, 0x1007d4) ? *(u32 *)(self + 0x14) : *(u32 *)(self + 0x10);
  if (target) {
    u8 *anim = vcall<u8 *>(*(u8 **)(self + 8), 0x230, target, 1u);
    u32 r = ext_461570(anim, 12.5f, 0x465710, 0);
    return (r & ~0xffu) | 1;
  }
  return vcall<u32>(self, 0xc);
}
PCREG(486890, putExecute);

// ---------------------------------------------------------------- Item_If
// 0x50c200 ZScriptItemInterface_t::EnablePickup(params) (map): parameter 0 = item id, parameter 1 = on/off; non-items
// log "ERROR: DisablePickup script command is called with reference to non-item geom" (item_if.cpp:0x4b8).
static void THISCALL scriptEnablePickup(u8 *, u8 *params) {
  u32 *p0 = (u32 *)ext_5003d0(*(u8 **)(params + 4), 0);
  u8 *it = vcall<u8 *>(refTable(), 0x58, *p0);
  if (it && isA(it, 0x1007d1)) {
    u32 *p1 = (u32 *)ext_5003d0(*(u8 **)(params + 4), 1);
    u8 *vt = *(u8 **)it;
    (*(u32(THISCALL **)(u8 *, u32))(vt + 0x300))(it, *p1 != 0);
    return;
  }
  logMsg2(0x69d420, 0x4b8, 0x69da80);
}
PCREG(50c200, scriptEnablePickup);

// 0x50c7e0 GetValidIKLnkObj(id) / 0x50c870 GetValidItem(id) (map): resolve the id; warn when missing or of the wrong
// class (ZLNKWHANDS 0x200073 / ZItem 0x1007d1); return the object or 0.
static u32 THISCALL scriptValidIK(u8 *, u32 id) {
  u8 *o = vcall<u8 *>(refTable(), 0x58, id);
  if (!o) {
    logMsg2(0x69d420, 0xbc, 0x69d4f0);
    return 0;
  }
  if (!isA(o, 0x200073)) {
    logMsg3(0x69d420, 0xc1, 0x69d510, *(u32 *)(o + 4));
    return 0;
  }
  return (u32)o;
}
PCREG(50c7e0, scriptValidIK);
static u32 THISCALL scriptValidItem(u8 *, u32 id) {
  u8 *o = vcall<u8 *>(refTable(), 0x58, id);
  if (!o) {
    logMsg2(0x69d420, 0xa4, 0x69d450);
    return 0;
  }
  if (!isA(o, 0x1007d1)) {
    logMsg3(0x69d420, 0xa9, 0x69d4a0, *(u32 *)(o + 4));
    return 0;
  }
  return (u32)o;
}
PCREG(50c870, scriptValidItem);
