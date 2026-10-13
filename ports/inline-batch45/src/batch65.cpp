// batch65.cpp - grenade flight, inline session batch 65: ZParamParticle::Init (0x4e73b0), GetPos (0x4e71b0) and the
// velocity getter (0x4e7330), and the four-argument vaddscalar (0x443ef0) they use.
#include "ff.h"

extern "C" void FASTCALL ext_4e0d40(float *dst, const float *src, float s);   // dst = src * s (batch 29)
extern "C" void THISCALL ext_4e0d00(float *v, float s);                       // v *= s (batch 29)
extern "C" void FASTCALL ext_43e920(float *dst, const float *a, const float *b);   // PSVECSubtract (batch 34)
extern "C" void FASTCALL ext_443ef0(float *dst, const float *a, const float *v, float s);
extern "C" void FASTCALL ext_451890(float *dst, const float *v, float s);    // vaddscalar (batch 63)

// The CRT's exp (_libm_sse2_exp_precise, SSE2 convention: double in xmm0, double in xmm0) through the exe's import
// slot, so the port and the exe use the same exp.
static double crtExp(double x) {
  double r;
  __asm__ volatile("movsd %1, %%xmm0\n\tcall *0x676350\n\tmovsd %%xmm0, %0"
                   : "=m"(r) : "m"(x) : "eax", "ecx", "edx", "xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6",
                     "xmm7", "memory", "cc");
  return r;
}

// 0x443ef0 vaddscalar(float *dst, const float *a, const float *v, float s), fastcall, ret 8. dst = a + v * s on three
// floats, all three before the stores; the x87 products are exact in double and each sum rounds in double first.
static void FASTCALL vaddScalar4(float *dst, const float *a, const float *v, float s) {
  double m0 = (double)v[0] * s, m1 = (double)v[1] * s, m2 = (double)v[2] * s;
  float r0 = (float)(m0 + a[0]);
  float r1 = (float)(m1 + a[1]);
  float r2 = (float)(m2 + a[2]);
  dst[0] = r0;
  dst[1] = r1;
  dst[2] = r2;
}
PCREG(443ef0, vaddScalar4);

// ZParamParticle (grenade and debris flight): +0 three floats A, +0xc the drag k, +0x10 three floats P, +0x1c three
// floats B, +0x28 the start time. Drag below 0.001 (or NaN) means plain projectile motion.

// 0x4e73b0 ZParamParticle::Init(const float *pos, const float *vel, const float *acc, float drag, float time),
// thiscall, ret 0x14. Negative drag becomes 0. With drag k: A = acc / k (the terminal velocity), B = (A - vel) / k and
// P = pos - B. Without: B = vel, P = pos, A = acc / 2.
static void THISCALL particleInit(u8 *self, const float *pos, const float *vel, const float *acc, float drag, float time) {
  float *A = (float *)self, *P = (float *)(self + 0x10), *B = (float *)(self + 0x1c);
  *(float *)(self + 0x28) = time;
  *(float *)(self + 0xc) = drag;
  if (0.0f > drag)
    *(float *)(self + 0xc) = 0.0f;
  float k = *(float *)(self + 0xc);
  if (!(k < bitsf(0x3a83126fu)) && k == k) {   // k >= 0.001
    float inv = 1.0f / k;
    ext_4e0d40(A, acc, inv);
    ext_43e920(B, A, vel);
    ext_4e0d00(B, inv);
    ext_43e920(P, pos, B);
  } else {
    B[0] = vel[0];
    B[1] = vel[1];
    B[2] = vel[2];
    P[0] = pos[0];
    P[1] = pos[1];
    P[2] = pos[2];
    ext_4e0d40(A, acc, 0.5f);
  }
}
PCREG(4e73b0, particleInit);

// 0x4e71b0 ZParamParticle::GetPos(float *out, float t) const, thiscall, ret 8. dt = t - start. With drag:
// out = P + B * exp(-k dt) + A dt. Without: out = P + B dt + A dt^2 (A is half the acceleration).
static void THISCALL particleGetPos(u8 *self, float *out, float t) {
  float dt = t - *(float *)(self + 0x28);
  float k = *(float *)(self + 0xc);
  float s;
  if (!(k < bitsf(0x3a83126fu)) && k == k) {
    float e = (float)crtExp((double)-(k * dt));
    ext_443ef0(out, (const float *)(self + 0x10), (const float *)(self + 0x1c), e);
    s = dt;
  } else {
    ext_443ef0(out, (const float *)(self + 0x10), (const float *)(self + 0x1c), dt);
    s = dt * dt;
  }
  ext_451890(out, (const float *)self, s);
}
PCREG(4e71b0, particleGetPos);

// 0x4e7330 ZParamParticle velocity at time t (out, t), thiscall, ret 8. dt = t - start. With drag:
// out = A + B * -(k exp(-k dt)). Without: out = B + A * 2 dt.
static void THISCALL particleGetVel(u8 *self, float *out, float t) {
  float k = *(float *)(self + 0xc);
  float dt = t - *(float *)(self + 0x28);
  if (!(k < bitsf(0x3a83126fu)) && k == k) {
    float e = (float)crtExp((double)-(k * dt));
    ext_443ef0(out, (const float *)self, (const float *)(self + 0x1c), -(e * *(float *)(self + 0xc)));
  } else {
    ext_443ef0(out, (const float *)(self + 0x1c), (const float *)self, dt + dt);
  }
}
PCREG(4e7330, particleGetVel);
