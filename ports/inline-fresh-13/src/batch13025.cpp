// batch13025.cpp - fresh slice 13, batch 25 (docs/20-fresh-13.md), 2026-10-12.
// 0x4b0350 CCutSequenceEvent::GetRootObject(REFTAB* a, REFTAB* b, const char* name) (name map high): thiscall, ret 0xc.
//  - Searches the geoms listed in a, then b, then (this+0x4c)->+0x18 (iterator slots 0x4c init / 0x5c next: returns the
//    id, it[0] != 0 while valid; geom = db[+0x54](id)) for one whose name (geom+0x54 -> +4, "<NONAME>" when null)
//    _stricmp-matches `name`; the last match wins. In b and the third table the geom also needs bit 10 of +0x3c clear.
//    The first table with a match ends the search; nothing found -> 0.
//  - With a match that ZBaseGeom 0x4db9a0(0x100001) accepts, its child list ((geom+0x54)+0x54, previous via GetPrev
//    0x4db520) is walked until a child with type flag 0x100000 (child+0x54 -> +0xc -> +0x23; 0x200002 without an
//    object); a child that 0x4db9a0(0x200027) accepts is returned instead of the geom.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))
#define VT(o, off) (*(u32 *)(*(u32 *)(o) + (off)))

extern "C" char ext_4db9a0[], ext_4db520[];
typedef void(THISCALL *PI)(void *self, u32 *it);
typedef u32(THISCALL *NI)(void *self, u32 *it);
typedef u32(THISCALL *R0)(void *self);
typedef u32(THISCALL *R1)(void *self, u32 a);
typedef u8(THISCALL *B1)(void *self, u32 a);
typedef s32 (*Cmp)(const char *a, const char *b);

static inline u8 *db() { return AT(u8 *, G(u8 *, 0x70039c), 0x9b); }

static u8 *match(u8 *g, const char *name, bool bit) {
  if (!g)
    return 0;
  u32 nm = AT(u32, AT(u8 *, g, 0x54), 4);
  if ((*(Cmp *)0x676414)(name, (const char *)(nm ? nm : 0x67c8e8)))
    return 0;
  if (bit && ((AT(u32, g, 0x3c) >> 10) & 1))
    return 0;
  return g;
}

static u8 *THISCALL fn4b0350(u8 *self, u8 *a, u8 *b, const char *name) {
  u8 *res = 0;
  if (a) {
    u32 it[3];
    ((PI)VT(a, 0x4c))(a, it);
    u32 id = ((NI)VT(a, 0x5c))(a, it);
    while (it[0]) {
      u8 *m = match((u8 *)((R1)VT(db(), 0x54))(db(), id), name, false);
      if (m)
        res = m;
      id = ((NI)VT(a, 0x5c))(a, it);
    }
    if (res)
      goto found;
  }
  if (b) {
    u32 it[3];
    ((PI)VT(b, 0x4c))(b, it);
    u32 id = ((NI)VT(b, 0x5c))(b, it);
    while (it[0]) {
      u8 *m = match((u8 *)((R1)VT(db(), 0x54))(db(), id), name, true);
      if (m)
        res = m;
      id = ((NI)VT(b, 0x5c))(b, it);
    }
    if (res)
      goto found;
  }
  {
    u8 *c = AT(u8 *, self, 0x4c);
    if (!c || !AT(u8 *, c, 0x18))
      return res;
    u32 it[3];
    u8 *t = AT(u8 *, c, 0x18);
    ((PI)VT(t, 0x4c))(t, it);
    t = AT(u8 *, AT(u8 *, self, 0x4c), 0x18);
    u32 id = ((NI)VT(t, 0x5c))(t, it);
    while (it[0]) {
      u8 *m = match((u8 *)((R1)VT(db(), 0x54))(db(), id), name, true);
      if (m)
        res = m;
      t = AT(u8 *, AT(u8 *, self, 0x4c), 0x18);
      id = ((NI)VT(t, 0x5c))(t, it);
    }
    if (!res)
      return 0;
  }
found:
  if (!((B1)(void *)ext_4db9a0)(res, 0x100001))
    return res;
  for (u8 *n = AT(u8 *, AT(u8 *, res, 0x54), 0x54); n; n = (u8 *)((R0)(void *)ext_4db520)(n)) {
    u8 *o = AT(u8 *, n, 0x54);
    u32 fl = o ? AT(u32, AT(u8 *, o, 0xc), 0x23) : 0x200002;
    if (fl & 0x100000)
      return res;
    if (((B1)(void *)ext_4db9a0)(n, 0x200027))
      return n;
  }
  return res;
}
PCREG(4b0350, fn4b0350);
