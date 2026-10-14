// batch1700.cpp - wire-actors thread (2026-10-15): vangle 0x4e0030, the angle between two vectors, needed by the camera helper's aim-assist pick
// (ZCamHelper::AngleToAim 0x5cf520 -> CanTarget 0x5d0490 -> PickAimTarget 0x5cf110 -> CommandPointerAtEnemy 0x5cda40).
#include "ff.h"

// 0x4e0030 vangle(const float *a, const float *b), fastcall (a in ECX, b in EDX), plain ret, result in ST0 (a float).
// SSE single precision: sb = b.x*b.x + b.y*b.y + b.z*b.z, dot = b.x*a.x + b.y*a.y + b.z*a.z (b factor first), lb = (float)sqrt((double)sb),
// la = (float)sqrt((double)(a.x*a.x + a.y*a.y + a.z*a.z)); c = dot / (lb * la). c > 1 gives 0, c < -1 gives pi (0x40490fdb),
// otherwise (float)acos((double)c) through the CRT slot 0x676354 (a NaN falls through to acos).
static float FASTCALL vangle(const float *a, const float *b) {
  float sb = b[0] * b[0] + b[1] * b[1];
  float dot = b[0] * a[0] + b[1] * a[1];
  dot = dot + b[2] * a[2];
  sb = sb + b[2] * b[2];
  float lb = (float)crt::sqrt((double)sb);
  float sa = a[0] * a[0] + a[1] * a[1];
  sa = sa + a[2] * a[2];
  float la = (float)crt::sqrt((double)sa);
  float c = dot / (lb * la);
  if (c > 1.0f)
    return 0.0f;
  if (-1.0f > c)
    return bitsf(0x40490fdbu);
  return (float)crt::acos((double)c);
}
PCREG(4e0030, vangle);
