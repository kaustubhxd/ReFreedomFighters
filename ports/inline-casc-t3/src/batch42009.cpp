// batch42009.cpp - Sonnet t3: tier H, SSE conversions.
#include "ff.h"

extern "C" u32 THISCALL ext_4e1590(u8 *self);  // size of the current record (value), plain ret
typedef u32 (*hook_t)();
typedef double __attribute__((aligned(1))) f64u;
typedef float __attribute__((aligned(1))) f32u;
typedef s32 __attribute__((aligned(1))) s32u;

// 0x4e13c0, thiscall(out, count) ret 8 (count >= 1, do-while): p = [this+8]; tag = (*p == 0xff) ? 0xff : *p & 0x3f; tag 1: out = double at p+1;
// tag 2: out = (double)float at p+1; tag 3: out = (double)int32 at p+1; else the assert hook 0x7003b0 (int3 when null), out untouched;
// then [this+8] += 0x4e1590(this) + 1 and out advances by one double.
static void THISCALL fn4e13c0(u8 *self, double *out, s32 count) {
  for (;;) {
    u8 *p = *(u8 **)(self + 8);
    u8 t = p[0];
    t = (t == 0xff) ? t : (t & 0x3f);
    if (t == 1) *out = *(f64u *)(p + 1);
    else if (t == 2) *out = (double)*(f32u *)(p + 1);
    else if (t == 3) *out = (double)*(s32u *)(p + 1);
    else {
      hook_t h = G(hook_t, 0x7003b0);
      if (!h) __asm__ volatile("int3");
      h();
    }
    u32 n = ext_4e1590(self);
    *(u32 *)(self + 8) += n + 1;
    if (count == 1) return;
    count--;
    out++;
  }
}
PCREG(4e13c0, fn4e13c0);
