// batch6547.cpp - unclaimed-65: batch 47 (docs/20-unclaimed-65.md, claim 27): 0x45d3a0, thiscall, no arguments. The SEH frame is not
// reproduced (tagged in the doc); the cookie check runs as the exe code.
#include "ff.h"

typedef u32(THISCALL *F1)(u8 *self, u32 a);
typedef u32(THISCALL *F2)(u8 *self, u32 a, u32 b);
typedef u32(THISCALL *F3)(u8 *self, u32 a, u32 b, u32 c);
typedef u32(THISCALL *F4)(u8 *self, u32 a, u32 b, u32 c, u32 d);
static u32 vc1(u8 *o, u32 s, u32 a) { return ((F1)(*(const u32 *)(*(const u32 *)o + s)))(o, a); }
static u32 vc2(u8 *o, u32 s, u32 a, u32 b) { return ((F2)(*(const u32 *)(*(const u32 *)o + s)))(o, a, b); }
static u32 vc3(u8 *o, u32 s, u32 a, u32 b, u32 c) { return ((F3)(*(const u32 *)(*(const u32 *)o + s)))(o, a, b, c); }
static u32 vc4(u8 *o, u32 s, u32 a, u32 b, u32 c, u32 d) { return ((F4)(*(const u32 *)(*(const u32 *)o + s)))(o, a, b, c, d); }

// a call with `self` in ecx and three stack arguments that the CALLER removes (add esp, 0xc follows the original call)
static void callCallerCleans3(u8 *self, u32 fn, u32 a, u32 b, u32 c) {
  asm volatile(
      "pushl %[c]\n\t"
      "pushl %[b]\n\t"
      "pushl %[a]\n\t"
      "call *%[fn]\n\t"
      "addl $12, %%esp\n\t"
      :
      : "c"(self), [fn] "r"(fn), [a] "r"(a), [b] "r"(b), [c] "r"(c)
      : "eax", "edx", "memory", "cc");
}

typedef void(__attribute__((cdecl)) * C2)(u32, u32);

extern "C" u32 THISCALL ext_4cc1d0(u8 *p);
extern "C" void THISCALL ext_4cbec0(u8 *p);
extern "C" void THISCALL ext_45c560(u8 *self, u32 a);   // thiscall, one argument (ret 4); another claim

// 0x45d3a0. See docs/20-unclaimed-65.md (claim 27).
static void THISCALL fn45d3a0(u8 *self) {
  u8 L90[0x80];
  if (G(u32, 0x7003a4) == 0) return;
  u8 *S = *(u8 **)(self + 0x10);
  if (S == nullptr || *(u8 **)(S + 0x1c) == nullptr) return;

  const u32 X = vc1(G(u8 *, 0x70038c), 0x48, 0x8f0fff);
  u8 *Y = *(u8 **)(S + 0x1c);
  u8 *Q = *(u8 **)(Y + 4);
  u8 *r9 = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  const u32 R = vc4(r9, 0x4c, (u32)self, 0x685230, 0x685220, *(const u32 *)(Q + 0xc));
  vc1(G(u8 *, 0x7003a8), 0x40, R);
  u8 *H = G(u8 *, 0x7003a4);
  const u32 R2 = vc1(r9, 0x4c, (u32)self);
  const u32 R3 = vc3(H, 0x3c, *(const u32 *)(Q + 8), *(const u32 *)(Q + 0xc), R2);
  *(u32 *)(Q + 4) = R3;
  if (R3 != 0) {
    vc1(H, 0x44, R3);
  } else {
    u8 *K = (u8 *)vc2(G(u8 *, 0x700390), 0x20, 0x685054, 0x711);
    u8 *P = (u8 *)vc2(self, 0x1d8, (u32)L90, 1);
    const u32 v = ext_4cc1d0(P);
    callCallerCleans3(P, *(const u32 *)(*(const u32 *)K + 0x2c), (u32)K, 0x685238, v);
    ext_4cbec0(L90);
    *(u32 *)(Y + 4) = 0;
  }

  ((C2)0x634273)(*(const u32 *)(Q + 8), 1);
  *(u32 *)(Q + 8) = 0;
  vc1(H, 0x58, *(const u32 *)(Q + 0xc));
  *(u32 *)(Q + 0xc) = 0;

  if (*(const u32 *)(Y + 4) == 0 && *(const u8 *)(G(u8 *, 0x70039c) + 0x1b3b) != 0) {
    u8 *c = *(u8 **)(*(u8 **)(self + 0x10) + 0x1c);
    if (c != nullptr) ext_45c560(c, 1);
    *(u32 *)(*(u8 **)(self + 0x10) + 0x1c) = 0;
    const u32 R4 = vc1(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x4c, (u32)self);
    vc1(H, 0x84, R4);
  }
  vc1(G(u8 *, 0x70038c), 0x48, X);
}

// NOT registered: blocked (docs/20-unclaimed-65.md, claim 27). Slot 0x4c of the render sub-object is called with 4 and with 1
// argument and no cleanup, so one callee ret count cannot balance both sites.
// PCREG(45d3a0, fn45d3a0);
