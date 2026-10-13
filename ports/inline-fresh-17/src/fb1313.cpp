// fb1313.cpp - fresh slice 17, batch 13.
#include "ff.h"

extern "C" void FASTCALL ext_43e920(float *out, const float *a, const float *b);   // PSVECSubtract (out = a - b)
extern "C" void FASTCALL ext_446ee0(float *out, const float *a, const float *b);   // vcross
extern "C" u32 THISCALL ext_4cbec0(void *str);                                     // MYSTR::~MYSTR
extern "C" u32 ext_4690b0(void *p, u32 line);
extern "C" u32 THISCALL ext_54f870(void *self, void *p, u32 size);
extern "C" void *ext_45c4f0(u32 size, u32 pool);
extern "C" void *ext_45c4b0(u32 size);
extern "C" u32 FASTCALL ext_4808d0(u32 a, u32 b, u32 c, u32 d);
extern "C" u32 THISCALL ext_480a40(void *self, u32 info, u32 name, u32 geom);       // ZPlayer::ZPlayer
extern "C" u32 THISCALL ext_43e990(void *self, u32 info, u32 name, u32 geom);       // ZGROUP::ZGROUP

typedef void (*voidfn)();
#define g_pAssertHook G(voidfn, 0x7003b0)

static inline void *engineDb() { return *(void **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x453a50 ZGATE::GetRootNormal(float* n): n = (p1 - p0) x (p2 - p0) for the corners at +0x22, +0x2e, +0x3a
// (PSVECSubtract, vcross), normalised unless all three components are 0 (NaN counts as non-zero; x87 maths in long double so it follows the
// FPU control word like the exe: sqrt(x*x + y*y + z*z), 1 / len, each component times it), then this slot +0x88(n).
static void THISCALL getRootNormal453a50(u8 *self, float *n) {
  float d1[3], d2[3];
  ext_43e920(d1, (const float *)(self + 0x2e), (const float *)(self + 0x22));
  ext_43e920(d2, (const float *)(self + 0x3a), (const float *)(self + 0x22));
  ext_446ee0(n, d1, d2);
  if (!(n[0] == 0.0f && n[1] == 0.0f && n[2] == 0.0f)) {
    long double x = n[0], y = n[1], z = n[2];
    long double inv = 1.0L / fsqrt_x87(x * x + y * y + z * z);
    n[0] = (float)((long double)n[0] * inv);
    n[1] = (float)((long double)n[1] * inv);
    n[2] = (float)((long double)n[2] * inv);
  }
  vcall<u32>(self, 0x88, n);
}
PCREG(453a50, getRootNormal453a50);

// 0x4b13d0 CCutSequenceShowHide::~CCutSequenceShowHide() (deleting): ~MYSTR(+0x55), then the ZEventBase-like teardown of
// 0x4c3990 (fb1212.cpp) with line 0xd5. SEH not reproduced.
static u8 *THISCALL dtor4b13d0(u8 *self, u32 flags) {
  ext_4cbec0(self + 0x55);
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  vcall<u32>(engineDb(), 0x34, self);
  if (flags & 1) {
    if (!(flags & 4)) {
      if (!g_pAssertHook)
        __builtin_debugtrap();
      g_pAssertHook();
      return self;
    }
    ext_4690b0(self, 0xd5);
  }
  return self;
}
PCREG(4b13d0, dtor4b13d0);

// 0x5fad90 (GUESS destructor of four host vectors at +0x38, +0x2c, +0x20, +0x14 in that order): each non-empty block
// (begin set and capacity bytes (+8 - begin) non-zero) goes back through 0x54f870(vec, begin, bytes). SEH not reproduced.
static void THISCALL dtor5fad90(u8 *self) {
  static const u32 offs[4] = {0x38, 0x2c, 0x20, 0x14};
  for (int i = 0; i < 4; i++) {
    u32 *v = (u32 *)(self + offs[i]);
    u32 b = v[0], n = v[2] - b;
    if (b && n)
      ext_54f870(v, (void *)b, n);
  }
}
PCREG(5fad90, dtor5fad90);

// 0x65a3d0 (GUESS MMX blend, fastcall (dst, src) + stack (a, b, c, n)): for (n + 3) / 4 blocks of 16 words:
// dst += ((((b * c) >> 16) << 4) + a) * src >> 16 << 4, lane-wise with a and b being 4-word vectors (pmulhw, psllw 4,
// paddw: 16-bit wrap-around). n must be >= 1 (0 loops 2^32 times in the exe).
static inline s16 mulhw(s16 x, s16 y) { return (s16)(((s32)x * (s32)y) >> 16); }
static void FASTCALL blend65a3d0(s16 *dst, const s16 *src, const s16 *a, const s16 *b, const s16 *c, u32 n) {
  s16 va[4], vb[4];
  for (int k = 0; k < 4; k++) {
    va[k] = a[k];
    vb[k] = b[k];
  }
  u32 blocks = (n + 3) >> 2;
  do {
    for (int j = 0; j < 16; j++) {
      s16 t = (s16)((u16)mulhw(vb[j & 3], c[j]) << 4);
      t = (s16)(u16)((u16)t + (u16)va[j & 3]);
      t = (s16)((u16)mulhw(t, src[j]) << 4);
      dst[j] = (s16)(u16)((u16)t + (u16)dst[j]);
    }
    c += 16;
    src += 16;
    dst += 16;
  } while (--blocks);
}
PCREG(65a3d0, blend65a3d0);

// 0x481450 (GUESS ZPlayer-derived factory, fastcall (info, name) + stack (geom, existing)): with `existing` -> 0x4808d0
// (existing, geom, info, name). Else 0x64b bytes from 0x45c4b0; null -> 0; ZPlayer::ZPlayer(p, geom, info, name), vtable
// 0x68c0bc, and the engine's +0x1907 object (when set) gets slot +0xc(0x6e6048, 0x68c708, 0). SEH not reproduced.
static u32 FASTCALL create481450(u32 info, u32 name, u32 geom, u32 existing) {
  if (existing)
    return ext_4808d0(existing, geom, info, name);
  u8 *p = (u8 *)ext_45c4b0(0x64b);
  if (!p)
    return 0;
  ext_480a40(p, geom, info, name);
  *(u32 *)p = 0x68c0bc;
  void *x = *(void **)(G(u8 *, 0x70039c) + 0x1907);
  if (x)
    vcall<u32>(x, 0xc, 0x6e6048u, 0x68c708u, 0u);
  return (u32)p;
}
PCREG(481450, create481450);

// 0x441ad0 (GUESS ZGROUP-derived factory, fastcall (pool, info) + stack (name, geom)): 0x83 bytes from 0x45c4f0(0x83,
// pool); null -> 0; ZGROUP::ZGROUP(p, info, name, geom), vtable 0x67cdbc, fields +0x5c..+0x82 cleared (+0x7f = -1).
// SEH not reproduced.
static u8 *FASTCALL create441ad0(u32 pool, u32 info, u32 name, u32 geom) {
  u8 *p = (u8 *)ext_45c4f0(0x83, pool);
  if (!p)
    return 0;
  ext_43e990(p, info, name, geom);
  *(u32 *)p = 0x67cdbc;
  *(u32 *)(p + 0x7b) = 0;
  *(u32 *)(p + 0x71) = 0;
  p[0x5c] = 0;
  *(u16 *)(p + 0x75) = 0;
  *(u32 *)(p + 0x77) = 0;
  *(u32 *)(p + 0x7f) = 0xffffffffu;
  for (int i = 0; i < 16; i++)
    p[0x5d + i] = 0;
  *(u32 *)(p + 0x6d) = 0;
  return p;
}
PCREG(441ad0, create441ad0);
