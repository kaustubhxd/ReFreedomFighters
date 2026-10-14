// batch914.cpp - residue-9 slice: 0x5b7790 [thiscall, no args, returns this (ret 0)]: the base constructor 0x469870 on this, bit 5 of
// this+4 set, the dword at this+0x44 cleared, the vtable 0x6b23a8 written at this, the dword at this+0x48 cleared. Body read in full.
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_469870(void *self);   // base constructor (stood in; shared with batch911)

// 0x5b7790 (no name in the map).
static u8 *THISCALL Init5b7790(u8 *self) {
  ext_469870(self);
  U32(self, 4) |= 0x20;
  U32(self, 0x44) = 0;
  U32(self, 0) = 0x6b23a8u;
  U32(self, 0x48) = 0;
  return self;
}
PCREG(5b7790, Init5b7790);
