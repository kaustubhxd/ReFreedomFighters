// batch9601.cpp - residue 6 batch 96: FUN_004643e0
#include "ff.h"

// 0x4643e0 (GUESS FUN_004643e0): thiscall, two arguments a, b, ret void.
// Stores a at [this+0x5c] and b at [this+0x64].
static void THISCALL guess4643e0(void *self, u32 a, u32 b) {
  *(u32 *)((u8 *)self + 0x5c) = a;
  *(u32 *)((u8 *)self + 0x64) = b;
}
PCREG(4643e0, guess4643e0);
