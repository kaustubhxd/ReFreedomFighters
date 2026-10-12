// batch1938.cpp - unclaimed-66 batches 38 and 39 (gap band; GUESS names). Thiscall, no arguments.
//   0x51f4a0: 0x511950(ECX = this+0x2d8) (a recording stub in the spec); then a tail jump to 0x512070 with ECX = this (exe code, bound).
//   0x51f4c0: [this] = 0x69fb3c first; then the same as 0x51f4a0.
#include "ff.h"

extern "C" void THISCALL ext_511950(void *self);   // thiscall, no arguments (recording stub in the spec)
extern "C" void THISCALL ext_512070(void *self);   // the base dtor step (batch 37; exe code bound here)

// 0x51f4a0, GUESS FUN_0051f4a0 (batch 38).
static void THISCALL wrapA(u8 *self) {
  ext_511950(self + 0x2d8);
  ext_512070(self);
}
PCREG(51f4a0, wrapA);

// 0x51f4c0, GUESS FUN_0051f4c0 (batch 39).
static void THISCALL wrapB(u8 *self) {
  *(u32 *)self = 0x69fb3c;
  ext_511950(self + 0x2d8);
  ext_512070(self);
}
PCREG(51f4c0, wrapB);
