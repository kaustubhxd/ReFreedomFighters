// batch1007.cpp - ZFFCamera1 camera collision: CalcCollisionParameters and CheckCollisions. Camera thread, 2026-10-11.
#include "cam.h"

extern "C" THISCALL void ext_5c9ed0(void *self, float *out);  // ZFFCam::GetGlobalFocalPoint (batch1001)
extern "C" THISCALL void ext_5c9f10(void *self, float *out);  // ZFFCam::GetVectFromFocal (batch1001)
extern "C" FASTCALL void ext_441940(float *v, const float *a);  // v += a
extern "C" FASTCALL void ext_4e0d80(float *v, float len);     // vsetlen
extern "C" FASTCALL float ext_4e0870(const float *a, const float *b);  // |a - b|
extern "C" THISCALL void *ext_5c1650(void *flag);             // CEnemyFlag::FlagPole
extern "C" THISCALL void ext_4dc630(void *geom, u32 set, u32 mask);  // ZBaseGeom::SetControl
extern "C" THISCALL void ext_5cc200(void *self);              // (unnamed) ZFFCamera1, after the rays; inferred LowerCollisionCheck

// Camera collision rays: five records of 0x82 bytes at +0x6c: start (+0), direction (+0xc), hit point (+0x28),
// fraction (+0x34), distance to hit (+0x6d). Rays 0-3 start at the focal point offset by the camera radius r
// (+0x2fa) to the four corners (r,r), (-r,-r), (-r,r), (r,-r) in the camera's own frame (camera geometry slot
// 0x88 rotates local to world); ray 4 starts at the focal point. All five point from the focal point toward the
// camera, with length r + 1500.
static const u32 RAY = 0x82;
static inline float *ray(void *self, u32 i, u32 off) { return &at<float>(self, 0x6c + i * RAY + off); }

// 0x5caf80 ZFFCamera1::CalcCollisionParameters()
static THISCALL void ZFFCamera1_CalcCollisionParameters(void *self) {
  float f[3];
  ext_5c9ed0(self, f);
  float r = at<float>(self, 0x2fa);
  float *s0 = ray(self, 0, 0), *s1 = ray(self, 1, 0), *s2 = ray(self, 2, 0), *s3 = ray(self, 3, 0);
  s0[0] = r;
  s0[1] = r;
  s0[2] = 0.0f;
  at<u32>(self, 0xf6) = 0;
  float n = -at<float>(self, 0x2fa);
  s1[0] = n;
  s1[1] = n;
  r = at<float>(self, 0x2fa);
  s2[1] = r;
  s2[2] = 0.0f;
  s2[0] = -r;
  r = at<float>(self, 0x2fa);
  s3[0] = r;
  s3[2] = 0.0f;
  s3[1] = -r;
  void *cam = ptr(self, 0x44);
  vcall<void>(cam, 0x88, s0);
  vcall<void>(ptr(self, 0x44), 0x88, s1);
  vcall<void>(ptr(self, 0x44), 0x88, s2);
  vcall<void>(ptr(self, 0x44), 0x88, s3);
  ext_441940(s0, f);
  ext_441940(s1, f);
  ext_441940(s2, f);
  ext_441940(s3, f);
  float *s4 = ray(self, 4, 0);
  s4[0] = f[0];
  s4[1] = f[1];
  s4[2] = f[2];
  float d[3];
  ext_5c9f10(self, d);
  ext_4e0d80(d, at<float>(self, 0x2fa) + G(float, 0x68af28));
  for (u32 i = 0; i < 4; i++) {
    float *dir = ray(self, i, 0xc);
    dir[0] = d[0];
    dir[1] = d[1];
    dir[2] = d[2];
  }
  float *dir4 = ray(self, 4, 0xc);
  dir4[0] = d[0];
  dir4[1] = d[1];
  dir4[2] = d[2];
}
PCREG(5caf80, ZFFCamera1_CalcCollisionParameters);

// World line test: world root (manager +0xadc) slot 0x2e0(ray, 0, 0x40, 0x200000, 1, 1) -> hit.
static inline bool ray_hits(float *r) {
  void *world = ptr(SYS9B, 0xadc);
  return vcall<bool>(world, 0x2e0, r, 0u, 0x40u, 0x200000u, 1u, 1u);
}

// 0x5cb480 ZFFCamera1::CheckCollisions(): recompute the rays (vslot 0xc0), switch off collision flag 0x40 on the
// focus (hero) geometry and, while the hero raises a flag, on the flag pole; cast the four corner rays (starting
// with the one after the last blocking ray, +0x68) and the centre ray; restore the flags. The max distance
// (+0x4aa) becomes the shortest hit distance (1500 if none), +0x64 the ray that set it, +0x30a whether any hit.
// Then the unnamed step 0x5cc200 runs and, on a hit, AdjustForObstacles (vslot 0xc4). Returns +0x30a.
static THISCALL u32 ZFFCamera1_CheckCollisions(void *self) {
  vcall<void>(self, 0xc0);
  u8 *focus = vcall<u8 *>(SYS9B, 0x58, at<u32>(self, 0x368));
  u8 *helper = ptr(self, 0x471);
  u8 *pole = 0;
  u32 poleFlag = (u32)focus, focusFlag;
  if (at<u8>(helper, 0xdd8)) {
    pole = (u8 *)ext_5c1650(ptr(helper, 0xdd9));
    if (pole) {
      poleFlag = at<u32>(ptr(pole, 8), 0x3c) & 0x40;
      ext_4dc630(ptr(pole, 8), 0, 0x40);
    } else {
      poleFlag = (u32)focus;
    }
  }
  focusFlag = at<u32>(ptr(focus, 8), 0x3c) & 0x40;
  ext_4dc630(ptr(focus, 8), 0, 0x40);
  for (int k = 0; k < 4; k++) {
    s32 i = at<s32>(self, 0x68);
    at<u32>(self, 0xa0 + i * RAY) = 0x3f800000;
    at<u32>(self, 0xd9 + at<s32>(self, 0x68) * RAY) = 0x44bb8000;
    if (ray_hits(&at<float>(self, 0x6c + at<s32>(self, 0x68) * RAY))) {
      s32 j = at<s32>(self, 0x68);
      float d = ext_4e0870(&at<float>(self, 0x94 + j * RAY), &at<float>(self, 0x6c + j * RAY));
      at<float>(self, 0xd9 + at<s32>(self, 0x68) * RAY) = d;
    }
    at<s32>(self, 0x68) = (at<s32>(self, 0x68) + 1) % 4;
  }
  at<u32>(self, 0x2a8) = 0x3f800000;
  at<u32>(self, 0x2e1) = 0x44bb8000;
  if (ray_hits(&at<float>(self, 0x274))) at<float>(self, 0x2e1) = ext_4e0870(&at<float>(self, 0x29c), &at<float>(self, 0x274));
  if (pole) ext_4dc630(ptr(pole, 8), poleFlag, 0);
  ext_4dc630(ptr(focus, 8), focusFlag, 0);
  at<u32>(self, 0x4aa) = 0x44bb8000;
  at<u8>(self, 0x30a) = 0;
  at<s32>(self, 0x64) = -1;
  if (G(float, 0x68af28) > at<float>(self, 0xd9)) {
    at<u8>(self, 0x30a) = 1;
    at<s32>(self, 0x64) = 0;
    at<u32>(self, 0x4aa) = at<u32>(self, 0xd9);
  }
  static const u32 dist_off[4] = {0x15b, 0x1dd, 0x25f, 0x2e1};
  for (int i = 0; i < 4; i++) {
    if (at<float>(self, 0x4aa) > at<float>(self, dist_off[i])) {
      at<u8>(self, 0x30a) = 1;
      at<s32>(self, 0x64) = i + 1;
      at<u32>(self, 0x4aa) = at<u32>(self, dist_off[i]);
    }
  }
  ext_5cc200(self);
  if (at<u8>(self, 0x30a)) vcall<void>(self, 0xc4);
  return at<u8>(self, 0x30a);
}
PCREG(5cb480, ZFFCamera1_CheckCollisions);
