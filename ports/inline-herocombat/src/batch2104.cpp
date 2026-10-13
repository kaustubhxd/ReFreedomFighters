// batch2104.cpp - wire-hero-combat thread, batch 2104: mpul 0x4de520, the matrix blend the ladder's
// ZFFHeroMovementGuide::Move uses (2026-10-13). docs/15 lists it as verified by the original pilot, whose source and JSON
// are not in the repo any more, so it is lifted again here from the exe.
#include "ff.h"

extern "C" void FASTCALL ext_4e0390(float *out, const float *a, const float *b, float t, float tlen);  // vector slerp (CRT atan, sin, cos)
extern "C" float THISCALL ext_44c840(float *v);                                    // vnorm, length in ST0
extern "C" void FASTCALL ext_446ee0(float *dst, const float *a, const float *b);   // vcross

static inline void copy9(float *out, const float *m) {
  for (int i = 0; i < 9; i++) ((u32 *)out)[i] = ((const u32 *)m)[i];
}

// 0x4de520 mpul(out, m0, m1, t): fastcall (ecx = out, edx = m0), stack m1 and t, ret 8. Blends two 3x3 frames (rows).
// t below 1/8192 -> m0; above 0.9998779296875 -> m1. When rows 0 and rows 1 of the two frames both have a positive dot
// product: rows 0 and 1 are lerped, row 2 = row 1 x row 0, rows 2 and 1 normalised, row 0 = row 2 x row 1. Otherwise row
// 0 is the slerp of the rows 0 (0x4e0390 with t, t), normalised (shorter than 1/8192 -> m0); row 1 lerped, normalised
// (same test); row 2 = row 1 x row 0, normalised (same test); row 1 = row 0 x row 2. Constants 0x679540, 0x68376c.
static void FASTCALL mpul(float *out, const float *m0, const float *m1, float t) {
  if (G(float, 0x679540) > t) {
    copy9(out, m0);
    return;
  }
  if (t > G(float, 0x68376c)) {
    copy9(out, m1);
    return;
  }
  float d0 = (m1[0] * m0[0] + m1[1] * m0[1]) + m1[2] * m0[2];
  if (d0 > 0.0f) {
    float d1 = (m0[4] * m1[4] + m0[3] * m1[3]) + m0[5] * m1[5];
    if (d1 > 0.0f) {
      for (int i = 0; i < 6; i++)
        out[i] = (m1[i] - m0[i]) * t + m0[i];
      ext_446ee0(out + 6, out + 3, out);
      ext_44c840(out + 6);
      ext_44c840(out + 3);
      ext_446ee0(out, out + 6, out + 3);
      return;
    }
  }
  ext_4e0390(out, m0, m1, t, t);
  float len = ext_44c840(out);
  if (G(float, 0x679540) > len) {
    copy9(out, m0);
    return;
  }
  for (int i = 3; i < 6; i++)
    out[i] = (m1[i] - m0[i]) * t + m0[i];
  len = ext_44c840(out + 3);
  if (G(float, 0x679540) > len) {
    copy9(out, m0);
    return;
  }
  ext_446ee0(out + 6, out + 3, out);
  len = ext_44c840(out + 6);
  if (G(float, 0x679540) > len) {
    copy9(out, m0);
    return;
  }
  ext_446ee0(out + 3, out, out + 6);
}
PCREG(4de520, mpul);
