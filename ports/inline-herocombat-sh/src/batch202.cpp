// batch202.cpp - ladder tree (inline-ladder thread, 2026-10-11): cubic Bezier segment set-up.
#include "ff.h"

extern "C" void FASTCALL ext_43e920(float *dst, const float *src, const float *a);   // PSVECSubtract (batch 34)
extern "C" void THISCALL ext_4e0d00(float *v, float s);                             // vscalar in place (batch 29)
extern "C" float THISCALL ext_45fe90(u8 *self, float h);                            // ArcLength (batch 200)

// 0x460100, thiscall, five stack args (p0, p1, p2, p3, h), ret 0x14. Name used here: ParametricCurve::SetBezier
// (inferred; no GC match). Builds the power-basis cubic of the Bezier segment p0..p3 per axis k (dst group at
// +4 + 0x10*k): with a = 3*(p1 - p0) and b = 3*(p3 - p2):
//   c0 = ((p0 + p0) - (p3 + p3)) + a + b,  c1 = ((p3*3) - (p0*3)) - a*2 - b,  c2 = a,  c3 = p0 (copied as a dword).
// Stores go in the exe's order (c0, c2, c1, c3 per axis). Then the float at +0x34 = ArcLength(h) (0x45fe90, which also
// writes +0x34 itself). Constants: 3.0 (0x40400000 pushed, and 0x680a68), 2.0 at 0x680a60.
static void THISCALL setBezier(u8 *self, const float *p0, const float *p1, const float *p2, const float *p3, float h) {
  float *o = (float *)(self + 4);
  float a[3], b[3];
  ext_43e920(a, p1, p0);
  ext_4e0d00(a, 3.0f);
  ext_43e920(b, p3, p2);
  ext_4e0d00(b, 3.0f);
  for (int k = 0; k < 3; k++) {
    float *g = o + 4 * k;
    float v = (p0[k] + p0[k]) - (p3[k] + p3[k]);
    v = v + a[k];
    g[0] = v + b[k];
    g[2] = a[k];
    float w = p3[k] * 3.0f - p0[k] * 3.0f;
    w = w - a[k] * 2.0f;
    g[1] = w - b[k];
    ((u32 *)g)[3] = ((const u32 *)p0)[k];
  }
  float len = ext_45fe90(self, h);
  *(float *)(self + 0x34) = len;
}
PCREG(460100, setBezier);
