#include "ff.h"

extern "C" float FASTCALL ext_4e0030(u8 *a, u8 *b);
extern "C" void THISCALL ext_662ab0(u8 *self, float value);
extern "C" void THISCALL ext_662b00(u8 *self, float value);
extern "C" void THISCALL ext_662b70(u8 *self, s32 milliseconds);

// Keep the integer-to-single conversions and scalar operations in SSE, as in
// the original.  In particular, the subtraction rounds to a single before it
// is widened for the absolute-value comparison.
static inline __m128 i32_ss(s32 value) {
  return _mm_cvtsi32_ss(_mm_setzero_ps(), value);
}

static inline bool changed_enough(u8 *self, s32 milliseconds) {
  __m128 scale = _mm_set_ss(G(float, 0x6785e4));
  __m128 old_time = _mm_mul_ss(i32_ss(*(s32 *)(self + 0x45)), scale);
  __m128 new_time = _mm_mul_ss(i32_ss(milliseconds), scale);
  __m128 delta = _mm_sub_ss(old_time, new_time);
  __m128d magnitude = _mm_and_pd(_mm_cvtps_pd(delta),
                                  _mm_loadu_pd((const double *)0x67cd50));
  // `comisd; jbe` proceeds only for an ordered magnitude strictly above the
  // threshold.  A C++ greater-than expression has the same NaN behaviour.
  return _mm_cvtsd_f64(magnitude) > G(double, 0x685278);
}

// 0x6630f0: thiscall(this, milliseconds), ret 4.  Refresh the matrix/easing
// transition only when its signed tick time differs by more than the engine's
// tiny double threshold.
void THISCALL fn_6630f0(u8 *self, s32 milliseconds) {
  if (!changed_enough(self, milliseconds)) return;

  *(u32 *)(self + 0x1c) = *(u32 *)(self + 4); // m1
  *(u32 *)(self + 0x20) = *(u32 *)(self + 8);
  *(u32 *)(self + 0x24) = *(u32 *)(self + 0xc);
  float blend = ext_4e0030(self + 4, self + 0x10);
  *(u32 *)(self + 0x3c) = 0; // m0
  ext_662ab0(self + 0x34, 0.0f); // m2
  ext_662b00(self + 0x34, blend); // m3
  ext_662b70(self + 0x34, milliseconds); // m4
}
PCREG(6630f0, fn_6630f0);
