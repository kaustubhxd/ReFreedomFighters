// batch4159.cpp - unclaimed-41 batch 50 (residue 0 of the relevant list): 0x4711c0 (returns the old dword at +0x68 and stores the argument); thiscall.
#include "ff.h"

static u32 THISCALL fn4711c0(u8 *self, u32 v) {
  u32 old = *(u32 *)(self + 0x68);
  *(u32 *)(self + 0x68) = v;
  return old;
}
PCREG(4711c0, fn4711c0);
