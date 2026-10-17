// batch252.cpp - ZFFHERO::CanOperateObject(CAction*, P12, P10, F14) (inline-ladder thread, 2026-10-11).
// PARTIAL: cases 0 and 1 (a+0x48 == 0 or 1) are ported here; every other step calls the ORIGINAL exe function (ext_58c450).
// Batch 251 (case 1) and batch 252 (case 0) are verified separately; each spec fixes the step.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" bool THISCALL ext_58c450(void *self, u32 a, u32 p12, u32 p10, u32 f14);   // the original function (other cases)
extern "C" bool THISCALL ext_58c150(void *self, u32 a, float *mat, float *pos);      // CalcObjectsMatPos (batch 249)
extern "C" void FASTCALL ext_43e920(float *dst, const float *src, const float *a);   // PSVECSubtract
extern "C" void FASTCALL ext_441a60(float *vec, const float *mat);                  // vmtmul (in place)
extern "C" float FASTCALL ext_4e0870(const float *a, const float *b);               // vdist (ST0)

// 0x58c450 CanOperateObject.
// Case 0 (a+0x48 == 0): F14 set: F84 = P10 (3 floats) (the matrix copy to F+0xbc is not observable and is not made);
//   else CalcObjectsMatPos(a, F+0xc0, F+0x84), false when it fails.
//   F90 = F84 - (hero+0x886) (PSVECSubtract); vmtmul(F90, hero+0x892).
//   True when -200.0 < F90[1] < 200.0 and F90[0]^2 + F90[2]^2 < 5625.0 (NaN fails each compare), else false.
// Case 1 (a+0x48 == 1): A, B from obj slot 0x80(A, B); D, C from hero slot 0x80(D, C); true when 100.0 > vdist(C, B).
static bool THISCALL heroCanOperateObject(u8 *self, u8 *a, u32 p12, u32 p10, u32 f14) {
  u32 step = U32(a, 0x48);
  if (step == 0) {
    float F84[3], F90[3];
    float mat[8];
    if (f14 & 0xff) {
      const float *P10 = (const float *)(unsigned long)p10;
      F84[0] = P10[0];
      F84[1] = P10[1];
      F84[2] = P10[2];
    } else {
      if (!ext_58c150(self, (u32)(unsigned long)a, mat, F84))
        return false;
    }
    ext_43e920(F90, F84, (const float *)(self + 0x886));
    ext_441a60(F90, (const float *)(self + 0x892));
    float y = F90[1];
    if (!(y > -200.0f))
      return false;
    if (!(200.0f > y))
      return false;
    float s = F90[0] * F90[0];
    s = s + F90[2] * F90[2];
    return 5625.0f > s;
  }
  if (step == 1) {
    u8 *obj = (u8 *)U32(a, 0x44);
    float A[3], B[3], C[3], D[3];
    vcall<void>(obj, 0x80, A, B);
    vcall<void>(self, 0x80, D, C);
    float d = ext_4e0870(C, B);
    return 100.0f > d;
  }
  return ext_58c450(self, (u32)(unsigned long)a, p12, p10, f14);
}
PCREG(58c450, heroCanOperateObject);
