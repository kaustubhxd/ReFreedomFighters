// batch58.cpp - climb and ladder trees, inline session batch 58: ZFFHeroMovementClimb::GetAnims and
// ZFFHeroMovementGuide::CalculateLadder.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vcallUU)(void *self, u32 a);

// 0x5e4380 ZFFHeroMovementClimb::GetAnims(), thiscall. Looks up the eight climb animations by name with slot 0x58.
// Both 50-unit climbs (+0x1e and +0x22) get "Climb_Wall_50_Right"; there is no left one in the exe.
static void THISCALL climbGetAnims(u8 *self) {
  static const u32 names[8] = {0x6b7c14u, 0x6b7c14u, 0x6b7c28u, 0x6b7c3cu, 0x6b7c54u, 0x6b7c68u, 0x6b7c80u, 0x6b7c94u};
  for (int i = 0; i < 8; ++i)
    *(u32 *)(self + 0x1e + 4 * i) = ((vcallUU)VT(self, 0x58))(self, names[i]);
}
PCREG(5e4380, climbGetAnims);


// The spline samplers GetSplinePos (0x4604f0), GetSplineVelocity (0x460570) and GetSplinePosVelocity (0x460af0)
// were lifted in batches 21, 40 and 41; CalculateLadder calls them as exe code.
typedef void(THISCALL *vcallVP)(void *self, void *a);
typedef void (*assertFn)(void);
extern "C" void THISCALL ext_460af0(u8 *shape, float *pos, float *vel, float t);
extern "C" void THISCALL ext_4e09b0(float *v);   // vneg

// The inline normalise (x87 under 53-bit control, so double arithmetic), skipped when the vector is zero.
static void normalizeNonZero(float *v) {
  if (v[0] == 0.0f && v[1] == 0.0f && v[2] == 0.0f)
    return;
  double x = v[0], y = v[1], z = v[2];
  double len = crt::sqrt(((x * x) + (y * y)) + (z * z));
  double inv = 1.0 / len;
  v[0] = (float)(x * inv);
  v[1] = (float)(y * inv);
  v[2] = (float)(z * inv);
}

// fmod through the exe's import slot for _CIfmod (x87 arguments, result in ST0).
static double crtFmod(double a, double b) {
  double r;
  __asm__ volatile("fldl %1\n\tfldl %2\n\tcall *0x676358\n\tfstpl %0" : "=m"(r) : "m"(a), "m"(b) : "eax", "ecx", "edx", "memory", "cc");
  return r;
}

// Sample the guide shape (+0x550, spline at +0x1c, world transforms slot 0x84 for points and 0x88 for directions).
static void sampleLadder(u8 *self, float *pos, float *vel, float t) {
  ext_460af0(*(u8 **)(self + 0x550) + 0x1c, pos, vel, t);
  u8 *sh = *(u8 **)(self + 0x550);
  ((vcallVP)VT(sh, 0x84))(sh, pos);
  sh = *(u8 **)(self + 0x550);
  ((vcallVP)VT(sh, 0x88))(sh, vel);
  normalizeNonZero(vel);
}

// 0x5e1c50 ZFFHeroMovementGuide::CalculateLadder(), thiscall. Samples the ladder shape at 0 (bottom), 1 (top) and 0.5,
// lowers the two ends by 110 minus the hero's height value (+0x43d), and orders them so the second is the higher
// (swapping both points and directions; otherwise both directions are negated). The climb length above 100 is
// rounded down to whole 100s with fmod. Writes the start (mid x, top - rounded length, mid z) to +0x554, the end
// (mid x, top, mid z) to +0x560 and the top's direction to +0x56c.
static void THISCALL calculateLadder(u8 *self) {
  if (*(u32 *)(self + 0x550) == 0) {
    assertFn f = G(assertFn, 0x7003b0);
    if (f)
      f();
    else
      __builtin_trap();
  }
  float p0[3], v0[3], p1[3], v1[3], p2[3], v2[3];
  sampleLadder(self, p0, v0, 0.0f);
  p0[1] = *(float *)(*(u8 **)(self + 4) + 0x43d) - 110.0f + p0[1];
  sampleLadder(self, p1, v1, 1.0f);
  float y0 = p0[1];
  p1[1] = *(float *)(*(u8 **)(self + 4) + 0x43d) - 110.0f + p1[1];
  if (y0 > p1[1]) {
    for (int a = 0; a < 3; ++a) {
      float tp = p0[a], tv = v0[a];
      p0[a] = p1[a];
      p1[a] = tp;
      v0[a] = v1[a];
      v1[a] = tv;
    }
  } else {
    ext_4e09b0(v1);
    ext_4e09b0(v0);
  }
  sampleLadder(self, p2, v2, 0.5f);
  double d = (double)(p1[1] - p0[1] - 100.0f);
  double r = crtFmod(d, G(double, 0x693d60));
  float len = (float)(d - r) + 100.0f;
  *(float *)(self + 0x554) = p2[0];
  *(float *)(self + 0x558) = p1[1] - len;
  *(float *)(self + 0x55c) = p2[2];
  *(float *)(self + 0x560) = p2[0];
  *(float *)(self + 0x564) = p1[1];
  *(float *)(self + 0x568) = p2[2];
  *(float *)(self + 0x56c) = v1[0];
  *(float *)(self + 0x570) = v1[1];
  *(float *)(self + 0x574) = v1[2];
}
PCREG(5e1c50, calculateLadder);
