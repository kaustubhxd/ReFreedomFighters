// batch8181.cpp - residue 6 batch 81 (GUESS name): FUN_0065c9e0.
#include "ff.h"

// 0x65c9e0 (GUESS FUN_0065c9e0): returns the old dword at this+4 and advances it by 8.
static u32 THISCALL guess65c9e0(u8 *self) {
  u32 old = *(u32 *)(self + 4);
  *(u32 *)(self + 4) = old + 8;
  return old;
}
PCREG(65c9e0, guess65c9e0);
