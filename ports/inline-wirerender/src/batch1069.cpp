// batch1069.cpp - clip-plane builder 0x4453c0 (name not in the class map; called by SetCam6ClipPlanes, 0x446790).
// Camera thread, 2026-10-11.
#include "cam.h"

typedef void (*relfn)(void);

// Any nonzero or NaN component: the normal is normalized (the original's jp tests).
static inline bool needs_norm(const float *v) {
  return !(v[0] == 0.0f && v[1] == 0.0f && v[2] == 0.0f);
}

// 0x4453c0 (thiscall, two stack args: plane ptr, index): the plane (x, y, z, w) is normalized in place (the
// length goes to w: w *= len; for a zero normal w *= 0) and appended to the arrays: the index table at +8
// (entry n = n), the count at +0, the counter at +4, and the planes at +0x38 + 16n (x), +0x3c, +0x40, +0x44.
// An index that is not the count calls the callback at 0x7003b0 (int3 when unset).
static THISCALL void ZCamPlanes_Add(u8 *self, float *plane, u32 index) {
  u32 n = at<u32>(self, 0);
  if (index != n) {
    relfn cb = G(relfn, 0x7003b0);
    if (!cb) __builtin_trap();   // the original's int3 when the callback is unset
    cb();
  }
  float wscale = 0.0f;
  if (needs_norm(plane)) {
    long double s = (long double)plane[0] * plane[0];
    s = s + (long double)plane[1] * plane[1];
    s = s + (long double)plane[2] * plane[2];
    long double len = fsqrt_x87(s);
    long double inv = 1.0L / len;
    plane[0] = (float)(plane[0] * inv);
    plane[1] = (float)(plane[1] * inv);
    plane[2] = (float)(plane[2] * inv);
    wscale = (float)len;   // the x87 stack keeps len: the last fstp to the scale slot stores the length
  }
  plane[3] = wscale * plane[3];
  at<u32>(self, 8 + n * 4) = n;
  at<u32>(self, 4) = at<u32>(self, 4) + 1;
  at<float>(self, 0x38 + 16 * n) = plane[0];
  at<float>(self, 0x3c + 16 * n) = plane[1];
  at<float>(self, 0x40 + 16 * n) = plane[2];
  at<float>(self, 0x44 + 16 * n) = plane[3];
  at<u32>(self, 0) = n + 1;
}
PCREG(4453c0, ZCamPlanes_Add);
