// batch719.cpp - soldier AI, batch 719 (2026-10-11): CFFCoverList::CreateSpotsAlongSpline, cover spots along a spline.
// Walk the shape's length L in steps of 75: u = t / L, point and velocity from BasicShape::GetSplinePosVelocity (shape +0x1c),
// both moved to the shape's root frame (slots 0x84 point, 0x88 vector). The velocity is normalised (x87 precision) unless all
// three components are exactly zero (NaN counts as nonzero). A spot is then created with direction
// (-vz, vy, vx) and no check. The loop runs while L > t. Flag: shape slot 0x210 with 1.
#include "ff.h"

extern "C" void THISCALL ext_460af0(void *spline, float *pos, float *vel, float u);   // BasicShape::GetSplinePosVelocity
extern "C" void THISCALL ext_585a40(void *self, float *a, float *b, float *c, float *d, u32 check, u32 type, u32 flags);

// 0x586760 CFFCoverList::CreateSpotsAlongSpline(ZSHAPE* shape, CCoverSpot::eType type, bool flag) [medium].
static void THISCALL cover_CreateSpotsAlongSpline(u8 *self, u8 *shape, u32 type, u32 flag) {
  float L = *(float *)(shape + 0x20);
  if (L > 0.0f) {
    float t = 0.0f;
    do {
      float u = t / L;
      float pos[3], vel[3];
      ext_460af0(shape + 0x1c, pos, vel, u);
      vcall<void>(shape, 0x84, pos);
      vcall<void>(shape, 0x88, vel);
      if (!(vel[0] == 0.0f && vel[1] == 0.0f && vel[2] == 0.0f)) {   // skip only the all-zero vector (NaN counts as nonzero)
        long double s = (long double)vel[0] * vel[0] + (long double)vel[1] * vel[1] + (long double)vel[2] * vel[2];
        long double len = fsqrt_x87(s);
        long double inv = 1.0L / len;
        for (int k = 0; k < 3; k++)
          vel[k] = (float)((long double)vel[k] * inv);
      }
      float P[3] = {pos[0], pos[1], pos[2]};
      float D[3] = {-vel[2], vel[1], vel[0]};
      ext_585a40(self, P, pos, vel, D, 0, type, 0);
      t = t + 75.0f;                               // 0x680a8c
    } while (L > t);
  }
  if ((u8)flag)
    vcall<void>(shape, 0x210, 1);
}
PCREG(586760, cover_CreateSpotsAlongSpline);
