#include "ff.h"
// batch1387.cpp - unclaimed-13 claim 6 (docs/20-unclaimed-13.md). Name from the GC name map (medium).

// Callees left as original code (bound by build.sh): 0x522f60 is thiscall (object in ecx, two float stack arguments,
// callee cleans) returning a double in st0; 0x524180 is thiscall with no arguments.
extern "C" double THISCALL ext_522f60(u8 *self, float a, float b);
extern "C" void THISCALL ext_524180(u8 *self);

// 0x523840, CMoveAlongPath::MoveToSplineVal(float, bool) (medium, GUESS name). Thiscall, ret 8.
// Stores the flag byte at +0x41; clamps the argument t to [0, 1] (0 if t < 0, else min(1, t), NaN gives t) and stores it at
// +0x42; sets +0x20 to +1.0 unless (clamped - base) < 0 (base = the float at +4), then -1.0; computes r = 0x522f60 (this, base, 50.0)
// and sets +0x35 to 3 when |r| > pi/180 (else 0), +0x46 to 0, the dword at +0x39 to 1; calls vtable slot +8 with
// (Q = +0x57, P = +0x5b); calls 0x524180; and calls vtable slot +0x20 with
// (g.+0x48 * +0x24 / +0x53 * +0x20 + +4), g being the global at 0x70039c.
static void THISCALL moveAlongPathMoveToSplineVal(u8 *self, float t, u32 flag) {
  const float one = 1.0f;
  *(u8 *)(self + 0x41) = (u8)flag;

  float clamped = (0.0f > t) ? 0.0f : ((one < t) ? one : t);
  *(float *)(self + 0x42) = clamped;

  float base = *(float *)(self + 4);
  float d = clamped - base;
  *(float *)(self + 0x20) = (0.0f > d) ? -1.0f : 1.0f;

  double r = ext_522f60(self, base, 50.0f);
  union { double d; u64 u; } ar;
  ar.d = r;
  ar.u &= 0x7fffffffffffffffull;

  *(u32 *)(self + 0x35) = (ar.d > 0.01745329238474369) ? 3u : 0u;
  *(u8 *)(self + 0x46) = 0;
  *(u32 *)(self + 0x39) = 1;

  u32 *vt = *(u32 **)self;
  typedef void(THISCALL * slot8_fn)(u8 *, float, float);
  ((slot8_fn)vt[8 / 4])(self, *(float *)(self + 0x57), *(float *)(self + 0x5b));

  ext_524180(self);

  u8 *g = (u8 *)(unsigned long)G(u32, 0x70039c);
  float v = *(float *)(g + 0x48);
  v = v * *(float *)(self + 0x24);
  v = v / *(float *)(self + 0x53);
  v = v * *(float *)(self + 0x20);
  v = v + *(float *)(self + 4);

  vt = *(u32 **)self;
  typedef void(THISCALL * slot20_fn)(u8 *, float);
  ((slot20_fn)vt[0x20 / 4])(self, v);
}
PCREG(523840, moveAlongPathMoveToSplineVal);
