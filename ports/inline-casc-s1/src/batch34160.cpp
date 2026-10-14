// batch34160.cpp - cascade tier H, batch 34160: 0x5f4e60 (scale a float or report), 0x4d6150 (queue a record), 0x5272e0 (integrate and snap to a limit), 0x45aff0 (derive a radius from a vector).
#include "ff.h"

extern "C" u32 ext_41e290(u32 size);                              // cdecl alloc
extern "C" void THISCALL ext_4d9350(void *self, u32 a, u32 b);   // ret 8
extern "C" void THISCALL ext_4dd060(void *self, void *v);        // ret 4
extern "C" void THISCALL ext_4dce50(void *self, u32 f);          // ret 4
typedef void (*hook_t)();

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x5f4e60, thiscall(p) ret 4: when byte [this+4] == 2: [this] = *p * [this] (floats). Otherwise the logger [0x700390]->slot0x20(0x69c8e0, 0xa6) q, q->slot0x2c(q, 0x69c6b0, 0x69c938) (cdecl, ecx = vtable) and the assert hook [0x7003b0] (int3 when null).
static void THISCALL fn5f4e60(u8 *self, float *p) {
  if (self[4] == 2) {
    *(float *)self = _mm_cvtss_f32(_mm_mul_ss(_mm_set_ss(*p), _mm_set_ss(*(float *)self)));
    return;
  }
  u8 *q = vcall<u8 *>(G(u8 *, 0x700390), 0x20, 0x69c8e0u, 0xa6u);
  typedef void (*pf)(u8 *, u32, u32);
  (*(pf *)(*(u8 **)q + 0x2c))(q, 0x69c6b0, 0x69c938);
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
}
PCREG(5f4e60, fn5f4e60);

// 0x4d6150, thiscall(a, b, c) ret 0xc: n = ext_41e290(0x1e); copies 0x1a bytes of b into n (16 + 8 + 2), unaligned [n+0x1a] = c; ext_4d9350(this + 4, a, n); then the embedded object at this + 0xa: its slot 1 (n).
static void THISCALL fn4d6150(u8 *self, u32 a, u8 *b, u32 c) {
  u8 *n = (u8 *)ext_41e290(0x1e);
  for (int i = 0; i < 0x1a; i++) n[i] = b[i];
  wr32(n + 0x1a, c);
  ext_4d9350(self + 4, a, (u32)n);
  vcall<void>(self + 0xa, 4, (u32)n);
}
PCREG(4d6150, fn4d6150);

// 0x5272e0, thiscall plain: x = [[0x70039c]+0x48] * [this+0x10] * f + [this+4], f = [this+0x14]; [this+4] = x. When f < 0: lim = [this+8]; when lim + constant 0x679540 >= x: unaligned dword [this+0x19] = 2, byte [this+0x18] = 1, [this+4] = lim.
// When f > 0: lim = [this+8]; when x > lim - constant: the same three stores.
static void THISCALL fn5272e0(u8 *self) {
  u8 *eng = G(u8 *, 0x70039c);
  __m128 zero = _mm_setzero_ps();
  __m128 f = _mm_set_ss(*(float *)(self + 0x14));
  __m128 x = _mm_mul_ss(_mm_set_ss(*(float *)(eng + 0x48)), _mm_set_ss(*(float *)(self + 0x10)));
  x = _mm_mul_ss(x, f);
  x = _mm_add_ss(x, _mm_set_ss(*(float *)(self + 4)));
  *(float *)(self + 4) = _mm_cvtss_f32(x);
  __m128 lim = _mm_set_ss(*(float *)(self + 8));
  __m128 k = _mm_set_ss(G(float, 0x679540));
  if (_mm_comigt_ss(zero, f)) {
    if (!_mm_comige_ss(_mm_add_ss(lim, k), x)) return;
  } else if (_mm_comigt_ss(f, zero)) {
    if (!_mm_comigt_ss(x, _mm_sub_ss(lim, k))) return;
  } else {
    return;
  }
  wr32(self + 0x19, 2);
  self[0x18] = 1;
  *(float *)(self + 4) = _mm_cvtss_f32(lim);
}
PCREG(5272e0, fn5272e0);

// 0x45aff0, thiscall plain: o = [this+8]; ext_4dd060(o, this + 0x18); r = (float)sqrt((double)(x*x + y*y + z*z)) + constant 0x678858 for the floats at o+0x40/0x44/0x48 (CRT sqrt import [0x676330]); ext_4dce50(o, r).
static void THISCALL fn45aff0(u8 *self) {
  ext_4dd060(*(u8 **)(self + 8), self + 0x18);
  u8 *o = *(u8 **)(self + 8);
  __m128 x = _mm_set_ss(*(float *)(o + 0x40)), y = _mm_set_ss(*(float *)(o + 0x44)), z = _mm_set_ss(*(float *)(o + 0x48));
  x = _mm_mul_ss(x, x);
  y = _mm_mul_ss(y, y);
  z = _mm_mul_ss(z, z);
  x = _mm_add_ss(x, y);
  x = _mm_add_ss(x, z);
  double d = _mm_cvtsd_f64(_mm_cvtps_pd(x));
  double r;
  asm volatile("movsd %[d], %%xmm0\n\tcall *0x676330\n\tmovsd %%xmm0, %[r]" : [r] "=m"(r) : [d] "m"(d)
               : "eax", "ecx", "edx", "xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7", "memory", "cc");
  float rf = (float)r;
  float out = _mm_cvtss_f32(_mm_add_ss(_mm_set_ss(rf), _mm_set_ss(G(float, 0x678858))));
  ext_4dce50(o, __builtin_bit_cast(u32, out));
}
PCREG(45aff0, fn45aff0);
