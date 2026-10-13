// batch1147.cpp - unclaimed-11 batch 48 (slice 10 gap band): 0x5bc160, GUESS (Save-like; one arg, ret 4, returns al = 1).
#include "ff.h"

// The float at +0x4d is passed as raw bits (the PC moves it with movss), so a NaN reaches the slot unchanged.
static bool THISCALL guessSaveFields(u8 *self, void *ser) {
  *(u32 *)(self + 4) &= ~0x40u;
  vcall<void>(ser, 0x64, *(u32 *)(self + 0x48));
  vcall<void>(ser, 0x60, (u32) * (self + 0x4c));
  vcall<void>(ser, 0x4c, *(u32 *)(self + 0x4d));
  vcall<void>(ser, 0x3c, *(u32 *)(self + 0x51));
  vcall<void>(ser, 0x3c, *(u32 *)(self + 0x55));
  vcall<void>(ser, 0x3c, *(u32 *)(self + 0x5d));
  vcall<void>(ser, 0x3c, *(u32 *)(self + 0x59));
  return true;
}
PCREG(5bc160, guessSaveFields);
