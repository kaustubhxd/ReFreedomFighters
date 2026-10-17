#include "ff.h"

extern "C" void ext_4513e0();

static inline float dg(const float *g, float a, float b, float c) {
  float r = g[1] * b;
  r = r + a * g[0];
  r = r + g[2] * c;
  return r;
}
static inline float lerpf(float t, float a, float b) {
  float r = b - a;
  r = r * t;
  return r + a;
}

// 0x451560: thiscall(const float *p) -> float (x87 return). 3D gradient noise: the lattice cell of p + [0x681380] (permutation table [0x6ff978], 512 ints; gradient table [0x6ff97c],
// 3 floats per entry; both built by 0x4513e0 when the flag byte [0x6ff980] is clear) with the fade curve (k - 2t) * t * t on each axis and trilinear interpolation of the eight
// corner dot products.
extern "C" float THISCALL fn_451560(const float *p) {
  if (G(u8, 0x6ff980) == 0) ext_4513e0();
  float c1 = G(float, 0x681380);
  float x = p[0] + c1;
  float y = p[1] + c1;
  float z = p[2] + c1;
  float one = G(float, 0x678858);
  const int *perm = G(const int *, 0x6ff978);
  float k3 = G(float, 0x680a68);
  int ix = (int)x;
  int iy = (int)y;
  u32 ix8 = (u8)ix;
  u32 P0 = perm[ix8];
  float fx = x - (float)ix;
  float fx1 = fx - one;
  u32 iy8 = (u8)iy;
  u32 iy81 = (u8)(iy8 + 1);
  float fy = y - (float)iy;
  int iz = (int)z;
  u32 iz8 = (u8)iz;
  u32 iz81 = (u8)(iz8 + 1);
  float fy1 = fy - one;
  u32 P1 = perm[(u8)(ix8 + 1)];
  u32 AA = perm[P0 + iy8];
  float fz = z - (float)iz;
  u32 BA = perm[P1 + iy8];
  u32 AB = perm[P0 + iy81];
  u32 BB = perm[P1 + iy81];
  float fz1 = fz - one;
  const float *grad = G(const float *, 0x6ff97c);
  float u = k3 - (fx + fx);
  u = u * (fx * fx);
  float v = k3 - (fy + fy);
  v = v * (fy * fy);
  float d000 = dg(grad + 3 * (AA + iz8), fx, fy, fz);
  float d100 = dg(grad + 3 * (BA + iz8), fx1, fy, fz);
  float L00 = lerpf(u, d000, d100);
  float d010 = dg(grad + 3 * (AB + iz8), fx, fy1, fz);
  float d110 = dg(grad + 3 * (BB + iz8), fx1, fy1, fz);
  float L10 = lerpf(u, d010, d110);
  float d001 = dg(grad + 3 * (AA + iz81), fx, fy, fz1);
  float M0 = lerpf(v, L00, L10);
  float d101 = dg(grad + 3 * (BA + iz81), fx1, fy, fz1);
  float L01 = lerpf(u, d001, d101);
  float d011 = dg(grad + 3 * (AB + iz81), fx, fy1, fz1);
  float d111 = dg(grad + 3 * (BB + iz81), fx1, fy1, fz1);
  float L11 = lerpf(u, d011, d111);
  float w = k3 - (fz + fz);
  w = w * (fz * fz);
  float M1 = lerpf(v, L01, L11);
  return lerpf(w, M0, M1);
}
PCREG(451560, fn_451560);
