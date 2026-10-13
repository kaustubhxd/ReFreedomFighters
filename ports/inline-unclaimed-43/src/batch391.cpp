// batch391.cpp - 0x641d80 (core: ZRagdollContainer::GetGravityValue, thiscall, no arguments). Returns the float global
// at 0x6ec3cc in ST0 (exe: fld dword ptr [0x6ec3cc]; ret). ECX is not used.
#include "ff.h"

static float THISCALL ragdollGravityValue(void *self) {
  (void)self;
  return G(float, 0x6ec3cc);
}
PCREG(641d80, ragdollGravityValue);
