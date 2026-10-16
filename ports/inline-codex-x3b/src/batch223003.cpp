#include "ff.h"

extern "C" void THISCALL ext_662fd0(u8 *self, const float *vector);
extern "C" u8 THISCALL ext_6627c0(u8 *self, float *value);
extern "C" void FASTCALL ext_4e0130(float *out, const float *from,
                                      const float *to, float max_angle);

// 0x662f40: thiscall(this, output_vec), ret 4 (AL).  First accepts a new
// destination vector, advances the scalar easing member, rotates the current
// vector from its snapshot toward the destination, then writes the new current
// vector to the caller's buffer.
u8 THISCALL fn_662f40(u8 *self, float *output_vec) {
  ext_662fd0(self, output_vec); // m0
  float angle = *(float *)(self + 0x34);
  u8 done = ext_6627c0(self + 0x34, &angle); // m1
  ext_4e0130((float *)(self + 4), (const float *)(self + 0x1c),
             (const float *)(self + 0x10), angle); // m2
  ((u32 *)output_vec)[0] = ((u32 *)(self + 4))[0]; // m3
  ((u32 *)output_vec)[1] = ((u32 *)(self + 4))[1];
  ((u32 *)output_vec)[2] = ((u32 *)(self + 4))[2]; // m4
  return done;
}
PCREG(662f40, fn_662f40);
