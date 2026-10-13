// batch1106.cpp - collision thread, batch 1106: ZCollisionBox::MovingSphereCollision (0x4ea390).
#include "ff.h"

extern "C" void FASTCALL ext_43e960(float *v, const float *a);                     // v -= a (x87)
extern "C" void FASTCALL ext_441940(float *v, const float *a);                     // PSVECAdd
extern "C" void FASTCALL ext_43e920(float *dst, const float *a, const float *b);   // PSVECSubtract
extern "C" void THISCALL port_4e8ed0(u8 *self);                                     // CalcStripsBoundInfo (batch 1105)
extern "C" u8 THISCALL port_4eaa80(u8 *self, u8 *impact, float *pos, const float *fallback, const float *scale);

// Box-local transform: lane j = (v0*m[6+j]... is vmmul; this is the transpose form the exe inlines:
// out = ((v0*m[6] + v1*m[7]) + v2*m[8], (v0*m[3] + v1*m[4]) + v2*m[5], (v0*m[0] + v1*m[1]) + v2*m[2]).
static inline void toLocal(float *out, float x, float y, float z, const float *m) {
  out[0] = ((x * m[6]) + (y * m[7])) + (z * m[8]);
  out[1] = ((y * m[4]) + (x * m[3])) + (z * m[5]);
  out[2] = ((x * m[0]) + (y * m[1])) + (z * m[2]);
}

// 0x4ea390 ZCollisionBox::MovingSphereCollision(ZSphereImpact *impact, const float *oldPos, float *newPos,
// const float *extent, float *vel, bool), thiscall, ret 0x18, always returns al = 0 (the bool is unused).
// ZCollisionBox fields used: +0 ground geom of the last floor hit, +4 its render-manager handle, +0x14 box array
// (built on first use), +0x18 3x3 rotation, +0x3c origin, +0x48 half size, +0x64 own dt (0 = use the engine's).
// 1. Clamps newPos (relative to the origin) so newPos +- extent stays inside +-half size, per axis.
// 2. Takes old and new positions into box space, and pushes the new one out of all triangles
//    (PushOutOfAllTris, scale = the extent in box space, fallback = the old position).
// 3. newPos = the result back in world space; vel = (result - old) / (dt * 60) in world space, with its vertical part
//    kept between 0 and the intended (newPos - oldPos).y / (dt * 60), and its horizontal length capped at the
//    intended one.
// 4. +4 = render-manager slot 0x50 (+0) when a floor was hit, else 0.
static u8 THISCALL movingSphereCollision(u8 *self, u8 *impact, const float *oldPos, float *newPos, const float *ext,
                                         float *vel, u8 flag) {
  (void)flag;
  const float *m = (const float *)(self + 0x18);
  const float *org = (const float *)(self + 0x3c);
  const float *half = (const float *)(self + 0x48);
  ext_43e960(newPos, org);
  for (int i = 0; i < 3; i++) {
    float h = half[i];
    if (ext[i] + newPos[i] > h)
      newPos[i] = h - ext[i];
    float e = ext[i];
    h = half[i];
    if (bitsf(fbits(h) ^ 0x80000000u) > newPos[i] - e)
      newPos[i] = e - h;
  }
  ext_441940(newPos, org);
  *(u32 *)self = 0;
  float mv0 = newPos[0] - oldPos[0];
  float mv1 = newPos[1] - oldPos[1];
  float mv2 = newPos[2] - oldPos[2];
  impact[8] = 0;
  float oL[3], nL[3], sL[3], dL[3];
  toLocal(oL, oldPos[0] - org[0], oldPos[1] - org[1], oldPos[2] - org[2], m);
  toLocal(nL, newPos[0] - org[0], newPos[1] - org[1], newPos[2] - org[2], m);
  ext_43e920(dL, nL, oL);
  {
    float x = ext[0], y = ext[1], z = ext[2];
    sL[0] = ((x * m[6]) + (y * m[7])) + (m[8] * z);
    sL[1] = ((m[3] * x) + (m[4] * y)) + (m[5] * z);
    sL[2] = ((x * m[0]) + (y * m[1])) + (m[2] * z);
  }
  if (*(u32 *)(self + 0x14) == 0)
    port_4e8ed0(self);
  port_4eaa80(self, impact, nL, oL, sL);
  float dt = *(float *)(self + 0x64);
  if (dt == 0.0f)
    dt = *(float *)(G(u8 *, 0x70039c) + 0x48);
  dt = dt * 60.0f;
  float inv = 0.0f;
  if (dt != 0.0f)
    inv = 1.0f / dt;
  mv0 = mv0 * inv;
  mv1 = mv1 * inv;
  mv2 = mv2 * inv;
  float a0 = nL[0], a1 = nL[1], a2 = nL[2];
  float d0 = (a0 - oL[0]) * inv, d1 = (a1 - oL[1]) * inv, d2 = (a2 - oL[2]) * inv;
  newPos[0] = ((a0 * m[6]) + (m[3] * a1)) + (a2 * m[0]);
  float r1 = ((a0 * m[7]) + (m[4] * a1)) + (a2 * m[1]);
  newPos[1] = r1;
  float r2 = ((a0 * m[8]) + (m[5] * a1)) + (a2 * m[2]);
  newPos[2] = r2;
  newPos[0] = newPos[0] + org[0];
  newPos[1] = r1 + org[1];
  newPos[2] = r2 + org[2];
  vel[0] = ((d0 * m[6]) + (m[3] * d1)) + (d2 * m[0]);
  vel[1] = ((d0 * m[7]) + (m[4] * d1)) + (d2 * m[1]);
  float v2 = ((d0 * m[8]) + (m[5] * d1)) + (d2 * m[2]);
  float vy = vel[1];
  vel[2] = v2;
  if (0.0f > mv1) {
    if (mv1 > vy)
      vel[1] = mv1;
    else if (vy > 0.0f)
      vel[1] = 0.0f;
  } else {
    if (vy > mv1)
      vel[1] = mv1;
    else if (0.0f > vy)
      vel[1] = 0.0f;
  }
  float vx = vel[0];
  float want = (float)crt::sqrt((double)(((mv0 * mv0) + 0.0f) + (mv2 * mv2)));
  float got = (float)crt::sqrt((double)(((vx * vx) + 0.0f) + (v2 * v2)));
  if (got > want) {
    float s = want / got;
    vel[0] = vx * s;
    vel[2] = v2 * s;
  }
  u32 g = *(u32 *)self;
  *(u32 *)(self + 4) = 0;
  if (g) {
    u8 *rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    *(u32 *)(self + 4) = vcall<u32>(rm, 0x50, g);
  }
  return 0;
}
PCREG(4ea390, movingSphereCollision);
