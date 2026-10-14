// batch1631.cpp - ZDllSound::CalcVolume (soundtimers thread, 2026-10-11).
#include "st.h"

extern "C" char ext_634dd6[];  // CRT log10 (libm_sse2_log10_precise thunk; double in xmm0, double out in xmm0)
typedef double(VECTORCALL *Log10Fn)(double);

// 0x535940 ZDllSound::CalcVolume(float x) [medium name]: the volume in hundredths of a decibel-like step. x == 0 gives
// -10000; otherwise 3000 x log10(x / 100) truncated to int (the float is divided by 100, the log is taken in double
// precision, the product is rounded to float before the truncation). NaN goes through the log path (the compare with
// 0 is unordered, as the original's jnp), and truncation of NaN gives the integer indefinite value.
// GUESS: the name; the meaning of the scale is not traced.
s32 THISCALL ZDllSound_CalcVolume(void *self, float x) {
  (void)self;
  if (x == 0.0f) return -10000;
  float q = x / 100.0f;
  double l = ((Log10Fn)(void *)ext_634dd6)((double)q);
  float f = (float)(l * 3000.0);
  return _mm_cvttss_si32(_mm_set_ss(f));
}
PCREG(535940, ZDllSound_CalcVolume);
