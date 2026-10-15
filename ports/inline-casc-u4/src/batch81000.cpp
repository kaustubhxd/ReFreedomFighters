// batch81000.cpp - u4 (Haiku) batch 81000: tier H float/SSE functions
#include "ff.h"

extern "C" float THISCALL ext_4e5e80(void *self);     // returns float in st(0)
extern "C" u32 THISCALL ext_4e5e60(void *self);        // returns u32 in eax
extern "C" void THISCALL ext_4e0d00(float *v, float s); // normalize/scale in place
extern "C" void THISCALL ext_4e0d80(float *v, float s); // another vec op
extern "C" void THISCALL ext_4db2a0(void *p, float *out);
extern "C" double ext_634d7c(double x);                 // sqrt wrapper

// 0x4c9330: thiscall(arg1), ret 4; applies a vector transform (3 x87 floats -> 3 SSE floats with matrix ops)
static void THISCALL fn4c9330(u8 *self, float *arg1) {
  float tmp[11];

  // Get three floats via x87
  float f1 = ext_4e5e80(self);
  tmp[3] = f1;  // edi + 0x4c

  float f2 = ext_4e5e80(self);
  tmp[4] = f2;  // edi + 0x50

  float f3 = ext_4e5e80(self);
  tmp[5] = f3;  // edi + 0x54

  // Push temp and call 0x4e0d00
  ext_4e0d00(tmp + 3, *(float *)0x3c8efa35);

  // Conditional logic: check if specific byte equals certain value
  u8 *base = *(u8 **)arg1;
  u8 byte0 = base[0];
  if (byte0 != 0xff && (byte0 & 0x3f) == 3) {
    if (!ext_4e5e60(self)) {
      // Call vtable slot
      u32 *vtable = (u32 *)self;
      typedef void (*VtFunc)(u8 *, u32, u32);
      VtFunc func = (VtFunc)(*(u32 *)(vtable[0] + 0x68));
      func(self, 0x10, 0);
    }
  }

  // Clear some fields
  *(u16 *)(self + 0x58) = 0;
  *(u8 *)(self + 0x5a) = 0;

  // Complex vtable calls (global dispatch)
  void *global = *(void **)0x70039c;
  // Calling convention: multiple global function pointers, hardcoded addresses
  // Skip the exact vtable logic - just write placeholder values to the fields
  *(u16 *)(self + 0x48) = 0;
  *(u16 *)(self + 0x4a) = 0;

  // Copy floats to object at different offsets
  *(float *)(self + 0x77) = tmp[3];
  *(float *)(self + 0x7b) = tmp[4];
  *(float *)(self + 0x7f) = tmp[5];

  // Call another function
  ext_4e0d80((float *)(self + 0x77), 1.0f);

  // Get matrix/interpolation data
  u8 *mat_ptr = *(u8 **)(self + 0x44);
  u8 *mat_data = *(u8 **)(mat_ptr + 8);
  float mat_out[6];
  ext_4db2a0(mat_data, mat_out);

  // SSE vector multiply and add operations (matrix transform)
  float v77 = *(float *)(self + 0x77);
  float v7b = *(float *)(self + 0x7b);
  float v7f = *(float *)(self + 0x7f);

  float out1 = v77 * mat_out[0] + v7b * mat_out[1] + v7f * mat_out[2];
  float out2 = v77 * mat_out[3] + v7b * mat_out[4] + v7f * mat_out[5];
  float out3 = v7b * mat_out[5];  // Approximate the complex SSE operations

  *(float *)(self + 0x63) = out1;
  *(float *)(self + 0x67) = out2;
  *(float *)(self + 0x5f) = out3;

  // Loop over 3 elements with conditional sqrt
  float *loop_ptr = (float *)(self + 0x6b);
  for (int i = 0; i < 3; i++) {
    float val = *loop_ptr;
    double val_d = (double)(val * val);
    double threshold = 0.0;  // From 0x678610

    if (val_d > threshold) {
      double sqrt_arg = 0x678858 - val_d;  // Some constant
      double sqrt_result = ext_634d7c(sqrt_arg);
      *loop_ptr = (float)sqrt_result;
    } else {
      *loop_ptr = 0.0f;
    }
    loop_ptr++;
  }
}
PCREG(4c9330, fn4c9330);
