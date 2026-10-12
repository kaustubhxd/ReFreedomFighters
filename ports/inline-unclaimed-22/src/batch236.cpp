// batch236.cpp - area 59 (residue 18), docs/20-unclaimed-59.md. Writes a row of a table at this->[+0xf] + a1 * 0x34:
// the 12 bytes at +0xc (from P, after a call that builds a local), +0x18 (from R), +0x24 (from Q) and a float at +0x30.
// Stack args: a1, P, Q, f, R (ret 0x14). Name GUESS.
#include "ff.h"

extern "C" void THISCALL ext_43e920(u8 *self, u8 *dst);   // original, thiscall, one stack word (ret 4); builds *self

// 0x5477a0, thiscall(a1, P, Q, f, R) ret 0x14.
static void THISCALL setRow_5477a0(u8 *self, u32 a1, u32 *P, u32 *Q, float f, u32 *R) {
  u32 idx = a1 * 0x34u;
  u8 *B0 = *(u8 **)(self + 0xf);
  u8 *dst = B0 + idx + 0xc;
  u8 local[12];
  ext_43e920(local, dst);
  ((u32 *)dst)[0] = P[0];
  ((u32 *)dst)[1] = P[1];
  ((u32 *)dst)[2] = P[2];
  B0 = *(u8 **)(self + 0xf);
  *(u32 *)(B0 + idx + 0x24) = Q[0];
  *(u32 *)(B0 + idx + 0x28) = Q[1];
  *(u32 *)(B0 + idx + 0x2c) = Q[2];
  *(float *)(B0 + idx + 0x30) = f;
  *(u32 *)(B0 + idx + 0x18) = R[0];
  *(u32 *)(B0 + idx + 0x1c) = R[1];
  *(u32 *)(B0 + idx + 0x20) = R[2];
}
PCREG(5477a0, setRow_5477a0);
