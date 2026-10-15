// batch34165.cpp - cascade tier H, batch 34165: 0x4616c0 (set a radius from a max), 0x5157d0 (compute a position from three float getters), 0x561f70 (finish a state), 0x478f90 (move an index in a sorted array).
#include "ff.h"

extern "C" void THISCALL ext_43df70(void *self);                        // plain ret
extern "C" void THISCALL ext_4db7c0(void *self, void *v);               // ret 4
extern "C" void THISCALL ext_4dce50(void *self, u32 f);                 // ret 4
extern "C" void THISCALL ext_4dd060(void *self, void *v);               // ret 4
extern "C" void FASTCALL ext_633654(u32 cookie);                         // /GS check
extern "C" void THISCALL ext_523470(void *self, u32 a, void *loc, u32 r);   // ret 0xc
extern "C" void FASTCALL ext_4de040(void *ecx, void *edx, u32 z);       // ret 4
extern "C" void THISCALL ext_4f9680(void *self, u32 a);                 // ret 4
extern "C" void THISCALL ext_563750(void *self, u32 a, u32 b);          // ret 8

// 0x4616c0, thiscall plain, /GS: ext_43df70(this); ext_4db7c0([this+8], v); m = max(v[2], max(v[1], v[0])) (maxss operand order); v = {m, m, m}; r = (float)sqrt((double)(m*m + m*m + m*m)) + constant 0x678858 (CRT sqrt import [0x676330]); ext_4dce50([this+8], r); ext_4dd060([this+8], v).
static void THISCALL fn4616c0(u8 *self) {
  float v[3];
  ext_43df70(self);
  ext_4db7c0(*(u8 **)(self + 8), v);
  __m128 x0 = _mm_max_ss(_mm_set_ss(v[1]), _mm_set_ss(v[0]));
  __m128 x1 = _mm_max_ss(_mm_set_ss(v[2]), x0);
  float m = _mm_cvtss_f32(x1);
  v[0] = m;
  v[1] = m;
  v[2] = m;
  __m128 s = _mm_mul_ss(x1, x1);
  __m128 t = _mm_add_ss(s, s);
  t = _mm_add_ss(t, s);
  double d = _mm_cvtsd_f64(_mm_cvtps_pd(t));
  double r;
  asm volatile("movsd %[d], %%xmm0\n\tcall *0x676330\n\tmovsd %%xmm0, %[r]" : [r] "=m"(r) : [d] "m"(d)
               : "eax", "ecx", "edx", "xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7", "memory", "cc");
  float rf = _mm_cvtss_f32(_mm_add_ss(_mm_set_ss((float)r), _mm_set_ss(G(float, 0x678858))));
  ext_4dce50(*(u8 **)(self + 8), __builtin_bit_cast(u32, rf));
  ext_4dd060(*(u8 **)(self + 8), v);
  ext_633654(0);
}
PCREG(4616c0, fn4616c0);

// 0x5157d0, thiscall plain, /GS: o = [this+0x5c]; q = (float)(200.0 (constant 0x67da2c) / o->slot0x10()); m = (float)(o->slot0x14() * q); r = (float)(o->slot0xc() + m) (x87 double precision, narrowed to float at each store);
// ext_523470(o, this + 0x28f, &loc, r); ext_4de040(this + 0x26b, &loc, 0).
static void THISCALL fn5157d0(u8 *self) {
  u32 loc[3];
  u8 *o = *(u8 **)(self + 0x5c);
  float t0 = vcall<float>(o, 0x10);
  float q = (float)((double)G(float, 0x67da2c) / (double)t0);
  o = *(u8 **)(self + 0x5c);
  float t1 = vcall<float>(o, 0x14);
  float m = (float)((double)t1 * (double)q);
  o = *(u8 **)(self + 0x5c);
  float t2 = vcall<float>(o, 0xc);
  float r = (float)((double)t2 + (double)m);
  ext_523470(*(u8 **)(self + 0x5c), (u32)(self + 0x28f), loc, __builtin_bit_cast(u32, r));
  ext_4de040(self + 0x26b, loc, 0);
  ext_633654(0);
}
PCREG(5157d0, fn5157d0);

// 0x561f70, thiscall plain: ext_4f9680(0x700e24, 2); k = [this+0xdc]; for k == 3 or 5: [this+0x64] = (float)[[0x70039c]+0x30] * constant 0x6785e4; ext_563750(this, k, 0); byte [this+0x85] = 1; [this+0x4c]->slot0xbc(0) and [this+0x50]->slot0xbc(0) when set;
// this->slot0xd4(0); [this+0xdc] = ([this+0xdc] == 5) ? 6 : 0.
static void THISCALL fn561f70(u8 *self) {
  ext_4f9680((void *)0x700e24, 2);
  u32 k = *(u32 *)(self + 0xdc);
  if (k != 3 && k != 5) return;
  s32 n = *(s32 *)(G(u8 *, 0x70039c) + 0x30);
  *(float *)(self + 0x64) = _mm_cvtss_f32(_mm_mul_ss(_mm_cvtepi32_ps(_mm_cvtsi32_si128(n)), _mm_set_ss(G(float, 0x6785e4))));
  ext_563750(self, k, 0);
  self[0x85] = 1;
  u8 *c = *(u8 **)(self + 0x4c);
  if (c) vcall<void>(c, 0xbc, 0u);
  u8 *d = *(u8 **)(self + 0x50);
  if (d) vcall<void>(d, 0xbc, 0u);
  vcall<void>(self, 0xd4, 0u);
  *(u32 *)(self + 0xdc) = (*(u32 *)(self + 0xdc) == 5) ? 6 : 0;
}
PCREG(561f70, fn561f70);

// 0x478f90, thiscall(f) ret 4, returns the index: arr = [this+0xc] of 16-byte entries (float first), idx = [this] (signed), size = [this+8]. While idx > 0 and arr[idx] > f (ordered): idx--; then while idx < size - 1: stop (return idx) when !(f >= arr[idx]), else idx++. Index kept in [this].
static s32 THISCALL fn478f90(u8 *self, u32 fb) {
  __m128 f = _mm_set_ss(bitsf(fb));
  s32 *pidx = (s32 *)self;
  u8 *arr = *(u8 **)(self + 0xc);
  if (*pidx > 0) {
    for (;;) {
      s32 idx = *pidx;
      __m128 e = _mm_set_ss(*(float *)(arr + idx * 16));
      if (!_mm_comigt_ss(e, f)) break;
      *pidx = idx - 1;
      if (*pidx <= 0) break;
    }
  }
  s32 n = *(s32 *)(self + 8) - 1;
  if (*pidx >= n) return *pidx;
  for (;;) {
    s32 idx = *pidx;
    __m128 e = _mm_set_ss(*(float *)(arr + idx * 16));
    if (!_mm_comige_ss(f, e)) return idx;
    *pidx = idx + 1;
    if (*pidx >= n) return *pidx;
  }
}
PCREG(478f90, fn478f90);
