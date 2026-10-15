// batch33114.cpp - h3 (Sonnet) batch 33114: tier H float/SSE functions
#include "ff.h"

#define SYS (*(u8 **)0x70039c)

static inline void W32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline float RF(u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return bitsf(v); }
static inline void WF(u8 *p, float f) { W32(p, fbits(f)); }

// 0x5d0c90: thiscall no args: two input axes ([0xb2b], [0xb23]) scaled by the stick scale [0xadd] into [0xa60]/[0xa64] with dead zones (|x| < 0.3 / 0.5 -> 0); [0xa64] != 0 -> [0xb05]=1.0; angle [0xa54] += clamp-to-pi step with wrap by 2*pi; [0xa5c] += dt*[0xa64] clamped to [[0xa9e], [0xaa2]]
static void THISCALL fn5d0c90(u8 *self) {
  float x1 = RF(self + 0xb2b);
  float x2 = RF(self + 0xadd);
  const float K1 = bitsf(0xc05f66f3u), K2 = bitsf(0x3fdf66f3u), PI = bitsf(0x40490fdbu);
  const float C1 = bitsf(0x4048f343u), C2 = bitsf(0xc048f343u), C3 = bitsf(0xc0490fdbu), TWO_PI = bitsf(0x40c90fdbu);
  float v0 = x1 * K1;
  v0 = v0 * x2;
  WF(self + 0xa60, v0);
  if (0.30000001192092896 > __builtin_fabs((double)x1)) W32(self + 0xa60, 0);
  float y1 = RF(self + 0xb23);
  float v1 = y1 * K2;
  v1 = v1 * x2;
  WF(self + 0xa64, v1);
  if (0.5 > __builtin_fabs((double)y1)) W32(self + 0xa64, 0);
  if (!(RF(self + 0xa64) == 0.0f)) W32(self + 0xb05, 0x3f800000);
  float dt = *(float *)(SYS + 0x48);
  float s = dt * RF(self + 0xa60);
  if (s > C1 || C2 > s) s = PI;
  float a = RF(self + 0xa54);
  a = a + s;
  if (a > PI) a = a - TWO_PI;
  else if (C3 > a) a = a + TWO_PI;
  WF(self + 0xa54, a);
  float d = *(float *)(SYS + 0x48);
  d = d * RF(self + 0xa64);
  d = d + RF(self + 0xa5c);
  float lo = RF(self + 0xa9e);
  WF(self + 0xa5c, d);
  float r;
  if (lo > d) r = lo;
  else {
    float hi = RF(self + 0xaa2);
    r = (hi < d) ? hi : d;
  }
  WF(self + 0xa5c, r);
}
PCREG(5d0c90, fn5d0c90);
