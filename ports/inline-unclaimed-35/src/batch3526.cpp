#include "ff.h"
// batch3526.cpp - area 35 claim 26 (docs/20-unclaimed-35.md): 0x47e5e0 (GUESS name), thiscall, no stack args, float return (st0).
// Helpers are GUESS recording stubs (harness). The CRT math helpers 0x634d7c (double in xmm0 -> xmm0) and 0x634dc4 (x87 operands
// double then 1.0 -> st0) run as original exe code, called through inline asm with the same operands. The exe's esp-relative
// locals are the buffer S; pointers into S go to the helpers where the exe puts them. Float arithmetic is in the exe's order
// (SSE, -ffp-contract=off). The SEH frame and /GS cookie check are not modelled. NOTE: 0x634d7c and 0x634dc4 are IAT thunks
// (sqrt and _CIfmod, api-ms-win-crt-math), not exe code; the spec gives them a harness handler / a stub at the thunk address.
// Labels follow the disassembly's branch targets: L9e5 (0x254 test), L8e3, L8bc, L842, L7da, L955, L969, L9ae, Labc, Laf1, LB19.

typedef u32(THISCALL *Slot0)(u8 *self);
typedef u32(THISCALL *Slot1)(u8 *self, u32 a0);
typedef u32(THISCALL *Slot2)(u8 *self, u32 a0, u32 a1);
typedef u32(THISCALL *Slot3)(u8 *self, u32 a0, u32 a1, u32 a2);

static u32 vcall0(u8 *o, u32 off) { return ((Slot0)*(u32 *)(*(u32 *)o + off))(o); }
static u32 vcall1(u8 *o, u32 off, u32 a0) { return ((Slot1)*(u32 *)(*(u32 *)o + off))(o, a0); }
static u32 vcall2(u8 *o, u32 off, u32 a0, u32 a1) { return ((Slot2)*(u32 *)(*(u32 *)o + off))(o, a0, a1); }
static u32 vcall3(u8 *o, u32 off, u32 a0, u32 a1, u32 a2) { return ((Slot3)*(u32 *)(*(u32 *)o + off))(o, a0, a1, a2); }

static void mv8(u8 *dst, u8 *src) {
  u32 a = *(u32 *)src, b = *(u32 *)(src + 4);
  *(u32 *)dst = a;
  *(u32 *)(dst + 4) = b;
}

extern "C" float THISCALL ext_47f490(u8 *self, u32 a0, u32 a1, float a2);
extern "C" void FASTCALL ext_4e09e0(u32 a0, u32 a1);
extern "C" void FASTCALL ext_441940(u32 a0, u32 a1);
extern "C" void FASTCALL ext_4419f0(u32 a0, u32 a1);
extern "C" void FASTCALL ext_4de480(u32 a0, u32 a1);
extern "C" void FASTCALL ext_4de040(u32 a0, u32 a1, u32 a2);
extern "C" void THISCALL ext_4e09b0(u8 *self);
extern "C" void THISCALL ext_47aad0(u8 *self, u32 a0, u32 a1);
extern "C" void THISCALL ext_477740(u8 *self, u32 a0, u32 a1);
extern "C" void THISCALL ext_47c690(u8 *self, float a0);
extern "C" void THISCALL ext_47ce80(u8 *self);
extern "C" void THISCALL ext_47cdf0(u8 *self, u32 a0, float a1);

// 0x634d7c (thunk to _libm_sse2_sqrt_precise): double in xmm0, result in xmm0.
static double callMath634d7c(double x) {
  __asm__ volatile("call *%1"
                   : "+x"(x)
                   : "r"(0x634d7cu)
                   : "eax", "ecx", "edx", "memory", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7",
                     "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
  return x;
}

// 0x634dc4 (thunk to _CIfmod): x87 operands (double, then 1.0), result in st0; stored as float.
static float callMath634dc4(double d) {
  float r;
  __asm__ volatile("fldl %1\n\tfld1\n\tcall *%2\n\tfstps %0"
                   : "=m"(r)
                   : "m"(d), "r"(0x634dc4u)
                   : "eax", "ecx", "edx", "memory", "xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7",
                     "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
  return r;
}

// 0x47e5e0, GUESS name: float-returning thiscall dispatcher over this's fields.
float THISCALL guess47e5e0(u8 *self) {
  u8 S[0x6c];
  u8 *esi = self;
  float f1, t, f, x2, q, sq, v;
  s32 ci;
  u32 a, c64c, flag726, flag754;
  double dd;
  bool eq;

  vcall2(esi, 0x57c, (u32)(S + 0x48), (u32)(S + 0x3c));
  ext_4e09e0((u32)(S + 0x30), (u32)(S + 0x48));
  f1 = *(float *)(esi + 0x644) * *(float *)0x678620;
  *(u32 *)(S + 4) = 0;
  ci = (s32)f1;
  a = *(u32 *)(*(u32 *)0x70039c + 0x40) - (u32)ci;
  flag726 = *(u8 *)(esi + 0x726);
  *(float *)(S + 8) = (float)(s32)a * *(float *)0x6785e4;
  if (flag726 == 0)
    goto L9e5;
  if ((u8)vcall0(esi, 0x254) != 0)
    goto L9e5;

  // Main path: t = S8 * this.75d * this.688, then the 47f490 call returns f.
  t = *(float *)(esi + 0x75d) * *(float *)(S + 8);
  t = t * *(float *)(esi + 0x688);
  *(float *)(S + 0x14) = t;
  c64c = *(u32 *)(esi + 0x64c);
  if (c64c == 0xb || c64c == 0xa) {
    t = 0.0f;
    *(float *)(S + 0x14) = 0.0f;
  }
  f = ext_47f490(esi, (u32)(S + 0x18), (u32)(S + 0x3c), t);
  *(float *)(S + 4) = f;
  c64c = *(u32 *)(esi + 0x64c);
  if (f <= *(float *)0x6785d0)
    goto L8e3;
  if (c64c == 0xb) {
    mv8(S + 0x24, S + 0x30);
    *(u32 *)(S + 0x2c) = *(u32 *)(S + 0x38);
    mv8(S + 0x18, S + 0x3c);
    *(u32 *)(S + 0x20) = *(u32 *)(S + 0x44);
    goto L8bc;
  }
  if (c64c != 0xa)
    goto L842;

  // c64c == 0xa: x2 = (S8 * this.688) / this.759 + this.755.
  x2 = (*(float *)(S + 8) * *(float *)(esi + 0x688)) / *(float *)(esi + 0x759) + *(float *)(esi + 0x755);
  *(float *)(S + 0x24) = *(float *)(esi + 0x6f2);
  *(float *)(S + 0x28) = *(float *)(esi + 0x6f6);
  *(float *)(S + 0x2c) = *(float *)(esi + 0x6fa);
  *(float *)(esi + 0x755) = x2;
  if (x2 <= *(float *)0x678858)
    goto L7da;
  ext_47aad0((u8 *)0x6ff9c0, *(u32 *)(esi + 0x6ce), (u32)esi);
  *(u32 *)(esi + 0x6ce) = 0;
  ext_477740(esi, 8, 0);
  *(u32 *)(esi + 0x64c) = 3;
  *(float *)(S + 0x18) = *(float *)(esi + 0x6e6);
  *(float *)(S + 0x1c) = *(float *)(esi + 0x6ea);
  *(float *)(S + 0x20) = *(float *)(esi + 0x6ee);
  vcall0(esi, 0x5f8);
  goto L8bc;

L7da:
  *(float *)(S + 0x18) = ((*(float *)(esi + 0x6e6) - *(float *)(esi + 0x6da)) * x2) + *(float *)(esi + 0x6da);
  *(float *)(S + 0x1c) = ((*(float *)(esi + 0x6ea) - *(float *)(esi + 0x6de)) * x2) + *(float *)(esi + 0x6de);
  *(float *)(S + 0x20) = ((*(float *)(esi + 0x6ee) - *(float *)(esi + 0x6e2)) * x2) + *(float *)(esi + 0x6e2);
  goto L8bc;

L842:
  flag754 = *(u8 *)(esi + 0x754);
  *(float *)(S + 0x24) = *(float *)(esi + 0x67c);
  *(float *)(S + 0x2c) = *(float *)(esi + 0x684);
  *(u32 *)(S + 0x28) = 0;
  if (flag754 != 0)
    ext_4e09b0(S + 0x24);

  *(u32 *)(esi + 0x64c) = 3;
  ext_477740(esi, 8, 0);
  *(float *)(esi + 0x755) = (*(float *)(S + 8) * *(float *)(esi + 0x688)) / *(float *)(esi + 0x759) + *(float *)(esi + 0x755);
  *(float *)(S + 4) = 0.0f;
  goto L8bc;

L8bc:
  dd = (double)*(float *)(esi + 0x755);
  *(double *)(S + 8) = dd;
  *(float *)(esi + 0x755) = callMath634dc4(dd);
  goto L9ae;

L8e3:
  *(float *)(S + 0x18) = *(float *)(esi + 0x660);
  *(float *)(S + 0x1c) = *(float *)(esi + 0x664);
  *(float *)(S + 0x20) = *(float *)(esi + 0x668);
  vcall3(esi, 0x620, (u32)(S + 0x18), 1, 1);
  if (*(u8 *)(esi + 0x699) == 0)
    goto L955;
  *(float *)(S + 0x24) = *(float *)(esi + 0x69a);
  *(float *)(S + 0x28) = *(float *)(esi + 0x69e);
  *(float *)(S + 0x2c) = *(float *)(esi + 0x6a2);
  goto L969;

L955:
  mv8(S + 0x24, S + 0x30);
  *(u32 *)(S + 0x2c) = *(u32 *)(S + 0x38);

L969:
  if (*(u32 *)(esi + 0x64c) == 0xa) {
    ext_47aad0((u8 *)0x6ff9c0, *(u32 *)(esi + 0x6ce), (u32)esi);
    *(u32 *)(esi + 0x6ce) = 0;
    *(u32 *)(esi + 0x64c) = 0;
  }
  vcall1(esi, 0x62c, 0);
  ext_477740(esi, 1, 0);

L9ae:
  ext_47c690(esi, *(float *)(S + 4));
  ext_47ce80(esi);
  ext_47cdf0(esi, (u32)(S + 0x18), *(float *)(S + 0x14));
  goto LB19;

L9e5:
  if ((u8)vcall0(esi, 0x254) == 0)
    goto Laf1;
  *(float *)(S + 0x18) = *(float *)(esi + 0x48);
  *(float *)(S + 0x1c) = *(float *)(esi + 0x4c);
  *(float *)(S + 0x20) = *(float *)(esi + 0x50);
  ext_4419f0((u32)(S + 0x18), (u32)(S + 0x48));
  ext_441940((u32)(S + 0x18), (u32)(S + 0x3c));
  ext_4de480((u32)(S + 0x48), (u32)(esi + 0x24));
  ext_4e09e0((u32)(S + 0x24), (u32)(S + 0x48));
  if (vcall0(esi, 0x588) == 0)
    goto LB19;
  q = ((*(float *)(esi + 0x48) * *(float *)(esi + 0x48)) + (*(float *)(esi + 0x4c) * *(float *)(esi + 0x4c))) +
      (*(float *)(esi + 0x50) * *(float *)(esi + 0x50));
  sq = (float)callMath634d7c((double)q);
  v = *(float *)(esi + 0x70e) - sq;
  *(float *)(esi + 0x70e) = v;
  if (0.0f > v)
    goto Labc;
  if (*(u8 *)(esi + 0x703) != 0)
    goto Labc;
  if (*(u8 *)(esi + 0x705) == 0)
    goto LB19;

Labc:
  vcall3(esi, 0x620, (u32)(S + 0x18), 1, 1);
  *(float *)(esi + 0x70a) = *(float *)(S + 0x1c);
  *(float *)(esi + 0x706) = *(float *)(S + 0x1c);
  *(u32 *)(esi + 0x70e) = 0x41c80000u;
  goto LB19;

Laf1:
  mv8(S + 0x24, S + 0x30);
  *(u32 *)(S + 0x2c) = *(u32 *)(S + 0x38);
  mv8(S + 0x18, S + 0x3c);
  *(u32 *)(S + 0x20) = *(u32 *)(S + 0x44);

LB19:
  ext_4e09b0(S + 0x24);
  *(u32 *)(S + 0x28) = 0;
  eq = (*(float *)(S + 0x24) == *(float *)(S + 0x30)) && (0.0f == *(float *)(S + 0x34)) &&
       (*(float *)(S + 0x2c) == *(float *)(S + 0x38));
  if (!eq)
    ext_4de040((u32)(S + 0x48), (u32)(S + 0x24), 0);
  vcall2(esi, 0x578, (u32)(S + 0x48), (u32)(S + 0x18));
  return *(float *)(S + 4);

}
PCREG(47e5e0, guess47e5e0);
