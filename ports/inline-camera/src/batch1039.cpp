// batch1039.cpp - ZCAMERA::Proj2D3D and ZCAMERA::Proj3D (screen <-> world ray helpers). Camera thread, 2026-10-11.
// Flag bit 0 of +0x48 selects orthographic projection. Field use: +0x3c / +0x40 screen scale (x, y), +0x58 focal
// distance (perspective).
#include "cam.h"

// 0x446280 ZCAMERA::Proj2D3D(float* a, float* b) const: a is the screen point in and out; b (if not null) receives
// the ray direction (0, 0, 1) in the orthographic case. Perspective: b = (a.x / f, a.y / f / s, 1), then a = 0.
static THISCALL void ZCAMERA_Proj2D3D(u8 *self, float *a, float *b) {
  if (at<u8>(self, 0x48) & 1) {
    float x = a[0] / at<float>(self, 0x3c);
    float y = a[1] / at<float>(self, 0x40);
    a[2] = 0.0f;
    a[1] = y;
    a[0] = x;
    if (b) {
      b[0] = 0.0f;
      b[1] = 0.0f;
      b[2] = 1.0f;
    }
  } else {
    float y = a[1] / at<float>(self, 0x58) / at<float>(self, 0x40);
    float x = a[0] / at<float>(self, 0x58);
    b[2] = 1.0f;
    b[1] = y;
    b[0] = x;
    a[0] = 0.0f;
    a[1] = 0.0f;
    a[2] = 0.0f;
  }
}
PCREG(446280, ZCAMERA_Proj2D3D);

// 0x446430 ZCAMERA::Proj3D(float* x, float* y) const: x (3D, its z is read) receives the point for the screen
// point y: ortho x = (y0 / sx, -y1 / sy); perspective with d = f / x.z: x = (y0 / d, -y1 / d / sy).
static THISCALL void ZCAMERA_Proj3D(u8 *self, float *x, float *y) {
  if (at<u8>(self, 0x48) & 1) {
    x[0] = y[0] / at<float>(self, 0x3c);
    float v = y[1] / at<float>(self, 0x40);
    asm("" : "+x"(v));   // keeps the sign flip after the divide (LLVM would fold it into the divide: NaN sign differs)
    x[1] = bitsf(fbits(v) ^ 0x80000000u);
  } else {
    float d = at<float>(self, 0x58) / x[2];
    x[0] = y[0] / d;
    float v = y[1] / d / at<float>(self, 0x40);
    asm("" : "+x"(v));   // see above
    x[1] = bitsf(fbits(v) ^ 0x80000000u);
  }
}
PCREG(446430, ZCAMERA_Proj3D);
