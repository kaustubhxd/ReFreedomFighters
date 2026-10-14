// batch34150.cpp - cascade tier H, batch 34150: 0x4c61a0 and 0x5ddad0 (use x87-returning getters), 0x59a5b0 (forward a float), 0x4dfde0 (2x2 transform with register arguments), 0x537f80 (store floats and an int scaled).
#include "ff.h"

extern "C" float THISCALL ext_4e5e80(void *self);              // plain ret, float in st0
extern "C" u32 THISCALL ext_4e5e60(void *self);                // plain ret
extern "C" u32 THISCALL ext_5aaa50(void *self, u32 a, u32 b, u32 f);   // ret 0xc

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x4c61a0, thiscall(a) ret 4: ext_4e5e80(a) (the float result is dropped); [this+0x4a] (unaligned) = ext_4e5e60(a).
static void THISCALL fn4c61a0(u8 *self, u8 *a) {
  volatile float dropped = ext_4e5e80(a);
  (void)dropped;
  wr32(self + 0x4a, ext_4e5e60(a));
}
PCREG(4c61a0, fn4c61a0);

// 0x5ddad0, thiscall(a) ret 4: [this+0x54] = ext_4e5e80(a); [this+0x58] = ext_4e5e80(a) (two successive reads).
static void THISCALL fn5ddad0(u8 *self, u8 *a) {
  float x = ext_4e5e80(a);
  *(float *)(self + 0x54) = x;
  float y = ext_4e5e80(a);
  *(float *)(self + 0x58) = y;
}
PCREG(5ddad0, fn5ddad0);

// 0x59a5b0, thiscall(a, b, f) ret 0xc: t = unaligned [this+0x1d0f]; when non-zero ext_5aaa50(t, a, b, f) (float as bits).
static void THISCALL fn59a5b0(u8 *self, u32 a, u32 b, u32 f) {
  u8 *t = (u8 *)rd32(self + 0x1d0f);
  if (t) ext_5aaa50(t, a, b, f);
}
PCREG(59a5b0, fn59a5b0);

// 0x4dfde0, ecx = A (floats a0, a1), edx = B (floats b0..b3), plain ret: A0' = b2*a1 + b0*a0; A1' = b3*a1 + b1*a0 (the original a0 and a1 are used for both).
static void FASTCALL fn4dfde0(float *A, float *B) {
  __m128 a0 = _mm_set_ss(A[0]);
  __m128 x1 = _mm_mul_ss(_mm_set_ss(B[2]), _mm_set_ss(A[1]));
  __m128 x0 = _mm_mul_ss(_mm_set_ss(B[0]), a0);
  x1 = _mm_add_ss(x1, x0);
  __m128 y1 = _mm_mul_ss(_mm_set_ss(B[3]), _mm_set_ss(A[1]));
  __m128 y0 = _mm_mul_ss(_mm_set_ss(B[1]), a0);
  y1 = _mm_add_ss(y1, y0);
  A[0] = _mm_cvtss_f32(x1);
  A[1] = _mm_cvtss_f32(y1);
}
PCREG(4dfde0, fn4dfde0);

// 0x537f80, thiscall(a, f) ret 8: unaligned [this+0x514d] = f (bits); byte [this+0x5148] = 1; unaligned [this+0x5149] = a; unaligned float [this+0x5151] = (float)(int)[[0x70039c]+0x1c] * constant at 0x6785e4.
static void THISCALL fn537f80(u8 *self, u32 a, u32 f) {
  wr32(self + 0x514d, f);
  self[0x5148] = 1;
  wr32(self + 0x5149, a);
  s32 n = *(s32 *)(G(u8 *, 0x70039c) + 0x1c);
  __m128 v = _mm_mul_ss(_mm_cvtepi32_ps(_mm_cvtsi32_si128(n)), _mm_set_ss(G(float, 0x6785e4)));
  wr32(self + 0x5151, __builtin_bit_cast(u32, _mm_cvtss_f32(v)));
}
PCREG(537f80, fn537f80);
