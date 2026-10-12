#include "ff.h"
// batch907.cpp - unclaimed-01 claim 6 (docs/20-unclaimed-01.md). CMoveAlongPath::FrameUpdate (0x523280, high).
// The three callees are original code (ext_ bindings), not lifted here. Comparisons follow the PC flags: a jbe after
// comiss(x, y) is taken exactly when !(x > y), so NaN takes the branch the same way the exe does.

extern "C" void THISCALL ext_524180(u8 *self);   // called first when +0x4b is nonzero (original code)
extern "C" void THISCALL ext_5230e0(u8 *self);   // called second (original code)
extern "C" void THISCALL ext_524270(u8 *self);   // tail-jumped to at the end when +0x63 != 0 (original code)

static void THISCALL moveAlongPathFrameUpdate(u8 *self) {
  if (*(u32 *)(self + 0x4b) == 0)
    return;
  ext_524180(self);
  ext_5230e0(self);
  u8 *g = G(u8 *, 0x70039c);
  float dt = *(float *)(g + 0x48);
  float step = dt * *(float *)(self + 0x24) / *(float *)(self + 0x53) * *(float *)(self + 0x20) + *(float *)(self + 4);
  typedef void(THISCALL * slot_fn)(u8 *, float);
  slot_fn vf = *(slot_fn *)(*(u32 *)self + 0x20);
  vf(self, step);
  g = G(u8 *, 0x70039c);
  dt = *(float *)(g + 0x48);
  float f28 = *(float *)(self + 0x28);
  float f2c = *(float *)(self + 0x2c);
  float nf = dt * f28 + *(float *)(self + 0x24);
  *(float *)(self + 0x24) = nf;
  if (f28 > 0.0f) {
    if (nf > f2c) {
      *(float *)(self + 0x28) = 0.0f;
      *(float *)(self + 0x24) = f2c;
    }
  } else if (0.0f > f28) {
    if (f2c > nf) {
      *(float *)(self + 0x28) = 0.0f;
      *(float *)(self + 0x24) = f2c;
    }
  }
  if (*(float *)(self + 0x63) != 0.0f)
    ext_524270(self);
}
PCREG(523280, moveAlongPathFrameUpdate);
