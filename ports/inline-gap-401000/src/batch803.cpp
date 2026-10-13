// batch803.cpp - gap band batch 803 (docs/20-gap-band-401000.md): 0x41fa40, thiscall (this, a), returns a bool.
#include "ff.h"
typedef int i32;

typedef u32(THISCALL *F1)(u8 *self, u32 a);
static u32 vc1(u8 *o, u32 s, u32 a) { return ((F1)(*(const u32 *)(*(const u32 *)o + s)))(o, a); }

extern "C" void THISCALL ext_41f190(u8 *self, u32 a);   // thiscall, one argument (callee pops 4; exe code)

// a call with `self` in ecx and two stack arguments that the CALLER removes (add esp, 8 follows the original call)
static void callCallerCleans2(u8 *self, u32 fn, u32 a, u32 b) {
  asm volatile(
      "pushl %[b]\n\t"
      "pushl %[a]\n\t"
      "call *%[fn]\n\t"
      "addl $8, %%esp\n\t"
      :
      : "c"(self), [fn] "r"(fn), [a] "r"(a), [b] "r"(b)
      : "eax", "edx", "memory", "cc");
}

static u8 THISCALL fn41fa40(u8 *self, u32 a) {
  if (vc1(G(u8 *, 0x70038c), 0x20, a) != 0) return 0;
  bool in = false;
  u8 *obj = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  if (obj != nullptr) {
    const u32 e = *(const u32 *)(obj + 0x1c5d);
    if (a >= e && e != 0) {
      const u32 size = *(const u32 *)(e - 8) & 0x1fffffff;
      if (a < e + size) in = true;
    }
  }
  if (in) {
    void (*cb)(void) = (void (*)(void))G(u32, 0x7003b0);
    if (cb == nullptr) __builtin_trap();   // the exe executes int3 here
    cb();
  }
  *(u32 *)(a - 0xc) -= 1;
  ext_41f190(self, a);
  const u32 c = *(const u32 *)(a - 0xc);
  if (c == 0) return 1;
  if ((i32)c < 0) {
    u8 *g = G(u8 *, 0x700390);
    callCallerCleans2((u8 *)*(const u32 *)g, *(const u32 *)(*(const u32 *)g + 0x34), (u32)g, 0x677524);
  }
  return 0;
}

PCREG(41fa40, fn41fa40);
