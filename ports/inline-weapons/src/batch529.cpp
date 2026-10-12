// batch529.cpp - weapons thread, batch 529: VerifyMat (0x4e2d60), the 3x3 matrix check used by PerformDrop and the
// rotation helper. The object is the matrix holder: column A = (M[0x18], M[0x1c], M[0x20]), column B =
// (M[0xc], M[0x10], M[0x14]), column C = (M[0], M[4], M[8]). Each column must have unit length (|len - 1| <= 1e-4,
// else a warning is logged, lines 0x2ac/0x2ae/0x2b0 with the length); the dot products of each column with the
// cross product of the other two must be within [0.999, 1.001] (lines 0x2b5/0x2b9/0x2bd). Nothing is repaired.
// Returns 1 when any check failed. Logger: [0x700390], slot 0x20 (file, line) -> stream, slot 0x2c = printf (cdecl).
// Source file string 0x697204 ("..\..\code\..." zlnk/geom math file).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef void *(THISCALL *vLogLine)(void *self, const char *file, u32 line);
typedef void (*logPrintf)(void *self, const char *fmt, double v);
extern "C" void FASTCALL ext_446ee0(float *dst, const float *a, const float *b);   // vcross: dst in ecx, a in edx, b on the stack

static const char *const kMathFile = (const char *)0x697204;
static inline void warnLen(u32 line, const char *msg, double v) {
  u8 *l = G(u8 *, 0x700390);
  void *st = ((vLogLine)VT(l, 0x20))(l, kMathFile, line);
  ((logPrintf)VT(st, 0x2c))(st, msg, v);
}
// Length of a vector as the exe computes it: float sum of squares (x^2, then + y^2, then + z^2), sqrt in double,
// rounded to float.
static inline float lenF(const float *v) {
  float s = v[0] * v[0];
  s += v[1] * v[1];
  s += v[2] * v[2];
  return (float)crt::sqrt((double)s);
}
static inline bool badUnit(float l) { return __builtin_fabsf(l - 1.0f) > 0.0001f; }
// Dot product in the exe's order ((p0*q0 + p1*q1) + p2*q2), float; NaN is never flagged (comiss/jbe).
static inline float dotF(const float *p, const float *q) { return p[0] * q[0] + p[1] * q[1] + p[2] * q[2]; }
static inline bool badDot(float d) { return 0.999f > d || d > 1.001f; }

// 0x4e2d60 VerifyMat (thiscall, no stack args, returns al). The float compares use single precision; the lengths and
// dots are computed as the exe does (float products, then sqrt in double).
static u8 THISCALL verifyMat(u8 *m) {
  float *fm = (float *)m;
  u8 flag = 0;
  float a[3] = {fm[0x18 / 4], fm[0x1c / 4], fm[0x20 / 4]};
  float b[3] = {fm[0xc / 4], fm[0x10 / 4], fm[0x14 / 4]};
  float c[3] = {fm[0], fm[1], fm[2]};
  float la = lenF(a), lb = lenF(b), lc = lenF(c);
  if (badUnit(la)) { warnLen(0x2ac, (const char *)0x697230, (double)la); flag = 1; }
  if (badUnit(lb)) { warnLen(0x2ae, (const char *)0x697248, (double)lb); flag = 1; }
  if (badUnit(lc)) { warnLen(0x2b0, (const char *)0x697260, (double)lc); flag = 1; }
  float x[3];
  ext_446ee0(x, b, c);                       // x = b cross c
  float d1 = dotF(a, x);
  if (badDot(d1)) { warnLen(0x2b5, (const char *)0x697278, (double)d1); flag = 1; }
  ext_446ee0(x, c, a);                       // x = c cross a
  float d2 = dotF(b, x);
  if (badDot(d2)) { warnLen(0x2b9, (const char *)0x697290, (double)d2); flag = 1; }
  ext_446ee0(x, a, b);                       // x = a cross b
  float d3 = dotF(c, x);
  if (badDot(d3)) { warnLen(0x2bd, (const char *)0x6972a8, (double)d3); flag = 1; }
  return flag;
}
PCREG(4e2d60, verifyMat);
