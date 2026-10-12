#include "ff.h"
// batch1382.cpp - unclaimed-13 claim 1, batch 2 (docs/20-unclaimed-13.md). Name from the GC name map (naming only).

// 0x4a5fc0, ZMatPosAnim::SetRotMat(float*) (high): copies 36 bytes (nine dwords, a 3x3 float matrix and one dword) from
// the argument to this+0x93. The original calls the copy helper at 0x4de420 (movups x2, mov); the port copies the bytes
// itself, dword by dword, in the same order.
static void THISCALL matPosAnimSetRotMat(u8 *self, const u32 *src) {
  u32 *dst = (u32 *)(self + 0x93);
  for (int i = 0; i < 9; i++) dst[i] = src[i];
}
PCREG(4a5fc0, matPosAnimSetRotMat);
