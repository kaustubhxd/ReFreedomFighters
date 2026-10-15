// batch1018.cpp - ZFFCamera1 setup: Reset, Init2, Load2, InitTestCam, MoveTestCameraWithGeom. Camera thread, 2026-10-11.
#include "cam.h"

extern "C" THISCALL void ext_5c9da0(void *self, float *v);                      // focus -> world (batch1001)
extern "C" THISCALL void ext_5ca4c0(void *self, const float *m, const float *p);  // SetCamMatPos (batch1001)
extern "C" THISCALL void ext_5ca460(void *self, const float *p);                // SetCamPos (batch1001)
extern "C" THISCALL void ext_5ccd10(void *self);                                // UpdateShaking (batch1004)
extern "C" THISCALL void ext_5ca140(void *self);                                // LookAtFocal (batch1002)
extern "C" THISCALL void ext_4690b0(void *self);                                // empty function (guard_check_icall)
extern "C" FASTCALL void ext_4de420(float *d, const float *s);                  // mcpy

static inline u32 cam_helper_of(u8 *g) {
  if (at<u32>(g, 0x85a) == 0) at<u32>(g, 0x85a) = vcall<u32>(g, 0x100, (const char *)0x6a6e88);  // "ZCamHelper"
  return at<u32>(g, 0x85a);
}
static inline void *world_list(const char *name) { return vcall<void *>(ptr(SYS9B, 0xadc), 0x25c, name, 0u); }

// 0x5cc560 ZFFCamera1::Reset(): focus matrix/position and focal point updated (vslots 0xb8, 0xb4), offsets set to
// (0, 0, -500) both eased and target, camera placed there in focus space, collisions checked (vslot 0xbc).
static THISCALL void ZFFCamera1_Reset(void *self) {
  vcall<void>(self, 0xb8);
  vcall<void>(self, 0xb4);
  at<u32>(self, 0x45d) = 0;
  at<u32>(self, 0x461) = 0;
  at<u32>(self, 0x465) = 0xc3fa0000;  // -500
  at<u32>(self, 0x451) = 0;
  at<u32>(self, 0x455) = 0;
  at<u32>(self, 0x459) = 0xc3fa0000;
  float v[3] = {at<float>(self, 0x45d), at<float>(self, 0x461), at<float>(self, 0x465)};
  ext_5c9da0(self, v);
  ext_5ca4c0(self, &at<float>(self, 0x3b4), v);
  vcall<void>(self, 0xbc);
}
PCREG(5cc560, ZFFCamera1_Reset);

// 0x5cbad0 ZFFCamera1::Init2(): find the level's "CameraBoxList" (+0x475) and enable every box's geometry
// (slot 0xbc(1)), start the box pass, find the ZCamHelper, and pick the normal field of view (+0x469, +0x46d):
// 81 degrees when the display object (sys slot 0xbc) says widescreen (slot 0xdc), else 67 degrees (127 when
// camera-list flag +0x83 is set); the camera list (sys +0x190f) is told widescreen on/off (slot 0xc).
static THISCALL void ZFFCamera1_Init2(void *self) {
  ext_4690b0(self);
  u8 *l = (u8 *)world_list((const char *)0x6b48dc);  // "CameraBoxList"
  at<u8 *>(self, 0x475) = l;
  if (l && ptr(l, 0x18)) {
    u32 it[4];
    vcall<void>(ptr(l, 0x18), 0x4c, it);
    u32 id = vcall<u32>(ptr(ptr(self, 0x475), 0x18), 0x5c, it);
    while (it[0]) {
      u32 *box = vcall<u32 *>(G(void *, 0x70038c), 0xcc, id);
      void *g = vcall<void *>(SYS9B, 0x58, box[0]);
      if (g) vcall<void>(g, 0xbc, 1u);
      id = vcall<u32>(ptr(ptr(self, 0x475), 0x18), 0x5c, it);
    }
  }
  if (ptr(self, 0x475)) {
    at<u32>(self, 0x479) = at<u32>(self, 0x489);
    at<u32>(self, 0x489) = 0x43fa0000;
    vcall<void>(ptr(ptr(self, 0x475), 0x18), 0x4c, &at<u32>(self, 0x59c));
  }
  u8 *g = vcall<u8 *>(SYS9B, 0x58, at<u32>(self, 0x368));
  if (g) at<u32>(self, 0x471) = cam_helper_of(g);
  void *disp = vcall<void *>(G(void *, 0x70039c), 0xbc);
  bool wide = vcall<bool>(disp, 0xdc);
  void *cl = ptr(G(u8 *, 0x70039c), 0x190f);
  if (wide) {
    vcall<void>(cl, 0xc, 1u);
    at<u32>(self, 0x469) = 0x3fb4f4ab;
    at<u32>(self, 0x46d) = 0x3fb4f4ab;
    return;
  }
  vcall<void>(cl, 0xc, 0u);
  float f = at<u8>(ptr(G(u8 *, 0x70039c), 0x190f), 0x83) ? G(float, 0x6b4d34) : G(float, 0x6b4d30);
  at<float>(self, 0x469) = f;
  at<float>(self, 0x46d) = f;
}
PCREG(5cbad0, ZFFCamera1_Init2);

// 0x5cbf60 ZFFCamera1::Load2(): after a load, find the box list again (its iterator reset, slot 0xc), mark the
// test camera for restart (+0x4d7), find the ZCamHelper, restart the box pass.
static THISCALL void ZFFCamera1_Load2(void *self) {
  u8 *l = (u8 *)world_list((const char *)0x6b48dc);
  at<u8 *>(self, 0x475) = l;
  if (l) vcall<void>(ptr(l, 0x18), 0xc);
  at<u8>(self, 0x4d7) = 1;
  at<u32>(self, 0x471) = 0;
  u8 *g = vcall<u8 *>(SYS9B, 0x58, at<u32>(self, 0x368));
  if (g) at<u32>(self, 0x471) = cam_helper_of(g);
  u8 *bl = ptr(self, 0x475);
  if (bl) {
    at<u32>(self, 0x479) = at<u32>(self, 0x489);
    at<u32>(self, 0x489) = 0x43fa0000;
    vcall<void>(ptr(bl, 0x18), 0x4c, &at<u32>(self, 0x59c));
  }
}
PCREG(5cbf60, ZFFCamera1_Load2);

// 0x5cbe30 ZFFCamera1::InitTestCam(): debug test camera follow list: the world's list at 0x7003b8 (+0x41c count,
// +0x420 entries), then the level's "TestCamList" geometries, then the focus geometry; cursor at the first.
static THISCALL void ZFFCamera1_InitTestCam(void *self) {
  u8 *w = G(u8 *, 0x7003b8);
  at<u32>(self, 0x5ac) = at<u32>(w, 0x41c);
  u32 *dst = &at<u32>(self, 0x5b0);
  const u32 *src = &at<u32>(w, 0x420);
  for (s32 n = at<s32>(w, 0x41c); n > 0; n--) *dst++ = *src++;
  u8 *l = (u8 *)world_list((const char *)0x6b4d1c);  // "TestCamList"
  if (l && ptr(l, 0x18)) {
    u32 it[4];
    vcall<void>(ptr(l, 0x18), 0x4c, it);
    u32 id = vcall<u32>(ptr(l, 0x18), 0x5c, it);
    while (it[0]) {
      u32 g = vcall<u32>(SYS9B, 0x58, id);
      if (g) {
        at<u32>(self, 0x5b0 + at<u32>(self, 0x5ac) * 4) = g;
        at<u32>(self, 0x5ac) += 1;
      }
      id = vcall<u32>(ptr(l, 0x18), 0x5c, it);
    }
  }
  u32 g = vcall<u32>(SYS9B, 0x58, at<u32>(self, 0x368));
  if (g) {
    at<u32>(self, 0x5b0 + at<u32>(self, 0x5ac) * 4) = g;
    at<u32>(self, 0x5ac) += 1;
  }
  at<u32>(self, 0x7b1) = (u32)self + 0x5b0;
  at<u32>(self, 0x7b5) = at<u32>(self, 0x5b0);
}
PCREG(5cbe30, ZFFCamera1_InitTestCam);

// 0x5cc420 ZFFCamera1::MoveTestCameraWithGeom(): debug test camera: focal point and focus 50 above the followed
// geometry (+0x7b5), focus matrix from the helper, distance moved by the helper's input +0xb27 * 15 and kept in
// -2000..-100, then placed and aimed like the normal camera (shake included).
static THISCALL void ZFFCamera1_MoveTestCameraWithGeom(void *self) {
  void *t = ptr(self, 0x7b5);
  if (!t) return;
  u32 *fp = &at<u32>(self, 0x30c);
  fp[0] = 0;
  fp[1] = 0x42480000;  // 50
  fp[2] = 0;
  vcall<void>(t, 0x84, fp);
  float *fm = &at<float>(self, 0x3b4);
  ext_4de420(fm, &at<float>(ptr(self, 0x471), 0xc89));
  u32 *fo = &at<u32>(self, 0x3d8);
  fo[0] = 0;
  fo[1] = 0x42480000;
  fo[2] = 0;
  vcall<void>(t, 0x84, fo);
  float d = at<float>(ptr(self, 0x471), 0xb27) * G(float, 0x680a80) + at<float>(self, 0x465);
  at<float>(self, 0x465) = d;
  float lo = G(float, 0x6b4d50), hi = G(float, 0x6a24f4);
  at<float>(self, 0x465) = lo > d ? lo : (hi < d ? hi : d);
  float v[3] = {at<float>(self, 0x45d), at<float>(self, 0x461), at<float>(self, 0x465)};
  ext_5c9da0(self, v);
  ext_5ca460(self, v);
  ext_5ccd10(self);
  ext_5ca4c0(self, fm, v);
  ext_5ca140(self);
}
PCREG(5cc420, ZFFCamera1_MoveTestCameraWithGeom);
