// batch1701.cpp - wire-actors thread (2026-10-15): ZCamHelper::AngleToAimXZ 0x5cf5d0 (copy of the version in inline-camera batch1010, with the
// callee declarations of batch50 so the pilot runs the same exe callees as the 0x5cf520 spec).
#include "ff.h"

extern "C" void THISCALL ext_5cf420(u8 *cam, float *out);                          // aim origin
extern "C" void THISCALL ext_4e09b0(float *v);                                     // vneg
extern "C" void FASTCALL ext_43e920(float *dst, const float *src, const float *a); // PSVECSubtract
extern "C" float FASTCALL ext_4e0030(const float *a, const float *b);              // vangle, ST0

// 0x5cf5d0, thiscall, ret 4, result in ST0: like 0x5cf520 (the angle between the aim direction and p - aim origin) in the horizontal plane:
// y of both vectors is zeroed before vangle. The aim direction is -(+0xcdd) when +0xa4c == 1, else +0xa72.
static float THISCALL aimAngleToXZ(u8 *cam, const float *p) {
  float org[3], dir[3], d[3];
  ext_5cf420(cam, org);
  if (*(u32 *)(cam + 0xa4c) == 1) {
    dir[0] = *(float *)(cam + 0xcdd);
    dir[1] = *(float *)(cam + 0xce1);
    dir[2] = *(float *)(cam + 0xce5);
    ext_4e09b0(dir);
  } else {
    dir[0] = *(float *)(cam + 0xa72);
    dir[1] = *(float *)(cam + 0xa76);
    dir[2] = *(float *)(cam + 0xa7a);
  }
  ext_43e920(d, p, org);
  d[1] = 0.0f;
  dir[1] = 0.0f;
  return ext_4e0030(d, dir);
}
PCREG(5cf5d0, aimAngleToXZ);
