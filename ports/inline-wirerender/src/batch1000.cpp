// batch1000.cpp - camera getters and setters (ZFFCamera1, ZFFCam, ZBaseCamera, ZCAMERA). Camera thread, 2026-10-11.
#include "cam.h"

// 0x5cbf50 ZFFCamera1::Is1stPerson(): the owner's (+0x471) +0x44 object, byte +0x67a. The original loads the
// pointer into EAX and then only AL, so the upper EAX bytes are the pointer's.
static THISCALL u32 ZFFCamera1_Is1stPerson(void *self) {
  u8 *o = ptr(ptr(self, 0x471), 0x44);
  u32 v = (u32)o;
  asm("" : "+r"(v));  // keep the pointer bits; clang otherwise folds the merge into a movzx
  return (v & ~0xffu) | at<u8>(o, 0x67a);
}
PCREG(5cbf50, ZFFCamera1_Is1stPerson);

// 0x5cbac0 ZFFCamera1::GetQuality(): the constant at 0x6b4d3c (5001.0f).
static THISCALL float ZFFCamera1_GetQuality(void *) { return G(float, 0x6b4d3c); }
PCREG(5cbac0, ZFFCamera1_GetQuality);

// 0x5cba90 ZFFCamera1::GetCurDist(): |dist at +0x465|, done in double (mask 0x67cd50), which quiets a signalling NaN.
static THISCALL float ZFFCamera1_GetCurDist(void *self) {
  __m128d d = _mm_cvtps_pd(_mm_load_ss(&at<float>(self, 0x465)));
  d = _mm_and_pd(d, *(const __m128d *)0x67cd50);
  return _mm_cvtss_f32(_mm_cvtpd_ps(d));
}
PCREG(5cba90, ZFFCamera1_GetCurDist);

// 0x5c9e60 ZFFCam::GetCameraPosition(float*): copies the camera position at +0x444.
static THISCALL void ZFFCam_GetCameraPosition(void *self, u32 *out) {
  out[0] = at<u32>(self, 0x444);
  out[1] = at<u32>(self, 0x448);
  out[2] = at<u32>(self, 0x44c);
}
PCREG(5c9e60, ZFFCam_GetCameraPosition);

// 0x5c9ea0 ZFFCam::GetFocalPos(float*) == GetFocalOffset(float*) (one PC body): copies +0x3d8.
static THISCALL void ZFFCam_GetFocalPos(void *self, u32 *out) {
  out[0] = at<u32>(self, 0x3d8);
  out[1] = at<u32>(self, 0x3dc);
  out[2] = at<u32>(self, 0x3e0);
}
PCREG(5c9ea0, ZFFCam_GetFocalPos);

// 0x5cccf0 ZFFCamera1::UpdateFocalPoint(): owner (+0x471) slot 0x88 fills the focal point at +0x30c.
static THISCALL void ZFFCamera1_UpdateFocalPoint(void *self) {
  void *o = ptr(self, 0x471);
  if (o) vcall<void>(o, 0x88, (u8 *)self + 0x30c);
}
PCREG(5cccf0, ZFFCamera1_UpdateFocalPoint);

// 0x5ca5b0 ZFFCam::UpdateFocusMatPos(): look up the focus geometry by handle +0x368, then its slot 0x2b0 writes
// the focus matrix (+0x3b4) and position (+0x3d8).
static THISCALL void ZFFCam_UpdateFocusMatPos(void *self) {
  void *g = vcall<void *>(SYS9B, 0x58, at<u32>(self, 0x368));
  if (g) vcall<void>(g, 0x2b0, (u8 *)self + 0x3b4, (u8 *)self + 0x3d8);
}
PCREG(5ca5b0, ZFFCam_UpdateFocusMatPos);

// 0x4fb550 ZBaseCamera::ActivateCamera(CMAINCAMERACONTROL*): active = 1 (+0x5a), control = arg (+0x5c).
static THISCALL void ZBaseCamera_ActivateCamera(void *self, u32 ctl) {
  at<u8>(self, 0x5a) = 1;
  at<u32>(self, 0x5c) = ctl;
}
PCREG(4fb550, ZBaseCamera_ActivateCamera);

// 0x4fb570 ZBaseCamera::DeactivateCamera(): active = 0.
static THISCALL void ZBaseCamera_DeactivateCamera(void *self) { at<u8>(self, 0x5a) = 0; }
PCREG(4fb570, ZBaseCamera_DeactivateCamera);

// 0x4fb580 ZBaseCamera::EnableCamera(bool): enabled byte +0x5b. Returns with AL = the argument.
static THISCALL u32 ZBaseCamera_EnableCamera(void *self, u32 on) {
  at<u8>(self, 0x5b) = (u8)on;
  return on;  // EAX upper bytes are not defined by the original (mov al only); ret spec compares nothing
}
PCREG(4fb580, ZBaseCamera_EnableCamera);

// 0x446d60 ZCAMERA::SetCameraRoot(unsigned): root handle at +0x1c. Leaves EAX = the argument.
static THISCALL u32 ZCAMERA_SetCameraRoot(void *self, u32 h) {
  at<u32>(self, 0x1c) = h;
  return h;
}
PCREG(446d60, ZCAMERA_SetCameraRoot);

// 0x445de0 ZCAMERA::GetCameraRoot(): geometry of handle +0x1c, or the world root (manager +0xadc) when the
// handle is 0 or does not resolve.
static THISCALL void *ZCAMERA_GetCameraRoot(void *self) {
  u32 h = at<u32>(self, 0x1c);
  if (h) {
    void *g = vcall<void *>(SYS9B, 0x58, h);
    if (g) return g;
  }
  return ptr(SYS9B, 0xadc);
}
PCREG(445de0, ZCAMERA_GetCameraRoot);

// 0x446d00 ZCAMERA::SetCameraListPrio(float): store (int)prio at +0x4c, then tell every camera list in the system
// list (+0x190f, linked by +8) that accepts this camera (slot 0xc0) the new priority (slot 0xc4).
static THISCALL void ZCAMERA_SetCameraListPrio(void *self, float prio) {
  at<s32>(self, 0x4c) = _mm_cvtt_ss2si(_mm_set_ss(prio));
  for (u8 *l = ptr(G(u8 *, 0x70039c), 0x190f); l; l = ptr(l, 8)) {
    if (vcall<bool>(l, 0xc0, self)) vcall<void>(l, 0xc4, self, prio);
  }
}
PCREG(446d00, ZCAMERA_SetCameraListPrio);
