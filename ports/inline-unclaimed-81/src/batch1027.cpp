// batch1027.cpp - area 81, batch 1027: 0x5457f0 (the ray test), fastcall (this in ecx, E in edx; a, b, c, d, e on the stack), ret 0x14, returns the bool in al.
// The exe leaves a stray word on the stack on every path past the t computation (the push ecx before the 0x443ef0 call is not popped: that callee pops only
// its own argument). Its exits pop edi (which takes the stray word, the bits of t) and esi (which takes the caller's edi). The asm wrapper reproduces that:
// it runs the cdecl core, then on the flagged path sets esi = the caller's edi and edi = the bits of t, and otherwise restores both. Stand-ins (GUESS):
// 0x43e920 (fastcall, one stack argument; writes a vector to ecx), 0x443ef0 (thiscall, one argument), 0x4e0d00 (thiscall, one float argument), 0x547430
// (thiscall, no arguments). The sqrt at 0x634d7c is hooked by sqrtsd on the exe side; the port uses an inline sqrtsd.
#include "ff.h"

extern "C" void __attribute__((fastcall)) ext_43e920(void *ecx, void *edx, void *a2);   // GUESS (stood in)
extern "C" void THISCALL ext_443ef0(void *self, u32 a);                                   // GUESS (stood in)
extern "C" void THISCALL ext_4e0d00(void *self, float f);                                 // GUESS (stood in)
extern "C" void THISCALL ext_547430(void *self);                                          // GUESS (stood in)

extern "C" volatile u32 rayTPost = 0;   // set after the t computation (the stray word is on the stack from here on)
extern "C" volatile u32 rayTBits = 0;   // bits of t (the stray word)

static inline double sqrtsd(double x) {
  double r;
  __asm__("sqrtsd %1, %0" : "=x"(r) : "x"(x));
  return r;
}

// The cdecl core (the stack-pass-through of the arguments is done by the wrapper below).
extern "C" u8 rayTestCore(u8 *self, u8 *E, u32 aArg, u32 bArg, u32 cArg, u32 dArg, u32 eArg) {
  rayTPost = 0;
  float V1[3], V2[3];
  ext_43e920(V1, self, E);
  ext_43e920(V2, (void *)aArg, E);
  float A0 = V2[0], A1 = V2[1], A2 = V2[2];
  float sA = ((A0 * A0) + (A1 * A1)) + (A2 * A2);
  float D = ((V1[0] * A0) + (V1[1] * A1)) + (V1[2] * A2);
  *(float *)bArg = D;
  if (0.0f > D)
    return 0;
  if (D > sA)
    return 0;
  float t = D / sA;
  *(float *)bArg = t;
  rayTBits = fbits(t);
  rayTPost = 1;
  float scr[4];
  ext_443ef0(scr, (u32)V2);
  ext_43e920((void *)eArg, &V1[2], self);
  float *e = (float *)eArg;
  float E0 = e[0], E1 = e[1], E2 = e[2];
  float se = ((E0 * E0) + (E1 * E1)) + (E2 * E2);
  float cc = *(float *)cArg;
  if (se > cc * cc)
    return 0;
  float r = (float)sqrtsd((double)se);
  *(float *)dArg = r;
  if (r > 0.000000999999997f)
    ext_4e0d00((void *)eArg, 1.0f / r);
  else
    ext_547430((void *)eArg);
  return 1;
}

// The wrapper: fastcall entry (ecx = this, edx = E, five stack arguments), cdecl call of the core, then the exit state the exe leaves.
__asm__(
    ".globl rayTestWrapper\n"
    "rayTestWrapper:\n"
    "  pushl %esi\n"
    "  pushl %edi\n"
    "  pushl 0x1c(%esp)\n"
    "  pushl 0x1c(%esp)\n"
    "  pushl 0x1c(%esp)\n"
    "  pushl 0x1c(%esp)\n"
    "  pushl 0x1c(%esp)\n"
    "  pushl %edx\n"
    "  pushl %ecx\n"
    "  call rayTestCore\n"
    "  addl $28, %esp\n"
    "  cmpl $0, rayTPost\n"
    "  je 1f\n"
    "  movl (%esp), %esi\n"
    "  movl rayTBits, %edi\n"
    "  addl $8, %esp\n"
    "  ret $0x14\n"
    "1:\n"
    "  popl %edi\n"
    "  popl %esi\n"
    "  ret $0x14\n");
extern "C" void rayTestWrapper();
PCREG(5457f0, rayTestWrapper);
