// batch6518.cpp - unclaimed-65: batch 18 (docs/20-unclaimed-65.md, claim 18, final). ZMovementBaseMove::GetActiveAnim, returns float
// (st0); ret 0x14 (the second argument is unused by the original).
#include "ff.h"

extern "C" void FASTCALL ext_43e920(float *out, float *in1, float *in2);  // out = in1 - in2 (fastcall; in2 on the stack, ret 4)
extern "C" void FASTCALL ext_441a60(float *vec, float *matrix);            // 3x3 matrix times vec, written back (fastcall, plain ret)

typedef void(THISCALL *Slot44Fn)(u8 *self, float a, float b);

// the sqrt thunk: double in xmm0, double out in xmm0
static double sqrtThunk(double x) {
  double r;
  asm volatile("call *%[t]\n\t"
               : "=x"(r)
               : [t] "r"(0x634d7c), "0"(x)
               : "eax", "ecx", "edx", "memory", "cc");
  return r;
}

// the _CIfmod thunk: st0 = 1.0, st1 = d; the thunk leaves st0 = d mod 1.0 with one pop; stored as a float
static float fmodOne(double d) {
  float out;
  asm volatile("fldl %[d]\n\t"
               "fld1\n\t"
               "call *%[t]\n\t"
               "fstps %[o]\n\t"
               : [o] "=m"(out)
               : [d] "m"(d), [t] "r"(0x634dc4)
               : "eax", "memory", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)", "cc");
  return out;
}

// 0x4884b0, ZMovementBaseMove::GetActiveAnim (residue 15). See docs/20-unclaimed-65.md (claim 18, final).
static float THISCALL movementBaseMoveGetActiveAnim(u8 *self, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  (void)a1;
  u8 *P = *(u8 **)(self + 0x21);
  if (!P) return 0.0f;
  *(u32 *)a0 = *(u32 *)P;
  float v0 = *(float *)(P + 0xc);
  float v1 = 0.0f;
  float v2 = *(float *)(P + 0x14);
  if (!(v0 == 0.0f && v2 == 0.0f)) {
    const long double x = v0, y = v1, z = v2;
    long double s = x * x + y * y + z * z;
    long double len;
    asm("fsqrt" : "=t"(len) : "0"(s));
    const long double r = 1.0L / len;
    v0 = (float)(x * r);
    v1 = (float)(y * r);
    v2 = (float)(z * r);
    const float lenF = (float)len;
    if (!(lenF == 0.0f)) {
      float T[3];
      ext_43e920(T, (float *)a4, (float *)a2);
      ext_441a60(T, (float *)a3);
      const float t = (T[0] * T[0] + 0.0f) + T[2] * T[2];
      const double rr = sqrtThunk((double)t);
      const float q = (float)rr / lenF;
      const float old = *(float *)(self + 0xc);
      const float newv = old + q;
      ((Slot44Fn)(*(const u32 *)(*(const u32 *)self + 0x44)))(self, old, newv);
      *(float *)(self + 0xc) = *(float *)(self + 0xc) + q;
    }
  }
  const double d = (double)*(float *)(self + 0xc);
  const float f = fmodOne(d);
  *(float *)(self + 0xc) = f;
  if (0.0f > f) *(float *)(self + 0xc) = f + 1.0f;
  return *(float *)(self + 0xc);
}
PCREG(4884b0, movementBaseMoveGetActiveAnim);
