// u69_72.cpp - area 69, group 72 (slice 8). A walk over a node list: self is a slot holding the current node P; the node layout is a flag byte at +0,
// dword links at +1, +5 and +9. No callees. eax on exit is not defined on every path, so the spec does not compare it (ret=None).
#include "ff.h"

// 0x42ffc0, thiscall no args (ret). Updates the slot at self to the next node:
// if *P == 0 and the node at [P+1] links back to P, the slot becomes [P+9].
// Otherwise, if [P+5] is non-null, the slot follows the +9 links from [P+5] to the last node with a non-null +9 (or stays at [P+5] if its +9 is null).
// If [P+5] is null: with ecx = [P+1], if [ecx+5] == P, the slot walks the +1 links while the node's +5 equals the previous node; the slot ends at the last node.
static void THISCALL nextNode42ffc0(u8 *self) {
  u32 *slot = (u32 *)self;
  u32 P = *slot;
  u32 ecx;
  if (*(u8 *)P == 0) {
    u32 t = *(u32 *)(P + 1);
    if (*(u32 *)(t + 1) == P) {
      *slot = *(u32 *)(P + 9);
      return;
    }
  }
  ecx = *(u32 *)(P + 5);
  if (ecx != 0) {
    u32 eax = *(u32 *)(ecx + 9);
    if (eax != 0) {
      do {
        ecx = eax;
        eax = *(u32 *)(ecx + 9);
      } while (eax != 0);
    }
    *slot = ecx;
    return;
  }
  ecx = *(u32 *)(P + 1);
  if (P == *(u32 *)(ecx + 5)) {
    u32 eax;
    do {
      eax = ecx;
      *slot = ecx;
      ecx = *(u32 *)(ecx + 1);
    } while (eax == *(u32 *)(ecx + 5));
  }
  *slot = ecx;
}
PCREG(42ffc0, nextNode42ffc0);
