// batch35196.cpp - cascade s5 batch 35196 (tier H): 0x446b50 (GUESS build an orthonormal frame looking from a position towards a point, and hand it to the object).
#include "ff.h"

extern "C" void THISCALL ext_4db2a0(u8 *self, float *m);                       // copies 0x24 bytes (3x3 matrix) from self to m, ret 4
extern "C" void FASTCALL ext_43e920(float *out, float *a, float *b);           // out = a - b, ret 4
extern "C" void FASTCALL ext_446ee0(float *out, float *p, float *q);           // cross-product style, ret 4
typedef void(THISCALL *v1_t)(void *, float *);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// x87 normalisation in double precision (as the exe's fld / fmul / fsqrt / fdiv sequence): v *= 1 / sqrt(x*x + y*y + z*z), each component stored back as a float.
static void normalize(float *v) {
  long double x = v[0], y = v[1], z = v[2];
  long double sq = x * x;
  sq = sq + y * y;
  sq = sq + z * z;
  long double len = fsqrt_x87(sq);
  long double r = 1.0L / len;
  v[0] = (float)((long double)v[0] * r);
  v[1] = (float)((long double)v[1] * r);
  v[2] = (float)(r * (long double)v[2]);
}

// 0x446b50, thiscall(a, unused) ret 8, no return value (the stack cookie is not reproduced). M = 3x3 matrix copied from [[this+8]+0x50] (0x4db2a0); V = M[0..2] = a - ([this+8] + 0x24) (0x43e920); when V is non-zero it is normalised; W = M[3..5], U = M[6..8];
// dot = (W.y * V.y + W.x * V.x) + W.z * V.z; when |dot| (as a double) equals the double at 0x678610 exactly, W.x += 1.0 (0x678858); U = 0x446ee0(W, V); when non-zero U is normalised; W = 0x446ee0(V, U); then this slot 0x6c(M).
static void THISCALL fn446b50(u8 *self, float *a, u32 unused) {
  float M[9];
  float *V = M, *W = M + 3, *U = M + 6;
  u8 *o = *(u8 **)(self + 8);
  ext_4db2a0(*(u8 **)(o + 0x50), M);
  ext_43e920(V, a, (float *)(o + 0x24));
  if (V[0] != 0.0f || V[1] != 0.0f || V[2] != 0.0f) normalize(V);
  float t1 = W[1] * V[1];
  float t0 = W[0] * V[0];
  t1 = t1 + t0;
  float t2 = W[2] * V[2];
  t1 = t1 + t2;
  double ad = (double)t1;
  ad = ad < 0 ? -ad : ad;
  if (ad == G(double, 0x678610)) W[0] = W[0] + G(float, 0x678858);
  ext_446ee0(U, W, V);
  if (U[0] != 0.0f || U[1] != 0.0f || U[2] != 0.0f) normalize(U);
  ext_446ee0(W, V, U);
  (*(v1_t **)self)[0x6c / 4](self, M);
}
PCREG(446b50, fn446b50);
