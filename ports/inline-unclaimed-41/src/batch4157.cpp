// batch4157.cpp - unclaimed-41 batch 49 (residue 0 of the relevant list): 0x52a1c0 (three constant stores); thiscall, no stack arguments.
#include "ff.h"

static void THISCALL fn52a1c0(u8 *self) {
  *(u32 *)(self + 0x29) = 0x43960000u;
  *(u32 *)(self + 0x2d) = 0xc3c80000u;
  *(u32 *)(self + 0x31) = 0xc0800000u;
}
PCREG(52a1c0, fn52a1c0);
