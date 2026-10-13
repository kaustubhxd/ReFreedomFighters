// batch4156.cpp - unclaimed-41 batch 49 (residue 0 of the relevant list): 0x483f00 (bit 10 of the dword at +0x417); thiscall, no stack arguments.
#include "ff.h"

static u8 THISCALL fn483f00(u8 *self) {
  return (u8)((*(u32 *)(self + 0x417) >> 10) & 1);
}
PCREG(483f00, fn483f00);
