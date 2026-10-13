// batch56.cpp - climb tree, inline session batch 56: ZFFHeroMovementClimb Move, AnimEnd, TerminateControl and
// GotControl (vtable slots 5, 7, 2 and 4 of the climb movement).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef void(THISCALL *vcallVF)(void *self, float a);
typedef void(THISCALL *vcallVUU)(void *self, u32 a, u32 b);
typedef void(THISCALL *vcallVPPF)(void *self, void *a, void *b, float c);
typedef void(THISCALL *vcallMove)(void *self, const float *a0, const float *a1, float *a2, float *a3, float *a4);

extern "C" void FASTCALL ext_4de420(float *dst, const float *src);                    // mcpy, nine dwords (batch 29)
extern "C" void THISCALL ext_4de7a0(float *m);                                          // mreset (batch 30)
extern "C" void FASTCALL ext_4de480(float *mat, const float *m);                      // mat = mat * m (batch 48)
extern "C" void FASTCALL ext_4419f0(float *v, const float *m);                        // vmmul (batch 48)
extern "C" void FASTCALL ext_43e8e0(float *dst, const float *a, const float *b);      // dst = a + b
extern "C" void FASTCALL ext_43e920(float *dst, const float *src, const float *a);    // PSVECSubtract (batch 34)
extern "C" void THISCALL ext_595440(u8 *hero, u32 stash, u32 reason);                  // ZFFHERO::StashItem (batch 49)
extern "C" void THISCALL ext_4946a0(u8 *snd, u32 owner);                               // ZSoundBase::SetOwner

// The hero's (+4, re-read each time) slot 0x400 gets the frame time (ticks [0x70039c]+0x40 / 1024) twice; the tick count is read each time.
static void tickHeroTwice(u8 *self) {
  for (int i = 0; i < 2; ++i) {
    u8 *hero = *(u8 **)(self + 4);
    float dt = (float)*(s32 *)(G(u8 *, 0x70039c) + 0x40) * G(float, 0x6785e4);
    ((vcallVF)VT(hero, 0x400))(hero, dt);
  }
}

// 0x5e5ec0 ZFFHeroMovementClimb::Move(const float *a0, const float *a1, float *a2, float *a3, float *a4), thiscall,
// ret 0x14. With the hero (+4): r = the hero's orientation (+0x24, nine floats) times the identity; p = the hero's
// position (+0x48) through vmmul with a0; a2 = a0 times r; a3 = a1 + p; a4 = a3 - a1. Then slot 0x48 of this
// (the base Move) with the same five arguments.
static void THISCALL climbMove(u8 *self, const float *a0, const float *a1, float *a2, float *a3, float *a4) {
  u8 *hero = *(u8 **)(self + 4);
  float p[3] = {*(float *)(hero + 0x48), *(float *)(hero + 0x4c), *(float *)(hero + 0x50)};
  float m[9], r[9];
  ext_4de420(m, (const float *)(hero + 0x24));
  ext_4de7a0(r);
  ext_4de480(r, m);
  ext_4419f0(p, a0);
  ext_4de420(a2, a0);
  ext_4de480(a2, r);
  ext_43e8e0(a3, a1, p);
  ext_43e920(a4, a3, a1);
  ((vcallMove)VT(self, 0x48))(self, a0, a1, a2, a3, a4);
}
PCREG(5e5ec0, climbMove);

// 0x5e1760 ZFFHeroMovementClimb::AnimEnd(), thiscall. Clears the climbing byte +0x1d, ticks the hero twice and
// clears the owner of the sound at +8.
static void THISCALL climbAnimEnd(u8 *self) {
  self[0x1d] = 0;
  tickHeroTwice(self);
  ext_4946a0(*(u8 **)(self + 8), 0);
}
PCREG(5e1760, climbAnimEnd);

// 0x5e7190 ZFFHeroMovementClimb::TerminateControl(bool force), thiscall, ret 4, result in al. A forced stop clears
// +0x1d. The hero takes its item back out (StashItem(false, 2)). Returns true when +0x1d is clear.
static u8 THISCALL climbTerminateControl(u8 *self, u32 force) {
  if ((u8)force)
    self[0x1d] = 0;
  ext_595440(*(u8 **)(self + 4), 0, 2);
  return self[0x1d] == 0;
}
PCREG(5e7190, climbTerminateControl);

// 0x5e4900 ZFFHeroMovementClimb::GotControl(), thiscall. Hero slot 0x230(+0x3e, 0x1001), hero slot 0x238(this + 0x46,
// this + 0x6a, the float +0x42), sets +0x1d, stashes the hero's item (StashItem(true, 2)) and ticks the hero twice.
static void THISCALL climbGotControl(u8 *self) {
  u8 *hero = *(u8 **)(self + 4);
  ((vcallVUU)VT(hero, 0x230))(hero, *(u32 *)(self + 0x3e), 0x1001);
  hero = *(u8 **)(self + 4);
  ((vcallVPPF)VT(hero, 0x238))(hero, self + 0x46, self + 0x6a, *(float *)(self + 0x42));
  self[0x1d] = 1;
  ext_595440(*(u8 **)(self + 4), 1, 2);
  tickHeroTwice(self);
}
PCREG(5e4900, climbGotControl);
