// batch992.cpp - area 56 claim A59 (0x633910, CRT float-to-unsigned helper used by round()).
// BLOCKER: This function uses VECTORCALL (float in xmm0), but the pilot framework doesn't support
// VECTORCALL for input arguments. The current approach (passing float bits via FASTCALL ecx) doesn't
// correctly map the calling convention, causing mismatches with the exe version.
// Status: Temporarily using exe code hook; needs proper VECTORCALL support or a different strategy.
#include "ff.h"

extern "C" u32 VECTORCALL ext_633910_exe(float f);  // Call exe code for now

static u32 FASTCALL floatToUnsigned633910(u32 f_bits) {
  // Placeholder: just call exe code
  float f = *(float *)&f_bits;
  return ext_633910_exe(f);
}
PCREG(633910, floatToUnsigned633910);
