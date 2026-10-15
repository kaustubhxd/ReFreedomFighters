// batch70000.cpp - cascade t1 (Haiku): four tier H (float / SSE) functions.
#include "ff.h"

static inline float rdf(const u8 *p) { u32 b = p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); float f; __builtin_memcpy(&f, &b, 4); return f; }

// 0x466b70, thiscall no args, returns float st0
// Reads [this+0x35] (float), [this+0x31] (float), global[0x70039c][0x40] (u32 index)
static float THISCALL fn466b70(u8 *self) {
  float f1 = rdf(self + 0x35);
  float f2 = rdf(self + 0x31);

  u8 *global_ptr = *(u8 **)(0x70039c);
  u32 idx = *(u32 *)(global_ptr + 0x40);

  // Compute abs value and apply mask
  u32 f1_bits = *(u32 *)&f1;
  f1_bits &= 0x7fffffff;  // abs mask
  float f1_abs = *(float *)&f1_bits;

  float scale1 = G(float, 0x678620);
  float scaled_f1 = f1_abs * scale1;
  int idx_scaled = (int)scaled_f1;

  int offset = (int)idx - idx_scaled;
  float result = (float)offset * G(float, 0x6785e4);

  // Branch logic based on original f1 sign and comparisons
  if (f1 < 0.0f) {
    // f1 is negative
    if (result > f2) {
      return 0.0f;
    } else if (f2 <= 0.0f) {
      return 1.0f;
    } else {
      // f2 > 0
      return result / f2;
    }
  } else {
    // f1 is >= 0
    if (f2 > result) {
      return result / f2;
    } else {
      // f2 <= result
      return 1.0f;
    }
  }
}
PCREG(466b70, fn466b70);
