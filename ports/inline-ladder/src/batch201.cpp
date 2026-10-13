// batch201.cpp - ladder tree (inline-ladder thread, 2026-10-11): closest point on one cubic by bisection.
#include "ff.h"

extern "C" float FASTCALL ext_4e0830(const float *a, const float *b);   // vdist2 (x87, ST0), runs as original code
extern "C" float FASTCALL ext_4e0870(const float *a, const float *b);   // vdist (batch 48), ST0

static inline float horner(const float *c, float t) {   // ((c0*t + c1)*t + c2)*t + c3
  float v = c[0] * t + c[1];
  v = v * t + c[2];
  return v * t + c[3];
}

// 0x4602b0, thiscall, four stack args (P, unused, out, steps), ret 0x10, float return in ST0. Name used here:
// ParametricCurve::ClosestPoint (inferred; no GC match, called by ZSHAPE::GetDistToSegment 0x44ace0).
// this is the cubic record: per axis four coefficients c0..c3 at +4, +0x14, +0x24 (Horner, as GetSplinePos 0x4604f0).
// Bisection on t in [lo, hi] = [0, 1], `steps` times (signed, none when <= 0): A = P(lo), B = P(hi); if
// vdist2(B, P) > vdist2(A, P) (ordered; equal or NaN moves lo) then hi = mid else lo = mid, mid = (hi + lo) * 0.5.
// Then out = P((hi + lo) * 0.5) and the result is vdist(out, P). The second stack argument is never read.
static float THISCALL closestPoint(u8 *self, const float *p, u32 unused, float *out, int steps) {
  (void)unused;
  const float *f = (const float *)(self + 4);
  float lo = 0.0f, hi = 1.0f;
  for (int i = steps; i > 0; i--) {
    float mid = (hi + lo) * 0.5f;
    float a[3], b[3];
    a[0] = horner(f, lo);
    a[1] = horner(f + 4, lo);
    a[2] = horner(f + 8, lo);
    b[2] = horner(f + 8, hi);
    b[0] = horner(f, hi);
    b[1] = horner(f + 4, hi);
    float da = ext_4e0830(a, p);
    float db = ext_4e0830(b, p);
    if (db > da)
      hi = mid;
    else
      lo = mid;
  }
  float t = (hi + lo) * 0.5f;
  out[0] = horner(f, t);
  out[1] = horner(f + 4, t);
  out[2] = horner(f + 8, t);
  return ext_4e0870(out, p);
}
PCREG(4602b0, closestPoint);
