// batch1014.cpp - ZCamHelper focus control: ResetFocus, MoveFocus, DoMoveFocus, ChangeFocus, UpdateFocusSystem.
// Camera thread, 2026-10-11.
#include "cam.h"

extern "C" FASTCALL void ext_4e09b0(float *v);  // vneg
extern "C" THISCALL void ext_5cf820(void *self, float *yaw, float *pitch, const float *dir);  // GetPolarAngles
extern "C" THISCALL void ext_5d2080(void *self);  // ZCamHelper::SetFocusSystemOni
extern "C" THISCALL void ext_5d1ea0(void *self);  // ZCamHelper::SetFocusSystemMouse (batch1012)
extern "C" THISCALL void ext_5cdb70(void *self);  // ZCamHelper::ControlBody
extern "C" THISCALL void ext_5cc560(void *cam);   // ZFFCamera1::Reset
extern "C" THISCALL void ext_5cebc0(void *self);  // (unnamed) ZCamHelper::DoChangeFocus
extern "C" FASTCALL void ext_43e920(float *d, const float *a, const float *b);  // d = a - b
extern "C" FASTCALL u32 ext_4e0130(float *out, const float *from, const float *to, float maxang);  // vangpul
extern "C" THISCALL void ext_662dd0(void *e, const float *v);  // vector ease: set start (inferred)
extern "C" THISCALL void ext_662e20(void *e, const float *v);  // vector ease: set target
extern "C" THISCALL void ext_662e70(void *e, s32 ms);          // vector ease: set time
extern "C" THISCALL void ext_662fd0(void *e, const float *m);  // matrix ease: set start
extern "C" THISCALL void ext_663060(void *e, const float *m);  // matrix ease: set target
extern "C" THISCALL void ext_6630f0(void *e, s32 ms);          // matrix ease: set time

// 0x5d1440 ZCamHelper::ResetFocus(): aim yaw/pitch from the hero's facing (-(row 0) of the hero matrix, flattened),
// angular speeds (+0xa60/+0xa64, +0xaf1/+0xaf5) zeroed, focus frame rebuilt (pad version), body control (unless
// scheme 1) and the camera reset.
static THISCALL void ZCamHelper_ResetFocus(void *self) {
  float m[9], pos[3];
  vcall<void>(ptr(self, 0x44), 0x80, m, pos);
  float d[3] = {m[0], m[1], m[2]};
  ext_4e09b0(d);
  d[1] = 0.0f;
  float *yaw = &at<float>(self, 0xae9), *pitch = &at<float>(self, 0xaed);
  ext_5cf820(self, yaw, pitch, d);
  at<float>(self, 0xa54) = *yaw;
  at<u32>(self, 0xa5c) = *(u32 *)pitch;
  at<u32>(self, 0xa60) = 0;
  at<u32>(self, 0xa64) = 0;
  at<u32>(self, 0xaf1) = 0;
  at<u32>(self, 0xaf5) = 0;
  ext_5d2080(self);
  if (at<u32>(self, 0xa4c) != 1) ext_5cdb70(self);
  ext_5cc560(ptr(self, 0xb54));
}
PCREG(5d1440, ZCamHelper_ResetFocus);

// 0x5d0bd0 ZCamHelper::MoveFocus(const float* p, float speed, bool fromCamera): start turning the aim toward p at
// `speed` rad/s (+0xab6 active, +0xab2 speed, +0xab7 start time, +0xabb from-camera, +0xabc target).
static THISCALL void ZCamHelper_MoveFocus(void *self, const u32 *p, float speed, u32 fromCam) {
  at<u8>(self, 0xabb) = (u8)fromCam;
  at<u8>(self, 0xab6) = 1;
  at<float>(self, 0xab2) = speed;
  u32 *t = &at<u32>(self, 0xab7), *now = (u32 *)(G(u8 *, 0x70039c) + 0x40);
  if (t != now) *t = *now;
  at<u32>(self, 0xabc) = p[0];
  at<u32>(self, 0xac0) = p[1];
  at<u32>(self, 0xac4) = p[2];
}
PCREG(5d0bd0, ZCamHelper_MoveFocus);

// 0x5cecd0 ZCamHelper::DoMoveFocus(): while active, pull the focus facing (row 0 of +0xc89) toward the target
// direction (from the camera position or the focus point) by speed*dt, and take yaw/pitch from it. Stops when
// reached, when the pitch hits -70 or +60 degrees, or (pad schemes, after 204 ms) when the stick moves.
static THISCALL void ZCamHelper_DoMoveFocus(void *self) {
  if (!at<u8>(self, 0xab6)) return;
  float c[3];
  if (at<u8>(self, 0xabb)) {
    vcall<void>(ptr(self, 0xb54), 0x94, c);
  } else {
    c[0] = at<float>(self, 0xc71);
    c[1] = at<float>(self, 0xc75);
    c[2] = at<float>(self, 0xc79);
  }
  float d[3];
  ext_43e920(d, &at<float>(self, 0xabc), c);
  if (!(d[0] == 0.0f && d[1] == 0.0f && d[2] == 0.0f)) {  // x87 normalize (extended precision)
    long double s = (long double)d[0] * d[0];
    s = s + (long double)d[1] * d[1];
    s = s + (long double)d[2] * d[2];
    long double inv = 1.0L / fsqrt_x87(s);
    d[0] = (float)(d[0] * inv);
    d[1] = (float)(d[1] * inv);
    d[2] = (float)(d[2] * inv);
  }
  float r[3];
  u32 done = ext_4e0130(r, &at<float>(self, 0xc89), d, at<float>(self, 0xab2) * at<float>(G(u8 *, 0x70039c), 0x48));
  float *yaw = &at<float>(self, 0xae9), *pitch = &at<float>(self, 0xaed);
  ext_5cf820(self, yaw, pitch, r);
  at<float>(self, 0xa54) = *yaw;
  float p = *pitch;
  at<float>(self, 0xa5c) = p;
  if (G(float, 0x6b4fec) >= p) at<u8>(self, 0xab6) = 0;  // comiss/jb: a NaN pitch keeps going
  if (p >= G(float, 0x6b4fb4)) at<u8>(self, 0xab6) = 0;
  if (at<u32>(self, 0xa4c) != 1 && (s32)(at<u32>(self, 0xab7) + 0xcc) < at<s32>(G(u8 *, 0x70039c), 0x40)) {
    if (!(at<float>(self, 0xb1f) == 0.0f && at<float>(self, 0xb23) == 0.0f && at<float>(self, 0xb2b) == 0.0f &&
          at<float>(self, 0xb27) == 0.0f))
      at<u8>(self, 0xab6) = 0;
  }
  if ((u8)done) at<u8>(self, 0xab6) = 0;
}
PCREG(5cecd0, ZCamHelper_DoMoveFocus);

// 0x5cd7f0 ZCamHelper::ChangeFocus(float* pos, float* mat, float time, int mode): ease the focus position (+0xd36)
// and matrix (+0xd87) from their current values to pos/mat over time*1024 ms; +0xd35 = changing.
static THISCALL void ZCamHelper_ChangeFocus(void *self, float *pos, float *mat, float t, u32 mode) {
  void *e1 = (u8 *)self + 0xd36;
  ext_662dd0(e1, &at<float>(self, 0xc71));
  ext_662e20(e1, pos);
  s32 ms = _mm_cvtt_ss2si(_mm_set_ss(t * G(float, 0x678620)));
  ext_662e70(e1, ms);
  void *e2 = (u8 *)self + 0xd87;
  at<u32>(self, 0xd7f) = mode;
  ext_662fd0(e2, &at<float>(self, 0xc89));
  ext_663060(e2, mat);
  ext_6630f0(e2, ms);
  at<u32>(self, 0xdd0) = mode;
  at<u8>(self, 0xd35) = 1;
}
PCREG(5cd7f0, ZCamHelper_ChangeFocus);

// 0x5d2e60 ZCamHelper::UpdateFocusSystem(): during a focus change run it; otherwise (unless raising a flag)
// rebuild the focus frame for the input scheme +0xe1c: 3 = mouse, 0..2 = pad.
static THISCALL void ZCamHelper_UpdateFocusSystem(void *self) {
  if (at<u8>(self, 0xd35)) {
    ext_5cebc0(self);
    return;
  }
  if (at<u8>(self, 0xdd8)) return;
  switch (at<u32>(self, 0xe1c)) {
    case 0: case 1: case 2: ext_5d2080(self); break;
    case 3: ext_5d1ea0(self); break;
  }
}
PCREG(5d2e60, ZCamHelper_UpdateFocusSystem);
