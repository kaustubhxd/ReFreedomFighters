// batch35187.cpp - cascade s5 batch 35187 (tier H): 0x45e930 (GUESS signed angle between an entity's direction and the direction towards another entity, in the x/z plane).
#include "ff.h"

extern "C" void THISCALL ext_4db670(u8 *self, float *b);        // ret 4
extern "C" void FASTCALL ext_43e960(float *b, float *a);         // b -= a (x87 single steps), plain ret
extern "C" void THISCALL ext_4e09b0(float *v);                   // negates the three floats, plain ret
extern "C" double VECTORCALL ext_634dbe(double);                 // CRT routine (acos), argument/result in XMM0
typedef u8 *(THISCALL *e1_t)(void *, u32);
typedef void(THISCALL *p1_t)(void *, float *);
typedef void(THISCALL *p2_t)(void *, float *, float *);

// 0x45e930, thiscall(a) ret 4, returns a float in st0 (the stack cookie is not reproduced). e = engine[+0x9b] slot 0x54(a); null returns 0. A = this[8][0x30..0x38]; this slot 0x84(A); B = e[0x30..0x38]; 0x4db670(e, B);
// B -= A (0x43e960); B[1] = 0; when B[0] or B[2] is non-zero (or NaN): len = x87 sqrt(x*x + y*y + z*z), B *= 1/len (x87, double precision), and the float len is kept as `angle`; this slot 0x80(P, A); A = P[0..2] negated (0x4e09b0);
// s = -1 when P[6]*B[0] + P[7]*B[1] + P[8]*B[2] > 0 else 1 (that order of float additions); d = B[1]*A[1] + B[0]*A[0] + B[2]*A[2]; angle = d > K2 (0x678858) ? 0 : K1 (0x67af2c) > d ? pi : (float)acos(d);
// returns (angle * K3 (0x685274)) * s as an x87 value.
static long double THISCALL fn45e930(u8 *self, u32 a) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  u8 *e = (*(e1_t **)tab)[0x54 / 4](tab, a);
  if (!e) return 0.0L;
  float A[3], B[3], P[9];
  float angle = 0;
  u8 *o = *(u8 **)(self + 8);
  A[0] = *(float *)(o + 0x30);
  A[1] = *(float *)(o + 0x34);
  A[2] = *(float *)(o + 0x38);
  (*(p1_t **)self)[0x84 / 4](self, A);
  B[0] = *(float *)(e + 0x30);
  B[1] = *(float *)(e + 0x34);
  B[2] = *(float *)(e + 0x38);
  ext_4db670(e, B);
  ext_43e960(B, A);
  B[1] = 0;
  if (B[0] != 0.0f || B[2] != 0.0f) {
    long double x = B[0], y = B[1], z = B[2];
    long double sq = x * x;
    sq = sq + y * y;
    sq = sq + z * z;
    long double len = fsqrt_x87(sq);
    long double r = 1.0L / len;
    B[0] = (float)((long double)B[0] * r);
    B[1] = (float)((long double)B[1] * r);
    B[2] = (float)(r * (long double)B[2]);
    angle = (float)len;
  }
  (*(p2_t **)self)[0x80 / 4](self, P, A);
  A[0] = P[0];
  A[1] = P[1];
  A[2] = P[2];
  ext_4e09b0(A);
  float t0 = P[6] * B[0];
  float sgn = 1.0f;
  float t1 = P[7] * B[1];
  t1 = t1 + t0;
  float t2 = P[8] * B[2];
  t1 = t1 + t2;
  float K1 = G(float, 0x67af2c);
  if (t1 > 0.0f) sgn = -1.0f;
  float d = B[1] * A[1];
  float d3 = B[0] * A[0];
  float d4 = B[2] * A[2];
  d = d + d3;
  d = d + d4;
  if (d > G(float, 0x678858)) angle = 0;
  else if (K1 > d) angle = bitsf(0x40490fdb);
  else angle = (float)ext_634dbe((double)d);
  long double res = (long double)angle * (long double)G(float, 0x685274);
  res = res * (long double)sgn;
  return res;
}
PCREG(45e930, fn45e930);
