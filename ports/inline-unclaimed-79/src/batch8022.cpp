#include "ff.h"
// batch8022.cpp - unclaimed-79 unclaimed small rows (docs/20-unclaimed-79.md). Names GUESS (no GC name).

// 0x48f780 (GUESS): stdcall (ret 8). Compares the strings at *a and *b two bytes per step. Returns 1 if equal, else 0.
static u32 STDCALL f_48f780(u32 pa, u32 pb) {
  u8 *s = *(u8 **)(unsigned long)pa;
  u8 *t = *(u8 **)(unsigned long)pb;
  for (;;) {
    u8 c = *s;
    if (c != *t) return 0;
    if (c == 0) return 1;
    u8 d = s[1];
    if (d != t[1]) return 0;
    s += 2;
    t += 2;
    if (d == 0) return 1;
  }
}
PCREG(48f780, f_48f780);

// 0x4972c0 (GUESS): thiscall (ret 4). When the argument is nonzero: decrements the counter at this+0x59, stores the word
// (arg - this+0x51) >> 5 at index counter of the array at this+0x55, then calls slot +0x30 of 0x70038c with (0x68e7d4, arg - base, 0x20).
static void THISCALL f_4972c0(u8 *self, u32 a) {
  if (a == 0) return;
  (*(u32 *)(self + 0x59))--;
  u32 idx = *(u32 *)(self + 0x59);
  u32 d = a - *(u32 *)(self + 0x51);
  u16 w = (u16)((s32)d >> 5);
  *(u16 *)(*(u8 **)(self + 0x55) + idx * 2) = w;
  u8 *g = G(u8 *, 0x70038c);
  if (g != 0) vcall<void, u32, u32, u32>(g, 0x30, 0x68e7d4u, d, 0x20u);
}
PCREG(4972c0, f_4972c0);

// 0x4947c0 (GUESS): stdcall (ret 4). Calls slot +0x134 of the sub-object at 0x70039c+0x9b with no arguments, then slot
// +0x5c of the returned object with (0x68e208, arg, 2). Returns the callee's eax.
static u32 STDCALL f_4947c0(u32 a) {
  u8 *sub = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *p = vcall<u8 *>(sub, 0x134);
  return vcall<u32, u32, u32, u32>(p, 0x5c, 0x68e208u, a, 2u);
}
PCREG(4947c0, f_4947c0);
