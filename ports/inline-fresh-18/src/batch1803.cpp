// batch1803.cpp - fresh-18 batch 3 (slice 18): serial helpers, loaders, small engine glue.
#include "ff.h"

static inline u8 *engineObj9b() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
typedef u32 (*u32fn)();
// MSVC assert hook: the handler in 0x7003b0 (its return value is passed on where the exe does), else int3.
static inline u32 ffAssertRet() {
  u32fn h = G(u32fn, 0x7003b0);
  if (!h) __builtin_debugtrap();
  return h();
}

extern "C" void THISCALL ext_5fa590(void *self, void *si, void *buf);   // OpaqueType_t::toSerial
extern "C" void THISCALL ext_658140(void *self);                         // ZRenderGC::BeginScene
extern "C" u8 *THISCALL ext_4d8fc0(void *self, const char *name);       // CFastLookup2::GetLowerCase
extern "C" u8 THISCALL ext_54dc10(void *self);
extern "C" u32 THISCALL ext_4cc5f0(void *self);                          // MYSTR::Length
extern "C" u32 THISCALL ext_4235b0(void *self, u32, u32, u32, u32, u32);
extern "C" u32 THISCALL ext_422ba0(void *self, u32, u32, u32, u32, u32);
extern "C" u8 THISCALL ext_4f05d0(void *self, void *lg);                 // ZWINOBJ::Load
extern "C" void THISCALL ext_4dc440(void *self, u32 on);                 // ZBaseGeom::SetAutoRoomAssign
extern "C" void *THISCALL ext_5003d0(void *self, u32 idx);
extern "C" void THISCALL ext_5002f0(void *self, u32 v);
extern "C" void *ext_41e290(u32 size);                                   // operator new, cdecl

// 0x6057a0 OpaqueString_t::toSerial(SerialInfo_t&, OpaqueObjectSerialBuffer_t&) [high]: base toSerial, then
// si.slot2c(buf.slot0(this+0xc)) (si's vtable is read before the buffer call).
static void THISCALL f6057a0(u8 *self, void *si, void *buf) {
  ext_5fa590(self, si, buf);
  u8 *svt = *(u8 **)si;
  u32 r = vcall<u32>(buf, 0, *(u32 *)(self + 0xc));
  typedef void(THISCALL * f2c)(void *, u32);
  (*(f2c *)(svt + 0x2c))(si, r);
}
PCREG(6057a0, f6057a0);

// 0x656420 GUESS: when n*8 != 0, engine(+0x190f).slot20() object's slot 0x18(p, n*8).
static void THISCALL f656420(void *, u32 p, u32 n) {
  u32 sz = n * 8;
  if (!sz) return;
  void *o = vcall<void *>(*(void **)(G(u8 *, 0x70039c) + 0x190f), 0x20);
  vcall<void>(o, 0x18, p, sz);
}
PCREG(656420, f656420);

// 0x6566a0 GUESS: a + engine(+0x1aa3)->+0x20 base (asserts when the base is null).
static u32 THISCALL f6566a0(void *, u32 a) {
  u32 base = *(u32 *)(*(u8 **)(G(u8 *, 0x70039c) + 0x1aa3) + 0x20);
  if (!base) ffAssertRet();
  return a + base;
}
PCREG(6566a0, f6566a0);

// 0x551020 FFNIFFactory_t::typeInfoFromSerial(const char*, SerialInfo_t&) [high]: not supported; logs through
// 0x700390 (slot 0x20(file 0x6a4be4, line 0xaa) gives a logger whose cdecl slot 0x2c gets two strings), then asserts.
typedef void (*cdecl3)(void *, u32, u32);
static u32 THISCALL f551020(void *, u32, u32) {
  void *lg = vcall<void *>(G(void *, 0x700390), 0x20, 0x6a4be4, 0xaa);
  (*(cdecl3 *)(*(u8 **)lg + 0x2c))(lg, 0x69c6b0, 0x69c7f0);
  return ffAssertRet();
}
PCREG(551020, f551020);

// 0x490fa0 ZEngineDataBase::GetStartupParam() [medium]: engine.slot134() object's slot 0x88("..." 0x68e208, &out).
static u32 f490fa0() {
  void *o = vcall<void *>(engineObj9b(), 0x134);
  u32 out = 0;
  vcall<void>(o, 0x88, 0x68e208, &out);
  return out;
}
PCREG(490fa0, f490fa0);

// 0x608d60 GUESS BeginScene wrapper: fails when 0x724b34 is set or the device (+0x1377) COM slot 0x88 fails;
// on success marks +0x13ec and stores the device in 0x724a00.
typedef s32(STDCALL *com1)(void *);
static bool THISCALL f608d60(u8 *self) {
  if (G(u8, 0x724b34)) return false;
  ext_658140(self);
  void *dev = *(void **)(self + 0x1377);
  if ((*(com1 *)(*(u8 **)dev + 0x88))(dev) < 0) return false;
  self[0x13ec] = 1;
  G(u32, 0x724a00) = *(u32 *)(self + 0x1377);
  return true;
}
PCREG(608d60, f608d60);

// 0x6549e0 GUESS: unless +0x80 is set, forwards (a, b) to engine slot 0x1b0's object slot 0x18 when its slot 0xc
// says yes.
static void THISCALL f6549e0(u8 *self, u32 a, u32 b) {
  if (self[0x80]) return;
  void *o = vcall<void *>(G(void *, 0x70039c), 0x1b0);
  if (!o) return;
  if (!vcall<u8>(o, 0xc)) return;
  vcall<void>(o, 0x18, a, b);
}
PCREG(6549e0, f6549e0);

// 0x4d70e0 CFastLookupFileCache_t::lookup(const char*, IOZip_LocalFileHeader_t&, long&) [medium]: copies the 26-byte
// header and the offset (+0x1a) of the cached entry.
static bool THISCALL f4d70e0(u8 *self, const char *name, u8 *hdr, u32 *off) {
  u8 *e = ext_4d8fc0(self + 4, name);
  if (!e) return false;
  *off = *(u32 *)(e + 0x1a);
  for (int i = 0; i < 0x1a; i++) hdr[i] = e[i];
  return true;
}
PCREG(4d70e0, f4d70e0);

// 0x4f45a0 ZLINEOBJ::GetStringWidth(const char*, int) [high]: sums slot 0x298(&p) (one glyph, advances p) for at
// most n glyphs.
static u32 THISCALL f4f45a0(void *self, const char *s, u32 n) {
  const char *p = s;
  u32 w = 0;
  if (!*p) return 0;
  do {
    if (n-- == 0) break;
    w += vcall<u32>(self, 0x298, &p);
  } while (*p);
  return w;
}
PCREG(4f45a0, f4f45a0);

// 0x54e0a0 GUESS constructor (vtable 0x6a3ea8) with a 256 KB buffer at +0x4f/+0x53.
static void *THISCALL f54e0a0(u8 *self) {
  *(u32 *)self = 0x6a3ea8;
  *(u32 *)(self + 0x4b) = 0;
  *(u16 *)(self + 0x57) = 0;
  *(u32 *)(self + 0x3f) = 0;
  self[0x59] = 0;
  *(u32 *)(self + 0x47) = 0;
  *(u32 *)(self + 0x37) = 2;
  *(u32 *)(self + 0x3b) = 0;
  *(u32 *)(self + 0x33) = 0;
  *(u32 *)(self + 0x4f) = 0;
  void *b = ext_41e290(0x40000);
  *(void **)(self + 0x4f) = b;
  *(void **)(self + 0x53) = b;
  return self;
}
PCREG(54e0a0, f54e0a0);

// 0x54a5e0 GUESS init: CreateEventA(0,0,0,0) into 0x713d28, then 0x54dc10 and own slot 0x90 must succeed; a slot 0x90
// failure is logged through 0x700390 (file 0x6a34c4, line 0x266, text 0x6a34fc).
typedef u32(STDCALL *createEvent)(u32, u32, u32, u32);
typedef void (*cdecl2)(void *, u32);
static bool THISCALL f54a5e0(void *self) {
  G(u32, 0x713d28) = (*(createEvent *)0x676148)(0, 0, 0, 0);
  if (!ext_54dc10(self)) return false;
  if (vcall<u8>(self, 0x90)) return true;
  void *lg = vcall<void *>(G(void *, 0x700390), 0x20, 0x6a34c4, 0x266);
  (*(cdecl2 *)(*(u8 **)lg + 0x2c))(lg, 0x6a34fc);
  return false;
}
PCREG(54a5e0, f54a5e0);

// 0x6238e0 GUESS UTF-16 copy step (cdecl, iconv style): copies 2-byte units from *ps (up to se) to *pd (up to de);
// when the source does not fit, a trailing unit whose high byte is a high surrogate (0xd8-0xdf) is left out.
static void f6238e0(u32, u8 **ps, u8 *se, u8 **pd, u8 *de) {
  u8 *end = se;
  s32 room = (s32)(((u32)de - (u32)*pd) & ~1u);
  u8 *s = *ps;
  if ((s32)((u32)se - (u32)s) > room && (se[-1] & 0xf8) == 0xd8) end -= 2;
  if (s == end) return;
  do {
    u8 *d = *pd;
    if (d == de) return;
    u8 *c = *ps;
    *(u16 *)d = (u16)((c[1] << 8) | c[0]);
    *pd += 2;
    *ps += 2;
  } while (*ps != end);
}
PCREG(6238e0, f6238e0);

// 0x422e60 GUESS: dispatches to 0x4235b0 when the string at +0x255b is non-empty, else to 0x422ba0 when +0x23db is.
static u32 THISCALL f422e60(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e) {
  if (ext_4cc5f0(self + 0x255b)) return ext_4235b0(self, a, b, c, d, e);
  if (ext_4cc5f0(self + 0x23db)) return ext_422ba0(self, a, b, c, d, e);
  return 0;
}
PCREG(422e60, f422e60);

// 0x4f5860 ZFRAME::Load(ZLoadGame*) [high]
static u8 THISCALL f4f5860(u8 *self, void *lg) {
  u8 r = ext_4f05d0(self, lg);
  if (!r) return r;
  vcall<void>(lg, 0x48, self + 0xbb);
  vcall<void>(lg, 0x48, self + 0xbf);
  vcall<void>(lg, 0x18, self + 0x93, 0x24);
  vcall<void>(self, 0x244);
  vcall<void>(self, 0x27c);
  return 1;
}
PCREG(4f5860, f4f5860);

// 0x493020 GUESS: unless engine slot 0x2c says no, looks up each (id, flags) pair of the counted list (engine slot
// 0x54) and turns on auto room assignment for flag 0x4000.
static void THISCALL f493020(void *, u32 *list) {
  if (vcall<u8>(engineObj9b(), 0x2c)) return;
  if (!list[0]) return;
  u32 *e = list + 1;
  u32 i = 0;
  do {
    void *g = vcall<void *>(engineObj9b(), 0x54, e[0]);
    if (e[1] & 0x4000) ext_4dc440(g, 1);
    i++;
    e += 2;
  } while (i != list[0]);
}
PCREG(493020, f493020);

// 0x53b860 ZSoundGraph::FindChain(SPath*, int, SPath*) [low]: index of the first path (stride 0x89) whose node list
// (count +0x25, ids from +5) equals the target's, else -1.
static s32 THISCALL f53b860(void *, u8 *paths, s32 n, u8 *t) {
  s32 len = *(s32 *)(t + 0x25);
  for (s32 i = 0; i < n; i++) {
    u8 *p = paths + i * 0x89;
    if (len != *(s32 *)(p + 0x25)) continue;
    s32 j = 0;
    while (j < len && *(u32 *)(t + 5 + 4 * j) == *(u32 *)(p + 5 + 4 * j)) j++;
    if (j >= len) return i;
  }
  return -1;
}
PCREG(53b860, f53b860);

// 0x6486e0 GUESS free-list allocator: takes entry head (+2) of 32-byte slots, resets it, returns slot+0x10.
static u8 *THISCALL f6486e0(u8 *pool) {
  u16 h = *(u16 *)(pool + 2);
  if (h == 0xffff) return 0;
  u8 *e = pool + (u32)h * 32;
  *(u16 *)(pool + 2) = *(u16 *)(e + 0x10);
  *(u16 *)(e + 0x22) = 0xffff;
  *(u32 *)(e + 0x10) = 0;
  *(u32 *)(e + 0x14) = 0xffff1206;
  *(u32 *)(e + 0x18) = 0;
  *(u32 *)(e + 0x1c) = 0;
  *(u32 *)(e + 0x24) = 0;
  *(u32 *)(e + 0x2c) = 0;
  *(u32 *)(e + 0x28) = 0;
  e[0x20] = 0;
  pool[0]++;
  return e + 0x10;
}
PCREG(6486e0, f6486e0);

// 0x5518e0 Signature_iii_EventTranslator_t::handleEventTranslation(ScriptEventFactory_t*, unsigned int, void*) [low]:
// creates the event (factory slot 0x18) and sets its three int parameters from args[0..2].
static void *THISCALL f5518e0(void *, void *factory, u32 id, u32 *args) {
  void *ev = vcall<void *>(factory, 0x18, id);
  if (!ev) return 0;
  void *prm = vcall<void *>(ev, 0x4c);
  ext_5002f0(ext_5003d0(prm, 0), args[0]);
  ext_5002f0(ext_5003d0(prm, 1), args[1]);
  ext_5002f0(ext_5003d0(prm, 2), args[2]);
  return ev;
}
PCREG(5518e0, f5518e0);
