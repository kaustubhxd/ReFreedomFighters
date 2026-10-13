// batch1008.cpp - ZFFCamera1 camera-box setup and the lower height limit. Camera thread, 2026-10-11.
#include "cam.h"

extern "C" THISCALL void ext_5ccba0(void *self, u32 id);       // ZFFCamera1::TestBox (batch1002; inlined in the original)
extern "C" THISCALL void ext_5c9da0(void *self, float *v);     // focus -> world (batch1001)
extern "C" THISCALL void ext_5c9e30(void *self, float *v);     // focus geometry slot 0x8c (batch1001)
extern "C" THISCALL void ext_5c9dd0(void *self, float *v);     // focus geometry slot 0x84 (batch1001)
extern "C" THISCALL void ext_5c9ed0(void *self, float *out);   // ZFFCam::GetGlobalFocalPoint
extern "C" FASTCALL void ext_4e0d40(float *out, const float *in, float s);  // vscalar: out = in * s
extern "C" FASTCALL void ext_4dfa30(float *out, const float *p, const float *dir, const float *pp, const float *n);  // line/plane intersection (inferred)
extern "C" FASTCALL float ext_4e0870(const float *a, const float *b);  // |a - b|

// 0x5cbca0 (unnamed) ZFFCamera1::InitCamboxDist() (GC name by size 212 B and use at activation; inferred): runs
// the whole camera-box list once (iterator on the stack, list +0x18 slots 0x4c start / 0x5c next) so the box
// distance is right on the first frame, then sets the wanted and current distance from it.
static THISCALL void ZFFCamera1_InitCamboxDist(void *self) {
  u8 *l = ptr(self, 0x475);
  if (!l) {
    at<u32>(self, 0x479) = 0x43fa0000;
    at<u32>(self, 0x2f6) = 0x43fa0000;
    return;
  }
  void *it = ptr(l, 0x18);
  if (it) {
    u32 cur[0x10];  // iterator state; its first word is non-zero while entries remain
    vcall<void>(it, 0x4c, cur);
    u32 id = vcall<u32>(ptr(ptr(self, 0x475), 0x18), 0x5c, cur);
    while (cur[0]) {
      ext_5ccba0(self, id);
      id = vcall<u32>(ptr(ptr(self, 0x475), 0x18), 0x5c, cur);
    }
  }
  float d = at<float>(self, 0x489);
  at<float>(self, 0x479) = d;
  at<float>(self, 0x47d) = d;
  at<float>(self, 0x459) = -d;
  at<float>(self, 0x465) = -d;
  at<u32>(self, 0x489) = 0x43fa0000;
}
PCREG(5cbca0, ZFFCamera1_InitCamboxDist);

// 0x5cc200 (unnamed) ZFFCamera1 lower limit (GC candidate LowerCollisionCheck, 316 B; inferred). The limit (+0x4ae)
// is 180 when hero flag 0x8000000 is set, otherwise -1e38 (off). A point 1500 behind the focus, taken to the
// focus geometry's local frame, is compared with it: if lower, it counts as a collision (+0x30a) and the max
// distance is cut to where the focal->back line (along -focus X axis row) meets the plane y = limit.
static THISCALL void ZFFCamera1_LowerLimit(void *self) {
  u8 *hero = ptr(ptr(self, 0x471), 0x44);
  at<u32>(self, 0x4ae) = (at<u32>(hero, 0x417) & 0x8000000) ? 0x43340000 : 0xfe967699;
  float v[3] = {0.0f, 0.0f, -1500.0f};
  ext_5c9da0(self, v);
  ext_5c9e30(self, v);
  if (!(at<float>(self, 0x4ae) > v[1])) return;
  float *fp = &at<float>(self, 0x30c);
  at<u8>(self, 0x30a) = 1;
  ext_5c9ed0(self, fp);
  float a[3];
  ext_4e0d40(a, &at<float>(self, 0x3b4), -1.0f);
  float b[3] = {0.0f, at<float>(self, 0x4ae), 0.0f};
  ext_5c9dd0(self, b);
  float c[3];
  ext_4dfa30(c, fp, a, b, (const float *)0x6ef2d8);
  float d = ext_4e0870(c, fp);
  if (at<float>(self, 0x4aa) > d) at<float>(self, 0x4aa) = d;
  ext_5c9dd0(self, v);
}
PCREG(5cc200, ZFFCamera1_LowerLimit);
