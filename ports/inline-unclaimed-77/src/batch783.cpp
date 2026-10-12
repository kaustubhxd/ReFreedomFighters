// batch783.cpp - unclaimed-77 claim 13 (docs/20-unclaimed-77.md): CExplodeMolotov::CreateParticles(float*, float*, float*) (medium).
// Thiscall, three arguments, ret 12. Callees are stubbed in the harness (GUESS).
// (none: the exe's x87 stack is empty at return). The CRT security-cookie check is not reproduced.
#include "ff.h"

extern "C" void THISCALL ext_443ef0(void *T, float *C, float v);          // stubbed: writes T, ret 8
extern "C" void THISCALL ext_4e0d00(void *vec, float s);                   // stubbed: writes its vector, ret 4
extern "C" void THISCALL ext_451890(void *obj, float s);                   // stubbed: logs its argument, ret 4
extern "C" void THISCALL ext_4e0a10(void *vec);                            // stubbed: writes L, ret 0
extern "C" void FASTCALL ext_43e920(void *ecx, void *edx, void *arg);     // stubbed: copies T to L, ret 4
extern "C" void THISCALL ext_4e73b0(void *self, void *p68, float *L, u32 *S, float f1, float f2);  // stubbed, ret 20

// 0x582880, CExplodeMolotov::CreateParticles(float*, float*, float*) (medium).
static void THISCALL explodeMolotovCreateParticles(u8 *self, float *A, float *B, float *C) {
  u32 *a = (u32 *)A, *b = (u32 *)B, *c = (u32 *)C;
  *(u32 *)(self + 0x68) = a[0];
  *(u32 *)(self + 0x6c) = a[1];
  *(u32 *)(self + 0x70) = a[2];
  *(u32 *)(self + 0x74) = b[0];
  *(u32 *)(self + 0x78) = b[1];
  *(u32 *)(self + 0x7c) = b[2];
  u32 S[3] = {0u, 0xc4758000u, 0u};
  u32 *D = (u32 *)(self + 0x80);
  D[0] = c[0];
  D[1] = c[1];
  D[2] = c[2];

  float T[3];
  float L[3];
  // the dot product in the exe's own operand order (NaN inputs take the destination operand, so the C++ operand order matters):
  // v = -((B1*C1 + C0*B0) + B2*C2) * 1.125
  alignas(16) static const u32 kSignMask[4] = {0x80000000u, 0u, 0u, 0u};
  static const float k1125 = 1.125f;
  float v;
  __asm__ volatile(
      "movss 4(%[b]), %%xmm1\n\t"
      "mulss 4(%[c]), %%xmm1\n\t"
      "movss (%[c]), %%xmm0\n\t"
      "mulss (%[b]), %%xmm0\n\t"
      "addss %%xmm0, %%xmm1\n\t"
      "movss 8(%[b]), %%xmm0\n\t"
      "mulss 8(%[c]), %%xmm0\n\t"
      "addss %%xmm0, %%xmm1\n\t"
      "xorps %[mask], %%xmm1\n\t"
      "mulss %[k], %%xmm1\n\t"
      "movss %%xmm1, %[out]\n\t"
      : [out] "=m"(v)
      : [b] "r"(B), [c] "r"(C), [mask] "m"(kSignMask[0]), [k] "m"(k1125)
      : "xmm0", "xmm1", "memory");
  ext_443ef0(T, C, v);

  bool allzero = (T[0] == 0.0f) && (T[1] == 0.0f) && (T[2] == 0.0f);
  float x1 = 0.0f;
  double len = 0.0;
  if (!allzero) {
    double s = (double)T[0] * (double)T[0];
    s = s + (double)T[1] * (double)T[1];
    s = s + (double)T[2] * (double)T[2];
    __asm__("sqrtsd %1, %0" : "=x"(len) : "x"(s));   // correctly rounded double sqrt, as fsqrt at 53-bit precision
    double r = 1.0 / len;
    T[0] = (float)((double)T[0] * r);
    T[1] = (float)((double)T[1] * r);
    T[2] = (float)((double)T[2] * r);
    x1 = (float)len;   // the last fstp pops len (the third fmulp consumes r), so [ebp-0x2c] = (float)len and the x87 stack ends empty
  }
  float m = (800.0f < x1) ? 800.0f : x1;
  ext_4e0d00(T, m);
  ext_451890(self + 0x68, 5.0f);

  for (u32 k = 0; k < 5; k++) {
    u8 *ecxThis = self + 0x9d + 0x2cu * k;
    ext_4e0a10(L);
    void *rm = *(void **)0x70039c;
    void **vt = *(void ***)rm;
    float R = ((float (THISCALL *)(void *, u32, u32))(*(void **)((u8 *)vt + 0x1c0)))(rm, 0x6ab6d4u, 0x3bbu);
    float g = R * 0.5f;
    float h = g * m;
    ext_4e0d00(L, h);
    ext_43e920(L, T, L);
    float f2 = (float)(*(s32 *)((u8 *)rm + 0x40)) * 0.0009765625f;
    ext_4e73b0(ecxThis, self + 0x68, L, S, 0.5f, f2);
    self[0x1c9 + k] = 1;
  }
}
PCREG(582880, explodeMolotovCreateParticles);
