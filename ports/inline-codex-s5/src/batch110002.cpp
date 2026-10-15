// batch801.cpp - animation layer thread, batch 801: quaternion blend core and ZBoneModifyBase::DepackBone.
#include "ff.h"

#define F8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FF(p, o) (*(float *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

// 0x4dfb10 QuatSlerp(p, q, t, out) [no GC name; called only by qpul; body is the Dolphin SDK C_QUATSlerp shape].
// __fastcall: p in ECX, q in EDX, t and out on the stack (ret 8). Constants read from the exe: 1.0 (0x678858),
// 2^-13 (0x679540), -1.0 (0x67af2c), pi (0x67da18), 0.5 (0x67a6ac).
// When p and q are nearly opposite (cos + 1 <= 2^-13), out = (-p1, p0, -p3, p2) and only out[0..2] are then
// blended (the 4-iteration loop of the SDK is 3 here; out[3] stays p2), as in the original.
static void FASTCALL QuatSlerp(const float *p, const float *q, float t, float *out) {
  const float one = 1.0f, eps = bitsf(0x39000000);
  float c = q[1] * p[1] + p[0] * q[0];
  c = c + q[2] * p[2];
  c = c + q[3] * p[3];
  if (c + one > eps) {
    float sp, sq;
    if (one - c > eps) {
      float om;
      if (c > one) om = 0.0f;
      else if (-1.0f > c) om = bitsf(0x40490fdb);
      else om = (float)crt::acos((double)c);
      double s = (double)(float)crt::sin((double)om);
      sp = (float)(crt::sin((double)((one - t) * om)) / s);
      sq = (float)(crt::sin((double)(om * t)) / s);
    } else {
      sq = t;
      sp = one - t;
    }
    for (int i = 0; i < 4; i++) out[i] = q[i] * sq + p[i] * sp;
    return;
  }
  float p1 = p[1];
  float a = (one - t) * bitsf(0x40490fdb) * 0.5f;
  out[0] = -p1;
  out[1] = p[0];
  out[2] = -p[3];
  out[3] = p[2];
  float sp = (float)crt::sin((double)a);
  float sq = (float)crt::sin((double)(t * bitsf(0x40490fdb) * 0.5f));
  for (int i = 0; i < 3; i++) out[i] = p[i] * sp + out[i] * sq;
}
PCREG(4dfb10, QuatSlerp);

