// batch1005.cpp - ZFFCamera1::DoChangeDistance: eases the camera offset, distance and field of view toward their
// targets each frame, with the aim-pitch lift used in close-up. Camera thread, 2026-10-11.
#include "cam.h"

extern "C" THISCALL void ext_662330(void *ease, float *val, float dst, float time);  // EaseInEaseOut update (inferred)
extern "C" THISCALL void ext_5d0bd0(void *helper, const float *p, float speed, u32 now);  // ZCamHelper::MoveFocus

// Fields: +0x451/+0x455/+0x459 target side/up/back offset, +0x45d/+0x461/+0x465 current (eased) values,
// +0x47d wanted distance, +0x4aa maximum distance, +0x4e4/+0x511/+0x53e/+0x56b four EaseInEaseOut (0x2d bytes
// each), +0x4cb close-up focus point. Owner ZCamHelper (+0x471): +0xaed aim pitch (radians, negative = up?).
// 0x5cb7a0 ZFFCamera1::DoChangeDistance() (GC name by size 548 B and position in MoveCameraWithGeom; inferred).
static THISCALL void ZFFCamera1_DoChangeDistance(void *self) {
  u8 *helper = ptr(self, 0x471);
  u8 *hero = ptr(helper, 0x44);
  at<float>(self, 0x459) = -at<float>(self, 0x47d);
  float mx = at<float>(self, 0x4aa);
  if (at<float>(self, 0x47d) > mx) at<float>(self, 0x459) = -mx;
  if (at<u8>(hero, 0x67a)) {  // first person
    at<u32>(self, 0x451) = 0;
    at<u32>(self, 0x455) = 0xc1700000;  // -15
    at<u32>(self, 0x459) = 0xbf800000;  // -1
  }
  float dx = 0.0f, dy = 0.0f;
  float pitch = at<float>(helper, 0xaed);
  if (at<u8>(self, 0x4ca)) {
    bool alt = (at<u32>(hero, 0x417) >> 10) & 1;
    if (G(float, 0x6b4d40) > pitch) {  // below -1 degree
      dy = (alt ? G(float, 0x6b4d44) : G(float, 0x6b4d48)) * pitch;  // -5 or -10
      dx = pitch * G(float, 0x6b4d4c);                               // -12
    } else if (pitch > G(float, 0x67da04)) {                         // above +1 degree
      dx = pitch * G(float, 0x680a70);                               // 10
      dy = pitch * (alt ? G(float, 0x684cf0) : G(float, 0x67da20));  // 40 or 20
    }
  }
  ext_662330((u8 *)self + 0x4e4, &at<float>(self, 0x45d), at<float>(self, 0x451) + dx, at<float>(self, 0x4b2));
  ext_662330((u8 *)self + 0x511, &at<float>(self, 0x461), at<float>(self, 0x455) + dy, at<float>(self, 0x4b2));
  ext_662330((u8 *)self + 0x53e, &at<float>(self, 0x465), at<float>(self, 0x459), at<float>(self, 0x4b2));
  ext_662330((u8 *)self + 0x56b, &at<float>(ptr(self, 0x44), 0x5c), at<float>(self, 0x46d), at<float>(self, 0x4b2));
  at<float>(self, 0x2f6) = -at<float>(self, 0x465);
  if (at<u8>(self, 0x598)) {
    s32 t = at<s32>(self, 0x4b6);
    if (t <= at<s32>(G(u8 *, 0x70039c), 0x40)) at<u8>(self, 0x598) = 0;
    if (at<u32>(self, 0x4dc) != 5) ext_5d0bd0(ptr(self, 0x471), &at<float>(self, 0x4cb), bitsf(0x418ba058), 1);
  }
  if (at<u8>(self, 0x599)) {
    if (at<s32>(self, 0x4b6) <= at<s32>(G(u8 *, 0x70039c), 0x40)) at<u8>(self, 0x599) = 0;
  }
}
PCREG(5cb7a0, ZFFCamera1_DoChangeDistance);

extern "C" THISCALL void ext_5c9da0(void *self, float *v);                     // focus -> world (batch1001)
extern "C" THISCALL void ext_5ca460(void *self, const float *p);               // SetCamPos (batch1001)
extern "C" THISCALL void ext_5ccd10(void *self);                               // UpdateShaking (batch1004)
extern "C" THISCALL void ext_5ca4c0(void *self, const float *m, const float *p);  // SetCamMatPos (batch1001)
extern "C" THISCALL void ext_5cb410(void *self);                               // CheckCamBoxes (batch1002)
extern "C" THISCALL void ext_5cb7a0(void *self);                               // DoChangeDistance (above)
extern "C" THISCALL void ext_5cb190(void *self);                               // ChangeZoomLevel (batch1003)

// 0x5cc330 ZFFCamera1::MoveCameraWithGeom(): the per-frame camera step. The eased offset (+0x45d..) is taken
// from focus space to the world and becomes the camera position, shake is applied, the camera takes the focus
// orientation, camera boxes are tested, the wanted distance becomes min(box or close-up distance, collision
// distance +0x481), the distance/offset/FOV are eased, the zoom level updated and collisions checked (slot 0xbc).
// The collision distance is then reset to 1500 (or max distance - 8 when +0x30a is set) for the next frame.
static THISCALL void ZFFCamera1_MoveCameraWithGeom(void *self) {
  float v[3] = {at<float>(self, 0x45d), at<float>(self, 0x461), at<float>(self, 0x465)};
  ext_5c9da0(self, v);
  ext_5ca460(self, v);
  ext_5ccd10(self);
  ext_5ca4c0(self, &at<float>(self, 0x3b4), &at<float>(self, 0x444));
  ext_5cb410(self);
  float *coll = &at<float>(self, 0x481);
  float *p = at<u8>(self, 0x4ca) ? &at<float>(self, 0x485) : &at<float>(self, 0x479);
  if (*p > *coll) p = coll;
  at<u32>(self, 0x47d) = *(u32 *)p;
  ext_5cb7a0(self);
  ext_5cb190(self);
  vcall<void>(self, 0xbc);
  at<u32>(self, 0x481) = 0x44bb8000;  // 1500
  if (at<u8>(self, 0x30a)) at<float>(self, 0x481) = at<float>(self, 0x4aa) - G(float, 0x680a6c);  // - 8
}
PCREG(5cc330, ZFFCamera1_MoveCameraWithGeom);
