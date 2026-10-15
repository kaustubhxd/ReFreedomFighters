// batch1018.cpp - ZFFCamera1 setup: Reset, Init2, Load2, InitTestCam, MoveTestCameraWithGeom. Camera thread, 2026-10-11.
#include "ff.h"
template<class T>static T&at(void*p,u32 o){return *(T*)((u8*)p+o);}
static void*ptr(void*p,u32 o){return at<void*>(p,o);}
#define SYS9B ptr(G(void*,0x70039c),0x9b)

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

