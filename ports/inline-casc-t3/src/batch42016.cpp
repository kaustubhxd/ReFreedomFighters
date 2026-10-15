// batch42016.cpp - Sonnet t3: tier H, ray/plane style float function.
#include "ff.h"

extern "C" void FASTCALL ext_441940(float *out, float *add);  // out += add (vec3), plain ret

// 0x4dfa30, fastcall(out = ecx, q = edx, n, p, d) stdcall-popped ret 0xc, returns bool (al): denom = d.x*n.x + d.y*n.y + n.z*d.z; false when K > |double(denom)| (NaN continues);
// t = ((p.y*d.y + p.x*d.x) + p.z*d.z - ((q.y*d.y + q.x*d.x) + q.z*d.z)) / denom; out = n * t; 0x441940(out, q) adds q; true.
static bool FASTCALL fn4dfa30(float *out, float *q, float *n, float *p, float *d) {
  float dy = d[1], dx = d[0], dz = d[2];
  float nx = n[0];
  float denom = dx * nx;
  denom = denom + dy * n[1];
  denom = denom + n[2] * dz;
  double a = (double)denom;
  if (a < 0.0) a = -a;
  if (G(double, 0x6970c8) > a) return false;
  float t2 = q[1] * dy;
  float t1 = p[1] * dy;
  t1 = t1 + p[0] * dx;
  t1 = t1 + p[2] * dz;
  t2 = t2 + q[0] * dx;
  t2 = t2 + q[2] * dz;
  t1 = t1 - t2;
  t1 = t1 / denom;
  out[0] = nx * t1;
  out[1] = t1 * n[1];
  out[2] = n[2] * t1;
  ext_441940(out, q);
  return true;
}
PCREG(4dfa30, fn4dfa30);
