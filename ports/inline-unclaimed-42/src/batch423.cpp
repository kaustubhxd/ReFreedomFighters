// batch423.cpp - unclaimed-42 batch 3 (claim 3, residue 1). ParametricCurve::RecSub, the cubic de Casteljau subdivision.
// Names from the GC name map (naming only, never committed).
#include "ff.h"

// ext_460870: the flatness test of one segment (the original code of another area). Stdcall, five stack arguments,
// returns AL. The four points are the control points of the segment; tol is the tolerance (float).
extern "C" u8 STDCALL ext_460870(const float *p0, const float *a, const float *b, const float *c, float tol);

// out = (x + y) * 0.5, the way the original computes it: the sum in double precision (x87), rounded to float, then the
// exact scale by 0.5 in single precision.
static void midpoint(float *out, const float *x, const float *y) {
  for (int i = 0; i < 3; ++i) out[i] = (float)((double)x[i] + (double)y[i]) * 0.5f;
}

// 0x460650, ParametricCurve::RecSub(float*&, int&, float*, float*, float*, float*, float, int, int) (high): thiscall,
// nine stack arguments, ret 0x24. If the count has reached maxd-1 it returns. If the segment p0,a,b,c is flat (the test
// 0x460870 is true), p0 is appended at the cursor (when the cursor is not null) and the count goes up by one. Otherwise
// the curve is split at t = 0.5 and both halves are recursed: (p0, (p0+a)/2, ...) and (mid, ..., c). The extra argument
// is passed through unchanged.
static void THISCALL paramCurveRecSub(u8 *self, u8 **buf, s32 *count, float *p0, float *a, float *b, float *c, float tol,
                                      s32 maxd, u32 extra) {
  s32 lim = maxd - 1;
  if (*count >= lim) return;
  if (ext_460870(p0, a, b, c, tol)) {
    u8 *cur = *buf;
    if (cur) {
      float *dst = (float *)cur;
      dst[0] = p0[0];
      dst[1] = p0[1];
      dst[2] = p0[2];
      *buf = cur + 12;
    }
    *count += 1;
    return;
  }
  float mpa[3], mab[3], mpab[3], mbc[3], mabc[3], mid[3];
  midpoint(mpa, p0, a);
  midpoint(mab, a, b);
  midpoint(mpab, mpa, mab);
  midpoint(mbc, b, c);
  midpoint(mabc, mab, mbc);
  midpoint(mid, mpab, mabc);
  paramCurveRecSub(self, buf, count, p0, mpa, mpab, mid, tol, maxd, extra);
  paramCurveRecSub(self, buf, count, mid, mabc, mbc, c, tol, maxd, extra);
}
PCREG(460650, paramCurveRecSub);
