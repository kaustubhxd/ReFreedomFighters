// batch1022.cpp - area 81, batch 1022: ZFFActorActionThrow::Update(), 0x5eb8c0, thiscall, no arguments, plain ret (void). Cookie check not reproduced.
// The CRT sqrt at 0x634d7c is hooked in the harness by a sqrtsd stub; the port uses an inline sqrtsd. Stand-ins (GUESS): 0x43e920 (fastcall, one stack
// argument; writes a vector to ecx), 0x451890 and 0x4e0d00 (thiscall, one float argument), 0x44c840 (thiscall, no arguments, returns a float in st0),
// 0x43e8e0 (fastcall, one stack argument). The kind test: this's slot 4 gives 0x12 (then m's slot 0x508) or else 0x13 (m's slot 0x50c); other kinds
// are not reached here and are trapped.
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define W32(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern "C" void __attribute__((fastcall)) ext_43e920(void *ecx, void *edx, void *a2);   // GUESS (stood in)
extern "C" void THISCALL ext_451890(void *self, float f);                                 // GUESS (stood in)
extern "C" void THISCALL ext_4e0d00(void *self, float f);                                 // GUESS (stood in)
extern "C" float THISCALL ext_44c840(void *self);                                         // GUESS (stood in)
extern "C" void __attribute__((fastcall)) ext_43e8e0(void *ecx, void *edx, void *a2);     // GUESS (stood in)

// The CRT sqrt of a double: sqrtsd (the exe's 0x634d7c, hooked to the same instruction in the harness).
static inline double sqrtsd(double x) {
  double r;
  __asm__("sqrtsd %1, %0" : "=x"(r) : "x"(x));
  return r;
}

// 0x5eb8c0 ZFFActorActionThrow::Update().
static void THISCALL actorActionThrowUpdate(u8 *self) {
  u8 *sys = *(u8 **)0x70039c;
  if (self[0x14])
    return;
  int n = (int)(*(float *)(self + 0x10) * 1024.0f);
  if ((int)D(sys, 0x40) < n)
    return;
  self[0x14] = 1;
  u8 *m = (u8 *)D(self, 0x8);
  u32 K1 = vcall<u32>(self, 0x4);
  u8 *x;
  if (K1 == 0x12) {
    x = (u8 *)vcall<u32>(m, 0x508);
  } else {
    u32 K2 = vcall<u32>(self, 0x4);
    if (K2 != 0x13)
      __builtin_trap();
    x = (u8 *)vcall<u32>(m, 0x50c);
  }
  float V[3] = {0.0f, 150.0f, -100.0f};
  vcall<void>(m, 0x84, (u32)V);
  *(float *)(x + 0x109) = V[0];
  *(float *)(x + 0x10d) = V[1];
  *(float *)(x + 0x111) = V[2];
  u8 *esi = self + 0x15;
  float vec[3];
  ext_43e920(vec, esi, V);
  float s = (vec[0] * vec[0] + vec[1] * vec[1]) + vec[2] * vec[2];
  float L = (float)sqrtsd((double)s);
  float q = L / 1000.0f;
  float f = (q * -0.5f) * q;
  ext_451890(vec, f);
  float t = 1.0f / q;
  ext_4e0d00(vec, t);
  float r44 = ext_44c840(vec);
  float mm = (1500.0f < r44) ? 1500.0f : r44;
  ext_4e0d00(vec, mm);
  ext_43e8e0(esi, V, vec);
  vcall<void>(x, 0x32c, (u32)esi);
  vcall<void>(x, 0x2d0, 3u, 0u);
  vcall<void>(x, 0x2d0, 0u, 0u);
  vcall<void>(x, 0x35c);
  u32 rr = vcall<u32>(m, 0x55c, (u32)x);
  if (rr)
    vcall<void>((void *)rr, 0x320);
}
PCREG(5eb8c0, actorActionThrowUpdate);
