// batch4158.cpp - unclaimed-41 batch 50 (residue 0 of the relevant list): 0x483b40 (dword at this+0x45d+4*i); thiscall.
#include "ff.h"

static u32 THISCALL fn483b40(u8 *self, u32 i) {
  return *(u32 *)(self + 0x45d + 4 * i);
}
PCREG(483b40, fn483b40);
