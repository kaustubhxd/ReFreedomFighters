// batch48001.cpp - cascade tier H, batch 48001: 0x5e3b40 (pick a sub-object by owner flags, read its keyed value and advance this->time).
#include "ff.h"

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static inline float ld(u8 *p) { return bitsf(rd32(p)); }

// object at [this+off] has its vtable pointer at +0 (unaligned); slot 0x14(t) returns a pointer to a dword (or 0); slot 0xc(t) returns a float
static inline float step(u8 *self, u32 off, u32 *out) {
  u8 *sub = self + off;
  u32 *r = vcall<u32 *>(sub, 0x14, ld(self + 0xc));
  if (r) *out = *r;
  float t = vcall<float>(sub, 0xc, ld(self + 0xc));
  return t;
}

// 0x5e3b40, thiscall(out, 4 unused dwords) ret 0x14, returns float st0. *out = 0. flags = [[this+4]+0x417] (unaligned).
// 0x800: step on this+0x125; 0x8000000: step on this+0x155 (the slot 0xc result goes to [this+0xc]) and when (int)([this+0x185] * c0x678620) < [sys+0x40]
// P->slot 0x400((float)[sys+0x40] * c0x6785e4) and [this+0x185] = (float)([sys+0x40] + 0x200 + (int)(sys->slot 0x1c0(0x6b7a5c, 0x5b) * c0x67a6ac * c0x678620)) * c0x6785e4;
// otherwise: !P->slot 0x534() && flags & 0x400: step this+0x13d; else flags & 0x10000000: this+0x16d, else this+0x10d. Always ends with this+0x10d slot 4(); returns [this+0xc].
static float THISCALL fn5e3b40(u8 *self, u32 *out, u32 a2, u32 a3, u32 a4, u32 a5) {
  *out = 0;
  u8 *P = *(u8 **)(self + 4);
  u32 flags = rd32(P + 0x417);
  float t;
  if (flags & 0x800) {
    t = step(self, 0x125, out);
    wr32(self + 0xc, fbits(t));
  } else if (flags & 0x8000000) {
    t = step(self, 0x155, out);
    wr32(self + 0xc, fbits(t));
    float x = ld(self + 0x185);
    int e = _mm_cvttss_si32(_mm_mul_ss(_mm_set_ss(x), _mm_set_ss(G(float, 0x678620))));
    int lim = *(int *)(G(u8 *, 0x70039c) + 0x40);
    if (e < lim) {
      vcall<void>(*(u8 **)(self + 4), 0x400, _mm_cvtss_f32(_mm_mul_ss(_mm_cvtepi32_ps(_mm_cvtsi32_si128(lim)), _mm_set_ss(G(float, 0x6785e4)))));
      float rnd = vcall<float>(G(u8 *, 0x70039c), 0x1c0, 0x6b7a5cu, 0x5bu);
      float prod = (float)(((long double)rnd * (long double)G(float, 0x67a6ac)) * (long double)G(float, 0x678620));
      int add = _mm_cvttss_si32(_mm_set_ss(prod));
      int sum = *(int *)(G(u8 *, 0x70039c) + 0x40) + (add + 0x200);
      float nv = _mm_cvtss_f32(_mm_mul_ss(_mm_cvtepi32_ps(_mm_cvtsi32_si128(sum)), _mm_set_ss(G(float, 0x6785e4))));
      wr32(self + 0x185, fbits(nv));
    }
  } else {
    u8 al = vcall<u8>(*(u8 **)(self + 4), 0x534);
    if (!al && (rd32(*(u8 **)(self + 4) + 0x417) & 0x400)) {
      t = step(self, 0x13d, out);
    } else if (rd32(*(u8 **)(self + 4) + 0x417) & 0x10000000) {
      t = step(self, 0x16d, out);
    } else {
      t = step(self, 0x10d, out);
    }
    wr32(self + 0xc, fbits(t));
  }
  vcall<void>(self + 0x10d, 4);
  return ld(self + 0xc);
}
PCREG(5e3b40, fn5e3b40);
