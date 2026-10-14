// batch5710.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 10: vmul(float*, const float*, const float*) (0x4e0940, medium name),
// fastcall: out in ECX, b in EDX, a on the stack (callee pops, ret 4). out[i] = a[i] * b[i] for i = 0..2, single precision (mulss).
#include "ff.h"

// 0x4e0940, vmul (medium)
static void FASTCALL vmul(float *out, const float *b, const float *a) {
  out[0] = a[0] * b[0];
  out[1] = a[1] * b[1];
  out[2] = a[2] * b[2];
}
PCREG(4e0940, vmul);
