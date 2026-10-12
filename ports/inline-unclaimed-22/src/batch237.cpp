// batch237.cpp - area 59 (residue 18), docs/20-unclaimed-59.md. Cursor walk over a linked list (next at +0x50, next2 at
// +0x60, the node's group at +0x54): the cursor *cur is advanced to a value from the node or cleared; 0x4db9a0 is called
// (thiscall, one argument, returns al) when a flag bit is set on the node's group. Name GUESS.
#include "ff.h"

extern "C" u32 THISCALL ext_4db9a0(u8 *node, u32 flags);   // original, thiscall, one stack word (ret 4), returns al

// 0x4414a0, thiscall(cur) ret 4: self = this; pc = cur (a pointer to the cursor word).
static void THISCALL walkCursor_4414a0(u8 *self, u32 *pc) {
  u32 stop = *(u32 *)(self + 8);
  if (*(u32 *)(self + 0x4c) == 0 && *pc == stop) {
    *pc = 0;
    return;
  }
  u8 *node = *(u8 **)pc;
  u8 *t = *(u8 **)(node + 0x54);
  u32 eax = t ? *(u32 *)(*(u8 **)(t + 0xc) + 0x23) : 0x200002u;
  if (eax & 0x100000u) {
    bool toLoop = false;
    if ((u32)node != stop) {
      if ((u8)ext_4db9a0(node, 0x100021u)) toLoop = true;
    }
    if (!toLoop) {
      u8 *n2 = *(u8 **)pc;
      u32 v = *(u32 *)(*(u8 **)(n2 + 0x54) + 0x50);
      if (v) {
        *pc = v;
        return;
      }
    }
  }
  for (;;) {
    u8 *n3 = *(u8 **)pc;
    if (*(u32 *)(n3 + 0x60)) {
      *pc = *(u32 *)(n3 + 0x60);
      return;
    }
    u32 nx = *(u32 *)(n3 + 0x50);
    *pc = nx;
    if (nx == stop) {
      *pc = 0;
      return;
    }
    if (nx == 0) return;
  }
}
PCREG(4414a0, walkCursor_4414a0);
