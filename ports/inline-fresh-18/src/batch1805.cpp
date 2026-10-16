// batch1805.cpp - fresh-18 batch 5 (slice 18): engine-allocated factories, SEH destructors, event translators,
// loaders/savers, small math.
// SEH frames and stack cookies of the exe are not reproduced (they leave no state behind on return).
#include "ff.h"

static inline u8 *engineObj9b() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
typedef void (*voidfn)();
static inline void ffAssert() {
  voidfn h = G(voidfn, 0x7003b0);
  if (h) h(); else __builtin_debugtrap();
}
typedef void (*cdeclLog3)(void *, u32, u32);

extern "C" void THISCALL ext_469870(void *self);
extern "C" void THISCALL ext_548ca0(void *self);
extern "C" void THISCALL ext_5bde30(void *self);                  // CCivilianPathList::CCivilianPathList
extern "C" void THISCALL ext_561020(void *self);                  // CBaseWindow::CBaseWindow
extern "C" void ext_634273(void *p, u32 size);                    // operator delete(p, size), cdecl
extern "C" void THISCALL ext_659c00(void *self);
extern "C" void THISCALL ext_659bb0(void *self);
extern "C" void THISCALL ext_4a7fb0(void *self, u32 db);          // ZGeomSpawn::ReadInput
extern "C" void *THISCALL ext_5003d0(void *self, u32 idx);
extern "C" void THISCALL ext_5002f0(void *self, u32 v);
extern "C" void THISCALL ext_500360(void *self, u32 fbits);       // float parameter (bits)
extern "C" void THISCALL ext_63f600(void *self, void *e);         // ZDrawBase::PrimInstanceLeave
extern "C" void THISCALL ext_4ce1c0(void *self, u32 off, u32 size);
extern "C" void *ext_41e290(u32 size);                            // operator new, cdecl
extern "C" void THISCALL ext_4fdb70(void *self);
extern "C" void *THISCALL ext_6014a0(void *self, u32 size);       // CHostInterface::alloc
extern "C" void THISCALL ext_5f10c0(void *self, u32 a);
extern "C" void THISCALL ext_54f870(void *self, u32 p, u32 n);

// Engine allocator: engine(+0x9b)+8 object's slot 0x44. It is given the caller's incoming ECX as its one stack word
// (the exe pushes ECX; the epilogue balance shows the callee pops 4).
static inline u8 *engineAlloc(u32 ecxIn) { return vcall<u8 *>(*(void **)(engineObj9b() + 8), 0x44, ecxIn); }
static inline u8 *geomFactory(u32 ecxIn, u32 vt) {
  u8 *o = engineAlloc(ecxIn);
  if (o) {
    ext_469870(o);
    *(u32 *)(o + 4) |= 0x20;
    *(u32 *)(o + 0x44) = 0;
    *(u32 *)o = vt;
  }
  return o;
}
// GUESS factories (engine-allocated, base 0x469870), one per class vtable.
static u8 *THISCALL f4baee0(u32 e) { return geomFactory(e, 0x692b7c); }
PCREG(4baee0, f4baee0);
static u8 *THISCALL f4be860(u32 e) { return geomFactory(e, 0x692e2c); }
PCREG(4be860, f4be860);
static u8 *THISCALL f4cab60(u32 e) { return geomFactory(e, 0x694ebc); }
PCREG(4cab60, f4cab60);
static u8 *THISCALL f5bc5a0(u32 e) { return geomFactory(e, 0x6b2f30); }
PCREG(5bc5a0, f5bc5a0);
static u8 *THISCALL f5d55a0(u32 e) { return geomFactory(e, 0x6b557c); }
PCREG(5d55a0, f5d55a0);
// GUESS factories with their own constructors.
static u8 *THISCALL f548e20(u32 e) {
  u8 *o = engineAlloc(e);
  if (o) ext_548ca0(o);
  return o;
}
PCREG(548e20, f548e20);
static u8 *THISCALL f5be120(u32 e) {   // named CCivilianPathList::CheckPath in the map [medium]; the body is a factory
  u8 *o = engineAlloc(e);
  if (o) ext_5bde30(o);
  return o;
}
PCREG(5be120, f5be120);
static u8 *THISCALL f5693a0(u32 e) {
  u8 *o = engineAlloc(e);
  if (o) {
    ext_561020(o);
    *(u32 *)o = 0x6a746c;
  }
  return o;
}
PCREG(5693a0, f5693a0);

// 0x608220 GUESS deleting dtor (vtables 0x6bc8ac -> 0x6bc88c): COM Release of +0x14.
typedef u32(STDCALL *com1)(void *);
static void *THISCALL f608220(u32 *self, u32 flags) {
  void *o = (void *)self[5];
  self[0] = 0x6bc8ac;
  (*(com1 *)(*(u8 **)o + 8))(o);
  self[0] = 0x6bc88c;
  if (flags & 1) ext_634273(self, 0x1c);
  return self;
}
PCREG(608220, f608220);

// 0x616aa0 ZRObjectBonesVSGC deleting dtor [medium]
static void *THISCALL f616aa0(u8 *self, u32 flags) {
  *(u32 *)self = 0x6bdd28;
  ext_659c00(self + 0x24);
  ext_659bb0(self + 0xc);
  *(u32 *)self = 0x6bdc40;
  if (flags & 1) ext_634273(self, 0x30);
  return self;
}
PCREG(616aa0, f616aa0);

// 0x616be0 GUESS deleting dtor (vtables 0x6bdcc0 -> 0x6bdc38): drops a reference on the shared block (+4, count +0x30).
static void *THISCALL f616be0(u8 *self, u32 flags) {
  u8 *sh = *(u8 **)(self + 4);
  *(u32 *)self = 0x6bdcc0;
  if (--*(u32 *)(sh + 0x30) == 0) ext_659c00(sh + 0x24);
  *(u32 *)self = 0x6bdc38;
  if (flags & 1) ext_634273(self, 0xc);
  return self;
}
PCREG(616be0, f616be0);

// 0x54a0e0 GUESS field copy between two record layouts.
static void THISCALL f54a0e0(void *, u32 *d, const u32 *s) {
  for (int i = 0; i < 11; i++) d[i] = s[2 + i];
  d[0x38 / 4] = s[0x34 / 4];
  d[0x3c / 4] = s[0x38 / 4];
  for (int i = 0; i < 9; i++) d[0x4c / 4 + i] = s[0x3c / 4 + i];
}
PCREG(54a0e0, f54a0e0);

// 0x4fa720 ZCONTROL::SetNextFocus(ZCONTROL*, EFocusMove) [high]: directions 1..4 store the engine handle of ctl in
// +0x78, +0x7c, +0x80, +0x84 (jump table 0x4fa7a8).
static void THISCALL f4fa720(u8 *self, u32 ctl, u32 dir) {
  static const u16 offs[4] = {0x78, 0x7c, 0x80, 0x84};
  if (dir - 1 > 3) return;
  *(u32 *)(self + offs[dir - 1]) = vcall<u32>(engineObj9b(), 0x4c, ctl);
}
PCREG(4fa720, f4fa720);

// 0x4a7f20 ZGeomSpawn::Load(ZLoadGame*) [high]: asserts unconditionally, then reads the spawn fields.
static bool THISCALL f4a7f20(u8 *self, void *lg) {
  *(u32 *)(self + 4) &= ~0x40u;
  ffAssert();
  ext_4a7fb0(self, 0);
  vcall<void>(lg, 0x58, self + 0x72);
  vcall<void>(lg, 0x58, self + 0x76);
  for (u32 o = 0x7b; o <= 0x80; o++) vcall<void>(lg, 0x68, self + o);
  return true;
}
PCREG(4a7f20, f4a7f20);

// 0x4c48a0 ZParticleEmitter::Save(ZSaveGame*) [high]
static bool THISCALL f4c48a0(u8 *self, void *sg) {
  *(u32 *)(self + 4) &= ~0x40u;
  void *r = vcall<void *>(sg, 0x3c, *(u32 *)(self + 0x82));
  vcall<void *>(r, 0x3c, *(u32 *)(self + 0x86));
  vcall<void>(sg, 0x54, *(u32 *)(self + 0x8a));
  vcall<void>(sg, 0x4c, *(u32 *)(self + 0x8e));   // floats are passed as their bits
  vcall<void>(sg, 0x4c, *(u32 *)(self + 0x92));
  vcall<void>(sg, 0x68, self + 0x96);
  vcall<void>(sg, 0x4c, *(u32 *)(self + 0xa2));
  return true;
}
PCREG(4c48a0, f4c48a0);

// 0x5517a0 Signature_ifff_EventTranslator_t::handleEventTranslation [low]: one int and three float parameters.
static void *THISCALL f5517a0(void *, void *factory, u32 id, u32 *args) {
  void *ev = vcall<void *>(factory, 0x18, id);
  if (!ev) return 0;
  void *prm = vcall<void *>(ev, 0x4c);
  ext_5002f0(ext_5003d0(prm, 0), args[0]);
  ext_500360(ext_5003d0(prm, 1), args[1]);
  ext_500360(ext_5003d0(prm, 2), args[2]);
  ext_500360(ext_5003d0(prm, 3), args[3]);
  return ev;
}
PCREG(5517a0, f5517a0);

// String parameter store shared by 0x500760 and 0x553fa0: slot type byte +4 (0 empty, 4 string object at +0).
static inline void setStringParam(u8 *slot, void *s) {
  u8 t = slot[4];
  if (t != 0) {
    if (t != 4) goto done;
    vcall<void>(*(void **)slot, 0x28);
  }
  *(u32 *)slot = vcall<u32>(s, 0x24);
  slot[4] = 4;
done:
  vcall<void>(s, 0x28);
}

// 0x500760 StringEventTranslator_t::handleEventTranslation [medium]
static void *THISCALL f500760(void *, void *factory, u32 id, u32 str) {
  void *ev = vcall<void *>(factory, 0x18, id);
  if (!ev) return 0;
  void *prm = vcall<void *>(ev, 0x4c);
  void *s = vcall<void *>(factory, 0, 0x67a14c, 0);
  vcall<void>(s, 0x30, str);
  setStringParam((u8 *)ext_5003d0(prm, 0), s);
  return ev;
}
PCREG(500760, f500760);

// 0x553fa0 CFFTools_if::GetLevelName(OpaqueCallParameters_t&) [high]: returns the level name (+0x48 of 0x7003b8's
// +0x2c15 block) as the call's string result.
static void THISCALL f553fa0(void *, u8 *prm) {
  if (!*(u32 *)(G(u8 *, 0x7003b8) + 0x2c15)) return;
  void *s = vcall<void *>(*(void **)(prm + 0xc), 0, 0x67a14c, 0);
  vcall<void>(s, 0x30, *(u32 *)(G(u8 *, 0x7003b8) + 0x2c15) + 0x48);
  setStringParam((u8 *)ext_5003d0(*(void **)(prm + 8), 0), s);
}
PCREG(553fa0, f553fa0);

// 0x4b5620 GUESS: engine handle (slot 0x58) of the idx-th entry of the table at (+0x44)->+0x18, or 0.
static u32 THISCALL f4b5620(u8 *self, u32 idx) {
  if (!*(void **)(*(u8 **)(self + 0x44) + 0x18)) return 0;
  u32 it[3];
  vcall<void>(*(void **)(*(u8 **)(self + 0x44) + 0x18), 0x4c, it);
  u32 x = vcall<u32>(*(void **)(*(u8 **)(self + 0x44) + 0x18), 0x5c, it);
  u32 i = 0;
  while (it[0]) {
    if (i++ == idx) return vcall<u32>(engineObj9b(), 0x58, x);
    x = vcall<u32>(*(void **)(*(u8 **)(self + 0x44) + 0x18), 0x5c, it);
  }
  return 0;
}
PCREG(4b5620, f4b5620);

// 0x45bda0 ZBloodSplatters::FadeMark(unsigned int, float) [high]: alpha = f (+ (age-60)/40*0.5 when age > 60),
// clamped to 1.0 by minss, sent to the window manager slot 0x20 object's slot 0x44.
static void THISCALL f45bda0(u8 *self, u32 i, float f) {
  float age = *(float *)(self + 0x258 + 4 * i);
  float k = G(float, 0x67885c);
  float x = age > k ? (age - k) / G(float, 0x684cf0) * G(float, 0x67a6ac) + f : f;
  void *o = vcall<void *>(*(void **)(G(u8 *, 0x70039c) + 0x190f), 0x20);
  float one = G(float, 0x678858);
  float a = one < x ? one : x;   // minss one, x
  vcall<void>(o, 0x44, (*(u32 **)(self + 0x40))[i], a);
}
PCREG(45bda0, f45bda0);

// 0x5496e0 GUESS: scales the unsigned count at (+0x5d)->+0xc by a signed percentage-like value d/1200: n*(1+d/1200)
// for d >= 0, n/(1-d/1200) otherwise; truncated to int.
static inline float u2f(u32 v) { return (float)((double)(s32)v + G(double, 0x680aa0 + 8 * (v >> 31))); }
static s32 THISCALL f5496e0(u8 *self, s32 d) {
  u32 n = *(u32 *)(*(u8 **)(self + 0x5d) + 0xc);
  float one = G(float, 0x678858), k = G(float, 0x68af24);
  if (d < 0) {
    float q = (float)d / k;
    float x = one / (one - q);
    return _mm_cvttss_si32(_mm_set_ss(x * u2f(n)));
  }
  float nf = u2f(n);
  float y = (float)d / k + one;
  return _mm_cvttss_si32(_mm_set_ss(nf * y));
}
PCREG(5496e0, f5496e0);

// 0x64a120 GUESS: returns a primitive-instance entry (edi+4) to the draw base's ring (+0x268 of (+0x1005d)), stamps the
// frame (engine +0x3c) and ring slot, and leaves the prim (entry +0xc, count +8) when it was the last one.
static void THISCALL f64a120(u8 *self, u8 *ent) {
  u8 *e = ent ? ent + 4 : 0;
  e[5] &= 0xfe;
  *(u32 *)e = *(u32 *)(G(u8 *, 0x70039c) + 0x3c);
  u8 *q = *(u8 **)(self + 0x1005d) + 0x268;
  *(u32 *)e = *(u32 *)(G(u8 *, 0x70039c) + 0x3c);
  u8 *c = *(u8 **)q;
  u16 idx = (u16)((s32)(c - q - 8) >> 2);
  *(u8 **)c = e;
  *(u32 *)q += 4;
  if (*(u8 **)q == q + 0x8008) *(u8 **)q = q + 8;
  *(u16 *)(e + 6) = idx;
  u8 *m = *(u8 **)(ent + 0xc);
  if (--m[8] == 0) ext_63f600(*(void **)(self + 0x1005d), m);
}
PCREG(64a120, f64a120);

// 0x496fe0 ZGeomBuffer::FreeEventRam(ZEventBase*) [high]: drops the event's attached block, frees its 16-byte-rounded
// size from the allocator at +0x2c and reports it to the memory tracker (0x70038c, assumed present as in the exe).
static void THISCALL f496fe0(u8 *self, u8 *ev) {
  (*(u32 *)(self + 0x3c))--;
  u32 sz = *(u32 *)(ev + 0x2c);
  u32 p = *(u32 *)(ev + sz - 4);
  if (p) {
    vcall<void>(G(void *, 0x70038c), 0xd4, p);
    *(u32 *)(ev + sz - 4) = 0;
  }
  u32 sz2 = *(u32 *)(ev + 0x2c);
  u32 off = (u32)ev - *(u32 *)(self + 0x30);
  u32 al = (sz2 + 0xf) & ~0xfu;
  ext_4ce1c0(*(void **)(self + 0x2c), off, al);
  void *m = G(void *, 0x70038c);
  if (m) {
    vcall<void>(m, 0x30, 0x68e524, off, al);
    m = G(void *, 0x70038c);
  }
  vcall<void>(m, 0x50, ev, al, 0x20a0ff);
  *(u32 *)(self + 0x38) -= sz2;
}
PCREG(496fe0, f496fe0);

// 0x4ceda0 STRREFTAB::RemoveStr(const char*) [high]: removes the first entry equal (_stricmp) to the name, else logs.
typedef s32 (*stricmpFn)(u32, u32);
static void THISCALL f4ceda0(u8 *self, u32 name) {
  if (self) {
    u32 it[3];
    vcall<void>(self, 0x4c, it);
    u32 x = vcall<u32>(self, 0x5c, it);
    while (it[0]) {
      if ((*(stricmpFn *)0x676414)(x, name) == 0) {
        vcall<void>(self, 0x44, it);
        *(u32 *)(self + 0xc) |= 0x80000000u;
        return;
      }
      x = vcall<u32>(self, 0x5c, it);
    }
  }
  void *lg = vcall<void *>(G(void *, 0x700390), 0x20, 0x695b7c, 0x58d);
  (*(cdeclLog3 *)(*(u8 **)lg + 0x2c))(lg, 0x695cc4, name);
}
PCREG(4ceda0, f4ceda0);

// 0x4fbb20 GUESS: appends a 0x15-byte node {key, value(float) +4, prev +8, next +0xc, owner +0x10, flag +0x14} to the
// list at +0x48/+0x4c after telling the table at (+0x44)->+0x18 (slot 4); updates the value through 0x4fdb70 when it
// differs.
static u8 *THISCALL f4fbb20(u8 *self, u32 *kv) {
  vcall<void>(*(void **)(*(u8 **)(self + 0x44) + 0x18), 4, kv[0]);
  u8 *n = (u8 *)ext_41e290(0x15);
  if (!n) return 0;
  float v = *(float *)(kv + 1);
  n[0x14] = 1;
  *(u8 **)(n + 0x10) = self;
  *(u32 *)n = kv[0];
  u8 *last = *(u8 **)(self + 0x4c);
  *(u8 **)(n + 8) = last;
  *(u32 *)(n + 0xc) = 0;
  if (last) *(u8 **)(last + 0xc) = n;
  else *(u8 **)(self + 0x48) = n;
  *(u8 **)(self + 0x4c) = n;
  if (!(*(float *)(n + 4) == v)) {
    *(float *)(n + 4) = v;
    ext_4fdb70(n);
  }
  return n;
}
PCREG(4fbb20, f4fbb20);

// 0x5fd0a0 GUESS list push_back with a CHostInterface-allocated 0x14-byte node (payload ctor 0x5f10c0 at +8).
static void THISCALL f5fd0a0(u32 **self, u32 a) {
  u32 *head = (u32 *)*self[0];
  u32 *node = (u32 *)ext_6014a0(self, 0x14);
  if ((u32)node + 8) ext_5f10c0(node + 2, a);
  node[0] = (u32)head;
  node[1] = head[1];
  *(u32 **)head[1] = node;
  head[1] = (u32)node;
}
PCREG(5fd0a0, f5fd0a0);

// 0x42ba60 GUESS destructor body: frees the two arrays (+0xc..+0x14 and +0..+8) through 0x54f870(ptr, bytes).
static void THISCALL f42ba60(u32 *self) {
  u32 *v = self + 3;
  u32 b = v[0], n = v[2] - v[0];
  if (b && n) ext_54f870(v, b, n);
  b = self[0];
  n = self[2] - self[0];
  if (b && n) ext_54f870(self, b, n);
}
PCREG(42ba60, f42ba60);
