// batch789.cpp - unclaimed-77 claim 19 (docs/20-unclaimed-77.md): RandomRange(float, float) (medium). Stdcall, ret 8, result in st0
// (double precision). The render-manager slot 0x1c0 is stubbed in the harness (GUESS).
#include "ff.h"

// 0x4de000, RandomRange(float lo, float hi) (medium): r = slot 0x1c0 of the render manager (args 0x69709c, 0xbc5); returns
// r * ((hi - lo) + 1.0) + lo, computed in x87 double precision and returned in st0.
static double __attribute__((stdcall)) randomRange(float lo, float hi) {
  void *rm = G(void *, 0x70039c);
  void **vt = *(void ***)rm;
  float r = ((float (THISCALL *)(void *, u32, u32))(*(void **)((u8 *)vt + 0x1c0)))(rm, 0x69709cu, 0xbc5u);
  double t = ((double)hi - (double)lo) + 1.0;
  double res = (double)r * t;
  res = res + (double)lo;
  return res;
}
PCREG(4de000, randomRange);
