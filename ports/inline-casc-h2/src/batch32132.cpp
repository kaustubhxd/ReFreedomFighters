// batch32132.cpp - cascade h2 (Sonnet): three tier H (float / SSE / x87) functions.
#include "ff.h"
#include <xmmintrin.h>

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static inline float rdf(const u8 *p) { u32 b = rd32(p); float f; __builtin_memcpy(&f, &b, 4); return f; }
static inline void wrf(u8 *p, float f) { u32 b; __builtin_memcpy(&b, &f, 4); wr32(p, b); }

extern "C" void THISCALL ext_5c9330(u8 *self, u32 a);   // thiscall ret 4
extern "C" void THISCALL ext_5c8650(u8 *self);          // thiscall
extern "C" u8 THISCALL ext_5c8470(u8 *self, u32 a);     // thiscall ret 4, returns al
extern "C" void THISCALL ext_5c92a0(u8 *self);          // thiscall (tail jump)

// 0x516f40, thiscall(p) ret 4: the 3 dwords at p are copied (unaligned) to this+0x45; unless all three floats are ordered-equal to 0 the vector is normalised:
// len = sqrt(x*x + y*y + z*z) in x87 53-bit precision, inv = 1.0 / len, component = (float)(c * inv).
static void THISCALL fn516f40(u8 *self, u8 *p) {
  u8 *d = self + 0x45;
  wr32(d, rd32(p));
  wr32(d + 4, rd32(p + 4));
  wr32(d + 8, rd32(p + 8));
  if (rdf(d) == 0.0f && rdf(d + 4) == 0.0f && rdf(d + 8) == 0.0f) return;
  double x = (double)rdf(d), y = (double)rdf(d + 4), z = (double)rdf(d + 8);
  double s = x * x;
  s = s + y * y;
  s = s + z * z;
  double len;
  __asm__("sqrtsd %1, %0" : "=x"(len) : "x"(s));
  double inv = 1.0 / len;
  wrf(d, (float)(x * inv));
  wrf(d + 4, (float)(y * inv));
  wrf(d + 8, (float)(z * inv));
}
PCREG(516f40, fn516f40);

// 0x5c8d40, thiscall no args: s = [this+0x88]; s == 0 -> return. t = (int)trunc((float)[this+0x8c] * 1024.0f);
// if (int)[eng+0x40] > t: [this+0x88] = 0; slot 0x12c of [this+0x44] with (s, word [0x714380], 0); if [this+0x88] == 0 now: [this+0x80] = 0;
// o = slot 0x58 of [[eng+0x9b]] with [this+0x70]; 0x5c9330(this, 0); slot 0x288 of [this+0x44] with (o, 0, 1); return.
// Then (also when [eng+0x40] <= t or [this+0x88] was set by the slot): if [this+0x80] == 0 return; 0x5c8650(this); if 0x5c8470(this, [this+0x80]) (al) tail jump 0x5c92a0(this).
static void THISCALL fn5c8d40(u8 *self) {
  u32 s = *(u32 *)(self + 0x88);
  if (s == 0) return;
  float f = *(float *)(self + 0x8c) * 1024.0f;
  u8 *eng = G(u8 *, 0x70039c);
  s32 t = _mm_cvttss_si32(_mm_set_ss(f));
  if ((s32)*(u32 *)(eng + 0x40) > t) {
    void *o44 = *(void **)(self + 0x44);
    *(u32 *)(self + 0x88) = 0;
    vcall<void>(o44, 0x12c, s, (u32)G(u16, 0x714380), 0u);
    if (*(u32 *)(self + 0x88) == 0) {
      u32 arg = *(u32 *)(self + 0x70);
      *(u32 *)(self + 0x80) = 0;
      u8 *eng2 = G(u8 *, 0x70039c);
      u32 o = vcall<u32>(*(void **)(eng2 + 0x9b), 0x58, arg);
      ext_5c9330(self, 0);
      vcall<void>(*(void **)(self + 0x44), 0x288, o, 0u, 1u);
      return;
    }
  }
  if (*(u32 *)(self + 0x80) == 0) return;
  ext_5c8650(self);
  if (ext_5c8470(self, *(u32 *)(self + 0x80))) ext_5c92a0(self);
}
PCREG(5c8d40, fn5c8d40);

// 0x435ed0, thiscall(out) ret 4: if [this+0x1c] != 0: p = slot 0x10 of [this+0x10]; if p: a = (float)(int)slot 0xd8 of [[0x70039c]+0x190f]; b = (float)(int)slot 0xdc (same object);
// out[1] = max(-0.5f, min(0.5f, ([this+0x68] - b*0.5f) / b)); out[0] = max(-0.5f, min(0.5f, ([this+0x64] - a*0.5f) / a)); out[2] = [p+8].
static void THISCALL fn435ed0(u8 *self, u8 *out) {
  if (rd32(self + 0x1c) == 0) return;
  u8 *p = vcall<u8 *>(*(void **)(self + 0x10), 0x10);
  if (!p) return;
  u32 ia = vcall<u32>(*(void **)(G(u8 *, 0x70039c) + 0x190f), 0xd8);
  float a = (float)(s32)ia;
  u32 ib = vcall<u32>(*(void **)(G(u8 *, 0x70039c) + 0x190f), 0xdc);
  float b = (float)(s32)ib;
  const float K = 0.5f, K2 = -0.5f;
  float y = (rdf(self + 0x68) - b * K) / b;
  float m1 = (K < y) ? K : y;
  float r1 = (K2 > m1) ? K2 : m1;
  wrf(out + 4, r1);
  float x = (rdf(self + 0x64) - a * K) / a;
  float m0 = (K < x) ? K : x;
  float r0 = (K2 > m0) ? K2 : m0;
  wrf(out, r0);
  wr32(out + 8, rd32(p + 8));
}
PCREG(435ed0, fn435ed0);
