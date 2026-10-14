// batch8821.cpp - wire-hit-parts (2026-10-15): IntersectTriangleAndLine 0x4e2560, the gateway run's exact lift (docs/19 part 2,
// gateway-run/results/run-2026-10-09-big.json), re-verified here at 1000 cases on seeds 1 and 2. One change: the flag is taken as a dword and
// its low byte tested (the gateway spec never passed a low byte other than 0 / 1, so the bool parameter passed there).
#include "ff.h"

bool FASTCALL IntersectTriangleAndLine(const float *O, const float *D, const float *V0,
                                       const float *V1, const float *V2, float &outT,
                                       u32 flag) {
  bool twoSided = (u8)flag != 0;   // the exe tests the argument's low byte (cmp byte [ebp+0x18], 0); a C++ bool would test bit 0 only
  const float kTol = bitsf(0x38d1b717);     // 9.999999747378752e-05 (at 0x68c730)
  const float kEps = bitsf(0x358637bd);     // 9.999999974752427e-07 (at 0x681370)
  const float kNegEps = bitsf(0xb58637bd);  // -9.999999974752427e-07 (at 0x6972c8)

  // edges e1 = V1 - V0, e2 = V2 - V0
  float e1x = V1[0] - V0[0];
  float e1y = V1[1] - V0[1];
  float e1z = V1[2] - V0[2];
  float e2x = V2[0] - V0[0];
  float e2y = V2[1] - V0[1];
  float e2z = V2[2] - V0[2];

  // P = D x e2
  float px = D[1] * e2z - D[2] * e2y;
  float py = D[2] * e2x - D[0] * e2z;
  float pz = D[0] * e2y - D[1] * e2x;

  // det = e1 . P
  float det = (py * e1y + px * e1x) + pz * e1z;

  if (!twoSided && det > 0.0f) return false;
  if (det > kNegEps && kEps > det) return false;

  // T = O - V0
  float tx = O[0] - V0[0];
  float ty = O[1] - V0[1];
  float tz = O[2] - V0[2];

  float uu = (ty * py + tx * px) + tz * pz;
  float lo = -(det * kTol);
  float b = det * kTol + det;

  if (det < 0.0f) {
    if (uu > lo) return false;
    if (b > uu) return false;
  } else {
    if (lo > uu) return false;
    if (uu > b) return false;
  }

  // Q = T x e1
  float qx = ty * e1z - tz * e1y;
  float qy = tz * e1x - tx * e1z;
  float qz = tx * e1y - ty * e1x;

  float vv = (D[0] * qx + D[1] * qy) + D[2] * qz;

  if (det < 0.0f) {
    if (vv > lo) return false;
  } else {
    if (lo > vv) return false;
  }

  float s = vv + uu;
  if (det < 0.0f) {
    if (b > s) return false;
  } else {
    if (s > b) return false;
  }

  float num = (qy * e2y + qx * e2x) + qz * e2z;
  outT = num / det;
  return true;
}

PCREG(4e2560, IntersectTriangleAndLine);
