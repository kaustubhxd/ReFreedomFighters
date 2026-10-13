// batch4016.cpp - area 70 (residue 9), batch 4016: 0x4ce810, returns the inline buffer or a fresh zeroed-to-0x22 buffer
// (name GUESS). The allocator 0x41e290 is cdecl with one argument (the caller cleans it up with the memset call's clean-up);
// the fill is the import memset (IAT 0x676260, reached through the thunk 0x634d10). Both are exe callees, stubbed in the spec.
#include "ff.h"

extern "C" void *ext_41e290(u32 size);                       // exe: cdecl allocator, one argument, plain ret
extern "C" void *ext_634d10(void *dst, int val, u32 n);       // exe: thunk to memset (cdecl, three arguments)

// 0x4ce810 (name GUESS): thiscall, no arguments, plain ret. If [this+4] is zero, returns this+0x1c. Otherwise allocates
// 16 + 4*[this+0x10] bytes, fills them with 0x22 and returns the block.
static void *THISCALL allocOrInline(u8 *self) {
  if (*(u32 *)(self + 4) == 0) return self + 0x1c;
  u32 size = (*(u32 *)(self + 0x10) * 4) + 0x10;
  u8 *p = (u8 *)ext_41e290(size);
  ext_634d10(p, 0x22, size);
  return p;
}
PCREG(4ce810, allocOrInline);
