// batch1040.cpp - ZCAMERA::SetCamTaget. Camera thread, 2026-10-11.
#include "cam.h"

extern "C" THISCALL void ext_4db2a0(void *obj, float *out);                       // copies the 3x3 matrix at obj (36 bytes) to out
extern "C" FASTCALL void ext_43e920(float *d, const float *a, const float *b);      // d = a - b
extern "C" FASTCALL void ext_446ee0(float *out, const float *a, const float *b);    // out = a x b

// True when some component is nonzero or NaN (the original's "jp" tests): then the vector is normalized.
static inline bool needs_norm(const float *v) {
  return !(v[0] == 0.0f && v[1] == 0.0f && v[2] == 0.0f);
}

// Scale v to unit length: the length is computed in x87 extended precision (fsqrt_x87), as the original does.
static void normalize3(float *v) {
  long double s = (long double)v[0] * v[0];
  s = s + (long double)v[1] * v[1];
  s = s + (long double)v[2] * v[2];
  long double inv = 1.0L / fsqrt_x87(s);
  v[0] = (float)(v[0] * inv);
  v[1] = (float)(v[1] * inv);
  v[2] = (float)(v[2] * inv);
}

// 0x446b50 ZCAMERA::SetCamTaget(float *p, u32 unused): the view direction v = p - sub+0x24 (normalized), then the
// frame (v, b, c): b = the matrix's second row, fixed when parallel to v; c = b x v; b = v x c. The frame goes to
// virtual slot 0x6c with v. The matrix copy also fills m[0..2] (overwritten by v) and m[6..8] (overwritten by c).
static THISCALL void ZCAMERA_SetCamTaget(u8 *self, float *p, u32) {
  u8 *sub = at<u8 *>(self, 8);
  float m[9];
  ext_4db2a0(at<void *>(sub, 0x50), m);
  float *v = m;
  float *b = m + 3;
  float *c = m + 6;
  ext_43e920(v, p, (float *)(sub + 0x24));
  if (needs_norm(v)) normalize3(v);
  float dot = b[1] * v[1];
  dot = dot + b[0] * v[0];
  dot = dot + b[2] * v[2];
  double ad = (double)dot;
  if (ad < 0) ad = -ad;
  if (ad == 1.0) b[0] = b[0] + 1.0f;   // b is parallel to v: nudge it so the cross product is not zero
  ext_446ee0(c, b, v);
  if (needs_norm(c)) normalize3(c);
  ext_446ee0(b, v, c);
  vcall<void>(self, 0x6c, v);
}
PCREG(446b50, ZCAMERA_SetCamTaget);
