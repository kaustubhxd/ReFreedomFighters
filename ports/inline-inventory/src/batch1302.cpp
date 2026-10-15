// batch1302.cpp - inventory thread (inline-inventory, 2026-10-11): item destructors, CopyData/CopyDataBlock,
// ZItemSpawn load/save/command, ZItem::EnablePickup, ZActionDropItem::Execute and ZScriptItemInterface_t calls.
#include "ff.h"

extern "C" u32 THISCALL ext_4cc5f0(u8 *str);                         // MYSTR::Length() const
extern "C" u32 THISCALL ext_4cc1d0(u8 *str);                         // MYSTR c_str (unnamed)
extern "C" u32 THISCALL ext_46a4f0(u8 *self);                        // ZItem::~ZItem() (body)
extern "C" u32 THISCALL ext_43ea20(u8 *self);                        // ZGROUP::~ZGROUP() (body, unnamed in map)
extern "C" void ext_45c510(void *p);                                 // ZGEOM::operator delete(void*) (cdecl)
extern "C" void ext_4690b0(void *p, u32 size);                       // empty placement delete (cdecl, ICF 'ret')
extern "C" u32 THISCALL ext_43f8c0(u8 *self, u8 *src);               // ZGROUP::CopyData(const ZGEOM*)
extern "C" u32 THISCALL ext_43f900(u8 *self, u8 *blk);               // ZGROUP::CopyDataBlock(DBLK*)
extern "C" u32 THISCALL ext_4e12e0(u8 *blk, void *dst, int n);       // DBLK::Get(unsigned int*, int)
extern "C" u32 THISCALL ext_4e11d0(u8 *blk, void *dst, int n);       // DBLK::Get(unsigned short*, int)
extern "C" u32 THISCALL ext_4e0fd0(u8 *blk, u32 reftab);             // DBLK::Get(REFTAB*)
extern "C" u32 THISCALL ext_4e1b30(u8 *blk);                         // DBLK::NextBlock()
extern "C" float THISCALL ext_4e5e80(void *rd);                      // DBREAD::operator float()
extern "C" u32 THISCALL ext_4e5e60(void *rd);                        // DBREAD::operator unsigned int()
extern "C" u32 THISCALL ext_470550(u8 *self, u32 id);                // (ZFFGameData 0x7003b8: remove spawned item)
extern "C" u32 THISCALL ext_471680(u8 *self);                        // ZItemSpawn::SpawnItem()
extern "C" u32 THISCALL ext_4614d0(u8 *anim, float t, u32 cb, u32 data);  // ZBoneAnim::AddCallBack
extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 i);                 // opaque call parameter i (pointer to value)

static inline u8 *refTable() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
static inline u8 isA(u8 *g, u32 type) { return (u8)vcall<u32>(g, 0x1e0, type); }  // ZGEOM slot 0x1e0 = IsA(type id)

// ---------------------------------------------------------------- deleting destructors
// MSVC scalar deleting destructor pattern: flag bit 0 = free, bit 2 = placement form (calls the empty operator
// delete with the size). ZGEOM-derived objects free through ZGEOM::operator delete.
static inline u8 *geomDelete(u8 *self, u32 flags, u32 size) {
  if (flags & 1) {
    if (!(flags & 4)) {
      ext_45c510(self);
      return self;
    }
    ext_4690b0(self, size);
  }
  return self;
}

// 0x46a7c0 ZItemButton::~ZItemButton() (high): vtable 0x687648, ZItem body, size 0x94.
static u8 *THISCALL itemButtonDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x687648;
  ext_46a4f0(self);
  return geomDelete(self, flags, 0x94);
}
PCREG(46a7c0, itemButtonDtor);

// 0x46a810 ZItemContainer::~ZItemContainer() (map): vtable 0x688308; deletes the contained-items list (+0x94,
// slot 0 with flag 1); ZItem body; size 0x98.
static u8 *THISCALL containerDtor(u8 *self, u32 flags) {
  u8 *l = *(u8 **)(self + 0x94);
  *(u32 *)self = 0x688308;
  if (l) vcall<u32>(l, 0, 1u);
  ext_46a4f0(self);
  return geomDelete(self, flags, 0x98);
}
PCREG(46a810, containerDtor);

// 0x46a940 ZItemTemplate::~ZItemTemplate() (map): vtable 0x6868e8; deletes the state list (+0x70); ZGROUP body;
// size 0x7c.
static u8 *THISCALL templDtor(u8 *self, u32 flags) {
  u8 *l = *(u8 **)(self + 0x70);
  *(u32 *)self = 0x6868e8;
  if (l) vcall<u32>(l, 0, 1u);
  ext_43ea20(self);
  return geomDelete(self, flags, 0x7c);
}
PCREG(46a940, templDtor);

// ---------------------------------------------------------------- ZItemState / ZItem / ZItemTemplate
// 0x4689e0 ZItemState::GetItemSettings(CCom*) (map): if the anim name (MYSTR at +0x61) is not empty, set the
// "strAnimName" setting on the CCom (slot 0x20). The CCom vtable is read before the c_str call.
static u32 THISCALL stateGetItemSettings(u8 *self, u8 *com) {
  u8 *s = self + 0x61;
  u32 n = ext_4cc5f0(s);
  if (!n) return n;
  u8 *vt = *(u8 **)com;
  u32 p = ext_4cc1d0(s);
  return (*(u32(THISCALL **)(u8 *, u32, u32))(vt + 0x20))(com, 0x685918, p);
}
PCREG(4689e0, stateGetItemSettings);

// 0x46baa0 ZItem::ClassFrameUpdate() (low, ICF with ZItemContainer): if neither controller (+0x74, +0x78) is busy
// (slot 0x14), clear flag 0x10 (own slot 0x114); then own slots 0x31c and 0x318 (tail).
static u32 THISCALL itemClassFrameUpdate(u8 *self) {
  if (!vcall<u32>(*(u8 **)(self + 0x74), 0x14) && !vcall<u32>(*(u8 **)(self + 0x78), 0x14))
    vcall<u32>(self, 0x114, 0x10u);
  vcall<u32>(self, 0x31c);
  return vcall<u32>(self, 0x318);
}
PCREG(46baa0, itemClassFrameUpdate);

// 0x46c7d0 ZItemTemplate::ClassInit() (map): templates must be INACTIVE (flag 0x400 in class info +8 -> +0x3c);
// otherwise logs "Error: %s Item template not marked INACTIVE in editor!" (zitem.cpp line 0x1b6, name or
// "<NONAME>") and deactivates itself (slot 0x210(1)).
static void THISCALL templClassInit(u8 *self) {
  if (*(u32 *)(*(u8 **)(self + 8) + 0x3c) & 0x400) return;
  u8 *log = vcall<u8 *>(G(u8 *, 0x700390), 0x20, 0x6887c4u, 0x1b6u);
  u32 nm = *(u32 *)(self + 4);
  u32 name = nm ? nm : 0x67c8e8;
  (*(void (**)(u8 *, u32, u32))(*(u8 **)log + 0x2c))(log, 0x688814, name);
  vcall<u32>(self, 0x210, 1u);
}
PCREG(46c7d0, templClassInit);

// 0x46c970 ZItem::CopyData(const ZGEOM*) (map): base copy; if the source is a ZItem (type 0x1007d1) copy +0x60, +0x64.
static void THISCALL itemCopyData(u8 *self, u8 *src) {
  ext_43f8c0(self, src);
  if (isA(src, 0x1007d1)) {
    *(u32 *)(self + 0x60) = *(u32 *)(src + 0x60);
    *(u32 *)(self + 0x64) = *(u32 *)(src + 0x64);
  }
}
PCREG(46c970, itemCopyData);

// 0x46ca10 ZItemContainer::CopyData(const ZGEOM*) (high): ZItem::CopyData inlined, then an IsA(0x1007da) whose
// result is unused (the container part copies nothing).
static u32 THISCALL containerCopyData(u8 *self, u8 *src) {
  ext_43f8c0(self, src);
  if (isA(src, 0x1007d1)) {
    *(u32 *)(self + 0x60) = *(u32 *)(src + 0x60);
    *(u32 *)(self + 0x64) = *(u32 *)(src + 0x64);
  }
  return vcall<u32>(src, 0x1e0, 0x1007dau);
}
PCREG(46ca10, containerCopyData);

// 0x46ca60 ZItemSpawn::CopyData(const ZGEOM*) (map): no base call; from another ZItemSpawn (0x2007db) copy the
// delay +0x4c and the two flags +0x50, +0x51.
static void THISCALL spawnCopyData(u8 *self, u8 *src) {
  if (isA(src, 0x2007db)) {
    *(u32 *)(self + 0x4c) = *(u32 *)(src + 0x4c);
    self[0x50] = src[0x50];
    self[0x51] = src[0x51];
  }
}
PCREG(46ca60, spawnCopyData);

// 0x46caa0 ZItemTemplate::CopyData(const ZGEOM*) (map): base; from a ZItemTemplate (0x1007d3) copy +0x5c..+0x6c
// (five dwords: item hands, inventory/pointer pictures, ...) and the material +0x78.
static void THISCALL templCopyData(u8 *self, u8 *src) {
  ext_43f8c0(self, src);
  if (isA(src, 0x1007d3)) {
    *(u32 *)(self + 0x5c) = *(u32 *)(src + 0x5c);
    *(u32 *)(self + 0x60) = *(u32 *)(src + 0x60);
    *(u32 *)(self + 0x64) = *(u32 *)(src + 0x64);
    *(u32 *)(self + 0x68) = *(u32 *)(src + 0x68);
    *(u32 *)(self + 0x6c) = *(u32 *)(src + 0x6c);
    *(u32 *)(self + 0x78) = *(u32 *)(src + 0x78);
  }
}
PCREG(46caa0, templCopyData);

// 0x46ce40 ZItemButton::CopyDataBlock(DBLK*) (high): ZItem part (+0x60), then dword +0x8e and word +0x92.
static u32 THISCALL buttonCopyDataBlock(u8 *self, u8 *blk) {
  ext_43f900(self, blk);
  ext_4e12e0(blk, self + 0x60, 1);
  ext_4e1b30(blk);
  ext_4e12e0(blk, self + 0x8e, 1);
  ext_4e11d0(blk, self + 0x92, 1);
  return ext_4e1b30(blk);
}
PCREG(46ce40, buttonCopyDataBlock);

// 0x46cea0 ZItemContainer::CopyDataBlock(DBLK*) (high): ZItem part, then the REFTAB +0x94.
static u32 THISCALL containerCopyDataBlock(u8 *self, u8 *blk) {
  ext_43f900(self, blk);
  ext_4e12e0(blk, self + 0x60, 1);
  ext_4e1b30(blk);
  ext_4e0fd0(blk, *(u32 *)(self + 0x94));
  return ext_4e1b30(blk);
}
PCREG(46cea0, containerCopyDataBlock);

// 0x46d700 ZItem::EnablePickup(bool) (map): if the template (+0x60 id) is pickable (slot 0x300), the item's pickup
// geom (own slot 0x2f8(0)) is shown (slot 0xbc) or hidden (slot 0xb8).
static void THISCALL itemEnablePickup(u8 *self, u32 on) {
  u32 id = *(u32 *)(self + 0x60);
  if (!id) return;
  u8 *t = vcall<u8 *>(refTable(), 0x58, id);
  if (!vcall<u32>(t, 0x300)) return;
  u8 *g = vcall<u8 *>(self, 0x2f8, 0u);
  if ((u8)on) vcall<u32>(g, 0xbc);
  else vcall<u32>(g, 0xb8);
}
PCREG(46d700, itemEnablePickup);

// ---------------------------------------------------------------- ZItemSpawn
// 0x46c910 ZItemSpawn::Command(unsigned short, void*) (map): command +0x48 = "remove": clears +0x52; unless byte +0x50
// (keep), the spawned item id +0x5a is removed via ZFFGameData and cleared, and flag 0x10 is set (slot 0x64).
// Command +0x4a = "spawn now". Returns 0.
static u32 THISCALL spawnCommand(u8 *self, u32 cmd, void *) {
  u16 c = (u16)cmd;
  if (c == *(u16 *)(self + 0x48)) {
    *(u32 *)(self + 0x52) = 0;
    if (!self[0x50]) {
      ext_470550(G(u8 *, 0x7003b8), *(u32 *)(self + 0x5a));
      *(u32 *)(self + 0x5a) = 0;
      vcall<u32>(self, 0x64, 0x10u);
    }
  }
  if (c == *(u16 *)(self + 0x4a)) ext_471680(self);
  return 0;
}
PCREG(46c910, spawnCommand);

// 0x46d290 ZItemSpawn::CopyEventDataBlock(DBREAD&) (map): float delay +0x4c, then two bools +0x50, +0x51.
static void THISCALL spawnCopyEvent(u8 *self, u8 *rd) {
  *(float *)(self + 0x4c) = ext_4e5e80(rd);
  self[0x50] = ext_4e5e60(rd) != 0;
  self[0x51] = ext_4e5e60(rd) != 0;
}
PCREG(46d290, spawnCopyEvent);

// 0x46f600 ZItemSpawn::Load(ZLoadGame*) (map): dword +0x52 (slot 0x40) and float +0x56 (slot 0x50) from the save,
// then re-reads the event data from a DBREAD cursor at 0 (the argument slot is reused for it). Returns true.
static u8 THISCALL spawnLoad(u8 *self, u8 *g) {
  vcall<u32>(g, 0x40, self + 0x52);
  vcall<u32>(g, 0x50, self + 0x56);
  u32 rd = 0;
  *(float *)(self + 0x4c) = ext_4e5e80(&rd);
  self[0x50] = ext_4e5e60(&rd) != 0;
  self[0x51] = ext_4e5e60(&rd) != 0;
  return 1;
}
PCREG(46f600, spawnLoad);

// 0x470670 ZItemSpawn::Save(ZSaveGame*) (map): dword +0x52 (slot 0x3c), float +0x56 (slot 0x4c). Returns true.
static u8 THISCALL spawnSave(u8 *self, u8 *g) {
  vcall<u32>(g, 0x3c, *(u32 *)(self + 0x52));
  vcall<u32>(g, 0x4c, *(u32 *)(self + 0x56));
  return 1;
}
PCREG(470670, spawnSave);

// 0x4717f0 ZItemTemplate::StateNotify(ZGEOM*, int) (map): for each set bit i (0..6) of the mask, state i of the
// list +0x70 (slot 4) gets the geom's reference id. Arithmetic shift, stops when the mask runs out.
static void THISCALL templStateNotify(u8 *self, u8 *geom, s32 mask) {
  for (u32 i = 0;;) {
    if (mask & 1) {
      u32 *slot = vcall<u32 *>(*(u8 **)(self + 0x70), 4, i);
      *slot = vcall<u32>(refTable(), 0x4c, geom);
    }
    mask >>= 1;
    if (!mask) break;
    if (++i == 7) break;
  }
}
PCREG(4717f0, templStateNotify);

// ---------------------------------------------------------------- actions
// 0x486480 ZActionDropItem::Execute() (map): notify the hand (+0xc slot 0x10); with an item (+0x10) the actor (+8)
// plays the drop animation (slot 0x228(item, 1, 0.0, 10.0, 1.0)) with the callback 0x465710 at t=10.0; returns
// true (only AL defined). Without an item: own slot 0xc (finish), tail call.
static u32 THISCALL dropExecute(u8 *self) {
  vcall<u32>(*(u8 **)(self + 0xc), 0x10);
  u32 item = *(u32 *)(self + 0x10);
  if (item) {
    u8 *anim = vcall<u8 *>(*(u8 **)(self + 8), 0x228, item, 1u, 0u, 0x41200000u, 0x3f800000u);
    u32 r = ext_4614d0(anim, 10.0f, 0x465710, 0);
    return (r & ~0xffu) | 1;
  }
  return vcall<u32>(self, 0xc);
}
PCREG(486480, dropExecute);

// ---------------------------------------------------------------- ZScriptItemInterface_t ("Item_If")
// 0x50b7f0 AddSeeAbleItem / 0x50bef0 DelSeeAbleItem (map): the world's "TrackLinkObjects" group (sys+0x9b -> +0xadc,
// by name slot 0x25c) gets message "Msg_ObjectAdd"-registered id (ref table slot 0x114, item_if.cpp line 0x8b /
// 0x93) with the item id from parameter 0. The group's vtable is read before the message lookup.
static u32 seeAble(u8 *params, u32 line) {
  u8 *grp = vcall<u8 *>(*(u8 **)(refTable() + 0xadc), 0x25c, 0x685f44u, 0u);
  u32 *p = (u32 *)ext_5003d0(*(u8 **)(params + 4), 0);
  u8 *vt = *(u8 **)grp;
  u32 msg = vcall<u32>(refTable(), 0x114, 0x690464u, 0u, 0x69d420u, line, *p);
  return (*(u32(THISCALL **)(u8 *, u8 *, u32))(vt + 0x130))(grp, grp, (u16)msg);
}
static u32 THISCALL scriptAddSeeAble(u8 *, u8 *params) { return seeAble(params, 0x8b); }
PCREG(50b7f0, scriptAddSeeAble);
static u32 THISCALL scriptDelSeeAble(u8 *, u8 *params) { return seeAble(params, 0x93); }
PCREG(50bef0, scriptDelSeeAble);
