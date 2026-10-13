// batch1006.cpp - ZFFCamera1 FrameUpdate, ActivateCamera, AdjustForObstacles; ZFFCam::FrameUpdate.
// Camera thread, 2026-10-11.
#include "cam.h"

extern "C" THISCALL void ext_4a95f0(void *self);              // ZFFCam::FrameUpdate
extern "C" THISCALL void ext_5cc330(void *self);              // ZFFCamera1::MoveCameraWithGeom (batch1005)
extern "C" THISCALL void ext_5cc420(void *self);              // ZFFCamera1::MoveTestCameraWithGeom
extern "C" THISCALL void ext_4fb800(void *self);              // ZBaseCamera::CalcRoomHint (batch1002)
extern "C" THISCALL void ext_5c96c0(void *self, u32 ctl);     // ZFFCam::ActivateCamera
extern "C" THISCALL void ext_5cbe30(void *self);              // ZFFCamera1::InitTestCam
extern "C" THISCALL void ext_5cbca0(void *self);              // (unnamed) ZFFCamera1 camera-box setup, inferred InitCamboxDist
extern "C" THISCALL void ext_5d1440(void *helper);            // ZCamHelper::ResetFocus
extern "C" THISCALL void ext_5c9f10(void *self, float *out);  // ZFFCam::GetVectFromFocal (batch1001)
extern "C" THISCALL void ext_5ca490(void *self, const float *p);  // SetCamPosAndPlace (batch1001)
extern "C" THISCALL void ext_5c9e00(void *self, float *v);    // world -> focus (batch1001)
extern "C" FASTCALL void ext_43e8e0(float *d, const float *a, const float *b);  // d = a + b
extern "C" FASTCALL void ext_4e0d80(float *v, float len);     // vsetlen

// 0x4a95f0 ZFFCam::FrameUpdate(): UpdateVars (vslot 0xc8).
static THISCALL void ZFFCam_FrameUpdate(void *self) { vcall<void>(self, 0xc8); }
PCREG(4a95f0, ZFFCam_FrameUpdate);

// The focus geometry's ZCamHelper, looked up by class name once and cached at geometry +0x85a.
static inline u32 cam_helper_of(u8 *g) {
  if (at<u32>(g, 0x85a) == 0) at<u32>(g, 0x85a) = vcall<u32>(g, 0x100, (const char *)0x6a6e88);  // "ZCamHelper"
  return at<u32>(g, 0x85a);
}

// 0x5cb9f0 ZFFCamera1::FrameUpdate(): only while active (+0x5a). Base update, then either the debug test camera
// (+0x7b0) or the normal step: fetch the ZCamHelper of the focus geometry, move the camera, tell the helper the
// current distance (helper +0xb15) and pick the room hint.
static THISCALL void ZFFCamera1_FrameUpdate(void *self) {
  if (!at<u8>(self, 0x5a)) return;
  ext_4a95f0(self);
  if (at<u8>(self, 0x7b0)) {
    ext_5cc420(self);
    return;
  }
  u8 *g = vcall<u8 *>(SYS9B, 0x58, at<u32>(self, 0x368));
  if (!g) return;
  at<u32>(self, 0x471) = cam_helper_of(g);
  ext_5cc330(self);
  u8 *h = ptr(self, 0x471);
  if (h) at<u32>(h, 0xb15) = at<u32>(self, 0x2f6);
  ext_4fb800(self);
}
PCREG(5cb9f0, ZFFCamera1_FrameUpdate);

// 0x5cacf0 ZFFCamera1::ActivateCamera(CMAINCAMERACONTROL*). A pending test-camera reset (+0x4d7) only restarts the
// test camera. Otherwise: distance 500, flags cleared, helper found and its focus reset, player position (+0x408)
// = focus geometry origin in world space, a far-away last position (+0x48d = player + 1000 on each axis), minimum
// distance 5 (+0x2fa), zoom transition 0.25 s, collision distance 1500, camera boxes set up.
static THISCALL void ZFFCamera1_ActivateCamera(void *self, u32 ctl) {
  ext_5c96c0(self, ctl);
  if (at<u8>(self, 0x4d7)) {
    at<u8>(self, 0x4d7) = 0;
    ext_5cbe30(self);
    ext_5cbca0(self);
    return;
  }
  ext_5cbe30(self);
  u32 h = at<u32>(self, 0x368);
  at<u32>(self, 0x2f6) = 0x43fa0000;  // 500
  at<u8>(self, 0x30a) = 0;
  at<u32>(self, 0x68) = 0;
  at<u32>(self, 0x64) = 0xffffffff;
  u8 *g = vcall<u8 *>(SYS9B, 0x58, h);
  if (g) {
    u32 helper = cam_helper_of(g);
    at<u32>(self, 0x471) = helper;
    if (helper) ext_5d1440((void *)helper);
    float *p = &at<float>(self, 0x408);
    at<u32>(self, 0x408) = 0;
    at<u32>(self, 0x40c) = 0;
    at<u32>(self, 0x410) = 0;
    vcall<void>(g, 0x84, p);
    float far_[3] = {1000.0f, 1000.0f, 1000.0f};
    ext_43e8e0(&at<float>(self, 0x48d), p, far_);
  }
  at<u32>(self, 0x2fa) = 0x40a00000;  // 5
  at<u32>(self, 0x4b2) = 0x3e800000;  // 0.25
  at<u32>(self, 0x4d8) = 0;
  at<u32>(self, 0x481) = 0x44bb8000;  // 1500
  ext_5cbca0(self);
}
PCREG(5cacf0, ZFFCamera1_ActivateCamera);

// 0x5cae30 ZFFCamera1::AdjustForObstacles(): keeps the camera within (max distance +0x4aa - min distance +0x2fa)
// of the focal point: if further, it is pulled in along the same direction, placed, and the eased offset
// (+0x45d) is set to the new position in focus space.
static THISCALL void ZFFCamera1_AdjustForObstacles(void *self) {
  float v[3];
  ext_5c9f10(self, v);
  float lim = at<float>(self, 0x4aa) - at<float>(self, 0x2fa);
  float sq = v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
  float len = (float)crt::sqrt((double)sq);
  if (!(len > lim)) return;
  ext_4e0d80(v, lim);
  float w[3];
  ext_43e8e0(w, &at<float>(self, 0x30c), v);
  ext_5ca490(self, w);
  u32 *o = &at<u32>(self, 0x45d);
  o[0] = at<u32>(self, 0x444);
  o[1] = at<u32>(self, 0x448);
  o[2] = at<u32>(self, 0x44c);
  ext_5c9e00(self, (float *)o);
}
PCREG(5cae30, ZFFCamera1_AdjustForObstacles);
