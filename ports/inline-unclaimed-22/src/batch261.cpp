// batch261.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch261"): the hero's close-combat
// movement speed (turn rate towards the target). Name from the GameCube name map (high); behaviour from the PC bytes.
#include "ff.h"

extern "C" void FASTCALL ext_43e920(float *out, const float *a, const float *b);   // PSVECSubtract (verified, inline-batch45)
extern "C" float THISCALL ext_488460(u8 *move);                                    // ZMovementBase::DeltaTime (verified, inline-batch45)
extern "C" void FASTCALL ext_4e0d00(float *v, float s);                             // vscalar (verified, inline-batch45)
extern "C" void FASTCALL ext_446ee0(float *out, const float *a, const float *b);   // vcross (verified, inline-batch45)

// acos through the exe's _libm_sse2_acos_precise thunk 0x634dbe (double in xmm0, result in xmm0).
static double acosExe(double d) {
  double out;
  asm volatile("movsd %[d], %%xmm0\n\t"
               "call *%[t]\n\t"
               "movsd %%xmm0, %[o]\n\t"
               : [o] "=m"(out)
               : [d] "m"(d), [t] "r"(0x634dbe)
               : "eax", "ecx", "edx", "xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7", "memory", "cc");
  return out;
}

// 0x5e18d0 ZFFHeroMovementCloseCombat::CalcNewSpeed(const float *dir, const float *pos, float *vel, float *rot) ret 0x10.
// this->vt[0x50](dir, pos, &fwd, &goal) (four words; the pops before the frame restore prove it); vel = goal - pos
// (PSVECSubtract), scaled by 1 / (DeltaTime * speed factor at render manager +0x54) (vscalar). side = dir x fwd (vcross);
// the angle between dir and fwd is acos of their dot product, 0 above 1.0 and pi below -1.0; rot = (0, angle / (DeltaTime
// * factor), 0), negated unless side.y > 0. The second division is x87 in the exe (st0 = DeltaTime * factor, fdivr); with
// float inputs and 53-bit precision the same value comes from double math.
static void THISCALL calcNewSpeed_5e18d0(u8 *self, const float *dir, const float *pos, float *vel, float *rot) {
  float fwd[3], goal[3], side[3];
  vcall<void>(self, 0x50, (u32)dir, (u32)pos, (u32)fwd, (u32)goal);
  ext_43e920(vel, goal, pos);
  float dt = ext_488460(self);
  ext_4e0d00(vel, 1.0f / (dt * *(float *)(*(u8 **)0x70039cu + 0x54)));
  ext_446ee0(side, dir, fwd);
  float dot = dir[1] * fwd[1] + dir[0] * fwd[0];
  dot = dot + dir[2] * fwd[2];
  float ang;
  if (dot > 1.0f) ang = 0.0f;
  else if (-1.0f > dot) ang = 3.14159274f;
  else ang = (float)acosExe((double)dot);
  float dt2 = ext_488460(self);
  float r = (float)((double)ang / ((double)dt2 * (double)*(float *)(*(u8 **)0x70039cu + 0x54)));
  if (!(side[1] > 0.0f)) r = -r;
  rot[0] = 0;
  rot[1] = r;
  rot[2] = 0;
}
PCREG(5e18d0, calcNewSpeed_5e18d0);
