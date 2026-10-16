#include "ff.h"

static inline __m128d abs_ss_as_pd_662b00(__m128 value) {
  return _mm_and_pd(_mm_cvtps_pd(value), _mm_load_sd((const double *)0x67cd50));
}

// 0x662b00: thiscall(easing, destination), ret 4.  A meaningful destination
// change restarts the scalar ease and sets its next snap threshold to one
// percent of the absolute current-to-destination distance.
void THISCALL fn_662b00(u8 *easing, float destination) {
  __m128 previous = _mm_set_ss(*(float *)(easing + 4));
  __m128 requested = _mm_set_ss(destination);
  __m128d delta = abs_ss_as_pd_662b00(_mm_sub_ss(previous, requested));
  __m128d threshold = _mm_cvtps_pd(_mm_set_ss(*(float *)(easing + 0x19)));
  if (!(_mm_cvtsd_f64(delta) > _mm_cvtsd_f64(threshold))) return; // m0

  u8 *now = G(u8 *, 0x70039c) + 0x40;
  if (easing + 0xd != now)
    *(u32 *)(easing + 0xd) = *(u32 *)now; // m1
  float current = *(float *)easing;
  *(float *)(easing + 8) = current; // m2
  __m128d new_delta = abs_ss_as_pd_662b00(
      _mm_sub_ss(_mm_set_ss(current), requested));
  *(float *)(easing + 4) = destination; // m3
  __m128 next_threshold = _mm_cvtpd_ps(
      _mm_mul_sd(new_delta, _mm_load_sd((const double *)0x6c4a90)));
  *(float *)(easing + 0x19) = _mm_cvtss_f32(next_threshold); // m4
}
PCREG(662b00, fn_662b00);
