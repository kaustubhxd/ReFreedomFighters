#include "ff.h"
// batch3527.cpp - area 35 claim 27 (docs/20-unclaimed-35.md): 0x44aed0 (residue name). Thiscall, four stack args (A, P, f2,
// V) with f2 written back in place (through its stack slot, taken by address), float return (st0), ret 0x10. The exe's SEH frame
// and /GS cookie check are not modelled. 0x634d7c is the sqrt thunk (harness handler). x87 subtraction at 53-bit precision.
// Stubbed in the harness: 0x460af0 (thiscall, three args), 0x460aa0 (thiscall, two args), 0x4e0870 (fastcall, float return),
// 0x633654 (no-op).

extern "C" void THISCALL ext_460af0(u8 *self, u32 a0, u32 a1, float a2);
extern "C" void THISCALL ext_460aa0(u8 *self, u32 a0, float a1);
extern "C" float FASTCALL ext_4e0870(u32 a0, u32 a1);

// 0x634d7c, sqrt thunk: double in xmm0, result in xmm0.
static double callSqrt(double x) {
  __asm__ volatile("call *%1"
                   : "+x"(x)
                   : "r"(0x634d7cu)
                   : "eax", "ecx", "edx", "memory", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7",
                     "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
  return x;
}

// 0x44aed0, ZSHAPE::GetSplinePosVelocity(...) (residue name).
float THISCALL guess44aed0(u8 *self, u32 A, u32 P, float f2, u32 Vp) {
  float *F = &f2;
  float *V = (float *)Vp;
  float *Pf = (float *)P;
  u8 *sub = self + 0x1c;
  u32 S10[3];
  float S0, s, t, r, rr, q, v, dot;

  ext_460af0(sub, A, P, *F);
  q = (V[0] * V[0] + V[1] * V[1]) + V[2] * V[2];
  s = (float)callSqrt((double)q);
  dot = ((Pf[1] * V[1]) + (V[0] * Pf[0])) + (Pf[2] * V[2]);
  S0 = *(float *)0x67d9fc;
  if (dot > 0.0f)
    S0 = *(float *)0x67fad8;
  t = *F - S0;
  if (0.0f > t)
    goto Lb000;

Lafa0:
  if (t > *(float *)0x678858)
    goto Lb110;
  ext_460aa0(sub, (u32)S10, t);
  r = ext_4e0870(A, (u32)S10);
  if (r > s)
    goto Lb026;
  S0 = S0 + S0;
  t = *F - S0;
  if (0.0f <= t)
    goto Lafa0;

Lb000:
  ext_460af0(sub, A, P, 0.0f);
  return 0.0f;

Lb110:
  ext_460af0(sub, A, P, 1.0f);
  return 1.0f;

Lb026:
  if (__builtin_fabs((double)S0) <= *(double *)0x67fad0)
    goto Lb0e2;

Lb050:
  v = *F - S0;
  *F = v;
  ext_460aa0(sub, (u32)S10, v);
  r = ext_4e0870(A, (u32)S10);
  rr = (float)((double)r - (double)s);
  if (*(double *)0x6785f8 > __builtin_fabs((double)rr))
    goto Lb0e2;
  if (rr > *(float *)0x6785d0)
    *F = *F + S0;
  S0 = S0 * *(float *)0x67a6ac;
  if (__builtin_fabs((double)S0) > *(double *)0x67fad0)
    goto Lb050;

Lb0e2:
  ext_460af0(sub, A, P, *F);
  return *F;
}
PCREG(44aed0, guess44aed0);
