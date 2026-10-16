#include "ff.h"

static inline __m128 i32_ss_662b70(s32 value) {
  return _mm_cvtsi32_ss(_mm_setzero_ps(), value);
}

// 0x662b70: thiscall(easing, milliseconds), ret 4.  The duration is an
// unaligned signed tick count.  The original compares its scaled absolute
// delta in double precision before restarting the ease.
void THISCALL fn_662b70(u8 *easing, s32 milliseconds) {
  __m128 scale = _mm_set_ss(G(float, 0x6785e4));
  __m128 old_time = _mm_mul_ss(i32_ss_662b70(*(s32 *)(easing + 0x11)), scale);
  __m128 new_time = _mm_mul_ss(i32_ss_662b70(milliseconds), scale);
  __m128 delta = _mm_sub_ss(old_time, new_time);
  __m128d magnitude = _mm_and_pd(_mm_cvtps_pd(delta),
                                  _mm_loadu_pd((const double *)0x67cd50));
  if (!(_mm_cvtsd_f64(magnitude) > G(double, 0x685278))) return; // m0

  *(u32 *)(easing + 0x11) = (u32)milliseconds; // m1
  u8 *now = G(u8 *, 0x70039c) + 0x40;
  if (easing + 0xd != now)
    *(u32 *)(easing + 0xd) = *(u32 *)now; // m2
  *(u32 *)(easing + 8) = *(u32 *)easing; // m3
}
PCREG(662b70, fn_662b70);
