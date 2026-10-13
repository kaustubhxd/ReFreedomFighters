// batch1062.cpp - area 81, batch 1062: 0x634340, __allmul (64-bit multiply)
// CRT utility for 64-bit * 32-bit multiplication with 4 arguments
// Takes: a_low, a_high, b, unused on stack; returns EDX:EAX = (a_high:a_low) * b
#include "ff.h"

static u64 STDCALL batch1062_allmul(u32 a_low, u32 a_high, u32 b, u32 unused) {
  // Multiply 64-bit value (a_high:a_low) by 32-bit value b
  // Result is a 64-bit value (or higher if overflow, but we return 64 bits)
  // unused parameter: might be for alignment or historical reasons
  (void)unused;
  u64 a64 = ((u64)a_high << 32) | a_low;
  return a64 * b;
}

PCREG(634340, batch1062_allmul);
