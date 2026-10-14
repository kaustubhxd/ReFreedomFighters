// batch943.cpp - area 56 residue 15, claim A2: 0x439270 (GetInputList, stdcall) and 0x46a730 (unnamed scalar deleting, thiscall).
#include "ff.h"

extern "C" u32 THISCALL ext_46a4f0(u8 *self);
extern "C" void ext_4690b0(u8 *p, u32 n);
extern "C" void ext_45c510(u8 *p);

// 0x439270, ZInputActions::GetInputList(int) const (high): table of 16-byte entries at 0x6e48c0; see docs/20-unclaimed-56.md.
static u32 STDCALL getInputList(s32 idx) {
  if (*(u32 *)0x6e48c0 == 0) return 0;
  u32 i = 0;
  u8 *ptr = (u8 *)0x6e48c0;
  for (;;) {
    if ((s32)i == idx) return *(u32 *)(0x6e48c0 + 16 * i);
    ptr += 16;
    i++;
    if (*(u32 *)ptr == 0) return 0;
  }
}
PCREG(439270, getInputList);

// 0x46a730 (GUESS name): base 0x46a4f0; flags bit 0 frees with 0x8e (bit 2) or runs 0x45c510; returns this.
static u8 *THISCALL unnamed46a730(u8 *self, u32 flags) {
  ext_46a4f0(self);
  if (flags & 1) {
    if (flags & 4) {
      ext_4690b0(self, 0x8e);
    } else {
      ext_45c510(self);
    }
  }
  return self;
}
PCREG(46a730, unnamed46a730);
