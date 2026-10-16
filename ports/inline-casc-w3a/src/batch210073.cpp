// batch210073.cpp - Sonnet-w3a: 0x42ab62 (printf-style wrapper: output stream 1, format, varargs pointer)
#include "ff.h"

extern "C" u32 ext_634d64(u32 which);
extern "C" u32 ext_42ab26(u32 file, u32 fmt, u32 opt, u32 *ap);

static u32 fn42ab62(u32 fmt, u32 a1, u32 a2) {
  (void)a2;
  u32 f = ext_634d64(1);  // @42ab62_a
  return ext_42ab26(f, fmt, 0, &a1);  // @42ab62_b
}
PCREG(42ab62, fn42ab62);
