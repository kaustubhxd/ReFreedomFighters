// u69_73.cpp - area 69, group 73 (slice 8). A float colour packer: three float args (a, b, c; stdcall, ret 0xc). No callees.
#include "ff.h"

// 0x5a5d00, ZOnScreenDisplay::CalcHealthColor(float, float, float) (GC map high). Constants: K1 at 0x678858, K2 at 0x67a6ac, K3 at 0x68af18, K4 at 0x68377c.
// m = 0 when a < 0 (ordered), otherwise min(K1, a); when K2 < m (or unordered) the second branch runs, otherwise the first branch.
// The three channels x2, x1, x3 are (truncated) times K3 and the first two clamp to 255; the last channel is c*K4. The result is
// ((((x3 << 8) + x2) << 8) + x1) << 8) - c4, as unsigned arithmetic.
static u32 STDCALL healthColor5a5d00(float a, float b, float c) {
  float K1 = *(const float *)0x678858;
  float K2 = *(const float *)0x67a6ac;
  float K3 = *(const float *)0x68af18;
  float K4 = *(const float *)0x68377c;
  float x1, x2, x3, x4;
  if (0.0f > a) {
    x1 = 0.0f;
    // A
    x1 = x1 * b;
    x3 = b + c;
    x1 = x1 + x1;
    x2 = x3;
    x1 = x1 + c;
    x4 = c;
  } else {
    float m = (K1 < a) ? K1 : a;
    if (!(K2 >= m)) {
      // B
      x3 = b + c;
      x1 = m + m;
      x1 = x1 - K1;
      x2 = K1 - x1;
      x1 = x3;
      x2 = x2 * b;
      x2 = x2 + c;
      x4 = c;
    } else {
      // A
      x1 = m * b;
      x3 = b + c;
      x1 = x1 + x1;
      x2 = x3;
      x1 = x1 + c;
      x4 = c;
    }
  }
  x4 = x4 * K4;
  x2 = x2 * K3;
  x1 = x1 * K3;
  x3 = x3 * K3;
  s32 edx = (s32)x2;
  if (edx > 0xff)
    edx = 0xff;
  s32 ecx = (s32)x1;
  if (ecx > 0xff)
    ecx = 0xff;
  u32 eax = (u32)(s32)x3;
  eax = (eax << 8) + (u32)edx;
  eax = (eax << 8) + (u32)ecx;
  ecx = (s32)x4;
  eax = (eax << 8) - (u32)ecx;
  return eax;
}
PCREG(5a5d00, healthColor5a5d00);
