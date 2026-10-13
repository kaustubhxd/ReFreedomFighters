// batch1002.cpp - ZFFCamera1 sniper zoom, close-up switch, camera boxes, commands. Camera thread, 2026-10-11.
#include "cam.h"

extern "C" FASTCALL void ext_43e920(float *d, const float *a, const float *b);  // d = a - b
extern "C" FASTCALL void ext_43e8e0(float *d, const float *a, const float *b);  // d = a + b
extern "C" FASTCALL void ext_4de040(float *m33, const float *dir, const float *up);  // createmat
extern "C" THISCALL void ext_5c9f30(void *self);                                 // ZFFCam::Init
extern "C" THISCALL void ext_5cb190(void *self);                                 // ZFFCamera1::ChangeZoomLevel
extern "C" THISCALL void ext_5cc900(void *self, float *v, float a, float b);     // ZFFCamera1::ShakeCamera
extern "C" THISCALL u32 ext_4fb260(void *self, u32 cmd, void *data);             // ZBaseCamera::Command
extern "C" THISCALL void ext_4fb610(void *self);                                 // ZBaseCamera 1st-person room hint
extern "C" THISCALL void ext_4fb680(void *self);                                 // ZBaseCamera::CalcCameraRoomHint3rdPerson

static const float kFovMin = 0.06981316208839417f;  // 0x6b4d28, 4 degrees: sniper zoom limit (most zoomed)
static const float kFovMax = 0.41887903213500977f;  // 0x6b4d2c, 24 degrees: sniper zoom limit (least zoomed)
#define FOV_STEP G(float, 0x69f198)                  // 2 degrees per tap
#define FOV_RATE G(float, 0x6a0bc8)                  // 30 degrees per second while held
#define FRAME_DT G(float, G(u32, 0x70039c) + 0x48)  // ZSysInterface +0x48: frame time in seconds

// Camera fields used here: +0x44 the engine camera (ZCAMERA, field of view at +0x5c), +0x46d the sniper field of
// view the camera keeps, +0x598/+0x599 close-up zoom in/out in progress, +0x4ca close-up (sniper) mode on.

// 0x5cca60 ZFFCamera1::SniperTapZoomIn(): field of view -2 degrees, not below 4.
static THISCALL void ZFFCamera1_SniperTapZoomIn(void *self) {
  float &f = at<float>(self, 0x46d);
  if (f > kFovMin) f = f - FOV_STEP;
  if (kFovMin > f) at<u32>(self, 0x46d) = 0x3d8efa34;
}
PCREG(5cca60, ZFFCamera1_SniperTapZoomIn);

// 0x5ccaa0 ZFFCamera1::SniperTapZoomOut(): field of view +2 degrees, not above 24.
static THISCALL void ZFFCamera1_SniperTapZoomOut(void *self) {
  float &f = at<float>(self, 0x46d);
  if (kFovMax > f) f = f + FOV_STEP;
  if (f > kFovMax) at<u32>(self, 0x46d) = 0x3ed67750;
}
PCREG(5ccaa0, ZFFCamera1_SniperTapZoomOut);

// 0x5ccae0 ZFFCamera1::SniperZoomIn(): while held, narrow the engine camera's field of view at 30 deg/s down to 4,
// unless a close-up transition is running; the camera remembers the result at +0x46d.
static THISCALL void ZFFCamera1_SniperZoomIn(void *self) {
  if (at<u8>(self, 0x598)) return;
  u8 *cam = ptr(self, 0x44);
  float f = at<float>(cam, 0x5c);
  if (f > kFovMin) at<float>(cam, 0x5c) = f - FRAME_DT * FOV_RATE;
  cam = ptr(self, 0x44);
  if (kFovMin > at<float>(cam, 0x5c)) at<u32>(cam, 0x5c) = 0x3d8efa34;
  at<u32>(self, 0x46d) = at<u32>(ptr(self, 0x44), 0x5c);
}
PCREG(5ccae0, ZFFCamera1_SniperZoomIn);

// 0x5ccb40 ZFFCamera1::SniperZoomOut(): widen at 30 deg/s up to 24 (no transition check, unlike zoom in).
static THISCALL void ZFFCamera1_SniperZoomOut(void *self) {
  u8 *cam = ptr(self, 0x44);
  float f = at<float>(cam, 0x5c);
  if (kFovMax > f) at<float>(cam, 0x5c) = FRAME_DT * FOV_RATE + f;
  cam = ptr(self, 0x44);
  if (at<float>(cam, 0x5c) > kFovMax) at<u32>(cam, 0x5c) = 0x3ed67750;
  at<u32>(self, 0x46d) = at<u32>(ptr(self, 0x44), 0x5c);
}
PCREG(5ccb40, ZFFCamera1_SniperZoomOut);

// 0x5cc880 ZFFCamera1::SetCloseUp(bool): switches the close-up (sniper) view. Entering sets "zooming in" (+0x598),
// leaving sets "zooming out" (+0x599). On a change the zoom level is recomputed and the transition start time
// (+0x4b6, ms) is set to now (sys +0x40) minus the elapsed part (+0x4b2 seconds * -1024, i.e. now + 1.024*t).
static THISCALL void ZFFCamera1_SetCloseUp(void *self, u32 on) {
  u8 b = (u8)on, old = at<u8>(self, 0x4ca);
  if (b) {
    if (!old) at<u16>(self, 0x598) = 1;
  } else if (old) {
    at<u16>(self, 0x598) = 0x100;
  }
  at<u8>(self, 0x4ca) = b;
  if (b == old) return;
  ext_5cb190(self);
  s32 t = _mm_cvtt_ss2si(_mm_set_ss(at<float>(self, 0x4b2) * G(float, 0x67862c)));
  at<s32>(self, 0x4b6) = at<s32>(G(u8 *, 0x70039c), 0x40) - t;
}
PCREG(5cc880, ZFFCamera1_SetCloseUp);

// 0x5ccba0 ZFFCamera1::TestBox(unsigned): camera box `id` from the box manager (0x70038c, slot 0xcc). If the
// player position (+0x408) lies inside the box geometry (slot 0x8c to local, slot 0x184 test), the box's maximum
// distance (box +4) caps the box distance at +0x489.
static THISCALL void ZFFCamera1_TestBox(void *self, u32 id) {
  u32 *box = vcall<u32 *>(G(void *, 0x70038c), 0xcc, id);
  if (!box) return;
  void *g = vcall<void *>(SYS9B, 0x58, box[0]);
  if (!g) return;
  float p[3] = {at<float>(self, 0x408), at<float>(self, 0x40c), at<float>(self, 0x410)};
  vcall<void>(g, 0x8c, p);
  if (!vcall<bool>(g, 0x184, p)) return;
  float m[9], v[3];
  vcall<void>(g, 0x80, m, v);  // result unused
  float lim = *(float *)&box[1];
  if (at<float>(self, 0x489) > lim) at<float>(self, 0x489) = lim;
}
PCREG(5ccba0, ZFFCamera1_TestBox);

// 0x5cb410 ZFFCamera1::CheckCamBoxes(): with no box list (+0x475) the box distance (+0x479) is 500. Otherwise,
// at the start of a pass (cursor +0x59c == 0) the result of the last pass is taken (+0x479 = +0x489), the running
// minimum reset to 500 and the cursor restarted (list slot 0x4c); each frame one box (slot 0x5c) is tested.
static THISCALL void ZFFCamera1_CheckCamBoxes(void *self) {
  u8 *l = ptr(self, 0x475);
  if (!l) {
    at<u32>(self, 0x479) = 0x43fa0000;
    return;
  }
  u32 *cur = &at<u32>(self, 0x59c);
  if (*cur == 0) {
    at<u32>(self, 0x479) = at<u32>(self, 0x489);
    at<u32>(self, 0x489) = 0x43fa0000;
    vcall<void>(ptr(l, 0x18), 0x4c, cur);
  }
  u32 id = vcall<u32>(ptr(ptr(self, 0x475), 0x18), 0x5c, cur);
  ZFFCamera1_TestBox(self, id);
}
PCREG(5cb410, ZFFCamera1_CheckCamBoxes);

// 0x5cbc80 ZFFCamera1::Init(): ZFFCam::Init, then distance 500.
static THISCALL void ZFFCamera1_Init(void *self) {
  ext_5c9f30(self);
  at<u32>(self, 0x2f6) = 0x43fa0000;
}
PCREG(5cbc80, ZFFCamera1_Init);

// 0x5cb750 ZFFCamera1::Command(unsigned short, void*): the registered shake message (+0x59a) shakes the camera
// with data {float a; float v[3]; float b} (ShakeCamera(v, a, b)); anything else goes to ZBaseCamera::Command.
static THISCALL u32 ZFFCamera1_Command(void *self, u32 cmd, float *data) {
  if ((u16)cmd == at<u16>(self, 0x59a)) {
    ext_5cc900(self, data + 1, data[0], data[4]);
    return 0;
  }
  return ext_4fb260(self, cmd, data);
}
PCREG(5cb750, ZFFCamera1_Command);

// 0x5ccc80 ZFFCamera1::TestCamNextFollow(): debug test camera. With a follow list (+0x5ac entries at +0x5b0) step
// the cursor (+0x7b1) round it and follow that entry (+0x7b5); without, follow the focus geometry.
static THISCALL void ZFFCamera1_TestCamNextFollow(void *self) {
  u32 n = at<u32>(self, 0x5ac);
  if (n) {
    at<u32>(self, 0x7b1) += 4;
    if (at<u32>(self, 0x7b1) == (u32)self + (n + 0x16c) * 4) at<u32>(self, 0x7b1) = (u32)self + 0x5b0;
    at<u32>(self, 0x7b5) = *(u32 *)at<u32>(self, 0x7b1);
    return;
  }
  at<void *>(self, 0x7b5) = vcall<void *>(SYS9B, 0x58, at<u32>(self, 0x368));
}
PCREG(5ccc80, ZFFCamera1_TestCamNextFollow);

// 0x4fb800 ZBaseCamera::CalcRoomHint(): first-person cameras use the 1st-person room hint, others the 3rd-person one.
static THISCALL void ZBaseCamera_CalcRoomHint(void *self) {
  if (vcall<bool>(self, 0x88))
    ext_4fb610(self);
  else
    ext_4fb680(self);
}
PCREG(4fb800, ZBaseCamera_CalcRoomHint);

// 0x5ca140 ZFFCam::LookAtFocal() (GC name by size and shape; not in the PC map): camera matrix (+0x36c) built to
// look from the camera position (+0x444) at the focal point (+0x30c), then given to the camera geometry (slot 0x7c).
static THISCALL void ZFFCam_LookAtFocal(void *self) {
  float f[3] = {at<float>(self, 0x30c), at<float>(self, 0x310), at<float>(self, 0x314)};
  float d[3];
  float *pos = &at<float>(self, 0x444);
  ext_43e920(d, f, pos);
  ext_4de040(&at<float>(self, 0x36c), d, 0);
  vcall<void>(ptr(self, 0x44), 0x7c, &at<float>(self, 0x36c), pos);
}
PCREG(5ca140, ZFFCam_LookAtFocal);

// 0x5ca1c0 ZFFCam::ResetCamPos(): camera 500 units above the player position (+0x408), placed (slot 0x78), then
// LookAtFocal inlined.
static THISCALL void ZFFCam_ResetCamPos(void *self) {
  float up[3] = {0.0f, 500.0f, 0.0f};
  float *pos = &at<float>(self, 0x444);
  ext_43e8e0(pos, &at<float>(self, 0x408), up);
  vcall<void>(ptr(self, 0x44), 0x78, pos);
  float f[3] = {at<float>(self, 0x30c), at<float>(self, 0x310), at<float>(self, 0x314)};
  float d[3];
  ext_43e920(d, f, pos);
  ext_4de040(&at<float>(self, 0x36c), d, 0);
  vcall<void>(ptr(self, 0x44), 0x7c, &at<float>(self, 0x36c), pos);
}
PCREG(5ca1c0, ZFFCam_ResetCamPos);
