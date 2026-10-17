// batch0606.cpp - fresh-06 batch 6 (docs/20-fresh-06.md). Callee pop counts from tools/rets.py.
#include "ff.h"

extern "C" void ext_634273(void *p, u32 size);       // __builtin_delete (cdecl)
extern "C" void *ext_41e290(u32 n);                  // __builtin_new (cdecl)
extern "C" void THISCALL ext_469870(void *self);
extern "C" void THISCALL ext_610100(void *self, void *db);
extern "C" u32 THISCALL ext_4e5e60(void *db);        // DBREAD::operator unsigned int()
extern "C" void *THISCALL ext_5003d0(void *arr, u32 i);
static inline void *rmgr() { return *(void **)(G(u8 *, 0x70039c) + 0x9b); }
static inline void *rmAlloc(u32 arg) { return vcall<void *>(*(void **)((u8 *)rmgr() + 8), 0x44, arg); }

// 0x576120, ZSubZoneMap::CopyEventDataBlock(DBREAD&): base, then three ids read in order, each resolved with the
// render manager's slot 0x58, to +0x1dc, +0x221, +0x225.
static void THISCALL subZoneCopyEvent(u8 *self, void *db) {
  ext_610100(self, db);
  u32 a = ext_4e5e60(db), b = ext_4e5e60(db), c = ext_4e5e60(db);
  *(u32 *)(self + 0x1dc) = vcall<u32>(rmgr(), 0x58, a);
  *(u32 *)(self + 0x221) = vcall<u32>(rmgr(), 0x58, b);
  *(u32 *)(self + 0x225) = vcall<u32>(rmgr(), 0x58, c);
}
PCREG(576120, subZoneCopyEvent);

// 0x5c5360 (no map name; GUESS: factory, vtable 0x6b4180): as 0x4cabe0 plus +0x14e = 0 and byte +0x152 = 0.
static void *THISCALL new6b4180(u32 ecx) {
  u8 *p = (u8 *)rmAlloc(ecx);
  if (p) {
    ext_469870(p);
    *(u32 *)(p + 4) |= 0x20;
    *(u32 *)(p + 0x44) = 0;
    *(u32 *)p = 0x6b4180;
    *(u32 *)(p + 0x14e) = 0;
    p[0x152] = 0;
  }
  return p;
}
PCREG(5c5360, new6b4180);

// 0x607da0 (no map name; GUESS: vertex buffer wrapper init): fields set (+0x12 = 100, +0x16 = 6, +0x1a = usage | 0x208,
// +0x22 = count * 36, +0x26 = *fvf, +4 = count, word +0x10 = 0x100, the rest of +0..+0x29 zero), then the device's
// slot 0x5c (COM stdcall: dev, count * 36, usage, fvf, 0, this) creates it. Returns this.
static void *THISCALL vbInit(u8 *self, void *dev, const u32 *fvf, const u32 *count, u32 usage) {
  *(u32 *)self = 0;
  *(u32 *)(self + 8) = 0;
  *(u16 *)(self + 0x10) = 0x100;
  *(u32 *)(self + 0xc) = 0;
  *(u32 *)(self + 4) = *count;
  for (int i = 0x12; i < 0x2a; ++i) self[i] = 0;
  *(u32 *)(self + 0x12) = 0x64;
  u32 n = *count;
  *(u32 *)(self + 0x16) = 6;
  *(u32 *)(self + 0x1e) = 0;
  *(u32 *)(self + 0x22) = n * 36;
  *(u32 *)(self + 0x26) = *fvf;
  u32 fv = *(u32 *)(self + 0x26);
  u32 us = usage | 0x208;
  *(u32 *)(self + 0x1a) = us;
  typedef u32(STDCALL * f5c)(void *, u32, u32, u32, u32, void *);
  (*(f5c *)(*(u8 **)dev + 0x5c))(dev, *(u32 *)(self + 4) * 36, us, fv, 0, self);
  return self;
}
PCREG(607da0, vbInit);

// 0x51a960 (no map name; GUESS: constructor, vtable 0x69f364): base ctor 0x519330(a, b); 0x51ace0 unless 0x701730 is
// set; the id read through [a+0x15] slot 0x40 (into the b argument's slot) is resolved with the render manager's
// slot 0x58 to +0x18. Returns this.
extern "C" void THISCALL ext_519330(void *self, void *a, u32 b);
extern "C" void THISCALL ext_51ace0(void *self);
static void *THISCALL ctor69f364(u8 *self, u8 *a, u32 b) {
  ext_519330(self, a, b);
  u32 flag = G(u32, 0x701730);
  *(u32 *)self = 0x69f364;
  if (!flag) ext_51ace0(self);
  vcall<void>(*(void **)(a + 0x15), 0x40, &b);
  *(u32 *)(self + 0x18) = vcall<u32>(rmgr(), 0x58, b);
  return self;
}
PCREG(51a960, ctor69f364);

// 0x490c60, ZEngineDataBase::GetRoomInsideTreeSize(): the cache file name for 0x68d834 (CalcCacheFileName into a
// local MYSTR), its c_str (0x4cc1d0) and 0 go to the file system's slot 0x30 (size); the MYSTR is destroyed.
// Returns the size.
extern "C" void THISCALL ext_48c4b0(void *self, void *str, u32 name);
extern "C" const char *THISCALL ext_4cc1d0(void *str);
extern "C" void THISCALL ext_4cbec0(void *str);
static u32 THISCALL roomInsideTreeSize(void *self) {
  u8 str[0x80];
  ext_48c4b0(self, str, 0x68d834);
  void *fs = G(void *, 0x700394);
  const char *nm = ext_4cc1d0(str);
  u32 r = vcall<u32>(G(void *, 0x700394), 0x30, nm, 0u);
  (void)fs;
  ext_4cbec0(str);
  return r;
}
PCREG(490c60, roomInsideTreeSize);

// 0x4444a0, ZROOM::FreeDynamicGeomList(): with a list at +0xa8: while its count (slot 0x14) is nonzero, the first item
// (slot 0x4c begin, slot 0x5c get; iterator first dword nonzero) gets own slot 0x36c and RemoveFromRoomList(this);
// then the list is deleted (slot 0 with 1) and +0xa8 cleared.
extern "C" void THISCALL ext_4dc1e0(void *g, void *room);
static void THISCALL roomFreeDynGeoms(u8 *self) {
  if (!*(void **)(self + 0xa8)) return;
  if (vcall<u32>(*(void **)(self + 0xa8), 0x14)) {
    do {
      if (*(void **)(self + 0xa8)) {
        u32 it[3];
        vcall<void>(*(void **)(self + 0xa8), 0x4c, it);
        void *g = vcall<void *>(*(void **)(self + 0xa8), 0x5c, it);
        if (it[0]) {
          vcall<void>(self, 0x36c, g);
          ext_4dc1e0(g, self);
        }
      }
    } while (vcall<u32>(*(void **)(self + 0xa8), 0x14));
  }
  void *l = *(void **)(self + 0xa8);
  if (l) vcall<void>(l, 0, 1u);
  *(u32 *)(self + 0xa8) = 0;
}
PCREG(4444a0, roomFreeDynGeoms);

// 0x600be0 (no map name; GUESS: constructor, vtable 0x6b96fc, a 10-entry pointer array): base 0x5fa5d0; capacity 10 at
// +8, count +0xc = 0, a new 40-byte array at +4, +0x10 = this+4, +0x14 = 0, byte +0x18 = 0. Returns this.
extern "C" void THISCALL ext_5fa5d0(void *self);
static void *THISCALL ctor6b96fc(u8 *self) {
  ext_5fa5d0(self);
  *(u32 *)self = 0x6b96fc;
  *(u32 *)(self + 8) = 0xa;
  *(u32 *)(self + 0xc) = 0;
  *(void **)(self + 4) = ext_41e290(40);
  *(u8 **)(self + 0x10) = self + 4;
  *(u32 *)(self + 0x14) = 0;
  self[0x18] = 0;
  return self;
}
PCREG(600be0, ctor6b96fc);

// 0x44c060, ZSNDOBJ::Free(): with a sound system (engine +0x1a9f) and an id (+0x1c), the render manager's slot 0x60
// gives the sound; its +0 is cleared; when its +0x10 is set it is shut down (0x44b610) and released to the sound system
// (re-read; slot 0x118).
extern "C" void THISCALL ext_44b610(void *s);
static void THISCALL sndobjFree(u8 *self) {
  u8 *eng = G(u8 *, 0x70039c);
  if (!*(u32 *)(eng + 0x1a9f)) return;
  u32 id = *(u32 *)(self + 0x1c);
  if (!id) return;
  u8 *s = vcall<u8 *>(*(void **)(eng + 0x9b), 0x60, id);
  if (!s) return;
  u32 z = *(u32 *)(s + 0x10);
  *(u32 *)s = 0;
  if (!z) return;
  ext_44b610(s);
  void *ss = *(void **)(G(u8 *, 0x70039c) + 0x1a9f);
  if (ss) vcall<void>(ss, 0x118, s);
}
PCREG(44c060, sndobjFree);

// 0x63af20, ZDrawArray<ZRoomDrawEntry,...>::Add(): finds a block with a free slot as 0x63ade0 (or makes one with
// ConstructorCall); takes slot idx = word +2 of the block (0xffff: 0), entry = block+0x10+idx*0x4c: the free list
// moves on to the entry's first word, entry +0 = 0, +4 = 0xffff1202, +0x38 = 0, byte +0x43 = 0, block count (+0) + 1.
extern "C" u8 THISCALL ext_63b440(void *self);
static u8 *THISCALL roomDrawArrayAdd(u8 *self) {
  u8 *first = *(u8 **)(self + 8);
  u8 *b = 0;
  if (first) {
    for (;;) {
      u8 *x = *(u8 **)(self + 8);
      if (*(u16 *)(x + 2) != 0xffff) { b = x; break; }
      u8 *n = *(u8 **)(x + 8);
      *(u8 **)(self + 8) = n;
      if (first == n || !n) break;
    }
  }
  if (!b) {
    if (!ext_63b440(self)) return 0;
    b = *(u8 **)(self + 8);
  }
  ++*(u32 *)(self + 0xc);
  u16 idx = *(u16 *)(b + 2);
  if (idx == 0xffff) return 0;
  u8 *e = b + 0x10 + idx * 0x4c;
  *(u16 *)(b + 2) = *(u16 *)e;
  *(u32 *)e = 0;
  *(u32 *)(e + 4) = 0xffff1202u;
  *(u32 *)(e + 0x38) = 0;
  e[0x43] = 0;
  ++b[0];
  return e;
}
PCREG(63af20, roomDrawArrayAdd);

// 0x5007e0, TriggerEventTranslator_t::handleEventTranslation(ScriptEventFactory_t*, unsigned, void*) (stdcall): the
// factory's slot 0x18 makes the event; the trigger geom (render manager slot 0x58 of data) gives its name (+4), or a
// local copy of the 25-byte default at 0x69c948; argument 0 (event slot 0x4c, then 0x5003d0) gets it (slot 0x30).
// Returns the event.
static void *STDCALL trigTranslate(void *fac, u32 id, u32 data) {
  void *ev = vcall<void *>(fac, 0x18, id);
  if (!ev) return 0;
  u8 *g = vcall<u8 *>(rmgr(), 0x58, data);
  char buf[25];
  const char *nm;
  if (g) {
    nm = *(const char **)(g + 4);
  } else {
    for (int i = 0; i < 25; ++i) buf[i] = G(char, 0x69c948 + i);
    nm = buf;
  }
  void *arr = vcall<void *>(ev, 0x4c);
  void **slot = (void **)ext_5003d0(arr, 0);
  vcall<void>(*slot, 0x30, nm);
  return ev;
}
PCREG(5007e0, trigTranslate);

// 0x610ea0 (no map name; GUESS: set the D3D viewport): x, y, w, h (floats) are converted with the CRT float-to-int
// (0x633910, XMM0 in, EAX out), min z 0 and max z 1.0 added; the device (+0x1377) slot 0xa0 (COM stdcall) gets the
// 24-byte viewport.
extern "C" u32 VECTORCALL ext_633910(float f);
static void THISCALL setViewport(u8 *self, float x, float y, float w, float h) {
  u32 vp[6];
  vp[0] = ext_633910(x);
  vp[1] = ext_633910(y);
  vp[2] = ext_633910(w);
  vp[3] = ext_633910(h);
  vp[4] = 0;
  vp[5] = 0x3f800000u;
  void *dev = *(void **)(self + 0x1377);
  typedef u32(STDCALL * fa0)(void *, u32 *);
  (*(fa0 *)(*(u8 **)dev + 0xa0))(dev, vp);
}
PCREG(610ea0, setViewport);
