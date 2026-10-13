// batch21.cpp - first-level functions, inline session batch 21 (Haiku, overnight).
#include "ff.h"

// 0x470550, thiscall (ret 4, no return value): count at this+0x8b4, array at this+0x8b8. Finds value among the first
// count entries; when found, the last entry moves into its slot and the count drops by one. Name unknown.
static void THISCALL removeLast(u8 *self, u32 value) {
  u32 *cnt = (u32 *)(self + 0x8b4);
  u32 *arr = (u32 *)(self + 0x8b8);
  u32 n = *cnt;
  for (u32 i = 0; i < n; i++) {
    if (arr[i] == value) {
      arr[i] = arr[n - 1];
      *cnt = *cnt - 1;
      return;
    }
  }
}
PCREG(470550, removeLast);

// 0x45d2b0, thiscall (ret 4, returns AL): the object's +8 is a pointer to three float bounds at +0x40, +0x44, +0x48.
// Returns 1 when |v[k]| is not greater than bound k for k = 0, 1, 2. Each value is widened to double and its sign bit is
// cleared (andps with 0x7fffffffffffffff); a NaN compares as not greater, so it passes. Name unknown.
static u8 THISCALL withinBounds3(u8 *self, const float *v) {
  u8 *bo = *(u8 **)(self + 8);
  for (int k = 0; k < 3; k++) {
    u64 bits = __builtin_bit_cast(u64, (double)v[k]) & 0x7fffffffffffffffULL;
    double x = __builtin_bit_cast(double, bits);
    double lim = (double)*(float *)(bo + 0x40 + 4 * k);
    if (x > lim)
      return 0;
  }
  return 1;
}
PCREG(45d2b0, withinBounds3);

// 0x4604f0, thiscall (ret 8, no return value): stack args out (3 floats) and t. The object holds 13 floats m[0..12] and
// the three outputs are cubics in t, one per axis k, using m[1+4k .. 4+4k] by Horner's rule:
//   out[k] = ((((m[1+4k] * t) + m[2+4k]) * t + m[3+4k]) * t) + m[4+4k]. The result of each axis is stored before the
// next axis is read. Name unknown.
static void THISCALL evalCubic3(float *m, float *out, float t) {
  for (int k = 0; k < 3; k++) {
    const float *c = m + 1 + 4 * k;
    float v = c[0];
    v = v * t;
    v += c[1];
    v = v * t;
    v += c[2];
    v = v * t;
    v += c[3];
    out[k] = v;
  }
}
PCREG(4604f0, evalCubic3);
