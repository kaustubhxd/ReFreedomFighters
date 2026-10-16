#include "ff.h"
extern "C" void FASTCALL ext_4dfb10(const float*,const float*,float,float*);
// qpul(float* out, const float* a, const float* b, float t) [medium, GameCube reference]. __fastcall (out ECX, a EDX), ret 8.
// Quaternion blend: dot(a, b) > 0.9 -> per-component lerp a + (b - a) t; otherwise a is flipped to the
// hemisphere of b (when |b - a|^2 > |b + a|^2) and QuatSlerp(a', b, t, out) is used.
static void FASTCALL qpul(float *out, const float *a, const float *b, float t) {
  float a0 = a[0], a1 = a[1], b0 = b[0], b1 = b[1], b2 = b[2], b3 = b[3];
  float d = a0 * b0 + b1 * a1;
  d = d + b2 * a[2];
  d = d + b3 * a[3];
  if (d > bitsf(0x3f666666)) {
    out[0] = (b0 - a0) * t + a[0];
    out[1] = (b[1] - a[1]) * t + a[1];
    out[2] = (b[2] - a[2]) * t + a[2];
    out[3] = (b[3] - a[3]) * t + a[3];
    return;
  }
  float tmp[4];
  float a2 = a[2], a3 = a[3];
  tmp[0] = a0; tmp[1] = a1; tmp[2] = a2; tmp[3] = a3;
  float m1 = b1 - a1, p1 = b1 + a[1];
  float m0 = b0 - a[0], p0 = b0 + a[0];
  float m2 = b2 - a2, p2 = b2 + a[2];
  float m3 = b3 - a[3], p3 = b3 + a[3];
  float sp = p0 * p0 + p1 * p1;
  float sm = m0 * m0 + m1 * m1;
  sp = sp + p2 * p2;
  sm = sm + m2 * m2;
  sp = sp + p3 * p3;
  sm = sm + m3 * m3;
  if (sm > sp)
    for (int i = 0; i < 4; i++) tmp[i] = -tmp[i];
  ext_4dfb10(tmp, b, t, out);
}
PCREG(4df040, qpul);

