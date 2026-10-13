// batch6250 - hit-reaction hand-off (ragdoll side, claim 43): 0x5438f0 ConstrainedParticleSystem::BlowDirBomb(const float *pos, float force, const float *dir)
// [thiscall, three stack arguments, ret 0xc]. The exe's stack-cookie check is not reproduced.
// force below 0x67d9fc (the comparison is ja: the function returns when that constant is above force). The direction is copied and
// normalised with 1/len (exe vscalar 0x4e0d00); len < 0x681370 -> BlowBomb(pos, force) (0x543810, GUESS stub by address) and return.
// Otherwise force2 = force * 0x680a90. sum = sum over particles i of 1 / (d_i + 1), with d_i = |particle_i - pos| (0x4e0870), particles at
// base + 0xc + 0x34*i for i < this+0x28. Then for each particle: vel_i (base + 0x24 + 0x34*i) += unit(dir) * (force2 / (d_i + 1) / sum) (0x451890).
// The constant 1.0 is 0x678858.
#include "ff.h"

extern "C" void THISCALL ext_4e0d00(float *v, float s);                                   // vscalar in place (exe)
extern "C" float FASTCALL ext_4e0870(const float *a, const float *b);                     // |a - b| (exe, ST0)
extern "C" void FASTCALL ext_451890(float *dst, const float *v, float s);                 // dst += v * s (exe)
extern "C" void THISCALL ext_543810(void *ps, const float *pos, float force);             // BlowBomb (GUESS stub by address)

static float rdf(const float *p) { float v; __builtin_memcpy(&v, p, 4); return v; }

static void THISCALL fn5438f0(u8 *self, const float *pos, float force, const float *dir) {
  if (G(float, 0x67d9fc) > force) return;
  float d0 = rdf(dir), d1 = rdf(dir + 1), d2 = rdf(dir + 2);
  float s = d1 * d1 + d0 * d0;
  s = s + d2 * d2;
  float len = (float)crt::sqrt((double)s);
  if (G(float, 0x681370) > len) {
    ext_543810(self, pos, force);
    return;
  }
  float unit[3] = {d0, d1, d2};
  float inv = G(float, 0x678858) / len;
  ext_4e0d00(unit, inv);
  float force2 = force * G(float, 0x680a90);
  float sum = 0.0f;
  s32 n = (s32)*(const u32 *)(self + 0x28);
  u8 *base = *(u8 **)(self + 0xf);
  for (s32 i = 0; i < n; i++) {
    u8 *p = base + 0xc + (u32)i * 0x34;
    float dist = ext_4e0870((const float *)p, pos);
    float w = G(float, 0x678858) / (dist + G(float, 0x678858));
    sum = sum + w;
  }
  for (s32 i = 0; i < n; i++) {
    u8 *p = base + 0xc + (u32)i * 0x34;
    float dist = ext_4e0870((const float *)p, pos);
    float s2 = force2 / (dist + G(float, 0x678858));
    s2 = s2 / sum;
    ext_451890((float *)(base + 0x24 + (u32)i * 0x34), unit, s2);
  }
}
PCREG(5438f0, fn5438f0);
