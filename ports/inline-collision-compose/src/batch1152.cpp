// batch1152.cpp - collision thread, batch 1152 (name GUESS: ZOctreeCompiled install): 0x4edb80. Thiscall (ECX = this), two stack
// arguments (X, count), ret 8. Returns when count is -1. Otherwise allocates 0x18 bytes (0x41e290, cdecl; zeroed on success, vtable
// 0x67d138 at +0), stores the pointer at [this+0x19d], and calls 0x4e3d60 (ECX = the block, stack X; batch 1150's Init) as exe code.
#include "ff.h"

extern "C" void *ext_41e290(u32 size);                       // exe: cdecl allocator, stubbed by address in the spec
extern "C" void THISCALL ext_4e3d60(void *self, u8 *X);       // exe (batch 1150 port exists): Init, ret 4

static void THISCALL installCollisionBuffer4edb80(u8 *self, u8 *X, u32 count) {
  if (count == 0xffffffffu) return;
  u8 *p = (u8 *)ext_41e290(0x18);
  if (p != 0) {
    __builtin_memset(p, 0, 0x18);
    *(u32 *)p = 0x67d138u;
  }
  *(u8 **)(self + 0x19d) = p;
  ext_4e3d60(p, X);
}
PCREG(4edb80, installCollisionBuffer4edb80);
