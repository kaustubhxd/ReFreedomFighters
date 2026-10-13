// batch785.cpp - gap band batch 785 (docs/20-gap-band-401000.md): 0x402290, cdecl (p, out), returns an int.
#include "ff.h"

typedef int i32;

static u32 __attribute__((cdecl)) fn402290(u32 *p, u32 *out) {
  const i32 idx = (i32)p[6];
  if (idx <= -1 || idx >= (i32)p[0xc]) return 0;
  if (out != nullptr) {
    u32 *X = (u32 *)p[1];
    i32 i = 0;
    if ((i32)X[1] > 0) {
      do {
        u32 *A = (u32 *)p[2];
        u32 *B = (u32 *)p[3];
        B[i] = A[i] + (u32)idx * 4;
        ++i;
      } while (i < (i32)X[1]);
    }
    *out = p[3];
  }
  return p[0xc] - p[6];
}

PCREG(402290, fn402290);
