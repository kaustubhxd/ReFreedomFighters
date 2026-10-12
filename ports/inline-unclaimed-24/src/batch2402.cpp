// batch2402.cpp - decomp area 24, batch 2402: ZCloth::ApplyWind(float* positions, float strength) (0x44f0f0),
// thiscall, ret 8. Cloth fields: +0x24 mode (dword; 0 = off), +0x28 wind vector (3 floats), +0x2c a float written into
// the wind's y component in the gust branch, +0x64 flags pointer (dword per vertex), +0x6c triangle count, +0x70
// triangle array (6-byte records: three 16-bit vertex indices).
// Helpers through the exe (ext_): vscalar (0x4e0d00 in place, 0x4e0d40 to dst, both scale by a float), vrot (0x4e0be0,
// rotate a vector by an axis-angle vector), 0x451560 (a float length helper, value in ST0), and the virtual slots
// 0x84 (fill a vector, mode 2 only) and 0x90 (fill the wind vector).
// The normal normalisation runs on the x87 in extended precision (as the original's fld/fmul/fsqrt/fdiv chain).
#include "ff.h"

extern "C" void FASTCALL ext_4e0d40(float *dst, const float *src, float s);   // vscalar to dst (ret 4)
extern "C" void THISCALL ext_4e0d00(float *v, float s);                       // vscalar in place (ret 4)
extern "C" void FASTCALL ext_4e0be0(float *v, const float *axisAngle);        // vrot
extern "C" float THISCALL ext_451560(float *v);                               // length helper (ST0)

static inline float fbitsToF(u32 b) { return __builtin_bit_cast(float, b); }

static void THISCALL clothApplyWind(u8 *self, float *pos, float strength) {
  u32 mode = *(u32 *)(self + 0x24);
  if (mode == 0)
    return;
  float wind[3] = {0, 0, 0};
  if (mode == 1 || mode == 3) {
    ext_4e0d40(wind, (float *)(self + 0x28), strength * 60.0f);
  } else if (mode == 2) {
    // gust branch: the original rotates the (not yet filled) wind vector; the fill below overwrites it.
    float v[3] = {0, 0, 0};
    vcall<void>(self, 0x84, v);
    ext_4e0d00(v, fbitsToF(0x38d1b717u));
    float t = ext_451560(v);
    double td = (double)t;
    float angle = (float)__builtin_fabs(td) * 4.0f * 3.14159274f;
    (void)angle;
    float axis[3] = {0, angle, 0};
    ext_4e0be0(wind, axis);
    wind[1] = *(float *)(self + 0x2c);
    ext_4e0d00(wind, 0.25f);
  }
  vcall<void>(self, 0x90, wind);
  u32 count = *(u32 *)(self + 0x6c);
  if (count == 0)
    return;
  u8 *tri = *(u8 **)(self + 0x70);
  u32 *flags = *(u32 **)(self + 0x64);
  for (u32 k = 0; k < count; ++k, tri += 6) {
    u32 i0 = *(u16 *)(tri + 0), i1 = *(u16 *)(tri + 2), i2 = *(u16 *)(tri + 4);
    float *P0 = pos + 3 * i0, *P1 = pos + 3 * i1, *P2 = pos + 3 * i2;
    float x01 = P0[0] - P1[0], y01 = P0[1] - P1[1], z01 = P0[2] - P1[2];
    float x12 = P1[0] - P2[0], y12 = P1[1] - P2[1], z12 = P1[2] - P2[2];
    float n[3];
    n[0] = y12 * z01 - z12 * y01;
    n[1] = z12 * x01 - x12 * z01;
    n[2] = x12 * y01 - y12 * x01;
    // normalise when any component is non-zero or NaN (the original's ucomiss/jp chain)
    bool any = !(n[0] == 0.0f) || !(n[1] == 0.0f) || !(n[2] == 0.0f);
    if (any) {
      long double S = (long double)n[0] * (long double)n[0];
      S = S + (long double)n[1] * (long double)n[1];
      S = S + (long double)n[2] * (long double)n[2];
      long double len = fsqrt_x87(S);
      long double inv = 1.0L / len;
      n[0] = (float)((long double)n[0] * inv);
      n[1] = (float)((long double)n[1] * inv);
      n[2] = (float)((long double)n[2] * inv);
    }
    float dot = ((wind[0] * n[0]) + (n[1] * wind[1])) + (wind[2] * n[2]);
    float dot2 = dot + dot;
    float q[3] = {n[0] * dot2, n[1] * dot2, n[2] * dot2};
    u32 i1f = i1;
    (void)i1f;
    if (flags[i0] != 0) {
      P0[0] = P0[0] - q[0];
      P0[1] = P0[1] - q[1];
      P0[2] = P0[2] - q[2];
    }
    if (flags[i1] != 0) {
      P1[0] = P1[0] - q[0];
      P1[1] = P1[1] - q[1];
      P1[2] = P1[2] - q[2];
    }
    if (flags[i2] != 0) {
      P2[0] = P2[0] - q[0];
      P2[1] = P2[1] - q[1];
      P2[2] = P2[2] - q[2];
    }
  }
}
PCREG(44f0f0, clothApplyWind);
