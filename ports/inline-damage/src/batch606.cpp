// batch606.cpp - damage thread, batch 606: ZFFHERO::Die.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])

extern "C" void THISCALL ext_4830e0(void *self, const float *pos, const float *dir, float force);  // ZPlayer::Die

typedef void (THISCALL *v0)(void *self);
typedef void (THISCALL *vU)(void *self, u32 a);

// 0x5910d0 ZFFHERO::Die(const float[2]& pos, const float[2]& dir, float force) (GC 80082fc0).
// Once only: +0x417 bit 0x40000 is the "dead" flag. ZPlayer::Die first; then the hit position (+0x9fa) and direction
// (+0xa06) are kept with impulse min(force, 250) * 0.02 (+0xa12) for the death ragdoll (inferred use), +0x827 = 1,
// then own slots 0x3dc(), 0x220(0), 0x368().
static void THISCALL heroDie(u8 *self, const float *pos, const float *dir, float force) {
  if (*(u32 *)(self + 0x417) & 0x40000) return;
  ext_4830e0(self, pos, dir, force);
  float f = __builtin_ia32_minss(_mm_set_ss(force), _mm_set_ss(250.0f))[0];  // minss with 0x689060
  *(u32 *)(self + 0x9fa) = *(const u32 *)pos;
  *(u32 *)(self + 0x9fe) = *(const u32 *)(pos + 1);
  *(u32 *)(self + 0xa02) = *(const u32 *)(pos + 2);
  *(u32 *)(self + 0xa06) = *(const u32 *)dir;
  *(u32 *)(self + 0xa0a) = *(const u32 *)(dir + 1);
  *(u32 *)(self + 0xa0e) = *(const u32 *)(dir + 2);
  *(u32 *)(self + 0x417) |= 0x40000;
  *(float *)(self + 0xa12) = f * 0.02f;
  self[0x827] = 1;
  ((v0)VT(self, 0x3dc))(self);
  ((vU)VT(self, 0x220))(self, 0);
  ((v0)VT(self, 0x368))(self);
}
PCREG(5910d0, heroDie);

// 0x4830e0 ZPlayer::Die(const float[2]&, const float[2]&, float) (GC 80152214): own slot 0x3dc(), then the object at
// +0x455 gets its slot 8 called with 1. The arguments are not used.
static void THISCALL playerDie(u8 *self, const float *, const float *, float) {
  ((v0)VT(self, 0x3dc))(self);
  u8 *o = *(u8 **)(self + 0x455);
  ((vU)VT(o, 8))(o, 1);
}
PCREG(4830e0, playerDie);
