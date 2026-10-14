// batch35188.cpp - cascade s5 batch 35188 (tier H): 0x636690 (GUESS blend every pixel of every level of an image towards or away from its luma: a saturation control).
#include "ff.h"

extern "C" s32 VECTORCALL ext_633910(float f);   // CRT float-to-int helper, argument in XMM0, result in EAX

static inline float cvt(u32 v) { return (float)((double)(int)v + G(double, 0x680aa0)); }
static inline float clampf(float x) {
  if (0.0f > x) return 0.0f;
  float one = G(float, 0x678858);
  return (one < x) ? one : x;
}

// 0x636690, thiscall(float t) ret 4, no return value. For each level k (count dword [this+0x10], signed) with record rec = [this+0x14] + 0x14 * k (width [rec+4], rows [rec+8], pixel base [rec+0x10]) and each pixel p
// (dword at base + (row * width + x) * 4; B = byte 0, G = byte 1, R = byte 2, alpha kept): c' = c * K0 (0x682eb8, as float from the converted byte); luma = G' * [0x6be13c] + R' * [0x6be144] + B' * [0x6be140]; each channel
// c'' = clamp((c' - luma) * t + luma) to [0, 1] (0 for below, min with 1.0 at 0x678858 above); the byte is (CRT float-to-int of c'' * K255 (0x68af18)); p = (p & 0xff000000) + (((R << 8) + G) << 8) + B (wrapping adds).
static void THISCALL fn636690(u8 *self, float t) {
  for (s32 k = 0; k < *(s32 *)(self + 0x10); k++) {
    u8 *rec = *(u8 **)(self + 0x14) + 0x14 * k;
    u32 *base = *(u32 **)(rec + 0x10);
    for (s32 row = 0; row < *(s32 *)(rec + 8); row++) {
      s32 w = *(s32 *)(rec + 4);
      if (w <= 0) continue;
      u32 *ptr = base + (u32)(w * row);
      s32 x = 0;
      do {
        u32 p = ptr[x];
        float R = cvt((p >> 16) & 0xff) * G(float, 0x682eb8);
        float Gc = cvt((p >> 8) & 0xff) * G(float, 0x682eb8);
        float B = cvt(p & 0xff) * G(float, 0x682eb8);
        float luma = Gc * G(float, 0x6be13c);
        float t1 = R * G(float, 0x6be144);
        luma = luma + t1;
        float t2 = B * G(float, 0x6be140);
        luma = luma + t2;
        float r2 = clampf((R - luma) * t + luma);
        float g2 = clampf((Gc - luma) * t + luma);
        float b2 = clampf((B - luma) * t + luma);
        u32 ri = (u32)ext_633910(r2 * G(float, 0x68af18));
        u32 gi = (u32)ext_633910(g2 * G(float, 0x68af18));
        u32 bi = (u32)ext_633910(b2 * G(float, 0x68af18));
        u32 out = (ri << 8) + gi;
        out = (out << 8) + bi;
        ptr[x] = (p & 0xff000000u) + out;
        x++;
      } while (x < *(s32 *)(rec + 4));
    }
  }
}
PCREG(636690, fn636690);
