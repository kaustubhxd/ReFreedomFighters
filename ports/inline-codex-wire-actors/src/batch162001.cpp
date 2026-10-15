// HealthSet 0x5a83e0, function copied unchanged from batch33100.
#include "ff.h"
static inline u32 R32(u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
extern "C" void THISCALL ext_5ec090(u8 *, u32, u32);
extern "C" u32 THISCALL ext_5a5d00(u8 *, u32, u32, u32);
extern "C" void THISCALL ext_5ec340(u8 *, u32, u32);
static void THISCALL fn5a83e0(u8 *self, u32 xb) {
  float x = bitsf(xb);
  if (x == *(float *)(self + 0x2fc)) return;
  u8 flag = self[0x658];
  float m = (1.0f < x) ? 1.0f : x;
  float c = (0.0f > m) ? 0.0f : m;
  *(float *)(self + 0x2fc) = c;
  u32 v;
  if (0.0f >= c) {
    v = 0;
  } else {
    float k = flag ? 55.0f : 119.0f;
    float t = c * k;
    t = t + 1.0f;
    v = (u32)_mm_cvttss_si32(_mm_set_ss(t));
  }
  ext_5ec090(*(u8 **)(self + 0x434), v, 8);
  u32 f = R32(self + 0x2fc);
  u32 r = ext_5a5d00(self, f, 0x3f800000u, 0u);
  ext_5ec340(*(u8 **)(self + 0x434), r, 0xffffffffu);
}
PCREG(5a83e0, fn5a83e0);
