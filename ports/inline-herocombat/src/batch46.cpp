// batch46.cpp - walk tree, inline session batch 46: 0x487a80 ZMovementBase::CalcNewPosAndSpeed.
// Called from Move (batch 45) through vtable slot 0x40. Slot 0x3c, which it calls in turn, is CalcNewSpeed (batch 33)
// in the ZFFHeroMovementBaseMove vtable.
#include "ff.h"

typedef void(THISCALL *vcallSpeed4)(void *self, const float *a0, const float *a1, float *move, float *turn);

extern "C" void THISCALL ext_4e0d00(float *v, float s);                                 // vscalar in place (batch 30)
extern "C" void FASTCALL ext_4de420(float *dst, const float *src);                      // mcpy, nine dwords (batch 29)
extern "C" void FASTCALL ext_4de7e0(float *mat, const float *angles);                   // rotate matrix by three angles
extern "C" float THISCALL ext_44c840(float *v);                                         // vnorm (batch 35), ST0 result unused
extern "C" void FASTCALL ext_446ee0(float *dst, const float *a, const float *b);        // vcross (batch 35)
extern "C" void FASTCALL ext_451890(float *dst, const float *v, float s);               // dst += v * s
extern "C" void FASTCALL ext_441940(float *dst, const float *src);                      // PSVECAdd (batch 34)
extern "C" void THISCALL ext_4812a0(u8 *player, const float *pos, float *vel, float dt); // ZPlayer::AdjustMovePoolSpeed
extern "C" void FASTCALL ext_443ef0(float *dst, const float *a, const float *v, float s); // dst = a + v * s

// 0x487a80, thiscall, five stack args (a0 old matrix, a1 old pos, a2 new matrix, a3 new pos, a4 velocity), ret 0x14.
static void THISCALL calcNewPosAndSpeed(u8 *self, const float *a0, const float *a1, float *a2, float *a3, float *a4) {
  float dt = *(float *)(self + 0x18);
  if (dt == 0.0f)
    dt = *(float *)(G(u8 *, 0x70039c) + 0x48);
  dt = dt * 60.0f;
  float move[3], turn[3];
  void **vt = *(void ***)self;
  ((vcallSpeed4)vt[0x3c / 4])(self, a0, a1, move, turn);
  ext_4e0d00(turn, dt);
  ext_4de420(a2, a0);
  if (turn[0] != 0.0f || turn[1] != 0.0f || turn[2] != 0.0f) {
    ext_4de7e0(a2, turn);
    ext_44c840(a2);
    ext_446ee0(a2 + 6, a2 + 3, a2);
    ext_44c840(a2 + 6);
    ext_446ee0(a2 + 3, a2, a2 + 6);
  }
  u8 *p = *(u8 **)(self + 4);
  u8 *q = *(u8 **)(self + 8);
  if (p[0x5ff] == 0) {
    *(u32 *)(q + 0x54) = 0;
    *(u32 *)(q + 0x58) = 0;
    *(u32 *)(q + 0x5c) = 0;
  } else {
    *(u32 *)(q + 0x54) = *(u32 *)(p + 0x42d);
    *(u32 *)(q + 0x58) = *(u32 *)(p + 0x431);
    *(u32 *)(q + 0x5c) = *(u32 *)(p + 0x435);
  }
  *(u32 *)(a4 + 0) = 0;
  *(u32 *)(a4 + 2) = 0;
  ext_451890(a4, (const float *)(*(u8 **)(self + 4) + 0x42d), dt);
  ext_441940(a4, move);
  ext_4812a0(*(u8 **)(self + 4), a1, a4, dt);
  ext_443ef0(a3, a1, a4, dt);
}
PCREG(487a80, calcNewPosAndSpeed);
