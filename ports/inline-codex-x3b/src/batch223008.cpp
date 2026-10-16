#include "ff.h"

extern "C" void THISCALL ext_662cf0(u8 *self);
extern "C" void THISCALL ext_662b70(u8 *self, s32 milliseconds);

static inline __m128 i32_ss_662e70(s32 value) {
  return _mm_cvtsi32_ss(_mm_setzero_ps(), value);
}

// 0x662e70: thiscall(vector_easing, milliseconds), ret 4.  A significant
// elapsed-time change rebuilds the vector pull and resets its scalar easer.
void THISCALL fn_662e70(u8 *self, s32 milliseconds) {
  __m128 scale = _mm_set_ss(G(float, 0x6785e4));
  __m128 old_time = _mm_mul_ss(i32_ss_662e70(*(s32 *)(self + 0x45)), scale);
  __m128 new_time = _mm_mul_ss(i32_ss_662e70(milliseconds), scale);
  __m128 delta = _mm_sub_ss(old_time, new_time);
  __m128d magnitude = _mm_and_pd(_mm_cvtps_pd(delta),
                                  _mm_loadu_pd((const double *)0x67cd50));
  if (!(_mm_cvtsd_f64(magnitude) > G(double, 0x685278))) return; // m0
  ext_662cf0(self); // m1
  ext_662b70(self + 0x34, milliseconds); // m2
}
PCREG(662e70, fn_662e70);
