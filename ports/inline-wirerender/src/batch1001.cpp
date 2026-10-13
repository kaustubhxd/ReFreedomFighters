// batch1001.cpp - ZFFCam small helpers: focus-space transforms, camera position setters, focal point.
// Camera thread, 2026-10-11. Unnamed functions get a descriptive name; the GameCube name is given when the map has one.
#include "cam.h"

// Engine vector/matrix helpers (all __fastcall; the original code runs).
extern "C" FASTCALL void ext_4419f0(float *v, const float *m33);              // vmmul: v = v * M (3x3)
extern "C" FASTCALL void ext_441a60(float *v, const float *m33);              // vmtmul: v = v * M^T
extern "C" FASTCALL void ext_441940(float *v, const float *a);                // PSVECAdd in place: v += a
extern "C" FASTCALL void ext_43e960(float *v, const float *a);                // v -= a
extern "C" FASTCALL void ext_43e920(float *d, const float *a, const float *b);  // d = a - b
extern "C" FASTCALL float ext_4e0870(const float *a, const float *b);         // |a - b|
extern "C" FASTCALL void ext_4de420(float *d, const float *s);                // mcpy: 3x3 matrix copy
extern "C" THISCALL void ext_4fb040(void *self);                              // ZBaseCamera::Init

static inline void *geom_of(u32 h) { return vcall<void *>(SYS9B, 0x58, h); }

// 0x5c9da0 (unnamed) focus-local -> world: v = v * focusMat(+0x3b4) + focusPos(+0x3d8).
static THISCALL void ZFFCam_FocusToWorld(void *self, float *v) {
  ext_4419f0(v, &at<float>(self, 0x3b4));
  ext_441940(v, &at<float>(self, 0x3d8));
}
PCREG(5c9da0, ZFFCam_FocusToWorld);

// 0x5c9dd0 (unnamed) pass v to the focus geometry's slot 0x84 (a world->local style transform on the geometry).
static THISCALL void ZFFCam_FocusGeomSlot84(void *self, float *v) {
  void *g = geom_of(at<u32>(self, 0x368));
  if (g) vcall<void>(g, 0x84, v);
}
PCREG(5c9dd0, ZFFCam_FocusGeomSlot84);

// 0x5c9e00 (unnamed) world -> focus-local: v = (v - focusPos) * focusMat^T.
static THISCALL void ZFFCam_WorldToFocus(void *self, float *v) {
  ext_43e960(v, &at<float>(self, 0x3d8));
  ext_441a60(v, &at<float>(self, 0x3b4));
}
PCREG(5c9e00, ZFFCam_WorldToFocus);

// 0x5c9e30 (unnamed) pass v to the focus geometry's slot 0x8c.
static THISCALL void ZFFCam_FocusGeomSlot8c(void *self, float *v) {
  void *g = geom_of(at<u32>(self, 0x368));
  if (g) vcall<void>(g, 0x8c, v);
}
PCREG(5c9e30, ZFFCam_FocusGeomSlot8c);

// 0x5c9e90 ZFFCam::GetCurDist(): the distance field +0x2f6.
static THISCALL float ZFFCam_GetCurDist(void *self) { return at<float>(self, 0x2f6); }
PCREG(5c9e90, ZFFCam_GetCurDist);

// 0x5c9ed0 ZFFCam::GetGlobalFocalPoint(float*): copies the focal point +0x30c.
static THISCALL void ZFFCam_GetGlobalFocalPoint(void *self, u32 *out) {
  out[0] = at<u32>(self, 0x30c);
  out[1] = at<u32>(self, 0x310);
  out[2] = at<u32>(self, 0x314);
}
PCREG(5c9ed0, ZFFCam_GetGlobalFocalPoint);

// 0x5c9f00 ZFFCam::GetQuality() == ZBaseCamera::GetQuality(): 0.
static THISCALL float ZFFCam_GetQuality(void *) { return 0.0f; }
PCREG(5c9f00, ZFFCam_GetQuality);

// 0x5c9f10 ZFFCam::GetVectFromFocal(float*): out = cameraPos(+0x444) - focalPoint(+0x30c).
static THISCALL void ZFFCam_GetVectFromFocal(void *self, float *out) {
  ext_43e920(out, &at<float>(self, 0x444), &at<float>(self, 0x30c));
}
PCREG(5c9f10, ZFFCam_GetVectFromFocal);

// 0x5c9f30 ZFFCam::Init(): base init, then distance 10.0 (+0x2fa), flag +0x450 off, up vector (0,1,0) at +0x3a8,
// no focus geometry (+0x368).
static THISCALL void ZFFCam_Init(void *self) {
  ext_4fb040(self);
  at<u32>(self, 0x2fa) = 0x41200000;  // 10.0f
  at<u8>(self, 0x450) = 0;
  at<u32>(self, 0x3a8) = 0;
  at<u32>(self, 0x3ac) = 0x3f800000;  // 1.0f
  at<u32>(self, 0x3b0) = 0;
  at<u32>(self, 0x368) = 0;
}
PCREG(5c9f30, ZFFCam_Init);

// 0x5ca460 (unnamed) SetCamPos(const float*): copies p to the camera position +0x444. It first computes the
// distance from the old position and throws it away (left over from a removed use).
static THISCALL void ZFFCam_SetCamPos(void *self, const u32 *p) {
  float *pos = &at<float>(self, 0x444);
  (void)ext_4e0870((const float *)p, pos);
  u32 *d = (u32 *)pos;
  d[0] = p[0];
  d[1] = p[1];
  d[2] = p[2];
}
PCREG(5ca460, ZFFCam_SetCamPos);

// 0x5ca490 (unnamed) SetCamPosAndPlace(const float*): position +0x444 = p, then the camera geometry (+0x44)
// slot 0x78 places itself there.
static THISCALL void ZFFCam_SetCamPosAndPlace(void *self, const u32 *p) {
  void *geom = ptr(self, 0x44);
  u32 *d = &at<u32>(self, 0x444);
  d[0] = p[0];
  d[1] = p[1];
  d[2] = p[2];
  vcall<void>(geom, 0x78, d);
}
PCREG(5ca490, ZFFCam_SetCamPosAndPlace);

// 0x5ca4c0 (unnamed) SetCamMatPos(const float* mat, const float* pos): matrix +0x36c = mat, position +0x444 =
// pos (with the same discarded distance as 0x5ca460), then camera geometry slot 0x7c(matrix, pos).
static THISCALL void ZFFCam_SetCamMatPos(void *self, const float *m, const u32 *p) {
  ext_4de420(&at<float>(self, 0x36c), m);
  (void)ext_4e0870((const float *)p, &at<float>(self, 0x444));
  at<u32>(self, 0x444) = p[0];
  at<u32>(self, 0x448) = p[1];
  at<u32>(self, 0x44c) = p[2];
  vcall<void>(ptr(self, 0x44), 0x7c, &at<float>(self, 0x36c), p);
}
PCREG(5ca4c0, ZFFCam_SetCamMatPos);

// 0x5ca520 ZFFCam::UpdateFocalPoint(): focal point = focus position; the focus geometry (slot 0x8c) maps it to
// local space, it is raised by 45 units (0x6b4bcc) and mapped back (slot 0x84).
static THISCALL void ZFFCam_UpdateFocalPoint(void *self) {
  float *fp = &at<float>(self, 0x30c);
  ((u32 *)fp)[0] = at<u32>(self, 0x3d8);
  ((u32 *)fp)[1] = at<u32>(self, 0x3dc);
  ((u32 *)fp)[2] = at<u32>(self, 0x3e0);
  void *g = geom_of(at<u32>(self, 0x368));
  if (g) vcall<void>(g, 0x8c, fp);
  fp[1] = fp[1] + G(float, 0x6b4bcc);
  g = geom_of(at<u32>(self, 0x368));
  if (g) vcall<void>(g, 0x84, fp);
}
PCREG(5ca520, ZFFCam_UpdateFocalPoint);
