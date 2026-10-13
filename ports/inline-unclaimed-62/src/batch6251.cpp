// batch6251 - hit-reaction hand-off (ragdoll side, claim 44): 0x543810 ConstrainedParticleSystem::BlowBomb(const float *pos, float force) [thiscall,
// two stack arguments, ret 8]. If 0x67d9fc > force: return. f2 = force * 0x680a90. For each particle i < this+0x28 (element base + 0xf, stride 0x34):
// v = particle_i - pos (exe 0x43e920); m2 = x*x + y*y + z*z (summed left to right); m = max(0x67cd40, m2) (maxss operand order); s = (1.0 / m) * f2;
// v *= s (exe 0x4e0d00); velocity_i += v (exe 0x441940, FASTCALL dst = element +0x24); old position_i (element +0x18) -= v (exe 0x43e960).
#include "ff.h"

extern "C" void THISCALL ext_4e0d00(float *v, float s);                                   // vscalar in place (exe)
extern "C" void FASTCALL ext_43e920(float *dst, const float *a, const float *b);          // PSVECSubtract: dst = a - b (exe)
extern "C" void FASTCALL ext_441940(float *dst, const float *src);                        // PSVECAdd: dst += src (exe)
extern "C" void FASTCALL ext_43e960(float *dst, const float *a);                          // dst -= a (exe, x87)

static float rdf(const float *p) { float v; __builtin_memcpy(&v, p, 4); return v; }

static void THISCALL fn543810(u8 *self, const float *pos, float force) {
  if (G(float, 0x67d9fc) > force) return;
  float f2 = force * G(float, 0x680a90);
  u32 count = *(const u32 *)(self + 0x28);
  u8 *base = *(u8 **)(self + 0xf);
  u8 *esi = base + 0x24;
  for (u32 i = 0; i < count; i++, esi += 0x34) {
    float v[3];
    ext_43e920(v, (const float *)(esi - 0x18), pos);
    float x = rdf(&v[0]), y = rdf(&v[1]), z = rdf(&v[2]);
    float xx = x * x;
    float yy = y * y;
    xx = xx + yy;
    float zz = z * z;
    float m2 = xx + zz;
    float k = G(float, 0x67cd40);
    float m = (k > m2) ? k : m2;
    float t = G(float, 0x678858) / m;
    float s = t * f2;
    ext_4e0d00(v, s);
    ext_441940((float *)esi, v);
    ext_43e960((float *)(esi - 0xc), v);
  }
}
PCREG(543810, fn543810);
