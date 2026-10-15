// Polar-angle port derived from inline-camera batch1015; strict verification added by codex-u1.
#include "ff.h"
static inline float wrap_pi(float y) {
  if (y > G(float, 0x67da18))
    y = y - G(float, 0x68aef8);
  else if (G(float, 0x6ad238) > y)
    y = y + G(float, 0x68aef8);
  return y;
}

static THISCALL void ZCamHelper_GetPolarAngles(void *self, float *yaw, float *pitch, const float *dir) {
  float v[3] = {dir[0], dir[1], dir[2]};
  if (!(v[0] == 0.0f && v[1] == 0.0f && v[2] == 0.0f)) {
    long double s = (long double)v[0] * v[0];
    s = s + (long double)v[1] * v[1];
    s = s + (long double)v[2] * v[2];
    long double inv = 1.0L / fsqrt_x87(s);
    v[0] = (float)(v[0] * inv);
    v[1] = (float)(v[1] * inv);
    v[2] = (float)(v[2] * inv);
  }
  float x = v[0], y = v[1], z = v[2];
  __m128d ax = _mm_and_pd(_mm_cvtps_pd(_mm_set_ss(x)), *(const __m128d *)0x67cd50);
  if (G(double, 0x685278) >= _mm_cvtsd_f64(ax)) {
    *(u32 *)yaw = 0.0f > z ? 0xbfc90fdb : 0x3fc90fdb;  // -+pi/2
  } else {
    float a = (float)crt::atan((double)(z / x));
    const float pi = G(float, 0x67da18);
    if (a > G(float, 0x6ad1fc) || G(float, 0x6ad234) > a) a = pi;
    *yaw = a;
    if (0.0f > x) *yaw = wrap_pi(a - pi);
  }
  float h = (float)crt::sqrt((double)(z * z + x * x));
  if (G(float, 0x679540) >= h)
    *(u32 *)pitch = 0;
  else
    *pitch = (float)crt::atan((double)(y / h));
}
PCREG(5cf820, ZCamHelper_GetPolarAngles);
