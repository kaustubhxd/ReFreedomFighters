// batch6357.cpp - unclaimed-63 batch 57: 0x5e90d0 ZWeaponRecycleList::CopyEventDataBlock(DBREAD&) (name from the core list), thiscall,
//   one stack argument r, ret 4. The float value f = 0x4e5e80(r) (thiscall with the argument in ECX, no stack arguments, the float
//   returned in st0; other areas' code, stubbed) is stored at this[+0x44c] (fstp dword).
#include "ff.h"

extern "C" float THISCALL ext_4e5e80(void *reader);   // float return in st0, original code, stubbed by the spec

// 0x5e90d0.
static void THISCALL unnamed5e90d0(u8 *self, u32 r) {
  float f = ext_4e5e80((void *)r);
  *(float *)(self + 0x44c) = f;
}
PCREG(5e90d0, unnamed5e90d0);
