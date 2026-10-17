// batch1300.cpp - inventory thread (inline-inventory, 2026-10-11): ZItem / ZItemTemplate / ZItemContainer / ZItemState
// leaf accessors and the small Load/Save/CopyDataBlock wrappers. Names are the GameCube ELF names from
// decoders/gc_pc_namemap.tsv (confidence given per function); offsets are PC (/Zp1 packed, so odd offsets are real).
#include "ff.h"

// ---------------------------------------------------------------- callees left as original code
extern "C" u32 THISCALL ext_4702b0(u8 *self, void *rd);            // ZItemState::ReadInput(DBREAD&)
extern "C" u32 THISCALL ext_6352f0(u8 *self, void *rd);            // ZEventBase::GetInput(DBREAD&)
extern "C" u32 THISCALL ext_46f9d0(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);  // ZItem::OwnerDraw
extern "C" u32 THISCALL ext_471680(u8 *self);                      // ZItemSpawn::SpawnItem()
extern "C" u32 THISCALL ext_43f900(u8 *self, u8 *blk);             // ZGROUP::CopyDataBlock(DBLK*)
extern "C" u32 THISCALL ext_46cee0(u8 *self, u8 *blk);             // ZItemTemplate::CopyDataBlock(DBLK*)
extern "C" u32 THISCALL ext_4e12e0(u8 *blk, u32 *dst, int n);      // DBLK::Get(unsigned int*, int)
extern "C" u32 THISCALL ext_4e0fd0(u8 *blk, u32 reftab);           // DBLK::Get(REFTAB*)
extern "C" u32 THISCALL ext_4e1b30(u8 *blk);                       // DBLK::NextBlock()
extern "C" u32 THISCALL ext_46f520(u8 *self, u8 *g);               // ZItem::Load(ZLoadGame*)
extern "C" u32 THISCALL ext_440e10(u8 *self, u8 *g);               // ZGROUP::Load(ZLoadGame*)
extern "C" u32 THISCALL ext_4705a0(u8 *self, u8 *g);               // ZItem::Save(ZSaveGame*)
extern "C" u32 THISCALL ext_441790(u8 *self, u8 *g);               // ZGROUP::Save(ZSaveGame*)
extern "C" u32 THISCALL ext_4614d0(u8 *anim, float t, u32 cb, u32 data);  // ZBoneAnim::AddCallBack
extern "C" void FASTCALL ext_4de7a0(float *m);                     // mreset(float*) (ecx only)
extern "C" u32 THISCALL ext_4db2c0(u8 *geom, float *m, float *p);  // ZBaseGeom::GetMatPos(float*, float*) const
extern "C" void ext_634273(void *p, u32 size);                     // operator delete(void*, size_t) (cdecl)

// ZSysInterface (0x70039c) +0x9b holds the reference table that turns a saved id into an object pointer:
// slot 0x58 = id -> object, slot 0x4c = object -> id (both used by the Load/Save pairs below).
static inline u8 *refTable() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// ---------------------------------------------------------------- leaf accessors
// 0x468a20 ZItemState::IsMain() (GC name, low: ICF-shared body). byte +0x52.
static u8 THISCALL itemStateIsMain(u8 *self) { return self[0x52]; }
PCREG(468a20, itemStateIsMain);

// 0x46e680 ZItemContainer::GetContainedItems() const (high). +0x94 = contained-items list object.
static u32 THISCALL containerGetContained(u8 *self) { return *(u32 *)(self + 0x94); }
PCREG(46e680, containerGetContained);

// 0x46e700 ZItemTemplate::GetItemClassName() const (low name, string proves it): "ZItem" at 0x6866a8.
static u32 THISCALL templGetItemClassName(u8 *) { return 0x6866a8; }
PCREG(46e700, templGetItemClassName);

// 0x46e720 ZItemTemplateContainer::GetItemClassName() const: "ZItemContainer" at 0x686504.
static u32 THISCALL templContGetItemClassName(u8 *) { return 0x686504; }
PCREG(46e720, templContGetItemClassName);

// 0x46eaa0 ZItemTemplate::GetMaterial() (medium). +0x78.
static u32 THISCALL templGetMaterial(u8 *self) { return *(u32 *)(self + 0x78); }
PCREG(46eaa0, templGetMaterial);

// 0x46eee0 ZItemTemplate::GetStates() const (low, ICF). +0x70 = state list (also what Load/Save stream).
static u32 THISCALL templGetStates(u8 *self) { return *(u32 *)(self + 0x70); }
PCREG(46eee0, templGetStates);

// 0x470c80 ZItemTemplate::SetInventoryPicture(unsigned int) (high). +0x64.
static void THISCALL templSetInventoryPicture(u8 *self, u32 v) { *(u32 *)(self + 0x64) = v; }
PCREG(470c80, templSetInventoryPicture);

// 0x4711c0 ZItem::SetMain(unsigned int) (high). +0x68 = id of the main item (resolved by GetMain). The exe loads
// the old value into EAX first, so EAX on return is the previous id.
static u32 THISCALL itemSetMain(u8 *self, u32 v) {
  u32 old = *(u32 *)(self + 0x68);
  *(u32 *)(self + 0x68) = v;
  return old;
}
PCREG(4711c0, itemSetMain);

// 0x471a10 ZItem::VerifyItemTemplate(const ZItemTemplate*) const (high): template's class info (+0xc) has type
// id 0x1007d3 at +0x23. 0x471a70 ZItemContainer::VerifyItemTemplate: same with 0x1007d9.
static u8 THISCALL itemVerifyTemplate(u8 *, u8 *t) {
  if (!t) return 0;
  return *(u32 *)(*(u8 **)(t + 0xc) + 0x23) == 0x1007d3;
}
PCREG(471a10, itemVerifyTemplate);
static u8 THISCALL containerVerifyTemplate(u8 *, u8 *t) {
  if (!t) return 0;
  return *(u32 *)(*(u8 **)(t + 0xc) + 0x23) == 0x1007d9;
}
PCREG(471a70, containerVerifyTemplate);

// Action class names (all high): return the literal.
static u32 THISCALL actDropName(u8 *) { return 0x68ccb4; }     // "ZActionDropItem"
PCREG(486e20, actDropName);
static u32 THISCALL actGetName(u8 *) { return 0x68cc08; }      // "ZActionGetItem"
PCREG(486e30, actGetName);
static u32 THISCALL actPickupName(u8 *) { return 0x68cc78; }   // "ZActionPickupItem"
PCREG(486e40, actPickupName);
static u32 THISCALL actPutName(u8 *) { return 0x68cc40; }      // "ZActionPutItem"
PCREG(486e60, actPutName);
static u32 THISCALL actSwapName(u8 *) { return 0x68ccec; }     // "ZActionSwapItem" (sic, no s)
PCREG(486e80, actSwapName);

// 0x4875d0 CPathUserProfile::GetUser() const (low, ICF): dword at +6 (packed struct).
static u32 THISCALL pathUserGetUser(u8 *self) { return *(u32 *)(self + 6); }
PCREG(4875d0, pathUserGetUser);

// 0x49eec0 CInventory::GetInventoryList() const (high): the list is embedded at +0x11a.
static u8 *THISCALL invGetList(u8 *self) { return self + 0x11a; }
PCREG(49eec0, invGetList);

// ---------------------------------------------------------------- tail calls and wrappers
// 0x468310 ZItemState::CopyEventDataBlock(DBREAD&) (high): tail call ReadInput.
static u32 THISCALL itemStateCopyEvent(u8 *self, void *rd) { return ext_4702b0(self, rd); }
PCREG(468310, itemStateCopyEvent);

// 0x46fd90 ZItemContainer::OwnerDraw(...) (medium): tail call ZItem::OwnerDraw with the same 7 arguments.
static u32 THISCALL containerOwnerDraw(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
  return ext_46f9d0(self, a, b, c, d, e, f, g);
}
PCREG(46fd90, containerOwnerDraw);

// 0x4683f0 ZItemState::Load(ZLoadGame*) (high): clears flag 0x40 of +4, reads the event base then the item-state
// input from a DBREAD cursor that starts at 0 (a 4-byte local). Returns true.
static u8 THISCALL itemStateLoad(u8 *self, u8 *) {
  u32 rd = 0;
  *(u32 *)(self + 4) &= ~0x40u;
  ext_6352f0(self, &rd);
  ext_4702b0(self, &rd);
  return 1;
}
PCREG(4683f0, itemStateLoad);

// 0x46e3b0 ZItemSpawn::FrameUpdate() (high): timer +0x56 += frame time (sys+0x48); once it reaches the
// respawn delay +0x4c it spawns the item and restarts at 0. NaN never spawns (comiss/jb).
static void THISCALL spawnFrameUpdate(u8 *self) {
  float t = *(float *)(G(u8 *, 0x70039c) + 0x48) + *(float *)(self + 0x56);
  *(float *)(self + 0x56) = t;
  if (t >= *(float *)(self + 0x4c)) {
    ext_471680(self);
    *(u32 *)(self + 0x56) = 0;
  }
}
PCREG(46e3b0, spawnFrameUpdate);

// 0x46eff0 ZItemSpawn::Init2() (name from map): the spawn marker geom +0x44 gets slot 0xbc(1) (hide) and
// slot 0x300(0); if byte +0x51 (spawn at start) is set, spawns now (tail call).
static u32 THISCALL spawnInit2(u8 *self) {
  vcall<u32>(*(u8 **)(self + 0x44), 0xbc, 1u);
  u32 r = vcall<u32>(*(u8 **)(self + 0x44), 0x300, 0u);
  if (self[0x51]) return ext_471680(self);
  return r;
}
PCREG(46eff0, spawnInit2);

// 0x46e740 ZItem::GetItemOwner() / 0x46e8c0 ZItem::GetMain() (names from map): resolve the saved id at +0x64 /
// +0x68 through the reference table; 0 stays 0.
static u32 THISCALL itemGetOwner(u8 *self) {
  u32 id = *(u32 *)(self + 0x64);
  if (!id) return 0;
  return vcall<u32>(refTable(), 0x58, id);
}
PCREG(46e740, itemGetOwner);
static u32 THISCALL itemGetMain(u8 *self) {
  u32 id = *(u32 *)(self + 0x68);
  if (!id) return 0;
  return vcall<u32>(refTable(), 0x58, id);
}
PCREG(46e8c0, itemGetMain);

// 0x46ef70 ZItemState::GetUseGeom(ZItem*) (name from map): id at +0xe1 resolved the same way; the ZItem* is unused.
static u32 THISCALL itemStateGetUseGeom(u8 *self, u8 *) {
  u32 id = *(u32 *)(self + 0xe1);
  if (!id) return 0;
  u32 r = vcall<u32>(refTable(), 0x58, id);
  return r ? r : 0;
}
PCREG(46ef70, itemStateGetUseGeom);

// 0x46e3e0 ZItem::GetAction(unsigned int) (name from map): finds the child group named "Action" (slot 0x100) and
// asks it (slot 0x8c) for entry `id`; args (0, 0, id, 0).
static u32 THISCALL itemGetAction(u8 *self, u32 id) {
  u8 *a = vcall<u8 *>(self, 0x100, 0x67a110u);
  if (!a) return 0;
  return vcall<u32>(a, 0x8c, 0u, 0u, id, 0u);
}
PCREG(46e3e0, itemGetAction);

// 0x46e580 ZItemTemplate::GetCameraPos() / 0x46e660 GetCenterPos(): child geom "PosBox_Camera" / "PosBox_Center"
// by name (slot 0x25c, second arg 0). GetCenterPos falls back to the template itself.
static u32 THISCALL templGetCameraPos(u8 *self) { return vcall<u32>(self, 0x25c, 0x68887cu, 0u); }
PCREG(46e580, templGetCameraPos);
static u32 THISCALL templGetCenterPos(u8 *self) {
  u32 r = vcall<u32>(self, 0x25c, 0x68886cu, 0u);
  return r ? r : (u32)self;
}
PCREG(46e660, templGetCenterPos);

// 0x46abb0 ZItem::AddDeactivate(unsigned int, float) (name from map): slot 0x110(0x10, 0) on self, then the
// item's controller (+0x74) slot 0x98(id, delay, 0).
static void THISCALL itemAddDeactivate(u8 *self, u32 id, float delay) {
  vcall<u32>(self, 0x110, 0x10u, 0u);
  vcall<u32>(*(u8 **)(self + 0x74), 0x98, id, delay, 0u);
}
PCREG(46abb0, itemAddDeactivate);

// 0x46cdc0 ZItem::CopyDataBlock(DBLK*) (medium): base group, then one dword into +0x60, next block.
static u32 THISCALL itemCopyDataBlock(u8 *self, u8 *blk) {
  ext_43f900(self, blk);
  ext_4e12e0(blk, (u32 *)(self + 0x60), 1);
  return ext_4e1b30(blk);
}
PCREG(46cdc0, itemCopyDataBlock);

// 0x46d040 ZItemTemplateContainer::CopyDataBlock(DBLK*) (high): template base, then the REFTAB at +0x7c.
static u32 THISCALL templContCopyDataBlock(u8 *self, u8 *blk) {
  ext_46cee0(self, blk);
  ext_4e0fd0(blk, *(u32 *)(self + 0x7c));
  return ext_4e1b30(blk);
}
PCREG(46d040, templContCopyDataBlock);

// Load/Save pairs (names from map, high): base class, then stream the list at +0x94 (container) or +0x70
// (template states) through the ZLoadGame slot 0x70 / ZSaveGame slot 0x6c. Return true.
static u8 THISCALL containerLoad(u8 *self, u8 *g) {
  ext_46f520(self, g);
  vcall<u32>(g, 0x70, *(u32 *)(self + 0x94));
  return 1;
}
PCREG(46f5d0, containerLoad);
static u8 THISCALL templLoad(u8 *self, u8 *g) {
  ext_440e10(self, g);
  vcall<u32>(g, 0x70, *(u32 *)(self + 0x70));
  return 1;
}
PCREG(46f660, templLoad);
static u8 THISCALL containerSave(u8 *self, u8 *g) {
  ext_4705a0(self, g);
  vcall<u32>(g, 0x6c, *(u32 *)(self + 0x94));
  return 1;
}
PCREG(470640, containerSave);
static u8 THISCALL templSave(u8 *self, u8 *g) {
  ext_441790(self, g);
  vcall<u32>(g, 0x6c, *(u32 *)(self + 0x70));
  return 1;
}
PCREG(4706a0, templSave);

// 0x470540 ZItemContainer::RemoveItem(unsigned int) (name from map): tail call slot 0x3c of the list at +0x94.
static u32 THISCALL containerRemoveItem(u8 *self, u32 id) { return vcall<u32>(*(u8 **)(self + 0x94), 0x3c, id); }
PCREG(470540, containerRemoveItem);

// 0x485f00 ZActionGetItem::~ZActionGetItem() (deleting destructor, medium): resets the vtable to the ZAction base
// (0x685294) and frees 0x1c bytes when bit 0 of the flag is set. Returns this.
static u8 *THISCALL actGetDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x685294;
  if (flags & 1) ext_634273(self, 0x1c);
  return self;
}
PCREG(485f00, actGetDtor);

// 0x4869a0 ZActionSwapItems::Execute() (name from map): with a target item (+0x14), the actor (+8) starts the swap
// animation (slot 0x230(item, 1)) and a callback 0x465710 is added at t=12.5 (0x41480000); returns true. Without one it tail
// calls its own slot 0xc (finish). Only AL is defined on the first path (EAX's upper bytes come from AddCallBack).
static u32 THISCALL swapExecute(u8 *self) {
  u32 item = *(u32 *)(self + 0x14);
  if (item) {
    u8 *anim = vcall<u8 *>(*(u8 **)(self + 8), 0x230, item, 1u);
    u32 r = ext_4614d0(anim, 12.5f, 0x465710, 0);
    return (r & ~0xffu) | 1;
  }
  return vcall<u32>(self, 0xc);
}
PCREG(4869a0, swapExecute);

// 0x486d90 ZFFActionPickupItem::Load(ZLoadGame&) (name from map): reads an id into the argument's own stack slot
// (ZLoadGame slot 0x40), resolves it, stores the item at +8.
static u32 THISCALL ffPickupLoad(u8 *self, u8 *g) {
  u32 slot = (u32)g;
  vcall<u32>(g, 0x40, &slot);
  u32 r = vcall<u32>(refTable(), 0x58, slot);
  *(u32 *)(self + 8) = r;
  return r;
}
PCREG(486d90, ffPickupLoad);

// 0x487030 ZFFActionPickupItem::Save(ZSaveGame&): item +8 -> id (slot 0x4c), written by ZSaveGame slot 0x3c.
static u32 THISCALL ffPickupSave(u8 *self, u8 *g) {
  u32 id = vcall<u32>(refTable(), 0x4c, *(u32 *)(self + 8));
  return vcall<u32>(g, 0x3c, id);
}
PCREG(487030, ffPickupSave);

// 0x46e980 ZItem::GetMainMatPos(float*, float*) (name from map): main geom (slot 0x2dc); without one the matrix
// is reset and the position zeroed, else tail call ZBaseGeom::GetMatPos on its base geom (+8).
static u32 THISCALL itemGetMainMatPos(u8 *self, float *m, float *p) {
  u8 *g = vcall<u8 *>(self, 0x2dc);
  if (!g) {
    ext_4de7a0(m);
    u32 *q = (u32 *)p;
    q[0] = 0;
    q[1] = 0;
    q[2] = 0;
    return (u32)p;
  }
  return ext_4db2c0(*(u8 **)(g + 8), m, p);
}
PCREG(46e980, itemGetMainMatPos);
