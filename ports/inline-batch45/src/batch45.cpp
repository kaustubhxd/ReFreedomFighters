// batch45.cpp - walk root, inline session batch 45: 0x5e5c00 ZFFHeroMovementBaseMove::Move.
#include "ff.h"

typedef void(THISCALL *vcallMove5)(void *self, const float *a0, const float *a1, float *a2, float *a3, float *a4);
typedef double(THISCALL *vcallStampF)(void *self, const char *file, u32 line);  // result read from ST0
typedef void(THISCALL *vcallFootDust)(void *self, float scale);

extern "C" void FASTCALL ext_441940(float *dst, const float *src);                // PSVECAdd (batch 34)
extern "C" void THISCALL ext_4e0d00(float *v, float s);                          // vscalar in place (batch 30)
extern "C" u8 *THISCALL ext_5e3dd0(u8 *self, u32 status);                        // GetAnimFromStatus (batch 32)
extern "C" void FASTCALL ext_4de040(float *out, const float *p, const float *q);  // createmat (batch 36)
extern "C" void FASTCALL ext_43e920(float *dst, const float *src, const float *a); // PSVECSubtract (batch 34)
extern "C" double THISCALL ext_488460(u8 *self);                                 // ZMovementBase::DeltaTime (batch 35), ST0

// 0x5e5c00, thiscall, five stack args (a0, a1, a2, a3, a4), ret 0x14.
// 1. this+0x21 = 0. Two virtual calls on this with (a0..a4): slot 0x40 (ZMovementBase::CalcNewPosAndSpeed) and slot 0x48
//    (ZMovementBase::CheckCollision). The vtable is reloaded before each call, as the exe does.
// 2. The velocity at this+0x53f gets a4 added, then is scaled by 0.125. s = |velocity| * 60 * 8 (float ops; the length is
//    the CRT sqrt of the float sum of squares).
// 3. Status fl = [player+0x417], player = [this+0x36d]: if 10 > s the two low bits are cleared; otherwise, when s is below
//    200 (bit 0x400 set) or 400 (clear), bit 2 is clear and either low bit is set, fl becomes (fl & ~2) | 1. Then
//    this+0x21 = GetAnimFromStatus(fl).
// 4. createmat(a2, (a2[0], 0, a2[2]), null): a2 becomes the heading frame.
// 5. Unless the player's bits 0xc000000 are clear and the byte at [0x7003b8]+0xab8 is set, the distance |a1 - a3| is added
//    to the accumulator at this+0x53b. The threshold is 150; with bits 0xc000000 it is 50, and if 10 > s a jitter
//    (r + 1) * DeltaTime * 50 is added too, r being slot 0x1c0 of the system object at 0x70039c called with
//    ("..\\..\\freedomfighter\\FFBackground\\ZFFHeroMovement.cpp", 412). The x87 chain is done in double under FPCW 0x27f.
// 6. When the accumulator passes the threshold, the player's slot 0x400 (EmitFootDustParticle) is called with
//    (float)[sys+0x40] / 1024, and the threshold is subtracted.
// The stack-cookie epilogue (0x633654) is the CRT's own check and is not part of the port.
static void THISCALL heroMove(u8 *self, const float *a0, const float *a1, float *a2, float *a3, float *a4) {
  *(u32 *)(self + 0x21) = 0;
  void **vt = *(void ***)self;
  ((vcallMove5)vt[0x40 / 4])(self, a0, a1, a2, a3, a4);
  vt = *(void ***)self;
  ((vcallMove5)vt[0x48 / 4])(self, a0, a1, a2, a3, a4);

  float *vel = (float *)(self + 0x53f);
  ext_441940(vel, a4);
  ext_4e0d00(vel, 0.125f);
  float vx = vel[0], vy = vel[1], vz = vel[2];
  float len2 = ((vx * vx) + (vy * vy)) + (vz * vz);
  float len = (float)crt::sqrt((double)len2);
  u8 *player = *(u8 **)(self + 0x36d);
  u32 fl = *(u32 *)(player + 0x417);
  float s = (len * 60.0f) * 8.0f;
  if (10.0f > s) {
    fl &= 0xfffffffcu;
  } else {
    float thr = (fl & 0x400u) ? 200.0f : 400.0f;
    if (thr > s && (fl & 4u) == 0 && (fl & 3u) != 0)
      fl = (fl & 0xfffffffdu) | 1u;
  }
  *(u8 **)(self + 0x21) = ext_5e3dd0(self, fl);

  float head[3];
  head[0] = a2[0];
  head[1] = 0.0f;
  head[2] = a2[2];
  ext_4de040(a2, head, 0);

  player = *(u8 **)(self + 0x36d);
  if ((*(u32 *)(player + 0x417) & 0xc000000u) == 0) {
    u8 *game = G(u8 *, 0x7003b8);
    if (game[0xab8] != 0)
      return;
  }
  float w[3];
  ext_43e920(w, a1, a3);
  float d2 = ((w[0] * w[0]) + (w[1] * w[1])) + (w[2] * w[2]);
  float d = (float)crt::sqrt((double)d2);
  player = *(u8 **)(self + 0x36d);
  float *acc = (float *)(self + 0x53b);
  *acc = d + *acc;
  float thresh = 150.0f;
  if (*(u32 *)(player + 0x417) & 0xc000000u) {
    thresh = 50.0f;
    if (10.0f > s) {
      u8 *sys = G(u8 *, 0x70039c);
      void **svt = *(void ***)sys;
      double r = ((vcallStampF)svt[0x1c0 / 4])(sys, (const char *)0x6b7a5cu, 0x19cu);
      float rp1 = (float)(r + 1.0);
      double t = ext_488460(self) * 50.0;
      t = t * (double)rp1;
      float jitter = (float)t;
      *acc = jitter + *acc;
    }
  }
  if (*acc > thresh) {
    u8 *sys = G(u8 *, 0x70039c);
    player = *(u8 **)(self + 0x36d);
    float scale = (float)*(s32 *)(sys + 0x40) * 0.0009765625f;
    void **pvt = *(void ***)player;
    ((vcallFootDust)pvt[0x400 / 4])(player, scale);
    *acc = *acc - thresh;
  }
}
PCREG(5e5c00, heroMove);
