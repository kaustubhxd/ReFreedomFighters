// batch1064.cpp - ZCAMERA::Proj2D(float *out, const float *in) const (0x446320). Camera thread, 2026-10-11.
#include "cam.h"

// 0x446320 (thiscall, two stack args): the point in (3D, its z is read) to the screen point out.
// Ortho (flags bit 0): out = (sx * in0, -(sy * in1)). Perspective: d = max(0.001, in2) (maxss: the second operand wins
// on NaN), k = focal / d, out = (in0 * k, -(in1 * k * sy)). The sign is flipped after the multiply: the asm barrier
// keeps LLVM from folding the flip into the multiply (for a NaN result the sign would come out differently).
static THISCALL void ZCAMERA_Proj2D(u8 *self, float *out, const float *in) {
  if (at<u8>(self, 0x48) & 1) {
    out[0] = at<float>(self, 0x3c) * in[0];
    float v = at<float>(self, 0x40) * in[1];
    asm("" : "+x"(v));
    out[1] = bitsf(fbits(v) ^ 0x80000000u);
  } else {
    const float K = bitsf(0x3a83126fu);   // 0x67d9fc: 0.001
    float d = (K > in[2]) ? K : in[2];
    float k = at<float>(self, 0x58) / d;
    out[0] = in[0] * k;
    float v = in[1] * k;
    v = v * at<float>(self, 0x40);
    asm("" : "+x"(v));
    out[1] = bitsf(fbits(v) ^ 0x80000000u);
  }
}
PCREG(446320, ZCAMERA_Proj2D);
