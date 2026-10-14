// batch34152.cpp - cascade tier H, batch 34152: 0x423f90 (Sleep(float)), 0x4df9d0 (float + constant to int), 0x4dfda0 (vector length), 0x52b330 (error stub returning 0.0), 0x5efcc0 (conditional tail call), 0x4b89d0 (time check and reset), 0x535940 (log10 scale), 0x46abb0 (forward through a child).
#include "ff.h"

extern "C" void THISCALL ext_5ef240(void *self);             // plain ret
extern "C" void THISCALL ext_4b8ab0(void *self, u32 a);      // ret 4
typedef void (*hook_t)();
typedef u32 (STDCALL *sleep_t)(u32);

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// The exe's float-to-int helper 0x633910 takes the float in xmm0 and returns the int in eax (the real code runs).
static inline s32 ftol633910(float x) {
  s32 r;
  asm volatile("movss %[x], %%xmm0\n\tcall *%[fn]" : "=a"(r) : [x] "m"(x), [fn] "r"(0x633910u)
               : "ecx", "edx", "xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7", "memory", "cc");
  return r;
}

// 0x423f90, stdcall(f) ret 4: i = ftol(f); tail-jumps to KERNEL32 Sleep through [0x6760e4] with i in the argument slot. Returns its result.
static u32 STDCALL fn423f90(u32 f) { return G(sleep_t, 0x6760e4)((u32)ftol633910(bitsf(f))); }
PCREG(423f90, fn423f90);

// 0x4df9d0, stdcall(f) ret 4: returns ftol(f + constant at 0x67a6ac).
static u32 STDCALL fn4df9d0(u32 f) {
  float s = _mm_cvtss_f32(_mm_add_ss(_mm_set_ss(bitsf(f)), _mm_set_ss(G(float, 0x67a6ac))));
  return (u32)ftol633910(s);
}
PCREG(4df9d0, fn4df9d0);

// 0x4dfda0, thiscall plain, returns a float in st0: sqrt of ([this]^2 + [this+4]^2) through the CRT sqrt import [0x676330] (double in xmm0), narrowed to float.
static float THISCALL fn4dfda0(float *self) {
  __m128 s = _mm_add_ss(_mm_mul_ss(_mm_set_ss(self[0]), _mm_set_ss(self[0])), _mm_mul_ss(_mm_set_ss(self[1]), _mm_set_ss(self[1])));
  double d = _mm_cvtsd_f64(_mm_cvtps_pd(s));
  double r;
  asm volatile("movsd %[d], %%xmm0\n\tcall *0x676330\n\tmovsd %%xmm0, %[r]" : [r] "=m"(r) : [d] "m"(d)
               : "eax", "ecx", "edx", "xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7", "memory", "cc");
  return (float)r;
}
PCREG(4dfda0, fn4dfda0);

// 0x52b330, stdcall(a, b) ret 8: the logger [0x700390]->slot0x20(0x6a0f54, 0x26b2) q; q->slot0x2c(q, 0x6a137c) (cdecl, ecx = vtable); the assert hook [0x7003b0] (int3 when null); returns 0.0 in st0.
static float STDCALL fn52b330(u32 a, u32 b) {
  u8 *q = vcall<u8 *>(G(u8 *, 0x700390), 0x20, 0x6a0f54u, 0x26b2u);
  typedef void (*pf)(u8 *, u32);
  (*(pf *)(*(u8 **)q + 0x2c))(q, 0x6a137c);
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
  return 0.0f;
}
PCREG(52b330, fn52b330);

// 0x5efcc0, thiscall plain: when byte [this+0xa0] is set and n = [[0x70039c]+0x40] > cvtt([this+0x9c] * constant 0x678620), or else n > cvtt([this+0x98] * constant), tail-calls ext_5ef240(this).
static void THISCALL fn5efcc0(u8 *self) {
  if (!self[0xa0]) return;
  s32 n = *(s32 *)(G(u8 *, 0x70039c) + 0x40);
  __m128 k = _mm_set_ss(G(float, 0x678620));
  s32 t1 = _mm_cvttss_si32(_mm_mul_ss(_mm_set_ss(*(float *)(self + 0x9c)), k));
  if (n > t1) { ext_5ef240(self); return; }
  s32 t2 = _mm_cvttss_si32(_mm_mul_ss(_mm_set_ss(*(float *)(self + 0x98)), k));
  if (n <= t2) return;
  ext_5ef240(self);
}
PCREG(5efcc0, fn5efcc0);

// 0x4b89d0, thiscall plain: t = cvtt(([this+0x54] + [this+0x50]) * constant 0x678620); when [[0x70039c]+0x40] >= t (signed): ext_4b8ab0(this, 0); this->slot0x68(0x10, 0).
static void THISCALL fn4b89d0(u8 *self) {
  __m128 s = _mm_add_ss(_mm_set_ss(*(float *)(self + 0x54)), _mm_set_ss(*(float *)(self + 0x50)));
  s32 t = _mm_cvttss_si32(_mm_mul_ss(s, _mm_set_ss(G(float, 0x678620))));
  if (*(s32 *)(G(u8 *, 0x70039c) + 0x40) < t) return;
  ext_4b8ab0(self, 0);
  vcall<void>(self, 0x68, 0x10u, 0u);
}
PCREG(4b89d0, fn4b89d0);

// 0x535940, stdcall(f) ret 4: when f equals the constant at 0x6785d0 returns cvtt(float at 0x6a24f8); else cvtt((float)(log10((double)(f / constant 0x67cd40)) * double at 0x6a24e8)) with log10 from the CRT import [0x67632c].
static s32 STDCALL fn535940(u32 fb) {
  float f = bitsf(fb);
  if (f == G(float, 0x6785d0)) return _mm_cvttss_si32(_mm_set_ss(G(float, 0x6a24f8)));
  __m128 q = _mm_div_ss(_mm_set_ss(f), _mm_set_ss(G(float, 0x67cd40)));
  double d = _mm_cvtsd_f64(_mm_cvtps_pd(q));
  double r;
  asm volatile("movsd %[d], %%xmm0\n\tcall *0x67632c\n\tmovsd %%xmm0, %[r]" : [r] "=m"(r) : [d] "m"(d)
               : "eax", "ecx", "edx", "xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7", "memory", "cc");
  double m = _mm_cvtsd_f64(_mm_mul_sd(_mm_set_sd(r), _mm_set_sd(G(double, 0x6a24e8))));
  return _mm_cvttss_si32(_mm_cvtsd_ss(_mm_setzero_ps(), _mm_set_sd(m)));
}
PCREG(535940, fn535940);

// 0x46abb0, thiscall(a, f) ret 8: this->slot0x110(0x10, 0); returns [this+0x74]->slot0x98(a, f, 0).
static u32 THISCALL fn46abb0(u8 *self, u32 a, u32 f) {
  vcall<void>(self, 0x110, 0x10u, 0u);
  return vcall<u32>(*(u8 **)(self + 0x74), 0x98, a, f, 0u);
}
PCREG(46abb0, fn46abb0);
