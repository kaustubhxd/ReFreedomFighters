// batch1036.cpp - ZCAMERA (engine render camera) accessors and setters. Camera thread, 2026-10-11.
// Setters that change a value also set dirty flag 0x2 in +0x48; an equal or NaN-free equal value leaves it alone.
#include "cam.h"

// 0x445fb0 ZCAMERA::GetViewAspect() const: float at +0x181 (returned in ST0).
static THISCALL float ZCAMERA_GetViewAspect(void *self) { return at<float>(self, 0x181); }
PCREG(445fb0, ZCAMERA_GetViewAspect);

// 0x445fc0 ZCAMERA::GetViewport(float* out) const: four dwords from +0x171.
static THISCALL void ZCAMERA_GetViewport(void *self, u32 *out) {
  out[0] = at<u32>(self, 0x171);
  out[1] = at<u32>(self, 0x175);
  out[2] = at<u32>(self, 0x179);
  out[3] = at<u32>(self, 0x17d);
}
PCREG(445fc0, ZCAMERA_GetViewport);

// 0x446030 ZCAMERA::IsActive() const: bit 5 of the flags (+0x48).
static THISCALL u32 ZCAMERA_IsActive(void *self) { return (at<u32>(self, 0x48) >> 5) & 1; }
PCREG(446030, ZCAMERA_IsActive);

// Helper: store v at off when it differs (or is NaN), setting dirty flag 0x2.
static inline void set_if_changed(void *self, u32 off, float v) {
  float cur = at<float>(self, off);
  if (!(cur == v)) {
    at<u32>(self, 0x48) |= 2;
    at<float>(self, off) = v;
  }
}

// 0x446d80 ZCAMERA::SetFOV(float degrees): stored as radians (x 0.0174533) at +0x5c.
static THISCALL void ZCAMERA_SetFOV(void *self, float deg) { set_if_changed(self, 0x5c, deg * G(float, 0x67da04)); }
PCREG(446d80, ZCAMERA_SetFOV);

// 0x446db0 ZCAMERA::SetFar(float) at +0x68.
static THISCALL void ZCAMERA_SetFar(void *self, float v) { set_if_changed(self, 0x68, v); }
PCREG(446db0, ZCAMERA_SetFar);

// 0x446de0 ZCAMERA::SetNear(float) at +0x64, at least 1.0 (maxss: NaN passes through).
static THISCALL void ZCAMERA_SetNear(void *self, float v) {
  float m = G(float, 0x678858) > v ? G(float, 0x678858) : v;
  set_if_changed(self, 0x64, m);
}
PCREG(446de0, ZCAMERA_SetNear);

// 0x446e10 ZCAMERA::SetTargetLen(float) at +0x60.
static THISCALL void ZCAMERA_SetTargetLen(void *self, float v) { set_if_changed(self, 0x60, v); }
PCREG(446e10, ZCAMERA_SetTargetLen);

// 0x446e40 ZCAMERA::SetViewAspect(float) at +0x181 (no dirty flag).
static THISCALL void ZCAMERA_SetViewAspect(void *self, float v) { at<float>(self, 0x181) = v; }
PCREG(446e40, ZCAMERA_SetViewAspect);

// 0x446eb0 ZCAMERA::SetWideScreen(bool): flag byte +0x196; FOV 81 deg (1.4137166 rad) wide, 67 deg (1.1693705) normal.
static THISCALL void ZCAMERA_SetWideScreen(void *self, u32 on) {
  at<u8>(self, 0x196) = (u8)on;
  at<u32>(self, 0x5c) = (u8)on ? 0x3fb4f4abu : 0x3f95adefu;
}
PCREG(446eb0, ZCAMERA_SetWideScreen);

// 0x446780 ZCAMERA::SetBackColor(int) at +0x6c.
static THISCALL void ZCAMERA_SetBackColor(void *self, u32 c) { at<u32>(self, 0x6c) = c; }
PCREG(446780, ZCAMERA_SetBackColor);
