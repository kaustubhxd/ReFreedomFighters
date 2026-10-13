// batch36.cpp - walk-tree lift, inline session batch 36 (Haiku, night): createmat.
#include "ff.h"

extern "C" float THISCALL ext_44c840(float *v);                           // vnorm, original code (lifted in batch 35)
extern "C" void FASTCALL ext_446ee0(float *dst, const float *a, const float *b);  // vcross, original code (batch 35)

// The x87 normalise path of createmat: scale v by 1/|v|, computed in double (exact x87 behaviour under 53-bit control).
static void normalizeVec(float *v) {
  double x = v[0], y = v[1], z = v[2];
  double sum = ((x * x) + (y * y)) + (z * z);
  double len = crt::sqrt(sum);
  double inv = 1.0 / len;
  v[0] = (float)(x * inv);
  v[1] = (float)(y * inv);
  v[2] = (float)(z * inv);
}

// 0x4de040, fastcall (out in ECX, p in EDX, q on the stack), ret 4. Builds a 3x3 frame: out[0..2] is p normalised (or (0,0,1)
// when p is null or its length is below 2^-13), out[6..8] is the cross of a and out, normalised unless it is zero. a is q when q is
// not null, after out is set to (0,1,0) when |dot(q, out)| > 0.999878; otherwise a is (0,1,0) or (1,0,0) chosen from |out[1]|, or
// tmp for the null-q case as the original. The lengths and dot use float ops (SSE), the normalise uses double. Name createmat.
static void FASTCALL createmat(float *out, const float *p, const float *q) {
  const float eps = bitsf(0x39000000u);   // 2^-13, the constant at 0x679540
  const float one = bitsf(0x3f800000u);   // 1.0f
  const double C = G(double, 0x6970d0);   // 0.999878, compared after fabs
  if (p != 0) {
    out[0] = p[0];
    out[1] = p[1];
    out[2] = p[2];
    float len = ext_44c840(out);
    if (eps > len) {
      out[0] = 0.0f;
      out[1] = 0.0f;
      out[2] = one;
    }
  } else {
    out[0] = 0.0f;
    out[1] = 0.0f;
    out[2] = one;
  }
  const float *a;
  float tmp[3];
  if (q != 0) {
    float t = (q[1] * out[1]) + (out[0] * q[0]);
    float dot = t + (q[2] * out[2]);
    double ad = (double)dot;
    if (ad < 0.0)
      ad = -ad;
    if (ad > C) {
      out[0] = 0.0f;
      out[1] = one;
      out[2] = 0.0f;
    }
    a = q;
  } else {
    float t = ((out[0] * 0.0f) + out[1]) + (out[2] * 0.0f);
    double ad = (double)t;
    if (ad < 0.0)
      ad = -ad;
    tmp[0] = 0.0f;
    tmp[1] = one;
    tmp[2] = 0.0f;
    if (ad > C) {
      tmp[0] = one;
      tmp[1] = 0.0f;
    }
    a = tmp;
  }
  float *d = out + 6;
  ext_446ee0(d, a, out);
  if (!(d[0] == 0.0f && d[1] == 0.0f && d[2] == 0.0f))
    normalizeVec(d);
  ext_446ee0(out + 3, out, d);
}
PCREG(4de040, createmat);
