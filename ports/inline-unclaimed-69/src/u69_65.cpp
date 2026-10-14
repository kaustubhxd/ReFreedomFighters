// u69_65.cpp - area 69, group 65 (slice 8). A clamp on a float at self+0x63d7 and a log10-style call through the import thunk 0x634dd6
// (IAT 0x67632c = api-ms-win-crt-math _libm_sse2_log10_precise, SSE2 convention: double in xmm0, result in xmm0; modelled by the harness).
#include "ff.h"

// The import thunk takes its double in xmm0 and returns it in xmm0. sseregparm does not cover the return value (it comes back on the x87 stack), so the call is
// made with inline asm: x in xmm0, the thunk address in eax, the result read back from xmm0.
static double callLog10Thunk(double x) {
  register double x0 __asm__("xmm0") = x;
  __asm__ volatile("movl $0x634dd6, %%eax\n\tcall *%%eax"
                   : "+x"(x0)
                   :
                   : "eax", "ecx", "edx", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7", "memory", "cc",
                     "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
  return x0;
}

// 0x549780, thiscall with one stack arg that is not read (ret 4). Clamps the float at self+0x63d7: if !(A >= x) (A = float at 0x67d9fc), it becomes 100.0 when x > B
// (B = float at 0x67cd40), otherwise it stays; if A >= x it becomes 0.0. Then, if the value is 0 (ordered equal), returns (int) the float at 0x6a24f8.
// Otherwise: d = (double)x * K1 (K1 at 0x6a36c8), rounded to float, widened, passed to the log10 thunk, the result times K2 (at 0x6a36d0) is rounded to float,
// and the int conversion of that float is returned (truncating).
static s32 THISCALL logClamp549780(u8 *self, u32 unused) {
  float x = *(float *)(self + 0x63d7);
  float A = *(float *)0x67d9fc;
  float B = *(float *)0x67cd40;
  if (!(A >= x)) {
    if (x > B)
      *(float *)(self + 0x63d7) = 100.0f;
  } else {
    *(float *)(self + 0x63d7) = 0.0f;
  }
  float xp = *(float *)(self + 0x63d7);
  if (xp == 0.0f)
    return (s32)*(float *)0x6a24f8;
  double d = (double)xp * *(double *)0x6a36c8;
  float f = (float)d;
  double r = callLog10Thunk((double)f);
  r = r * *(double *)0x6a36d0;
  float f2 = (float)r;
  return (s32)f2;
}
PCREG(549780, logClamp549780);
