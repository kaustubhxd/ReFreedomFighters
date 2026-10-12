// batch4132.cpp - unclaimed-41 batch 32 (core-todo residue-19): 0x43abb0 ZInputActions::ActivateMap(const char*) (thiscall with one
// stack argument p, ret 4; ecx is not read). For a non-null p: the dword at p+0x29 is cleared, then byte p+0x2e &= 0x2f and byte p+0x2f &= 0x01.
#include "ff.h"

static void THISCALL fn43abb0(u8 *ecxUnused, u8 *p) {
  (void)ecxUnused;
  if (p != 0) {
    *(u32 *)(p + 0x29) = 0;
    p[0x2e] &= 0x2f;
    p[0x2f] &= 0x01;
  }
}
PCREG(43abb0, fn43abb0);
