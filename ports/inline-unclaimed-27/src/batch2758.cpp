#include "ff.h"
// batch2758.cpp - unclaimed-27 batch 58 (residue 6). Copy 3 dwords, 17 bytes.
// FUN_00460e20: GUESS name. Fastcall (or special), copies 3 dwords from [edx] to [ecx], returns void.

static void FASTCALL funcCopy3Dwords(u32 *dst, u32 *src) {
  dst[0] = src[0];
  dst[1] = src[1];
  dst[2] = src[2];
}

PCREG(460e20, funcCopy3Dwords);
