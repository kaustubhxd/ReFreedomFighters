// batch303.cpp - unclaimed-03 batch 3 (docs/20-unclaimed-03.md): CMoveAlongPath::CalcAcceleration and
// CMoveAlongPath::OffsetSplineVal. Names are from the GC name map (naming only, GUESS where medium or low); the bodies
// are from the PC bytes. Both return a float on the x87 stack.
#include "ff.h"

// 0x522f20, CMoveAlongPath::CalcAcceleration(float, float) (medium, GUESS): if the first argument is greater than the
// float at 0x679540 (comiss, unordered skips), returns ((a2 - this+0x24)^2 / a1) * the float at 0x67a6ac; otherwise
// returns the constant 0x7e967699 (about 1e38) that the PC code stores in the argument slot first. The store into
// the argument slot is the caller's stack, not visible to the port. Callee pops 8.
static float THISCALL moveAlongCalcAcceleration(u8 *self, float a1, float a2) {
  float d = a2 - *(float *)(self + 0x24);
  float r = bitsf(0x7e967699u);
  if (a1 > bitsf(0x39000000u) /* 0x679540 */)
    r = (d * d) / a1 * bitsf(0x3f000000u) /* 0x67a6ac, 0.5 */;
  return r;
}
PCREG(522f20, moveAlongCalcAcceleration);

// 0x523940, CMoveAlongPath::OffsetSplineVal(float) (medium, GUESS): t = (a / this+0x53) + this+4 (divss, addss). If
// t < 0 the result is 0; otherwise it is minss(1.0 from 0x678858, t): 1.0 when 1.0 < t, else t (NaN gives t). The
// minss form is kept with the SSE intrinsic so the NaN and equal cases match the PC instruction. Callee pops 4.
static float THISCALL moveAlongOffsetSplineVal(u8 *self, float a) {
  float t = a / *(float *)(self + 0x53) + *(float *)(self + 0x4);
  if (t < 0.0f)
    return 0.0f;
  return _mm_cvtss_f32(_mm_min_ss(_mm_set_ss(1.0f), _mm_set_ss(t)));
}
PCREG(523940, moveAlongOffsetSplineVal);
