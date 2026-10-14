// batch926.cpp - unclaimed-09 batch 18: 0x460800 (docs/20-unclaimed-09.md, claim 19). A wrapper around area 42's
// RecSub 0x460650 (ParametricCurve::RecSub, verified there). thiscall with eight stack arguments, ret 0x20, returns int.
#include "ff.h"

// 0x460650, ParametricCurve::RecSub (original code, verified by area 42): thiscall, nine stack arguments.
extern "C" void THISCALL ext_460650(u8 *self, float **cur, int *cnt, float *a, float *b, float *c, float *d, float tol, int maxd, int extra);

// 0x460800 (GUESS name: ParametricCurve::RecSub wrapper): s = (K - x)^2 with K = 1.0 (float at 0x678858); cnt = 0; calls
// 0x460650 with the cursor by reference, cnt by reference, the four points, s, and the two ints; then copies d[0..2] to
// the (updated) cursor and returns cnt + 1.
static int THISCALL recSubWrap(u8 *self, float *out, float *a, float *b, float *c, float *d, float x, int p, int q) {
  float t = G(float, 0x678858) - x;
  float s = t * t;
  int cnt = 0;
  ext_460650(self, &out, &cnt, a, b, c, d, s, p, q);
  out[0] = d[0];
  out[1] = d[1];
  out[2] = d[2];
  return cnt + 1;
}
PCREG(460800, recSubWrap);
