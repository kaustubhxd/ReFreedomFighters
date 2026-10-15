// batch908.cpp - vehicles thread, batch 908: ZHeli::UpdateDustEmitter (rotor-wash dust) and two
// ParticleEmitter leaves.
#include "ff.h"

extern "C" u8 THISCALL ext_51c470(void *heli);                     // ZHeli::FindGround (batch 907)
extern "C" void THISCALL ext_4e0d00(float *v, float k);             // vscalar: v *= k
extern "C" void FASTCALL ext_441940(float *a, const float *b);      // PSVECAdd: a += b
extern "C" void THISCALL ext_516b60(void *em, u32 a, u32 b, u32 c);  // emitter set-up (name unknown), pops 12
extern "C" void THISCALL ext_5168b0(void *em);                       // ParticleEmitter::FrameUpdate

static inline u8 *sysp() { return *(u8 **)0x70039c; }
static inline long double rnd(u32 line) {
  typedef long double(THISCALL * fn)(void *, const char *, u32);
  u8 *sy = sysp();
  return (*(fn *)(*(u8 **)sy + 0x1c0))(sy, (const char *)0x69f8b8, line);
}

// 0x516f40 ParticleEmitter::SetEmitDir(const float[3]&): the direction goes to +0x45 and, unless it is exactly
// (0,0,0), is normalised on the x87 stack (len = fsqrt(x*x + y*y + z*z), each component * (1 / len)).
static void THISCALL emitterSetEmitDir(u8 *e, const u32 *d) {
  float *v = (float *)(e + 0x45);
  ((u32 *)v)[0] = d[0];
  ((u32 *)v)[1] = d[1];
  ((u32 *)v)[2] = d[2];
  if (v[0] == 0.0f && v[1] == 0.0f && v[2] == 0.0f)
    return;
  long double x = v[0], y = v[1], z = v[2];
  long double len = fsqrt_x87((x * x + y * y) + z * z);
  long double inv = 1.0L / len;
  v[0] = (float)(v[0] * inv);
  v[1] = (float)(v[1] * inv);
  v[2] = (float)(v[2] * inv);
}
PCREG(516f40, emitterSetEmitDir);

// 0x517030 (ParticleEmitter, name unknown): 0x516b60(a, b, +0x29) on the same emitter.
static void THISCALL emitterSetup(u8 *e, u32 a, u32 b) { ext_516b60(e, a, b, *(u32 *)(e + 0x29)); }
PCREG(517030, emitterSetup);

// 0x51db60 ZHeli::UpdateDustEmitter(). Skipped when the global at 0x7003b8 has byte +0xab8 set. With 10% chance per
// frame (engine random < 0.1) and ground found below: dust strength +0x4c1 = 1 - clamp((height - 500) / 1000, 0, 1)
// and the dust particle of the ground material is chosen: material (engine +0x1aa3 -> +0x1c slot 0x74 of the hit
// info +0x562) -> +0x18 slot 0xf8 -> byte +2 -> world slot 0x160 -> its +0x44 handed to the emitter +0x4ad
// (0x517030, with the name at 0x677b5a). Then, while less than 1500 above the ground: the emitter (+0x4ad) is put at
// the ground point (+0x54e, +0x552 + 40, +0x556) plus 200 units in a random horizontal direction (angle
// rand * 2 * pi), in heli space (slot 0x8c), its position copied to +0x4da, its direction from slot 0x90
// (the heli's), and it is updated.
static void THISCALL heliUpdateDustEmitter(u8 *s) {
  if ((*(u8 **)0x7003b8)[0xab8])
    return;
  volatile float r0 = (float)rnd(0x478);
  if (0.1f > r0 && ext_51c470(s)) {
    float x = _mm_cvtss_f32(_mm_div_ss(_mm_sub_ss(_mm_load_ss((float *)(s + 0x597)), _mm_set_ss(500.0f)),
                                       _mm_set_ss(1000.0f)));
    float c = 0.0f > x ? 0.0f : _mm_cvtss_f32(_mm_min_ss(_mm_set_ss(1.0f), _mm_set_ss(x)));
    *(float *)(s + 0x4c1) = 1.0f - c;
    void *wd = *(void **)(sysp() + 0x9b);
    vcall<u32>(wd, 0x58, *(u32 *)(s + 0x56a));
    u32 m = vcall<u32>(*(void **)(*(u8 **)(sysp() + 0x1aa3) + 0x1c), 0x74, s + 0x562);
    u8 *p = vcall<u8 *>(*(void **)(*(u8 **)(sysp() + 0x1aa3) + 0x18), 0xf8, m);
    if (p) {
      u8 *q = vcall<u8 *>(*(void **)(sysp() + 0x9b), 0x160, (u32)p[2]);
      if (q)
        emitterSetup(s + 0x4ad, *(u32 *)(q + 0x44), 0x677b5a);
    }
  }
  if (*(float *)(s + 0x597) >= 1500.0f)
    return;
  float t[3], v[3], d[3];
  t[0] = *(float *)(s + 0x54e);
  t[2] = *(float *)(s + 0x556);
  t[1] = *(float *)(s + 0x552) + 40.0f;
  volatile float r = (float)rnd(0x49b);
  double a = (double)(r * 2.0f * 3.1415927410125732f);
  float co = (float)crt::cos(a);
  v[1] = 0;
  v[0] = co;
  float si = (float)crt::sin(a);
  d[1] = 0;
  d[0] = co;
  v[2] = si;
  d[2] = si;
  ext_4e0d00(v, 200.0f);
  ext_441940(t, v);
  vcall<void>(s, 0x8c, t);
  vcall<void>(s, 0x90, d);
  *(float *)(s + 0x4da) = t[0];
  *(float *)(s + 0x4de) = t[1];
  *(float *)(s + 0x4e2) = t[2];
  emitterSetEmitDir(s + 0x4ad, (u32 *)d);
  ext_5168b0(s + 0x4ad);
}
PCREG(51db60, heliUpdateDustEmitter);
