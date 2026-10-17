// batch1809.cpp - fresh-18 batch 9 (slice 18): constructors, deletes, script calls, config lookup, translators.
// SEH frames and stack cookies of the exe are not reproduced (they leave no state behind on return).
#include "ff.h"
#include <stdarg.h>

static inline u8 *engineObj9b() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
typedef void (*voidfn)();
static inline void ffAssert() {
  voidfn h = G(voidfn, 0x7003b0);
  if (h) h(); else __builtin_debugtrap();
}
typedef void (*cdeclLog2)(void *, u32);
typedef void (*cdeclLog3)(void *, u32, u32);
typedef s32 (*stricmpFn)(u32, u32);

extern "C" void THISCALL ext_43de40(void *self, u32 a, u32 b, u32 c);            // ZSTDOBJ::ZSTDOBJ
extern "C" void *ext_634d10(void *d, u32 v, u32 n);                              // memset (import jump)
extern "C" void ext_634273(void *p, u32 size);                                  // operator delete(p, size), cdecl
extern "C" void *THISCALL ext_5003d0(void *self, u32 idx);
extern "C" void THISCALL ext_5002f0(void *self, u32 v);
extern "C" void THISCALL ext_500360(void *self, u32 fbits);
extern "C" u32 THISCALL ext_4cc1d0(void *self);                                  // MYSTR::c_str (pops 0)
extern "C" void THISCALL ext_4cbe80(void *self, u32 s);                          // MYSTR::MYSTR(const char*)
extern "C" void THISCALL ext_4cbee0(void *self, void *o);                        // MYSTR::operator=
extern "C" void THISCALL ext_4cbec0(void *self);                                 // MYSTR::~MYSTR
extern "C" void THISCALL ext_469870(void *self);
extern "C" void THISCALL ext_49f670(void *self);
extern "C" void ext_42abee(char *buf, u32 fmt, va_list ap);                      // vsprintf, cdecl
typedef u32(STDCALL *addAtomFn)(const char *);                                  // GlobalAddAtomA (IAT 0x6760f4)

// 0x45b3a0 GUESS ZSTDOBJ subclass constructor (vtable 0x684580): +0x28 = 8.0f, +0x2c = 10.0f, a cleared 0x80-byte
// block at +0x8d8 (+0x254 points at it) and buffer pointers +0x40/+0x248/+0x24c/+0x250 into the object.
static void *THISCALL f45b3a0(u8 *self, u32 a, u32 b, u32 c) {
  ext_43de40(self, a, b, c);
  *(u32 *)(self + 0x28) = 0x41000000;
  *(u32 *)(self + 0x2c) = 0x41200000;
  *(u32 *)(self + 0x38) = 0;
  *(u32 *)(self + 0x3c) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)(self + 0x34) = 0;
  *(u32 *)(self + 0x24) = 0;
  *(u32 *)self = 0x684580;
  ext_634d10(self + 0x8d8, 0, 0x80);
  *(u8 **)(self + 0x254) = self + 0x8d8;
  *(u8 **)(self + 0x40) = self + 0x258;
  *(u32 *)(self + 0x44) = 0xffffffffu;
  *(u8 **)(self + 0x248) = self + 0x458;
  *(u8 **)(self + 0x24c) = self + 0x4d8;
  *(u8 **)(self + 0x250) = self + 0x6d8;
  *(u32 *)(self + 0x1c) = 0x80;
  *(u32 *)(self + 0x20) = 0x20;
  *(u32 *)(self + 0x18) = 0x60;
  return self;
}
PCREG(45b3a0, f45b3a0);

// 0x63fc20 GUESS: deletes the eight 4-byte blocks at +0x218..+0x234, then clears the pointers.
static void THISCALL f63fc20(u8 *self) {
  for (u32 o = 0x218; o <= 0x234; o += 4) ext_634273(*(void **)(self + o), 4);
  for (u32 o = 0x218; o <= 0x234; o += 4) *(u32 *)(self + o) = 0;
}
PCREG(63fc20, f63fc20);

// 0x50f120 ZScriptSceneInterface_t::GetParentForGeom(OpaqueCallParameters_t&) [low]: result = engine handle (db
// slot 0x4c) of the geom's parent (slot 0x20); 0 when the handle does not resolve. A result slot whose type byte
// is above 1 is logged and asserted.
static void THISCALL f50f120(void *, u8 *prm) {
  u32 *p = (u32 *)ext_5003d0(*(void **)(prm + 4), 0);
  void *g = vcall<void *>(engineObj9b(), 0x58, *p);
  if (!g) {
    ext_5002f0(ext_5003d0(*(void **)(prm + 8), 0), 0);
    return;
  }
  u32 par = vcall<u32>(g, 0x20);
  u32 h = vcall<u32>(engineObj9b(), 0x4c, par);
  u8 *q = (u8 *)ext_5003d0(*(void **)(prm + 8), 0);
  if (q[4] <= 1) {
    *(u32 *)q = h;
    q[4] = 1;
    return;
  }
  void *lg = vcall<void *>(G(void *, 0x700390), 0x20, 0x69c8e0, 0xc4);
  (*(cdeclLog3 *)(*(u8 **)lg + 0x2c))(lg, 0x69c6b0, 0x69c938);
  ffAssert();
}
PCREG(50f120, f50f120);

// 0x651ce0 GUESS: when name differs (_stricmp) from the engine's current name (MYSTR at engine +0x1e91), stores it,
// copies +0x6f/+0x73 to +0x77/+0x7b and sets byte +0x1a97.
static void THISCALL f651ce0(void *, u32 name) {
  if (!(*(stricmpFn *)0x676414)(ext_4cc1d0(G(u8 *, 0x70039c) + 0x1e91), name)) return;
  u8 tmp[0x80];
  ext_4cbe80(tmp, name);
  ext_4cbee0(G(u8 *, 0x70039c) + 0x1e91, tmp);
  ext_4cbec0(tmp);
  u8 *e = G(u8 *, 0x70039c);
  *(u32 *)(e + 0x77) = *(u32 *)(e + 0x6f);
  e = G(u8 *, 0x70039c);
  *(u32 *)(e + 0x7b) = *(u32 *)(e + 0x73);
  G(u8 *, 0x70039c)[0x1a97] = 1;
}
PCREG(651ce0, f651ce0);

// 0x5d9f60 CTVStudioCam::CTVStudioCam() [high]: registers messages 0x15..0x17 (engine db slot 0x114, four words) and
// keeps their ids in the words at +0x50/+0x52/+0x54.
static void *THISCALL f5d9f60(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6b6544;
  *(u16 *)(self + 0x50) = (u16)vcall<u32>(engineObj9b(), 0x114, 0x6b65fc, 0, 0x6b65c8, 0x15);
  *(u16 *)(self + 0x52) = (u16)vcall<u32>(engineObj9b(), 0x114, 0x6b660c, 0, 0x6b65c8, 0x16);
  *(u16 *)(self + 0x54) = (u16)vcall<u32>(engineObj9b(), 0x114, 0x6b661c, 0, 0x6b65c8, 0x17);
  return self;
}
PCREG(5d9f60, f5d9f60);

// Owner tag of a tracked block (as in 0x493f20): 0 when the tracker (0x70038c) slot 0x20 claims it, the range
// callback (+8, range +0xc..+0x10) when it covers p, else the word before the block (filled by slot 0xac when 0).
typedef u32(THISCALL *tagFn)(void *);
static inline u32 blockTag(u8 *p) {
  if (vcall<u32>(G(void *, 0x70038c), 0x20, p)) return 0;
  u8 *m = G(u8 *, 0x70038c);
  tagFn fn = *(tagFn *)(m + 8);
  if (fn && *(u8 **)(m + 0xc) <= p && p < *(u8 **)(m + 0x10)) return fn(p);
  if (!*(u32 *)(p - 4)) vcall<void>(m, 0xac, p);
  return *(u32 *)(p - 4);
}

// 0x49f5a0 GUESS constructor (vtable 0x68f560, geom base 0x469870, member 0x49f670 at +0x6c); records its owner tag
// under 0x68f724 (engine db slot 0x138 object, slot 0x60(name, value, size 4)).
static void *THISCALL f49f5a0(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x68f560;
  ext_49f670(self + 0x6c);
  void *x = vcall<void *>(engineObj9b(), 0x138);
  u32 tag = blockTag(self);
  vcall<void>(x, 0x60, 0x68f724, tag, 4);
  return self;
}
PCREG(49f5a0, f49f5a0);

// 0x4320e0 CConfiguration::ExtractInputFromNode(unsigned int) [high]: maps the node's input code (slot 0x10; device
// in the high word: 0, 1, 2 select the tables at +8/+0x18/+0x28 of engine +0x190b, 0x42 searches the three ranges)
// to its 12-byte entry, or 0. Other devices fall back to (id, id) as table and count, as the exe does.
static u32 THISCALL f4320e0(void *self, u32 id) {
  u32 v = vcall<u32>(self, 0x10, id);
  u32 dev = v >> 16;
  u32 base, n;
  u8 *t = *(u8 **)(G(u8 *, 0x70039c) + 0x190b);
  if (dev == 0) { base = *(u32 *)(t + 8); n = *(u32 *)(t + 0xc); }
  else if (dev == 1) { base = *(u32 *)(t + 0x18); n = *(u32 *)(t + 0x1c); }
  else if (dev == 2) { base = *(u32 *)(t + 0x28); n = *(u32 *)(t + 0x2c); }
  else {
    if (dev == 0x42) {
      s32 lo = (s32)(v & 0xffff);
      for (u32 i = 0; i < 3; i++) {
        s32 *e = (s32 *)(t + 0x10 * i);
        if (!(e[0] > lo) && e[3] + e[0] > lo) return (u32)e[2] + (u32)(lo - e[0]) * 12;
      }
    }
    base = id;
    n = id;
  }
  u32 lo = v & 0xffff;
  for (s32 i = 0; i < (s32)n; i++)
    if ((u32)i == lo) return base + (u32)i * 12;
  return 0;
}
PCREG(4320e0, f4320e0);

// 0x551160 Signature_ffffff_EventTranslator_t::handleEventTranslation [low]: six float parameters.
static void *THISCALL f551160(void *, void *factory, u32 id, u32 *args) {
  void *ev = vcall<void *>(factory, 0x18, id);
  if (!ev) return 0;
  void *prm = vcall<void *>(ev, 0x4c);
  for (u32 i = 0; i < 6; i++) ext_500360(ext_5003d0(prm, i), args[i]);
  return ev;
}
PCREG(551160, f551160);

// 0x449920 ZGateLightSpotMaster::SetMultiplier(float) [high]: passes f to every light of the table at +0x1c (slot
// 0x230), refreshes (slot 0x238), rewrites the light record (+0x14 = f) of [+8]+0x6c through the renderer
// (engine +0x1aa3 -> +0x18, slots 0x84 get / 0xa0 set) and marks dirty (slot 0x220(1)).
static void THISCALL f449920(u8 *self, u32 f) {
  void *t = *(void **)(self + 0x1c);
  u32 it[3];   // kept apart from rec as in the exe frame (the harness reads both after the call)
  if (t) {
    vcall<void>(t, 0x4c, it);
    u32 x = vcall<u32>(*(void **)(self + 0x1c), 0x5c, it);
    while (it[0]) {
      void *g = vcall<void *>(engineObj9b(), 0x58, x);
      if (g) vcall<void>(g, 0x230, f);
      x = vcall<u32>(*(void **)(self + 0x1c), 0x5c, it);
    }
  }
  vcall<void>(self, 0x238);
  u8 rec[0x38];
  vcall<void>(*(void **)(*(u8 **)(G(u8 *, 0x70039c) + 0x1aa3) + 0x18), 0x84, *(u32 *)(*(u8 **)(self + 8) + 0x6c), rec);
  *(u32 *)(rec + 0x14) = f;
  vcall<void>(*(void **)(*(u8 **)(G(u8 *, 0x70039c) + 0x1aa3) + 0x18), 0xa0, *(u32 *)(*(u8 **)(self + 8) + 0x6c), rec);
  vcall<void>(self, 0x220, 1);
  asm volatile("" ::"r"(it) : "memory");
}
PCREG(449920, f449920);

// 0x424ee0 ZSysComGC::DataToDebug(char*, ...) [low] (cdecl): formats into 0x400 bytes and sends the text's global
// atom through slot 0x18(0xc, atom, 0); logs an empty text or a failed atom. Nothing happens while +0x24 is 0.
static void f424ee0(u8 *self, u32 fmt, ...) {
  if (!*(u32 *)(self + 0x24)) return;
  char buf[0x400];
  va_list ap;
  va_start(ap, fmt);
  ext_42abee(buf, fmt, ap);
  va_end(ap);
  if (!buf[0]) {
    void *lg = vcall<void *>(G(void *, 0x700390), 0x20, 0x6786c4, 0x1b9);
    (*(cdeclLog2 *)(*(u8 **)lg + 0x2c))(lg, 0x678738);
    return;
  }
  u16 atom = (u16)(*(addAtomFn *)0x6760f4)(buf);
  if (atom) {
    vcall<void>(self, 0x18, 0xc, (u32)atom, 0);
    return;
  }
  void *lg = vcall<void *>(G(void *, 0x700390), 0x20, 0x6786c4, 0x1c0);
  (*(cdeclLog3 *)(*(u8 **)lg + 0x2c))(lg, 0x678770, (u32)buf);
}
PCREG(424ee0, f424ee0);
