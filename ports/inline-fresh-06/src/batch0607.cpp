// batch0607.cpp - fresh-06 batch 7 (docs/20-fresh-06.md). Callee pop counts from tools/rets.py.
#include "ff.h"

static inline void *rmgr() { return *(void **)(G(u8 *, 0x70039c) + 0x9b); }

// Geom factories (fastcall: class info in ECX, name in EDX; stack: parent, placement): with a placement buffer the
// object is made by 0x45c4f0(size, p), else by 0x45c4b0(size) (both cdecl); a non-null object is constructed with
// (parent, class info, name) and returned (0 otherwise). Sizes / constructors: 0x44b8e0 0x21 ZSNDOBJ (0x44b310),
// 0x4454e0 0x197 (0x4451d0), 0x455660 0xf1 (0x455330), 0x45b6a0 0x650c (0x45b240), 0x45b7e0 0x958 (0x45b3a0).
extern "C" void *ext_45c4f0(u32 size, void *p);
extern "C" void *ext_45c4b0(u32 size);
#define GCTOR(a) extern "C" void *THISCALL ext_##a(void *self, void *parent, void *ci, const char *name);
GCTOR(44b310) GCTOR(4451d0) GCTOR(455330) GCTOR(45b240) GCTOR(45b3a0)
typedef void *(THISCALL *geomCtor)(void *self, void *parent, void *ci, const char *name);
static inline void *makeGeom(u32 size, geomCtor ctor, void *ci, const char *name, void *parent, void *p) {
  void *o = p ? ext_45c4f0(size, p) : ext_45c4b0(size);
  if (!o) return 0;
  return ctor(o, parent, ci, name);
}
static void *FASTCALL newSndObj(void *ci, const char *nm, void *par, void *p) { return makeGeom(0x21, ext_44b310, ci, nm, par, p); }
PCREG(44b8e0, newSndObj);
static void *FASTCALL newGeom197(void *ci, const char *nm, void *par, void *p) { return makeGeom(0x197, ext_4451d0, ci, nm, par, p); }
PCREG(4454e0, newGeom197);
static void *FASTCALL newGeomF1(void *ci, const char *nm, void *par, void *p) { return makeGeom(0xf1, ext_455330, ci, nm, par, p); }
PCREG(455660, newGeomF1);
static void *FASTCALL newGeom650c(void *ci, const char *nm, void *par, void *p) { return makeGeom(0x650c, ext_45b240, ci, nm, par, p); }
PCREG(45b6a0, newGeom650c);
static void *FASTCALL newGeom958(void *ci, const char *nm, void *par, void *p) { return makeGeom(0x958, ext_45b3a0, ci, nm, par, p); }
PCREG(45b7e0, newGeom958);

// 0x442e20, ZTreeGroup::DetachDynamicGeoms(ZBaseGeom*): when the geom's type ([[+0x54]+0xc]+0x23, or 0x200002 without
// +0x54) has bit 0x100000: unless (IsDerivedFrom(0x100020) and (prim slot 0x310, or slot 0x30c with the geom not
// this's +8)), each child of the prim (+0x50, next +0x60) gets own slot 0x2f4. Then a geom other than +8 with flag
// 0x40000 at +0x3c is detached from its dynamic container (0).
extern "C" u8 THISCALL ext_4db9a0(void *g, u32 cls);
extern "C" void THISCALL ext_4da720(void *g, void *grp);
static void THISCALL treeDetachDynGeoms(u8 *self, u8 *g) {
  u8 *p = *(u8 **)(g + 0x54);
  u32 t = p ? *(u32 *)(*(u8 **)(p + 0xc) + 0x23) : 0x200002;
  if (t & 0x100000) {
    if (ext_4db9a0(g, 0x100020)) {
      if (vcall<u8>(p, 0x310)) return;
      if (vcall<u8>(p, 0x30c) && g != *(u8 **)(self + 8)) return;
    }
    for (u8 *q = *(u8 **)(p + 0x50); q; q = *(u8 **)(q + 0x60)) vcall<void>(self, 0x2f4, q);
  }
  if (g != *(u8 **)(self + 8) && (*(u32 *)(g + 0x3c) & 0x40000)) ext_4da720(g, 0);
}
PCREG(442e20, treeDetachDynGeoms);

// 0x4912a0, ZEngineDataBase::GetTreesData(void*, unsigned): the cache file name for 0x68d838 (local MYSTR), then the
// file system's slot 0x60(c_str, buf, size, 0, 0) reads it; the MYSTR is destroyed.
extern "C" void THISCALL ext_48c4b0(void *self, void *str, u32 name);
extern "C" const char *THISCALL ext_4cc1d0(void *str);
extern "C" void THISCALL ext_4cbec0(void *str);
static void THISCALL getTreesData(void *self, void *buf, u32 size) {
  u8 str[0x80];
  ext_48c4b0(self, str, 0x68d838);
  const char *nm = ext_4cc1d0(str);
  vcall<void>(G(void *, 0x700394), 0x60, nm, buf, size, 0u, 0u);
  ext_4cbec0(str);
}
PCREG(4912a0, getTreesData);

// 0x42f6e0, ZSysInterface::ReadNormalToken(string&, char*&, const char*) (this unused): the string is emptied
// (assign of an empty range, 0x5f2d60), then characters are appended until end, ' ', '\t', '\r', '\n' or '$'. When the
// string is full (end + 1 == capacity end) it grows to size + max(size, 1) (0x431270); a terminator is written after
// the end, then the character at the end.
extern "C" void THISCALL ext_5f2d60(void *s, const char *b, const char *e);
extern "C" void THISCALL ext_431270(void *s, u32 cap);
static void THISCALL sysReadNormalToken(void *, u8 **str, u8 **pp, u8 *end) {
  ext_5f2d60(str, (const char *)0x677b5a, (const char *)0x677b5a);
  if (*pp == end) return;
  do {
    u8 ch = **pp;
    if (ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n' || ch == '$') return;
    u8 *e = str[1];
    if (e + 1 == str[2]) {
      u32 sz = (u32)(e - str[0]);
      u32 n = sz < 1 ? 1 : sz;
      ext_431270(str, n - (u32)str[0] + (u32)e);
    }
    u8 *t = str[1] + 1;
    if (t) *t = 0;
    *t = 0;
    *str[1] = ch;
    ++str[1];
    ++*pp;
  } while (*pp != end);
}
PCREG(42f6e0, sysReadNormalToken);

// 0x498e60, ZGeomBuffer::SaveDeletedEvents(ZSaveGame*): section 0xf (slot 8); each deleted-event id of the render
// manager's list (+0xc; iterator slot 0x4c begin, 0x5c next while its first dword is set) is written as 4 bytes
// (slot 0x10); then -1 as the end marker.
static void THISCALL saveDeletedEvents(void *, void *sg) {
  // one frame array: the iterator and the end marker must not share a stack slot (the harness reads stack arguments
  // after the run, and the original keeps them apart)
  u32 fr[5];
  u32 *it = fr;
  vcall<void>(sg, 8, 0xfu);
  if (*(void **)((u8 *)rmgr() + 0xc)) {
    vcall<void>(*(void **)((u8 *)rmgr() + 0xc), 0x4c, it);
    u32 v = vcall<u32>(*(void **)((u8 *)rmgr() + 0xc), 0x5c, it);
    while (it[0]) {
      vcall<void>(sg, 0x10, &v, 4u);
      v = vcall<u32>(*(void **)((u8 *)rmgr() + 0xc), 0x5c, it);
    }
  }
  fr[4] = 0xffffffffu;
  vcall<void>(sg, 0x10, &fr[4], 4u);
}
PCREG(498e60, saveDeletedEvents);

// 0x616620 (no map name; GUESS: constructor, vtables 0x6bdc58 then 0x6bdc8c): +4 = a, +8..+0x10 cleared, 0x659330 on
// +8 with (word +0xe of [[b+0x10]+8], [c+0xb9a8]); flag 0x1000000 or-ed into [[b+0xc]+0x38]+0x3c. Returns this.
extern "C" void THISCALL ext_659330(void *o, u32 a, u32 b);
static void *THISCALL ctor6bdc58(u8 *self, u32 a, u8 *b, u8 *c) {
  *(u32 *)(self + 4) = a;
  *(u32 *)self = 0x6bdc58;
  *(u32 *)(self + 8) = 0;
  *(u32 *)(self + 0xc) = 0;
  *(u32 *)(self + 0x10) = 0;
  u32 cv = *(u32 *)(c + 0xb9a8);
  u32 w = *(u16 *)(*(u8 **)(*(u8 **)(b + 0x10) + 8) + 0xe);
  ext_659330(self + 8, w, cv);
  *(u32 *)(*(u8 **)(*(u8 **)(b + 0xc) + 0x38) + 0x3c) |= 0x1000000;
  *(u32 *)self = 0x6bdc8c;
  return self;
}
PCREG(616620, ctor6bdc58);
