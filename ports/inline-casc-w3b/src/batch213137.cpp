#include "ff.h"

typedef u32(THISCALL *V2)(void *, u32, u32);

static inline u8 *vt(void *o) { return *(u8 **)o; }
static inline float rf(const u8 *base, u32 off) { float v; __builtin_memcpy(&v, base + off, 4); return v; }
static inline void wf(u8 *base, u32 off, float v) { __builtin_memcpy(base + off, &v, 4); }
static inline void cp(u8 *base, u32 dst, u32 src) { u32 v; __builtin_memcpy(&v, base + src, 4); __builtin_memcpy(base + dst, &v, 4); }
static inline float minss(float dst, float src) { return (dst < src) ? dst : src; }
static inline float cf(u32 a) { return G(float, a); }

static inline u32 fmt3d(u32 fn, u32 ecx_, u32 O, u32 fmt, double d) {
  u32 r;
  __asm__ volatile("subl $8,%%esp; movsd %[d],(%%esp); pushl %[fmt]; pushl %[O]; call *%%eax; addl $16,%%esp"
                   : "=a"(r), "+c"(ecx_) : "0"(fn), [d] "x"(d), [fmt] "r"(fmt), [O] "r"(O) : "edx", "memory", "cc");
  return r;
}

static void report(float d) {
  u8 *E = G(u8 *, 0x700390);
  u8 *O = (u8 *)(*(V2 *)(vt(E) + 0x20))(E, 0x6b4d68, 0x8f);
  fmt3d(*(u32 *)(vt(O) + 0x2c), *(u32 *)O, (u32)O, 0x6b4db8, (double)d);
}

// 0x5d2ab0: thiscall(), void. Turret / aim smoothing on a pair of angles: yaw w = this+0xae9 (wrapped to +-pi) moves toward the target this+0xa54 at the rate this+0xaf1 (itself
// derived from the remaining error d, the gain this+0xb01 * [0x6b4fbc] * this+0xadd and the limit this+0xaf9), clamped by the limits [0x6b4fe8] / [0x6a09e4] when
// this[0xb45]; the error is re-evaluated after the step (and logged through [0x700390] when it is below [0x67af28]); pitch this+0xaed follows this+0xa5c at the rate this+0xaf5
// with the same scheme and a final clamp to [this+0xa96, this+0xa9a].
extern "C" void THISCALL fn_5d2ab0(u8 *self) {
  float TWO = cf(0x68aef8);
  float PI = cf(0x67da18);
  float NPI = cf(0x6ad238);
  float a54 = rf(self, 0xa54);
  float a = rf(self, 0xae9);
  float x1 = a54;
  if (a > x1) x1 = x1 + TWO;
  x1 = x1 - a;
  float d = x1;
  if (cf(0x67af28) > d) report(d);
  if (d > PI) d = d - TWO;
  else if (NPI > d) d = d + TWO;
  float k = rf(self, 0xaf9);
  if (k > cf(0x6785d0)) {
    float g = rf(self, 0xb01) * cf(0x6b4fbc);
    float q = d / k;
    g = g * rf(self, 0xadd);
    g = g * q;
    wf(self, 0xaf1, g);
  } else {
    cp(self, 0xaf1, 0xa60);
  }
  if (self[0xb45] != 0) {
    float v = rf(self, 0xaf1);
    float LIM = cf(0x6b4fe8);
    float U = cf(0x6a09e4);
    float r1 = (LIM > v) ? LIM : minss(U, v);
    wf(self, 0xaf1, r1);
    float a60 = rf(self, 0xa60);
    float r2 = (LIM > a60) ? LIM : minss(U, a60);
    wf(self, 0xa60, r2);
  }
  u8 *eng = G(u8 *, 0x70039c);
  float T7 = cf(0x6ad1fc);
  float m = rf(eng, 0x48) * rf(self, 0xaf1);
  if (m > T7 || cf(0x6ad234) > m) m = PI;
  m = m + rf(self, 0xae9);
  if (m > PI) m = m - TWO;
  else if (NPI > m) m = m + TWO;
  wf(self, 0xae9, m);
  float t2 = rf(self, 0xa54);
  if (m > t2) t2 = t2 + TWO;
  t2 = t2 - m;
  float d2 = t2;
  if (cf(0x67af28) > d2) report(d2);
  if (d2 > PI) d2 = d2 - TWO;
  else if (NPI > d2) d2 = d2 + TWO;
  float k3 = rf(self, 0xaf9);
  double ad = (double)d2;
  u64 bits;
  __builtin_memcpy(&bits, &ad, 8);
  bits &= 0x7fffffffffffffffULL;
  __builtin_memcpy(&ad, &bits, 8);
  if (ad >= (double)k3) {
    cp(self, 0xaf1, 0xa60);
    float n;
    if (0.0f > d2) {
      if (k3 > T7 || cf(0x6ad234) > k3) k3 = PI;
      n = rf(self, 0xa54) + k3;
    } else {
      if (k3 > T7 || cf(0x6ad234) > k3) k3 = PI;
      n = rf(self, 0xa54) - k3;
    }
    if (n > PI) n = n - TWO;
    else if (NPI > n) n = n + TWO;
    wf(self, 0xae9, n);
  }
  float k2 = rf(self, 0xafd);
  if (k2 > cf(0x6785d0)) {
    float x = rf(self, 0xa5c) - rf(self, 0xaed);
    float g = rf(self, 0xb01) * cf(0x6b4fb8);
    x = x / k2;
    g = g * rf(self, 0xadd);
    x = x * g;
    wf(self, 0xaf5, x);
  } else {
    cp(self, 0xaf5, 0xa64);
  }
  eng = G(u8 *, 0x70039c);
  float p1 = rf(self, 0xa5c);
  float w = rf(eng, 0x48) * rf(self, 0xaf5);
  w = w + rf(self, 0xaed);
  float e = p1 - w;
  wf(self, 0xaed, w);
  if (cf(0x6b4fdc) > e) {
    p1 = p1 + cf(0x6a066c);
    wf(self, 0xaed, p1);
    cp(self, 0xaf5, 0xa64);
  } else if (e > k2) {
    p1 = p1 - k2;
    wf(self, 0xaed, p1);
    cp(self, 0xaf5, 0xa64);
  }
  float cur = rf(self, 0xaed);
  float lo = rf(self, 0xa96);
  float res = (lo > cur) ? lo : minss(rf(self, 0xa9a), cur);
  wf(self, 0xaed, res);
}
PCREG(5d2ab0, fn_5d2ab0);
