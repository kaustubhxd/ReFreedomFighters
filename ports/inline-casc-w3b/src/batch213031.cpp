#include "ff.h"

extern "C" u32 ext_62c640(u32 a, u32 b);
extern "C" double VECTORCALL ext_634db2(double base, double exp);

// class of the (lo, hi) pair at p: hi == 0 -> base[0x4c + lo]; else 0x62c640(hi, lo)
static inline u32 cls_le(u8 *base, u8 *p) {
  if (p[1] == 0) return base[0x4c + p[0]];
  return ext_62c640(p[1], p[0]);
}

// 0x6253b0: cdecl(base, a, b): little-endian twin of 0x622980: compares two strings of (lo, hi) byte pairs (2, 3 or 4 bytes wide by class)
extern "C" u32 fn_6253b0(u8 *base, u8 *a, u8 *b) {
  static const u8 map1[25] = {0, 1, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 4, 3};
  static const u8 map2[25] = {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0};
  for (;;) {
    u32 c = cls_le(base, a) - 5;
    if (c > 0x18) break;
    u32 m = map1[c];
    if (m == 4) break;
    u32 w = m == 0 ? 2 : m == 1 ? 3 : m == 2 ? 4 : 2;
    for (u32 k = 0; k < w; k++)
      if (a[k] != b[k]) return 0;
    a += w;
    b += w;
  }
  u32 c = cls_le(base, b) - 5;
  if (c > 0x18) return 1;
  return map2[c] ? 1 : 0;
}
PCREG(6253b0, fn_6253b0);

// 0x662940: thiscall(this, float t) ret 4 -> st0: easing curve selected by the dword at this+0x15: 0 linear, 1 x87 2t^2, 2..5 float
// polynomial terms with exe constants, 6 and above t^n * t^(n-1)-style pow product through the CRT pow (0x634db2)
long double THISCALL fn_662940(u8 *self, float t) {
  u32 n;
  __builtin_memcpy(&n, self + 0x15, 4);
  switch (n) {
    case 0:
    case 1: return (long double)t;
    case 2: {
      long double x = (long double)t;
      return x * (x + x);
    }
    case 3: {
      float c = t * G(float, 0x67da1c);
      c = c * t;
      c = c * t;
      return (long double)c;
    }
    case 4: {
      float x = t * t;
      float c = x * G(float, 0x680a6c);
      c = c * x;
      return (long double)c;
    }
    case 5: {
      float x = t * t;
      float c = x * G(float, 0x6a60a0);
      c = c * x;
      c = c * t;
      return (long double)c;
    }
    case 6: {
      float x = t * t;
      float c = x * G(float, 0x6b7f68);
      c = c * x;
      c = c * x;
      return (long double)c;
    }
    default: {
      float fn = (float)(double)n;
      double p1 = ext_634db2((double)t, (double)fn);
      float r1 = (float)p1;
      u32 m = n - 1;
      float fm = (float)(double)m;
      double p2 = ext_634db2(G(double, 0x697520), (double)fm);
      float r2 = (float)p2;
      return (long double)(r1 * r2);
    }
  }
}
PCREG(662940, fn_662940);
