// batch928.cpp - vehicles thread, batch 928: CUnderCarriageCar per-frame sub-steps (ground probe, weight
// transfer, anchors, reversed dampers, wheels and steering, dust, exhaust).
#include "ff.h"

extern "C" void THISCALL ext_5165d0(void *d, float a, u32 probe, float y, const void *box);  // damper ground (920)
extern "C" void THISCALL ext_516620(void *d, const float *p);                               // damper set x/z (921)
extern "C" void THISCALL ext_5162e0(void *d, const float *p);                               // damper reset at (920)
extern "C" void FASTCALL ext_4419f0(float *v, const float *m);                             // vmmul
extern "C" void FASTCALL ext_441940(float *a, const float *b);                             // PSVECAdd
extern "C" void THISCALL ext_529e30(void *w, float tspd, float spd);                       // CWheel::Revolve (921)
extern "C" void FASTCALL ext_4ddcb0(float *m, const float *axis, float a);                 // LoadRotationAxisAngle
extern "C" void THISCALL ext_4dcb90(void *geom, const float *m);                           // ZBaseGeom::SetMatSimple
extern "C" u32 THISCALL ext_516250(void *d);                                               // damper ground dust (922)
extern "C" void THISCALL ext_52a070(void *w, void *def);                                   // CWheel set dust (922)
extern "C" void THISCALL ext_516f40(void *em, const float *d);                             // SetEmitDir (908)
extern "C" void THISCALL ext_5168b0(void *em);                                             // ParticleEmitter::FrameUpdate

static const u32 ABS64[4] __attribute__((aligned(16))) = {0xffffffff, 0x7fffffff, 0xffffffff, 0x7fffffff};
static inline float sadd(float a, float b) { asm("addss %1, %0" : "+x"(a) : "x"(b)); return a; }
static inline float ssub(float a, float b) { asm("subss %1, %0" : "+x"(a) : "x"(b)); return a; }
static inline float smul(float a, float b) { asm("mulss %1, %0" : "+x"(a) : "x"(b)); return a; }
static inline float sdiv(float a, float b) { asm("divss %1, %0" : "+x"(a) : "x"(b)); return a; }
static inline float absd(float v) {
  return _mm_cvtss_f32(_mm_cvtpd_ps(_mm_and_pd(_mm_cvtps_pd(_mm_set_ss(v)), _mm_load_pd((const double *)ABS64))));
}
static inline float absdiv(float v, float d) {
  __m128d x = _mm_and_pd(_mm_cvtps_pd(_mm_set_ss(v)), _mm_load_pd((const double *)ABS64));
  return _mm_cvtss_f32(_mm_cvtpd_ps(_mm_div_sd(x, _mm_cvtps_pd(_mm_set_ss(d)))));
}
static inline float mn(float a, float b) { return _mm_cvtss_f32(_mm_min_ss(_mm_set_ss(a), _mm_set_ss(b))); }
#define F(p, o) (*(float *)((u8 *)(p) + (o)))
static inline u8 *sysp() { return *(u8 **)0x70039c; }

// 0x526ac0 (CUnderCarriageCar, unnamed: weight transfer): while moving (speed +0x68 > 2^-13) damper mass = 1 +
// min(20, |acceleration +0x6c| / +0x94) on the axle it pitches toward (front when acc * sign +0x7c < 0, rear when
// > 0); the turn (|+0x74| / +0x98, clamped to [0, 3]) adds to one wheel of every pair.
static void THISCALL ucCarWeight(u8 *s) {
  float a1 = 0, a2 = 0;
  if (F(s, 0x68) > 0.0001220703125f) {
    float v = F(s, 0x6c);
    float t = smul(F(s, 0x7c), v);
    if (0.0f > t)
      a1 = absdiv(v, F(s, 0x94));
    else if (t > 0.0f)
      a2 = absdiv(v, F(s, 0x94));
  }
  float r = mn(20.0f, a2), f = mn(20.0f, a1);
  if (*(s32 *)(s + 0x8c) > 0) {
    float m = sadd(f, 1.0f);
    for (s32 i = 0; i < *(s32 *)(s + 0x8c); i++)
      F(s, 0xc9 + i * 0xde) = m;
  }
  if (*(s32 *)(s + 0x90) > 0) {
    float m = sadd(r, 1.0f);
    for (s32 i = 0; i < *(s32 *)(s + 0x90); i++)
      F(s, 0x441 + i * 0xde) = m;
  }
  float w = F(s, 0x74);
  s32 side = 0.0f >= smul(w, F(s, 0x7c)) ? 1 : 0;
  float x = absdiv(w, F(s, 0x98));
  float x2 = 0.0f > x ? 0.0f : mn(3.0f, x);
  for (s32 i = 0; i < *(s32 *)(s + 0x8c); i += 2)
    F(s, 0xc9 + side * 0xde + (i / 2) * 0x1bc) = sadd(F(s, 0xc9 + side * 0xde + (i / 2) * 0x1bc), x2);
  for (s32 i = 0; i < *(s32 *)(s + 0x90); i += 2)
    F(s, 0x441 + side * 0xde + (i / 2) * 0x1bc) = sadd(F(s, 0x441 + side * 0xde + (i / 2) * 0x1bc), x2);
}
PCREG(526ac0, ucCarWeight);

