// batch50000.cpp - cascade u3, tier H, batch 50000: 0x463da0 (split a float interval by a step and advance two transform blocks).
#include "ff.h"

extern "C" void THISCALL ext_463a30(u8 *self, u8 *a, u8 *b, float t);   // ret 0xc
extern "C" void FASTCALL ext_441940(u8 *a, u8 *b);
extern "C" void FASTCALL ext_4de480(u8 *a, u8 *b);
extern "C" void THISCALL ext_4de7a0(u8 *self);
extern "C" void FASTCALL ext_633654(u32 cookie);                         // /GS check
extern "C" void ext_634dc4();                                            // x87 CRT routine (st0 = divisor, st1 = dividend; fmod)

// 0x463da0, thiscall(float a, float b) ret 8, /GS: p = [[this+0x1c]+0x14]; s = p[0x20]; step = (float)(int)p[0xc]; L = p[0x18];
// ia = cvtt(s*a), ib = cvtt(s*b), rem = b - (float)ib * step.
//  L > b and ia == ib: ext_463a30(this, this+0x24, this+0x48, rem);
//  b >= L: ext_463a30(..., L == step ? L : (float)fmod(L, step)); then always calls this slot 0x340(0, 1);
//  otherwise (b < L or NaN): ext_463a30(..., step), resets this+0x82 via 4de7a0, clears +0xa6/+0xaa/+0xae, and for each of ib-(ia+1) full steps
//  builds a block with ext_463a30(&m, &v, step) and applies ext_441940(this+0x48, &v), ext_4de480(this+0x24, &m); then ext_463a30(..., rem).
static void THISCALL fn463da0(u8 *self, float a, float b) {
  u8 *p = *(u8 **)(*(u8 **)(self + 0x1c) + 0x14);
  float s = *(float *)(p + 0x20);
  float step = (float)*(s32 *)(p + 0xc);
  float L = *(float *)(p + 0x18);
  s32 ib = _mm_cvttss_si32(_mm_set_ss(s * b));
  s32 ia = _mm_cvttss_si32(_mm_set_ss(s * a));
  float rem = b - (float)ib * step;
  u8 *m1 = self + 0x24;
  u8 *m2 = self + 0x48;
  if (L > b && ib == ia) {
    ext_463a30(self, m1, m2, rem);
    ext_633654(0);
    return;
  }
  if (b >= L) {
    float t;
    if (L == step) {
      t = L;
    } else {
      double ld = (double)L, sd = (double)step;
      __asm__ volatile("fldl %1\n\tfldl %2\n\tcall ext_634dc4\n\tfstps %0" : "=m"(t) : "m"(ld), "m"(sd) : "eax", "ecx", "edx", "memory", "cc", "st", "st(1)", "st(2)", "st(3)");
    }
    ext_463a30(self, m1, m2, t);
    vcall<void>(self, 0x340, 0, 1);
    ext_633654(0);
    return;
  }
  ext_463a30(self, m1, m2, step);
  ext_4de7a0(self + 0x82);
  *(u32 *)(self + 0xa6) = 0;
  *(u32 *)(self + 0xaa) = 0;
  *(u32 *)(self + 0xae) = 0;
  s32 k = ia + 1;
  if (k < ib) {
    u8 v[12], m[0x24];
    ext_463a30(self, m, v, step);
    s32 n = ib - k;
    do {
      ext_441940(m2, v);
      ext_4de480(m1, m);
    } while (--n);
  }
  ext_463a30(self, m1, m2, rem);
  ext_633654(0);
}
PCREG(463da0, fn463da0);
