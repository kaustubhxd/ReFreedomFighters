#include "ff.h"

static inline __m128d abs_ss_as_pd_662ab0(__m128 value) {
  return _mm_and_pd(_mm_cvtps_pd(value), _mm_load_sd((const double *)0x67cd50));
}

// 0x662ab0: thiscall(easing, value), ret 4 in AL.  Snap both current and
// source to a value outside the tolerance, then stamp the new easing start.
u8 THISCALL fn_662ab0(u8 *easing, float value) {
  __m128d magnitude = abs_ss_as_pd_662ab0(
      _mm_sub_ss(_mm_set_ss(*(float *)easing), _mm_set_ss(value)));
  __m128d threshold = _mm_cvtps_pd(_mm_set_ss(*(float *)(easing + 0x19)));
  if (!(_mm_cvtsd_f64(magnitude) > _mm_cvtsd_f64(threshold))) return 0; // m0
  *(float *)easing = value; // m1
  *(float *)(easing + 8) = value; // m2
  u8 *now = G(u8 *, 0x70039c) + 0x40;
  if (easing + 0xd != now)
    *(u32 *)(easing + 0xd) = *(u32 *)now; // m3
  return 1;
}
PCREG(662ab0, fn_662ab0);
