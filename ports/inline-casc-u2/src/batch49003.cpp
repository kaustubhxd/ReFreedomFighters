// batch49003.cpp - cascade u2 batch 49003: 0x407770 (autocorrelation + Levinson-Durbin LPC; x87 code run at 53-bit precision, ported with double).
#include "ff.h"

// 0x407770, cdecl(x, lpc, n, m): returns the final error in st0. buf[j] = (float)(c0 + sum_t x[t]*x[t+j]) for j = m..0 (c0 = double at 0x6be098);
// then the recursion on double temporaries with float stores; an error equal to the float at 0x6bdfd4 (or NaN) zeroes lpc and returns that constant.
static double fn407770(float *x, float *lpc, int n, int m) {
  float *buf = (float *)__builtin_alloca(4 * (m + 1) + 4);
  for (int j = m; j >= 0; j--) {
    double acc = G(double, 0x6be098);
    for (int t = 0; t < n - j; t++) acc += (double)x[t] * (double)x[j + t];
    buf[j] = (float)acc;
  }
  double E = buf[0];
  if (m <= 0) return E;
  const float eps = G(float, 0x6bdfd4);
  const float one = G(float, 0x6be05c);
  for (int i = 0; i < m; i++) {
    double r = -(double)buf[i + 1];
    if (!((double)E < (double)eps) && !((double)E > (double)eps)) {
      for (int k = 0; k < m; k++) lpc[k] = 0;
      return (double)eps;
    }
    for (int j = 0; j < i; j++) r = r - (double)lpc[j] * (double)buf[i - j];
    r = r / E;
    lpc[i] = (float)r;
    int h = i / 2;
    for (int j = 0; j < h; j++) {
      double tj = lpc[j];
      lpc[j] = (float)(((double)lpc[j] + r * (double)lpc[i - 1 - j]));
      lpc[i - 1 - j] = (float)((double)lpc[i - 1 - j] + r * tj);
    }
    if (i & 1) lpc[h] = (float)((r + (double)one) * (double)lpc[h]);
    E = E * ((double)one - r * r);
  }
  return E;
}
PCREG(407770, fn407770);
