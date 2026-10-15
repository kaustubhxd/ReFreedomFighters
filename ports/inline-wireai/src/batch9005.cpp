// batch9005.cpp - wire-ai thread (2026-10-13): ConstrainedParticleSystem::ComputeDistances 0x544e10 (name low), the rest
// lengths of the ragdoll's constraints, part of CRagdoll2::Init's tree (CRagdoll2::ComputeParticlePositions 0x6411b0 calls it on the
// bind pose).
#include "ff.h"

extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);   // d = a - b
typedef float(THISCALL *vRand544)(void *self, const char *file, u32 line);

// Particle records at [this+0xf], 0x34 bytes, position at +0xc. Constraint lists of 0xc-byte entries {i, j, length}: distances [this+0x13]
// (count +0x2c), special (minimum distance) [this+0x17] (count +0x30).
static inline float plen(u8 *recs, u32 i, u32 j) {
  float d[3];
  ext_43e920(d, (float *)(recs + 0xc + i * 0x34), (float *)(recs + 0xc + j * 0x34));
  float q = d[0] * d[0] + d[1] * d[1];
  q = q + d[2] * d[2];
  return (float)crt::sqrt((double)q);
}
static inline void spec(u8 *self, u32 k, u32 i, u32 j, float l) {
  u8 *e = *(u8 **)(self + 0x17) + 0xc * k;
  *(u32 *)e = i;
  *(u32 *)(e + 4) = j;
  *(float *)(e + 8) = l;
}

// 0x544e10 ConstrainedParticleSystem::ComputeDistances(), thiscall, plain ret. Every distance entry gets |p_i - p_j| (CRT sqrt). The 13
// special entries, from the current positions (p2 - p8 etc.; the list pointer is re-read as the exe does):
//  0 {2, 8} and 1 {3, 9}: 0.95 |p2 - p8|; 2 {5, 11} and 3 {6, 10}: 1.5 |p5 - p9|; 4 {2, 11} and 5 {3, 10}: |p2 - p6|;
//  6 {8, 14} and 7 {9, 15}: 0.1 |p8 - p14|; 8 {8, 15} and 9 {9, 14}: |p8 - p12|; 10 {2, 15}: 2.2 |p8 - p12|; 11 {3, 14}: 1.9 |p8 - p12|;
//  12: r = engine random (slot 0x1c0, particle3.cpp line 0xc49, float); 0.5 > r: {3, 15} 0.6 |p3 - p15|, else {2, 14} 0.6 |p2 - p14|.
// The special count becomes 13; when it was below 13 first "ERROR: ...SetNumSpecConstraints(..): Number of special constraints too high."
// (particle3.cpp line 0xd0a) and the assert hook (int3 without one).
static void THISCALL computeDistances(u8 *self) {
  s32 n = *(s32 *)(self + 0x2c);
  u8 *e = *(u8 **)(self + 0x13);
  for (s32 k = 0; k < n; k++, e += 0xc) {
    u8 *recs = *(u8 **)(self + 0xf);
    *(float *)(e + 8) = plen(recs, *(u32 *)e, *(u32 *)(e + 4));
  }
  float v = plen(*(u8 **)(self + 0xf), 2, 8) * bitsf(0x3f733333u);   // 0x67c1ac 0.95
  spec(self, 0, 2, 8, v);
  spec(self, 1, 3, 9, v);
  v = plen(*(u8 **)(self + 0xf), 5, 9) * bitsf(0x3fc00000u);         // 0x680a5c 1.5
  spec(self, 2, 5, 0xb, v);
  spec(self, 3, 6, 0xa, v);
  v = plen(*(u8 **)(self + 0xf), 2, 6);
  spec(self, 4, 2, 0xb, v);
  spec(self, 5, 3, 0xa, v);
  v = plen(*(u8 **)(self + 0xf), 8, 14) * bitsf(0x3dcccccdu);        // 0x67a284 0.1
  spec(self, 6, 8, 0xe, v);
  spec(self, 7, 9, 0xf, v);
  float l = plen(*(u8 **)(self + 0xf), 8, 12);
  spec(self, 8, 8, 0xf, l);
  spec(self, 9, 9, 0xe, l);
  spec(self, 10, 2, 0xf, l * bitsf(0x400ccccdu));                    // 0x6a315c 2.2
  spec(self, 11, 3, 0xe, l * bitsf(0x3ff33333u));                    // 0x6a3158 1.9
  void *sys = G(void *, 0x70039c);
  float r = ((vRand544)(*(void ***)sys)[0x1c0 / 4])(sys, (const char *)0x6a2e20u, 0xc49u);
  float m;
  if (bitsf(0x3f000000u) > r) {                                     // 0x67a6ac 0.5
    m = plen(*(u8 **)(self + 0xf), 3, 15);
    u8 *s = *(u8 **)(self + 0x17);
    *(u32 *)(s + 0x90) = 3;
    *(u32 *)(s + 0x94) = 0xf;
  } else {
    m = plen(*(u8 **)(self + 0xf), 2, 14);
    u8 *s = *(u8 **)(self + 0x17);
    *(u32 *)(s + 0x90) = 2;
    *(u32 *)(s + 0x94) = 0xe;
  }
  *(float *)(*(u8 **)(self + 0x17) + 0x98) = m * bitsf(0x3f19999au); // 0x67c1a0 0.6
  if (*(s32 *)(self + 0x30) < 0xd) {
    void *log = vcall<void *>(*(void **)0x700390, 0x20, (const char *)0x6a2e20u, 0xd0au);
    typedef void(__attribute__((cdecl)) * printf_t)(void *, const char *);
    (*(printf_t *)(*(u8 **)log + 0x2c))(log, (const char *)0x6a3058u);
    void (*h)() = *(void (**)())0x7003b0;
    if (h) h();
    else __builtin_debugtrap();
  }
  *(s32 *)(self + 0x30) = 0xd;
}
PCREG(544e10, computeDistances);
