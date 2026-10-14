// batch35193.cpp - cascade s5 batch 35193 (tier H): 0x40fe70 (GUESS find all real roots of a polynomial with Laguerre's method and deflation).
#include "ff.h"

// 0x40fe70, cdecl(coef, n, out), returns 0 or -1 (the exe works on an alloca'd double copy of the n + 1 float coefficients; x87 arithmetic in double precision, kept in long double here like the original).
// For each degree m = n .. 1: x = C0 (0x6be098 double); iterate Laguerre: b = D[m], f = d = C0; for k = m .. 1: f = f*x + d; d = d*x + b; b = b*x + D[k-1] (all from the old values);
// disc = (((m - 1) * d) * d - (m * f) * b) * (m - 1); when disc is not >= C0 returns -1. sq = sqrt(disc); den = d > C0 ? max(d + sq, C1 (0x6be128)) : min(d - sq, C2 (0x6be120)) (NaN handling as the compares); dx = (m * b) / den;
// x1 = x - dx; when dx is not >= C0 dx *= C3 (0x6be118); r = |dx / x1|; r >= C4 (0x6be110): x = x1 and again. Otherwise out[m - 1] = (float)x1 and the polynomial is deflated in place: for k = m .. 1: D[k-1] = x1 * D[k] + D[k-1]; D advances by one, m decreases. Returns 0 after the last root (or at once for n <= 0).
static s32 fn40fe70(float *coef, s32 n, float *out) {
  double Dbuf[130];
  if (n >= 0)
    for (s32 i = 0; i <= n && i < 129; i++) Dbuf[i] = (double)coef[i];
  if (n <= 0) return 0;
  double *D = Dbuf;
  long double C0 = G(double, 0x6be098);
  s32 m = n;
  do {
    long double x = C0;
    long double x1;
    for (;;) {
      long double f = C0, d = C0, b = D[m];
      for (s32 k = m; k >= 1; k--) {
        long double nf = f * x;
        nf = nf + d;
        long double nd = d * x;
        nd = nd + b;
        long double nb = b * x;
        nb = nb + D[k - 1];
        f = nf;
        d = nd;
        b = nb;
      }
      long double Nm1 = (s32)(m - 1);
      long double N = (long double)(double)m;
      long double t = Nm1 * d;
      t = t * d;
      long double u = N * f;
      u = u * b;
      long double S = t - u;
      long double disc = S * Nm1;
      if (!(disc >= C0)) return -1;
      long double sq = fsqrt_x87(disc);
      long double den;
      if (d > C0) {
        den = d + sq;
        if (!(den >= (long double)G(double, 0x6be128))) den = G(double, 0x6be128);
      } else {
        den = d - sq;
        if (den > (long double)G(double, 0x6be120)) den = G(double, 0x6be120);
      }
      long double nb2 = b * N;
      long double dx = nb2 / den;
      x1 = x - dx;
      if (!(dx >= C0)) dx = dx * (long double)G(double, 0x6be118);
      long double r = dx / x1;
      if (r < 0) r = -r;
      x = x1;
      if (!(r >= (long double)G(double, 0x6be110))) break;
    }
    out[m - 1] = (float)x1;
    for (s32 k = m; k >= 1; k--) {
      long double t2 = x1 * D[k];
      t2 = t2 + D[k - 1];
      D[k - 1] = (double)t2;
    }
    D++;
    m--;
  } while (m > 0);
  return 0;
}
PCREG(40fe70, fn40fe70);
