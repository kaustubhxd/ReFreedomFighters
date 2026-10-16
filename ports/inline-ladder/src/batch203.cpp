// batch203.cpp - ladder tree (inline-ladder thread, 2026-10-11): ZSHAPE::GetDistToSegment.
#include "ff.h"

extern "C" void THISCALL ext_460100(u8 *self, const float *p0, const float *p1, const float *p2, const float *p3, float h);
extern "C" float THISCALL ext_4602b0(u8 *self, const float *p, float t0, float *out, int steps);

// 0x44ace0, ZSHAPE::GetDistToSegment(float (&out)[3], float *pts, const float (&p)[3]) const [GameCube reference, medium],
// thiscall (this is not read), three stack args, ret 0xc, float return in ST0.
// A ParametricCurve on the stack (vtable 0x67f86c, the float at +0x34 preset to -1.0) is set to the Bezier segment of the
// four points pts[0..3] (12 bytes apart) with arc-length step 0.1 (0x3dcccccd), then GetClosestPoint(p, 0.0, out, 10)
// gives the closest point in out and its distance, which is returned. The PC build never reads GetClosestPoint's float argument.
static float THISCALL getDistToSegment(void *self, float *out, const float *pts, const float *p) {
  (void)self;
  u32 curve[0x38 / 4];
  curve[0] = 0x67f86c;
  curve[0x34 / 4] = 0xbf800000;
  ext_460100((u8 *)curve, pts, pts + 3, pts + 6, pts + 9, bitsf(0x3dcccccd));
  return ext_4602b0((u8 *)curve, p, 0.0f, out, 10);
}
PCREG(44ace0, getDistToSegment);
