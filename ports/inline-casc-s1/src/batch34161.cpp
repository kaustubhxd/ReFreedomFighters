// batch34161.cpp - cascade tier H, batch 34161: 0x52a300 (reset three blocks from exe constants), 0x421810 (read a vector and a clock), 0x4b0f90 (read four floats and a pow), 0x5ab970 (scaled float of a child's vector).
#include "ff.h"

extern "C" void THISCALL ext_52cea0(void *self, u32 a);        // ret 4
extern "C" u8 *THISCALL ext_52cf60(void *self, u32 a);         // ret 4
extern "C" void THISCALL ext_42d730(void *self, void *s);      // ret 4
extern "C" float THISCALL ext_4e5e80(void *self);              // float in st0
extern "C" void THISCALL ext_4db7c0(void *self, void *v);      // ret 4
extern "C" void FASTCALL ext_633654(u32 cookie);                // /GS check
typedef int (*clock_t_)(void);

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void cp(u8 *dst, u32 src, int n) { const u8 *k = (const u8 *)src; for (int i = 0; i < n; i++) dst[i] = k[i]; }

// 0x52a300, thiscall(a) ret 4, returns this: ext_52cea0(this, a); ext_52cea0(this + 0x51, a); ext_52cf60(this + 0xa2, a); then copies exe constants: 0x6a0efc (16) -> +0x51, 0x6a0f0c (1) -> +0x61, 0x6a0f10 (16) -> +0, 0x6a0f20 (8) -> +0x10, 0x6a0f28 (1) -> +0x18.
static u8 *THISCALL fn52a300(u8 *self, u32 a) {
  ext_52cea0(self, a);
  ext_52cea0(self + 0x51, a);
  ext_52cf60(self + 0xa2, a);
  cp(self + 0x51, 0x6a0efc, 16);
  cp(self + 0x61, 0x6a0f0c, 1);
  cp(self, 0x6a0f10, 16);
  cp(self + 0x10, 0x6a0f20, 8);
  cp(self + 0x18, 0x6a0f28, 1);
  return self;
}
PCREG(52a300, fn52a300);

// 0x421810, thiscall(s) ret 4: ext_42d730(this, s); s->slot0x54(this + 0x23c6); s->slot0x5c(this + 0x23ce); t = clock() (CRT import [0x676434]); double at [this+0xc] = (double)(float)((double)t * 0.001 (constant 0x6785e8)); this->slot0x170().
static void THISCALL fn421810(u8 *self, u8 *s) {
  ext_42d730(self, s);
  vcall<void>(s, 0x54, (u32)(self + 0x23c6));
  vcall<void>(s, 0x5c, (u32)(self + 0x23ce));
  int t = G(clock_t_, 0x676434)();
  double d = _mm_cvtsd_f64(_mm_mul_sd(_mm_cvtepi32_pd(_mm_cvtsi32_si128(t)), _mm_set_sd(G(double, 0x6785e8))));
  float f = _mm_cvtss_f32(_mm_cvtpd_ps(_mm_set_sd(d)));
  *(double *)(self + 0xc) = (double)f;
  vcall<void>(self, 0x170);
}
PCREG(421810, fn421810);

// 0x4b0f90, thiscall(s) ret 4: [this+0x5c], [this+0x58], [this+0x54] = three successive ext_4e5e80(s) floats; f4 = a fourth; r = pow(10.0 (double at 0x692790), f4 / 20.0 (constant 0x67da20)) through the CRT pow import [0x67634c]; [this+0x64] = (float)(1.0 (double at 0x678610) / r).
static void THISCALL fn4b0f90(u8 *self, u8 *s) {
  float a = ext_4e5e80(s);
  *(float *)(self + 0x5c) = a;
  float b = ext_4e5e80(s);
  *(float *)(self + 0x58) = b;
  float c = ext_4e5e80(s);
  *(float *)(self + 0x54) = c;
  float f4 = ext_4e5e80(s);
  double e = (double)f4 / (double)G(float, 0x67da20);
  double base = G(double, 0x692790);
  double r;
  asm volatile("movsd %[b], %%xmm0\n\tmovsd %[e], %%xmm1\n\tcall *0x67634c\n\tmovsd %%xmm0, %[r]" : [r] "=m"(r) : [b] "m"(base), [e] "m"(e)
               : "eax", "ecx", "edx", "xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7", "memory", "cc");
  double q = _mm_cvtsd_f64(_mm_div_sd(_mm_set_sd(G(double, 0x678610)), _mm_set_sd(r)));
  *(float *)(self + 0x64) = _mm_cvtss_f32(_mm_cvtpd_ps(_mm_set_sd(q)));
}
PCREG(4b0f90, fn4b0f90);

// 0x5ab970, thiscall plain, returns an int; /GS check: when ([this+0x72] - [this+0x6e], unaligned) has no bits above 0xf the result is 0; else p = unaligned [this+0x6e], ext_4db7c0([[p+8]+8], &v) and the result is cvtt(v[1] * constant 0x680a60).
static s32 THISCALL fn5ab970(u8 *self) {
  s32 res = 0;
  u32 diff = rd32(self + 0x72) - rd32(self + 0x6e);
  if (diff & 0xfffffff0) {
    float v[4];
    u8 *p = (u8 *)rd32(self + 0x6e);
    ext_4db7c0(*(u8 **)(*(u8 **)(p + 8) + 8), v);
    res = _mm_cvttss_si32(_mm_mul_ss(_mm_set_ss(v[1]), _mm_set_ss(G(float, 0x680a60))));
  }
  ext_633654(0);
  return res;
}
PCREG(5ab970, fn5ab970);
