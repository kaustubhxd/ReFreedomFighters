#include "ff.h"

extern "C" double VECTORCALL ext_634d70(double x);  // cos
extern "C" double VECTORCALL ext_634d76(double x);  // sin

// 0x4dec90: fastcall(m = ECX, angles = EDX) -> void. m is a 3x3 float matrix (m[0..8] at +0, +4 ... +0x20); the angles are three floats (x, y, z). Builds sin/cos of each
// angle (CRT wrappers, results rounded to float, call order: sin x, cos x, sin y, cos y, sin z, cos z) and rotates every column triple (m0,m3,m6), (m1,m4,m7), (m2,m5,m8) of m
// in place by z, then x, then y: (a,b,c) -> P = cz*c - sz*b; Q = c*sz + cz*b; b' = cx*Q - sx*a; S = Q*sx + cx*a; a' = cy*S - sy*P; c' = S*sy + cy*P.
static inline void rot3(float &a, float &b, float &c, float sx, float cx, float sy, float cy, float sz, float cz) {
  float P = cz * c - sz * b;
  float Q = c * sz + cz * b;
  float nb = cx * Q - sx * a;
  float S = Q * sx + cx * a;
  float na = cy * S - sy * P;
  float nc = S * sy + cy * P;
  a = na;
  b = nb;
  c = nc;
}

extern "C" void FASTCALL fn_4dec90(float *m, float *ang) {
  float sx = (float)ext_634d76((double)ang[0]);
  float cx = (float)ext_634d70((double)ang[0]);
  float sy = (float)ext_634d76((double)ang[1]);
  float cy = (float)ext_634d70((double)ang[1]);
  float sz = (float)ext_634d76((double)ang[2]);
  float cz = (float)ext_634d70((double)ang[2]);
  rot3(m[0], m[3], m[6], sx, cx, sy, cy, sz, cz);
  rot3(m[1], m[4], m[7], sx, cx, sy, cy, sz, cz);
  rot3(m[2], m[5], m[8], sx, cx, sy, cy, sz, cz);
}
PCREG(4dec90, fn_4dec90);
