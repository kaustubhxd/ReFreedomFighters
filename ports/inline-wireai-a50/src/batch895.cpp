// batch895.cpp - gap band slice: 0x420300 [22 instr, thiscall, one stack arg (an index), ret 4, returns a byte (al)]. The flag byte
// at this + 5*idx + 0xf0b keeps its top bit as the result; if bit 1 is set it is cleared (the stored byte keeps bit 7). Then the
// float at the engine object (0x70039c) +0x9c7 is compared with the constant at 0x6785d0: equal (ordered) gives 0, otherwise the
// result is the top bit of the byte (the unordered case goes that way too, through the jp).
#include "ff.h"

#define F32(p, o) (*(float *)((u8 *)(p) + (o)))

// 0x420300 (name GUESS "Flag420300").
static u8 THISCALL Flag420300(u8 *self, u32 idx) {
  u8 *addr = self + 5 * idx + 0xf0b;
  u8 al = *addr;
  u8 cl = al >> 7;
  if (al & 2) *addr = al & 0x7f;
  float gf = F32(G(u8 *, 0x70039c), 0x9c7);
  float c = G(float, 0x6785d0);
  if (gf == c) return 0;
  return cl;
}
PCREG(420300, Flag420300);
