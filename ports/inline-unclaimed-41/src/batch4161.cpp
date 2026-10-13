// batch4161.cpp - unclaimed-41 batch 50 (residue 0 of the relevant list): 0x4e5480 (byte at [this+8] + [p]); thiscall.
#include "ff.h"

static u8 THISCALL fn4e5480(u8 *self, u8 *p) {
  return ((u8 *)(*(u32 *)(self + 8) + *(u32 *)p))[0];
}
PCREG(4e5480, fn4e5480);
