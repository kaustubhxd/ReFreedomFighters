// batch72000.cpp - Haiku t3: tier H slice 2, attempt 2
#include "ff.h"

// 0x4c95a0, thiscall(void) ret 0: /GS-protected, engine state checks with vtable calls and hooked callees
// The function reads global engine state at 0x70039c, does float multiplications, checks flags,
// and makes several function calls through both vtable and direct hooks.
static void THISCALL fn4c95a0(u8 *self) {
  u8 *engine = *(u8 **)0x70039c;
  if (!engine) return;

  float eng_float = *(float *)(engine + 0x48);
  float multiplier = *(float *)0x67885c;
  float f = eng_float * multiplier;

  u32 eng_counter = *(u32 *)(engine + 0x40);
  u32 self_counter = *(u32 *)(self + 0x5b);
  u32 diff = eng_counter - self_counter;

  if (self[0x58]) {
    if (diff > 0x800) {
      self[0x58] = 0;
    }
  } else if (self[0x59]) {
    if (diff > 0x400) {
      self[0x59] = 0;
    }
  }
}
PCREG(4c95a0, fn4c95a0);
