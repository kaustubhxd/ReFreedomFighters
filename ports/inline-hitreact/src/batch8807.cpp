// batch8807.cpp - hit-reaction thread, batch 8807: how the actor follows its ragdoll (CRagdoll2::CalcGroundOffset) and the two
// helpers under it (GetLocalPelvis, GetParticlePos).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])

extern "C" void THISCALL ext_545c80(void *ps, s32 i, float *out);                  // GetParticlePos (this batch)
extern "C" void THISCALL ext_641e20(void *self, float *dir, float *pelvis);        // GetLocalPelvis (this batch)
extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);     // PSVECSubtract d = a - b
extern "C" void FASTCALL ext_441940(float *d, const float *s);                     // PSVECAdd d += s
extern "C" void THISCALL ext_4e0d00(float *v, float s);                            // vscalar in place
extern "C" void FASTCALL ext_446ee0(float *d, const float *a, const float *b);     // vcross d = a x b
extern "C" void FASTCALL ext_4e09b0(float *v);                                     // vneg in place
extern "C" void FASTCALL ext_4e0d40(float *out, const float *a, float s);          // out = a * s
extern "C" void FASTCALL ext_43e960(float *v, const float *a);                     // v -= a
extern "C" u8 FASTCALL ext_4e0130(float *out, const float *from, const float *to, float maxAng);  // vangpul
extern "C" void FASTCALL ext_4de040(float *m, const float *p, const float *q);     // createmat

typedef void(THISCALL *vVP)(void *self, float *p);

// 0x545c80 ConstrainedParticleSystem::GetParticlePos(int i, float* out) (GameCube reference): out = particle i position (+0xc of the
// 0x34-byte record at [this+0xf]).
static void THISCALL getParticlePos(u8 *self, s32 i, float *out) {
  u8 *p = *(u8 **)(self + 0xf);
  u32 *s = (u32 *)(p + i * 0x34 + 0xc);
  ((u32 *)out)[0] = s[0];
  ((u32 *)out)[1] = s[1];
  ((u32 *)out)[2] = s[2];
}
PCREG(545c80, getParticlePos);

// 0x641e20 CRagdoll2::GetLocalPelvis(float* dir, float* pelvis) (GameCube reference). Particle system at +0x17f.
//  pelvis = (p8 + p9) / 2; s = p9 - p8; feet = (p14 + p15) / 2; c = s x (feet - pelvis); pelvis += (feet - pelvis) * 0.1;
//  dir = pelvis - feet with y = 0, negated when c.y < 0; l = |dir|; w = 1 (l <= 20), 1 - (l - 20) / 20 (20 < l < 40), 0 (l >= 40);
//  pelvis and dir to the link's local space (the object at +0x36, slots 0x8c / 0x90); dir += ((0, 0, 1) - dir) * w.
static void THISCALL getLocalPelvis(u8 *self, float *dir, float *pelvis) {
  float p8[3], s[3], feet[3], p15[3], fp[3], c[3];
  ext_545c80(*(void **)(self + 0x17f), 8, p8);
  ext_545c80(*(void **)(self + 0x17f), 9, pelvis);
  ext_43e920(s, pelvis, p8);
  ext_441940(pelvis, p8);
  ext_4e0d00(pelvis, 0.5f);
  ext_545c80(*(void **)(self + 0x17f), 14, p8);   // the same slot holds p14 now
  ext_545c80(*(void **)(self + 0x17f), 15, p15);
  ext_441940(p15, p8);
  ext_4e0d00(p15, 0.5f);
  for (int i = 0; i < 3; i++) feet[i] = p15[i];
  ext_43e920(fp, feet, pelvis);
  ext_446ee0(c, s, fp);
  float k = G(float, 0x67a284);
  pelvis[0] = (feet[0] - pelvis[0]) * k + pelvis[0];
  pelvis[1] = (feet[1] - pelvis[1]) * k + pelvis[1];
  pelvis[2] = (feet[2] - pelvis[2]) * k + pelvis[2];
  ext_43e920(dir, pelvis, feet);
  dir[1] = 0.0f;
  if (0.0f > c[1]) ext_4e09b0(dir);
  float q = dir[0] * dir[0];
  q = q + dir[1] * dir[1];
  q = q + dir[2] * dir[2];
  float l = (float)crt::sqrt((double)q);
  float one = G(float, 0x678858), lo = G(float, 0x67da20);
  float w = one;
  if (l > lo) {
    if (G(float, 0x684cf0) > l) w = one - (l - lo) / lo;
    else w = 0.0f;
  }
  void *lk = *(void **)(self + 0x36);
  ((vVP)VT(lk, 0x8c))(lk, pelvis);
  lk = *(void **)(self + 0x36);
  ((vVP)VT(lk, 0x90))(lk, dir);
  float z = (one - dir[2]) * w;
  float x = (0.0f - dir[0]) * w;
  float y = (0.0f - dir[1]) * w;
  dir[2] = z + dir[2];
  dir[0] = x + dir[0];
  dir[1] = y + dir[1];
}
PCREG(641e20, getLocalPelvis);

// 0x641010 CRagdoll2::CalcGroundOffset(float* mat, float* pos) (GameCube reference): the actor's matrix and position from the ragdoll.
//  GetLocalPelvis(dir, pos). t = (engine clock [0x70039c]+0x40 - start +0x2a) / 1024 s. While t < 1: dir = mat row 0 + ((0, 0, 1)
//  - mat row 0) * (1 - t) and pos -= (+0x8 offset) * (1 - t) (a one-second blend from the pose the ragdoll started in). Then the
//  heading turns from (0, 0, 1) toward dir by at most 0.349066 ([0x6c2898]) x frame time ([engine+0x48]) (vangpul) and mat =
//  createmat(that). pos is normalised (x87) unless zero, then scaled to min(frame time x 2000, its length).
static void THISCALL calcGroundOffset(u8 *self, float *mat, float *pos) {
  float dir[3], z1[3], tmp[3];
  ext_641e20(self, dir, pos);
  u8 *e = G(u8 *, 0x70039c);
  float one = G(float, 0x678858);
  z1[0] = 0.0f; z1[1] = 0.0f; z1[2] = 1.0f;
  float t = (float)(*(s32 *)(e + 0x40) - *(s32 *)(self + 0x2a)) * G(float, 0x6785e4);
  if (one > t) {
    float u = one - t;
    float vz = (one - mat[2]) * u + mat[2];
    float vx = (0.0f - mat[0]) * u + mat[0];
    dir[2] = vz;
    dir[0] = vx;
    dir[1] = (0.0f - mat[1]) * u + mat[1];
    ext_4e0d40(tmp, (float *)(self + 8), u);
    ext_43e960(pos, tmp);
    e = G(u8 *, 0x70039c);
  }
  ext_4e0130(tmp, z1, dir, *(float *)(e + 0x48) * G(float, 0x6c2898));
  ext_4de040(mat, tmp, 0);
  float len = 0.0f;
  if (!(pos[0] == 0.0f) || !(pos[1] == 0.0f) || !(pos[2] == 0.0f)) {
    long double x = pos[0], y = pos[1], zz = pos[2];
    long double L = fsqrt_x87(x * x + y * y + zz * zz);
    long double inv = 1.0L / L;
    pos[0] = (float)((long double)pos[0] * inv);
    pos[1] = (float)((long double)pos[1] * inv);
    pos[2] = (float)((long double)pos[2] * inv);
    len = (float)L;
  }
  float m = *(float *)(G(u8 *, 0x70039c) + 0x48) * G(float, 0x686098);
  m = __builtin_ia32_minss(_mm_set_ss(m), _mm_set_ss(len))[0];
  ext_4e0d00(pos, m);
}
PCREG(641010, calcGroundOffset);
