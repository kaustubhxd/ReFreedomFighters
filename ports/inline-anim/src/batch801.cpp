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
  QuatSlerp(tmp, b, t, out);
}
PCREG(4df040, qpul);

// ZBoneModifyBase::DepackBone(ZBoneQuat* out, ZBlendBone* bb, ZAnimFileBase* file, const ZActiveBone* ab)
// [high, GameCube reference]. thiscall (this unused), ret 0x10.
//   ZBoneQuat:   +0 quat[4], +0x24 pos[3]                     (stride 0x30)
//   ZBlendBone:  +0 quat[4], +0x10 pos[3], +0x1c last anim, +0x20 start time (int, 1/1024 s ticks) (stride 0x24)
//   ZActiveBone: +0 anim, +4 frame, +8 blend-in time, +0xc 2nd anim, +0x10 2nd weight, +0x14 2nd frame,
//                +0x18 extra offset (quat[4], pos[3] at +0x10)                       (packed, stride 0x1d)
// No anim: the blend bone is copied out. Otherwise: sample anim (file vt 0xc = GetFramePosQuat(id, 0, pos, quat,
// frame)), blend a second anim on top (qpul + lerp by weight), apply the extra offset (qmul + PSVECAdd), then fade in
// from the previous pose over the blend-in time when the anim changed (weight (dt/T)^2, dt from the clock at
// [0x70039c]+0x40), and store the result back into the blend bone.
// The original guards the two blend-bone time stores with "&field != &local" (an inlined self-assignment check);
// that is always true for heap objects and is not reproduced.
extern "C" void FASTCALL ext_4def50(float *out, const float *a, const float *b);  // qmul (batch in docs/18)
extern "C" void FASTCALL ext_441940(float *dst, const float *src);                 // PSVECAdd (batch 34)
static void THISCALL DepackBone(void *, float *q, u8 *bb, void *file, const u8 *ab) {
  if (F32(ab, 0) == 0) {
    F32(q, 0) = F32(bb, 0); F32(q, 4) = F32(bb, 4); F32(q, 8) = F32(bb, 8); F32(q, 0xc) = F32(bb, 0xc);
    F32(q, 0x24) = F32(bb, 0x10); F32(q, 0x28) = F32(bb, 0x14); F32(q, 0x2c) = F32(bb, 0x18);
    return;
  }
  float *pos = q + 9;
  typedef void(THISCALL * gfpq)(void *, u32, u32, float *, float *, float);
  (*(gfpq *)(*(u8 **)file + 0xc))(file, F32(ab, 0), 0, pos, q, FF(ab, 4));
  if (F32(ab, 0xc)) {
    float tq[4], tp[3];
    (*(gfpq *)(*(u8 **)file + 0xc))(file, F32(ab, 0xc), 0, tp, tq, FF(ab, 0x14));
    qpul(q, q, tq, FF(ab, 0x10));
    float w = FF(ab, 0x10);
    pos[0] = (tp[0] - pos[0]) * w + pos[0];
    pos[1] = (tp[1] - pos[1]) * w + pos[1];
    pos[2] = (tp[2] - pos[2]) * w + pos[2];
  }
  if (FP(ab, 0x18)) {
    float tq[4] = {q[0], q[1], q[2], q[3]};
    ext_4def50(q, tq, (const float *)FP(ab, 0x18));
    ext_441940(pos, (const float *)((u8 *)FP(ab, 0x18) + 0x10));
  }
  s32 now = *(s32 *)((u8 *)G(void *, 0x70039c) + 0x40);
  if (F32(bb, 0x1c) != F32(ab, 0)) {
    *(s32 *)(bb + 0x20) = now;
    if (F32(bb, 0x1c) == 0) F32(bb, 0x20) = 0xfff06000;
    F32(bb, 0x1c) = F32(ab, 0);
  }
  float dt = (float)(now - *(s32 *)(bb + 0x20)) * bitsf(0x3a800000);
  float T = FF(ab, 8);
  if (T > dt) {
    float f = dt / T;
    f = f * f;
    qpul(q, (const float *)bb, q, f);
    pos[0] = (pos[0] - FF(bb, 0x10)) * f + FF(bb, 0x10);
    pos[1] = (pos[1] - FF(bb, 0x14)) * f + FF(bb, 0x14);
    pos[2] = (pos[2] - FF(bb, 0x18)) * f + FF(bb, 0x18);
  }
  F32(bb, 0) = F32(q, 0); F32(bb, 4) = F32(q, 4); F32(bb, 8) = F32(q, 8); F32(bb, 0xc) = F32(q, 0xc);
  F32(bb, 0x10) = F32(q, 0x24); F32(bb, 0x14) = F32(q, 0x28); F32(bb, 0x18) = F32(q, 0x2c);
}
PCREG(645c90, DepackBone);
