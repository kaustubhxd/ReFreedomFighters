// batch265.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch265"): ZItem::SetItemOwner,
// how an item moves from one owner to another (pick-up, drop, inventory). Name from the GameCube name map (high).
#include "ff.h"

extern "C" const char *THISCALL ext_4cc1d0(u8 *str);   // original string c_str
extern "C" void THISCALL ext_4cbec0(u8 *str);          // original string destructor
extern "C" void THISCALL ext_4dc440(u8 *geom, u32 on); // ZBaseGeom::SetAutoRoomAssign(bool) (hooked, GUESS stub)
extern "C" void THISCALL ext_4dbe30(u8 *geom, u32 on); // ZBaseGeom::MakeDynamic(bool) (hooked, GUESS stub)

typedef void(__attribute__((cdecl)) * log3_t)(void *, const char *, const char *, const char *, const char *);
typedef void (*assert_t)();
typedef void(THISCALL *send128_t)(u8 *, u32, u32, u32);

#define DB (*(u8 **)(*(u8 **)0x70039cu + 0x9b))

// RegisterZMsg(msg, 0, zitem.cpp, line) sent to g with SendCommand slot 0x128 (cmd, data, 0). The data and 0 words are
// pushed before the four RegisterZMsg words; g's vtable is read before the db calls.
static void sendItemMsg(u8 *g, u32 msg, u32 line, u32 data) {
  u8 *gv = *(u8 **)g;
  u32 r = vcall<u32>(DB, 0x114, msg, 0u, 0x6887c4u, line);
  (*(send128_t *)(gv + 0x128))(g, (u16)r, data, 0u);
}

// 0x470c90 ZItem::SetItemOwner(unsigned newOwner, ZGROUP *group, bool notify) ret 0xc, returns the old owner id (+0x64).
//  - A change of owner on an item whose class (+8)->+0x3c has 0x200000 asserts; with an old owner it first logs "Item %s
//    not detached from old owner %s before attached to new owner %s" (zitem.cpp 0x3d1; names via vt[0x1d8], the item or
//    the missing owner's place taken by the item itself; item name +4 or "<NONAME>").
//  - Same nonzero owner again: returns at once. A new owner the db does not know counts as 0.
//  - notify and a real change: "MSG_REMOVEITEMFROMINVENTORY" (0x3ec) to the old owner and "MSG_ADDITEMTOINVENTORY" (0x3f1)
//    to the new one, both with this item's handle (db vt[0x4c]); if the db then no longer knows the item, it returns.
//  - +0x64 = new owner; the group (argument, else this->vt[0x20]()) gets vt[0x288](this, 0, 1), with SetAutoRoomAssign /
//    MakeDynamic on the item's base geom (+8) depending on the group's and the item's class flags; finally
//    this->vt[0x300](vt[0x2f4]() == 0 && vt[0x2e8]()->vt[0x300]() != 0).
static u32 THISCALL setItemOwner_470c90(u8 *self, u32 owner, u8 *group, u8 notify) {
  u32 old = *(u32 *)(self + 0x64);
  if (old != owner && (*(u32 *)(*(u8 **)(self + 8) + 0x3c) & 0x200000)) {
    if (old) {
      u8 *og = (u8 *)vcall<u32>(DB, 0x58, old);
      u8 *ng = (u8 *)vcall<u32>(DB, 0x58, owner);
      if (!og) og = self;
      if (!ng) ng = self;
      void *log = vcall<void *>(*(void **)0x700390u, 0x20, (const char *)0x6887c4u, 0x3d1u);
      u8 nbuf[0x80], obuf[0x80];
      u8 *ns = (u8 *)vcall<u32>(ng, 0x1d8, (u32)nbuf, 1u);
      u8 *os = (u8 *)vcall<u32>(og, 0x1d8, (u32)obuf, 1u);
      const char *item = *(const char **)(self + 4) ? *(const char **)(self + 4) : (const char *)0x67c8e8u;
      const char *nn = ext_4cc1d0(ns);
      const char *on = ext_4cc1d0(os);
      (*(log3_t *)(*(u8 **)log + 0x2c))(log, (const char *)0x688920u, item, on, nn);
      ext_4cbec0(obuf);
      ext_4cbec0(nbuf);
    }
    assert_t a = *(assert_t *)0x7003b0u;
    if (a) a();
    else __builtin_debugtrap();   // the exe jumps to an int3 when no hook is set
  }
  old = *(u32 *)(self + 0x64);
  if (old && old == owner) return old;
  u8 *oldG = (u8 *)vcall<u32>(DB, 0x58, old);
  u8 *newG = 0;
  if (owner) {
    newG = (u8 *)vcall<u32>(DB, 0x58, owner);
    if (!newG) owner = 0;
  }
  if (notify && newG != oldG) {
    if (oldG) {
      u8 *ov = *(u8 **)oldG;
      u32 h = vcall<u32>(DB, 0x4c, (u32)self);
      u32 r = vcall<u32>(DB, 0x114, 0x688968u, 0u, 0x6887c4u, 0x3ecu);
      (*(send128_t *)(ov + 0x128))(oldG, (u16)r, h, 0u);
    }
    if (newG) {
      u32 h = vcall<u32>(DB, 0x4c, (u32)self);
      sendItemMsg(newG, 0x688984u, 0x3f1u, h);
      if (!vcall<u32>(DB, 0x58, h)) return old;
    }
  }
  *(u32 *)(self + 0x64) = owner;
  u8 *root = (u8 *)vcall<u32>(self, 0x20);
  u8 *g = group;
  if (!g) {
    g = root;
    if (!root) g = (u8 *)vcall<u32>(self, 0x20);
  }
  if (*(u32 *)(*(u8 **)(g + 8) + 0x3c) & 0x40040000) {
    if (*(u32 *)(*(u8 **)(self + 8) + 0x3c) & 0x40000) {
      ext_4dc440(*(u8 **)(self + 8), 0);
      ext_4dbe30(*(u8 **)(self + 8), 0);
    }
    vcall<void>(g, 0x288, (u32)self, 0u, 1u);
  } else {
    vcall<void>(g, 0x288, (u32)self, 0u, 1u);
    if (!(*(u32 *)(*(u8 **)(self + 8) + 0x3c) & 0x40000)) ext_4dbe30(*(u8 **)(self + 8), 1);
    ext_4dc440(*(u8 **)(self + 8), 1);
  }
  u32 v = 0;
  if (!vcall<u32>(self, 0x2f4) && vcall<u32>((u8 *)vcall<u32>(self, 0x2e8), 0x300)) v = 1;
  vcall<void>(self, 0x300, v);
  return old;
}
PCREG(470c90, setItemOwner_470c90);
#undef DB
