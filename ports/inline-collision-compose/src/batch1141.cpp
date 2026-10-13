// batch1141.cpp - collision thread, batch 1141 (hard-row lane, name GUESS): 0x441530, a walk over a node tree that stops at a
// sentinel (this+8), with a flag test (bit 0x100000 of the dword at type+0xc+0x23 of the node's type). No calls. Thiscall (ECX =
// this), one stack argument p (a pointer to the current-node cell), ret 4.
#include "ff.h"

// Flag word of a node: the dword at [[[n+0x54]+0xc]+0x23], or 0x200002 when the node's type is null.
static u32 flagsOf441530(u8 *n) {
  u8 *t = *(u8 **)(n + 0x54);
  if (t == 0) return 0x200002u;
  u8 *x = *(u8 **)(t + 0xc);
  return *(u32 *)(x + 0x23);
}

static void THISCALL walk441530(u8 *self, u8 **p) {
  if (*(u32 *)(self + 0x4c) == 0 && *p == *(u8 **)(self + 8)) {
    *p = 0;
    return;
  }
  u8 *cand = *(u8 **)(*(u8 **)(*p + 0x54) + 0x50);
  if (cand != 0 && (flagsOf441530(cand) & 0x100000u)) {
    *p = cand;
    return;
  }
  for (;;) {
    if (*(u8 **)(*p + 0x60) != 0) {
      *p = *(u8 **)(*p + 0x60);
      if (flagsOf441530(*p) & 0x100000u) return;
    }
    u8 *nxt = *(u8 **)(*p + 0x50);
    *p = nxt;
    if (nxt == *(u8 **)(self + 8)) {
      *p = 0;
      return;
    }
    if (nxt == 0) return;
  }
}
PCREG(441530, walk441530);
