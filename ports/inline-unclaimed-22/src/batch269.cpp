// batch269.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch269"): ZFFActor::ControlBreathing,
// the hero's breathing sound (tired panting after running, quiet breaths near the listener). Name from the GameCube name map
// (high); behaviour from the PC bytes.
#include "ff.h"

extern "C" float THISCALL ext_467ca0(u8 *self);                     // ZFFHERO::IsSoundCommandDone (inline-soundtimers 1605)
extern "C" void THISCALL ext_441890(u8 *snd, float t);             // sound object: set length (inline-soundtimers 1611)
extern "C" void FASTCALL ext_43e920(float *out, const float *a, const float *b); // PSVECSubtract (inline-batch45)

typedef double(THISCALL *rndf_t)(u8 *, const char *, u32);

#define RM (*(u8 **)0x70039cu)
#define DB (*(u8 **)(RM + 0x9b))
#define F(o) (*(float *)(self + (o)))

// 0x59ead0 ZFFActor::ControlBreathing() (thiscall, no args). Only with a sound system (rm+0x1a9f) and rm+0x1b5d != 1.
// Clears the "breathing now" byte +0x93f; nothing while the last breath (IsSoundCommandDone) is not exactly 0. The breath
// timer +0x941 counts down by the frame time rm+0x48; at < 0 the tiredness +0x945 moves toward the target +0x949 (up at
// 50/s, down at 2.5/s). With the listener object +0x92e within 150 vertically and |dx| + |dz| below 600 * tired + 300 the
// next breath plays: this->vt 0x6e8(in 4 / out 5 by +0x940, 0, 0) gives the sound id, db vt 0x60 the sound; volume
// (tired * 9 + 0.1, faded past 1.4 of distance) * 0.25, length (range / 100) via 0x441890, start moved back by
// (1 - tired) * 250. Timer = (1 - tired) * 3.5 (+ half the sound's length); +0x940 toggles; an in-breath adds 20%. Out of
// range the timer is rm->vt 0x1c0 (random, file/line 0xb32) * 10.
void THISCALL controlBreathing_59ead0(u8 *self) {
  if (!*(u32 *)(RM + 0x1a9f)) return;
  if (*(u32 *)(RM + 0x1b5d) == 1) return;
  self[0x93f] = 0;
  float done = ext_467ca0(self);
  if (!(done == 0.0f)) return;
  float t = F(0x941) - *(float *)(RM + 0x48);
  F(0x941) = t;
  if (!(0.0f > t)) return;
  float a = F(0x945), b = F(0x949);
  if (b > a)
    F(0x945) = (float)(__builtin_fabs((double)(b - a)) * (double)(*(float *)(RM + 0x48) * *(float *)0x680a84u) + (double)a);
  else if (a > b)
    F(0x945) = (float)((double)a - __builtin_fabs((double)(b - a)) * (double)(*(float *)(RM + 0x48) * *(float *)0x680a64u));
  float range = F(0x945) * *(float *)0x6a60acu + *(float *)0x68af1cu;
  float p1[3] = {0, 0, 0};
  vcall<void>(*(u8 **)(self + 0x92e), 0x84, (u32)p1);
  float p2[3] = {0, 0, 0};
  vcall<void>(self, 0x84, (u32)p2);
  float d[3];
  ext_43e920(d, p1, p2);
  float h = (float)(__builtin_fabs((double)d[0]) + __builtin_fabs((double)d[2]));
  if (*(double *)0x6aef70u > __builtin_fabs((double)d[1]) && range > h) {
    self[0x93f] = 1;
    u32 id = vcall<u32>(self, 0x6e8, self[0x940] ? 4u : 5u, 0u, 0u);
    u8 *snd = (u8 *)vcall<u32>(DB, 0x60, id);
    if (snd) {
      *(u32 *)(snd + 0xc) = 0;
      float v = F(0x945) * *(float *)0x68aefcu + *(float *)0x67a284u;
      if (h > *(float *)0x6ac04cu) v = v * (*(float *)0x678858u - (h - *(float *)0x6ac04cu) / range);
      *(float *)(snd + 0x88) = v * *(float *)0x67a288u;
      ext_441890(snd, range / *(float *)0x67cd40u);
      int e = *(int *)(snd + 0x64);
      int n = (int)((float)e - (*(float *)0x678858u - F(0x945)) * *(float *)0x689060u);
      *(int *)(snd + 0x64) = n;
      *(int *)(snd + 0x60) = n - e;
    }
    float x = (*(float *)0x678858u - F(0x945)) * *(float *)0x6ad9dcu;
    F(0x941) = x;
    if (snd) F(0x941) = *(float *)(snd + 0x70) * *(float *)0x67a6acu + x;
    self[0x940] = self[0x940] == 0;
    if (self[0x940]) return;
    float y = F(0x941);
    F(0x941) = y * *(float *)0x67da20u / *(float *)0x67cd40u + y;
    return;
  }
  double r = (*(rndf_t *)(*(u8 **)RM + 0x1c0))(RM, (const char *)0x6ae6a0u, 0xb32u);
  F(0x941) = (float)(r * (double)*(float *)0x680a70u);
}
PCREG(59ead0, controlBreathing_59ead0);
#undef F
#undef DB
#undef RM
