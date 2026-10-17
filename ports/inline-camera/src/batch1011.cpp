// batch1011.cpp - ZCamHelper mouse aim: MovePointerMouse. Camera thread, 2026-10-11.
#include "cam.h"

extern "C" THISCALL u32 ext_591b20(void *hero);  // ZFFHERO::GetFFItemType

static inline float minss(float a, float b) { return a < b ? a : b; }  // SSE minss(a, b): b when unordered

// 0x5d0df0 ZCamHelper::MovePointerMouse(): mouse deltas (+0xe0f x, +0xe13 y) times the pointer speed (+0xadd)
// turn the aim yaw (+0xa54, wrapped to -pi..pi) and pitch (+0xa5c, clamped to -70..+60 degrees). Holding item
// type 9 limits each step to 0.05 rad (about 2.9 degrees) per frame. A step of more than 179.9 degrees either
// way counts as exactly 180.
static THISCALL void ZCamHelper_MovePointerMouse(void *self) {
  float s = at<float>(self, 0xadd);
  float dx = at<float>(self, 0xe0f) * s;
  float dy = at<float>(self, 0xe13) * s;
  if (ext_591b20(ptr(self, 0x44)) == 9) {
    const float lo = G(float, 0x6b4fd8), hi = G(float, 0x681dc4);
    dx = lo > dx ? lo : minss(hi, dx);
    dy = lo > dy ? lo : minss(hi, dy);
  }
  const float pi = G(float, 0x67da18);
  if (dx > G(float, 0x6ad1fc) || G(float, 0x6ad234) > dx) dx = pi;
  float yaw = at<float>(self, 0xa54) - dx;
  if (yaw > pi)
    yaw = yaw - G(float, 0x68aef8);
  else if (G(float, 0x6ad238) > yaw)
    yaw = yaw + G(float, 0x68aef8);
  at<float>(self, 0xa54) = yaw;
  float pitch = at<float>(self, 0xa5c) - dy;
  at<float>(self, 0xa5c) = pitch;
  const float plo = G(float, 0x6b4ff0);
  at<float>(self, 0xa5c) = plo > pitch ? plo : minss(G(float, 0x6a09e4), pitch);
}
PCREG(5d0df0, ZCamHelper_MovePointerMouse);

extern "C" THISCALL void ext_5a7530(void *osd, u32 mode);  // OSD pointer drawing mode (inferred)
extern "C" THISCALL void ext_5cc880(void *cam, u32 on);    // ZFFCamera1::SetCloseUp (batch1002)
extern "C" THISCALL u32 ext_5d11c0(void *self);            // (unnamed, x87) target check for mode 9

// Debug log: (*0x700390) slot 0x20(file, line) gives a stream whose vtable slot `off` is a cdecl printf-style
// method called as fn(stream, msg). The original leaves ECX = the stream's vtable; the stub does not log ECX.
static inline void debug_log(u32 line, u32 off, const char *msg) {
  void *s = vcall<void *>(G(void *, 0x700390), 0x20, (const char *)0x6b4e78, line);
  typedef void (*logfn)(void *, const char *);
  (*(logfn *)(*(u8 **)s + off))(s, msg);
}

// Aim tuning fields: +0xadd pointer speed, +0xb01 (unknown factor), +0xaf9/+0xafd two angles (15 and 7 degrees
// when aiming), +0xa96/+0xa9a and +0xa9e/+0xaa2 two angle ranges (-75..75 aiming, -70..60 otherwise).
static inline void aim_tuning(void *self, u32 speed) {
  at<u32>(self, 0xb01) = 0x3e99999a;  // 0.3
  at<u32>(self, 0xadd) = speed;
  at<u32>(self, 0xaf9) = 0x3e860a92;  // 15 deg
  at<u32>(self, 0xafd) = 0x3dfa35dd;  // 7 deg
  at<u32>(self, 0xa96) = 0xbfa78d36;  // -75 deg
  at<u32>(self, 0xa9a) = 0x3fa78d36;  // 75 deg
  at<u32>(self, 0xa9e) = 0xbfa78d36;
  at<u32>(self, 0xaa2) = 0x3fa78d36;
}

// 0x5d2eb0 ZCamHelper::UpdatePointerMode(): each frame, from the pointer mode (+0xad5, EFFPointerMode) and the
// aim button (+0xb45): tell the camera the mode (camera +0x4dc), set the enemy-pick limits (range 3000, cone 90
// degrees for scheme 1 else +0xdf5), the pointer speed and angle limits, the OSD pointer drawing (object +0xe18,
// fetched from the hero's +0x852 -> +0x1d0f), and switch the camera close-up on while aiming.
// Aiming: pointer speed 0.25 (mode 4 sniper: 0.1, mode 12: 0.25 with no extra angles). Not aiming: speed 1, angle
// range -70..60; mode 5 forces the close-up (speed 0.35). +0xd32 = pointer free (not aiming, first person or
// scheme +0xe1c == 3 aside); item type 11 clears it.
static THISCALL void ZCamHelper_UpdatePointerMode(void *self) {
  u8 closeup = 0;
  if (at<u32>(self, 0xe18) == 0) {
    u8 *p = ptr(ptr(self, 0x44), 0x852);
    if (p) at<u32>(self, 0xe18) = at<u32>(p, 0x1d0f);
    if (at<u32>(self, 0xe18) == 0) {
      debug_log(0x156, 0x30, (const char *)0x6b4f30);  // "ZCamHelper::UpdatePointerMode() -> m_lpDrawOSD=0"
      return;
    }
  }
  void *cam = ptr(self, 0xb54);
  at<u32>(cam, 0x4dc) = at<u32>(self, 0xad5);
  at<u32>(self, 0xdfd) = 0x453b8000;  // 3000
  at<u32>(self, 0xe01) = 0x4b095440;  // 9e6
  at<u32>(self, 0xdf9) = at<u32>(self, 0xa4c) == 1 ? 0x3fc90fdb : at<u32>(self, 0xdf5);
#define OSD(n) ext_5a7530(ptr(self, 0xe18), n)
  if (at<u8>(self, 0xb45)) {
    u32 mode = at<u32>(self, 0xad5);
    closeup = 1;
    at<u8>(self, 0xd32) = 0;
    aim_tuning(self, 0x3e800000);  // 0.25
    switch (mode) {
      case 0: OSD(0); break;
      case 1: OSD(1); break;
      case 2: OSD(3); break;
      case 3: OSD(0x12); break;
      case 4:  // sniper scope
        at<u32>(self, 0xb01) = 0x3f800000;
        at<u32>(self, 0xadd) = 0x3dcccccd;  // 0.1
        at<u32>(self, 0xafd) = 0;
        at<u32>(self, 0xaf9) = 0;
        OSD(0x10);
        break;
      case 5: ext_5cc880(ptr(self, 0xb54), 0); break;
      case 6: OSD(5); break;
      case 7: OSD(7); break;
      case 8: OSD(9); break;
      case 9:
        if ((u8)ext_5d11c0(self)) (void)vcall<void *>(SYS9B, 0x58, at<u32>(self, 0xd0d));
        OSD(0);
        break;
      case 10: {
        ext_5cc880(ptr(self, 0xb54), 0);
        debug_log(0x1bd, 0x2c, (const char *)0x6b4f64);  // "ERROR: ML: This should not happen!!"
        typedef void (*failfn)();
        failfn fail = G(failfn, 0x7003b0);
        if (fail)
          fail();
        else
          __builtin_debugtrap();
        break;
      }
      case 11: OSD(0xd); break;
      case 12:
        at<u32>(self, 0xb01) = 0x3f800000;
        at<u32>(self, 0xadd) = 0x3e800000;
        at<u32>(self, 0xafd) = 0;
        at<u32>(self, 0xaf9) = 0;
        OSD(0x11);
        break;
    }
  } else {
    void *osd = ptr(self, 0xe18);
    at<u8>(self, 0xd32) = 1;
    bool fp = at<u8>(ptr(self, 0x44), 0x67a) != 0;
    if (at<u32>(self, 0xe1c) == 3) {
      fp = true;
      at<u8>(self, 0xd32) = 0;
    }
    at<u32>(self, 0xadd) = 0x3f800000;
    at<u32>(self, 0xb01) = 0x3f800000;
    at<u32>(self, 0xaf9) = 0;
    at<u32>(self, 0xafd) = 0;
    at<u32>(self, 0xa96) = 0xbf9c61aa;  // -70 deg
    at<u32>(self, 0xa9a) = 0x3f860a92;  // 60 deg
    at<u32>(self, 0xa9e) = 0xbf9c61aa;
    at<u32>(self, 0xaa2) = 0x3f860a92;
    ext_5a7530(osd, 0);
    switch (at<u32>(self, 0xad5)) {
      case 0: OSD(0); break;
      case 1: if (fp) OSD(1); break;
      case 2: case 4: if (fp) OSD(3); break;
      case 3: if (fp) OSD(0x12); break;
      case 5:
        closeup = 1;
        at<u8>(self, 0xd32) = 0;
        aim_tuning(self, 0x3eb33333);  // 0.35
        OSD(5);
        break;
      case 6: if (fp) OSD(5); break;
      case 7:
        at<u8>(self, 0xd32) = 0;
        OSD(7);
        break;
      case 8: if (fp) OSD(9); break;
      case 9:
        if ((u8)ext_5d11c0(self)) (void)vcall<void *>(SYS9B, 0x58, at<u32>(self, 0xd0d));
        OSD(0);
        break;
    }
  }
#undef OSD
  ext_5cc880(ptr(self, 0xb54), closeup);
  if (ext_591b20(ptr(self, 0x44)) == 0xb) at<u8>(self, 0xd32) = 0;
}
PCREG(5d2eb0, ZCamHelper_UpdatePointerMode);
