// batch1808.cpp - fresh-18 batch 8 (slice 18): window destructors, factories, loaders, fog impact, item tables.
// SEH frames and stack cookies of the exe are not reproduced (they leave no state behind on return).
#include "ff.h"

static inline u8 *engineObj9b() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
typedef void (*voidfn)();
static inline void ffAssert() {
  voidfn h = G(voidfn, 0x7003b0);
  if (h) h(); else __builtin_debugtrap();
}

extern "C" void THISCALL ext_4ccf60(void *self);                                 // REFTAB32::~REFTAB32
extern "C" void ext_4690b0(void *p, u32 v);                                     // cdecl
extern "C" void *ext_41e290(u32 size);                                          // operator new, cdecl
extern "C" void THISCALL ext_500900(void *self, u32 a, u32 b);
extern "C" void THISCALL ext_505d50(void *self);
extern "C" void THISCALL ext_64f6a0(void *self, void *cam);                      // ZRender::AddCameraToView
extern "C" void THISCALL ext_517050(void *self, u32 a, u32 b, u32 c);
extern "C" void THISCALL ext_5273b0(void *self);
extern "C" void THISCALL ext_511c60(void *self);
extern "C" void *ext_45c4b0(u32 size);                                          // cdecl allocator
extern "C" u32 FASTCALL ext_4471f0(u32 a, u32 b, u32 c, u32 d);
extern "C" void THISCALL ext_45c3a0(void *self, u32 a, u32 b, u32 c);            // ZGEOM::ZGEOM
extern "C" u32 THISCALL ext_4fa230(void *self, void *lg);                        // ZCONTROL::Load
extern "C" void THISCALL ext_5de090(void *self, const void *imp);                // ZFogController::AddFogImpact
extern "C" u32 FASTCALL ext_47fc30(u32 a, u32 b, u32 c, u32 d);
extern "C" void THISCALL ext_43de40(void *self, u32 a, u32 b, u32 c);            // ZSTDOBJ::ZSTDOBJ

// Window destructor tail shared by 0x4f69e0 and 0x5658e0 (scalar-deleting form of the CWindow base, vtable 0x686874):
// unregisters through engine db slot 0x34; flag 1 asserts unless flag 4 is set, which calls 0x4690b0(this, state).
static inline void *windowDtorTail(u8 *self, u32 flags, u32 state) {
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  vcall<void>(engineObj9b(), 0x34, self);
  if (flags & 1) {
    if (!(flags & 4)) {
      ffAssert();
      return self;
    }
    ext_4690b0(self, state);
  }
  return self;
}

// 0x4f69e0 CAutoLayout::~CAutoLayout() [medium]
static void *THISCALL f4f69e0(u8 *self, u32 flags) {
  ext_4ccf60(self + 0x48);
  return windowDtorTail(self, flags, 0xfa);
}
PCREG(4f69e0, f4f69e0);

// 0x5658e0 CBootMenu::~CBootMenu() [medium]
static void *THISCALL f5658e0(u8 *self, u32 flags) {
  *(u32 *)(self + 0x180) = 0x6a6c0c;
  return windowDtorTail(self, flags, 0xcb2);
}
PCREG(5658e0, f5658e0);

// 0x506160 GUESS factory (fastcall): 0x18-byte object (base 0x500900(a, b), vtable 0x69cc88), registered through
// 0x505d50 while [0x700f7c] is 0; +0x14 = engine handle of the id read from a(+0x15) slot 0x40.
static void *FASTCALL f506160(u8 *a, u32 b) {
  u8 *o = (u8 *)ext_41e290(0x18);
  if (!o) return 0;
  ext_500900(o, (u32)a, b);
  *(u32 *)o = 0x69cc88;
  if (!G(u32, 0x700f7c)) ext_505d50(o);
  u32 id;
  vcall<void>(*(void **)(a + 0x15), 0x40, &id);
  *(u32 *)(o + 0x14) = vcall<u32>(engineObj9b(), 0x58, id);
  return o;
}
PCREG(506160, f506160);

// 0x64f760 ZRender::AllocateDrawBuffers() [high]: inside a memory-tracker scope (0x70038c slot 0x48), adds every
// camera of the table at +0x8c to the view unless the device (+0xbd) is lost or slot 0xa4 refuses.
static void THISCALL f64f760(u8 *self) {
  u32 x = vcall<u32>(G(void *, 0x70038c), 0x48, 0xff60a0);
  vcall<void>(self, 0x3c);
  u8 *dev = *(u8 **)(self + 0xbd);
  if (!dev[5]) {
    vcall<void>(dev, 8);
    if (!vcall<u32>(self, 0xa4, 0) && *(void **)(self + 0x8c)) {
      u32 it[3];
      vcall<void>(*(void **)(self + 0x8c), 0x4c, it);
      u32 id = vcall<u32>(*(void **)(self + 0x8c), 0x5c, it);
      while (it[0]) {
        void *cam = vcall<void *>(engineObj9b(), 0x58, id);
        if (cam) ext_64f6a0(self, cam);
        id = vcall<u32>(*(void **)(self + 0x8c), 0x5c, it);
      }
    }
  }
  vcall<void>(G(void *, 0x70038c), 0x48, x);
}
PCREG(64f760, f64f760);

// 0x51f3e0 GUESS constructor (vtable 0x69fb3c, base 0x517050): members at +0x1684 (0x5273b0) and +0x16e5
// (0x511c60), +0x1654..+0x165c cleared, then +0x1684's slot 0 gets (1.0472f, 0.8727f, 6.2832f) (60, 50, 360 deg).
static void *THISCALL f51f3e0(u8 *self, u32 a, u32 b, u32 c) {
  ext_517050(self, a, b, c);
  *(u32 *)self = 0x69fb3c;
  ext_5273b0(self + 0x1684);
  ext_511c60(self + 0x16e5);
  *(u32 *)(self + 0x1654) = 0;
  *(u32 *)(self + 0x1658) = 0;
  *(u32 *)(self + 0x165c) = 0;
  vcall<void>(self + 0x1684, 0, 0x3f860a92u, 0x3f5f66f3u, 0x40c90fdbu);
  return self;
}
PCREG(51f3e0, f51f3e0);

// 0x631620 GUESS (cdecl): byte +0x1c = (sum of words +0x8c..+0xa4 step 4 and of words +0x28c..+0x48c) <=
// (word +0x288 + sum of words +0xa8..+0x1a4) / 4, all unsigned 32-bit.
static void f631620(u8 *p) {
  u32 a = 0;
  for (u32 o = 0x8c; o <= 0xa4; o += 4) a += *(u16 *)(p + o);
  u32 s = 0;
  for (u32 i = 0; i < 120; i++) s += *(u16 *)(p + 0xa8 + 4 * i);
  u32 t = *(u16 *)(p + 0x288) + s;
  u32 r = 0;
  for (u32 i = 0; i < 128; i++) r += *(u16 *)(p + 0x28c + 4 * i);
  a += r;
  p[0x1c] = a <= (t >> 2);
}
PCREG(631620, f631620);

// 0x448160 GUESS forward or build (fastcall): 0x4471f0(d, c, a, b) when d is set, else a 0x1c-byte ZGEOM subclass
// (vtable 0x67de70; flag 1 of +0x14 when engine db byte +0xbad is set).
static u32 FASTCALL f448160(u32 a, u32 b, u32 c, u32 d) {
  if (d) return ext_4471f0(d, c, a, b);
  u8 *o = (u8 *)ext_45c4b0(0x1c);
  if (!o) return 0;
  ext_45c3a0(o, c, a, b);
  *(u32 *)o = 0x67dc30;
  *(u32 *)(o + 0x18) = 0;
  if (engineObj9b()[0xbad]) *(u32 *)(o + 0x14) |= 1;
  *(u32 *)o = 0x67de70;
  return (u32)o;
}
PCREG(448160, f448160);

// 0x4f7f20 ZSlider::Load(ZLoadGame*) [high]
static u8 THISCALL f4f7f20(u8 *self, void *lg) {
  u8 r = (u8)ext_4fa230(self, lg);
  if (!r) return r;
  vcall<void>(lg, 0x48, self + 0x8f);
  vcall<void>(lg, 0x48, self + 0x93);
  vcall<void>(lg, 0x48, self + 0x97);
  vcall<void>(lg, 0x50, self + 0x9b);
  vcall<void>(lg, 0x50, self + 0x9f);
  vcall<void>(lg, 0x50, self + 0xa3);
  vcall<void>(lg, 0x48, self + 0xa7);
  vcall<void>(lg, 0x40, self + 0xab);
  vcall<void>(lg, 0x40, self + 0xaf);
  vcall<void>(lg, 0x70, self + 0xb3);
  vcall<void>(lg, 0x50, self + 0xcf);
  return 1;
}
PCREG(4f7f20, f4f7f20);

// 0x5ddde0 ZImpactFog::Command(unsigned short, void*) [high]: on the impact command (word 0x71439c) adds a fog
// impact {0, 0, 0, engine +0x40, the 24 bytes at +0x48} after +0x44's slot 0x84 fills it; always returns 0.
static u32 THISCALL f5ddde0(u8 *self, u32 cmd, u32) {
  if ((u16)cmd != G(u16, 0x71439c)) return 0;
  void *fc = *(void **)(G(u8 *, 0x7003b8) + 0x2c4d);
  if (!fc) return 0;
  u32 s[10];
  s[3] = *(u32 *)(G(u8 *, 0x70039c) + 0x40);
  s[0] = s[1] = s[2] = 0;
  for (int i = 0; i < 6; i++) s[4 + i] = *(u32 *)(self + 0x48 + 4 * i);
  vcall<void>(*(void **)(self + 0x44), 0x84, s);
  ext_5de090(fc, s);
  return 0;
}
PCREG(5ddde0, f5ddde0);

// 0x47fde0 GUESS forward or build (fastcall): 0x47fc30(d, c, a, b) when d is set, else a 0x90-byte ZSTDOBJ subclass
// (vtable 0x68b364; +0x1c = 100.0f, +0x20 = 1.0f, +0x24 = 0.5f, +0x18 = 8, +0x8c = 0).
static u32 FASTCALL f47fde0(u32 a, u32 b, u32 c, u32 d) {
  if (d) return ext_47fc30(d, c, a, b);
  u8 *o = (u8 *)ext_45c4b0(0x90);
  if (!o) return 0;
  ext_43de40(o, c, a, b);
  *(u32 *)o = 0x68b364;
  *(u32 *)(o + 0x1c) = 0x42c80000;
  *(u32 *)(o + 0x24) = 0x3f000000;
  *(u32 *)(o + 0x20) = 0x3f800000;
  *(u32 *)(o + 0x8c) = 0;
  *(u32 *)(o + 0x18) = 8;
  return (u32)o;
}
PCREG(47fde0, f47fde0);

// 0x493f20 GUESS: resolves a block's owner tag (flag 0x10: notify +0xc8 slot 4 first; tracker slot 0x20 says owned
// elsewhere -> 0; the tracker's range callback (+8, range +0xc..+0x10) or the word before the block), then clears
// +0xcc's slot 4 entry (flag 8) and passes the tag to the listeners at +0x48.. selected by flag 0x40.
typedef u32(THISCALL *tagFn)(void *);
static void THISCALL f493f20(u8 *self, u8 *p, u32 flags) {
  if (flags & 0x10) {
    vcall<void>(*(void **)(self + 0xc8), 4, p);
    flags &= ~0x10u;
  }
  u32 v;
  if (!p) v = 0;
  else if (vcall<u32>(G(void *, 0x70038c), 0x20, p)) v = 0;
  else {
    u8 *m = G(u8 *, 0x70038c);
    tagFn fn = *(tagFn *)(m + 8);
    if (fn && *(u8 **)(m + 0xc) <= p && p < *(u8 **)(m + 0x10)) v = fn(p);
    else {
      if (!*(u32 *)(p - 4)) vcall<void>(m, 0xac, p);
      v = *(u32 *)(p - 4);
    }
  }
  if (flags & 8) {
    flags &= ~8u;
    u32 *r = vcall<u32 *>(self + 0xcc, 4, v);
    if (r) *r = 0;
  }
  flags &= 0x40;
  for (u8 *q = self + 0x48; flags; q += 4, flags >>= 1)
    if (flags & 1) vcall<void>(*(void **)q, 0x3c, v);
}
PCREG(493f20, f493f20);

// 0x61cd60 GUESS (cdecl) item table add: entries of 12 bytes {item, byte flag +4, value +8} at s+0x14 (count +0xc,
// capacity +0x10, grown x2 through the allocator's +0xc/+0x10 callbacks); returns 1 when present or added, 0 when
// the allocation fails. With d set the first item whose byte +9 is clear becomes s+8; c == 0 marks item byte +8.
typedef u32 (*alloc1)(u32);
typedef u32 (*realloc2)(u32, u32);
static u32 f61cd60(u32 *s, u8 *e, u32 c, u32 d, u32 y, u8 *al) {
  if (y || d) {
    s32 n = (s32)s[3];
    u32 *arr = (u32 *)s[5];
    for (s32 i = 0; i < n; i++)
      if ((u32)e == arr[3 * i]) return 1;
    if (d && !s[2] && !e[9]) s[2] = (u32)e;
  }
  if (s[3] == s[4]) {
    u32 p;
    if (!s[4]) {
      s[4] = 8;
      p = (*(alloc1 *)(al + 0xc))(0x60);
    } else {
      s[4] *= 2;
      p = (*(realloc2 *)(al + 0x10))(s[5], s[4] * 12);
    }
    s[5] = p;
    if (!p) return 0;
  }
  u32 *ent = (u32 *)s[5] + 3 * s[3];
  ent[0] = (u32)e;
  ent[2] = y;
  *(u8 *)(ent + 1) = (u8)c;
  if (!c) e[8] = 1;
  s[3]++;
  return 1;
}
PCREG(61cd60, f61cd60);
