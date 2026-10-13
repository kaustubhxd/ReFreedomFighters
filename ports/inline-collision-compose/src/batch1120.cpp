// batch1120.cpp - collision thread, batch 1120: the collect callback chain of GetDynamicGeomsInBox.
#include "ff.h"

static inline u8 *sysObj() { return G(u8 *, 0x70039c); }
static inline u8 *renderMgr() { return *(u8 **)(sysObj() + 0x9b); }

extern "C" void THISCALL ext_4dc630(u8 *geom, u32 set, u32 mask);     // SetControl (batch 1114)
extern "C" u32 THISCALL ext_4daf80(const u8 *geom);                   // GetBoundTreeType (batch 1108)
extern "C" u8 *THISCALL ext_4db550(const u8 *geom);                   // GetRoomList (batch 1113)
typedef void *(THISCALL *vcallLog)(void *self, const char *file, u32 line);

// Info record of the dynamic box query (names from these bodies):
// +4 callback, +0x5c out array begin, +0x60 out array end, +0x64 count, +0x68 flag mask, +0x6c class wanted,
// +0x70 room filter (0 = none), +0x74 marked geoms (SetControl 0x10000000), +0x1074 marked count (cap 0x400).

// 0x4ec720 (unnamed; guessed RoomListContains), thiscall (list record in ECX, room on the stack), ret 4, al.
// The list holds byte +0x1c room pointers from +0.
static u8 THISCALL roomListContains(const u8 *list, const u8 *room) {
  u32 n = list[0x1c];
  for (u32 i = 0; i < n; i++)
    if (((const u8 *const *)list)[i] == room)
      return 1;
  return 0;
}
PCREG(4ec720, roomListContains);

// 0x4eddf0 (unnamed; guessed MatchGeom), fastcall (info in ECX, geom in EDX), plain ret, al. Geoms whose flags share
// a bit with the info's mask (and that have no 0xc00 bits) are checked: a geom whose tree type is the wanted class is
// appended to the out array while below its end; then, for a group (bound class 0x100000), each child is matched
// recursively. Returns whether anything was matched.
static u8 FASTCALL matchGeom(u8 *info, u8 *geom) {
  u32 flags = *(u32 *)(geom + 0x3c);
  if (!(*(u32 *)(info + 0x68) & flags))
    return 0;
  if (flags & 0xc00)
    return 0;
  u8 hit = 0;
  if (ext_4daf80(geom) == *(u32 *)(info + 0x6c)) {
    u32 cnt = *(u32 *)(info + 0x64);
    u8 **slot = *(u8 ***)(info + 0x5c) + cnt;
    if ((u8 *)slot < *(u8 **)(info + 0x60)) {
      *slot = geom;
      hit = 1;
      *(u32 *)(info + 0x64) = cnt + 1;
    }
  }
  u8 *bound = *(u8 **)(geom + 0x54);
  u32 cls = bound ? *(u32 *)(*(u8 **)(bound + 0xc) + 0x23) : 0x200002u;
  if (cls & 0x100000) {
    for (u8 *c = *(u8 **)(bound + 0x50); c; c = *(u8 **)(c + 0x60))
      hit |= matchGeom(info, c);
  }
  return hit;
}
PCREG(4eddf0, matchGeom);

// 0x4edd40 (unnamed; guessed DynCollectCallback), fastcall (object in ECX (key at +0), info in EDX), al. The
// render manager's slot 0x54 maps the key to a geom (null or 0x10000000 flagged: no). With a room filter, the geom's
// room list must contain it. The geom is then marked (SetControl 0x10000000) and recorded in the marked list while
// below 0x400 (over the cap: a log line through [0x700390], file 0x6977c4 line 0xb9, format 0x6977f8). Returns MatchGeom.
static u8 FASTCALL dynCollect(const u8 *obj, u8 *info) {
  u8 *geom = vcall<u8 *>(renderMgr(), 0x54, *(const u32 *)obj);
  if (!geom)
    return 0;
  if (*(u32 *)(geom + 0x3c) & 0x10000000)
    return 0;
  if (*(u32 *)(info + 0x70)) {
    u8 *list = ext_4db550(geom);
    if (!list)
      return 0;
    if (!roomListContains(list, *(u8 *const *)(info + 0x70)))
      return 0;
  }
  u32 marked = *(u32 *)(info + 0x1074);
  if (marked < 0x400) {
    ext_4dc630(geom, 0x10000000, 0);
    *(u8 **)(info + 0x74 + 4 * marked) = geom;
    *(u32 *)(info + 0x1074) = marked + 1;
  } else {
    void *eh = G(void *, 0x700390);
    void *lg = ((vcallLog)(*(void ***)eh)[0x20 / 4])(eh, (const char *)0x6977c4u, 0xb9u);
    typedef void (*cdeclFmt)(void *, const char *);
    ((cdeclFmt)(*(void ***)lg)[0x2c / 4])(lg, (const char *)0x6977f8u);
  }
  return matchGeom(info, geom);
}
PCREG(4edd40, dynCollect);
