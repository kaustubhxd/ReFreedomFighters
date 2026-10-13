// batch1009.cpp - ZFFCam::ActivateCamera and ZFFCam::UpdateVars. Camera thread, 2026-10-11.
#include "cam.h"

extern "C" THISCALL void ext_4fb550(void *self, u32 ctl);  // ZBaseCamera::ActivateCamera (batch1000)
extern "C" FASTCALL void ext_4de040(float *m33, const float *dir, const float *up);  // createmat
extern "C" FASTCALL void ext_43e920(float *d, const float *a, const float *b);      // d = a - b
extern "C" FASTCALL void ext_4e0d00(float *v, float s);                             // v *= s

// 0x5c96c0 ZFFCam::ActivateCamera(CMAINCAMERACONTROL*): keep the control (+0x60), take the start matrix and position
// from the level object named "MainCamera" (geometry manager slot 0x138 -> name lookup slot 0x88), zero the
// velocity, run UpdateVars (slot 0xc8), and reset the collision state: no hit, distances 100000.
static THISCALL void ZFFCam_ActivateCamera(void *self, u32 ctl) {
  ext_4fb550(self, ctl);
  at<u32>(self, 0x60) = ctl;
  void *names = vcall<void *>(SYS9B, 0x138);
  u32 id = 0;
  vcall<void>(names, 0x88, (const char *)0x685a0c, &id);  // "MainCamera"
  void *g = vcall<void *>(SYS9B, 0x58, id);
  if (!g) return;
  u32 *pos = &at<u32>(self, 0x444);
  vcall<void>(g, 0x80, &at<float>(self, 0x36c), pos);
  at<u32>(self, 0x390) = pos[0];
  at<u32>(self, 0x394) = pos[1];
  at<u32>(self, 0x398) = pos[2];
  at<u32>(self, 0x39c) = 0;
  at<u32>(self, 0x3a0) = 0;
  at<u32>(self, 0x3a4) = 0;
  vcall<void>(self, 0xc8);
  at<u8>(self, 0x30a) = 0;
  at<u32>(self, 0x68) = 0;
  at<u32>(self, 0x2f6) = 0x47c35000;  // 100000
  for (u32 i = 0; i < 5; i++) {
    at<u8>(self, 0xd8 + i * 0x82) = 0;
    at<u32>(self, 0xd9 + i * 0x82) = 0x47c35000;
  }
}
PCREG(5c96c0, ZFFCam_ActivateCamera);

// 0x5ca5f0 ZFFCam::UpdateVars(): each frame, the focus geometry is the control's (+0x60) geometry +0x48. Its
// matrix/position go to +0x3e4/+0x408 (player), slot 0x3a0 then 0x390 fill the follow position +0x438 and
// matrix +0x414 (vtable read once for both), slot 0x84 takes the follow position to world, slot 0x88 gives the
// follow direction +0x42c, from which the follow matrix is rebuilt. Then UpdateFocusMatPos (0xb8),
// UpdateFocalPoint (0xb4), and the camera velocity (+0x39c) = (pos - last pos) / frame time (unless dt == 0).
static THISCALL void ZFFCam_UpdateVars(void *self) {
  u8 *ctl = ptr(self, 0x60);
  if (!ctl) return;
  u32 h = at<u32>(ctl, 0x48);
  at<u32>(self, 0x368) = h;
  void *g = vcall<void *>(SYS9B, 0x58, h);
  if (!g) return;
  vcall<void>(g, 0x80, &at<float>(self, 0x3e4), &at<float>(self, 0x408));
  u8 *vt = *(u8 **)g;
  float *fpos = &at<float>(self, 0x438), *fmat = &at<float>(self, 0x414);
  u32 x = (*(u32(THISCALL **)(void *, float *, float *))(vt + 0x3a0))(g, fmat, fpos);
  (*(void(THISCALL **)(void *, u32))(vt + 0x390))(g, x);
  vcall<void>(g, 0x84, fpos);
  vcall<void>(g, 0x88, &at<float>(self, 0x42c));
  ext_4de040(fmat, &at<float>(self, 0x42c), 0);
  vcall<void>(self, 0xb8);
  vcall<void>(self, 0xb4);
  float *last = &at<float>(self, 0x390);
  ext_43e920(&at<float>(self, 0x39c), &at<float>(self, 0x444), last);
  float dt = at<float>(G(u8 *, 0x70039c), 0x48);
  if (!(dt == G(float, 0x6785d0))) ext_4e0d00(&at<float>(self, 0x39c), G(float, 0x678858) / dt);
  at<u32>(self, 0x390) = at<u32>(self, 0x444);
  at<u32>(self, 0x394) = at<u32>(self, 0x448);
  at<u32>(self, 0x398) = at<u32>(self, 0x44c);
}
PCREG(5ca5f0, ZFFCam_UpdateVars);
