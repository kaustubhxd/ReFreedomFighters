// batch34155.cpp - cascade tier H, batch 34155: 0x5186d0 (store a pow-scaled float), 0x46d290 (read three values from a source), 0x4e7880 (set up an entry), 0x535990 (score from three floats).
#include "ff.h"

extern "C" float THISCALL ext_4e5e80(void *self);           // float in st0
extern "C" u32 THISCALL ext_4e5e60(void *self);
extern "C" void THISCALL ext_4e7ce0(void *self, u32 a);     // ret 4
extern "C" void THISCALL ext_4e7c50(void *self, u32 a);     // ret 4

static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x5186d0, thiscall(f1, f2, i) ret 0xc: when f1 differs from the constant at 0x6785d0 (0.0, or is NaN): unaligned float [this+0x163d] = (float)pow(10.0 (double at 0x692790), (double)(f1 / constant 0x67da20)) through the CRT pow import [0x67634c] (xmm0 base, xmm1 exponent);
// then unaligned [this+0x1641] = f2 bits and [this+0x1645] = i.
static void THISCALL fn5186d0(u8 *self, u32 f1, u32 f2, u32 i) {
  float f = bitsf(f1);
  if (!(f == G(float, 0x6785d0))) {
    __m128 x = _mm_div_ss(_mm_set_ss(f), _mm_set_ss(G(float, 0x67da20)));
    double e = _mm_cvtsd_f64(_mm_cvtps_pd(x));
    double base = G(double, 0x692790);
    double r;
    asm volatile("movsd %[b], %%xmm0\n\tmovsd %[e], %%xmm1\n\tcall *0x67634c\n\tmovsd %%xmm0, %[r]" : [r] "=m"(r) : [b] "m"(base), [e] "m"(e)
                 : "eax", "ecx", "edx", "xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7", "memory", "cc");
    float rf = (float)r;
    wr32(self + 0x163d, __builtin_bit_cast(u32, rf));
  }
  wr32(self + 0x1641, f2);
  wr32(self + 0x1645, i);
}
PCREG(5186d0, fn5186d0);

// 0x46d290, thiscall(s) ret 4: [this+0x4c] = ext_4e5e80(s) (float); byte [this+0x50] = ext_4e5e60(s) != 0; byte [this+0x51] = ext_4e5e60(s) != 0 (two calls).
static void THISCALL fn46d290(u8 *self, u8 *s) {
  float x = ext_4e5e80(s);
  *(float *)(self + 0x4c) = x;
  self[0x50] = ext_4e5e60(s) != 0;
  self[0x51] = ext_4e5e60(s) != 0;
}
PCREG(46d290, fn46d290);

// 0x4e7880, thiscall(a, p, b, f) ret 0x10: unaligned [this+9] = a; [this] = p; byte [this+8] = b; float [this+4] = f (bits); ext_4e7ce0(this, 0); ext_4e7c50(this, -1).
static void THISCALL fn4e7880(u8 *self, u32 a, u32 p, u32 b, u32 f) {
  wr32(self + 9, a);
  *(u32 *)self = p;
  self[8] = (u8)b;
  *(u32 *)(self + 4) = f;
  ext_4e7ce0(self, 0);
  ext_4e7c50(self, (u32)-1);
}
PCREG(4e7880, fn4e7880);

// 0x535990, stdcall(a, b, c) ret 0xc: x = (a == 0.0) ? constant 0x678858 (1.0) : a; r = (x > b) ? (x / b)^2 * constant 0x680a70 : 0; returns cvtt((constant 0x67cd40 - c) * constant 0x6a24f4 - r).
static s32 STDCALL fn535990(u32 ab, u32 bb, u32 cb) {
  float a = bitsf(ab);
  __m128 x0 = _mm_set_ss(a);
  __m128 x1 = _mm_setzero_ps();
  if (a == 0.0f) x0 = _mm_set_ss(G(float, 0x678858));
  __m128 x2 = _mm_set_ss(bitsf(bb));
  if (_mm_comigt_ss(x0, x2)) x1 = _mm_div_ss(x0, x2);
  __m128 y0 = _mm_sub_ss(_mm_set_ss(G(float, 0x67cd40)), _mm_set_ss(bitsf(cb)));
  x1 = _mm_mul_ss(x1, x1);
  y0 = _mm_mul_ss(y0, _mm_set_ss(G(float, 0x6a24f4)));
  x1 = _mm_mul_ss(x1, _mm_set_ss(G(float, 0x680a70)));
  y0 = _mm_sub_ss(y0, x1);
  return _mm_cvttss_si32(y0);
}
PCREG(535990, fn535990);
