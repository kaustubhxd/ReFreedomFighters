// batch4153.cpp - unclaimed-41 batch 49 (residue 0 of the relevant list): 0x468200 (getter of the dword at +0x1d2); thiscall, no stack arguments.
#include "ff.h"

static u32 THISCALL fn468200(u8 *self) {
  return *(u32 *)(self + 0x1d2);
}
PCREG(468200, fn468200);
