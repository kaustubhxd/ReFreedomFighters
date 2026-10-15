// batch8824.cpp - wire-hit-parts (2026-10-15): the triangle-against-unit-sphere test under the collision box's list test
// (0x4e9280 -> 0x4dddf0 -> 0x4ddb20 / 0x4dd930). Names: none in the map (both also called by ZCollisionGC::CalcLineCollision).
#include "ff.h"

extern "C" void FASTCALL ext_43e920(float *out, const float *a, const float *b);   // PSVECSubtract out = a - b
extern "C" void FASTCALL ext_441940(float *v, const float *a);                     // PSVECAdd v += a
extern "C" void FASTCALL ext_441a60(float *v, const float *m);                     // vmtmul in place
extern "C" void FASTCALL ext_446ee0(float *out, const float *a, const float *b);   // vcross
extern "C" float FASTCALL ext_44c840(float *v);                                    // vnorm (length in ST0, discarded here)
extern "C" u8 FASTCALL ext_4dd930(const float *p, const float *d, const float *q); // segment / box slab test (batch43)
extern "C" u8 FASTCALL ext_4ddb20(const float *a, const float *b);                 // this batch

// 0x4ddb20 (fastcall(a, b), plain ret, al): does the segment a -> b touch the unit sphere at the origin? |a|^2 < 1 -> 1. d = b - a;
// unless d is exactly zero, d is normalised in x87 (53-bit: double arithmetic) and L = |d| kept as a float (else L = 0). p = -(a . d);
// p > L or 0 > p -> 0. Else c = a + d * p; returns |c| <= 1 (the CRT sqrt of the float sum; a NaN length counts as touching).
static u8 FASTCALL segSphere(const float *a, const float *b) {
  float s2 = (a[0] * a[0] + a[1] * a[1]) + a[2] * a[2];
  if (G(float, 0x678858) > s2) return 1;
  float d[3];
  ext_43e920(d, b, a);
  float L = 0.0f;
  if (!(d[0] == 0.0f) || !(d[1] == 0.0f) || !(d[2] == 0.0f)) {
    double q = ((double)d[0] * d[0] + (double)d[1] * d[1]) + (double)d[2] * d[2];
    double l = crt::sqrt(q);                      // fsqrt at the 53-bit control word = the correctly rounded double sqrt
    double inv = (double)G(float, 0x678858) / l;   // fld 1.0 (a float local), fdiv
    d[0] = (float)((double)d[0] * inv);
    d[1] = (float)((double)d[1] * inv);
    d[2] = (float)((double)d[2] * inv);
    L = (float)l;
  }
  float p = -((a[0] * d[0] + d[1] * a[1]) + d[2] * a[2]);
  if (p > L) return 0;
  if (0.0f > p) return 0;
  d[0] = d[0] * p;
  d[1] = d[1] * p;
  d[2] = d[2] * p;
  ext_441940(d, a);
  float c2 = (d[0] * d[0] + d[1] * d[1]) + d[2] * d[2];
  float len = (float)crt::sqrt((double)c2);
  return !(len > G(float, 0x678858));
}
PCREG(4ddb20, segSphere);

// 0x4dddf0 (fastcall(centre, m, e0, e1, e2), ret 0xc, al): does the triangle touch the unit sphere of a box frame? v_i = (e_i - centre) *
// m^T (vmtmul). n = (v1 - v0) x (v2 - v1); |n|^2 below float [0x679540] -> 0. An edge v0v1, v1v2, v2v0 touching the sphere (0x4ddb20)
// -> 1. Else n = unit(n) (vnorm); d = v0 . n; |d| > double [0x678610] -> 0; n *= d; returns 0x4dd930(v, n, n) != 0 (the foot of the
// perpendicular inside the triangle).
static u8 FASTCALL triSphere(const float *centre, const float *m, const float *e0, const float *e1, const float *e2) {
  float v[9];
  ext_43e920(v, e0, centre);
  ext_43e920(v + 3, e1, centre);
  ext_43e920(v + 6, e2, centre);
  ext_441a60(v, m);
  ext_441a60(v + 3, m);
  ext_441a60(v + 6, m);
  float a[3], b[3], n[3];
  ext_43e920(a, v + 3, v);
  ext_43e920(b, v + 6, v + 3);
  ext_446ee0(n, a, b);
  float l2 = (n[0] * n[0] + n[1] * n[1]) + n[2] * n[2];
  if (G(float, 0x679540) > l2) return 0;
  if (ext_4ddb20(v, v + 3)) return 1;
  if (ext_4ddb20(v + 3, v + 6)) return 1;
  if (ext_4ddb20(v + 6, v)) return 1;
  ext_44c840(n);
  float d = (v[0] * n[0] + v[1] * n[1]) + v[2] * n[2];
  if (__builtin_fabs((double)d) > G(double, 0x678610)) return 0;
  n[0] = n[0] * d;
  n[1] = n[1] * d;
  n[2] = n[2] * d;
  return ext_4dd930(v, n, n) != 0;
}
PCREG(4dddf0, triSphere);
