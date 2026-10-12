// batch2427.cpp - decomp area 24, batch 2427.
#include "ff.h"

// 0x61bc30 (GUESS owner), cdecl, plain ret: slot 0x14 of the object (first argument) with the second and third
// arguments; eax is the slot's result.
static u32 cdeclForwardSlot14(void *obj, u32 a, u32 b) {
  return vcall<u32>(obj, 0x14, a, b);
}
PCREG(61bc30, cdeclForwardSlot14);

// 0x435e70 ZInputDeviceGameControlBase::IsConnected(int), thiscall, ret 4, float on st0. count at +0x61 (signed).
static float THISCALL inputIsConnected(u8 *self, s32 idx) {
  s32 cnt = *(s32 *)(self + 0x61);
  if (idx <= cnt)
    return *(float *)(self + 0x1d + idx * 4);
  return 0.0f;
}
PCREG(435e70, inputIsConnected);
