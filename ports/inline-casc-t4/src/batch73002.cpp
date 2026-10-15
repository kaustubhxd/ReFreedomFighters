#include "ff.h"

extern "C" void THISCALL ext_4da1d0(u8 *self, u32 flag);
extern "C" void THISCALL ext_4dd060(u8 *self, const float *v);
extern "C" void THISCALL ext_4dce50(u8 *self, float v);

static void THISCALL fn44f480(u8 *self) {
  u8 *o = *(u8 **)(self + 8);
  ext_4da1d0(o, 1);
  float x = *(float *)(o + 0x40);
  float y = *(float *)(o + 0x44);
  float z = *(float *)(o + 0x48);
  __m128 m = _mm_set_ss(y);
  m = _mm_max_ss(m, _mm_set_ss(x));
  m = _mm_max_ss(m, _mm_set_ss(z));
  float maxv = _mm_cvtss_f32(m);
  float scaled = maxv * G(float, 0x67da1c);
  float v[3] = {maxv, scaled, maxv};
  ext_4dd060(o, v);
  x = *(float *)(o + 0x40);
  y = *(float *)(o + 0x44);
  z = *(float *)(o + 0x48);
  float sum = x * x;
  sum = sum + y * y;
  sum = sum + z * z;
  double root = crt::sqrt((double)sum);
  ext_4dce50(o, (float)root + G(float, 0x678858));
}
PCREG(44f480, fn44f480);
