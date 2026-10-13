// batch 100: simple residue 6 getters 0x46b6e0, 0x593ae0, 0x596ce0
#include "ff.h"

// 0x46b6e0: thiscall, no arguments, returns byte in AL
static u8 THISCALL guess46b6e0(void *self) {
  return ((u8 *)self)[0xc4];
}
PCREG(46b6e0, guess46b6e0);

// 0x593ae0: thiscall, no arguments, returns byte in AL
static u8 THISCALL guess593ae0(void *self) {
  return ((u8 *)self)[0x828];
}
PCREG(593ae0, guess593ae0);

// 0x596ce0: thiscall, no arguments, returns dword in EAX
static u32 THISCALL guess596ce0(void *self) {
  return *(u32 *)((u8 *)self + 0x1fb6);
}
PCREG(596ce0, guess596ce0);
