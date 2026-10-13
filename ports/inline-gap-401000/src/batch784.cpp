// batch784.cpp - gap band batch 784 (docs/20-gap-band-401000.md): 0x41f3a0, thiscall (this), void.
#include "ff.h"

typedef u32(THISCALL *F1)(u8 *self, u32 a);
typedef u32(THISCALL *F2)(u8 *self, u32 a, u32 b);
static u32 vc1(u8 *o, u32 s, u32 a) { return ((F1)(*(const u32 *)(*(const u32 *)o + s)))(o, a); }
static u32 vc2(u8 *o, u32 s, u32 a, u32 b) { return ((F2)(*(const u32 *)(*(const u32 *)o + s)))(o, a, b); }

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

static void THISCALL fn41f3a0(u8 *self) {
  u32 node = *(const u32 *)(self + 0x18);
  while (node != 0) {
    vc1(self, 0x88, node);
    node = *(const u32 *)node;
  }
  u8 *o = *(u8 **)(self + 0x31);
  if (*(const u32 *)o == 0) return;
  const u32 X = vc2(G(u8 *, 0x700390), 0x20, 0x6774c8, 0xfb);
  const u32 vt = *(const u32 *)X;
  callCallerCleans3(o, *(const u32 *)(vt + 0x2c), X, 0x6774fc, *(const u32 *)o);
}

PCREG(41f3a0, fn41f3a0);
