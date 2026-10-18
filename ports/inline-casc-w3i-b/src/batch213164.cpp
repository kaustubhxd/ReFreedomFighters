#include "ff.h"

extern "C" void FASTCALL ext_43e920(void *out, void *a, void *b);
extern "C" void FASTCALL ext_43e960(void *a, void *b);
extern "C" void FASTCALL ext_441940(void *a, void *b);
extern "C" void FASTCALL ext_451890(void *a, void *b, float s);
extern "C" void FASTCALL ext_4e0980(void *a, void *b);
extern "C" void FASTCALL ext_4e0a10(void *v);
extern "C" float FASTCALL ext_4e2120(void *a, void *b);
extern "C" void THISCALL ext_4daf90(void *self, void *out);
extern "C" void THISCALL ext_4db7c0(void *self, void *out);
extern "C" void THISCALL ext_584aa0(void *self, u32 a, u32 b, u32 c);
extern "C" u32 THISCALL ext_5dbed0(void *self, void *v);
extern "C" void FASTCALL ext_633654(u32 cookie);

static inline u32 R32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void W32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline float RF(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline void WF(u8 *p, float v) { __builtin_memcpy(p, &v, 4); }
static inline u8 *vt(void *o) { return *(u8 **)o; }
typedef void(THISCALL *Hook)(void *);

// normalises the vector at c in place (x87, 53-bit control word) and returns its length as float
static float normalise(u8 *c) {
  long double xx = (long double)RF(c) * (long double)RF(c);
  long double yy = (long double)RF(c + 4) * (long double)RF(c + 4);
  long double s = xx + yy;
  long double zz = (long double)RF(c + 8) * (long double)RF(c + 8);
  s = s + zz;
  long double l = fsqrt_x87(s);
  long double inv = (long double)1.0f / l;
  WF(c, (float)((long double)RF(c) * inv));
  WF(c + 4, (float)((long double)RF(c + 4) * inv));
  WF(c + 8, (float)((long double)RF(c + 8) * inv));
  return (float)l;
}

// 0x5833e0: thiscall(kind, arg) ret 8, /GS, void. Emits "hit" records (slot 0x128 of the entities) for everything inside this[0x51] around the owner's
// position: first the entities found by the iterator object [[0x7003b8]+0x2c11] (slot 0x84), then the ids listed in [[0x7003b8]+0x4a0 .. +0x4a4).
// kind 0/2 = owner is the id of the object at this[0x44] (kind 2: also a filter object arg[4]); kind 1 = from the struct arg; other kinds assert.
static void body_5833e0(u8 *ebx, u32 kind, u8 *arg) {
  u8 fr[0x108];
  { void *d = fr; u32 n = sizeof fr; asm volatile("rep stosb" : "+D"(d), "+c"(n) : "a"(0xcc) : "memory"); }
#define EBP (fr + 0x100)
#define P(off) (EBP - (off))
  u8 *eng = G(u8 *, 0x70039c);
  W32(P(0xe0), 0);
  u32 edi;
  bool haveedi = true;
  auto assert_hook = [&]() {
    Hook h = G(Hook, 0x7003b0);
    if (!h) __builtin_trap();
    h(arg);
  };
  if (kind == 2) {
    W32(P(0xe0), R32(arg + 4));
    kind = 0;
  }
  if (kind == 0) {
    u8 *o = (u8 *)R32(ebx + 0x44);
    u8 al = (u8)(*(u32(THISCALL **)(void *, u32))(vt(o) + 0x1e0))(o, 0x200006);
    if (al) {
      u8 *T = (u8 *)R32(eng + 0x9b);
      edi = (*(u32(THISCALL **)(void *, u32))(vt(T) + 0x4c))(T, R32(ebx + 0x44));
    } else {
      edi = 0;
    }
    W32(P(0xd4), edi);
  } else if (kind == 1) {
    if (arg == 0) {
      assert_hook();
      edi = R32(P(0xd4));
      W32(P(0xd4), edi);
    } else {
      edi = R32(arg);
      W32(P(0xd4), edi);
      if (edi == 0) {
        edi = R32(arg + 4);
        if (edi != 0) {
          edi = R32((u8 *)edi + 0x24);
        } else {
          assert_hook();
          edi = R32(P(0xd4));
        }
        W32(P(0xd4), edi);
      }
    }
  } else {
    assert_hook();
    edi = R32(P(0xd4));
    W32(P(0xd4), edi);
  }
  (void)haveedi;
  u8 *G7 = G(u8 *, 0x7003b8);
  u32 edx = R32(G7 + 0x4ac);
  if (edx) {
    u8 *T = (u8 *)R32(eng + 0x9b);
    W32(ebx + 0x5e, (*(u32(THISCALL **)(void *, u32))(vt(T) + 0x4c))(T, edx));
  }
  u8 *esi = (u8 *)R32(ebx + 0x44);
  W32(P(0xf4), (u32)esi);
  (*(u32(THISCALL **)(void *, u8 *, u8 *))(vt(esi) + 0x80))(esi, P(0x7c), P(0x28));
  u8 *blk = (u8 *)R32(esi + 8);
  ext_4daf90(blk, P(0x4c));
  ext_4db7c0((u8 *)R32(esi + 8), P(0x58));
  u32 r20 = (*(u32(THISCALL **)(void *))(vt(esi) + 0x20))(esi);
  ext_584aa0(ebx, r20, R32(esi + 8), R32(esi + 8) + 0x24);
  G7 = G(u8 *, 0x7003b8);
  float rad = RF(ebx + 0x51);
  u8 *it = (u8 *)R32(G7 + 0x2c11);
  W32(P(0xe4), 0xffffffffu);
  W32(P(0xdc), (u32)it);
  typedef u32(THISCALL * V4)(void *, u8 *, float, u8 *, u32);
  esi = (u8 *)(*(V4 *)(vt(it) + 0x84))(it, P(0x28), rad, P(0xe4), 0xffffffffu);
  while (esi) {
    (*(u32(THISCALL **)(void *, u8 *, u8 *))(vt(esi) + 0x384))(esi, P(0xa0), P(0x10));
    u8 *own = (u8 *)R32(P(0xf4));
    W32(P(0x14), R32(P(8)));
    __builtin_memcpy(P(0x1c), P(0x10), 8);
    (*(u32(THISCALL **)(void *, u8 *))(vt(own) + 0x8c))(own, P(0x1c));
    ext_43e960(P(0x1c), P(0x4c));
    float d = ext_4e2120(P(0x1c), P(0x58));
    WF(P(0xd8), d);
    if (!(RF(P(0xd8)) > RF(ebx + 0x51))) {
      float x1 = RF(P(0xd8));
      float m = (0.0f > x1) ? 0.0f : x1;
      WF(P(0xd8), m);
      u32 ctx = R32(P(0xe0));
      bool ok = true;
      if (ctx) ok = (u8)ext_5dbed0((void *)ctx, P(0x10)) != 0;
      if (ok) {
        ext_43e920(P(0xf0), P(0x10), P(0x28));
        WF(P(0x34), 0.1f);
        WF(P(0x30), 1.0f);
        WF(P(0x2c), 0.1f);
        ext_4e0a10(P(0x40));
        ext_4e0980(P(0x40), P(0x34));
        ext_451890(P(0x10), P(0x40), 100.0f);
        float x2 = RF(P(0xd8));
        float x0 = RF(ebx + 0x51) - RF(ebx + 0x55);
        x2 = x2 - RF(ebx + 0x55);
        float x3 = RF(P(0xe8));
        W32(P(0xf8), (u32)P(0xb4));
        W32(P(0xc4), 0);
        W32(P(0xc8), 4);
        W32(P(0xcc), 0);
        W32(P(0xd0), R32(P(0xd4)));
        x2 = x2 / x0;
        float v0 = G(float, 0x678858) - x2;
        WF(P(0xac), x3);
        float y2 = RF(P(0xec));
        WF(P(0xb0), y2);
        v0 = v0 * RF(ebx + 0x59);
        WF(P(0xa8), v0);
        WF(P(0xc0), RF(P(0x10)));
        WF(P(0xbc), RF(P(0xc)));
        WF(P(0xb8), RF(P(8)));
        float x4 = RF(P(0xf0));
        WF(P(0xb4), x4);
        if (!(x4 == 0.0f && y2 == 0.0f && x3 == 0.0f)) {
          WF(P(0xd8), 1.0f);
          WF(P(0xd8), normalise((u8 *)R32(P(0xf8))));
        }
        typedef u32(THISCALL * V3)(void *, u32, u8 *, u32);
        (*(V3 *)(vt(esi) + 0x128))(esi, (u32)G(u16, 0x714288), P(0xd0), 0);
      }
    }
    it = (u8 *)R32(P(0xdc));
    W32(P(0xe4), R32(P(0xe4)));
    esi = (u8 *)(*(V4 *)(vt(it) + 0x84))(it, P(0x28), RF(ebx + 0x51), P(0xe4), 0xffffffffu);
  }
  G7 = G(u8 *, 0x7003b8);
  u8 *ep = (u8 *)R32(G7 + 0x4a0);
  if (ep != (u8 *)R32(G7 + 0x4a4)) {
    do {
      u8 *T = (u8 *)R32(eng + 0x9b);
      esi = (u8 *)(*(u32(THISCALL **)(void *, u32))(vt(T) + 0x58))(T, R32(ep));
      if (esi) {
        W32(P(0x14), R32(P(0x20)));
        __builtin_memcpy(P(0x1c), P(0x28), 8);
        (*(u32(THISCALL **)(void *, u8 *))(vt(esi) + 0x8c))(esi, P(0x1c));
        ext_441940(P(0x1c), (u8 *)R32(esi + 8) + 0x30);
        float d = ext_4e2120(P(0x1c), (u8 *)R32(esi + 8) + 0x40);
        WF(P(0xdc), d);
        float m = (0.0f > RF(P(0xdc))) ? 0.0f : RF(P(0xdc));
        WF(P(0xdc), m);
        if (RF(ebx + 0x51) > m) {
          W32(P(0x10), 0);
          W32(P(0xc), 0);
          W32(P(8), 0);
          (*(u32(THISCALL **)(void *, u8 *))(vt(esi) + 0x84))(esi, P(0x10));
          ext_43e920(P(0xf0), P(0x28), P(0x10));
          float x0 = RF(ebx + 0x51) - RF(ebx + 0x55);
          float x2 = RF(P(0xdc)) - RF(ebx + 0x55);
          float x3 = RF(ebx + 0x59);
          W32(P(0xc8), 4);
          x2 = x2 / x0;
          float v0 = G(float, 0x678858) - x2;
          v0 = v0 * x3;
          WF(P(0xa8), v0);
          if (v0 > x3) WF(P(0xa8), x3);
          WF(P(0xc0), RF(P(0x10)));
          WF(P(0xbc), RF(P(0xc)));
          WF(P(0xb8), RF(P(8)));
          float y2 = RF(P(0xec)), z3 = RF(P(0xe8));
          W32(P(0xd0), R32(P(0xd4)));
          W32(P(0xdc), (u32)P(0xb4));
          W32(P(0xcc), 0);
          float x4 = RF(P(0xf0));
          WF(P(0xb4), x4);
          WF(P(0xb0), y2);
          WF(P(0xac), z3);
          if (!(x4 == 0.0f && y2 == 0.0f && z3 == 0.0f)) {
            WF(P(0xd8), 1.0f);
            WF(P(0xd8), normalise((u8 *)R32(P(0xdc))));
          }
          typedef u32(THISCALL * V3)(void *, u32, u8 *, u32);
          (*(V3 *)(vt(esi) + 0x128))(esi, (u32)G(u16, 0x714288), P(0xd0), 0);
        }
      }
      ep += 4;
      G7 = G(u8 *, 0x7003b8);
    } while (ep != (u8 *)R32(G7 + 0x4a4));
  }
}
extern "C" void THISCALL fn_5833e0(u8 *self, u32 kind, u8 *arg);
extern "C" void THISCALL fn_5833e0(u8 *self, u32 kind, u8 *arg) {
  body_5833e0(self, kind, arg);
  ext_633654(G(u32, 0x6f5630));
}
PCREG(5833e0, fn_5833e0);
