// batch373.cpp - 0x403e50 (gap band, mid-size). cdecl(dst, src): for i in 0..55: if src[i] > dst[i] (ordered): dst[i] = src[i].
// The exe compares with fcomp and tests C0|C3; an unordered compare sets C0 and C3, so NaN never copies.
#include "ff.h"

static void copyIfGreater56(float *dst, const float *src) {
  for (int i = 0; i < 56; i++) {
    if (src[i] > dst[i])
      dst[i] = src[i];
  }
}
PCREG(403e50, copyIfGreater56);
