// batch891.cpp - gap band 0x401000-0x421000 slice (taken by area 50; see docs/20-unclaimed-50.md): 0x41e650 [16 instr, thiscall,
// one stack arg, ret 4, bool]. Range test of a pointer against the block at this+0x1c5d: the block size is in its header word
// (low 29 bits, the word at block-8).
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x41e650 (name GUESS "InBlock41e650").
static bool THISCALL InBlock41e650(u8 *self, u32 p) {
  u32 base = U32(self, 0x1c5d);
  if (p < base) return false;
  if (base == 0) return false;
  u32 size = (U32(base, -8) & 0x1fffffffu) + base;
  if (p >= size) return false;
  return true;
}
PCREG(41e650, InBlock41e650);
