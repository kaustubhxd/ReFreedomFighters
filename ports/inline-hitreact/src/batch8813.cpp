// batch8813.cpp - hit-reaction thread, batch 8813: two ZeroOut helpers, the minimum-distance constraint 0x543680 (taken over from area 50)
// and mmmul 0x4de440.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])

extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);        // PSVECSubtract d = a - b
extern "C" void FASTCALL ext_451890(float *d, const float *v, float s);               // vaddscalar d += v * s
extern "C" void FASTCALL ext_441970(float *out, const float *v, const float *m);      // vmmul

typedef float (THISCALL *vRand)(void *self, const char *file, u32 line);
static const char *const FILE_P3 = (const char *)0x6a2e20;   // '..\\..\\code\\engine\\dynamics\\particle3.cpp'

// 0x543680 (no name in the map; ZeroOut's minimum-distance constraint), fastcall: ECX = position A, EDX = position B, stack: wA, wB,
// minDist; ret 0xc. v = B - A; len = |v| (float from the CRT sqrt of the float sum (x^2 + y^2) + z^2). len > minDist -> nothing. While
// len < 1e-6: v = three engine randoms (engine [0x70039c] slot 0x1c4, file particle3.cpp line 0xa99), len = |v|. Then
// k = (len - minDist) * C / ((wA + wB) * len) with C = [0x680a58]; A += v * (k * wB); B += v * -(k * wA).
static void FASTCALL minDistance(float *A, float *B, float wA, float wB, float minDist) {
  float v[3];
  ext_43e920(v, B, A);
  float q = v[0] * v[0] + v[1] * v[1];
  q = q + v[2] * v[2];
  float len = (float)crt::sqrt((double)q);
  if (len > minDist) return;
  while (G(float, 0x681370) > len) {
    u8 *e = G(u8 *, 0x70039c);
    float r1 = ((vRand)VT(e, 0x1c4))(e, FILE_P3, 0xa99);
    e = G(u8 *, 0x70039c);
    float r2 = ((vRand)VT(e, 0x1c4))(e, FILE_P3, 0xa99);
    e = G(u8 *, 0x70039c);
    float r3 = ((vRand)VT(e, 0x1c4))(e, FILE_P3, 0xa99);
    v[0] = r1; v[1] = r2; v[2] = r3;
    float s = r1 * r1 + r2 * r2;
    s = s + r3 * r3;
    len = (float)crt::sqrt((double)s);
  }
  float k = (len - minDist) * G(float, 0x680a58) / ((wA + wB) * len);
  ext_451890(A, v, k * wB);
  volatile float tv = k * wA;   // the multiply before the sign flip (clang would fold the negation into wA and lose the NaN sign)
  float t = tv;
  ext_451890(B, v, bitsf(fbits(t) ^ 0x80000000u));   // xorps with the sign mask (0x67af40), also on a NaN
}
PCREG(543680, minDistance);

// 0x4de440 mmmul(float* out, const float* a, const float* b) (), fastcall + 1 stack arg, ret 4: the rows of out from vmmul of
// the rows of a with b, row 2 first, then row 1, then row 0.
static void FASTCALL mmmul(float *out, const float *a, const float *b) {
  ext_441970(out + 6, a + 6, b);
  ext_441970(out + 3, a + 3, b);
  ext_441970(out, a, b);
}
PCREG(4de440, mmmul);
