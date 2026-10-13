// batch47.cpp - walk tree, inline session batch 47: 0x487fc0 ZMovementBase::CheckCollision.
// Called from Move (batch 45) through vtable slot 0x48. Pushes the new position out of nearby movers, then runs the
// two collision vtable calls, the floor-material lookup and the player's slot 0x5a8.
#include "ff.h"

typedef void(THISCALL *vcallMatPos)(void *self, float *mat, float *pos);
typedef u8(THISCALL *vcallCollide6)(void *self, void *state, const float *a0, const float *a1, float *a2, float *a3, float *a4);
typedef u8(THISCALL *vcallFloor4)(void *self, float *pos, float *normal, float *a3, float *floor);
typedef u32(THISCALL *vcallArg1)(void *self, u32 arg);
typedef void(THISCALL *vcallFlag)(void *self, u32 flag);

extern "C" void THISCALL ext_4de7a0(float *m);                                       // mreset (batch 30)
extern "C" void THISCALL ext_4db7c0(u8 *geom, float *size);                          // ZBaseGeom::GetSize
extern "C" void FASTCALL ext_43e920(float *dst, const float *src, const float *a);   // PSVECSubtract (batch 34)
extern "C" void THISCALL ext_4e09b0(float *v);                                       // vneg (batch 29)
extern "C" void THISCALL ext_4e0d00(float *v, float s);                              // vscalar in place (batch 30)
extern "C" void FASTCALL ext_441940(float *dst, const float *src);                   // PSVECAdd (batch 34)

static inline double absd(double x) {
  union { double d; u32 w[2]; } u;
  u.d = x;
  u.w[1] &= 0x7fffffffu;
  return u.d;
}

// 0x487fc0, thiscall, five stack args (a0 old matrix, a1 old pos, a2 new matrix, a3 new pos, a4 velocity), ret 0x14,
// result in al (from vtable slot 0x4c).
static u8 THISCALL checkCollision(u8 *self, const float *a0, const float *a1, float *a2, float *a3, float *a4) {
  u8 *game = G(u8 *, 0x7003b8);
  for (u8 **it = (u8 **)(game + 0x40c); it != (u8 **)(game + 0x40c + *(s32 *)(game + 0x408) * 4);
       game = G(u8 *, 0x7003b8), ++it) {
    u8 *ent = *it;
    if (*(u8 **)(self + 4) == ent)
      continue;
    if ((*(u32 *)(*(u8 **)(ent + 8) + 0x3c) >> 10) & 1u)
      continue;
    float pos[3] = {0.0f, 0.0f, 0.0f};
    float mat[9];
    ext_4de7a0(mat);
    void **evt = *(void ***)ent;
    ((vcallMatPos)evt[0x80 / 4])(ent, mat, pos);
    float size[3];
    ext_4db7c0(*(u8 **)(ent + 8), size);
    float d[3];
    ext_43e920(d, pos, a3);
    if (!((double)(size[1] * 2.0f) > absd((double)d[1])))
      continue;
    d[1] = 0.0f;
    float len2 = ((d[0] * d[0]) + 0.0f) + (d[2] * d[2]);
    float len = (float)crt::sqrt((double)len2);
    if (!(size[0] > len))
      continue;
    float k = (size[0] - len) / (size[0] * 0.5f);
    ext_4e09b0(d);
    ext_4e0d00(d, k);
    ext_441940(a3, d);
  }

  void **vt = *(void ***)self;
  u8 r = ((vcallCollide6)vt[0x4c / 4])(self, *(u8 **)(self + 4) + 0x41b, a0, a1, a2, a3, a4);
  float fpos[3], fnorm[3];
  vt = *(void ***)self;
  if (((vcallFloor4)vt[0x5c / 4])(self, fpos, fnorm, a3, (float *)(*(u8 **)(self + 4) + 0x439))) {
    a3[0] = fpos[0];
    a3[1] = fpos[1];
    a3[2] = fpos[2];
    u8 *p = *(u8 **)(self + 4);
    *(float *)(p + 0x439) = fnorm[0];
    *(float *)(p + 0x43d) = fnorm[1];
    *(float *)(p + 0x441) = fnorm[2];
    *(float *)(*(u8 **)(self + 4) + 0x451) = fnorm[1];
  }

  u8 *st = *(u8 **)(self + 4) + 0x41b;
  if (*(u32 *)(st + 4) != 0 || *(u32 *)st != 0) {
    u8 *coll = *(u8 **)(G(u8 *, 0x70039c) + 0x1aa3);
    u8 *x = *(u8 **)(coll + 0x1c);
    u32 id = ((vcallArg1)(*(void ***)x)[0x74 / 4])(x, (u32)st);
    coll = *(u8 **)(G(u8 *, 0x70039c) + 0x1aa3);
    u8 *y = *(u8 **)(coll + 0x18);
    u8 *m = (u8 *)((vcallArg1)(*(void ***)y)[0xf8 / 4])(y, id);
    if (m) {
      u8 *rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
      u8 *t = (u8 *)((vcallArg1)(*(void ***)rm)[0x160 / 4])(rm, (u32)m[2]);
      if (t) {
        *(u32 *)(*(u8 **)(self + 4) + 0x14b) = *(u32 *)(t + 0x28);
        *(u32 *)(*(u8 **)(self + 4) + 0x15d) = *(u32 *)(t + 0x3c);
      }
    }
  }
  u8 *p = *(u8 **)(self + 4);
  ((vcallFlag)(*(void ***)p)[0x5a8 / 4])(p, p[0x423] != 0 ? 1u : 0u);
  return r;
}
PCREG(487fc0, checkCollision);
