// batch1003.cpp - ZFFCamera1::ChangeZoomLevel: close-up (aim / scope) camera parameters per pointer mode.
// Camera thread, 2026-10-11.
#include "cam.h"

// Fields (ZFFCamera1, packed):
//   +0x451, +0x455  close-up camera offset (side, up) in the follow frame
//   +0x469          normal field of view (radians), +0x46d current target field of view
//   +0x479          box-limited distance (CheckCamBoxes), +0x485 close-up distance
//   +0x4b2          zoom transition time (s)
//   +0x4ca          close-up (aim) on; +0x4dc pointer mode, +0x4e0 previous pointer mode
//   +0x598, +0x599  zooming in / zooming out to close-up
// The owner (+0x471, ZCamHelper) +0x44 is the hero: +0x71 "hide hero" byte (scope view), +0x417 flags (0x400
// changes the close-up distance from 70 to 90; inferred: crouch or similar stance).
static THISCALL void ZFFCamera1_ChangeZoomLevel(void *self) {
  at<u8>(ptr(ptr(self, 0x471), 0x44), 0x71) = 0;
  if (at<u8>(self, 0x4ca)) {
    at<u32>(self, 0x4b2) = 0x3e800000;  // 0.25 s
    at<u32>(self, 0x485) = 0x428c0000;  // 70
    at<u32>(self, 0x451) = 0x41a00000;  // 20
    at<u32>(self, 0x455) = 0xc1700000;  // -15
    if (at<u32>(ptr(ptr(self, 0x471), 0x44), 0x417) & 0x400) at<u32>(self, 0x485) = 0x42b40000;  // 90
    u32 mode = at<u32>(self, 0x4dc);
    if (at<u32>(self, 0x4e0) != mode) at<u16>(self, 0x598) = 1;
    at<u32>(self, 0x4e0) = mode;
    switch (mode) {
      case 12:
        at<u32>(self, 0x4b2) = 0x3e800000;  // 0.25 s
        at<u32>(self, 0x485) = 0x40000000;  // 2
        at<u32>(self, 0x451) = 0;
        at<u32>(self, 0x455) = 0x41200000;  // 10
        at<u32>(self, 0x46d) = 0x3e32b8c2;  // 10 degrees
        break;
      case 4: {  // sniper scope: hero hidden (unless sys +0x1b5d), field of view kept within 4..24 degrees
        at<u32>(self, 0x4b2) = 0x3e800000;
        at<u32>(self, 0x485) = 0x40000000;
        at<u32>(self, 0x451) = 0;
        at<u32>(self, 0x455) = 0x41200000;
        if (at<u32>(G(u8 *, 0x70039c), 0x1b5d) == 0) at<u8>(ptr(ptr(self, 0x471), 0x44), 0x71) = 1;
        float f = at<float>(self, 0x46d);
        const float lo = G(float, 0x6b4d28), hi = G(float, 0x6b4d2c);
        at<float>(self, 0x46d) = lo > f ? lo : (hi < f ? hi : f);  // comiss/ja, then minss(hi, f)
        break;
      }
      case 5:
        at<u32>(self, 0x4b2) = 0x3f000000;  // 0.5 s
        at<u32>(self, 0x485) = 0x43480000;  // 200
        at<u32>(self, 0x451) = 0;
        at<u32>(self, 0x455) = 0x41200000;
        break;
      case 7:
        at<u32>(self, 0x455) = 0xc0800000;  // -4
        break;
      case 8:
        at<u32>(self, 0x46d) = at<u32>(self, 0x469);
        break;
      default:
        at<u32>(self, 0x46d) = 0x3f0efa35;  // 32 degrees
        break;
    }
  } else {
    at<u32>(self, 0x4b2) = 0x3f800000;  // 1 s
    at<u32>(self, 0x451) = 0;
    at<u32>(self, 0x455) = 0;
    at<u32>(self, 0x46d) = at<u32>(self, 0x469);
    switch (at<u32>(self, 0x4dc)) {
      case 4: at<u32>(self, 0x4b2) = 0x3f000000; break;
      case 5: at<u32>(self, 0x4b2) = 0x3f800000; break;
      case 12: at<u32>(self, 0x4b2) = 0x3e800000; break;
    }
  }
  if (at<u8>(self, 0x598) || at<u8>(self, 0x599)) return;
  // Not zooming: a change of the box-limited distance gets a slow 3 s transition. GetCurDist is called twice.
  float box = at<float>(self, 0x479);
  float d = vcall<float>(self, 0xac);
  if (box > d || vcall<float>(self, 0xac) > at<float>(self, 0x479)) at<u32>(self, 0x4b2) = 0x40400000;  // 3 s
}
PCREG(5cb190, ZFFCamera1_ChangeZoomLevel);
