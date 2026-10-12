// batch422.cpp - unclaimed-42 batch 2 (claim 2, slice floor(addr/16) mod 20 = 1). Names from the GC name map (naming only).
#include "ff.h"

// 0x5a5dd0, ZOnScreenDisplay::CalcProjection2D(float*, float, float, ZGEOM*, ZCAMERA*) (high): thiscall, ret 0x14.
// out[0] = (s*r/t)/r * x; out[1] = -((s*r/t)/r * y / cam+0x40); out[2] = s*r/t, where s = 2*geom8+0x44, t = s/this+0x2f4
// (times c0 when this+0x658 != 0 and this+0x8d0 == 2), r = 0x68c740 / tan(cam+0x5c * c0) in double precision.
static void THISCALL osdCalcProjection2D(u8 *self, float *out, float x, float y, u8 *geom, u8 *cam) {
  const float c0 = G(float, 0x67a6ac);
  u8 *g8 = *(u8 **)(geom + 8);
  float s = *(float *)(g8 + 0x44);
  s = s + s;
  float t = s / *(float *)(self + 0x2f4);
  if (*(u8 *)(self + 0x658) != 0 && *(u32 *)(self + 0x8d0) == 2) t = t * c0;

  float c5c = *(float *)(cam + 0x5c) * c0;
  double d = crt::tan((double)c5c);
  float rf = (float)(G(double, 0x68c740) / d);

  float x2 = s * rf;
  x2 = x2 / t;
  float x1 = x2 / rf;
  float x0 = x1;
  x1 = x1 * x;
  x0 = x0 * y;
  x0 = x0 / *(float *)(cam + 0x40);

  out[0] = x1;
  out[1] = bitsf(fbits(x0) ^ G(u32, 0x67af40));
  out[2] = x2;
}
PCREG(5a5dd0, osdCalcProjection2D);
