// batch310.cpp - mounted gun tree, batch 310: vangpul, the angle-limited "turn vector a toward vector b" helper that
// ZCamHelper::RestrictPointerAngle uses to keep the camera inside a nest's arc (also used by aim, heli, IK code).
#include "ff.h"

extern "C" float FASTCALL ext_44e630(float *out, const float *v);                  // vnorm: out = v / |v|, returns |v|
extern "C" void FASTCALL ext_43e920(float *dst, const float *src, const float *a); // PSVECSubtract: dst = src - a
extern "C" void FASTCALL ext_441940(float *v, const float *a);                     // PSVECAdd: v += a

// 0x4e0130 vangpul(float *out, const float *from, const float *to, float maxAng), GC map [low]; fastcall (out ECX,
// from EDX), ret 8, al = 1 when `to` was reached. Angle between the unit directions: 0 above dot 1, pi below dot -1,
// else acos(dot). Within maxAng: out = to (raw copy), return 1. Otherwise out = cos(maxAng) * A - sin(maxAng) * C,
// where C = normalise(A * dot - B) (x87, skipped for a zero vector), i.e. A turned by maxAng toward B, and the length
// blends from |from| to |to| by maxAng / angle (0 when the angle is not above 2^-13); return 0.
static u8 FASTCALL vangpul(float *out, const float *from, const float *to, float maxAng) {
  float a[3], b[3], c[3];
  float lf = ext_44e630(a, from);
  float lt = ext_44e630(b, to);
  float t = 0.0f;
  float dot = (b[0] * a[0] + b[1] * a[1]) + b[2] * a[2];
  float ang;
  if (dot > 1.0f)
    ang = 0.0f;
  else if (-1.0f > dot)
    ang = 3.1415927410125732f;   // 0x67da18
  else
    ang = (float)crt::acos((double)dot);
  if (!(ang > maxAng)) {
    ((u32 *)out)[0] = ((const u32 *)to)[0];
    ((u32 *)out)[1] = ((const u32 *)to)[1];
    ((u32 *)out)[2] = ((const u32 *)to)[2];
    return 1;
  }
  c[0] = a[0] * dot;
  c[1] = a[1] * dot;
  c[2] = a[2] * dot;
  ext_43e920(c, c, b);
  if (!(c[0] == 0.0f && c[1] == 0.0f && c[2] == 0.0f)) {
    long double s = (long double)c[0] * c[0];
    s = s + (long double)c[1] * c[1];
    s = s + (long double)c[2] * c[2];
    long double inv = (long double)1.0f / fsqrt_x87(s);
    c[0] = (float)((long double)c[0] * inv);
    c[1] = (float)((long double)c[1] * inv);
    c[2] = (float)((long double)c[2] * inv);
  }
  float sn = (float)(-crt::sin((double)maxAng));
  c[0] = c[0] * sn;
  c[1] = c[1] * sn;
  c[2] = c[2] * sn;
  float cs = (float)crt::cos((double)maxAng);
  out[0] = a[0] * cs;
  out[1] = a[1] * cs;
  out[2] = a[2] * cs;
  ext_441940(out, c);
  if (ang > 0.0001220703125f)   // 0x679540
    t = maxAng / ang;
  float k = (lt - lf) * t + lf;
  out[0] = out[0] * k;
  out[1] = out[1] * k;
  out[2] = out[2] * k;
  return 0;
}
PCREG(4e0130, vangpul);
