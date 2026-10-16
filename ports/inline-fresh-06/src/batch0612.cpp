// batch0612.cpp - fresh-06 batch 12 (docs/20-fresh-06.md). Callee pop counts from tools/rets.py.
#include "ff.h"

static inline void *rmgr() { return *(void **)(G(u8 *, 0x70039c) + 0x9b); }
extern "C" void ext_634273(void *p, u32 size);       // __builtin_delete (cdecl, sized)
typedef void (*hfn)();
static inline void handlerCall() {
  hfn h = G(hfn, 0x7003b0);
  if (!h) asm volatile("int3");
  h();
}

// 0x4599e0, ZCubeGridParticles::DrawBufferViewUpdate(ZDrawBuffer*, ZCAMERA*): with the buffer's matrices A (slot 0x3c)
// and B (slot 0x40): d = (B pos - A pos) (PSVECSubtract, positions at +0x24) times B (vmtmul); M = A * B (mmtmul), copied
// (mcpy); own slot 0x80(M, d), camera slot 0x94(M, d), own slot 0xdc(buffer, camera, M, d). Returns false (only AL
// changes: the upper EAX bytes are slot 0xdc's).
extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);
extern "C" void FASTCALL ext_441a60(float *v, const float *m);
extern "C" void FASTCALL ext_4de4b0(float *d, const float *a, const float *b);
extern "C" void FASTCALL ext_4de420(float *d, const float *s);
static u32 THISCALL cubeGridViewUpdate(u8 *self, u8 *buf, u8 *cam) {
  float f[0x1b];
  float *d = f, *mm = f + 5, *m = f + 0xe, *v = f + 0x17;
  u8 *a = vcall<u8 *>(buf, 0x3c);
  u8 *b = vcall<u8 *>(buf, 0x40);
  ext_43e920(d, (const float *)(a + 0x24), (const float *)(b + 0x24));
  ext_441a60(d, (const float *)b);
  ext_4de4b0(mm, (const float *)a, (const float *)b);
  ext_4de420(m, mm);
  v[0] = d[0];
  v[1] = d[1];
  v[2] = d[2];
  vcall<void>(self, 0x80, m, v);
  vcall<void>(cam, 0x94, m, v);
  u32 r = vcall<u32>(self, 0xdc, buf, cam, m, v);
  return r & 0xffffff00u;
}
PCREG(4599e0, cubeGridViewUpdate);

// 0x4ca820, ZSetZDefine::Init(): the define's value is the object at +0x44 (or, with byte +0x48 set, its slot 0x20);
// the render manager's object (slot 0x138) gets slot 0x60(name, render manager slot 0x4c(value), 2), where the name is
// the string at +0x49 when non-empty, else the object's +4. (The 2 is pushed before slot 0x4c's one argument.) The
// string at +0x49 is then deleted (size 1), and own slot 0x58 runs.
static void THISCALL setZDefineInit(u8 *self) {
  u32 val = *(u32 *)(self + 0x44);
  if (self[0x48]) val = vcall<u32>(*(void **)(self + 0x44), 0x20);
  const char *s = *(const char **)(self + 0x49);
  if (s && *s) {
    void *o = vcall<void *>(rmgr(), 0x138);
    u32 x = vcall<u32>(rmgr(), 0x4c, val);
    vcall<void>(o, 0x60, *(u32 *)(self + 0x49), x, 2u);
  } else {
    void *o = vcall<void *>(rmgr(), 0x138);
    u32 nm = *(u32 *)(*(u8 **)(self + 0x44) + 4);
    u32 x = vcall<u32>(rmgr(), 0x4c, val);
    vcall<void>(o, 0x60, nm, x, 2u);
  }
  void *p = *(void **)(self + 0x49);
  if (p) ext_634273(p, 1);
  vcall<void>(self, 0x58);
}
PCREG(4ca820, setZDefineInit);

// 0x4cb720, ZViewNotify::End(): each entry of the list at +0x54 (slot 0x4c begin, slot 0x64 next) with byte +4 set
// whose geom (render manager slot 0x58(entry id)) exists gets SendCommand (slot 0x130: geom, word +0x52, +0x44). The
// list is deleted (slot 0 with 1); the +0x64 blocks of the array at +0x68 (0x20 bytes each) and the array (4) are
// deleted, then the buffer at +0x6c (4).
static void THISCALL viewNotifyEnd(u8 *self) {
  if (*(void **)(self + 0x54)) {
    u32 it[3];
    vcall<void>(*(void **)(self + 0x54), 0x4c, it);
    for (u32 *e = vcall<u32 *>(*(void **)(self + 0x54), 0x64, it); e; e = vcall<u32 *>(*(void **)(self + 0x54), 0x64, it)) {
      if (!((u8 *)e)[4]) continue;
      void *g = vcall<void *>(rmgr(), 0x58, e[0]);
      if (g) vcall<void>(g, 0x130, g, (u32)*(u16 *)(self + 0x52), *(u32 *)(self + 0x44));
    }
  }
  if (*(void **)(self + 0x54)) vcall<void>(*(void **)(self + 0x54), 0, 1u);
  if (*(void **)(self + 0x68)) {
    for (u32 i = 0; i != *(u32 *)(self + 0x64); ++i) ext_634273((*(void ***)(self + 0x68))[i], 0x20);
    ext_634273(*(void **)(self + 0x68), 4);
  }
  if (*(void **)(self + 0x6c)) ext_634273(*(void **)(self + 0x6c), 4);
}
PCREG(4cb720, viewNotifyEnd);

// 0x63f3e0 (no map name; GUESS: get or create the draw slot of a light/prim, thiscall (item, unused)): an item with a
// slot id (word +0x40) returns table[id & 0xfff] (+0x68). Else the pool (+0x22c, slot 8) gives an object (none: 0);
// the id is ZAllocIndex::New(+0xb990) + 1 masked to 12 bits (0 calls the handler; int3 when none, not exercised), the
// object is stored there, the id in the item and the item in the object (+0xc). An item with a nonzero float at +0x18
// or +0x1c (NaN counts) is appended to the 16-entry list at +0x174 (count +0x170; a full list calls the handler first).
// Own slot 0xb0(object) runs. Returns the object.
extern "C" u32 THISCALL ext_4ce7b0(void *ai);
static void *THISCALL drawSlotGet(u8 *self, u8 *item, u32) {
  u16 id = *(u16 *)(item + 0x40);
  if (id) return (*(void ***)(self + 0x68))[id & 0xfff];
  u8 *o = vcall<u8 *>(*(void **)(self + 0x22c), 8);
  if (!o) return 0;
  u32 k = (ext_4ce7b0(self + 0xb990) + 1) & 0xfff;
  if (!k) handlerCall();
  (*(void ***)(self + 0x68))[k] = o;
  *(u16 *)(item + 0x40) = (u16)k;
  *(u8 **)(o + 0xc) = item;
  if (*(float *)(item + 0x18) != 0.0f || *(float *)(item + 0x1c) != 0.0f) {
    if (*(u32 *)(self + 0x170) + 1 > 0x10) handlerCall();
    *(u8 **)(self + 0x174 + *(u32 *)(self + 0x170) * 4) = o;
    ++*(u32 *)(self + 0x170);
  }
  vcall<void>(self, 0xb0, o);
  return o;
}
PCREG(63f3e0, drawSlotGet);

// 0x53b2a0, CEVENTCONTROLLER::Save(ZSaveGame*): a local REFTAB32 collects render manager slot 0x4c(+4) of each entry of
// the list at +4 (slot 0x4c begin, slot 0x64 next); the save game's slot 0x6c writes it; the table is destroyed.
// Returns true.
extern "C" void THISCALL ext_4ccba0(void *t);
extern "C" void THISCALL ext_4cd540(void *t, u32 v);
extern "C" void THISCALL ext_4ccf60(void *t);
static u8 THISCALL eventCtlSave(u8 *self, void *sg) {
  u32 fr[0x2e];
  u32 *it = fr, *tab = fr + 3;
  ext_4ccba0(tab);
  if (*(void **)(self + 4)) {
    vcall<void>(*(void **)(self + 4), 0x4c, it);
    for (u8 *e = vcall<u8 *>(*(void **)(self + 4), 0x64, it); e; e = vcall<u8 *>(*(void **)(self + 4), 0x64, it))
      ext_4cd540(tab, vcall<u32>(rmgr(), 0x4c, *(u32 *)(e + 4)));
  }
  vcall<void>(sg, 0x6c, tab);
  ext_4ccf60(tab);
  return 1;
}
PCREG(53b2a0, eventCtlSave);

// 0x498be0, ZGeomBuffer::SaveAllEvents(SWorkSaveVars*): SaveEvents for the root geom ([render manager +0xadc] +8),
// then for every set bit of the vars' mask bytes (+8, count +0xc) whose geom (array [+0x14]+4, 0x70 bytes each, 8 per
// byte) lacks flag 0x4000000 at +0x3c, SaveEvents for its top parent (+0x50 chain). Then the stream ([vars]) gets
// slot 8(0xd) and slot 0x10(&-1, 4).
extern "C" void THISCALL ext_498f00(void *self, void *vars, void *g);
static void THISCALL geomBufSaveAllEvents(u8 *self, u8 *vars) {
  ext_498f00(self, vars, *(void **)(*(u8 **)((u8 *)rmgr() + 0xadc) + 8));
  for (u32 i = 0; i != *(u32 *)(vars + 0xc); ++i) {
    u32 mask = (*(u8 **)(vars + 8))[i];
    if (!mask) continue;
    u8 *g = *(u8 **)(*(u8 **)(self + 0x14) + 4) + i * 0x380;
    for (u32 bit = 1; bit <= 0x80; bit += bit, g += 0x70) {
      if (!(mask & bit) || (*(u32 *)(g + 0x3c) & 0x4000000)) continue;
      u8 *r = g;
      while (*(u8 **)(r + 0x50)) r = *(u8 **)(r + 0x50);
      ext_498f00(self, vars, r);
      mask = (*(u8 **)(vars + 8))[i];
    }
  }
  vcall<void>(*(void **)vars, 8, 0xdu);
  u32 m1 = 0xffffffffu;
  vcall<void>(*(void **)vars, 0x10, &m1, 4u);
}
PCREG(498be0, geomBufSaveAllEvents);
