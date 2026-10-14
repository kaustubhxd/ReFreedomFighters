// batch34157.cpp - cascade tier H, batch 34157: 0x4ddfa0 (project a vector), 0x54f150 (move toward with a tolerance), 0x5a5ca0 (set a max-derived vector).
#include "ff.h"

extern "C" void FASTCALL ext_43e920(void *ecx, void *edx, void *out);     // ret 4
extern "C" void THISCALL ext_43df70(void *self);                          // plain ret
extern "C" void THISCALL ext_4dd060(void *self, void *v);                 // ret 4
extern "C" void FASTCALL ext_633654(u32 cookie);                           // /GS check

// 0x4ddfa0, ecx = A (3 floats), edx = B (3 floats), plain ret: d = A.x*B.x + A.y*B.y + A.z*B.z (summed in that order); out = B * d; then ext_43e920(A, A, &out).
static void FASTCALL fn4ddfa0(float *A, float *B) {
  float out[3];
  __m128 b0 = _mm_set_ss(B[0]), b1 = _mm_set_ss(B[1]), b2 = _mm_set_ss(B[2]);
  __m128 x0 = _mm_mul_ss(_mm_set_ss(A[0]), b0);
  __m128 x2 = _mm_mul_ss(_mm_set_ss(A[1]), b1);
  x2 = _mm_add_ss(x2, x0);
  x0 = _mm_mul_ss(_mm_set_ss(A[2]), b2);
  x2 = _mm_add_ss(x2, x0);
  b0 = _mm_mul_ss(b0, x2);
  b1 = _mm_mul_ss(b1, x2);
  b2 = _mm_mul_ss(b2, x2);
  out[0] = _mm_cvtss_f32(b0);
  out[1] = _mm_cvtss_f32(b1);
  out[2] = _mm_cvtss_f32(b2);
  ext_43e920(A, A, out);
}
PCREG(4ddfa0, fn4ddfa0);

// 0x54f150, stdcall(a, b, c) ret 0xc, returns a double in st0 (x87 precision control: 53 bits): a when a == b; a > b with a - b > c gives b + c; a < b with b - a > c gives b - c; otherwise a.
static double STDCALL fn54f150(u32 ab, u32 bb, u32 cb) {
  float a = bitsf(ab), b = bitsf(bb), c = bitsf(cb);
  if (a == b) return (double)a;
  if (_mm_comigt_ss(_mm_set_ss(a), _mm_set_ss(b))) {
    if (_mm_comigt_ss(_mm_sub_ss(_mm_set_ss(a), _mm_set_ss(b)), _mm_set_ss(c))) return (double)b + (double)c;
  } else {
    if (_mm_comigt_ss(_mm_sub_ss(_mm_set_ss(b), _mm_set_ss(a)), _mm_set_ss(c))) return (double)b - (double)c;
  }
  return (double)a;
}
PCREG(54f150, fn54f150);

// 0x5a5ca0, thiscall plain: ext_43df70(this); o = [this+8]; m = max([o+0x48], max([o+0x44], [o+0x40])) (maxss operand order); v = {m, m, m}; ext_4dd060(o, &v); /GS check.
static void THISCALL fn5a5ca0(u8 *self) {
  float v[3];
  ext_43df70(self);
  u8 *o = *(u8 **)(self + 8);
  __m128 x0 = _mm_max_ss(_mm_set_ss(*(float *)(o + 0x44)), _mm_set_ss(*(float *)(o + 0x40)));
  __m128 x1 = _mm_max_ss(_mm_set_ss(*(float *)(o + 0x48)), x0);
  float m = _mm_cvtss_f32(x1);
  v[0] = m;
  v[1] = m;
  v[2] = m;
  ext_4dd060(o, v);
  ext_633654(0);
}
PCREG(5a5ca0, fn5a5ca0);
