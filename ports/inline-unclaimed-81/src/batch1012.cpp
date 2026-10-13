// batch1012.cpp - area 81, batch 1012: CActionController::FrameUpdate(), 0x4a0970, thiscall, no arguments, plain ret. No SEH frame, no cookie.
// Stand-ins (GUESS): 0x4a1e00 (thiscall on each element of this+0x5c[i]), 0x4a1710 (thiscall on an element array, one argument),
// 0x634da6 (cdecl double -> double, result in st0). The debug-print branches (sys+0x9c7 and sys+0x9c3 both nonzero: a print through the
// sys vtable slot 0x1c8 / 0x178 / 0x17c, whose edx is undefined in the exe) are trapped; the harness keeps both floats zero.
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_4a1e00(void *self);                       // GUESS (stood in)
extern "C" void THISCALL ext_4a1710(void *self, u32 k);                // GUESS (stood in)
extern "C" double __attribute__((cdecl)) ext_634da6(double x);          // GUESS (stood in)

// 0x4a0970 CActionController::FrameUpdate().
static void THISCALL actionControllerFrameUpdate(u8 *self) {
  u8 *sys = *(u8 **)0x70039c;
  if (*(float *)(sys + 0x9c7) != 0.0f && *(float *)(sys + 0x9c3) != 0.0f)
    __builtin_trap();
  for (u32 i = 0; i < D(self, 0x48); ++i)
    ext_4a1e00((void *)D(self, 0x5c + 4 * i));

  u8 *P = (u8 *)*(u32 *)0x7002a8;
  if (P) {
    u32 flag = 0;
    vcall<void>(P, 0x4c, (u32)&flag);
    u8 *E = (u8 *)vcall<u32>(P, 0x5c, (u32)&flag);
    while (flag) {
      u8 *R = (u8 *)vcall<u32>((void *)*(u32 *)0x70038c, 0xcc, (u32)E);
      if (R)
        vcall<void>(R, 0x5c, 0x20u, 0u, (u32)*(u16 *)0x7002d4);
      E = (u8 *)vcall<u32>(P, 0x5c, (u32)&flag);
    }
    vcall<void>(P, 0x0, 1u);
    *(u32 *)0x7002a8 = 0;
  }

  for (int j = 0; j < (int)D(self, 0x48); ++j) {
    u8 *xj = (u8 *)D(self, 0x5c + 4 * j);
    u32 *cnt = (u32 *)(self + 0x4c + 4 * j);
    int n = (int)D(xj, 0x804) + 1;
    if (n <= 0)
      continue;
    float x = (float)n * 0.2f;                       // mulss with the float at 0x67c194
    double r = ext_634da6((double)x);
    int ia = (int)r;
    int m = ia <= n ? ia : n;
    int c = (int)*cnt;
    int q = c / n;
    (void)q;
    int rem = c % n;
    *cnt = (u32)rem;
    int hi = m + rem < n ? m + rem : n;
    int lo = m - n + rem;
    if (lo < 0)
      lo = 0;
    for (int k = 0; k < lo; ++k) {
      u8 *R = (u8 *)vcall<u32>((void *)*(u32 *)0x70038c, 0xcc, D(xj, 4 + 4 * k));
      if (!R) {
        ext_4a1710(xj, (u32)k);
        --k;
        --lo;
      } else {
        u32 s = vcall<u32>((void *)D(*(u8 **)0x70039c, 0x9b), 0x58, D(xj, 0));
        vcall<void>(R, 0xb4, s);
      }
    }
    for (int k = rem; k < hi; ++k) {
      u8 *R = (u8 *)vcall<u32>((void *)*(u32 *)0x70038c, 0xcc, D(xj, 4 + 4 * k));
      if (!R) {
        ext_4a1710(xj, (u32)k);
        --k;
        --hi;
      } else {
        u32 s = vcall<u32>((void *)D(*(u8 **)0x70039c, 0x9b), 0x58, D(xj, 0));
        vcall<void>(R, 0xb4, s);
      }
    }
    *cnt = (u32)((int)*cnt + m);
  }
  if (*(float *)(sys + 0x9c7) != 0.0f && *(float *)(sys + 0x9c3) != 0.0f)
    __builtin_trap();
}
PCREG(4a0970, actionControllerFrameUpdate);
