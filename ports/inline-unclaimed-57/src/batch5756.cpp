// batch5756.cpp - unclaimed-57, band batch 56 (name GUESS): 0x5d8740, thiscall, no args, ret. Two helpers write floats through pointers into the
// function's frame: 0x4db500(ECX = dword (dword this+0x44)+8, &f1) (thiscall, one argument; unverified, hooked: writes a fixed float, the pointer is
// not logged); this+0x4c = f1; 0x4db7c0(ECX = dword (dword this+0x44)+8, &f2) (same shape); this+0x50 = f2. The stack-cookie check 0x633654 is
// the same no-op hook as in batch 48 (the cookie is unchanged).
#include "ff.h"

extern "C" void THISCALL ext_4db500(u8 *self, float *out);  // hooked in the spec (writes through out, pointer not logged)
extern "C" void THISCALL ext_4db7c0(u8 *self, float *out);  // hooked in the spec (writes through out, pointer not logged)

static void THISCALL unnamed5d8740(u8 *self) {
  float f1;
  ext_4db500(*(u8 **)(*(u8 **)(self + 0x44) + 8), &f1);
  *(float *)(self + 0x4c) = f1;
  float f2;
  ext_4db7c0(*(u8 **)(*(u8 **)(self + 0x44) + 8), &f2);
  *(float *)(self + 0x50) = f2;
}
PCREG(5d8740, unnamed5d8740);
