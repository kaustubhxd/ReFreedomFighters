// batch911.cpp - unclaimed-09 batch 3: CMAINCAMERACONTROL::GetOldCam and ToggleFreeCam (docs/20-unclaimed-09.md).
// Both are thiscall. Names are from the GC name map (low confidence: GUESS).
#include "ff.h"

// 0x4fc680, CMAINCAMERACONTROL::GetOldCam() (low): returns the dword at this+0x74 in eax.
static u32 THISCALL camGetOldCam(u8 *self) {
  return *(u32 *)(self + 0x74);
}
PCREG(4fc680, camGetOldCam);

// 0x4fdd10, CMAINCAMERACONTROL::ToggleFreeCam() (low): stores 1 as a byte at this+0x69.
static void THISCALL camToggleFreeCam(u8 *self) {
  self[0x69] = 1;
}
PCREG(4fdd10, camToggleFreeCam);
