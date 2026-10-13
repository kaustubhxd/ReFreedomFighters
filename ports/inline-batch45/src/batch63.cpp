// batch63.cpp - throw tree, inline session batch 63: ZFFActionThrow::Execute (0x5e0500) and Terminate (0x5e0600), the
// hero's camera-helper getter (0x566fa0) and the three x87 vector helpers ZFFActionThrow::Update calls (0x43e8e0,
// 0x44e630, 0x451890).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vcallUU)(void *self, u32 a);

extern "C" void THISCALL ext_59a6a0(u8 *osd, u32 on);   // ZGameOSD: byte +0x22ce = on (batch 38)

// 0x566fa0, thiscall on the hero, eax. The hero's ZCamHelper (+0x85a), made with the hero's slot 0x100("ZCamHelper")
// the first time.
static u32 THISCALL heroCamHelper(u8 *hero) {
  if (*(u32 *)(hero + 0x85a) == 0)
    *(u32 *)(hero + 0x85a) = ((vcallUU)VT(hero, 0x100))(hero, 0x6a6e88u);
  return *(u32 *)(hero + 0x85a);
}
PCREG(566fa0, heroCamHelper);

// 0x5e0500 ZFFActionThrow::Execute(), thiscall, al. The hero is +8. Copies the camera helper's byte +0xb45 to +0x21,
// turns the OSD throw meter on (hero +0x852, ZGameOSD byte +0x22ce = 1), and starts the three timers +0x14, +0x18 and
// +0x1c at the tick count / 1024. Clears +0x20. Always true. The helper is fetched inline (same code as 0x566fa0).
static u8 THISCALL throwExecute(u8 *self) {
  u8 *hero = *(u8 **)(self + 8);
  if (*(u32 *)(hero + 0x85a) == 0)
    *(u32 *)(hero + 0x85a) = ((vcallUU)VT(hero, 0x100))(hero, 0x6a6e88u);   // "ZCamHelper"
  self[0x21] = (*(u8 **)(hero + 0x85a))[0xb45];
  ext_59a6a0(*(u8 **)(*(u8 **)(self + 8) + 0x852), 1);
  float k = bitsf(0x3a800000u);   // 1 / 1024
  *(float *)(self + 0x14) = (float)*(s32 *)(G(u8 *, 0x70039c) + 0x40) * k;
  *(float *)(self + 0x18) = (float)*(s32 *)(G(u8 *, 0x70039c) + 0x40) * k;
  s32 now = *(s32 *)(G(u8 *, 0x70039c) + 0x40);
  self[0x20] = 0;
  *(float *)(self + 0x1c) = (float)now * k;
  return 1;
}
PCREG(5e0500, throwExecute);

// 0x5e0600 ZFFActionThrow::Terminate(), thiscall. Turns the OSD throw meter off (hero +8, +0x852, byte +0x22ce = 0).
static void THISCALL throwTerminate(u8 *self) {
  ext_59a6a0(*(u8 **)(*(u8 **)(self + 8) + 0x852), 0);
}
PCREG(5e0600, throwTerminate);

// 0x43e8e0, fastcall (dst in ECX, a in EDX), one stack arg b, ret 4. dst = a + b on three floats, all sums before the
// stores. The x87 adds under 53-bit precision round once more to float, which gives the same bits as float adds.
static void FASTCALL psVecAdd3(float *dst, const float *a, const float *b) {
  float s0 = a[0] + b[0];
  float s1 = a[1] + b[1];
  float s2 = a[2] + b[2];
  dst[0] = s0;
  dst[1] = s1;
  dst[2] = s2;
}
PCREG(43e8e0, psVecAdd3);

// 0x44e630 vnorm(float *dst, const float *src), fastcall, result in ST0. All three components exactly 0: dst = 0 and
// the result is 0. Otherwise len = sqrt(x*x + y*y + z*z) and dst = src * (1 / len), in double (53-bit x87), and the
// result is len rounded to float. A NaN component counts as non-zero.
static float FASTCALL vnormTo(float *dst, const float *src) {
  if (src[0] == 0.0f && src[1] == 0.0f && src[2] == 0.0f) {
    dst[0] = 0.0f;
    dst[1] = 0.0f;
    dst[2] = 0.0f;
    return 0.0f;
  }
  double x = src[0], y = src[1], z = src[2];
  double len = crt::sqrt(((x * x) + (y * y)) + (z * z));
  double inv = 1.0 / len;
  dst[0] = (float)((double)src[0] * inv);
  dst[1] = (float)((double)src[1] * inv);
  dst[2] = (float)((double)src[2] * inv);
  return (float)len;
}
PCREG(44e630, vnormTo);

// 0x451890 vaddscalar(float *dst, const float *v, float s), fastcall, ret 4. dst += v * s on three floats. Each
// product is exact in double and the add rounds in double before the float store, so the port uses double math.
static void FASTCALL vaddScalar(float *dst, const float *v, float s) {
  double m0 = (double)v[0] * s, m1 = (double)v[1] * s, m2 = (double)v[2] * s;
  float r0 = (float)(m0 + dst[0]);
  float r1 = (float)(m1 + dst[1]);
  float r2 = (float)(m2 + dst[2]);
  dst[0] = r0;
  dst[1] = r1;
  dst[2] = r2;
}
PCREG(451890, vaddScalar);
