// batch6333.cpp - unclaimed-63 gap-band batch 33: one cursor step over a node list (band 0x4c1000-0x4e1000).
//   0x4cf370 (C-set; no GC name): thiscall, one argument P (a pointer to a two-dword cursor: P[0] = node, P[1] = index), ret 4.
//     If P[1] == this[+0x10]: P[1] = 0 and P[0] = P[0]->next (node +4). node = P[0]; if node == 0 return 0.
//     If P[1] == this[+8]->[+8] and node->[+4] == 0: P[0] = 0 and return 0.
//     Else P[1] = this[+0x18] + P[1] and return node + 0x10 + 4 * (old P[1]).
#include "ff.h"

// 0x4cf370 (C-set): returns a pointer to the slot, or 0 at the end of the list.
static u8 *THISCALL unnamed4cf370(u8 *self, u32 *P) {
  if (P[1] == *(u32 *)(self + 0x10)) {
    P[1] = 0;
    P[0] = *(u32 *)(P[0] + 4);
  }
  u32 node = P[0];
  if (node == 0)
    return 0;
  u32 idx = P[1];
  if (idx == *(u32 *)(*(u32 *)(self + 8) + 8) && *(u32 *)(node + 4) == 0) {
    P[0] = 0;
    return 0;
  }
  P[1] = *(u32 *)(self + 0x18) + idx;
  return (u8 *)(node + 0x10 + idx * 4);
}
PCREG(4cf370, unnamed4cf370);
