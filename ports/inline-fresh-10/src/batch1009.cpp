// batch1009.cpp - fresh-10 batch 9: geom destructors and factories, loads, key lookup, zip EOCD (slice 10).
#include "ff.h"

#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define SCENE (*(u8 **)(*(u8 **)0x70039c + 0x9b))
extern "C" void ext_634273(void *p, u32 n);   // operator delete (cdecl)
extern "C" void ext_4690b0(void *p, u32 n);   // ZOctreeFuskeBaseKlasse::lort (cdecl; the exe body is only `ret`)
extern "C" void THISCALL ext_4cbec0(void *);  // MYSTR::~MYSTR

// The geom destructor tail shared by 0x4a79a0, 0x4ca9a0 and 0x4b1ae0 (scalar deleting, SEH frame): +0x44 = 0,
// +0x30 = 0, base vtable 0x686874, scene.slot34(this); with flag 1: flag 4 gives lort(this, size), else the assert
// hook [0x7003b0] (int3 when it is null). Returns this.
typedef void (*hook_t)();
static inline u8 *GeomDtorTail(u8 *self, u32 flags, u32 size) {
  F32(self, 0x44) = 0;
  F32(self, 0x30) = 0;
  F32(self, 0) = 0x686874;
  vcall<void>(SCENE, 0x34, self);
  if (flags & 1) {
    if (flags & 4) {
      ext_4690b0(self, size);
    } else {
      hook_t h = G(hook_t, 0x7003b0);
      if (!h) asm volatile("int3");
      h();
    }
  }
  return self;
}

// 0x4a79a0 ZGeomSpawn::~ZGeomSpawn() (medium; scalar deleting): size 0x81.
static u8 *THISCALL GeomSpawnDtor(u8 *self, u32 flags) { return GeomDtorTail(self, flags, 0x81); }
PCREG(4a79a0, GeomSpawnDtor);

// 0x4ca9a0 ZScrollTexture::~ZScrollTexture() (medium; scalar deleting): size 0x94.
static u8 *THISCALL ScrollTextureDtor(u8 *self, u32 flags) { return GeomDtorTail(self, flags, 0x94); }
PCREG(4ca9a0, ScrollTextureDtor);

// 0x4b1ae0 CExternCutSequenceCommand::~CExternCutSequenceCommand() (low; scalar deleting): ~MYSTR(+0x56) first, size 0xde.
static u8 *THISCALL ExternCutSeqDtor(u8 *self, u32 flags) {
  ext_4cbec0(self + 0x56);
  return GeomDtorTail(self, flags, 0xde);
}
PCREG(4b1ae0, ExternCutSeqDtor);

// The scene factory shared by 0x4ae520, 0x4be7e0, 0x4caae0 and 0x4c87e0 (SEH frame): o = [scene+8].slot44(ecx); if o:
// 0x469870(o) (base ctor), +4 |= 0x20, +0x44 = 0, vtable. ECX is passed straight through as the slot44 argument (GUESS
// that it is a class or size id; the caller's ECX is all the exe pushes).
extern "C" void THISCALL ext_469870(void *);
static inline u8 *SceneCreate(u32 arg, u32 vt) {
  u8 *o = vcall<u8 *>(*(void **)(SCENE + 8), 0x44, arg);
  if (o) {
    ext_469870(o);
    F32(o, 4) |= 0x20;
    F32(o, 0x44) = 0;
    F32(o, 0) = vt;
  }
  return o;
}
static u8 *THISCALL Create4ae520(u32 a) { return SceneCreate(a, 0x690cc0); }
PCREG(4ae520, Create4ae520);
static u8 *THISCALL Create4be7e0(u32 a) { return SceneCreate(a, 0x693028); }
PCREG(4be7e0, Create4be7e0);
static u8 *THISCALL Create4caae0(u32 a) { return SceneCreate(a, 0x69523c); }
PCREG(4caae0, Create4caae0);
// 0x4c87e0: same with vtable 0x694d40 and +0x59 = 0.
static u8 *THISCALL Create4c87e0(u32 a) {
  u8 *o = SceneCreate(a, 0x694d40);
  if (o) F32(o, 0x59) = 0;
  return o;
}
PCREG(4c87e0, Create4c87e0);

// 0x5eef20 CMessageBomb::Load(ZLoadGame*) (medium): g.slot68(+0x10); +0x11, +0x15 = g.slot40 (read dword);
// g.slot48(+0x19); g.slot48(+0x1d); CreateSprites(); the sprites +4, +8, +0xc each get slotc(g).
extern "C" void THISCALL ext_5eecd0(void *);
static void THISCALL MessageBombLoad(u8 *self, void *g) {
  vcall<void>(g, 0x68, self + 0x10);
  u32 v;
  vcall<void>(g, 0x40, &v);
  F32(self, 0x11) = v;
  vcall<void>(g, 0x40, &v);
  F32(self, 0x15) = v;
  vcall<void>(g, 0x48, self + 0x19);
  vcall<void>(g, 0x48, self + 0x1d);
  ext_5eecd0(self);
  vcall<void>(*(void **)(self + 4), 0xc, g);
  vcall<void>(*(void **)(self + 8), 0xc, g);
  vcall<void>(*(void **)(self + 0xc), 0xc, g);
}
PCREG(5eef20, MessageBombLoad);

// 0x432560 CConfiguration::GetKeyMapping(const char*, const SActionOverride*) const (high): walk the mapping list
// (+0x84; slot4c begin, slot64 next). Each entry whose name (first dword) matches (striwcmp == 0) is returned when
// `take` is set; take starts as (ovr == 0) and becomes (entry == ovr) at each non-taken match. None: 0.
extern "C" s32 FASTCALL ext_4cc850(const char *, const char *);
static u8 *THISCALL GetKeyMapping(u8 *self, const char *name, void *ovr) {
  u8 *l = self + 0x84;
  bool take = ovr == 0;
  u32 it[3];
  vcall<void>(l, 0x4c, it);
  for (u8 *e = vcall<u8 *>(l, 0x64, it); e; e = vcall<u8 *>(l, 0x64, it)) {
    if (ext_4cc850(*(const char **)e, name) == 0) {
      if (take) return e;
      take = ovr == e;
    }
  }
  return 0;
}
PCREG(432560, GetKeyMapping);

// 0x5510e0 Signature_fff_EventTranslator_t::handleEventTranslation(ScriptEventFactory_t*, unsigned, void*) (low; stdcall):
// ev = factory.slot18(id); if ev: args = ev.slot4c(); for i in 0..2: 0x500360(0x5003d0(args, i), data[i] float).
extern "C" void *THISCALL ext_5003d0(void *, u32);
extern "C" void THISCALL ext_500360(void *, u32);   // takes a float; passed as its bits (a copy, like the exe's movss)
static void *STDCALL HandleEventFFF(void *factory, u32 id, u32 *data) {
  void *ev = vcall<void *>(factory, 0x18, id);
  if (!ev) return 0;
  void *a = vcall<void *>(ev, 0x4c);
  ext_500360(ext_5003d0(a, 0), data[0]);
  ext_500360(ext_5003d0(a, 1), data[1]);
  ext_500360(ext_5003d0(a, 2), data[2]);
  return ev;
}
PCREG(5510e0, HandleEventFFF);

// 0x5708a0 CSewerMenu::Init() (medium): ZVideoSelector::Init(); o = scene.slot138(); x = scene.slot4c(+0x44, 0x10);
// o.slot60(+0x1a3 ? 0x6a86e0 : 0x6a86ec, x).
extern "C" void THISCALL ext_562440(void *);
static void THISCALL SewerMenuInit(u8 *self) {
  ext_562440(self);
  u32 str = self[0x1a3] ? 0x6a86e0 : 0x6a86ec;
  void *o = vcall<void *>(SCENE, 0x138);
  u32 x = vcall<u32>(SCENE, 0x4c, F32(self, 0x44), 0x10u);
  vcall<void>(o, 0x60, str, x);
}
PCREG(5708a0, SewerMenuInit);

// 0x4d7ba0 FsZip_t::writeEOCD() (low): through the file +0x15 (slot18(buf, n, handle +0x11)): signature 0x06054b50,
// the 18 bytes at +0x22, tag 0x52756e65 ("eunR"), the 18 bytes at +0x34; any short write sets +0x6e = 1.
static void THISCALL ZipWriteEOCD(u8 *self) {
  u32 sig = 0x6054b50;
  if (vcall<u32>(*(void **)(self + 0x15), 0x18, &sig, 4u, F32(self, 0x11)) != 4) self[0x6e] = 1;
  if (vcall<u32>(*(void **)(self + 0x15), 0x18, self + 0x22, 0x12u, F32(self, 0x11)) != 0x12) self[0x6e] = 1;
  sig = 0x52756e65;
  if (vcall<u32>(*(void **)(self + 0x15), 0x18, &sig, 4u, F32(self, 0x11)) != 4) self[0x6e] = 1;
  if (vcall<u32>(*(void **)(self + 0x15), 0x18, self + 0x34, 0x12u, F32(self, 0x11)) != 0x12) self[0x6e] = 1;
}
PCREG(4d7ba0, ZipWriteEOCD);

// 0x4d8e60 GUESS: empty the list [this] (head +4, end +8): for each head entry e, its sublist s (+0x11): unless the
// byte flag +4 is set, delete(*x, 0) for every item; s.slot0(1); then list.slot4(e) removes it. Finally word +4 = 0.
static void THISCALL ClearList4d8e60(u8 *self) {
  for (;;) {
    u8 *l = *(u8 **)self;
    u8 *e = *(u8 **)(l + 4);
    if (e == *(u8 **)(l + 8) || !e) break;
    void *s = *(void **)(e + 0x11);
    if (s) {
      if (!self[4]) {
        u32 it[3];
        vcall<void>(s, 0x4c, it);
        for (void **x = vcall<void **>(s, 0x64, it); x; x = vcall<void **>(s, 0x64, it)) ext_634273(*x, 0);
      }
      vcall<void>(s, 0, 1u);
    }
    vcall<void>(*(void **)self, 4, e);
  }
  *(u16 *)(self + 4) = 0;
}
PCREG(4d8e60, ClearList4d8e60);

// 0x490de0 ZEngineDataBase::GetSoundDataSize() (medium; thiscall, ECX passed on): MYSTR s = CalcCacheFileName(0x68d854);
// r = [0x700394].slot30(s.c_str(), 0); ~MYSTR(s); return r.
extern "C" void THISCALL ext_48c4b0(void *, void *, u32);
static u32 THISCALL GetSoundDataSize(void *self) {
  u8 s[0x80];
  ext_48c4b0(self, s, 0x68d854);
  void *fs = G(void *, 0x700394);
  u32 r = vcall<u32>(fs, 0x30, *(u32 *)s, 0u);
  ext_4cbec0(s);
  return r;
}
PCREG(490de0, GetSoundDataSize);

// 0x433d20 GUESS constructor (CConfiguration-derived, vtable 0x67a2a4; SEH frame): CConfiguration(); +4 = MYSTR(0x67a390).
extern "C" void THISCALL ext_431630(void *);
extern "C" void THISCALL ext_4cbe80(void *, u32);
extern "C" void THISCALL ext_4cbee0(void *, void *);
static u8 *THISCALL Config433d20(u8 *self) {
  ext_431630(self);
  F32(self, 0) = 0x67a2a4;
  u8 t[0x80];
  ext_4cbe80(t, 0x67a390);
  ext_4cbee0(self + 4, t);
  ext_4cbec0(t);
  return self;
}
PCREG(433d20, Config433d20);
