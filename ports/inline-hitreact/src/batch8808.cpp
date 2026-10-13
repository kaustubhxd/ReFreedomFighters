// batch8808.cpp - hit-reaction thread, batch 8808: ConstrainedParticleSystem::Move, the ragdoll integrator (taken over from area 50,
// 2026-10-12 14:27 UTC, coordinator).
#include "ff.h"

extern "C" void FASTCALL ext_443ef0(float *d, const float *a, const float *v, float s);   // vaddscalar4 d = a + v * s
extern "C" void FASTCALL ext_547a70(void *self, s32 n);                                  // ConstrainedParticleSystem::ZeroOut (not verified)
extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);           // PSVECSubtract d = a - b
extern "C" void FASTCALL ext_451890(float *d, const float *v, float s);                  // vaddscalar d += v * s
extern "C" void FASTCALL ext_4e0d40(float *out, const float *a, float s);                // vscalar3 out = a * s
extern "C" void FASTCALL ext_441940(float *d, const float *s);                           // PSVECAdd d += s
extern "C" void THISCALL ext_545950(void *self);                                         // FindFaces (not verified)
extern "C" void THISCALL ext_543a90(void *self);                                         // CheckCollision3 (not verified)
extern "C" void THISCALL ext_4e0d00(float *v, float s);                                  // vscalar in place

typedef double(VECTORCALL *libm2)(double, double);
static inline double crt_pow(double x, double y) { return (*(libm2 *)0x67634c)(x, y); }   // exe IAT, as the original calls it

// 0x546320 ConstrainedParticleSystem::Move(float dt, bool inWater, float waterLevel) , result in ST0.
// Particle records (0x34 bytes) at [this+0xf], count +0x28: +0 last position copy, +0xc position, +0x18 old position, +0x24 velocity
// (displacement per 0.02 s), +0x30 mass (10000 = fixed). Globals: time step 0.02 [0x6ec484], drag 0.01 [0x6ec488], gravity 1500 [0x6ec3cc].
//  - busy flag +0x1b: assert hook (int3 without one), return 0.
//  - +0x61 = dt; old = pos + vel * (dt / 0.02 * -1/3) for every particle.
//  - k = (float)pow(1 - drag, dt / 0.02 / 3); g = 2 * gravity * dt * dt / 3 / 3.
//  - 3 sub steps: ZeroOut(+0x59 once, then 3) (+0x59 cleared); then per particle
//      dry: d = pos - old; old = pos; unless fixed: pos += d * k, pos.y -= g;
//      in water (inWater): saved = pos; d = pos - old; at or under the water line (waterLevel >= pos.y): vel = d * 0.9, unless fixed:
//        pos += vel, f = min(1, max(0, (pos.y - waterLevel) / 25)), y = pos.y - f * g, pos.y = (float)(((float)sin(t) * 0.075 + 0.05) *
//        (double)((1 - f) * 0.5) + y) with t = clock time in s minus (pos.x + pos.z) / 50; above it: vel = d * k, unless fixed:
//        pos += vel, pos.y -= g; old = saved;
//    vel = pos - old; FindFaces; CheckCollision3; old = pos - vel, record +0 = pos.
//  - vel = (pos - old) * 3 / (dt / 0.02) for every particle; sum them.
//  - particle 0 below -10000: return 0; else return |sum| / dt.
static float THISCALL cpsMove(u8 *self, float dt, u8 inWater, float waterLevel) {
  if (self[0x1b]) {
    typedef void (*AssertHook)();
    AssertHook h = G(AssertHook, 0x7003b0);
    if (!h) __builtin_debugtrap();
    h();
    return 0.0f;
  }
  *(float *)(self + 0x61) = dt;
  u8 *base = *(u8 **)(self + 0xf);
  for (s32 i = 0; i < *(s32 *)(self + 0x28); i++) {
    u8 *p = base + i * 0x34;
    ext_443ef0((float *)(p + 0x18), (float *)(p + 0xc), (float *)(p + 0x24), dt / G(float, 0x6ec484) * G(float, 0x6a3160));
  }
  float s1 = dt / G(float, 0x6ec484);
  float three = G(float, 0x680a68);
  float drag1 = G(float, 0x678858) - G(float, 0x6ec488);
  s1 = s1 / three;
  float k = (float)crt_pow((double)drag1, (double)s1);
  float g = G(float, 0x6ec3cc) * dt;
  g = g * dt;
  g = g + g;
  g = g / three;
  g = g / three;
  double c1 = G(double, 0x6a3150), c2 = G(double, 0x6a3148);
  for (s32 sub = 3; sub != 0; sub--) {
    s32 n0 = *(s32 *)(self + 0x59);
    if (n0) {
      ext_547a70(self, n0);
      *(s32 *)(self + 0x59) = 0;
    } else {
      ext_547a70(self, 3);
    }
    if (!inWater) {
      u8 *b = *(u8 **)(self + 0xf);
      for (s32 i = 0; i < *(s32 *)(self + 0x28); i++) {
        u8 *p = b + i * 0x34;
        float d[3];
        ext_43e920(d, (float *)(p + 0xc), (float *)(p + 0x18));
        *(u32 *)(p + 0x18) = *(u32 *)(p + 0xc);
        *(u32 *)(p + 0x1c) = *(u32 *)(p + 0x10);
        *(u32 *)(p + 0x20) = *(u32 *)(p + 0x14);
        if (!(*(float *)(p + 0x30) == G(float, 0x67ff1c))) {
          ext_451890((float *)(p + 0xc), d, k);
          *(float *)(p + 0x10) = *(float *)(p + 0x10) - g;
        }
      }
    } else {
      u8 *b = *(u8 **)(self + 0xf);
      for (s32 i = 0; i < *(s32 *)(self + 0x28); i++) {
        u8 *p = b + i * 0x34;
        float sx = *(float *)(p + 0xc), sz = *(float *)(p + 0x14), sy = *(float *)(p + 0x10);
        float d[3];
        if (waterLevel >= sy) {
          ext_43e920(d, (float *)(p + 0xc), (float *)(p + 0x18));
          ext_4e0d40((float *)(p + 0x24), d, bitsf(0x3f666666));
          if (!(*(float *)(p + 0x30) == G(float, 0x67ff1c))) {
            ext_441940((float *)(p + 0xc), (float *)(p + 0x24));
            float y = *(float *)(p + 0x10);
            float t = (y - waterLevel) / G(float, 0x685270);
            t = __builtin_ia32_maxss(_mm_set_ss(0.0f), _mm_set_ss(t))[0];
            float f = __builtin_ia32_minss(_mm_set_ss(G(float, 0x678858)), _mm_set_ss(t))[0];
            float y2 = y - f * g;
            float q = (*(float *)(p + 0x14) + *(float *)(p + 0xc)) / G(float, 0x680a84);
            *(float *)(p + 0x10) = y2;
            s32 now = *(s32 *)(G(u8 *, 0x70039c) + 0x40);
            q = q * G(float, 0x67862c);
            s32 qi = _mm_cvttss_si32(_mm_set_ss(q));
            float tt = (float)(now - qi) * G(float, 0x6785e4);
            double sn = crt::sin((double)tt);
            float u = (G(float, 0x678858) - f) * G(float, 0x67a6ac);
            double r = (sn * c1 + c2) * (double)u + (double)y2;
            *(float *)(p + 0x10) = (float)r;
          }
        } else {
          ext_43e920(d, (float *)(p + 0xc), (float *)(p + 0x18));
          ext_4e0d40((float *)(p + 0x24), d, k);
          if (!(*(float *)(p + 0x30) == G(float, 0x67ff1c))) {
            ext_441940((float *)(p + 0xc), (float *)(p + 0x24));
            *(float *)(p + 0x10) = *(float *)(p + 0x10) - g;
          }
        }
        *(float *)(p + 0x18) = sx;
        *(float *)(p + 0x1c) = sy;
        *(float *)(p + 0x20) = sz;
      }
    }
    u8 *b = *(u8 **)(self + 0xf);
    for (s32 i = 0; i < *(s32 *)(self + 0x28); i++) {
      u8 *p = b + i * 0x34;
      ext_43e920((float *)(p + 0x24), (float *)(p + 0xc), (float *)(p + 0x18));
    }
    ext_545950(self);
    ext_543a90(self);
    b = *(u8 **)(self + 0xf);
    for (s32 i = 0; i < *(s32 *)(self + 0x28); i++) {
      u8 *p = b + i * 0x34;
      ext_43e920((float *)(p + 0x18), (float *)(p + 0xc), (float *)(p + 0x24));
      *(u32 *)(p + 0) = *(u32 *)(p + 0xc);
      *(u32 *)(p + 4) = *(u32 *)(p + 0x10);
      *(u32 *)(p + 8) = *(u32 *)(p + 0x14);
    }
  }
  float sum[3];
  sum[0] = 0.0f; sum[1] = 0.0f; sum[2] = 0.0f;
  u8 *b = *(u8 **)(self + 0xf);
  for (s32 i = 0; i < *(s32 *)(self + 0x28); i++) {
    u8 *p = b + i * 0x34;
    ext_43e920((float *)(p + 0x24), (float *)(p + 0xc), (float *)(p + 0x18));
    float sdt = dt / G(float, 0x6ec484);
    ext_4e0d00((float *)(p + 0x24), G(float, 0x680a68) / sdt);
    ext_441940(sum, (float *)(p + 0x24));
  }
  if (G(float, 0x6a24f8) > *(float *)(*(u8 **)(self + 0xf) + 0x10)) return 0.0f;
  float q = sum[1] * sum[1];
  q = q + sum[0] * sum[0];
  q = q + sum[2] * sum[2];
  float len = (float)crt::sqrt((double)q);
  return len / dt;
}
PCREG(546320, cpsMove);
