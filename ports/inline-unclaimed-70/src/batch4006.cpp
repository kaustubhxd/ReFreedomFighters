// batch4006.cpp - area 70 (residue 9), batch 4006: a list walk that calls a slot 0x7c virtual per node (name GUESS).
#include "ff.h"

// 0x4cdb90 (name GUESS): thiscall, plain ret. Sets bit 31 of the dword at +0xc; walks the list at +4 (next at node+4),
// calling this's slot 0x7c with each node (the next pointer is read before the call); then clears +4 and +0x14.
static void THISCALL clearNodeList(u8 *self) {
  *(u32 *)(self + 0xc) |= 0x80000000u;
  u8 *n = *(u8 **)(self + 4);
  while (n) {
    u8 *next = *(u8 **)(n + 4);
    vcall<void>(self, 0x7c, n);
    n = next;
  }
  *(u8 **)(self + 4) = 0;
  *(u32 *)(self + 0x14) = 0;
}
PCREG(4cdb90, clearNodeList);
