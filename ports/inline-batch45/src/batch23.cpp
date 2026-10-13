// batch23.cpp - first-level functions, inline session batch 23 (Haiku, overnight).
#include "ff.h"

// 0x45b0f0, thiscall (ret 8, returns AL), stack args v (3 floats) and t: returns 1 when, for each k, the float at
// this+0x18+4k minus t (rounded to float) is at least |v[k]| (widened to double, sign cleared). A NaN fails. Name unknown.
static u8 THISCALL inBox(u8 *self, const float *v, float t) {
  for (int k = 0; k < 3; k++) {
    float d = *(float *)(self + 0x18 + 4 * k) - t;
    u64 bits = __builtin_bit_cast(u64, (double)v[k]) & 0x7fffffffffffffffULL;
    double a = __builtin_bit_cast(double, bits);
    if (!((double)d >= a))
      return 0;
  }
  return 1;
}
PCREG(45b0f0, inBox);

// 0x446280, thiscall (ret 8), stack pointers out (3 floats) and out2 (3 floats, may be null only when bit 0 of this+0x48 is
// set). With bit 0 set: out[0] = out[0] / this+0x3c, out[1] = out[1] / this+0x40, out[2] = 0; when out2 is not null it
// gets (0, 0, 1.0f). With bit 0 clear: out2[2] = 1.0f, out2[1] = out[1] / this+0x58 / this+0x40, out2[0] = out[0] /
// this+0x58, then out gets (0, 0, 0). out2 is written before out is cleared, as in the original. Name unknown.
static void THISCALL divPair2(u8 *self, float *out, float *out2) {
  if (self[0x48] & 1) {
    float y = out[1] / *(float *)(self + 0x40);
    float x = out[0] / *(float *)(self + 0x3c);
    out[2] = bitsf(0);
    out[1] = y;
    out[0] = x;
    if (out2) {
      out2[0] = bitsf(0);
      out2[1] = bitsf(0);
      out2[2] = 1.0f;
    }
    return;
  }
  float y = out[1] / *(float *)(self + 0x58);
  y = y / *(float *)(self + 0x40);
  float x = out[0] / *(float *)(self + 0x58);
  out2[2] = 1.0f;
  out2[1] = y;
  out2[0] = x;
  out[0] = bitsf(0);
  out[1] = bitsf(0);
  out[2] = bitsf(0);
}
PCREG(446280, divPair2);

// 0x46eef0, thiscall (ret 4, returns AL): copies three dwords from this+0xaa, +0xae, +0xb2 into out[0..2] as raw bits,
// then returns 1 unless all three are equal to 0.0 (ordered compare; a NaN counts as not zero). Name unknown.
static u8 THISCALL copy3Check(u8 *self, float *out) {
  *(u32 *)out = *(u32 *)(self + 0xaa);
  *(u32 *)(out + 1) = *(u32 *)(self + 0xae);
  *(u32 *)(out + 2) = *(u32 *)(self + 0xb2);
  return !(out[0] == 0.0f && out[1] == 0.0f && out[2] == 0.0f);
}
PCREG(46eef0, copy3Check);
