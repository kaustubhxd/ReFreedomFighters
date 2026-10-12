// batch6339.cpp - unclaimed-63 gap-band batch 39: 0x4d8730 (x87 set; no GC name), thiscall, one stack argument a, ret 4.
//   If a != 0: f = 0x6762d4(a) (cdecl, the float comes back in st0, caller cleans 4); *(float *)this[+0x104] = f.
//   If a == 0: L = [0x700390]->vtbl[+0x20](0x696c88, 0xb9) (thiscall, ret 8); p = this[+0x104]; d = (double)*(float *)p;
//     r = this->vtbl[+4](p) (thiscall with the argument cleaned by the caller, see the asm); name = 0x4cc1d0(r) (thiscall, no arguments, original, stubbed by the spec);
//     L->vtbl[+0x2c](L, 0x696d74, name, p, d) (cdecl, caller cleans 24; p is the argument pushed for vtbl[+4]).
#include "ff.h"

extern "C" u32 THISCALL ext_4cc1d0(void *self);   // thiscall, no arguments, original code, stubbed by the spec

typedef float(*cdecl_f_fn)(u32);
typedef u32(THISCALL * log20_fn)(void *, u32, u32);
typedef void (*printf_fn)(u32, u32, u32, u32, double);

// 0x4d8730 (x87 set).
static void THISCALL unnamed4d8730(u8 *self, u32 a) {
  if (a != 0) {
    float f = ((cdecl_f_fn)G(u32, 0x6762d4))(a);
    *(float *)(*(u32 *)(self + 0x104)) = f;
    return;
  }
  u32 lg = G(u32, 0x700390);
  u32 l = ((log20_fn)(*(u32 *)(*(u32 *)lg + 0x20)))((void *)lg, 0x696c88u, 0xb9u);
  u32 p = *(u32 *)(self + 0x104);
  double d = (double)*(float *)p;
  u32 lvt = *(u32 *)l;
  // vtbl[+4] is called with the argument pushed and left on the stack (the caller cleans it, after printf's 24 bytes)
  u32 r, fn = *(u32 *)(*(u32 *)self + 4), th = (u32)self;
  asm volatile("push %[p]\n\tcall *%[fn]\n\tadd $4, %%esp"
               : "=a"(r), "+c"(th)
               : [p] "r"(p), [fn] "r"(fn)
               : "edx", "memory", "cc");
  u32 name = ext_4cc1d0((void *)r);
  // the original leaves p on the stack after vtbl[+4] and the printf call sees it as its fourth argument, before the double
  ((printf_fn)(*(u32 *)(lvt + 0x2c)))(l, 0x696d74u, name, p, d);
}
PCREG(4d8730, unnamed4d8730);
