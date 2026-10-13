// batch1113.cpp - collision thread, batch 1113: ZBaseGeom room draw-list attach (one of the render-manager
// blockers named in docs/20-inline-batch-4-5.md batch 42) and its two small callees.
#include "ff.h"

static inline u8 *sysObj() { return G(u8 *, 0x70039c); }
static inline u8 *drawLists() { return *(u8 **)(*(u8 **)(sysObj() + 0x9b) + 8); }   // [[0x70039c]+0x9b]+8

// 0x4dafb0 ZBaseGeom::GetDynamicParent() [high], thiscall. Flag 0x40000000 and a non-zero room index (u16 +0x5c):
// the draw-list object's slot 0x4c returns a base, and the parent is base + (index - 1) * 0x70. Otherwise null.
static u8 *THISCALL getDynamicParent(u8 *self) {
  if (!(*(u32 *)(self + 0x3c) & 0x40000000) || !*(u16 *)(self + 0x5c))
    return 0;
  u8 *base = vcall<u8 *>(drawLists(), 0x4c);
  return base + (u32)*(u16 *)(self + 0x5c) * 0x70 - 0x70;
}
PCREG(4dafb0, getDynamicParent);

// 0x4db550 ZBaseGeom::GetRoomList() const [high], thiscall: the draw-list object's slot 0x5c (room index u16 +0x5c),
// or null for index 0.
static u8 *THISCALL getRoomList(const u8 *self) {
  u16 idx = *(const u16 *)(self + 0x5c);
  if (!idx)
    return 0;
  return vcall<u8 *>(drawLists(), 0x5c, (u32)idx);
}
PCREG(4db550, getRoomList);

extern "C" u32 FASTCALL ext_4daf20(u32 cls, u32 flags);   // GetBaseGeomListType (batch 29)
extern "C" u8 *THISCALL ext_4dafb0(u8 *self);
extern "C" u8 *THISCALL ext_4db550(const u8 *self);
extern "C" u8 THISCALL ext_4dc290(u8 *self);              // ZBaseGeom::RequestCustomDraw (batch 29)
extern "C" void THISCALL ext_4d9d20(u8 *self, u8 *room);

static inline u32 boundClass(const u8 *g) {
  const u8 *b = *(u8 *const *)(g + 0x54);
  return b ? *(const u32 *)(*(u8 *const *)(b + 0xc) + 0x23) : 0x200002u;
}

// True when the class descriptor chain of bound object b (+0xc, linked by +0xc, id at +0x23) contains id.
static inline bool hasClass(const u8 *b, u32 id) {
  for (const u8 *d = *(u8 *const *)(b + 0xc); d; d = *(u8 *const *)(d + 0xc))
    if (*(const u32 *)(d + 0x23) == id)
      return true;
  return false;
}

// Adds geom to a draw list head unless the draw-list object already has it: slot 0x40(head, geom), then
// head = slot 0x38(head, geom, geom).
static inline void addToList(u32 *head, u8 *geom) {
  if (vcall<u8>(drawLists(), 0x40, *head, geom))
    return;
  *head = vcall<u32>(drawLists(), 0x38, *head, geom, geom);
}

// 0x4d9d20 ZBaseGeom::AttachToRoomsDrawLists(ZROOM *room) [high], thiscall, ret 4.
// Geoms flagged 0x202c00 are never drawn. By GetBaseGeomListType(class, flags):
// - 1 (drawn): flagged 0x40040000 (room-bound): add to room+0xbc, or (no room) to every room of the room list of the
//   geom (or of its dynamic parent when flagged 0x40000000; list = up to byte +0x1c rooms). Otherwise find the first
//   ancestor (+0x50 chain) whose bound has class 0x100021 (a custom-draw group): unless that bound is the dynamic
//   tree [[[0x70039c]+0x9b]+0xadc], add to its list at +0xb8 (+0xb4 when RequestCustomDraw); then notify
//   [[0x70039c]+0x190f] (slot 0x18c with the bound's +8) when present.
// - 0 (a group): recurse into each child (bound+0x50, linked by +0x60) unless the child's bound has class 0x100021,
//   or has class 0x100020 and its slot 0x310 says no.
static void THISCALL attachToRoomsDrawLists(u8 *self, u8 *room) {
  u32 f = *(u32 *)(self + 0x3c);
  if (f & 0x202c00)
    return;
  u8 *bnd = *(u8 **)(self + 0x54);
  u32 lt = ext_4daf20(boundClass(self), f);
  if (lt == 1) {
    if (f & 0x40040000) {
      if (room) {
        addToList((u32 *)(room + 0xbc), self);
        return;
      }
      u8 *g = self;
      if (f & 0x40000000)
        g = ext_4dafb0(self);
      u8 *list = ext_4db550(g);
      if (!list)
        return;
      u32 n = list[0x1c];
      for (u32 i = 0; i != n; i++) {
        u8 *r = (i < list[0x1c]) ? ((u8 **)list)[i] : 0;
        addToList((u32 *)(r + 0xbc), self);
      }
      return;
    }
    for (u8 *p = *(u8 **)(self + 0x50); p; p = *(u8 **)(p + 0x50)) {
      u8 *pb = *(u8 **)(p + 0x54);
      if (!pb || !hasClass(pb, 0x100021))
        continue;
      if (pb != *(u8 **)(*(u8 **)(sysObj() + 0x9b) + 0xadc)) {
        u32 *head = (u32 *)(pb + 0xb8);
        if (ext_4dc290(self))
          head = (u32 *)(pb + 0xb4);
        addToList(head, self);
      }
      u8 *o = *(u8 **)(sysObj() + 0x190f);
      if (o)
        vcall<void>(o, 0x18c, *(u32 *)(pb + 8));
      return;
    }
    return;
  }
  if (lt != 0)
    return;
  for (u8 *c = *(u8 **)(bnd + 0x50); c; c = *(u8 **)(c + 0x60)) {
    u8 *cb = *(u8 **)(c + 0x54);
    if (cb) {
      if (hasClass(cb, 0x100021))
        continue;
      if (hasClass(cb, 0x100020) && vcall<u8>(cb, 0x310))
        continue;
    }
    ext_4d9d20(c, room);
  }
}
PCREG(4d9d20, attachToRoomsDrawLists);

extern "C" void THISCALL ext_4da770(u8 *self, u8 *room);

// Removes geom from a draw list head if the draw-list object has it: slot 0x40(head, geom), then
// head = slot 0x3c(head, geom, geom).
static inline void removeFromList(u32 *head, u8 *geom) {
  if (!vcall<u8>(drawLists(), 0x40, *head, geom))
    return;
  *head = vcall<u32>(drawLists(), 0x3c, *head, geom, geom);
}

// 0x4da770 ZBaseGeom::DetachFromRoomsDrawLists(ZROOM *room) [high], thiscall, ret 4. The mirror of
// AttachToRoomsDrawLists with slot 0x3c (remove) for slot 0x38, without the 0x202c00 early-out; GetRoomList and
// RequestCustomDraw are inlined (the dynamic parent's room index is read directly).
static void THISCALL detachFromRoomsDrawLists(u8 *self, u8 *room) {
  u8 *bnd = *(u8 **)(self + 0x54);
  u32 f = *(u32 *)(self + 0x3c);
  u32 lt = ext_4daf20(boundClass(self), f);
  if (lt == 1) {
    if (f & 0x40040000) {
      if (room) {
        removeFromList((u32 *)(room + 0xbc), self);
        return;
      }
      u8 *g = self;
      if (f & 0x40000000)
        g = ext_4dafb0(self);
      u16 idx = *(u16 *)(g + 0x5c);
      if (!idx)
        return;
      u8 *list = vcall<u8 *>(drawLists(), 0x5c, (u32)idx);
      if (!list)
        return;
      u32 n = list[0x1c];
      for (u32 i = 0; i != n; i++) {
        u8 *r = (i < list[0x1c]) ? ((u8 **)list)[i] : 0;
        removeFromList((u32 *)(r + 0xbc), self);
      }
      return;
    }
    for (u8 *p = *(u8 **)(self + 0x50); p; p = *(u8 **)(p + 0x50)) {
      u8 *pb = *(u8 **)(p + 0x54);
      if (!pb || !hasClass(pb, 0x100021))
        continue;
      if (pb != *(u8 **)(*(u8 **)(sysObj() + 0x9b) + 0xadc)) {
        u8 custom = bnd ? vcall<u8>(bnd, 0xd0) : 0;
        removeFromList((u32 *)(pb + (custom ? 0xb4 : 0xb8)), self);
      }
      u8 *o = *(u8 **)(sysObj() + 0x190f);
      if (o)
        vcall<void>(o, 0x18c, *(u32 *)(pb + 8));
      return;
    }
    return;
  }
  if (lt != 0)
    return;
  for (u8 *c = *(u8 **)(bnd + 0x50); c; c = *(u8 **)(c + 0x60)) {
    u8 *cb = *(u8 **)(c + 0x54);
    if (cb) {
      if (hasClass(cb, 0x100021))
        continue;
      if (hasClass(cb, 0x100020) && vcall<u8>(cb, 0x310))
        continue;
    }
    ext_4da770(c, room);
  }
}
PCREG(4da770, detachFromRoomsDrawLists);
