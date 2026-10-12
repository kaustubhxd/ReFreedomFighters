// batch1021.cpp - area 81, batch 1021: ZFFHeroMovementCloseCombat::FrameUpdate(), 0x5e2020, thiscall, no arguments, plain ret. Cookie check not
// reproduced (no SEH frame). The CRT sqrt at 0x634d7c (xmm0 in and out) is hooked in the harness by a sqrtsd stub; the port uses __builtin_sqrt (the same
// correctly rounded double sqrt). Stand-ins (GUESS): 0x43e920 (fastcall, one stack argument; writes a vector to ecx), 0x4e09e0 (thiscall, no arguments),
// 0x4de040 (thiscall, one argument). The frame array fr is esp after the prologue: exe operands esp+X taken after a push are fr+X-4 (accounted for below).
// The exe stores an int into esp+0x10 (the length slot) after pushing, so the length is overwritten before the final compare.
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern "C" void __attribute__((fastcall)) ext_43e920(void *ecx, void *edx, void *a2);   // GUESS (stood in)
extern "C" void THISCALL ext_4e09e0(void *self);                                         // GUESS (stood in)
extern "C" void THISCALL ext_4de040(void *self, u32 a);                                  // GUESS (stood in)

// 0x5e236c: the gate tail, refreshes the flag at this+0x5ac.
static void gateTail(u8 *self) {
  float a = *(float *)(self + 0x5ad) * 1024.0f;
  D(self, 0x5d2) = D(self, 0x5b6);
  u8 *sys = *(u8 **)0x70039c;
  u32 edx = D(sys, 0x40) - (u32)(int)a;
  int b = (int)(*(float *)(self + 0x5a0) * 1024.0f);
  if ((int)edx <= b)
    return;
  *(u8 *)(self + 0x5ac) = 0;
}

// The CRT sqrt of a double: sqrtsd (the same instruction the exe's 0x634d7c runs on this path).
static inline double sqrtsd(double x) {
  double r;
  __asm__("sqrtsd %1, %0" : "=x"(r) : "x"(x));
  return r;
}

// 0x5e2020 ZFFHeroMovementCloseCombat::FrameUpdate().
static void THISCALL heroCloseCombatFrameUpdate(u8 *self) {
  u8 fr[0xb4];
  u8 *sys = *(u8 **)0x70039c;
  if (*(u8 *)(self + 0x5b5)) {
    gateTail(self);
    return;
  }
  u32 edx = D(sys, 0x40) - (u32)(int)(*(float *)(self + 0x5ad) * 1024.0f);
  if ((int)edx < (int)(*(float *)(self + 0x59c) * 1024.0f)) {
    gateTail(self);
    return;
  }
  u32 P = D(self, 0x5b6);
  *(u8 *)(self + 0x5b5) = 1;
  u8 *rm = (u8 *)D(sys, 0x9b);
  u8 *R = (u8 *)vcall<u32>(rm, 0x58, P);
  if (!R)
    return;
  u32 ecSlot = (u32)R;
  u8 *K = (u8 *)D(R, 0xc);
  u32 kind = D(K, 0x23);
  if (kind == 0x2007f9u) {
    ecSlot = 0;
  } else if (kind != 0x2003e8u) {
    void (*hook)() = (void (*)())*(u32 *)0x7003b0;
    if (!hook)
      __builtin_trap();
    hook();
  }
  float *vB = (float *)(fr + 0x5c);
  float *vA = (float *)(fr + 0x50);
  float *vC = (float *)(fr + 0x80);
  float *vD = (float *)(fr + 0x98);
  float *vX = (float *)(fr + 0x14);
  vcall<void>(R, 0x80, (u32)vB, (u32)vA);
  u8 *H = (u8 *)D(self, 0x36d);
  vcall<void>(H, 0x80, (u32)vD, (u32)vC);
  ext_43e920(vX, vC, vA);
  float s = (vX[0] * vX[0] + 0.0f) + vX[2] * vX[2];
  float len = (float)sqrtsd((double)s);
  vX[1] = 0.0f;
  *(float *)(fr + 0x10) = len;
  if (!(170.0f > len)) {
    u8 *dbg = (u8 *)vcall<u32>((void *)*(u32 *)0x700390, 0x20, 0x6b7a5cu, 0x673u);
    typedef void(__attribute__((cdecl)) * print_fn)(u32, u32, double);
    print_fn fn = (print_fn)D(*(u8 **)dbg, 0x2c);
    fn((u32)dbg, 0x6b7de4u, (double)len);
    return;
  }
  float *S = (float *)(self + 0x5c6);
  float dot = ((S[1] * vB[1] + vB[0] * S[0]) + S[2] * vB[2]);
  if (0.0f > dot)
    ext_4e09e0(fr + 0x8c);
  ext_4de040(fr + 0x5c, 0u);
  if (ecSlot == 0) {
    vcall<void>(R, 0x578, (u32)vB, (u32)vA);
    u8 *O = (u8 *)vcall<u32>(R, 0x20);
    vcall<void>(O, 0x7c, (u32)vB, (u32)vA);
  }
  // 0x5e21fb: rm slot 0x4c on H, then the copies of this+0x5a8, this+0x5a4 and the S vector.
  D(fr, 0x28) = D(self, 0x5a8);
  *(float *)(fr + 0x48) = *(float *)(self + 0x5a4);
  u8 *sysN = *(u8 **)0x70039c;
  u8 *rm2 = (u8 *)D(sysN, 0x9b);
  u32 rmres = vcall<u32>(rm2, 0x4c, (u32)H);
  D(fr, 0x24) = 0;
  float *Sf = (float *)(self + 0x5c6);
  *(float *)(fr + 0x3c) = Sf[0];
  *(float *)(fr + 0x40) = Sf[1];
  *(float *)(fr + 0x44) = Sf[2];
  *(float *)(fr + 0x34) = *(float *)(self + 0x5be) + 120.0f;
  *(float *)(fr + 0x30) = *(float *)(self + 0x5ba);
  *(float *)(fr + 0x38) = *(float *)(self + 0x5c2);
  D(fr, 0x20) = rmres;
  // the T1 value is stored over the length slot (esp+0x10) after the push of 0 at 0x5e22ab
  u32 T1;
  if (ecSlot != 0)
    T1 = (u32)(int)*(float *)(R + 0x7ff);
  else
    T1 = vcall<u32>(R, 0x674);
  D(fr, 0x10) = T1;
  u16 ax = (u16)vcall<u32>(rm2, 0x114, 0x69eaacu, 0u, 0x6b7a5cu, 0x668u, (u32)(fr + 0x20), 0u);
  vcall<void>(R, 0x128, (u32)ax);
  u32 T2;
  if (ecSlot != 0)
    T2 = (u32)(int)*(float *)(R + 0x7ff);
  else
    T2 = vcall<u32>(R, 0x674);
  if ((int)D(fr, 0x10) > (int)T2)
    *(u8 *)(self + 0x610) = 1;
  (void)sys;
  (void)rmres;
}
PCREG(5e2020, heroCloseCombatFrameUpdate);
